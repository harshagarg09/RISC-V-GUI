#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QProcess>
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


void MainWindow::on_pushButton_clicked()
{
    QFile file("C:/Users/hp/Documents/newvenus/input.txt");
    file.open(QFile::WriteOnly | QFile::Text);
    QTextStream out(&file);
        QString text = ui->textEdit->toPlainText();
        out<<text;
        file.flush();
        file.close();
        QMessageBox::information(this,"title","Code executed successfully!!");

}

void MainWindow::paintEvent(QPaintEvent *event)
{
   
}

void MainWindow::on_pushButton_2_clicked()
{
    // count++;
     if(count==0){
     QFile file("C:/Users/hp/Documents/newvenus/output.txt");
     if(!file.open(QFile::ReadOnly | QFile::Text)){
         QMessageBox::warning(this,"title","file not open");
     }
      QTextStream in(&file);

     while(!in.atEnd()){
                QString text = in.readLine();
                QStringList fields = text.split( ";" );
                ins.push_back(fields);
    }


 }
     if(count<ins.size()){
                        QStringList f=ins[count];
                        ui->lineEdit->setText(f[0]);
                        ui->lineEdit_2->setText(f[1]);
                        ui->lineEdit_3->setText(f[2]);
                        ui->lineEdit_4->setText(f[3]);
                        ui->lineEdit_5->setText(f[4]);
                        count++;
     }

}
