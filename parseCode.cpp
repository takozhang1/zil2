#include "main.h"
#include "parseCode.h"

using namespace std;

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
    bool bInput = false;
    bool bWhile = false;
    bool bIf = false;
    bool bRand = false;

    // String
    int stringStartPos = 0;
    bool qoute = false;

    vector<string> command {"","","",""};

    unsigned int commandCounter = 0;


    for (unsigned int i = 0; i < code.length(); i++){
        valueString += code[i];

        //Finding start posistion of Strings
        if (code[i] == '"' && code[i - 1] !='\\'){
            if (!qoute){
                qoute = true;
                stringStartPos = i;
                //cout << "String Start POS::" << stringStartPos << "<===\n";
            }
            else{
                qoute = false;
            }
        }

        if (code[i] == ' '){

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
                    stringString += '"';
                    for (int j = stringStartPos + 1; code[j] != '"' || code[j - 1] == '\\'; j++){
                        //cout << "Char ==>" << code[j] << "<==\n";
                        stringString += code[j];
                        //cout << "Building String::" << stringString << "\n";
                    }
                    stringString += '"';

                    cout << "@@@@@ :" << stringString << "\n";
                    //cout << "In let stage 3 <><><><>\n\n";
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
                cout << "loop position is :" << commandCounter << "\n\n";
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
                bIf = true;
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
                command[0] = valueString;
                commands.push_back(command);
                command.clear();
                command = {"","","",""};
                commandCounter++;
            }

            //input
            if (valueString == "input "){
                bInput = true;
                command[0] = valueString;
                cout << "in input\n";
            }
            else if(bInput == true && bKey == false){
                command[1] = valueString;
                cout << "storage name is :" << command[1] << "\n";
                commands.push_back(command);
                bInput = false;
                bKey = false;
                key.clear();
                command.clear();
                command = {"","","",""};
                commandCounter++;
            }

            //Random variable = range min max
            if (valueString == "rand "){
                bRand = true;
                command[0] = valueString;
                cout << "in rand\n";
            }
            else if(bRand == true && bKey == false){
                command[1] = valueString;
                cout << "storage name is :" << command[1] << "\n";
                bKey = true;
            }
            else if (bRand == true && bKey == true && bValue == false){
                command[2] = valueString;
                cout << "value 1 is :" << command[2] << "\n";
                bValue = true;
            }
            else if (bRand == true && bValue == true){
                command[3] = valueString;
                cout << "value 2 is :" << command[3] << "\n\n";
                commands.push_back(command);
                bRand = false;
                bKey = false;
                bValue = false;
                key.clear();
                command.clear();
                command = {"","","",""};
                commandCounter++;
            }

            valueString.clear();
        }
    }
}
