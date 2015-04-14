/******************************************************************************
-   earthquake.h
-   Prog Tools for Scits Engrs - CIVL 8903 Homework IX
-
-   File Discreption: class defination of an event
-
-   Implemented by: Yang Yang
-
-   Github Repository: https://github.com/SwiftHickory/homework8.git
******************************************************************************/

#ifndef EVENT_H
#define EVENT_H

#include "station.h"
#include "earthquake.h"
#include "myFunction.h"

class Event{
public:
    // implement by Yang
    // constructor for Event.
    Event();

    // implement by Yang
    // this function read input file named inputFileName and then process it
    void setInputFile(string fileName);

    // implement by Shepherd
    // read header
    void headerProcessing();

    // implement by Yuan
    // read valid entries into st
    void tableProcessing();

    // implement by Yang
    // print header
    void printHeader();

    // implement by Yang
    // print signals
    void printSignals();

    // implement by Yang
    ~Event();

private:
    Earthquake eq;
    list<Station *> st;
    ifstream inputFile;
    string inputFileName;
    ofstream outputFile;
    string outputFileName;
    int numberOfStations;
    int numberOfValidStations;
    bool isValidEvent;
    int NumOfValidEntry;
    int NumOfReadEntry;
    int NumOfSignal;
};



#endif