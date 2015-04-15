/******************************************************************************
-   earthquake.h
-   Prog Tools for Scits Engrs - CIVL 8903 Homework IX
-
-   File Discreption: main function
-
-   Implemented by all of us
-
-   Github Repository: https://github.com/SwiftHickory/homework8.git
******************************************************************************/

#include "event.h"
#include "global.h"

using namespace std;

int main(int argc, char *argv[]) {

    // open log file
    openOutput(logFile, logFileName);

    if (argc > 1) {
        Event *eventDB = new Event[argc - 1];
    } else {
        cout << "Usage: " << argv[0] << " fileName1 fileName2 ..." << endl;
        cout << "Please give at least one input file" << endl;
        return;
    }
    
    for (int i = 1; i < argc; i++) {
        eventDB[i].setInputFile(argv[i]);
    }

    // close logFile
    logFile.close();

    return 0;

}
