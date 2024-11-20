#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "lexer.hpp"

using namespace std;

int yyparse();
int yylex();

int main(int argc, char *argv[]){
    ifstream file(argv[1]);
    string line;
    int c=0;

    if(file.is_open()){
        stringstream buffer;
        buffer << file.rdbuf(); 
        std::string fileContent = buffer.str();
        cout << "LEX TABLE" << endl;
        cout << "ROW|LEX|TOKEN|ATTRIBUTE" << endl;
        for (Token token: getTokens(fileContent)) {
            cout << "Row:" << token.line << "|" << token.lex << "|" << token.typeLex << "|" << token.attr << "|" << std::endl;
            c++;
        }
    } else {
        cerr << "Unable to open file for some reason buddy." << "\n";
    }
    file.close();
    cout << "\n";
    cout << "SYMBOL TABLE" << endl;
    for(string str: getSymbolTable()){
        cout << str << "|" << endl;
    }
    cout << "\n";
    //for(int i=0;i<=c;i++) cout<<yylex()<<endl;
    yyparse();
    return 0;
}