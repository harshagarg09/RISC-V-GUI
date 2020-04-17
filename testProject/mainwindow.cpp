#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->count=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked()
{
   // count++;
    if(count==0){
    QFile file("C:/Users/hp/Documents/venus/input.txt");
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"title","file not open");
    }
     QTextStream in(&file);

    while(!in.atEnd()){
               QString text = in.readLine();
               QStringList fields = text.split( ";" );
               ins.push_back(fields);
              /* ui->lineEdit->setText(fields[0]);
               ui->lineEdit_2->setText(fields[1]);
               ui->lineEdit_3->setText(fields[2]);
               ui->lineEdit_4->setText(fields[3]);
               ui->lineEdit_5->setText(fields[4]);
*/
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
