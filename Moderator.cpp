#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <streambuf>
#define LIMIT 144

using namespace std;

void moderator(void);
void consoleInput(void);
void fileInput(void);
void datatype(string str);
void normal(string str);
void finance(string str);
void politics(string str);
void aggregate(string str);
void communityGuidelines(string str);
void result(int pointGood, int pointBad);

int main(void){
    moderator();
    return 0;
}

void moderator(void){
    char opt1, opt2;
g1:
    cout << "\n\n\t=========================================\n";
    cout << "\t\t\tMODERATOR\n\t";
    cout << "=========================================\n\n";
    cout << "\t Choose (Input Mode):\n\n\t 1. Console Input\n\t 2. File Input\n\t 3. Exit\n\n\t";
    cout << "-----------------------------------------";
    cout << "\n\n\t Option: ";
    cin.clear();
    cin >> opt1;
    if(opt1=='1'){
        system("cls");
        consoleInput();
    }
    else if(opt1=='2'){
        system("cls");
        fileInput();
    }
    else if(opt1=='3'){
        opt2 = 'n';
        goto g2;
    }
    else{
        system("cls");
        goto g1;
    }
    cout << "\n\t Run again(Y/N): ";
    cin >> opt2;
g2:
    if(opt2=='Y' || opt2=='y'){
        system("cls");
        goto g1;
    }
    else{
        cout << "\n\t=========================================\n";
        cout << "\t\t\tSEE YOU";
        cout << "\n\t=========================================\n\n";
    }
}

void consoleInput(void){
    int strSize = 1024;
    char str[strSize]="", ch;
    cout << "\n\n\t=========================================\n";
    cout << "\t\t\tMODERATOR\n\t";
    cout << "=========================================\n\n";
    cout << "\n\tInput: ";
    cin.ignore();
    cin.getline(str, strSize);
    datatype(str);
}

void fileInput(void){
    ifstream filePtr;
    string fileName;
g1:
    cout << "\n\n\t=========================================\n";
    cout << "\t\t\tMODERATOR\n\t";
    cout << "=========================================\n\n";
    cout << "\n\t File Name: ";
    cin >> fileName;
    filePtr.open(fileName);
    if(!filePtr.is_open()){
        system("cls");
        goto g1;
    }
    string fileData((istreambuf_iterator<char>(filePtr)), istreambuf_iterator<char>());
    datatype(fileData);
    filePtr.close();
}

void datatype(string str){
    char opt;
g1:
    system("cls");
    cout << "\n\n\t=========================================\n";
    cout << "\t\t\tMODERATOR\n\t";
    cout << "=========================================\n\n";
    cout << "\n\t Choose (Data Type):\n";
    cout << "\n\t 1. Normal\n\t 2. Politics\n\t 3. Aggregate\n\t 4. Business & Finance\n\t 5. Community Guidelines\n\t 6. Exit\n\n\t";
    cout << "-----------------------------------------";
    cout << "\n\n\t Option: ";
    cin >> opt;
    if(opt=='1'){
        normal(str);
    }
    else if(opt=='2'){
        politics(str);
    }
    else if(opt=='3'){
        aggregate(str);
    }
    else if(opt=='4'){
        finance(str);
    }
    else if(opt=='5'){
        communityGuidelines(str);
    }
    else if(opt=='6'){
        cout << "\n\t=========================================\n";
        cout << "\t\t\tSEE YOU";
        cout << "\n\t=========================================\n\n";
        exit(0);
    }
    else{
        goto g1;
    }
}

void normal(string str){
    ifstream positive("normal\\positive.txt");
    ifstream negative("normal\\negative.txt");
    if(!positive.is_open() || !negative.is_open()){
        cout << "\t Cannot open file positive." << endl;
        exit(1);
    }
    system("cls");
    str = str + "/";
    char opt;
    string dbStr, tem1, tem2, posStr[LIMIT], negStr[LIMIT];
    int i, pos, index, pointGood=0, pointBad=0, lengthDbStr, lengthInput=str.length();
    while(getline(positive, dbStr)){
        pos = str.find(dbStr);
        lengthDbStr = dbStr.length();
        if(pos!=(-1)){
            tem1 = str[pos-1];
            tem2 = str[pos+lengthDbStr];
            if((tem1==" " || tem1==".") && (tem2==" " || tem2=="." || tem2=="," || tem2=="/") && (tem2!="?")){
                posStr[pointGood++] = dbStr;
            }
        }
    }
    positive.close();
    while(getline(negative, dbStr)){
        pos = str.find(dbStr);
        lengthDbStr = dbStr.length();
        if(pos!=(-1)){
            tem1 = str[pos-1];
            tem2 = str[pos+lengthDbStr];
            if((tem1==" " || tem1==".") && (tem2==" " || tem2=="." || tem2=="," || tem2=="/") && (tem2!="?")){
                negStr[pointBad++] = dbStr;
            }
        }
    }
    negative.close();
    result(pointGood, pointBad);
    if(pointGood>0 || pointBad>0){
        cout << "\t Show marked checkpoints (Y/N): ";
        cin >> opt;
        if(opt=='Y' || opt=='y'){
            cout << "\t-----------------------------------------";
            cout << "\n\n\t Positive\t\tNegative\n\n\t";
            if(pointGood>pointBad){
               index = pointGood;
            }
            else{
                index = pointBad;
            }
            for(i=0; i<index; i++){
                if(i>=pointGood){
                    cout << " \t\t\t" << negStr[i] << "\n\t";
                }
                else if(i>=pointBad){
                    cout << " " << posStr[i] << "\n\t";
                }
                else{
                    cout << " " << posStr[i] << "\t\t" << negStr[i] << "\n\t";
                }
            }
        cout << endl;
        }
    }
    cout << "\t-----------------------------------------\n";
}

void finance(string str){
    ifstream positive("finance\\positive.txt");
    ifstream negative("finance\\negative.txt");
    if(!positive.is_open() || !negative.is_open()){
        cout << "\t Cannot open file positive." << endl;
        exit(1);
    }
    system("cls");
    str = str + "/";
    char opt;
    string dbStr, tem1, tem2, posStr[LIMIT], negStr[LIMIT];
    int i, pos, index, pointGood=0, pointBad=0, lengthDbStr, lengthInput=str.length();
    while(getline(positive, dbStr)){
        pos = str.find(dbStr);
        lengthDbStr = dbStr.length();
        if(pos!=(-1)){
            tem1 = str[pos-1];
            tem2 = str[pos+lengthDbStr];
            if((tem1==" " || tem1==".") && (tem2==" " || tem2=="." || tem2=="," || tem2=="/") && (tem2!="?")){
                posStr[pointGood++] = dbStr;
            }
        }
    }
    positive.close();
    while(getline(negative, dbStr)){
        pos = str.find(dbStr);
        lengthDbStr = dbStr.length();
        if(pos!=(-1)){
            tem1 = str[pos-1];
            tem2 = str[pos+lengthDbStr];
            if((tem1==" " || tem1==".") && (tem2==" " || tem2=="." || tem2=="," || tem2=="/") && (tem2!="?")){
                negStr[pointBad++] = dbStr;
            }
        }
    }
    negative.close();
    result(pointGood, pointBad);
    if(pointGood>0 || pointBad>0){
        cout << "\t Show marked checkpoints (Y/N): ";
        cin >> opt;
        if(opt=='Y' || opt=='y'){
            cout << "\t-----------------------------------------";
            cout << "\n\n\t Positive\t\tNegative\n\n\t";
            if(pointGood>pointBad){
               index = pointGood;
            }
            else{
                index = pointBad;
            }
            for(i=0; i<index; i++){
                if(i>=pointGood){
                    cout << " \t\t\t" << negStr[i] << "\n\t";
                }
                else if(i>=pointBad){
                    cout << " " << posStr[i] << "\n\t";
                }
                else{
                    cout << " " << posStr[i] << "\t\t" << negStr[i] << "\n\t";
                }
            }
        cout << endl;
        }
    }
    cout << "\t-----------------------------------------\n";
}

void politics(string str){
    ifstream positive("politics\\positive.txt");
    ifstream negative("politics\\negative.txt");
    if(!positive.is_open() || !negative.is_open()){
        cout << "\t Cannot open file positive." << endl;
        exit(1);
    }
    system("cls");
    str = str + "/";
    char opt;
    string dbStr, tem1, tem2, posStr[LIMIT], negStr[LIMIT];
    int i, pos, index, pointGood=0, pointBad=0, lengthDbStr, lengthInput=str.length();
    while(getline(positive, dbStr)){
        pos = str.find(dbStr);
        lengthDbStr = dbStr.length();
        if(pos!=(-1)){
            tem1 = str[pos-1];
            tem2 = str[pos+lengthDbStr];
            if((tem1==" " || tem1==".") && (tem2==" " || tem2=="." || tem2=="," || tem2=="/") && (tem2!="?")){
                posStr[pointGood++] = dbStr;
            }
        }
    }
    positive.close();
    while(getline(negative, dbStr)){
        pos = str.find(dbStr);
        lengthDbStr = dbStr.length();
        if(pos!=(-1)){
            tem1 = str[pos-1];
            tem2 = str[pos+lengthDbStr];
            if((tem1==" " || tem1==".") && (tem2==" " || tem2=="." || tem2=="," || tem2=="/") && (tem2!="?")){
                negStr[pointBad++] = dbStr;
            }
        }
    }
    negative.close();
    result(pointGood, pointBad);
    if(pointGood>0 || pointBad>0){
        cout << "\t Show marked checkpoints (Y/N): ";
        cin >> opt;
        if(opt=='Y' || opt=='y'){
            cout << "\t-----------------------------------------";
            cout << "\n\n\t Positive\t\tNegative\n\n\t";
            if(pointGood>pointBad){
               index = pointGood;
            }
            else{
                index = pointBad;
            }
            for(i=0; i<index; i++){
                if(i>=pointGood){
                    cout << " \t\t\t" << negStr[i] << "\n\t";
                }
                else if(i>=pointBad){
                    cout << " " << posStr[i] << "\n\t";
                }
                else{
                    cout << " " << posStr[i] << "\t\t" << negStr[i] << "\n\t";
                }
            }
        cout << endl;
        }
    }
    cout << "\t-----------------------------------------\n";
}

void aggregate(string str){
    ifstream positive("aggregate\\positive.txt");
    ifstream negative("aggregate\\negative.txt");
    if(!positive.is_open() || !negative.is_open()){
        cout << "\t Cannot open file positive." << endl;
        exit(1);
    }
    system("cls");
    str = str + "/";
    char opt;
    string dbStr, tem1, tem2, posStr[LIMIT], negStr[LIMIT];
    int i, pos, index, pointGood=0, pointBad=0, lengthDbStr, lengthInput=str.length();
    while(getline(positive, dbStr)){
        pos = str.find(dbStr);
        lengthDbStr = dbStr.length();
        if(pos!=(-1)){
            tem1 = str[pos-1];
            tem2 = str[pos+lengthDbStr];
            if((tem1==" " || tem1==".") && (tem2==" " || tem2=="." || tem2=="," || tem2=="/") && (tem2!="?")){
                posStr[pointGood++] = dbStr;
            }
        }
    }
    positive.close();
    while(getline(negative, dbStr)){
        pos = str.find(dbStr);
        lengthDbStr = dbStr.length();
        if(pos!=(-1)){
            tem1 = str[pos-1];
            tem2 = str[pos+lengthDbStr];
            if((tem1==" " || tem1==".") && (tem2==" " || tem2=="." || tem2=="," || tem2=="/") && (tem2!="?")){
                negStr[pointBad++] = dbStr;
            }
        }
    }
    negative.close();
    result(pointGood, pointBad);
    if(pointGood>0 || pointBad>0){
        cout << "\t Show marked checkpoints (Y/N): ";
        cin >> opt;
        if(opt=='Y' || opt=='y'){
            cout << "\t-----------------------------------------";
            cout << "\n\n\t Positive\t\tNegative\n\n\t";
            if(pointGood>pointBad){
               index = pointGood;
            }
            else{
                index = pointBad;
            }
            for(i=0; i<index; i++){
                if(i>=pointGood){
                    cout << " \t\t\t" << negStr[i] << "\n\t";
                }
                else if(i>=pointBad){
                    cout << " " << posStr[i] << "\n\t";
                }
                else{
                    cout << " " << posStr[i] << "\t\t" << negStr[i] << "\n\t";
                }
            }
        cout << endl;
        }
    }
    cout << "\t-----------------------------------------\n";
}

void communityGuidelines(string str){
    ifstream cgl("communityGuidelines\\term&con.txt");
    if(!cgl.is_open()){
        cout << "\t Cannot open file positive." << endl;
        exit(1);
    }
    system("cls");
    str = str + "/";
    char opt;
    string dbStr, tem1, tem2, cglStr[LIMIT];
    int i, pos, point=0, lengthDbStr, lengthInput=str.length();
    while(getline(cgl, dbStr)){
        pos = str.find(dbStr);
        lengthDbStr = dbStr.length();
        if(pos!=(-1)){
            tem1 = str[pos-1];
            tem2 = str[pos+lengthDbStr];
            if((tem1==" " || tem1==".") && (tem2==" " || tem2=="." || tem2=="," || tem2=="/") && (tem2!="?")){
                cglStr[point++] = dbStr;
            }
        }
    }
    cgl.close();
    if(point>0){
        cout << "\t Show marked checkpoints (Y/N): ";
        cin >> opt;
        if(opt=='Y' || opt=='y'){
            cout << "\t-----------------------------------------";
            cout << "\n\n\t Check Points:\n\n";
            for(i=0; i<point; i++){
                cout << "\t " << cglStr[i] << "\n";
            }
        cout << endl;
        }
    }
    cout << "\t-----------------------------------------\n";
}

void result(int pointGood, int pointBad){
    float goodPer, badPer;
    string status;
    int total;
    total = pointGood + pointBad;
    if(total==0){
        total = 1;
    }
    goodPer = ((float)pointGood/total)*100;
    badPer = ((float)pointBad/total)*100;

    cout << "\n\n\t----------------------------------------\n";
    cout << "\t\t\tResult\n";
    cout << "\t----------------------------------------\n\n";
    if(goodPer>badPer){
        if(badPer==0){
            status = "Positive";
        }
        else if(goodPer>50 && goodPer<75){
            status = "Seems Positive";
        }
        else{
            status = "Slightly Positive";
        }
    }
    else if(badPer>goodPer){
        if(goodPer==0){
            status = "Negative";
        }
        else if(badPer>50 && badPer<75){
            status = "Seems Negative";
        }
        else{
            status = "Slightly Negative";
        }
    }
    else{
        status = "Neutral";
    }
    cout << "\t Positive Percentage: " << goodPer << "%\n";
    cout << "\t Negative Percentage: " << badPer << "%\n\n";
    cout << "\t Positive Checkpoints: " << pointGood << "\n";
    cout << "\t Negative Checkpoints: " << pointBad << "\n";
    cout << "\n\t Overall Data Status: " << status << "\n";
    cout << "\n\t----------------------------------------\n";
}
