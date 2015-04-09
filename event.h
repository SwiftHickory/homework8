/******************************************************************************
-   earthquake.h
-   Prog Tools for Scits Engrs - CIVL 8903 Homework IX
-
-   File Discreption: class defination of earthquake
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
	// constructor for Event.
	Event();

	// this function read input file named inputFileName and then process it
	setInputFile(string inputFileName);

	// read header can then produce output header
	void headerProcessing();

	// read table and then produce output
	void tableProcessing();

	// read and processing one entry
	bool processOneEntry();

	// print header
	void printHeader();

	// print signals
	void printSignals();

	~Event();

private:
	Earthquake eq;
	list<Station> st;
	ifstream inputFile;
	ofstream logFile;
	ofstream outputFile;
	int numberOfStations;
	int numberOfValidStations;
};

#endif