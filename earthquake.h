/******************************************************************************
-   earthquake.h
-   Prog Tools for Scits Engrs - CIVL 8903 Homework IX
-
-   File Discreption: class defination of earthquake
-
-   Implemented by: Yuan Zhou
-
-   Github Repository: https://github.com/SwiftHickory/homework8.git
******************************************************************************/
// Try if I get the idea how to merge the files.

#ifndef EARTHQUAKE_H
#define EARTHQUAKE_H

#include "myFunction.h"

// case insensitive
enum typeOfMagnitudeType {
    ml,
    ms,
    mb,
    mw
};

enum months {
    January,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

class Earthquake{
public:
    // implement by Shepherd
    bool setEventID(string new_eventID);
    string getEventID();

    // implement by Yang
    bool setDate(string new_date);
    string getDate();

    // implement by Yang
    bool setTime(string new_time);
    string getTime();

    // implement by Yang
    bool setTimeZone(string new_timeZone);
    string getTimeZone();

    // implement by Shepherd
    bool setEarthquakeName(ifstream &IF);
    string getEarthqaukeName();

    // implement by Yang
    bool setMonth(string new_month);
    string getMonth();

    // implement by Yang
    bool setDay(string new_day);
    string getDay();

    // implement by Yang
    bool setYear(string new_year);
    string getYear();

    // implement by Shepherd
    bool setEvlo(double new_evlo);
    double getEvlo();

    // implement by Shepherd
    bool setEvla(double new_evla);
    double getEvla();

    // implement by Shepherd
    bool setEvdp(double new_evdp);
    double getEvdp();

    // implement by Yuan
    bool setMagnitudeType(string new_magnitudeType);
    string getMagnitudeType();

    // implement by Yuan
    bool setMagnitude(float new_magnitude);
    float getMagnitude();


private:
    string eventID;
    string date;
    string time;
    string timeZone;
    string earthquakeName;
    months month;
    int day;
    int year;
    int hour;
    int minute;
    int second;
    int millisecond;
    double evlo;
    double evla;
    double evdp;
    typeOfMagnitudeType magnitudeType;
    float magnitude;

    // implement by Yuan
    bool setHour(string new_hour);
    string getHour();

    // implement by Yuan
    bool setMinute(string new_minute);
    string getMinute();

    // implement by Yuan
    bool setSecond(string new_second);
    string getSecond();

    // implement by Yuan
    bool setMillisecond(string new_millisecond);
    string getMillisecond();

    // implement by Yang
    // return the numer of days in a month
    int daysOfAMonth();
};

#endif