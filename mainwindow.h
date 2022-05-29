#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define combox_index
#include <QMainWindow>
#include <QApplication>
#include <QTranslator>
#include <QNetworkReply>
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
    static QString IP_FIND_L;

private slots:
    void changeEvent(QEvent *e);
    void on_pushButton_clicked();
    void get_one_ip();
    void get_one_ip_requestFinished(QNetworkReply* reply);
    void on_comboBox_currentIndexChanged(int index);
    void on_lineEdit_textChanged(const QString &arg1);
    void keyPressEvent(QKeyEvent *);

private:
    QTranslator tran;
    QApplication *qapp;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
