#include "secdialog.h"
#include "ui_secdialog.h"
#include "doordialog.h"
#include <QSerialPort>
#include <QSerialPortInfo>

QSerialPort seri;



SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);
    seri.setPortName("COM8");
    seri.setBaudRate(QSerialPort::Baud9600);
    seri.setDataBits(QSerialPort::Data8);
    seri.setParity(QSerialPort::NoParity);
    seri.setStopBits(QSerialPort::OneStop);
    seri.setFlowControl(QSerialPort::NoFlowControl);
    seri.open(QIODevice::ReadWrite);
}

SecDialog::~SecDialog()
{
    delete ui;
    seri.close();
}







void SecDialog::on_pushButton_Doors_clicked()
{
hide();
doorDialog = new DoorDialog(this);
doorDialog->show();
seri.close();

}


void SecDialog::on_pushButtonWindows_clicked()
{
    hide();
    windowDialog = new WindowDialog(this);
    windowDialog->show();
    seri.close();
}


void SecDialog::on_pushButton_Lights_clicked()
{
    hide();
    lightsDialog = new LightsDialog(this);
    lightsDialog-> show();
    seri.close();
}






void SecDialog::on_AC_ON_clicked()
{

    ui->AC->setText(seri.readAll());

}



void SecDialog::on_AC_OFF_clicked()
{
    ui->AC->setText("AC OFF");
    seri.write("s");
}




void SecDialog::on_RECONNECT_clicked()
{
    seri.setPortName("COM8");
    seri.setBaudRate(QSerialPort::Baud9600);
    seri.setDataBits(QSerialPort::Data8);
    seri.setParity(QSerialPort::NoParity);
    seri.setStopBits(QSerialPort::OneStop);
    seri.setFlowControl(QSerialPort::NoFlowControl);
    seri.open(QIODevice::ReadWrite);
}

