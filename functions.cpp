#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QDebug>
#include <QClipboard>

void MainWindow::get_one_ip(){
    QJsonDocument doc(QJsonObject {{"ip",ui->lineEdit->text()}});
    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QNetworkAccessManager* naManager = new QNetworkAccessManager(this);
    QMetaObject::Connection connRet = QObject::connect(naManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(get_one_ip_requestFinished(QNetworkReply*)));
    Q_ASSERT(connRet);

    request.setUrl(QUrl(MainWindow::IP_FIND_L + "get_one_ip/"));
    naManager->post(request, doc.toJson());
}
void MainWindow::get_one_ip_requestFinished(QNetworkReply* reply) {
    QVariant reason = reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
    QNetworkReply::NetworkError err = reply->error();
    if(err != QNetworkReply::NoError) {
        qDebug() << "Failed: " << reply->errorString();
        QMessageBox::critical(this,tr("出错了！"),reply->errorString());
    }
    else {
        QJsonObject obj = QJsonDocument::fromJson(reply->readAll()).object();
        QString o = obj["ip_from"].toString();
        if (QMessageBox::question(this,tr("IP来源查询完成，复制到剪贴板？"),tr("IP来源：")+o,QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes)
                ==QMessageBox::Yes){
                 qapp->clipboard()->setText(o);
        }
    }
}
