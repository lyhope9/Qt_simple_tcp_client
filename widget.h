#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTcpSocket>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    void connectToServer();
    void ReadInformation();

private slots:

    void on_btnConnect_clicked();

    void on_btnSend_clicked();

    void on_btnDisconnect_clicked();

private:
    Ui::Widget *ui;

    QTcpSocket *tcpsocket;
};

#endif // WIDGET_H
