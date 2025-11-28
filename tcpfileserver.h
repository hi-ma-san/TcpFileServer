#ifndef TCPFILESERVER_H
#define TCPFILESERVER_H

#include <QDialog>

class TcpFileServer : public QDialog
{
    Q_OBJECT

public:
    TcpFileServer(QWidget *parent = nullptr);
    ~TcpFileServer();
};
#endif // TCPFILESERVER_H
