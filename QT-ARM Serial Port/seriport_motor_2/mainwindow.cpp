#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QErrorMessage>
#include"project.h"
#include<QProgressBar>
#include <QSlider>
#include<QPushButton>
#include<QTimer>
#include<QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Disable maximizing
    //setFixedSize(winId(),height());
    //adding title for widget
    QMainWindow::setWindowTitle("Serial Port");
    //Ports
    QList<QSerialPortInfo> ports=info.availablePorts();
    QList<QString>stringPorts;

    for (int i = 0; i <ports.size(); ++i)
    {
        stringPorts.append(ports.at(i).portName());
    }
        ui->comboBox_port->addItems(stringPorts);

    //Baud Rate
    QList<qint32>baudRates=info.standardBaudRates();
    QList<QString>stringBaudRates;

    for (int i = 0; i < baudRates.size(); ++i)
    {
        stringBaudRates.append(QString::number(baudRates.at(i)));
    }
        ui->comboBox_baudrate->addItems(stringBaudRates);

    //Data Bits
        ui->comboBox_databits->addItem("5");
        ui->comboBox_databits->addItem("6");
        ui->comboBox_databits->addItem("7");
        ui->comboBox_databits->addItem("8");
   //Data Bits
            ui->comboBox_stopbits->addItem("1 Bit");
            ui->comboBox_stopbits->addItem("1,5 Bits");
            ui->comboBox_stopbits->addItem("2 Bits");
   //Parities
            ui->comboBox_parity->addItem("No Parity");
            ui->comboBox_parity->addItem("Even Parity");
            ui->comboBox_parity->addItem("Odd Parity");
            ui->comboBox_parity->addItem("Mark Parity");
            ui->comboBox_parity->addItem("Space Parity");
  //Flow Control
      ui->comboBox_flowcontrol->addItem("No Flow Control");
      ui->comboBox_flowcontrol->addItem("Hardware Flow Control");
      ui->comboBox_flowcontrol->addItem("Software Flow Control");



}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::serialReceived()
{
    QByteArray dataBA = serialPort.readAll();
      QString data(dataBA);
      Buffer.append(data);
      int index = Buffer.indexOf(Code);
      if(index != -1){
         QString message = Buffer.mid(0,index);
         ui->textBrowser->setTextColor(Qt::blue); // Receieved message's color is blue.
         ui->textBrowser->append(message);
         Buffer.remove(0,index+codeSize);
      }
}


void MainWindow::on_pushButton_Connect_clicked()
{
    QString portName = ui->comboBox_port->currentText();
       serialPort.setPortName(portName);

       serialPort.open(QIODevice::ReadWrite);

       if(!serialPort.isOpen()){
           ui->textBrowser->setTextColor(Qt::red);
           ui->textBrowser->append("!!!! Something went Wrong !!!!");
       }
       else {
           ui->textBrowser->setText("Connected");
           QString stringbaudRate = ui->comboBox_baudrate->currentText();
           int intbaudRate = stringbaudRate.toInt();
           serialPort.setBaudRate(intbaudRate);

           QString dataBits = ui->comboBox_databits->currentText();
           if(dataBits == "5 Bits") {
              serialPort.setDataBits(QSerialPort::Data5);
           }
           else if((dataBits == "6 Bits")) {
              serialPort.setDataBits(QSerialPort::Data6);
           }
           else if(dataBits == "7 Bits") {
              serialPort.setDataBits(QSerialPort::Data7);
           }
           else if(dataBits == "8 Bits"){
              serialPort.setDataBits(QSerialPort::Data8);
           }

           QString stopBits = ui->comboBox_stopbits->currentText();
           if(stopBits == "1 Bit") {
            serialPort.setStopBits(QSerialPort::OneStop);
           }
           else if(stopBits == "1,5 Bits") {
            serialPort.setStopBits(QSerialPort::OneAndHalfStop);
           }
           else if(stopBits == "2 Bits") {
            serialPort.setStopBits(QSerialPort::TwoStop);
           }

           QString parity = ui->comboBox_parity->currentText();
           if(parity == "No Parity"){
             serialPort.setParity(QSerialPort::NoParity);
           }
           else if(parity == "Even Parity"){
             serialPort.setParity(QSerialPort::EvenParity);
           }
           else if(parity == "Odd Parity"){
             serialPort.setParity(QSerialPort::OddParity);
           }
           else if(parity == "Mark Parity"){
             serialPort.setParity(QSerialPort::MarkParity);
           }
           else if(parity == "Space Parity") {
               serialPort.setParity(QSerialPort::SpaceParity);
           }


           QString flowControl = ui->comboBox_flowcontrol->currentText();
           if(flowControl == "No Flow Control") {
             serialPort.setFlowControl(QSerialPort::NoFlowControl);
           }
           else if(flowControl == "Hardware Flow Control") {
             serialPort.setFlowControl(QSerialPort::HardwareControl);
           }
           else if(flowControl == "Software Flow Control") {
             serialPort.setFlowControl(QSerialPort::SoftwareControl);
           }

           Code = ui->lineEdit_code->text();
           codeSize = Code.size();

           connect(&serialPort,SIGNAL(readyRead()),this,SLOT(receiveMessage()));
       }
       timer=new QTimer(this);
       connect(timer,SIGNAL(timeout()),this,SLOT(MySlot()));
       timer->start(1100);

}


void MainWindow::on_pushButton_Disconnect_clicked()
{
    serialPort.close();
    ui->textBrowser->setText("Disconnected");

}


void MainWindow::on_pushButton_Refresh_clicked()
{
    ui->comboBox_port->clear();
       QList<QSerialPortInfo> ports = info.availablePorts();
       QList<QString> stringPorts;
       for(int i = 0 ; i < ports.size() ; i++){
           stringPorts.append(ports.at(i).portName());
       }
       ui->comboBox_port->addItems(stringPorts);
}


void MainWindow::on_pushButton_send_clicked()
{
    QString position=  ui->lineEdit_send->text();

/*
      QProgressBar *prg=new QProgressBar(this);
      //prg->setRange(0,100);
      QString message = ui->lineEdit_send->text();
        ui->textBrowser->setTextColor(Qt::darkRed); // Color of message to send is green.
        ui->textBrowser->append(message);
        ui->progressBar->setValue(0);
        prg->setValue(ui->horizontalSlider->value());
        serialPort.write((message).toUtf8());
*/
    QString message = ui->lineEdit_send->text();
      ui->textBrowser->setTextColor(Qt::darkGreen); // Color of message to send is green.
      ui->textBrowser->append(message);
      serialPort.write(message.toUtf8());


      ui->textBrowser->setTextColor(Qt::darkBlue);
      serialPort.readLine();
    QProgressBar *prg=new QProgressBar(this);

    //QPushButton *pshbtn =new QPushButton(this);

        prg->setRange(0,100);

        if(ui->lineEdit_send->text()=="mtr:0")
      {
          ui->progressBar->setValue(0);

          prg->setValue(ui->horizontalSlider->value());
          prg->valueChanged(ui->lineEdit_send->text().toInt());
          emit;


      }
        if(ui->lineEdit_send->text()=="mtr:1")
      {
          ui->progressBar->setValue(10);

          prg->setValue(ui->horizontalSlider->value());
          prg->valueChanged(ui->lineEdit_send->text().toInt());
          emit;


      }
      if(ui->lineEdit_send->text()=="mtr:2")
      {
          ui->progressBar->setValue(20);

          prg->setValue(ui->horizontalSlider->value());
         prg->valueChanged(ui->lineEdit_send->text().toInt());
          emit;

      }
      if(ui->lineEdit_send->text()=="mtr:3")
      {
          ui->progressBar->setValue(30);

          prg->setValue(ui->horizontalSlider->value());
          prg->valueChanged(ui->lineEdit_send->text().toInt());

          emit;
      }
      if(ui->lineEdit_send->text()=="mtr:4")
      {
          ui->progressBar->setValue(40);

          prg->setValue(ui->horizontalSlider->value());
          prg->valueChanged(ui->lineEdit_send->text().toInt());

          emit;
      }
      if(ui->lineEdit_send->text()=="mtr:5")
      {
          ui->progressBar->setValue(50);

          prg->setValue(ui->horizontalSlider->value());
          prg->valueChanged(ui->lineEdit_send->text().toInt());

          emit;
      }
      if(ui->lineEdit_send->text()=="mtr:6")
      {
          ui->progressBar->setValue(60);

          prg->setValue(ui->horizontalSlider->value());
          prg->valueChanged(ui->lineEdit_send->text().toInt());

          emit;
      }
      if(ui->lineEdit_send->text()=="mtr:7")
      {
          ui->progressBar->setValue(70);

          prg->setValue(ui->horizontalSlider->value());
          prg->valueChanged(ui->lineEdit_send->text().toInt());

          emit;
       }
      if(ui->lineEdit_send->text()=="mtr:8")
      {
          ui->progressBar->setValue(80);

          prg->setValue(ui->horizontalSlider->value());
          prg->valueChanged(ui->lineEdit_send->text().toInt());

          emit;
      }
}


void MainWindow::on_pushButton_clear_clicked()
{

    ui->textBrowser->clear();
}


void MainWindow::on_pushButton_open_project_clicked()
{
    Project *project=new Project(this);
    project->show();
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    ui->progressBar->setValue(value);

}




void MainWindow::on_horizontalSlider_sliderReleased()
{
  int position=  ui->horizontalSlider->value();


    QProgressBar *prg=new QProgressBar(this);
    //prg->setRange(0,100);
   // QString message = ui->label_scroll->text()="mtr:0";
      ui->textBrowser->setTextColor(Qt::darkRed); // Color of message to send is green.
      ui->textBrowser->append(QString::number(position));
      ui->progressBar->setValue(0);
      prg->setValue(ui->horizontalSlider->value());
      serialPort.write(QString::number(position).toUtf8());
    //ui->label_scroll->setText(QString::number(position));
   /* if(position==0||position==10||position==20||position==30||position==40||position==50||position==60||position==70||position==80){
    if(position==0)
    {
    QProgressBar *prg=new QProgressBar(this);
    //prg->setRange(0,100);
   // QString message = ui->label_scroll->text()="mtr:0";
      ui->textBrowser->setTextColor(Qt::darkRed); // Color of message to send is green.
      ui->textBrowser->append(QString::number(position));
      ui->progressBar->setValue(0);
      prg->setValue(ui->horizontalSlider->value());
      serialPort.write(QString::number(position).toUtf8());
    }
     if(position==10)
    {
        QString message1 = ui->label_scroll->text()="mtr:1";
          ui->textBrowser->setTextColor(Qt::darkRed); // Color of message to send is green.
          ui->textBrowser->append(message1);
          ui->progressBar->setValue(30);
          prg->setValue(ui->horizontalSlider->value());


          serialPort.write(message1.toUtf8());
     }
  if(position==20)
      {
        QString message2 = ui->label_scroll->text()="mtr:2";
          ui->textBrowser->setTextColor(Qt::darkRed); // Color of message to send is green.
          ui->textBrowser->append(message2);
          ui->progressBar->setValue(40);
          prg->setValue(ui->horizontalSlider->value());
         serialPort.write(message2.toUtf8());


        }
        if(position==30)
      {
        QString message3 = ui->label_scroll->text()="mtr:3";
          ui->textBrowser->setTextColor(Qt::darkRed); // Color of message to send is green.
          ui->textBrowser->append(message3);
          ui->progressBar->setValue(50);
          prg->setValue(ui->horizontalSlider->value());
          serialPort.write(message3.toUtf8());
         serialPort.write(message3.toUtf8());

      }
     if(position==40)
      {
        QString message4 = ui->label_scroll->text()="mtr:4";
          ui->textBrowser->setTextColor(Qt::darkRed); // Color of message to send is green.
          ui->textBrowser->append(message4);
          ui->progressBar->setValue(60);
          prg->setValue(ui->horizontalSlider->value());
         serialPort.write(message4.toUtf8());


      }
     if(position==50)
      {
        QString message5 = ui->label_scroll->text()="mtr:5";
          ui->textBrowser->setTextColor(Qt::darkRed); // Color of message to send is green.
          ui->textBrowser->append(message5);
          ui->progressBar->setValue(70);
          prg->setValue(ui->horizontalSlider->value());
          serialPort.write(message5.toUtf8());


      }
       if(position==60)
      {
        QString message6 = ui->label_scroll->text()="mtr:6";
          ui->textBrowser->setTextColor(Qt::darkRed); // Color of message to send is green.
          ui->textBrowser->append(message6);
          ui->progressBar->setValue(80);
          prg->setValue(ui->horizontalSlider->value());
          serialPort.write(message6.toUtf8());


      }
       if(position==70)
      {
        QString message7 = ui->label_scroll->text()="mtr:7";
          ui->textBrowser->setTextColor(Qt::darkRed); // Color of message to send is green.
          ui->textBrowser->append(message7);
          ui->progressBar->setValue(90);
          prg->setValue(ui->horizontalSlider->value());
         serialPort.write(message7.toUtf8());


      }
       if(position==80)
      {
          QString message8 = ui->label_scroll->text()="mtr:8";
            ui->textBrowser->setTextColor(Qt::darkRed); // Color of message to send is green.
            ui->textBrowser->append(message8);
            ui->progressBar->setValue(100);
            prg->setValue(ui->horizontalSlider->value());
           serialPort.write(message8.toUtf8());


}

    }
    */
}
int sayac=1;
void MainWindow::MySlot()
{

    QProgressBar *prg=new QProgressBar(this);


     if(sayac==1)
    {
        QString message = ui->label_scroll->text()="mtr:1";
          ui->textBrowser->setTextColor(Qt::darkRed);
          ui->textBrowser->append(message);
          ui->lcdNumber->display(200);
          prg->setValue(ui->horizontalSlider->value());
         serialPort.write(message.toUtf8());

    }
    else if(sayac==2)
    {
        QString message = ui->label_scroll->text()="mtr:2";
          ui->textBrowser->setTextColor(Qt::darkRed);
          ui->textBrowser->append(message);
          ui->lcdNumber->display(300);
          prg->setValue(ui->horizontalSlider->value());
         serialPort.write(message.toUtf8());

    }
    else if(sayac==3)
    {
        QString message = ui->label_scroll->text()="mtr:3";
          ui->textBrowser->setTextColor(Qt::darkRed);
          ui->textBrowser->append(message);
          ui->lcdNumber->display(400);
          prg->setValue(ui->horizontalSlider->value());
         serialPort.write(message.toUtf8());

    }
    else if(sayac==4)
    {
        QString message = ui->label_scroll->text()="mtr:4";
          ui->textBrowser->setTextColor(Qt::darkRed);
          ui->textBrowser->append(message);
          ui->lcdNumber->display(500);
          prg->setValue(ui->horizontalSlider->value());
         serialPort.write(message.toUtf8());

    }

    else if(sayac==5)
    {
        QString message = ui->label_scroll->text()="mtr:5";
          ui->textBrowser->setTextColor(Qt::darkRed);
          ui->textBrowser->append(message);
          ui->lcdNumber->display(600);
          prg->setValue(ui->horizontalSlider->value());
         serialPort.write(message.toUtf8());

    }
    else if(sayac==6)
    {
        QString message = ui->label_scroll->text()="mtr:6";
          ui->textBrowser->setTextColor(Qt::darkRed);
          ui->textBrowser->append(message);
          ui->lcdNumber->display(700);
          prg->setValue(ui->horizontalSlider->value());
         serialPort.write(message.toUtf8());

    }
    else if(sayac==7)
    {
        QString message = ui->label_scroll->text()="mtr:7";
          ui->textBrowser->setTextColor(Qt::darkRed);
          ui->textBrowser->append(message);
          ui->lcdNumber->display(800);
          prg->setValue(ui->horizontalSlider->value());
         serialPort.write(message.toUtf8());

    }
    else if(sayac==8)
    {
        QString message = ui->label_scroll->text()="mtr:8";
          ui->textBrowser->setTextColor(Qt::darkRed);
          ui->textBrowser->append(message);
          ui->lcdNumber->display(900);
          prg->setValue(ui->horizontalSlider->value());
         serialPort.write(message.toUtf8());
    }
    else if(sayac==9)
    {
        QString message = ui->label_scroll->text()="mtr:7";
          ui->textBrowser->setTextColor(Qt::darkRed);
          ui->textBrowser->append(message);
          ui->lcdNumber->display(800);
          prg->setValue(ui->horizontalSlider->value());
         serialPort.write(message.toUtf8());

    }
    else if(sayac==10)
    {
        QString message = ui->label_scroll->text()="mtr:6";
          ui->textBrowser->setTextColor(Qt::darkRed);
          ui->textBrowser->append(message);
         ui->lcdNumber->display(700);
          prg->setValue(ui->horizontalSlider->value());
         serialPort.write(message.toUtf8());

    }
    else if(sayac==11)
    {
        QString message = ui->label_scroll->text()="mtr:5";
          ui->textBrowser->setTextColor(Qt::darkRed);
          ui->textBrowser->append(message);
       ui->lcdNumber->display(600);
          prg->setValue(ui->horizontalSlider->value());
         serialPort.write(message.toUtf8());

    }
    else if(sayac==12)
    {
        QString message = ui->label_scroll->text()="mtr:4";
          ui->textBrowser->setTextColor(Qt::darkRed);
          ui->textBrowser->append(message);
          ui->lcdNumber->display(500);
          prg->setValue(ui->horizontalSlider->value());
         serialPort.write(message.toUtf8());

    }
    else if(sayac==13)
    {
        QString message = ui->label_scroll->text()="mtr:3";
          ui->textBrowser->setTextColor(Qt::darkRed);
          ui->textBrowser->append(message);
          ui->lcdNumber->display(400);
          prg->setValue(ui->horizontalSlider->value());
         serialPort.write(message.toUtf8());

    }
    else if(sayac==14)
    {
        QString message = ui->label_scroll->text()="mtr:2";
          ui->textBrowser->setTextColor(Qt::darkRed);
          ui->textBrowser->append(message);
          ui->lcdNumber->display(300);
          prg->setValue(ui->horizontalSlider->value());
         serialPort.write(message.toUtf8());

    }
    else if(sayac==15)
    {
        QString message = ui->label_scroll->text()="mtr:1";
          ui->textBrowser->setTextColor(Qt::darkRed);
          ui->textBrowser->append(message);
          ui->lcdNumber->display(200);
          prg->setValue(ui->horizontalSlider->value());
         serialPort.write(message.toUtf8());

    }
    else if(sayac==16)
    {
        QString message = ui->label_scroll->text()="mtr:0";
          ui->textBrowser->setTextColor(Qt::darkRed);
          ui->textBrowser->append(message);
         ui->lcdNumber->display(100);
          prg->setValue(ui->horizontalSlider->value());
         serialPort.write(message.toUtf8());

    }
    else
    {
        timer->stop();
        ui->lcdNumber->display(0);
    }
    sayac++;
}



