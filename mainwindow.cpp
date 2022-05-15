#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "./functions.cpp"
#include "./main.cpp"
bool MainWindow::ok = false;
// QString MainWindow::IP_FOUD_L = "http://127.0.0.1:5000/";
QString MainWindow::IP_FOUD_L = "https://ip_api.yanjiajia.cn/";
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
        case QEvent::LanguageChange:
            ui->retranslateUi(this);
            break;
        default:
            break;
    }
}

void MainWindow::on_pushButton_clicked()
{
    MainWindow::get_one_ip();
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if(index==1){
        ok = tran.load(":/english.qm");

    }else if(index==0){
        ok = tran.load(":/chinese.qm");
    }
    if (ok){
        qapp->installTranslator(&tran);
    }
}

