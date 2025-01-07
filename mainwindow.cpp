#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QThread>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), serialPort(new QSerialPort(this)) {
    ui->setupUi(this);

    connect(ui->btnSelectFirmware_A, &QPushButton::clicked, this, &MainWindow::selectFirmware);
    connect(ui->btnSelectFirmware_B, &QPushButton::clicked, this, &MainWindow::selectFirmware);
    connect(ui->btnStartUpgrade, &QPushButton::clicked, this, &MainWindow::startUpgrade);
    connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::receiveData);
    // 按钮点击连接槽
    connect(ui->pushButtonConnect, &QPushButton::clicked, this, &MainWindow::connectOrDisconnect);

    scanSerialPorts();
    ui->chose_app->clear();
    ui->chose_app->addItem("A");
    ui->chose_app->addItem("B");
    currentPacketIndex=0;
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::selectFirmware() {
    firmwarePath = QFileDialog::getOpenFileName(this, "选择固件文件", "", "BIN Files (*.bin)");
    if (!firmwarePath.isEmpty()) {
        ui->textLog->append("已选择固件文件: " + firmwarePath);
    }

    QFileInfo fileInfo(firmwarePath);
    QString fileName = fileInfo.fileName(); // 提取文件名（不包括路径）
    QRegularExpression regexA("V[0-9]+\\.[0-9]+A", QRegularExpression::CaseInsensitiveOption);
    QRegularExpression regexB("V[0-9]+\\.[0-9]+B", QRegularExpression::CaseInsensitiveOption);
    if (regexA.match(fileName).hasMatch()) {
        ui->textLog->append("检测到固件类型: A固件");
        ui->file_path_A->setText(firmwarePath);
    } else if (regexB.match(fileName).hasMatch()) {
        ui->textLog->append("检测到固件类型: B固件");
         ui->file_path_B->setText(firmwarePath);
    } else {
        ui->textLog->append("未检测到固件类型标识");
    }

}

void MainWindow::startUpgrade() {

    if (firmwarePath.isEmpty()) {
        QMessageBox::warning(this, "警告", "请先选择固件文件！");
        return;
    }
    //
    QString app_txt=ui->chose_app->currentText();
    if(app_txt=="A")
    {
        //firmwarePath设置为B地址
        firmwarePath=ui->file_path_B->text();
    }
    else if(app_txt=="B")
    {
        //firmwarePath设置为B地址
        firmwarePath=ui->file_path_B->text();
    }
    QFile file(firmwarePath);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, "错误", "无法打开固件文件！");
        return;
    }

    firmwareData = file.readAll();
    file.close();
    //打印升级包大小
    ui->textLog->append("固件文件大小: " + QString::number(firmwareData.size()) + " 字节");
    //发送指令
    QString msg="AAA"+QString::number(firmwareData.size());
    ui->textLog->append(msg);
    //serialPort->write(msg.toUtf8());
    serialPort->write("AAA86840");
     //等待3s开始升级

}

void MainWindow::sendData() {


    QByteArray packet = firmwareData.mid(currentPacketIndex * 256, 256);  // 每包256字节
    // 添加数据校验（如CRC）...
    while (currentPacketIndex * 256 <firmwareData.size()) {


      serialPort->write(packet);
      currentPacketIndex++;
      ui->progressBar->setValue((currentPacketIndex * 256 * 100) / firmwareData.size());

    //发送延时50ms
    }
    if (currentPacketIndex * 256 >= firmwareData.size()) {
        ui->textLog->append("升级完成！");
        serialPort->close();
        return;
    }
}

void MainWindow::receiveData() {
    QByteArray response = serialPort->readAll();

    // 确保数据不为空
    if (response.contains("Serial:")) {
        // 获取 "Serial:" 的起始位置
        int startIndex = response.indexOf("Serial:") + QString("Serial:").length(); // 起始索引

        // 从起始位置到第一个空格前提取版本号
        int endIndex = response.indexOf('\n', startIndex); // 找到空格的位置
        QString version;
        if (endIndex == -1) {
            // 如果没有空格，则取到字符串末尾
            version = response.mid(startIndex).trimmed();
        } else {
            // 如果有空格，则取起始位置到空格之间的部分
            version = response.mid(startIndex, endIndex - startIndex).trimmed();
        }

        // 显示到 UI 界面
        ui->textLog->append("单片机版本号：" + version);
        ui->Serial_txt->setText(version);
    }
   else if (response.contains("SF_version:")) {
        // 获取 "Serial:" 的起始位置
        int startIndex = response.indexOf("SF_version:") + QString("SF_version:").length(); // 起始索引

        // 从起始位置到第一个空格前提取版本号
        int endIndex = response.indexOf('H', startIndex); // 找到空格的位置
        QString version;
        if (endIndex == -1) {
            // 如果没有空格，则取到字符串末尾
            version = response.mid(startIndex).trimmed();
        } else {
            // 如果有空格，则取起始位置到空格之间的部分
            version = response.mid(startIndex, endIndex - startIndex).trimmed();
        }

        // 显示到 UI 界面
        ui->SF_version->setText(version);

    }

    ui->textLog->append(response);
    if (response.contains("!!!"))
    {
          QThread::sleep(5);
        sendData();
    }


}



//函数功能：搜索串口

void MainWindow::scanSerialPorts() {
    ui->comboBoxSerialPorts->clear();
    const auto ports = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &port : ports) {
        ui->comboBoxSerialPorts->addItem(port.portName());
    }
    ui->comboBoxBaudRate->clear();
    //设置常用的波特率，默认为115200
    ui->comboBoxBaudRate->addItem("115200");
    ui->comboBoxBaudRate->addItem("9600");
    ui->comboBoxBaudRate->addItem("19200");
    ui->comboBoxBaudRate->addItem("38400");
    ui->comboBoxBaudRate->addItem("57600");
    ui->comboBoxBaudRate->addItem("115200");
}

void MainWindow::connectOrDisconnect() {
    if (!isConnected) {
        // 获取当前选择的串口
        const QString portName = ui->comboBoxSerialPorts->currentText();
        const QString baudRateText = ui->comboBoxBaudRate->currentText();

        if (portName.isEmpty()) {
            QMessageBox::warning(this, "Warning", "Please select a serial port.");
            return;
        }

        // 配置串口
        serialPort->setPortName(portName);
        serialPort->setBaudRate(baudRateText.toInt());

        // 尝试打开串口
        if (serialPort->open(QIODevice::ReadWrite)) {
            isConnected = true;
            ui->pushButtonConnect->setText("Disconnect");
            ui->comboBoxSerialPorts->setEnabled(false);
            ui->comboBoxBaudRate->setEnabled(false);
            QMessageBox::information(this, "Info", "Serial port connected.");
        } else {
            QMessageBox::critical(this, "Error", "Failed to open the serial port.");
        }
    } else {
        // 断开连接
        serialPort->close();
        isConnected = false;
        ui->pushButtonConnect->setText("Connect");
        ui->comboBoxSerialPorts->setEnabled(true);
        ui->comboBoxBaudRate->setEnabled(true);
        QMessageBox::information(this, "Info", "Serial port disconnected.");
    }
}

