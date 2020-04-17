#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
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
    QFile file("C:/Users/K.m.C/Documents/Project/output.txt");

    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
            QMessageBox::warning(this,"title","file not open");
    }
    QTextStream in (&file);
    while(!in.atEnd())
    {
        QString text = in.readLine();
        QStringList fields = text.split( ";" );
        ui->textEdit->setPlainText(fields[0]);
        ui->textEdit_2->setPlainText(fields[1]);
        ui->textEdit_3->setPlainText(fields[2]);
        ui->textEdit_5->setPlainText(fields[3]);
        ui->textEdit_4->setPlainText(fields[4]);
    }

    file.close();
}
