#include "Event.h"
#include "global.h"

Event::Event() {

    isValidEvent = true;
    numberOfStations = 0;
    numberOfValidStations = 0;

}

// set input file and process the file
void Event::setInputFile(string fileName) {

    inputFileName = fileName + ".in";
    outputFileName = fileName + ".out";

    if (openInputFile(inputFile, inputFileName)) {
        printOutput(logFile, "Processing input file: " + inputFileName + "\n");

        openOutput(outputFile, outputFileName);
        headerProcessing();
        tableProcessing();

        printOutput(logFile, "Finished " + inputFileName + "\n");
        printOutput(logFile, cutLine());
        printOutput(logFile, "\n");
    }

}

// read valid entries into st
void tableProcessing(){
    int numOfValidEntry = 0;
    int numOfReadEntry = 0;
    int numOfSignal = 0;
    string networkCode;
    bool isValidEntry = true;
    // Station entry[];    Using list here, since no maximum constrain.
    while (inputfile >> networkCode){
    }
}

// print header
void printHeader() {

    outputFile << "# " << eq.getDay() << " " << eq.getMonth() << " " << eq.getYear() << " ";
    outputFile << eq.getTime() << " " << eq.getTimeZone() << " " << eq.getMagnitudeType() << " " << eq.getMagnitude() << " ";
    outputFile << eq.getEarthqaukeName() << " [" << eq.getEventID() << "] (";
    outputFile << eq.getEvlo() << ", " << eq.getEvla() << ", " << eq.getEvdp() << ")" << endl;

}

// print signals
void printSignals() {

    // print all the signals to output file
    for (list<Station>::iterator it = st.begin(); it != st.end(); it++) {
        string orientation = it->getOrientation();

        for (int j = 0; j < orientation.length(); j++) {
            stringstream singalStream;
            singalStream << eq.getEventID() << ".";
            singalStream << it->getNetworkCode() << ".";
            singalStream << it->getStationCode() << ".";
            singalStream << it->getBandType();
            singalStream << it->getInstrumentType();
            singalStream << orientation[j] << endl;

            outputFile << singalStream.str();
        }
    }

}

Event::~Event() {

    if (inputFile.is_open()) {
        inputFile.close()
    }

    if (outputFile.is_open()) {
        outputFile.close();
    }

}