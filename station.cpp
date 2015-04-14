#include "station.h"

Station::Station() {
    
}

bool Station::setNetworkCode(string new_networkCode){
    
    // Case insensitive, convert the network code to uppercase.
    new_networkCode = upperString(new_networkCode);
    
    if (new_networkCode ==  "CE") {
        networkCode = CE;
        return true;
    }
    if (new_networkCode ==  "CI") {
        networkCode = CI;
        return true;
    }
    if (new_networkCode ==  "FA") {
        networkCode = FA;
        return true;
    }
    if (new_networkCode ==  "NP") {
        networkCode = NP;
        return true;
    }
    if (new_networkCode ==  "WR") {
        networkCode = WR;
        return true;
    }
    return false;
}

string Station:: getNetworkCode() {
    switch(networkCode){
        case(CE):
            return "CE";
            break;
        case(CI):
            return "CI";
            break;
        case(FA):
            return "FA";
            break;
        case(NP):
            return "NP";
            break;
        case(WR):
            return "WR";
            break;
    }
}

bool Station::setBandType(string new_bandType){

    // Case insensitive, convert the band type to uppercase. 
    new_bandType = upperString(new_bandType);

    if (new_bandType == "LONG-PERIOD"){
        typeOfBand = longperiod;
        return true;
    }
    if (new_bandType == "SHORT-PERIOD"){
        typeOfBand = shortperiod;
        return true;
    }
    if (new_bandType == "BROADBAND"){
        typeOfBand = broadband;
        return true;
    }
    return false;
}

string Station::getBandType(){
    switch (typeOfBand){
        case (longperiod): 
            return "L";
            break;
        case (shortperiod): 
            return "B";
            break;
        case (broadband): 
            return "H";
            break;
    }
}

bool Station::setInstrumentType(string new_instrumentType){

    // Case insensitive, convert the band type to uppercase
    new_instrumentType = upperString(new_instrumentType);

    if (new_instrumentType == "HIGH-GAIN") {
        typeOfInstrument = highgain;
        return true;
    }
    if (new_instrumentType == "LOW-GAIN") {
        typeOfInstrument = lowgain;
        return true;
    }
    if (new_instrumentType == "ACCELEROMETER") {
        typeOfInstrument = accelerometer;
        return true;
    }
    return false;
}

string Station::getInstrumentType(){
    switch(typeOfInstrument){
        case highgain:
            return "H";
            break;
        case lowgain:
            return "L";
            break;
        case accelerometer:
            return "N";
            break;
    }

}bool Station::setOrientation(string str) {

    // case insensitive so convert it to lower case first
    str = lowerString(str);

    if (str.length() < 4) {
        if (isdigit(str[0])) {
            for (int i = 0; i < (int)str.length(); i++) {
                if (str[i] != '1' && str[i] != '2' && str[i] != '3') {
                    return false;
                }
            }

            orientation =  str;

            return true;
        } else if (islower(str[0])) {
            for (int i = 0; i < (int)str.length(); i++) {
                if (str[i] != 'n' && str[i] != 'e' && str[i] != 'z') {
                    return false;
                }
            }

            orientation = str;

            return true;
        }
    }

    return false;

}

string Station::getOrientation() {

    return upperString(orientation);

}