#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

int intFromString(string& from);
void run(vector<vector<string> >& commands, map<string, int>& data, map<string, string>& dataString, map<string, char>& dataType);
void listCommands(vector<vector<string> >& commands);
void parseCode(string& code, vector<vector<string> >& commands);
string toString(int x);

string toString(int x){
  ostringstream oStream;
  oStream << x;
  return oStream.str();
}

int intFromString(string& from){
    int to = 0;
    istringstream tempStream(from);
    tempStream >> to;
    return to;
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
            if (commands[i][2][0] == '"'){
                //cout << "This is a String\n";
                dataType[commands[i][1]] = 's';
                //cout << dataType[commands[i][1]] << "\n";
                for (int j = 1; j < commands[i][2].size(); j++){
                    if (commands[i][2][j] == '\\'){
                        switch (commands[i][2][j + 1]){
                        case '"':
                            dataString[commands[i][1]] += "\"";
                            continue;
                            break;
                        case '\\':
                            cout << "in \\\\ Eorrors:\n\n\n";
                            dataString[commands[i][1]] += "\\";
                            continue;
                            break;
                        default:
                            break;
                        }
                    }
                    if (commands[i][2][j] == '\\'){
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
            else{
                dataType[commands[i][1]] = 'i';
                data[commands[i][1]] = intFromString(commands[i][2]);
            }

            if (debug){
                cout << "\nrunCommandCounter is:" << i << "\n" << "in run let \n";
                cout << commands[i][1] << " value is:" << data[commands[i][1]] << "\n\n";
            }
        }
        //add
        else if (commands[i][0] == "add "){
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
        //subtract
        else if (commands[i][0] == "sub "){
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
        //multiple
        else if (commands[i][0] == "multi "){
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
        //division
        else if (commands[i][0] == "divi "){
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
        //modulo
        else if (commands[i][0] == "modu "){
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
        //print
        else if (commands[i][0] == "print "){
            //cout << dataString[commands[i][1]] << " ******\n";
            //cout << dataType[commands[i][1]] << " ******\n";
            if (dataType[commands[i][1]] == 's'){
                cout << "variable :" << commands[i][1] <<" ";
                cout << dataString[commands[i][1]] << "\n";
            }
            else{
                cout << "variable :" << commands[i][1] <<" ";
                cout << data[commands[i][1]] << "\n";
            }
        }
        //while
        else if (commands[i][0] == "while "){
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
        //assign
        else if (commands[i][0] == "assign "){
            data[commands[i][1]] = data[commands[i][2]];
            if (debug){
                    cout << "\nrunCommandCounter is:" << i << "\n" << "in run assign \n";
                    cout << commands[i][1] << " value is:" << data[commands[i][1]] << "\n";
                    cout << commands[i][2] << " value is:" << data[commands[i][2]] << "\n\n";
            }
        }
        //if
        else if (commands[i][0] == "if "){
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
    }
}

void parseCode(string& code, vector<vector<string> >& commands){

    string temp = "";
    string valueString = "";
    string key = "";

    bool let = false;
    bool bKey = false;
    bool bValue = false;
    bool add = false;
    bool bSub = false;
    bool print = false;
    bool loop = false;
    bool bAssign = false;
    bool bDebug = false;
    bool bMulti = false;
    bool bDivi = false;
    bool bModu = false;

    // Test Loop Values
    int loopPosition[] {};
    int loopNumber = 0;
    bool bWhile = false;
    int pc = 0;

    int ifPosition[] {};
    int ifNumber = 0;
    bool bIf = false;

    vector<string> command {"","","",""};

    unsigned int commandCounter = 0;

    for (unsigned int i = 0; i < code.length(); i++){
        temp = code[i];
        valueString += temp;

        if (temp == " "){

             //debug
            if (valueString == "debug "){
                cout << "in debug \n";
                command[0] = valueString;
                cout << "variable is:" << valueString << "\n\n";
                command[1] = "?";
                command[2] = "?";
                command[3] = "?";

                commands.push_back(command);
                command.clear();
                command = {"","","",""};
                commandCounter++;
            }

            //Declare Variables
            if (valueString == "let "){
                command[0] = valueString;
                let = true;
                cout << "in let\n";
            }
            else if (let == true && bKey == false){
                command[1] = valueString;
                cout << "key is :" << command[1] << "\n";
                bKey = true;
            }
            else if (let == true && bKey == true){
                if (valueString[0] == '"'){
                    string stringString = "";
                    stringString += valueString;
                    for(int j = i; code[j] != '"'; j++){
                        //Check Escape Characters
                        if (code[j] == '\\'){
                            switch(code[j + 1]) {
                            case '"':
                                stringString += '\\';
                                stringString += '"';
                                j += 1;
                                continue;
                                break;
                            case '\\':
                                stringString += "\\\\";
                                j += 1;
                                continue;
                                break;
                            default:
                                break;
                            }
                        }
                        else{
                            stringString += code[j];
                        }
                    }
                    stringString += '"';
                    cout << "@@@@@ :" << stringString << "\n";
                    cout << "In let stage 3 <><><><>\n\n";
                    command[2] = stringString;
                    cout << "value is :" << command[2] << "\n\n";
                    commands.push_back(command);
                    let = false;
                    bKey = false;
                    command.clear();
                    command = {"","","",""};
                    commandCounter++;
                }
                else{
                    command[2] = valueString;
                    cout << "value is :" << command[2] << "\n\n";
                    commands.push_back(command);
                    let = false;
                    bKey = false;
                    command.clear();
                    command = {"","","",""};
                    commandCounter++;
                }
            }

            //ADD 2 Variables
            if (valueString == "add "){
                add = true;
                command[0] = valueString;
                cout << "in add\n";
            }

            else if(add == true && bKey == false){
                command[1] = valueString;
                cout << "storage name is :" << command[1] << "\n";
                bKey = true;
            }
            else if (add == true && bKey == true && bValue == false){
                command[2] = valueString;
                cout << "value 1 is :" << command[2] << "\n";
                bValue = true;
            }
            else if (add == true && bValue == true){
                command[3] = valueString;
                cout << "value 2 is :" << command[3] << "\n\n";
                commands.push_back(command);
                add = false;
                bKey = false;
                bValue = false;
                key.clear();
                command.clear();
                command = {"","","",""};
                commandCounter++;
            }

            //Subtract 2 Variables
            if (valueString == "sub "){
                bSub = true;
                command[0] = valueString;
                cout << "in sub\n";
            }

            else if(bSub == true && bKey == false){
                command[1] = valueString;
                cout << "storage name is :" << command[1] << "\n";
                bKey = true;
            }
            else if (bSub == true && bKey == true && bValue == false){
                command[2] = valueString;
                cout << "value 1 is :" << command[2] << "\n";
                bValue = true;
            }
            else if (bSub == true && bValue == true){
                command[3] = valueString;
                cout << "value 2 is :" << command[3] << "\n\n";
                commands.push_back(command);
                bSub = false;
                bKey = false;
                bValue = false;
                key.clear();
                command.clear();
                command = {"","","",""};
                commandCounter++;
            }

            //Multiple 2 Variables
            if (valueString == "multi "){
                bMulti = true;
                command[0] = valueString;
                cout << "in multi\n";
            }

            else if(bMulti == true && bKey == false){
                command[1] = valueString;
                cout << "storage name is :" << command[1] << "\n";
                bKey = true;
            }
            else if (bMulti == true && bKey == true && bValue == false){
                command[2] = valueString;
                cout << "value 1 is :" << command[2] << "\n";
                bValue = true;
            }
            else if (bMulti == true && bValue == true){
                command[3] = valueString;
                cout << "value 2 is :" << command[3] << "\n\n";
                commands.push_back(command);
                bMulti = false;
                bKey = false;
                bValue = false;
                key.clear();
                command.clear();
                command = {"","","",""};
                commandCounter++;
            }

            //division
            if (valueString == "divi "){
                bDivi = true;
                command[0] = valueString;
                cout << "in divi\n";
            }

            else if(bDivi == true && bKey == false){
                command[1] = valueString;
                cout << "storage name is :" << command[1] << "\n";
                bKey = true;
            }
            else if (bDivi == true && bKey == true && bValue == false){
                command[2] = valueString;
                cout << "value 1 is :" << command[2] << "\n";
                bValue = true;
            }
            else if (bDivi == true && bValue == true){
                command[3] = valueString;
                cout << "value 2 is :" << command[3] << "\n\n";
                commands.push_back(command);
                bDivi = false;
                bKey = false;
                bValue = false;
                key.clear();
                command.clear();
                command = {"","","",""};
                commandCounter++;
            }

            //modulo
            if (valueString == "modu "){
                bModu = true;
                command[0] = valueString;
                cout << "in modu\n";
            }

            else if(bModu == true && bKey == false){
                command[1] = valueString;
                cout << "storage name is :" << command[1] << "\n";
                bKey = true;
            }
            else if (bModu == true && bKey == true && bValue == false){
                command[2] = valueString;
                cout << "value 1 is :" << command[2] << "\n";
                bValue = true;
            }
            else if (bModu == true && bValue == true){
                command[3] = valueString;
                cout << "value 2 is :" << command[3] << "\n\n";
                commands.push_back(command);
                bModu = false;
                bKey = false;
                bValue = false;
                key.clear();
                command.clear();
                command = {"","","",""};
                commandCounter++;
            }

            //Print Variable
            if (valueString == "print "){
                cout << "in print \n";
                command[0] = valueString;
                print = true;
            }
            else if (print == true){
                cout << "variable is:" << valueString << "\n\n";
                command[1] = valueString;
                command[2] = "?";
                command[3] = "?";
                commands.push_back(command);
                print = false;
                command.clear();
                command = {"","","",""};
                commandCounter++;
            }

            // assign x from y
            if (valueString == "assign "){
                cout << "in assign \n";
                command[0] = valueString;
                bAssign = true;
            }
            else if (bAssign == true && bValue == false){
                command[1] = valueString;
                cout << "value 1 is:" << command[1] << "\n";
                bValue = true;
            }
            else if (bAssign == true && bValue == true){
                command[2] = valueString;
                command[3] = "?";
                cout << "value 2 is:" << command[2] << "\n";
                bAssign = false;
                bValue = false;
                commands.push_back(command);
                command.clear();
                command = {"","","",""};
                commandCounter++;
            }


            //Loop
            if (valueString == "loop "){
                cout << "in loop \n";
                command[0] = valueString;
                command[1] = commandCounter;
                loopPosition[loopNumber] = commandCounter;
                cout << "loop position is :" << loopPosition[loopNumber] << "\n\n";
                loopNumber++;

                commands.push_back(command);

                command.clear();
                command = {"","","",""};
                commandCounter++;
            }
            //While Loop
            if (valueString == "while "){
                cout << "in while \n";
                command[0] = valueString;
                bWhile = true;
            }
            else if (bWhile == true && bValue == false){
                cout << "value 1 is:" << valueString << "\n";
                command[1] = valueString;
                bValue = true;
            }
            else if (bWhile == true && bValue == true){
                command[2] = valueString;
                cout << "value 2 is:" << command[2] << "\n";
                command[3] = toString(loopPosition[loopNumber - 1]);
                cout << "loopPosition is:" << command[3] << "\n\n";

                loopNumber--;

                commands.push_back(command);

                command.clear();
                command = {"","","",""};
                bWhile = false;
                bValue = false;
                commandCounter++;
            }
            //If
            if (valueString == "if "){
                cout << "in if \n";
                command[0] = valueString;
                //ifPosition[ifNumber] = commandCounter;
                bIf = true;
                //ifNumber++;
            }
            else if (bIf == true && bValue == false){
                command[1] = valueString;
                bValue = true;
            }
            else if (bIf == true & bValue == true){
                command[2] = valueString;
                bIf = false;
                bValue = false;
                commands.push_back(command);
                command.clear();
                command = {"","","",""};
                commandCounter++;
            }
            if (valueString == "endif "){
                cout << "in endif \n";
                //commands[ifPosition[ifNumber -1]][3] = toString(commandCounter - 1);
                command[0] = valueString;
                commands.push_back(command);
                command.clear();
                command = {"","","",""};
                commandCounter++;
            }

            valueString.clear();
        }
    }
}

void listCommands(vector<vector<string> >& commands){
    for (unsigned int i = 0 ; i < commands.size(); i++ ){
        for (unsigned int j = 0; j < commands[i].size() ; j++ ){
            if (j == 0){
                cout << "command counter is:" << i << "\n";
                cout << "command is:" << commands[i][j] << "\n";
            }
            else if (j == 1){
                cout << "targer memory is:" << commands[i][j] << "\n";
            }
            else if (j == 2){
                cout << "first variable is:" << commands[i][j] << "\n";
            }
            else if (j == 3){
                cout << "second variable is:" << commands[i][j] << "\n";
            }
        }
        cout << "\n";
    }
}

void loadCode(string& code,string& filePath){
    code.clear();
    ifstream inf{filePath, ifstream::binary};
    if (!inf){
        cerr << "No File at Path " << filePath << "\n";
    }
    char ch{};
    while (inf.get(ch)){
        code += ch;
    }
}

int main(int argc, char *argv[])
{
    cout << "zil2\n" << endl;

    string code{};
    string filePath{};
    if (argc > 1){
        filePath = argv[1];
    }

    if (filePath == ""){
        cout << "Empty Path\n";
        cout << "Loading Default Path\n\n";
        filePath = "code.zil2";
    }

    loadCode(code,filePath);
    cout << code;

    map<string, int> data;
    map<string, char> dataType;
    map<string, string> dataString;
    vector<vector<string> > commands;

    parseCode(code, commands);

    listCommands(commands);

    run(commands, data, dataString, dataType);

    return 0;
}
