#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <regex>
#include <vector>

using namespace std;

enum {
    NOW_LISTENING,
    NO_ARGS,
    TOO_MANY_ARGS,
    INVALID_ARGS,
    ENVIRONMENT_NOT_SET,
    PORT_RANGE,
};

vector<string> en = {
    "Now listening on port",
    "No arguments provided.  See usage...",
    "Too many arguments provided.  See usage below...",
    "Invalid arguments provided.  See usage for more info...",
    "Enviorment variable for port not set.",
    "Port value must be between 0 -65k."
};

vector<string> es = {
    "Ahora escuchando en el puerto",
    "No hay argumentos. Ve el uso...",
    "Demasiado argumentos. Ver el uso abajo...",
    "Argumentos no validos. Ver el uso para mas informacion...",
    "Variable de entorno no se ha establecido.",
    "Valor del puerto debe estar entre 0 - 65k."
};

//define constants
const int PORT_MIN = 0;
const int PORT_MAX = 65536;
 
void usage();
void about();
void setport(int port);

vector<string> msg = es;

main(int argc, char* args[]) {
    //check for correct number of arguments
    if (argc == 1) {
        cout << msg.at(NO_ARGS) << endl;
        usage();
        return 0;
    }
    if (argc > 4) {
        cout << msg.at(TOO_MANY_ARGS) << endl;
        usage();
        return 1;
    }
    //get first flag
    string flag1 = args[1];
    if ((flag1 == "-!" || flag1 == "--about") && (argc == 2)){
        about();
        return 0;
    }
    //print version number
    if ((flag1 == "-v" || flag1 == "--version") && (argc == 2)){
        cout << "Version: 1.2.2a" << endl;
        return 0;
    }
    if ((flag1 == "-h" || flag1 == "--help" || flag1 == "-?") && (argc == 2)) {
        usage();
        return 0;
    }
    if ((flag1 == "-p" || flag1 == "--port") && (argc ==3)){
        string flag2 = args[2];
        if (flag2 == "-e") {
            int portNum = atoi(getenv("PORT"));
            setport(portNum);
            return 0;
        }
        setport(atoi(args[2]));
        return 0;
    }
    if ((flag1 == "-p" || flag1 == "--port") && (argc == 4)){
        string flag2 = args[2];
        if (flag2 == "-e") {
            if (getenv(args[3]) == NULL){
                cout << msg.at(ENVIRONMENT_NOT_SET) << endl;
                usage();
            int portNum = atoi(getenv(args[3]));
            setport(portNum);
            return 0;
        
            }        
        }
    }
    // all other cases are fail cases print error message and usage
    cout << msg.at(INVALID_ARGS) << endl;
    usage();
    return 2;
}

void usage(){
    ifstream usage_file;
    usage_file.open("setport.usage_es.txt");
    string line;
    while (getline(usage_file, line)){
        cout << line << endl;
    }
    usage_file.close();
}

void about(){
    ifstream about_file;
    about_file.open("setport.about_es.txt");
    string line;
    while (getline(about_file, line)){
        cout << line << endl;
    }
    about_file.close();
}
void setport(int port){
    if (port <= PORT_MIN || port >= PORT_MAX) {
        cout << msg.at(PORT_RANGE) << endl;
        usage();
        exit(3);
    }
    cout  << msg.at(NOW_LISTENING) << port << endl;
}

/*
string* msg = en; //defaults to English

//demo of a function that can print out messages in any language WITHOUT BEING AWARE OF THE LANGUAGE BEING USED
void someProcess() {
   cout << msg[HELLO] << endl;
   cout << msg[TOO_MANY_PARAMETERS] << endl;
   cout << msg[GOODBYE] << endl;
   cout << "-----------" << endl;
}

int main(int argc, char *args[]) {
string locale;
//get the locale value from env vars in this order
//1. LANGUAGE
//2. LC_ALL
//3. LC_MESSAGES, (LC_TIME, ...)
//4. LANG

//ignore these values 
//null
//""
//"C"
//"C.UTF-8"

string language;
//if no locale value, default the language to English

//use ONE regEx to validate the locale value's syntax
// error out on invalid SYNTAX, don't worry about a valid VALUE e.g. 
// es is good because country and format are optional
// en_FR is good because format is optional
// en.UTF-8 is good because country is optional
// en_NZ.UTF-8 is good
// zz_ZZ.UTF-8 is good syntax, the fact that there's no language zz or country ZZ is not important. They could appear after your program is released.
// e1 is bad syntax, no number
// english is bad syntax, only 2 letter language
// en_USA is bad syntax, only 2 letter country
// EN is bad syntax, only lowercase language
// en_us is bad syntax, only uppercase country
//use regEx to parse out the language without the country or format

//vector msg;
//read the appropriate messages from the right language file into Vector msg
// The following is untried. Consider it psuedo code.
// ifstream in("portsetter_" + lang + ".txt");
// string line;
// while (!in.eof()) {
// in >> line;
// msg.push_back(line);
// }

//Proof Of Concept (POC) working code
 someProcess();

 msg = es;
 someProcess();
 
 msg = en;
 someProcess();
}

//some differences between POC and the actual requirements
//1. msg is a vector instead of an array
//2. no someProcess(). Everywhere you have cout << "some literal string", you'll change to cout << msg[LITERAL_STRING]
//3. everywhere except version(), e.g. "1.0.1a" is not translated
//4. msg vector will come from a messages file, not hardcoded like in POC
//5. usage() and about() don't need to be put into msg vector. They will just print out the appropriate file.
//6. POC has both Spanish and English loaded. You will only load 1 language.
//7. if a language, say German, is requested, and you don't have German files, print error message about missing the user's language, and then continue as normal in English.
//  You can use this format or one of your own choosing. "Missing de translation files. Using English." (de is German)
//  Continue as normal in English means setport -p 837 would print "Listening on port 837" and return 0;

//sudo locale-gen "es_MX.UTF-8"
*/