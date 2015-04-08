#ifndef EVENT_H
#define EVENT_H

#include "station.h"
#include "earthquake.h"
#include <list>

class Event{
public:
	Event(string inputFileName);

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