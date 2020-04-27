#include "mainwindow.h"

#include <QApplication>
#include<string>
#include<QFile>
#include<QTextStream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
 /*   RType rTypeInsObj;
        IType iTypeInsObj;
        SBType sbTypeInsObj;
      SType sTypeInsObj;
        UJType ujTypeInsObj;
        UType uTypeInsObj;

    //    InterStateBuffers isb;

        vector<string> labelNames;
        vector<int> labelLineNumber;

        int insType;
        int lineNo=0;

        string inputFileName = "input1.txt";
        string outputFileName = "machineCode.txt";
        string basicCodeFileName = "basicCode.txt";

        // Directory path to source instruction text files
        string dir = "C:/Users/hp/Downloads/RISC-V-GUI-master/Project/instruction/";

        rTypeInsObj.initialise(dir + "RType.txt");
        iTypeInsObj.initialise(dir + "IType.txt");
        sbTypeInsObj.initialise(dir + "SBType.txt");
      sTypeInsObj.initialise(dir + "SType.txt");
        ujTypeInsObj.initialise(dir + "UJType.txt");
        uTypeInsObj.initialise(dir + "UType.txt");


        MemoryAccess memAccess;

        assembler_initiate(memAccess);

        ifstream iFile("C:/Users/hp/Downloads/RISC-V-GUI-master/Project/input1.txt", ios :: in);
        ofstream oFile("C:/Users/hp/Downloads/RISC-V-GUI-master/Project/machineCode.txt");
        ofstream oFile2("C:/Users/hp/Downloads/RISC-V-GUI-master/Project/basicCode.txt");

        cout<<"\n::::::::::  RISC V SIMULATOR :::::::::::::\n\n"<<endl;

        //Find All Labels in the input file
        findLabels(inputFileName,labelNames,labelLineNumber);

        if(!iFile.is_open())
            cout<<"Error in reading input file";
        else{
            bitset<32> machineCode;
            string line;
            while(getline(iFile,line)) {
                // Skip Label descriptions
                size_t found = line.find(':');
                if(found != string::npos) continue;

                lineNo++;
                // replacing sp with x2
                for(int i=1;i<(line.size()-2);i++){
                    if(line[i]=='s' &&line[i+1]=='p'&&(line[i-1]==' '||line[i-1]==','||line[i-1]=='(')&&(line[i+2]==' ' ||line[i+2]==','||line[i+2]==')'||line[i+2]=='\n')){
                        line[i]='x';
                        line[i+1]='2';
                    }
                }

                // replacing labels
                for(int i=0;i<labelNames.size();i++){
                    size_t found = line.find(labelNames[i]);
                    if(found != string::npos){
                        string newline;
                        for(int j=0;j<found;j++) newline.push_back(line[j]);
                        int offset = labelLineNumber[i] - lineNo -i;
                    //	offset *= 4; // Multiplying offset by 4
                        ostringstream numStr;
                        numStr << offset;
                        string intStr = numStr.str();
                        line = newline + intStr;
                    }
                }

                if(rTypeInsObj.isPresent(line)) {
                    machineCode = rTypeInsObj.decode(line);
                    insType = 1;
                }
                else if(iTypeInsObj.isPresent(line)) {
                    machineCode = iTypeInsObj.decode(line);
                    insType = 2;
                }
                else if(sbTypeInsObj.isPresent(line)) {
                    machineCode = sbTypeInsObj.decode(line);
                    insType = 3;
                }
                else if(sTypeInsObj.isPresent(line)) {
                    machineCode = sTypeInsObj.decode(line);
                    insType = 4;
                }
                else if(ujTypeInsObj.isPresent(line)) {
                    machineCode = ujTypeInsObj.decode(line);
                    insType = 5;
                }
                else if(uTypeInsObj.isPresent(line)) {
                    machineCode = uTypeInsObj.decode(line);
                    insType = 6;
                }
                else {
                    cout<<"Hello\n";
                    cout<<"ERROR !! Instuction not identified : "<<line<<endl;
                    machineCode = bitset<32>(0);
                    insType = -1;
                }
                oFile <<lineNo<<" "<< machineCode <<" "<< insType << endl;
                oFile2 <<lineNo<<" "<< line << endl;
            }
            oFile<<lineNo+1<<" 0 0"<<endl;
  //          isb.lines = lineNo;
    //        isb.init_btb();
        }
        iFile.close();
        oFile.close();
        oFile2.close();

        Registry_File rFile;
        Fetch fetch;
        MUX_Y muxy;
        Decode decode;
        RegUpdate regUpdate;
        ALU alu;
        IAG iag;
        decode.initialise();

        cout<<">>> Modes <<<"<<endl;
        cout<<"  1) Without Pipelining\n  2) With Pipelining but no data forwarding\n";
        cout<<"  3) With Pipelining and data forwarding\n\n";
        cout<<" Enter your choice : ";

        int ch;
        bool runStepByStep = false;
       // cin>>ch;
        ch=3;
    /*    if(ch ==1){
            isb.enablePipe = false;
            cout<<" Show register value after every cycle ? (y/n)  ";
            char c;
            //cin>>c;
            c='y';
            if(c=='y'||c=='Y') isb.printRegFile = true;
            else isb.printRegFile = false;
            isb.printISB = false;
            cout<<" Run step by step ? (y/n)  ";
            //cin>>c;
            c='y';
            if(c=='y'||c=='Y') runStepByStep = true;
            else runStepByStep = false;
        }

        else if(ch == 2){
            isb.enablePipe = true;
            isb.enableDF = false;
            char c;
            cout<<" Show register value after every cycle ? (y/n)  ";
            //cin>>c;
            c='Y';
            if(c=='y'||c=='Y') isb.printRegFile = true;
            else isb.printRegFile = false;
            cout<<" Show inter state buffer values after every cycle ? (y/n)  ";
            //cin>>c;
            c='Y';
            if(c=='y'||c=='Y') isb.printISB = true;
            else isb.printISB = false;
        }*/
 /*    else if(ch == 3) {
            isb.enablePipe = true;
            isb.enableDF = true;
            char c;
            cout<<" Show register value after every cycle ? (y/n)  ";
            //cin>>c;
            c='y';
            if(c=='y'||c=='Y') isb.printRegFile = true;
            else isb.printRegFile = false;
       //     cout<<" Show inter state buffer values after every cycle ? (y/n)  ";
            c='y';
           // cin>>c;
            if(c=='y'||c=='Y') isb.printISB = true;
            else isb.printISB = false;
   //     }
   //     else{ cout<<" invalid choice !\n"; return 0;}

    // If pipeline is disabled
   /*     if(!isb.enablePipe){
            int i = 0;
            char k;
            while(1){
                i++;
                if(runStepByStep){
                    k = 'n';
                    while(k != 'r' && k != 'R'){
                        cout<<"\n RUN CYCLE NUMBER : "<<i<<" ? "<<" ( enter 'r' to run & 'e' to terminate) "<<endl;
                      k='r';
                        //cin>>k;
                    }
                }
                fetch.get(isb,rFile);
                if(isb.IR.readInt() == 0 || k == 'e' || k == 'E')
                    break;

                decode.decoder(isb,rFile);
                alu.compute(isb);
                memory(isb, memAccess, muxy);
                writeBack(isb, regUpdate, rFile);
                iag.step(isb,alu);
                isb.resetAll();

                if(isb.printRegFile) print(i,isb,rFile);
            }
            isb.totalCycles = i-1;
            cout<<"\n\n---------------- Code executed succesfully ----------------\n\n"<<endl;
            cout<<" Final register values :\n";
            rFile.print();
            cout<<" Summary :\n";
            printSummary(isb);
        }*/

    // If pipeline is enabled with data forwarding
   /*     if(isb.enablePipe && isb.enableDF){
            bool end = false;
            int i = 0,j=0;
            while(1){
                i++;

                isb.isMispred = false;
                if(end)
                    j++;
                if(j >= 4)
                    break;

                if(i==1){
                    if(!end){
                        fetch.get(isb,rFile);
                        if(!isb.hazard_type) iag.update(isb);
                        else iag.jumpPC(isb,isb.branch_address);
                    }
                    updateISB(isb);
                }
                else if(i==2) {
                    decode.decoder(isb,rFile);
                    if(isb.stall){
                        updateIfStall(isb);
                        continue;
                    }
                    updateAfterDecoder(isb);
                    if(isb.isMispred) iag.jumpPC(isb,isb.nextPC);
                    if(!end){
                        if(isb.hazard_type == 2){
                            iag.jumpPC(isb, isb.branch_address);
                        }
                        fetch.get(isb,rFile);
                        updateISB(isb);
                        if(!isb.hazard_type) iag.update(isb);
                        else iag.jumpPC(isb,isb.branch_address);
                    }
                    if(end)	updateISB(isb);
                }
                else if(i==3) {
                    if(!isb.stall) alu.compute(isb);
                    decode.decoder(isb,rFile);
                    if(isb.stall){
                        updateIfStall(isb);
                        continue;
                    }
                    updateAfterDecoder(isb);
                    if(isb.isMispred) iag.jumpPC(isb,isb.nextPC);
                    if(!end){
                        if(isb.hazard_type == 2){
                            iag.jumpPC(isb, isb.branch_address);
                        }
                        fetch.get(isb,rFile);
                        updateISB(isb);
                        if(!isb.hazard_type) iag.update(isb);
                        else iag.jumpPC(isb,isb.branch_address);
                    }
                    if(end)	updateISB(isb);
                }
                else if(i==4) {
                    memory(isb, memAccess, muxy);
                    if(!isb.stall) alu.compute(isb);
                    decode.decoder(isb,rFile);
                    if(isb.stall){
                        updateIfStall(isb);
                        continue;
                    }
                    updateAfterDecoder(isb);
                    if(isb.isMispred) iag.jumpPC(isb,isb.nextPC);
                    if(!end){
                        if(isb.hazard_type == 2){
                            iag.jumpPC(isb, isb.branch_address);
                        }
                        fetch.get(isb,rFile);
                        updateISB(isb);
                        if(!isb.hazard_type) iag.update(isb);
                        else iag.jumpPC(isb,isb.branch_address);
                    }
                    if(end)	updateISB(isb);
                }
                else{
                    writeBack(isb, regUpdate, rFile);
                    memory(isb, memAccess, muxy);
                    if(!isb.stall) alu.compute(isb);
                    decode.decoder(isb,rFile);
                    if(isb.stall){
                        updateIfStall(isb);
                        continue;
                    }
                    updateAfterDecoder(isb);
                    if(isb.isMispred) iag.jumpPC(isb,isb.nextPC);
                    if(!end){
                        if(isb.hazard_type == 2){
                            iag.jumpPC(isb, isb.branch_address);
                        }
                        fetch.get(isb,rFile);
                        updateISB(isb);
                        if(!isb.hazard_type) iag.update(isb);
                        else iag.jumpPC(isb,isb.branch_address);
                    }
                    if(end)	updateISB(isb);
                }
                if(isb.IR.readInt() == 0 )
                    end = true;
                if(isb.printRegFile || isb.printISB) print(i,isb,rFile);
            }
            isb.totalCycles = i-1;
            cout<<"\n\n---------------- Code executed succesfully ----------------\n\n"<<endl;
            cout<<" Final register values :\n";
            rFile.print();
            cout<<" Summary :\n";
            printSummary(isb);
        }

        // If pipeline is enabled without data forwarding
   /*     if(isb.enablePipe && !isb.enableDF){
            bool end = false, skipExecute = false;
            int i = 0,j=0;
            while(1){
                i++;
                isb.isMispred = false;
                if(end)
                    j++;
                if(j >= 4)
                    break;

                if(i==1){
                    if(!end){
                        fetch.get(isb,rFile);
                        if(!isb.hazard_type) iag.update(isb);
                        else iag.jumpPC(isb,isb.branch_address);
                    }
                    updateISB(isb);
                }
                else if(i==2) {
                    decode.decoder(isb,rFile);
                    if(isb.stall){
                        updateIfStall(isb);
                        continue;
                    }
                    updateAfterDecoder(isb);
                    if(isb.isMispred) iag.jumpPC(isb,isb.nextPC);
                    if(!end){
                        if(isb.hazard_type == 2){
                            iag.jumpPC(isb, isb.branch_address);
                        }
                        fetch.get(isb,rFile);
                        updateISB(isb);
                        if(!isb.hazard_type) iag.update(isb);
                        else iag.jumpPC(isb,isb.branch_address);
                    }
                    if(end)	updateISB(isb);
                }
                else if(i==3) {
                    if(!isb.stall) alu.compute(isb);
                    decode.decoder(isb,rFile);
                    if(isb.stall){
                        updateIfStall(isb);
                        continue;
                    }
                    updateAfterDecoder(isb);
                    if(isb.isMispred) iag.jumpPC(isb,isb.nextPC);
                    if(!end){
                        if(isb.hazard_type == 2){
                            iag.jumpPC(isb, isb.branch_address);
                        }
                        fetch.get(isb,rFile);
                        updateISB(isb);
                        if(!isb.hazard_type) iag.update(isb);
                        else iag.jumpPC(isb,isb.branch_address);
                    }
                    if(end)	updateISB(isb);
                }
                else if(i==4) {
                    memory(isb, memAccess, muxy);
                    if(!isb.stall) alu.compute(isb);
                    decode.decoder(isb,rFile);
                    if(isb.stall){
                        updateIfStall(isb);
                        continue;
                    }
                    updateAfterDecoder(isb);
                    if(isb.isMispred) iag.jumpPC(isb,isb.nextPC);
                    if(!end){
                        if(isb.hazard_type == 2){
                            iag.jumpPC(isb, isb.branch_address);
                        }
                        fetch.get(isb,rFile);
                        updateISB(isb);
                        if(!isb.hazard_type) iag.update(isb);
                        else iag.jumpPC(isb,isb.branch_address);
                    }
                    if(end)	updateISB(isb);
                }
                else{
                    writeBack(isb, regUpdate, rFile);
                    memory(isb, memAccess, muxy);
                    if(!isb.stall) alu.compute(isb);
                    decode.decoder(isb,rFile);
                    if(isb.stall){
                        updateIfStall(isb);
                        continue;
                    }
                    updateAfterDecoder(isb);
                    if(isb.isMispred) iag.jumpPC(isb,isb.nextPC);
                    if(!end){
                        if(isb.hazard_type == 2){
                            iag.jumpPC(isb, isb.branch_address);
                        }
                        fetch.get(isb,rFile);
                        updateISB(isb);
                        if(!isb.hazard_type) iag.update(isb);
                        else iag.jumpPC(isb,isb.branch_address);
                    }
                    if(end)	updateISB(isb);
                }
                if(isb.IR.readInt() == 0 )
                    end = true;
                if(isb.printRegFile || isb.printISB) print(i,isb,rFile);
            }
            isb.totalCycles = i-1;
            cout<<"\n\n---------------- Code executed succesfully ----------------\n\n"<<endl;
            cout<<" Final register values :\n";
            rFile.print();
            cout<<" Summary :\n";
            printSummary(isb);
        }*/
      //  return 0;
    w.show();
    return a.exec();
}
/*
void findLabels(string inputFileName, vector<string> &labelNames, vector<int> &labelLineNumber){
    ifstream iFile("C:/Users/hp/Downloads/RISC-V-GUI-master/Project/input1.txt");
    if(iFile.is_open()){
        int lineNo = 0;
        string line;
       // cout<<"Hi\n";
        while(getline(iFile,line)) {
           // cout<<"HEllo\n";
//            cout<<line<<endl;
            lineNo++;
            size_t found = line.find(':');
            if(found != string::npos){
                string labelName;
                int i=0;
                while(!isalnum(line[i])) i++;
                while(line[i]!=':' && i<line.size()) labelName.push_back(line[i++]);
                labelNames.push_back(labelName);
                labelLineNumber.push_back(lineNo);
            }
        }
    }
    iFile.close();
}

void memory(InterStateBuffers &isb,MemoryAccess &memAccess ,MUX_Y &muxy){
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

void writeBack(InterStateBuffers &isb, RegUpdate &regUpdate, Registry_File &rFile){
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

void updateISB(InterStateBuffers &isb){
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

void updateAfterDecoder(InterStateBuffers &isb){
    isb.wblocD = isb.write_back_location;
    isb.isjalrD = isb.isjalr;
    isb.isMemD = isb.isMem;
}

void updateIfStall(InterStateBuffers &isb){
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
*/
