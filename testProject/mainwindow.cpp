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

  /*      QString  command( "pushd" );
        QStringList params = QStringList() << "C:\Users\hp\Documents\newvenus\ca";
        QProcess::startDetached( command, params );

        QProcess process;
        process.start("pushd", QStringList() << "Documents\newvenus\ca");
       // QProcess::execute("pushd", QStringList() <<"C:\Users\hp\Documents\newvenus\CA_RISCV_PROJECT");
        //QProcess::execute("g++ main.cpp");
        QProcess process2;
        process2.start("g++", QStringList() << "main.cpp");
        QProcess process3;
        process3.start("./a.out", QStringxx2List() );
        QMessageBox::information(this,"title","Code executed successfully!!");
*/

}

void MainWindow::paintEvent(QPaintEvent *event)
{
   /* QPainter myline(this);
    myline.drawLine(50,50,200,200);
    QPainter register_file(this);
    QPen pen;
    pen.setColor(Qt::blue);
    register_file.setPen(pen);
    register_file.drawRect(200,300,150,150);
    QPainter RA(this);
    RA.setPen(pen);
    RA.drawRect(450,400,50,50);
    QPainter RB(this);
    RB.setPen(pen);
    RB.drawRect(450,150,50,50);
    QPainter MuxA(this);
    MuxA.drawRect(600,400,50,150);
    QPainter MuxB(this);
    MuxB.drawRect(600,100,50,200);
    QPainter ALU(this);
    ALU.setPen(pen);
    ALU.drawRect(800,250,100,250);
    QPainter RZ(this);
    RZ.setPen(pen);
    RZ.drawRect(1000,350,50,50);
    QPainter RM(this);
    RM.setPen(pen);
    RM.drawRect(1000,50,50,50);
    QPainter MuxY(this);
    MuxY.drawRect(1200,300,50,150);
    QPainter MuxM(this);
    MuxM.drawRect(1200,25,50,150);
    QPainter RY(this);
    RY.setPen(pen);
    RY.drawRect(1300,350,50,50);*/
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
