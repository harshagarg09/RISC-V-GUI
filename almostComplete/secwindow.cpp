#include "secwindow.h"
#include "ui_secwindow.h"

secWindow::secWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::secWindow)
{
    ui->setupUi(this);
}

secWindow::~secWindow()
{
    delete ui;
}
void secWindow::paintEvent(QPaintEvent *event)
{
    QPainter line(this);
    line.drawLine(100,100,100,690);

    QPainter  rect(this);
    rect.drawRect(QRect(300,120,100,100));

    QPainter line1(this);
    line1.drawLine(100,100,350,100);

    QPainter line2(this);
    line2.drawLine(350,100,350,120);

    QPainter line3(this);
    line3.drawLine(320,220,320,250);

    QPainter line4(this);
    line4.drawLine(380,220,380,250);

    QPainter  rect1(this);
    rect1.drawRect(QRect(300,250,30,30));

    QPainter  rect2(this);
    rect2.drawRect(QRect(365,250,30,30));

    QPainter line5(this);
    line5.drawLine(320,280,320,310);

    QPainter line6(this);
    line6.drawLine(380,280,380,310);

    QPainter  rect3(this);
    rect3.drawRect(QRect(280,310,50,40));

    QPainter  rect4(this);
    rect4.drawRect(QRect(360,310,50,40));

    QPainter line7(this);
    line7.drawLine(300,350,320,390);

    QPainter line8(this);
    line8.drawLine(400,350,380,390);

    QPainter  rect5(this);
    rect5.drawRect(QRect(300,390,100,40));

    QPainter line9(this);
    line9.drawLine(350,430,350,460);

    QPainter  rect6(this);
    rect6.drawRect(QRect(320,460,60,40));

    QPainter line10(this);
    line10.drawLine(350,500,350,520);

    QPainter  rect7(this);
    rect7.drawRect(QRect(320,520,60,40));

    QPainter line11(this);
    line11.drawLine(350,560,350,580);

    QPainter  rect8(this);
    rect8.drawRect(QRect(320,580,60,40));

    QPainter line14(this);
    line14.drawLine(380,295,520,295);

    QPainter line15(this);
    line15.drawLine(520,295,520,360);

    QPainter  rect9(this);
    rect9.drawRect(QRect(500,360,60,40));

    QPainter line16(this);
    line16.drawLine(520,400,520,480);

    QPainter  rect10(this);
    rect10.drawRect(QRect(490,480,60,40));

    QPainter line17(this);
    line17.drawLine(380,600,480,600);

     QPainter line18(this);
     line18.drawLine(480,600,480,450);

     QPainter line19(this);
     line19.drawLine(480,450,500,450);

     QPainter line20(this);
     line20.drawLine(500,450,500,480);

     if(isb.from=="RZ"&&isb.to=="RA")
      {
          QPainter line29(this);
          QPen linepen(Qt::red);
          linepen.setWidth(5);
          line29.setPen(linepen);
          line29.drawLine(350,510,200,510);

          QPainter line30(this);
          line30.setPen(linepen);
          line30.drawLine(200,510,200,300);

          QPainter line31(this);
          line31.setPen(linepen);
          line31.drawLine(200,300,290,300);

           QPainter line32(this);
          line32.setPen(linepen);
         line32.drawLine(290,300,290,310);
          //line 29,line 30,line 31,line 32
      }
      else
      {
          QPainter line29(this);
           line29.drawLine(350,510,200,510);

           QPainter line30(this);
             line30.drawLine(200,510,200,300);

             QPainter line31(this);
              line31.drawLine(200,300,290,300);

             QPainter line32(this);
              line32.drawLine(290,300,290,310);
      }
       if(isb.from=="RZ"&&isb.to=="RB")
      {
          //line 25,line 26,line 27,line 28
          QPainter line25(this);
          QPen linepen(Qt::red);
          linepen.setWidth(5);
          line25.setPen(linepen);
         line25.drawLine(350,510,440,510);

          QPainter line26(this);
          line26.setPen(linepen);
          line26.drawLine(440,510,440,300);

          QPainter line27(this);
          line27.setPen(linepen);
          line27.drawLine(440,300,400,300);

           QPainter line28(this);
          line28.setPen(linepen);
          line28.drawLine(400,300,400,310);
      }
      else
      {
          QPainter line25(this);
           line25.drawLine(350,510,440,510);

           QPainter line26(this);
            line26.drawLine(440,510,440,300);

            QPainter line27(this);
            line27.drawLine(440,300,400,300);

           QPainter line28(this);
            line28.drawLine(400,300,400,310);

      }
      if(isb.from=="RY"&&isb.to=="RA")
      {
          //line 13,line 12
          if(isb.to=="RA")
          {
              //line 21,line 22
              QPainter line21(this);
              QPen linepen(Qt::red);
              linepen.setWidth(5);
              line21.setPen(linepen);
              line21.drawLine(100,295,300,295);

              QPainter line22(this);
              line22.setPen(linepen);
              line22.drawLine(300,295,300,310);

          }
          else
          {
               QPainter line21(this);
               line21.drawLine(100,295,300,295);

               QPainter line22(this);
               line22.drawLine(300,295,300,310);
          }
          if(isb.to=="RB")
          {
              //line 23,line 24
              QPainter line23(this);
              QPen linepen(Qt::red);
              linepen.setWidth(5);
              line23.setPen(linepen);
              line23.drawLine(100,290,370,290);

              QPainter line24(this);
              line24.setPen(linepen);
              line24.drawLine(370,290,370,310);
          }
          else
          {
               QPainter line23(this);
               line23.drawLine(100,290,370,290);
              QPainter line24(this);
              line24.drawLine(370,290,370,310);

          }
          QPainter line12(this);
          QPen linepen(Qt::red);
          linepen.setWidth(5);
          line12.setPen(linepen);
          line12.drawLine(350,620,350,690);

          QPainter line13(this);
          line13.setPen(linepen);
            line13.drawLine(100,690,350,690);
      }
      else
      {
          QPainter line12(this);
          line12.drawLine(350,620,350,690);

          QPainter line13(this);
          line13.drawLine(100,690,350,690);
      }



}
