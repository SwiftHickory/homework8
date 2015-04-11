#include "myFunction.h"
#include "global.h"

// function to open input file
bool openInput(ifstream &inputFile, string fileName, ofstream &logFile) {

    inputFile.open(fileName.c_str());

    // perform sanity check it
    if (!inputFile.is_open()) {
        printOutput(logFile, "Cannot open input file: " + fileName + "\n");
        return false;
    }

    return true;

}

// function to open output file
bool openOutput(ofstream &outputFile, string fileName) {

    outputFile.open(fileName.c_str());

    // perform sanity check it
    if (!outputFile.is_open()) {
        if (fileName == logFileName) {
            // if we can open error file, just print out to terminal
            cout << "Cannot open log file: " << logFileName << endl;
        } else {
            printOutput(logFile, "Cannot open output file: " + fileName + "\n");
        }

        return false;
    }

    return true;

}

// print messeage to both terminal and a file
void printOutput(ofstream &outputFile, const string &message, bool needExit) {

    cout << message;
    outputFile << message;

    if (needExit) {
        exit(EXIT_FAILURE);
    }

}

// print cutline
string cutLine() {

    stringstream cutlineStream;

    for (int i = 0; i < 40; i++) {
        cutlineStream << "-";
    }

    cutlineStream << endl;

    return cutlineStream.str();
}

// change all the letters in a string to upper case
string upperString(string str){ 
    for (int i = 0; i < (int)str.size(); i++) {
        str[i] = toupper(str[i]);
    }
    return str; 
}

// convert a int to string
string intToString(int num){
    stringstream s;
    s << num;
    return s.str();
}