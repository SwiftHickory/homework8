#include "earthquake.h"

bool Earthquake::setEventID(string new_eventID) {
    
    eventID = new_eventID;
    return true;
    
}

string Earthquake::getEventID() {
    
    return eventID;
    
}

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

bool Earthquake::setEarthquakeName(ifstream &IF) {
    
    int checkpeek = 1, isfirst = 1;
    string TempName, FinalName;
    while(checkpeek == 1)
    {
        IF >> TempName;
        if (isfirst == 1)
        {
            FinalName = TempName;
            isfirst = 0;
        } else
        {
            FinalName = FinalName + " " + TempName;
        }
        if(IF.peek() == '\n') checkpeek = 0;
    }
    earthquakeName = FinalName;
    return true;
    
}

string Earthquake::getEarthqaukeName() {
    
    return earthquakeName;
    
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

    return "Wrong month";

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

    return 0;

}

bool Earthquake::setEvlo(double new_evlo) {

    evlo = new_evlo;
    return true;
    
}

double Earthquake::getEvlo() {
    
    return evlo;
    
}

bool Earthquake::setEvla(double new_evla) {
    
    evla = new_evla;
    return true;
    
}

double Earthquake::getEvla() {
    
    return evla;
    
}

bool Earthquake::setEvdp(double new_evdp) {
    
    evdp = new_evdp;
    return true;
    
}

double Earthquake::getEvdp() {
    
    return evdp;
    
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
        return false;
    }
    else{
        magnitude = new_magnitude;
        return true;
    }

}

float Earthquake::getMagnitude(){

    return magnitude;
    
}

bool Earthquake::setHour(string new_hour){

    if (!is_digits(new_hour)){
        return false;
    }
    else{
        hour = atoi(new_hour.c_str());
        if (hour < 0 || hour >23 ){
            return false;
        }
    }

    return true;

}

string Earthquake::getHour(){

    return intToString(hour);

}

bool Earthquake::setMinute(string new_minute){

    if (!is_digits(new_minute)){
        return false;
    }
    else{
        minute = atoi(new_minute.c_str());
        if (minute < 0 || minute >59){
            return false;
        }
    }

    return true;

}

string Earthquake::getMinute(){

    return intToString(minute);

}

bool Earthquake::setSecond(string new_second){

    if (!is_digits(new_second)){
        return false;
    }
    else{
        second = atoi(new_second.c_str());
        if (second < 0 || second > 59){
            return false;
        }
    }

    return true;

}

string Earthquake::getSecond(){

    return intToString(second);

}

bool Earthquake::setMillisecond(string new_millisecond){

    if (!is_digits(new_millisecond)){
        return false;
    }
    else{
        millisecond = atoi(new_millisecond.c_str());
        if (millisecond < 0 || millisecond >59){
            return false;
        }
    }

    return true;

}

string Earthquake::getMillisecond(){

    return intToString(millisecond);

}

bool Earthquake::setTimeZone(string new_timeZone) {

    // time zone must be three characters
    if (new_timeZone.length() != 3) {
        return false;
    } else {
        timeZone = new_timeZone;
        return true;
    }

}

string Earthquake::getTimeZone() {

    return timeZone;

}