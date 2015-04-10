#include "myFunction.h"

// function to open input file
void openInput(ifstream &inputFile, string fileName, ofstream &logFile) {

    inputFile.open(fileName.c_str());

    // perform sanity check it
    if (!inputFile.is_open()) {
        printOutput(logFile, "Cannot open input file: " + fileName + "\n", true);
    }

}

// function to open output file
void openOutput(ofstream &outputFile, string fileName) {

    outputFile.open(fileName.c_str());

    // perform sanity check it
    if (!outputFile.is_open()) {
        if (fileName == logFileName) {
            // if we can open error file, just print out to terminal
            cout << "Cannot open log file: " << logFileName << endl;
        } else {
            printOutput(logFile, "Cannot open output file: " + fileName + "\n", true);
        }
    }

}

// print messeage to both terminal and a file
void printOutput(ofstream &outputFile, const string &message, bool needExit) {

    cout << message;
    outputFile << message;

    if (needExit) {
        exit(EXIT_FAILURE);
    }

}