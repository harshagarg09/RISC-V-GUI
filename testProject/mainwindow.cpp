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
    this->count = 0;
    decode.initialise();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
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

    QPainter line12(this);
    line12.drawLine(350,620,350,690);

    QPainter line13(this);
    line13.drawLine(100,690,350,690);

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

     QPainter line21(this);
     line21.drawLine(100,295,300,295);

     QPainter line22(this);
     line22.drawLine(300,295,300,310);

     QPainter line23(this);
     line23.drawLine(100,290,370,290);

     QPainter line24(this);
     line24.drawLine(370,290,370,310);

    QPainter line25(this);
     line25.drawLine(350,510,440,510);

     QPainter line26(this);
      line26.drawLine(440,510,440,300);

      QPainter line27(this);
      line27.drawLine(440,300,400,300);

     QPainter line28(this);
      line28.drawLine(400,300,400,310);

      QPainter line29(this);
       line29.drawLine(350,510,200,510);

       QPainter line30(this);
        line30.drawLine(200,510,200,300);

        QPainter line31(this);
        line31.drawLine(200,300,290,300);

       QPainter line32(this);
        line32.drawLine(290,300,290,310);

}


void MainWindow::on_pushButton_clicked()
{
                    i++;

                    isb.isMispred = false;
                    if(end)
                        j++;
                    if(j >= 4)
                    {
                        QMessageBox::information(this,"title","Code executed successfully!!!");
                        return;

                    }
                    if(i==1){
                        if(!end){
                            fetch.get(isb,rFile);
                            if(!isb.hazard_type) iag.update(isb);
                            else iag.jumpPC(isb,isb.branch_address);
                            printOnTextEdit();

                        }
                        else
                       printOnTextEdit();
                        updateISB(isb);
                    }
                    else if(i==2) {
                        decode.decoder(isb,rFile);
                        if(isb.stall){
                            printOnTextEdit();
                            updateIfStall(isb);
                            return;
                        }
                        updateAfterDecoder(isb);
                        if(isb.isMispred) iag.jumpPC(isb,isb.nextPC);
                        if(!end){
                            if(isb.hazard_type == 2){
                                iag.jumpPC(isb, isb.branch_address);
                            }
                            fetch.get(isb,rFile);

                            printOnTextEdit();

                            updateISB(isb);
                            if(!isb.hazard_type) iag.update(isb);
                            else iag.jumpPC(isb,isb.branch_address);
                        }
                        if(end)	{
                            printOnTextEdit();
                            updateISB(isb);
                        }
                    }
                    else if(i==3) {
                        if(!isb.stall) alu.compute(isb);
                        decode.decoder(isb,rFile);
                        if(isb.stall){
                            printOnTextEdit();
                            updateIfStall(isb);
                            return;
                        }
                        updateAfterDecoder(isb);
                        if(isb.isMispred) iag.jumpPC(isb,isb.nextPC);
                        if(!end){
                            if(isb.hazard_type == 2){
                                iag.jumpPC(isb, isb.branch_address);
                            }
                            fetch.get(isb,rFile);
                            printOnTextEdit();
                            updateISB(isb);
                            if(!isb.hazard_type) iag.update(isb);
                            else iag.jumpPC(isb,isb.branch_address);
                        }
                        if(end)	{
                            printOnTextEdit();
                            updateISB(isb);
                        }
                    }
                    else if(i==4) {
                        memory(isb, *memAccess, muxy);
                        if(!isb.stall) alu.compute(isb);
                        decode.decoder(isb,rFile);
                        if(isb.stall){
                            printOnTextEdit();
                            updateIfStall(isb);
                            return;
                        }
                        updateAfterDecoder(isb);
                        if(isb.isMispred) iag.jumpPC(isb,isb.nextPC);
                        if(!end){
                            if(isb.hazard_type == 2){
                                iag.jumpPC(isb, isb.branch_address);
                            }
                            fetch.get(isb,rFile);
                            printOnTextEdit();

                            updateISB(isb);
                            if(!isb.hazard_type) iag.update(isb);
                            else iag.jumpPC(isb,isb.branch_address);
                        }
                        if(end)	{
                            printOnTextEdit();

                            updateISB(isb);
                        }
                    }
                    else{
                        writeBack(isb, regUpdate, rFile);
                        memory(isb, *memAccess, muxy);
                        if(!isb.stall) alu.compute(isb);
                        decode.decoder(isb,rFile);
                        if(isb.stall){
                            printOnTextEdit();
                            updateIfStall(isb);
                            return;
                        }
                        updateAfterDecoder(isb);
                        if(isb.isMispred) iag.jumpPC(isb,isb.nextPC);
                        if(!end){
                            if(isb.hazard_type == 2){
                                iag.jumpPC(isb, isb.branch_address);
                            }
                            fetch.get(isb,rFile);
                            printOnTextEdit();
                            updateISB(isb);
                            if(!isb.hazard_type) iag.update(isb);
                            else iag.jumpPC(isb,isb.branch_address);
                        }
                        if(end)	{
                            printOnTextEdit();
                            updateISB(isb);
                        }
                    }
                    if(isb.IR.readInt() == 0 )
                        end = true;
               //     if(isb.printRegFile || isb.printISB) print(i,isb,rFile);

     /*  if(count==0)
       {
           QFile file("C:/Users/hp/Downloads/RISC-V-GUI-master/Project/output.txt");

           if(!file.open(QFile::ReadOnly | QFile::Text))
           {
                   QMessageBox::warning(this,"title","file not open");
           }
           QTextStream in (&file);
           while(!in.atEnd())
           {
               QString text = in.readLine();
               QStringList fields = text.split( ";" );
              ins.push_back(fields);
           }

       }
       if(count<ins.size()){
                              QStringList f=ins[count];
                              ui->textEdit->setText(f[0]);
                              ui->textEdit_2->setText(f[1]);
                              ui->textEdit_3->setText(f[2]);
                              ui->textEdit_5->setText(f[3]);
                              ui->textEdit_5->setText(f[4]);
                              count++;
           }
*/

   // file.close();
}
void MainWindow::printOnTextEdit(){
    ui->textEdit->setText(QString::fromStdString(isb.instruction));
    ui->textEdit_2->setText(QString::fromStdString(isb.instructionD));
    ui->textEdit_3->setText(QString::fromStdString(isb.instructionE));
    ui->textEdit_5->setText(QString::fromStdString(isb.instructionM));
    ui->textEdit_5->setText(QString::fromStdString(isb.instructionW));

}
void MainWindow::memory(InterStateBuffers &isb,MemoryAccess &memAccess ,MUX_Y &muxy){
    if(!isb.enablePipe){
            if(isb.isMem == true){
                if(isb.insType == 4){
                    memAccess.writeWord(isb);
                    muxy.MUX_Y_SELECT = 1;
                }
                else {
                    memAccess.readWord(isb);
                    muxy.MUX_Y_SELECT = 2; // for getting register val from memory
                }
        }
        else if(isb.isjalr == true || isb.insType == 5){
            muxy.MUX_Y_SELECT = 3;
        }
        else
            muxy.MUX_Y_SELECT = 1;
        isb.RY.writeInt(muxy.output(isb));
    }
    else{
        if(isb.isMemM == true){
                if(isb.insTypeM == 4){
                    memAccess.writeWord(isb);
                    muxy.MUX_Y_SELECT = 1;
                }
                else {
                    memAccess.readWord(isb);
                    muxy.MUX_Y_SELECT = 2; // for getting register val from memory
                }
        }
        else if(isb.isjalrM == true || isb.insTypeM == 5){
            muxy.MUX_Y_SELECT = 3;
        }
        else
            muxy.MUX_Y_SELECT = 1;
        isb.RY.writeInt(muxy.output(isb));
    }
}

void MainWindow::writeBack(InterStateBuffers &isb, RegUpdate &regUpdate, Registry_File &rFile){
    if(!isb.enablePipe){
        if(isb.write_back_location != -1){
            regUpdate.update(isb,rFile, isb.write_back_location);
        }
    }
    else{
        if(isb.wblocW != -1){
            regUpdate.update(isb,rFile, isb.wblocW);
        }
    }
}
void MainWindow::updateISB(InterStateBuffers &isb){
    isb.wblocW = isb.wblocM;
    isb.wblocM = isb.wblocE;
    isb.wblocE = isb.wblocD;

    isb.returnAddW = isb.returnAddM;
    isb.returnAddM = isb.returnAddE;
    isb.returnAddE = isb.returnAddD;
    isb.returnAddD = isb.return_address;

    isb.insTypeW = isb.insTypeM;
    isb.insTypeM = isb.insTypeE;
    isb.insTypeE = isb.insTypeD;
    isb.insTypeD = isb.insType;

    isb.instructionW = isb.instructionM;
        isb.instructionM = isb.instructionE;
        isb.instructionE = isb.instructionD;
        isb.instructionD = isb.instruction;

    isb.isjalrW = isb.isjalrM;
    isb.isjalrM = isb.isjalrE;
    isb.isjalrE = isb.isjalrD;

    isb.isMemW = isb.isMemM;
    isb.isMemM = isb.isMemE;
    isb.isMemE = isb.isMemD;
}

void print(int i, InterStateBuffers &isb, Registry_File &rFile){
    cout<<"===== < Cycle "<<i<<" > ====="<<endl;
    if(isb.printRegFile) rFile.print();
    if(isb.printISB) isb.printAll();
    cout<<endl;
}

void printSummary(InterStateBuffers &isb){
    cout<<" Total Cycles \t\t\t:\t"<<isb.totalCycles<<endl;
    cout<<" Total Instructions \t\t:\t"<<isb.lines<<endl;
    cout<<" CPI \t\t\t\t:\t"<<((float)isb.totalCycles/isb.lines)<<endl;
    // cout<<" Total Data Transfer Instructions :\t"<<<<endl;
    // cout<<" Total ALU Instructions :\t"<<<<endl;
    // cout<<" Total Control Instructions :\t"<<<<endl;
    cout<<" Total Stalls \t\t\t:\t"<<isb.numStall + isb.mispredNumber*2<<endl;
    cout<<" Number of Data Hazards :\t"<<isb.dataHazardNumber<<endl;
    // cout<<" Number of Control Hazards :\t"<<<<endl;
    cout<<" Total Branch Misprediction \t:\t"<<isb.mispredNumber<<endl;
    cout<<" Stalls due to Data Hazard :\t"<<isb.numStall<<endl;
    cout<<" Stalls due to Control Hazard :\t"<<isb.mispredNumber*2<<endl;
}

void MainWindow::updateAfterDecoder(InterStateBuffers &isb){
    isb.wblocD = isb.write_back_location;
    isb.isjalrD = isb.isjalr;
    isb.isMemD = isb.isMem;
}

void MainWindow::updateIfStall(InterStateBuffers &isb){
    isb.wblocW = isb.wblocM;
    isb.wblocM = isb.wblocE;
    isb.wblocE = -1;
    isb.insTypeW = isb.insTypeM;
    isb.insTypeM = isb.insTypeE;
    isb.instructionW = isb.instructionM;
     isb.instructionM = isb.instructionE;
    isb.returnAddW = isb.returnAddM;
    isb.returnAddM = isb.returnAddE;
    isb.isjalrW = isb.isjalrM;
    isb.isjalrM = isb.isjalrE;
    isb.isMemW = isb.isMemM;
    isb.isMemM = isb.isMemE;
}

