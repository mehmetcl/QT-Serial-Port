#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include<QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QTimer *timer;
private slots:
    void serialReceived();
    void on_pushButton_Connect_clicked();

    void on_pushButton_Disconnect_clicked();

    void on_pushButton_Refresh_clicked();

    void on_pushButton_send_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_open_project_clicked();

    void on_horizontalSlider_valueChanged(int value);


    void on_horizontalSlider_sliderReleased();
    void MySlot();
private:
    Ui::MainWindow *ui;
    QSerialPort serialPort;
    QSerialPortInfo info;
    QString Buffer;
    QString Code;
    int codeSize;

};
#endif // MAINWINDOW_H
