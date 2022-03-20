#include "main.h"
#include "run.h"
#include "parseCode.h"

using namespace std;

void listCommands(vector<vector<string> >& commands);

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
        filePath = "tikTakToe.zil2";
    }

    loadCode(code,filePath);
    //cout << code;

    map<string, int> data;
    map<string, char> dataType;
    map<string, string> dataString;
    vector<vector<string> > commands;

    parseCode(code, commands);
    //List Commands for debuging
    //listCommands(commands);

    run(commands, data, dataString, dataType);

    return 0;
}
