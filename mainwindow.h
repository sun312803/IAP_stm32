#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void selectFirmware();  // 选择固件文件
    void startUpgrade();    // 开始升级
    void sendData();        // 发送数据包
    void receiveData();     // 接收单片机反馈
    void scanSerialPorts();  // 扫描串口
    void connectOrDisconnect();  // 连接/断开串口




private:
    Ui::MainWindow *ui;
    QSerialPort *serialPort;    // 串口对象
    QString firmwarePath;       // 固件文件路径
    QByteArray firmwareData;    // 固件数据
    int currentPacketIndex;     // 当前发送的数据包索引
    bool isConnected;         // 当前连接状态
};

#endif // MAINWINDOW_H
