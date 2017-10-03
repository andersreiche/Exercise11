#include "Options.h"
#include <string>
#include <cstring>
#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

Options::Options()
{
	//init
    argC = 0;
    argV = NULL;
    optstring = "";
    count = 0; 			//count is the iterator used to select argV
}

Options::~Options()
{

}

//reads in the valid options from main
void Options::setOptstring(string validopt)
{
	//getopt() can't reset count, so rather here than an explicit function
	count = 0;
	optstring = validopt;
}

//invokes getopt() to count how many options are on cmdline
int Options::numopt(void)
{
	//You can never reset count too often
	count = 0;
	int number = 0;
	while (getopt() != "INVALID") {
        number++;
    }
		count = 0;
		return (number);
	}

// this was needed in order to not call setOptstring() only to reset count
void Options::resetcounter(void) {
	count = 0;
}
