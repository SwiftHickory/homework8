/******************************************************************************
-   station.h
-   Prog Tools for Scits Engrs - CIVL 8903 Homework IX
-
-   File Discreption: class defination of station
-
-   Implemented by: Shepherd Kenworthy Tate
-
-   Github Repository: https://github.com/SwiftHickory/homework8.git
******************************************************************************/

#ifndef STATION_H
#define STATION_H

#include "myFunction.h"

// case sensitive
enum networkCodeType {
    CE,
    CI,
    FA,
    NP,
    WR
};

// case insensitive
enum typeOfBandType {
    longperiod,  // L
    shortperiod,  // B
    broadband  // H
};

// case insensitive
enum typeOfInstrumentType {
    highgain,  // H
    lowgain,  // L
    accelerometer  // N
};

class Station {
public:
    void setNetworkCode(string new_networkCode);
    string getNetworkCode();

    void setStationCode(string new_stationCode);
    string getStationCode();

    void setBandType(string new_bandType);
    string getBandType();

    void setInstrumentType(string new_instrumentType);
    string getInstrumentType();

    void setOrientation(string new_orientation);
    string getOrientation();

    void setLogStream();
    string getLogStream();

    void setIsValidEntry();
    void getIsValidEntry();

private:
    networkCodeType networkCode;
    string stationCode;
    typeOfBandType typeOfBand;
    typeOfInstrumentType typeOfInstrument;
    string orientation;  // one to three characters, case insensitive
    stringstream logStream; // stringstream to store information needed to print to logFile
    bool isValidEntry;
};

#endif