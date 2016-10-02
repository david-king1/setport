#include <iostream>
#include <vector>
#include <stdio.h>
#include <fstream>

using namespace std;


main(int argc, char* args[]){
    
    string FILE_OUTPUT_STREAM = " > /dev/null";
    
    fstream test_file;
    test_file.open("portsettertest.txt");
    string line;
    if (test_file){
        while (getline(test_file, line)) {
            //cout << line;
            //cout << endl;
            //cout << FILE_OUTPUT_STREAM;
            //string line2 = line.append(FILE_OUTPUT_STREAM);
            int statusCode = system(line.c_str());
            //cout << line2;
            //cout << endl;
        }
    }
    /*
    vector<string> test_cases;
    vector<int> test_results;
    //happy path
    test_cases.push_back("./portsetter.cpp.o > /dev/null");
    test_cases.push_back("./portsetter.cpp.o -h > /dev/null");
    test_cases.push_back("./portsetter.cpp.o --help > /dev/null");
    test_cases.push_back("./portsetter.cpp.o -p 4040 > /dev/null");
    test_cases.push_back("./portsetter.cpp.o --port 4040 > /dev/null");
    //sad path
   /* test_cases.push_back("./portsetter.cpp.o help");
    test_cases.push_back("./portsetter.cpp.o -help");
    test_cases.push_back("./portsetter.cpp.o --h");
    test_cases.push_back("./portsetter.cpp.o -h --help");
    test_cases.push_back("./portsetter.cpp.o -hs");
    test_cases.push_back("./portsetter.cpp.o -p --port 9");
    test_cases.push_back("./portsetter.cpp.o -p 77 33");
    test_cases.push_back("./portsetter.cpp.o -p -21");
    test_cases.push_back("./portsetter.cpp.o -p 0");
    test_cases.push_back("./portsetter.cpp.o --port");
    test_cases.push_back("./portsetter.cpp.o -p 90642");
    test_cases.push_back("./portsetter.cpp.o -x 45321");
    test_cases.push_back("./portsetter.cpp.o -P 714");
    
    //positive tests
    for (int i = 0; i < 5; ++i){
        int statusCode = system(test_cases[i].c_str()) / 256;
        test_results.push_back(statusCode);
    }
    //negative tests
    for (int i = 5; i < 18; ++i){
        int statusCode = system(test_cases[i].c_str()) / 256;
        test_results.push_back(statusCode);
    } 

    for (int j = 0; j < 18; ++j){
        cout << test_results[j] << endl;
    }
    */

    return 0;
}
