#include "earthquake.h"

bool Earthquake::setDate(string new_date) {

    // the length of date must be 10
    if (new_date.length() == 10) {
        // date format is mm/dd/yyyy
        string new_month = new_date.substr(0, 2);
        string new_day = new_date.substr(3, 2);
        string new_year = new_date.substr(6, 4);

        if (!setYear(new_year) || !setMonth(new_month) || !setDay(new_day)) {
            return false;
        }

        // date format is mm/dd/year or mm-dd-year
        if ((new_date[2] != '/' || new_date[5] != '/') && (new_date[2] != '-' || new_date[5] != '-')) {
            return false;
        }
    } else {
        return false;
    }

    date = new_date;

    return true;

}

string Earthquake::getDate() {

    return date;

}

bool Earthquake::setTime(string new_time) {

    // the length of time must be 12
    if (new_time.length() == 12) {
        // time format is hh:mm:ss.fff
        string new_hour = new_time.substr(0, 2);
        string new_minute = new_time.substr(3, 2);
        string new_second = new_time.substr(6, 2);
        string new_millisecond = new_time.substr(9, 3);

        if (!setHour(new_hour) || !setMinute(new_minute) || !setSecond(new_second) || !setMillisecond(new_millisecond)) {
            return false;
        }

        // check for delimer
        if (new_time[2] != ':' || new_time[5] != ':' || new_time[8] != '.') {
            return false;
        }
    } else {
        return false;
    }

    time = new_time;
    return true;

}

string Earthquake::getTime() {

    return time;

}

bool Earthquake::setMonth(string new_month) {

    if (new_month == "01") {
        month = January;
        return true;
    }

    if (new_month == "02") {
        month = February;
        return true;
    }

    if (new_month == "03") {
        month = March;
        return true;
    }

    if (new_month == "04") {
        month = April;
        return true;
    }

    if (new_month == "05") {
        month = May;
        return true;
    }

    if (new_month == "06") {
        month = June;
        return true;
    }

    if (new_month == "07") {
        month = July;
        return true;
    }

    if (new_month == "08") {
        month = August;
        return true;
    }

    if (new_month == "09") {
        month = September;
        return true;
    }

    if (new_month == "10") {
        month = October;
        return true;
    }

    if (new_month == "11") {
        month = November;
        return true;
    }

    if (new_month == "12") {
        month = December;
        return true;
    }
    
    return false;

}

string Earthquake::getMonth() {

    switch (month) {
        case January:
            return "January";
            break;
        case February:
            return "February";
            break;
        case March:
            return "March";
            break;
        case April:
            return "April";
            break;
        case May:
            return "May";
            break;
        case June:
            return "June";
            break;
        case July:
            return "July";
            break;
        case August:
            return "August";
            break;
        case September:
            return "September";
            break;
        case October:
            return "October";
            break;
        case November:
            return "November";
            break;
        case December:
            return "December";
            break;
    }

}

bool Earthquake::setDay(string new_day) {

    // day should be numbers 
    if (!is_digits(new_day)) {
        return false;
     } else {
        day = atoi(new_day.c_str());
        if (day < 0 || day > daysOfAMonth()) {
            return false;
        }
     }

     return true;

}

string Earthquake::getDay() {

    string day_str = intToString(day);

    if (day_str.length() == 1) {
        day_str = "0" + day_str;
    }

    return day_str;

}

bool Earthquake::setYear(string new_year) {

    // year should be numbers 
    if (!is_digits(new_year)) {
        return false;
     } else {
        year = atoi(new_year.c_str());
     }

     return true;

}

string Earthquake::getYear() {

    return intToString(year);

}

// return the numer of days in a month
int Earthquake::daysOfAMonth() {

    switch (month) {
        case January:
            return 31;
            break;
        case February:
            return year % 4 == 0 ? 28 :29;
            break;
        case March:
            return 31;
            break;
        case April:
            return 30;
            break;
        case May:
            return 31;
            break;
        case June:
            return 30;
            break;
        case July:
            return 31;
            break;
        case August:
            return 31;
            break;
        case September:
            return 30;
            break;
        case October:
            return 31;
            break;
        case November:
            return 30;
            break;
        case December:
            return 31;
            break;
    }

}

bool Earthquake::setMagnitudeType(string new_magnitudeType){

    // Case insensitive, convert the band type to uppercase
    new_magnitudeType = upperString(new_magnitudeType);

    if (new_magnitudeType == "ML"){
        magnitudeType = ml;
        return true;
    }
    if (new_magnitudeType == "MS"){
        magnitudeType = ms;
        return true;
    }
    if (new_magnitudeType == "MB"){
        magnitudeType = mb;
        return true;
    }
    if (new_magnitudeType == "MW"){
        magnitudeType = mw;
        return true;
    }
   
    //printOutput(logFile,  "Error: invalid magnitude type of this earthquake!\n", true);
    return false;
}

string Earthquake::getMagnitudeType(){
    switch (magnitudeType){
        case ml:
            return "Ml";
            break;
        case ms:
            return "Ms";
            break;
        case mb:
            return "Mb";
            break;
        case mw:
            return "Mw";
            break;
    }
}


bool Earthquake::setMagnitude(float new_magnitude){
    if (new_magnitude <= 0){
        //printOutput(logFile,"Error: Magnitude must be a positive number.\n", true);
    }
    else{
        magnitude = new_magnitude;
    }
}

float Earthquake::getMagnitude(){
    return magnitude;
}