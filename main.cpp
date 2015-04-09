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

using namespace std;

int main(int argc, char *argv[]) {

	if (argc > 1) {
		Event *eventDB = new Event[argc - 1];
	} else {
		cout << "Usage: " << argv[0] << " fileName1 fileName2 ..." << end;
		cout << "Please give at least one input file" << endl;
		return;
	}
	
	for (int i = 0; i < argc - 1; i++) {
		eventDB[i].setInputFile(argv[i]);
	}

	return;

}
