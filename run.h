#ifndef RUN_H_INCLUDED
#define RUN_H_INCLUDED
//#include "main.h"

void run(std::vector<std::vector<std::string> >& commands, std::map<std::string, int>& data,
    std::map<std::string, std::string>& dataString, std::map<std::string, char>& dataType);
void let(std::vector<std::vector<std::string> >& commands, std::map<std::string, int>& data,
    std::map<std::string, std::string>& dataString, std::map<std::string, char>& dataType, int i, bool debug);
void add(std::vector<std::vector<std::string> >& commands, std::map<std::string, int>& data,
    std::map<std::string, std::string>& dataString, std::map<std::string, char>& dataType, int i, bool debug);
void sub(std::vector<std::vector<std::string> >& commands, std::map<std::string, int>& data,
    std::map<std::string, std::string>& dataString, std::map<std::string, char>& dataType, int i, bool debug);
void multi(std::vector<std::vector<std::string> >& commands, std::map<std::string, int>& data,
    std::map<std::string, std::string>& dataString, std::map<std::string, char>& dataType, int i, bool debug);
void divi(std::vector<std::vector<std::string> >& commands, std::map<std::string, int>& data,
    std::map<std::string, std::string>& dataString, std::map<std::string, char>& dataType, int i, bool debug);
void modu(std::vector<std::vector<std::string> >& commands, std::map<std::string, int>& data,
    std::map<std::string, std::string>& dataString, std::map<std::string, char>& dataType, int i, bool debug);
void print(std::vector<std::vector<std::string> >& commands, std::map<std::string, int>& data,
    std::map<std::string, std::string>& dataString, std::map<std::string, char>& dataType, int i, bool debug);
int runWhile(std::vector<std::vector<std::string> >& commands, std::map<std::string, int>& data,
    std::map<std::string, std::string>& dataString, std::map<std::string, char>& dataType, int i, bool debug);
void runAssign(std::vector<std::vector<std::string> >& commands, std::map<std::string, int>& data,
    std::map<std::string, std::string>& dataString, std::map<std::string, char>& dataType, int i, bool debug);
int runIf(std::vector<std::vector<std::string> >& commands, std::map<std::string, int>& data,
    std::map<std::string, std::string>& dataString, std::map<std::string, char>& dataType, int i, bool debug);
void runInput(std::vector<std::vector<std::string> >& commands, std::map<std::string, int>& data,
    std::map<std::string, std::string>& dataString, std::map<std::string, char>& dataType, int i, bool debug);
void runRand(std::vector<std::vector<std::string> >& commands, std::map<std::string, int>& data,
    std::map<std::string, std::string>& dataString, std::map<std::string, char>& dataType, int i, bool debug);

#endif // RUN_H_INCLUDED
