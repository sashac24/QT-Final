#include "lightsdialog.h"
#include "ui_lightsdialog.h"
#include "secdialog.h"
#include <QSerialPort>
#include <QSerialPortInfo>

QSerialPort serial;

SecDialog *secDialog;

LightsDialog::LightsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LightsDialog)
{
    ui->setupUi(this);

}

LightsDialog::~LightsDialog()
{
    delete ui;
    serial.close();
}

void LightsDialog::on_pushButton_BackHome_clicked()
{
    hide();
    secDialog = new SecDialog(this);
    secDialog->show();
    serial.close();
}


void LightsDialog::on_pushButton_clicked()
{
    hide();
    addLightDialog = new AddLightDialog(this);
    addLightDialog->show();
}


void LightsDialog::on_GarageL_ON_clicked()
{
    serial.write("t");
}


void LightsDialog::on_GarageL_OFF_clicked()
{
    serial.write("y");
}




void LightsDialog::on_Edit_clicked()
{
    serial.setPortName("COM8");
    serial.setBaudRate(QSerialPort::Baud9600);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);
    serial.open(QIODevice::ReadWrite);
}


void LightsDialog::on_FrontL_ON_clicked()
{
    serial.write("u");
}



void LightsDialog::on_FrontL_OFF_clicked()
{
    serial.write("i");
}


void LightsDialog::on_BackL_ON_clicked()
{
    serial.write("e");
}


void LightsDialog::on_BackL_OFF_clicked()
{
    serial.write("r");
}


void LightsDialog::on_SideL_ON_clicked()
{
    serial.write("t");
}


void LightsDialog::on_SideL_OFF_clicked()
{
    serial.write("y");
}

