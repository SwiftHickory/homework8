#include "event.h"

using namespace std;

int main(int argc, char *argv[]) {

	list<Event> evDB;

	while (inputFileName) {
		Event tempEvent(inputFileName);
		evDB.push_back(tempEvent);
	}

}