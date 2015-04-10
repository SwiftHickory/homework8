#include "Event.h"

Event::Event() {

	isValidEvent = true;
	numberOfStations = 0;
	numberOfValidStations = 0;
	openOutput(logFile, logFileName);

}

void Event::setInputFile(string inputFileName) {

	openInput(inputFile, inputFileName);
	openOutput(outputFile, outputFileName);

}