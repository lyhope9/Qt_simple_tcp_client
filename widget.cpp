#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    tcpsocket = new QTcpSocket(this);
    connect(tcpsocket, &QTcpSocket::connected, this, &Widget::connectToServer);
    connect(tcpsocket, &QTcpSocket::readyRead, this, &Widget::ReadInformation);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::connectToServer(){
    ui->textEditRead->setText("成功和服务器进行连接");
}

void Widget::ReadInformation(){
    QByteArray temp = tcpsocket->readAll();
    ui->textEditRead->append(temp);

}

void Widget::on_btnConnect_clicked()
{
    QString ip = ui->lineEditIpAddress->text();
    quint16 port = ui->lineEditPort->text().toInt();
    tcpsocket->connectToHost(ip, port);
}

void Widget::on_btnSend_clicked()
{
    QString str = ui->textEditWrite->toPlainText();
    tcpsocket->write(str.toUtf8().data());
}


void Widget::on_btnDisconnect_clicked()
{
    tcpsocket->write(QString("客户端请求断开").toUtf8().data());
    ui->textEditRead->append(QString("断开连接"));
    tcpsocket->disconnectFromHost();
}
