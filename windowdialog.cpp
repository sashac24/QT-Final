#include "windowdialog.h"
#include "ui_windowdialog.h"
#include "secdialog.h"
#include <QSerialPort>
#include <QSerialPortInfo>

QSerialPort serio;

SecDialog *secDialog2;

WindowDialog::WindowDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowDialog)
{
    ui->setupUi(this);
}

WindowDialog::~WindowDialog()
{
    delete ui;
    serio.close();
}

void WindowDialog::on_pushButton_BackHome_clicked()
{
    hide();
    secDialog2 = new SecDialog(this);
    secDialog2->show();
    serio.close();
}


void WindowDialog::on_pushButton_clicked()
{
    hide();
    addWindowDialog = new AddWindowDialog(this);
    addWindowDialog->show();
}


void WindowDialog::on_FrontW_Open_clicked()
{
    serio.write("o");
}


void WindowDialog::on_FrontW_Close_clicked()
{
    serio.write("p");
}


void WindowDialog::on_BackW_Open_clicked()
{
    serio.write("o");
}


void WindowDialog::on_BackW_Close_clicked()
{
    serio.write("p");
}


void WindowDialog::on_SideW_Open_clicked()
{
    serio.write("o");
}


void WindowDialog::on_SideW_Close_clicked()
{
    serio.write("p");
}


void WindowDialog::on_Edit_clicked()
{
    serio.setPortName("COM8");
    serio.setBaudRate(QSerialPort::Baud9600);
    serio.setDataBits(QSerialPort::Data8);
    serio.setParity(QSerialPort::NoParity);
    serio.setStopBits(QSerialPort::OneStop);
    serio.setFlowControl(QSerialPort::NoFlowControl);
    serio.open(QIODevice::ReadWrite);
}

