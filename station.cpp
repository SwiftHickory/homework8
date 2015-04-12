#include "station.h"
#include "global.h"

Station::Station() {
    
}

bool Station::setOrientation(string str) {

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