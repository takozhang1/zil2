#include "main.h"
#include "run.h"

using namespace std;

void let(vector<vector<string> >& commands, map<string, int>& data,
    map<string, string>& dataString, map<string, char>& dataType, int i, bool debug){
    if (commands[i][2][0] == '"'){
        //cout << "This is a String\n";
        dataType[commands[i][1]] = 's';
        //cout << dataType[commands[i][1]] << "\n";
        //cout << "$@$@$@$::" << commands[i][2] << "\n";
        for (int j = 1; j < commands[i][2].size(); j++){
            if (commands[i][2][j] == '\\'){
                switch (commands[i][2][j + 1]){
                    case '"':
                        dataString[commands[i][1]] += "\"";
                        continue;
                        break;
                    case '\\':
                        dataString[commands[i][1]] += "\\\\";
                        continue;
                        break;
                    case 'n':
                        dataString[commands[i][1]] += "\\";
                        continue;
                        break;
                    default:
                        break;
                    }
                continue;
            }
            if (commands[i][2][j] == '"'){
                continue;
            }
            if (debug) {
                cout << "string chars: " << commands[i][2][j] << "\n";
            }
            dataString[commands[i][1]] += commands[i][2][j];
        }
    }
    else {
        dataType[commands[i][1]] = 'i';
        data[commands[i][1]] = intFromString(commands[i][2]);
    }
    if (debug){
        cout << "\nrunCommandCounter is:" << i << "\n" << "in run let \n";
        cout << commands[i][1] << " value is:" << data[commands[i][1]] << "\n\n";
    }
}

void add(vector<vector<string> >& commands, map<string, int>& data,
    map<string, string>& dataString, map<string, char>& dataType, int i, bool debug){
    if (dataType[commands[i][1]] == 's' && dataType[commands[i][2]] == 's' && dataType[commands[i][3]] == 's'){
        dataString[commands[i][1]] = dataString[commands[i][2]] + dataString[commands[i][3]];
    }
    else if (dataType[commands[i][1]] == 'i' && dataType[commands[i][2]] == 'i' && dataType[commands[i][3]] == 'i'){
        data[commands[i][1]] = data[commands[i][2]] + data[commands[i][3]];
    }
    else{
        cout << "Error type missmatch\n" << dataType[commands[i][1]] << " != " << dataType[commands[i][2]];
        cout << " != " << dataType[commands[i][3]] << "\n";
    }
    if (debug){
        cout << "\nrunCommandCounter is:" << i << "\n" << "in run add \n";
        cout << commands[i][1] << " value is:" << data[commands[i][1]] << "\n";
        cout << commands[i][2] << " value is:" << data[commands[i][2]] << "\n";
        cout << commands[i][3] << " value is:" << data[commands[i][3]] << "\n";
        cout << "add return value is :";
        cout << data[commands[i][2]] + data[commands[i][3]] << "\n\n";
    }
}

void multi(vector<vector<string> >& commands, map<string, int>& data,
    map<string, string>& dataString, map<string, char>& dataType, int i, bool debug){
    data[commands[i][1]] = data[commands[i][2]] * data[commands[i][3]];
    if (debug){
        cout << "\nrunCommandCounter is:" << i << "\n" << "in run multi \n";
        cout << commands[i][1] << " value is:" << data[commands[i][1]] << "\n";
        cout << commands[i][2] << " value is:" << data[commands[i][2]] << "\n";
        cout << commands[i][3] << " value is:" << data[commands[i][3]] << "\n";
        cout << "multi return value is :";
        cout << data[commands[i][2]] * data[commands[i][3]] << "\n\n";
    }
}

void sub(vector<vector<string> >& commands, map<string, int>& data,
    map<string, string>& dataString, map<string, char>& dataType, int i, bool debug){

    data[commands[i][1]] = data[commands[i][2]] - data[commands[i][3]];
    if (debug){
        cout << "\nrunCommandCounter is:" << i << "\n" << "in run sub \n";
        cout << commands[i][1] << " value is:" << data[commands[i][1]] << "\n";
        cout << commands[i][2] << " value is:" << data[commands[i][2]] << "\n";
        cout << commands[i][3] << " value is:" << data[commands[i][3]] << "\n";
        cout << "add return value is :";
        cout << data[commands[i][2]] - data[commands[i][3]] << "\n\n";
    }
}

void divi(vector<vector<string> >& commands, map<string, int>& data,
    map<string, string>& dataString, map<string, char>& dataType, int i, bool debug){
    data[commands[i][1]] = data[commands[i][2]] / data[commands[i][3]];
    if (debug){
        cout << "\nrunCommandCounter is:" << i << "\n" << "in run divi \n";
        cout << commands[i][1] << " value is:" << data[commands[i][1]] << "\n";
        cout << commands[i][2] << " value is:" << data[commands[i][2]] << "\n";
        cout << commands[i][3] << " value is:" << data[commands[i][3]] << "\n";
        cout << "divi return value is :";
        cout << data[commands[i][2]] / data[commands[i][3]] << "\n\n";
    }
}

void modu(vector<vector<string> >& commands, map<string, int>& data,
    map<string, string>& dataString, map<string, char>& dataType, int i, bool debug){
    data[commands[i][1]] = data[commands[i][2]] % data[commands[i][3]];
        if (debug){
        cout << "\nrunCommandCounter is:" << i << "\n" << "in run modu \n";
        cout << commands[i][1] << " value is:" << data[commands[i][1]] << "\n";
        cout << commands[i][2] << " value is:" << data[commands[i][2]] << "\n";
        cout << commands[i][3] << " value is:" << data[commands[i][3]] << "\n";
        cout << "modu return value is :";
        cout << data[commands[i][2]] % data[commands[i][3]] << "\n\n";
    }
}

void print(vector<vector<string> >& commands, map<string, int>& data,
    map<string, string>& dataString, map<string, char>& dataType, int i, bool debug){
    //cout << dataString[commands[i][1]] << " ******\n";
    //cout << dataType[commands[i][1]] << " ******\n";
    if (dataType[commands[i][1]] == 's'){
        //cout << "variable :" << commands[i][1] <<" ";
        //cout << dataString[commands[i][1]] << "\n";
        for (int j = 0; j < dataString[commands[i][1]].size(); j++){
            if (dataString[commands[i][1]][j] == '\\'){
                switch (dataString[commands[i][1]][j + 1]){
                    case 'n':
                        cout << "\n";
                        j += 1;
                        continue;
                       break;
                    case '\\':
                        cout << '\\';
                        j += 1;
                   continue;
                        break;
                   default:
                        break;
                }
            }
            else{
                cout << dataString[commands[i][1]][j];
            }
        }
    }
    else{
        cout << data[commands[i][1]] << "\n";
    }
}

void runWhile(vector<vector<string> >& commands, map<string, int>& data,
    map<string, string>& dataString, map<string, char>& dataType, int i, bool debug){
    if (data[commands[i][1]] != data[commands[i][2]]){
        if (debug){
            cout << "\nrunCommandCounter is:" << i << "\n" << "in run while \n";
            cout << commands[i][1] << " value is:" << data[commands[i][1]] << "\n";
            cout << commands[i][2] << " value is:" << data[commands[i][2]] << "\n";
            cout << "loop back position is:" << commands[i][3] << "\n\n";
        }
        i = intFromString(commands[i][3]);
    }
}

void runAssign(vector<vector<string> >& commands, map<string, int>& data,
    map<string, string>& dataString, map<string, char>& dataType, int i, bool debug){
    switch (dataType[commands[i][1]]){
        case 's':
            if (dataType[commands[i][2]] == 's'){
                dataString[commands[i][1]] = dataString[commands[i][2]];
            }
            else if (dataType[commands[i][2]] == 'i'){
                dataString[commands[i][1]] = toString(data[commands[i][2]]);
            }
            else{
                cout << "Error type missmatch\n" << dataType[commands[i][1]] << " != " << dataType[commands[i][2]] << "\n";
            }
            if (debug){
                cout << "\nrunCommandCounter is:" << i << "\n" << "in run assign \n";
                cout << commands[i][1] << " value is:" << dataString[commands[i][1]] << "\n";
                cout << commands[i][2] << " value is:" << dataString[commands[i][2]] << "\n\n";
            }
            break;
        case 'i':
            if (dataType[commands[i][2]] == 'i'){
                data[commands[i][1]] = data[commands[i][2]];
            }
            else if (dataType[commands[i][2]] == 's'){
                data[commands[i][1]] = intFromString(dataString[commands[i][2]]);
            }
            else{
                cout << "Error type missmatch\n" << dataType[commands[i][1]] << " != " << dataType[commands[i][2]] << "\n";
            }
            if (debug){
                cout << "\nrunCommandCounter is:" << i << "\n" << "in run assign \n";
                cout << commands[i][1] << " value is:" << dataString[commands[i][1]] << "\n";
                cout << commands[i][2] << " value is:" << dataString[commands[i][2]] << "\n\n";
            }
            break;
        default:
            break;
    }
}

void runIf(vector<vector<string> >& commands, map<string, int>& data,
    map<string, string>& dataString, map<string, char>& dataType, int i, bool debug){
    if (data[commands[i][1]] != data[commands[i][2]]){
        //if command is if add one to ifCounter
        //if command is endif subtract on from if
        int ifCounter = 1;
        unsigned int ifIter = i + 1;
        while (ifCounter){
            if (commands[ifIter][0] == "if "){
                ifCounter++;
            }
            if (commands[ifIter][0] == "endif "){
                ifCounter--;
            }
            ifIter++;
        }
        ifIter--;
        i = ifIter;
    }
}

void runInput(std::vector<std::vector<std::string> >& commands, std::map<std::string, int>& data,
    std::map<std::string, std::string>& dataString, std::map<std::string, char>& dataType, int i, bool debug){
    string temp = "";
    cin >> temp;
    //cout << temp << "<==\n";
    dataString[commands[i][1]] = temp;
    dataType[commands[i][1]] = 's';
    //cout << dataString[commands[i][1]] << "<===\n";
}

void run(vector<vector<string> >& commands, map<string, int>& data, map<string, string>& dataString, map<string, char>& dataType){
    bool debug = false;
    for (unsigned int i = 0; i < commands.size(); i++){
        //debug
        if (commands[i][0] == "debug "){
            debug = true;
        }
        //let
        else if (commands[i][0] == "let "){
            let(commands, data, dataString, dataType, i, debug);
        }
        //add
        else if (commands[i][0] == "add "){
            add(commands, data, dataString, dataType, i, debug);
        }
        //subtract
        else if (commands[i][0] == "sub "){
            sub(commands, data, dataString, dataType, i, debug);
        }
        //multiple
        else if (commands[i][0] == "multi "){
            multi(commands, data, dataString, dataType, i, debug);
        }
        //division
        else if (commands[i][0] == "divi "){
            divi(commands, data, dataString, dataType, i, debug);
        }
        //modulo
        else if (commands[i][0] == "modu "){
            modu(commands, data, dataString, dataType, i, debug);
        }
        //print
        else if (commands[i][0] == "print "){
            print(commands, data, dataString, dataType, i, debug);
        }
        //while
        else if (commands[i][0] == "while "){
            runWhile(commands, data, dataString, dataType, i, debug);
        }
        //assign
        else if (commands[i][0] == "assign "){
            runAssign(commands, data, dataString, dataType, i, debug);
        }
        //if
        else if (commands[i][0] == "if "){
            runIf(commands, data, dataString, dataType, i, debug);
        }
        //input
        else if (commands[i][0] == "input "){
            runInput(commands, data, dataString, dataType, i, debug);
        }
    }
}
