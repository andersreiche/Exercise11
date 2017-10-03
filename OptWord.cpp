#include "OptWord.h"
#include <string>
#include <cstring>
#include <stdio.h>
#include <iostream>
using namespace std;

OptWord::OptWord(int argc, const char **argv) {
	argC = argc;
	argV = (char**) argv;
	optstring = "";
	count = 0;
}


OptWord::OptWord(const OptWord &rhs) {

	argC = rhs.argC;
	argV = rhs.argV;
	optstring = rhs.optstring;
	count = rhs.count;
}



OptWord::OptWord() {
}

OptWord::~OptWord() {

}

//This looks for the WORD commands starting with '--'
string OptWord::getopt(void) {

	for (; count < argC; count++) {

		if (argV[count][0] == '-' && argV[count][1] == '-'
				&& strlen(argV[count]) > 3) {
			string str(argV[count] + 2);	//filter out the dashes

			if (str == optstring) {			//Is this a valid option?
				count++;
				return (optstring);			//If yes, return it.
			}
		}
	}
	return ("INVALID");						//If no, return "INVALID"
}
