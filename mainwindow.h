#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define combox_index
#include <QMainWindow>
#include <QApplication>
#include <QTranslator>
#include <QNetworkReply>
#include <QClipboard>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static bool ok;
    static QString IP_FOUD_L;

private slots:
    void changeEvent(QEvent *e);
    void on_pushButton_clicked();
    void get_one_ip();
    void get_one_ip_requestFinished(QNetworkReply* reply);
    void on_comboBox_currentIndexChanged(int index);

private:
    QTranslator tran;
    QApplication *qapp;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
