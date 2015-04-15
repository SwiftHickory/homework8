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

int main(int argc, char *argv[]) {

    if (argc == 1) {
        cout << "Usage: " << argv[0] << " fileName1 fileName2 ..." << endl;
        cout << "Please give at least one input file" << endl;
        return 0;
    }

    // open log file
    if (!openOutput(logFile, logFileName)) {
        cout << "Log file open error! Exit program" << endl;
        return 0;
    }

    // allocate memory for event db
    Event *eventDB = new Event[argc - 1];
    
    for (int i = 0; i < argc - 1; i++) {
        eventDB[i].setInputFile(argv[i+1]);
    }

    // close logFile
    logFile.close();

    return 0;

}
