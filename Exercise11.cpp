#include "OptChars.h"
#include "OptWord.h"
#include <iostream>
#include "Options.h"
#include <sstream>
#include <fstream>
#include <string.h>
#include <ctime>
using namespace std;
OptChars opt;
OptWord opt2;

int main(int argc, char** argv) {
	try {
		int WordArgs = 0;
		int args;
		int i = 1;			// should be set to the number of valid words
		string validOpt = "f";
		//number of valid options.
		string validWords[i];
		validWords[0] = "file";

		//test if the CHARS are set by the programmer
		if (validOpt.length() == 0) {
			throw 1;
		}

		//test if the WORDS are set by the programmer
		for (int j = 0; j < i; j++) {
			if (validWords[j].length() == 0) {
				throw 2;
			}
		}

		//copy dynamically allocated obj to the global class and clean up
		OptChars *obj;
		obj = new OptChars(argc, (const char**) argv);
		opt = *obj;
		delete obj;
		obj = NULL;

		//copy dynamically allocated obj to the global class and clean up
		OptWord *obj2;
		obj2 = new OptWord(argc, (const char**) argv);
		opt2 = *obj2;
		delete obj2;
		obj2 = NULL;

		//sets the valid options for '-' commands and count them up
		opt.setOptstring(validOpt);
		args = opt.numopt();

		//sets the valid options for '--' commands and count them up
		for (int j = 0; j < i; j++) {
			opt2.setOptstring(validWords[j]);
			int word = opt2.numopt();
			WordArgs += word;
		}

		///////////////////// PRINT THE OPTIONS /////////////////////////

		// loop out the '-' commands.
		if (args != 0) {
			cout << "Valid chars on cmdline: " << args << endl;
			for (int o = 1; o <= args; o++) {
				string str = opt.getopt();
				if (str != "INVALID") //don't want to spam "INVALID"
						{
					cout << "Found match: -" << str << endl;
				}
			}
		}

		//loop out the '--' commands. Nested for loop because words options
		// take a string each and needs to be set each time
		if (WordArgs != 0) {
			cout << "valid words on cmdline: " << WordArgs << endl;
			for (int j = 0; j < i; j++) {
				opt2.setOptstring(validWords[j]);
				for (int o = 1; o <= WordArgs; o++) {
					string str = opt2.getopt();
					if (str != "INVALID") //don't want to spam "INVALID"
							{
						cout << "Found match: -" << str << endl;
					}
				}
			}
		}

		///////////////////// RUN THE OPTIONS /////////////////////////

		// resets the argument counters to 0
		opt.resetcounter();
		opt2.resetcounter();

		// loop out the '-' commands.
		if (args != 0) {
			for (int o = 1; o <= args; o++) {
				string str = opt.getopt();
				if (str == "f") {			// check for the -f option
					// next option is the filename
					string filename;
					for (int a = 1; a < argc; a++) {
						if (string(argv[a]) == "-f") {
							filename = string(argv[a + 1]);
						}
					}
					// initialize a filestream and open it with filename
					fstream myfile;
					myfile.open((filename).c_str(),
							fstream::in | fstream::out | fstream::app);

					// if file exists
					if (myfile.is_open()) {

						// read and print to consle
						string line;
						while (myfile.eof() == 0) {
							getline(myfile, line);
							cout << line << endl;
						}
						// after input operation, failbit is set
						// clear removes failbit so we can write to file
						myfile.clear();
						// get time and print to file
						time_t T;  				//create a time variable
						time(&T); 				//write time to T
						myfile << ctime(&T); 	// formats the timestamp
						myfile.close();
					}
				}
			}

		}

		//loop out the '--' commands. Nested for loop because words options
		// take a string each and needs to be set each time
		if (WordArgs != 0) {
			for (int j = 0; j < i; j++) {
				opt2.setOptstring(validWords[j]);
				for (int o = 1; o <= WordArgs; o++) {
					string str = opt2.getopt();
					if (str == "file")		// check for the --file option
							{
						// next option is the filename
						string filename;
						for (int a = 1; a < argc; a++) {
							if (string(argv[a]) == "--file") {
								filename = string(argv[a + 1]);
							}
						}
						// initialize a filestream and open it with filename
						fstream myfile;
						myfile.open((filename).c_str(),
								fstream::in | fstream::out | fstream::app);

						// if file exists
						if (myfile.is_open()) {

							// read and print to consle
							string line;
							while (myfile.eof() == 0) {
								getline(myfile, line);
								cout << line << endl;
							}
							// after input operation, failbit is set
							// clear removes failbit so we can write to file
							myfile.clear();
							// get time and print to file
							time_t T;  				//create a time variable
							time(&T); 				//write time to T
							myfile << ctime(&T); 	// formats the timestamp
							myfile.close();
						}
					}
				}
			}
		}

	} catch (int x) {
		cout << "ErrorID: " << x << endl;
	} catch (exception &s) {
		cout << "exception found: " << s.what() << endl;
	} catch (...) {
		cout << "something went wrong" << endl;
	}
	return (0);
}

