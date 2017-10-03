#include "OptChars.h"
#include <string>
#include <cstring>
#include <stdio.h>
#include <iostream>
using namespace std;



OptChars::OptChars(int argc, const char **argv)
{
	argC = argc;
	argV = (char**) argv;
	optstring = "";
	count = 0;
}


OptChars::OptChars(const OptChars &rhs)
{

    argC = rhs.argC;
	argV = rhs.argV;
    optstring = rhs.optstring;
    count = rhs.count;
}


OptChars::OptChars()
{
}


OptChars::~OptChars()
{

}

//This looks for the CHAR commands starting with '-'
string OptChars::getopt(void)
{
	for (; count < argC; count++)
	{

		//char commands can be stored in a single string, so we loop it by char
		for (size_t j = 0; j < optstring.size(); j++)
		{

			//first element should be '-' and ALWAYS 2 elements long
			if (argV[count][0] == '-' && strlen(argV[count]) == 2)
			{
			if(argV[count][1] == optstring[j]) 	//Is this a valid option?
					{
				count++;
				return (optstring.substr(j,1));	//If yes, return it.
					}
				}
			}
		}

	return ("INVALID");							//If no, return "INVALID"
}
