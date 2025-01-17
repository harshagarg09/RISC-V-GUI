#ifndef SBTYPE_H
#define SBTYPE_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <bitset>
#include <algorithm>

using namespace std;

class SBType {

    // instruction :- imm[12] | imm [10:5] | rs2 | rs1 | funct3 | imm[4:1] | imm[11] | opcode
    vector<string> instructions;
    vector<string> opcode;
    vector<string> funct3;

    /* Function extracts the all the integers in an instruction basically */
    /* for ex : beq x2,x3,offset : will extract 2,3 i.e parameters needed for MC generation.*/
    vector <int> extractint(string str) {
        // recieves a string and extracts all the integers and returns them in a list (vector)
        // countCommas counts the commas to ensure no numbers are picked off the LABEL.
        vector <int> result;
        int sum,currentint, sum2;
        for(int strIndex = 0 ; strIndex < str.size() ; strIndex++) {

            sum = 0;
            bool intfound = 0, intfound2 = 0;

            while(strIndex < str.size() && isdigit(str[strIndex])) {
                currentint = str[strIndex] - '0';
                sum = sum*10 + currentint;
                strIndex++;
                intfound = 1;
            }

            if(str[strIndex] == '-'){
                sum2 = 0;
                strIndex++;
                while(strIndex < str.size() && isdigit(str[strIndex])){
                    currentint = str[strIndex] - '0';
                    sum2 = sum2*10 + currentint;
                    strIndex++;
                    intfound2 = 1;
                }
                sum2 = sum2*(-1);
            }

            if(intfound)
                result.push_back(sum);

            if(intfound2)
                result.push_back(sum2);
        }

        return result; //returning vector of extracted parameters
    }


    public:

    // initialise the vectors with their respective values from the input file.
    void initialise (string filename) {
        ifstream ifile(filename);
        string line;
        while(getline(ifile,line)) {
            stringstream ss(line);
            string token;
            ss >> token;
            instructions.push_back(token);
            ss >> token;
            opcode.push_back(token);
            ss >> token;
            funct3.push_back(token);
        }
    }

    bool isPresent(string command)
    {
        stringstream ss(command);
        string ins;
        ss >> ins;
        vector <string> :: iterator it = find(instructions.begin(),instructions.end(),ins);
        if(it == instructions.end())
        return false;
        else
        return true;
    }

    bitset <32> decode (string instruction) {
        bitset <32> MachineCode;
        stringstream ss(instruction); //helpful for tokenizing space separated strings.
        vector <int> parameters = extractint(instruction); // extracted all register names, offsets etc.
        string action;
        ss >> action;
        int index = find(instructions.begin(),instructions.end(),action) - instructions.begin();
        string opcodestr,funct3str;

        opcodestr = opcode[index];
        funct3str = funct3[index];
        bitset <12> immediate(parameters[2]);//The label offset has been taken care of
        bitset <5> rs1(parameters[0]),rs2(parameters[1]);

        for(int i=0;i<7;i++)
            MachineCode[i] = (opcodestr[opcodestr.size()-1-i] == '0') ? 0 : 1; //copying opcode string to the opcode field

        MachineCode[7] = immediate[10];

        for(int i=0;i<4;i++)
            MachineCode[i+8] = immediate[i];


        for(int i = 0; i<3; i++)
            MachineCode[i+12] = (funct3str[funct3str.size()-i-1] == '0') ? 0 : 1;

        for(int i=0;i<5;i++)
            MachineCode[i+15] = rs1[i];

        for(int i=0; i<5 ; i++)
            MachineCode[i+20] = rs2[i];

        for(int i=0;i<6;i++)
            MachineCode[i+25] = immediate[i+4];

        MachineCode[31] = immediate[11];

        return MachineCode;

    }
};
#endif // SBTYPE_H
