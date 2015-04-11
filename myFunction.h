/******************************************************************************
-   earthquake.h
-   Prog Tools for Scits Engrs - CIVL 8903 Homework IX
-
-   File Discreption: functions used in this project
-
-   Implemented by all of us
-
-   Github Repository: https://github.com/SwiftHickory/homework8.git
******************************************************************************/

#ifndef MYFUNCTION_H
#define MYFUNCTION_H

#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <list>

using namespace std;

// implement by Yang
// function to open input file
bool openInput(ifstream &inputFile, string fileName);

// implement by Yang
// function to open output file
bool openOutput(ofstream &outputFile, string fileName);

// implement by Shepherd
// check whether a string contains only digits
bool is_digits(string str);

// implement by Shepherd
// change all the letters in a string to lower case
string lowerString(string str);

// implement by Yuan
// change all the letters in a string to upper case
string upperString(string str);

// implement by Yuan
// convert a int to string
string intToString(int num);

// implement by Yang
// print messeage to both terminal and a file
void printOutput(ofstream &outputFile, const string &message, bool needExit = false);

// print cutline
string cutLine();

#endif