#ifndef RTYPE_H
#define RTYPE_H
#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <bitset>
#include <algorithm>

using namespace std;

class RType {
    private:
    vector <string> instructions;    // instruction : 0->31 | opcode (7) | rd (5) | funct3 | rs1(5) | rs2 (5) | funct7 |
    vector <string> opcode;
    vector <string> funct3;
    vector <string> funct7;

    /* Function extracts the all the integers in an instruction basically */
    /* for ex : sw x2,24(x3) : will extract 2,24,3 i.e parameters needed for MC generation.*/
    vector <int> extractint(string str) { // recieves a string and extracts all the integers and returns them in a list (vector)
        vector <int> result;
        int sum,currentint;
        for(int strIndex = 0 ; strIndex < str.size() ; strIndex++) {

            sum = 0;
            bool intfound = 0;

            while(strIndex < str.size() && isdigit(str[strIndex])) {
                currentint = str[strIndex] - '0';
                sum = sum*10 + currentint;
                strIndex++;
                intfound = 1;
            }

            if(intfound)
                result.push_back(sum);
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
            ss >> token;
            funct7.push_back(token);
        }
    }

    // checks if given command is present in the list of S Type instructions.
    bool isPresent(string command) {
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
        /*Edit this*/
        bitset <32> MachineCode;
        stringstream ss(instruction); //helpful for tokenizing space separated strings.
        vector <int> parameters = extractint(instruction); // extracted all register names, offsets etc.
        string action;
        ss >> action;
        int index = find(instructions.begin(),instructions.end(),action) - instructions.begin();
        string opcodestr,funct3str,funct7str;

        opcodestr = opcode[index];
        funct3str = funct3[index];
        funct7str = funct7[index];



        //Settting up RS1 , RS2  , RD
        bitset <5> rs2(parameters[2]),rs1(parameters[1]);
        bitset <5> rd (parameters[0]);

        for(int i=0;i<7;i++) {
            MachineCode[i] = (opcodestr[opcodestr.size()-1-i] == '0') ? 0 : 1; //copying opcode string to the opcode field
        }

        for(int i=0;i<5;i++) {
            MachineCode[i+7] = rd[i];
        }

        for(int i = 0; i<3; i++) {
            MachineCode[i+12] = (funct3str[funct3str.size()-i-1] == '0') ? 0 : 1;
        }

        for(int i=0;i<5;i++)
            MachineCode[i+15] = rs1[i];

        for(int i=0; i<5 ; i++)
            MachineCode[i+20] = rs2[i];

        for(int i=0;i<7;i++)
            MachineCode[i+25] = (funct7str[funct7str.size()-i-1] == '0') ? 0 : 1;

        return MachineCode;

    }



};

#endif // RTYPE_H
