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

void Event::headerProcessing () {
    
    string new_eventID, new_date, new_time, new_timeZone, new_magnitudeType;
    double new_Long, new_Lat, new_Depth;
    float new_magnitude;
    
    inputFile >> new_eventID;
    eq.setEventID(new_eventID);
    
    inputFile >> new_date;
    if(eq.setDate(new_date) == false) {
        printOutput(logFile, "Invalid Date");
    }
        
    inputFile >> new_time;
    if(eq.setTime(new_time) == false) {
        printOutput(logFile, "Invalid Time");
    }
    
    inputFile >> new_timeZone;
    if(eq.setTimeZone(new_timeZone) == false) {
        printOutput(logFile, "Invalid Time Zone");
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
        printOutput(outputFile, "Invalid Magnitude Type", false);
    }
    
    inputFile >> new_magnitude;
    if(eq.setMagnitude(new_magnitude) == false) {
        printOutput(outputFile, "Negative Magnitude", false);
    }

}

void printOutput(ofstream &outputFile, const string &message, bool needExit) {
    
    cout << message;
    outputFile << message;
    
    if (needExit) {
        exit(EXIT_FAILURE);
    }
    
}

// print header
void printHeader() {

    outputFile << "# " << eq.getDay() << " " << eq.getMonth() << " " << eq.getYear() << " ";
    outputFile << eq.getTime() << " " << eq.getTimeZone() << " " << eq.getMagnitudeType() << " " << eq.getMagnitude() << " ";
    outputFile << eq.getEarthqaukeName() << " [" << eq.getEventID() << "] (";
    outputFile << eq.getEvlo() << ", " << eq.getEvla() << ", " << eq.getEvdp() << ")" << endl;

}

// Read and check entries, store the valid entries into list<station> st.
void tableProcessing(){
    int NumOfValidEntry = 0;
    int NumOfReadEntry = 0;
    int NumOfSignal = 0;
    string networkcode;
    bool isValidEntry = true;
    Station *temp_station = new Station();
    //Since there is no constraint of the maximum valid entry number, using the "list" for storing the entries.
    list<Station> st;   // Might be deleted later.

    // Reading the file to the end 
    while (inputFile >> networkcode){
        NumOfReadEntry ++;
        if (IsValidEntry(inputFile, temp_station, NumOfReadEntry, networkcode)){
            // After checking the validation of one entry, push it back into the list signal.
            st.push_back(temp_station);
            string orientation = *temp_station->getOrientation;
            NumOfSignal += (int)orientation.length();
            NumOfValidEntry ++;
        } 
    }
    printOutput(logFile, "Total invalid entries ignored: " + intToString(NumOfReadEntry-NumOfValidEntry) + "\n");
    printOutput(logFile, "Total valid entries read: " + intToString(NumOfReadEntry) + "\n");
    printOutput(logFile, "Total signal names produced: " + intToString(NumOfSignal) + "\n");

}

// Read and check one entry if it is a valid entry.
bool IsValidEntry (ifstream &inputFile, Station &entry, int entryNumber, string networkcode){
    string  stname, typeofband, typeofinstru, orientation;
    bool isValidEntry = true;

    if(!entry.setNetworkCode(networkcode)){
        printOutput(logFile,"Entry # " + intToString(entryNumber) + " ignored. Invalid network code.\n", false);
        isValidEntry = false;
    }

    inputFile >> stname;
    if(!entry.setStationCode(stname)){
        printOutput(logFile, "Entry # " + intToString(entryNumber) + " ignored. Invalid station code.\n", false);
        isValidEntry = false;
    }

    inputFile >> typeofband;
    if(!entry.setBandType(typeofband)){
        printOutput(logFile, "Entry # " + intToString(entryNumber) + " ignored. Invalid band type.\n", false);
        isValidEntry = false;
    }

    inputFile >> typeofinstru;
    if(!entry.setInstrumentType(typeofinstru)){
        printOutput(logFile, "Entry # " + intToString(entryNumber) + " ignored. Invalid instrument type.\n", false);
        isValidEntry = false;
    }

    inputFile >> orientation;
    if(!entry.setOrientation(orientation)){
        printOutput(logFile, "Entry # " + intToString(entryNumber) + " ignored. Invalid orientation.\n", false);
        isValidEntry = false;
    }

    return isValidEntry;
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