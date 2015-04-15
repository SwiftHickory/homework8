#include "event.h"
#include "global.h"

Event::Event() {

    isValidEvent = true;
    numberOfStations = 0;
    numberOfValidStations = 0;
    numberOfSignals = 0;

}

// set input file and process the file
void Event::setInputFile(string fileName) {

    inputFileName = fileName + ".in";
    outputFileName = fileName + ".out";

    if (openInput(inputFile, inputFileName)) {
        printOutput(logFile, "Processing input file: " + inputFileName + "\n");

        headerProcessing();
        if (isValidEvent) {
            openOutput(outputFile, outputFileName);
            tableProcessing();
            printHeader();
            printSignals();
        }
    }

    printOutput(logFile, "Finished " + inputFileName + "\n\n");
    printOutput(logFile, cutLine());
    printOutput(logFile, "\n");

}

void Event::headerProcessing () {
    
    string new_eventID, new_date, new_time, new_timeZone, new_magnitudeType;
    double new_Long, new_Lat, new_Depth;
    float new_magnitude;
    
    inputFile >> new_eventID;
    eq.setEventID(new_eventID);
    
    inputFile >> new_date;
    if(eq.setDate(new_date) == false) {
        printOutput(logFile, "Error: invalid date of this earthquake!\n");
        isValidEvent = false;
        return;
    }
        
    inputFile >> new_time;
    if(eq.setTime(new_time) == false) {
        printOutput(logFile, "Error: invalid time of this earthquake!\n");
        isValidEvent = false;
        return;
    }
    
    inputFile >> new_timeZone;
    if(eq.setTimeZone(new_timeZone) == false) {
        printOutput(logFile, "Error: invalid time zone of this earthquake!\n");
        isValidEvent = false;
        return;
    }
    
    eq.setEarthquakeName(inputFile);
    
    inputFile >> new_Long;
    eq.setEvlo(new_Long);
    
    inputFile >> new_Lat;
    eq.setEvla(new_Lat);
    
    inputFile >> new_Depth;
    eq.setEvdp(new_Depth);
    
    inputFile >> new_magnitudeType;
    if(eq.setMagnitudeType(new_magnitudeType) == false) {
        printOutput(logFile, "Error: invalid magnitude type of this earthquake!\n");
        isValidEvent = false;
        return;
    }
    
    inputFile >> new_magnitude;
    if(eq.setMagnitude(new_magnitude) == false) {
        printOutput(logFile, "Error: invalid magnitude of this earthquake!\n");
        isValidEvent = false;
        return;
    }

}

// print header
void Event::printHeader() {

    outputFile << "# " << eq.getDay() << " " << eq.getMonth() << " " << eq.getYear() << " ";
    outputFile << eq.getTime() << " " << eq.getTimeZone() << " " << eq.getMagnitudeType() << " " << eq.getMagnitude() << " ";
    outputFile << eq.getEarthqaukeName() << " [" << eq.getEventID() << "] (";
    outputFile << eq.getEvlo() << ", " << eq.getEvla() << ", " << eq.getEvdp() << ")" << endl;

}

// Read and check entries, store the valid entries into list<station> st.
void Event::tableProcessing(){

    string networkcode;
    bool isValidEntry = true;
    Station *temp_station = new Station;
 
    // Reading the file to the end 
    while (inputFile >> networkcode){
        numberOfStations++;
        string  stname,typeofband,typeofinstru,orientation;
        isValidEntry = true;

        // Read and check one entry if it is a valid entry.
        if(!(temp_station->setNetworkCode(networkcode))) {
            printOutput(logFile,"Entry # " + intToString(numberOfStations) + " ignored. Invalid network code.\n");
            isValidEntry = false;
        }

        inputFile >> stname;
        if(!(temp_station->setStationCode(stname))) {
            printOutput(logFile, "Entry # " + intToString(numberOfStations) + " ignored. Invalid station code.\n");
            isValidEntry = false;
        }

        inputFile >> typeofband;
        if(!(temp_station->setBandType(typeofband))) {
            printOutput(logFile, "Entry # " + intToString(numberOfStations) + " ignored. Invalid band type.\n");
            isValidEntry = false;
        }

        inputFile >> typeofinstru;
        if(!(temp_station->setInstrumentType(typeofinstru))) {
            printOutput(logFile, "Entry # " + intToString(numberOfStations) + " ignored. Invalid instrument type.\n");
            isValidEntry = false;
        }

        inputFile >> orientation;
        if(!(temp_station->setOrientation(orientation))) {
            printOutput(logFile, "Entry # " + intToString(numberOfStations) + " ignored. Invalid orientation.\n");
            isValidEntry = false;
        }

        if (isValidEntry == true) {
            // After checking the validation of one entry, push it back into the list signal.
            st.push_back(temp_station);
            string orientation = temp_station->getOrientation();
            numberOfSignals += orientation.length();
            numberOfValidStations++;
        } 
    }

    printOutput(logFile, "Total invalid entries ignored: " + intToString(numberOfStations - numberOfValidStations) + "\n");
    printOutput(logFile, "Total valid entries read: " + intToString(numberOfValidStations) + "\n");
    printOutput(logFile, "Total signal names produced: " + intToString(numberOfStations) + "\n");
 
}

// print signals
void Event::printSignals() {

    // print all the signals to output file
    for (list<Station *>::iterator it = st.begin(); it != st.end(); it++) {
        string orientation = (*it)->getOrientation();

        for (int j = 0; j < (int)orientation.length(); j++) {
            outputFile << eq.getEventID() << ".";
            outputFile << (*it)->getNetworkCode() << ".";
            outputFile << (*it)->getStationCode() << ".";
            outputFile << (*it)->getBandType();
            outputFile << (*it)->getInstrumentType();
            outputFile << orientation[j] << endl;
        }
    }

}

Event::~Event() {

    if (inputFile.is_open()) {
        inputFile.close();
    }

    if (outputFile.is_open()) {
        outputFile.close();
    }

}