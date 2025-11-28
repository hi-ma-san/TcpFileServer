#ifndef TCPFILESERVER_H
#define TCPFILESERVER_H

#include <QDialog>
#include <QtNetwork>
#include <QtWidgets>

class TcpFileServer : public QDialog
{
    Q_OBJECT

public:
    TcpFileServer(QWidget *parent = nullptr);
    ~TcpFileServer();

public slots:
    void start();
    void acceptConnection();
    void updateServerProgress();
    void displayError(QAbstractSocket::SocketError socketError);
private:
    QProgressBar        *serverProgressBar;
    QLabel              *serverStatusLabel;
    QPushButton         *startButton;
    QPushButton         *quitButton;
    QDialogButtonBox    *buttonBox;

    //QtcpServer用於接收client端接收請求
    //當QTcpServer物件接收到client請求後創建一個QTcpSocket物件與client端進行連線 (newConnection)
    //並繼續等待其他client發起連線請求 如果有多個連線請求則會同時創建多個QTcpSocket
    QTcpServer      tcpServer;
    QTcpSocket      *tcpServerConnection;
    qint64          totalBytes;
    qint64          byteReceved;
    qint64          fileNameSize;
    QString         fileName;
    QFile           *localFile;
    QByteArray      inBlock;

};
#endif // TCPFILESERVER_H
