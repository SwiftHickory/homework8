/******************************************************************************
-   station.h
-   Prog Tools for Scits Engrs - CIVL 8903 Homework IX
-
-   File Discreption: class defination of station
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
    // implement by Yang
    Station();

    // implement by Shepherd
    bool setNetworkCode(string new_networkCode);
    string getNetworkCode();

    bool setStationCode(string new_stationCode);
    string getStationCode();

    // implement by Yuan
    bool setBandType(string new_bandType);
    string getBandType();

    bool setInstrumentType(string new_instrumentType);
    string getInstrumentType();

    // implement by Yang
    bool setOrientation(string new_orientation);
    string getOrientation();

private:
    networkCodeType networkCode;
    string stationCode;
    typeOfBandType typeOfBand;
    typeOfInstrumentType typeOfInstrument;
    string orientation;  // one to three characters, case insensitive
};

#endif