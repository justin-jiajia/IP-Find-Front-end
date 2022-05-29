#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "./main.cpp"
#include "./functions.cpp"
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QKeyEvent>
bool MainWindow::ok = false;
// QString MainWindow::IP_FIND_L = "http://127.0.0.1:5000/";
QString MainWindow::IP_FIND_L = "https://ip_api.yanjiajia.cn/";
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->geometry().size());
    QRegularExpression re("^(?:(?:25[0-5]|2[0-4][0-9]|1[0-9][0-9]|0?[0-9]?[1-9]|0?[1-9]0)\\.)(?:(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){2}(?:25[0-4]|2[0-4][0-9]|1[0-9][0-9]|0?[0-9]?[1-9]|0?[1-9]0)$");
    ui->lineEdit->setValidator(new QRegularExpressionValidator(re,this));
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
        if (ok){
            qapp->installTranslator(&tran);
        }

    }else if(index==0){
            qapp->removeTranslator(&tran);
    }
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    ui->pushButton->setEnabled(ui->lineEdit->hasAcceptableInput());
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
   switch (e->key())
   {
   case Qt::Key_Enter :
       if (ui->lineEdit->hasAcceptableInput()) {
           MainWindow::get_one_ip();
       }
       break;
   }
}
