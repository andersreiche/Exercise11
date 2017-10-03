#ifndef OPTCHARS_H
#define OPTCHARS_H
#include "Options.h"

class OptChars : public Options			   //derived from class Options
{
public:
    OptChars();
    OptChars(int argc, const char **argv); //saves args to private vars
    OptChars(const OptChars &rhs);		   //copy constructor
    virtual ~OptChars();
	string getopt(void);				   //returns all valid CHARS on cmd
};

#endif // OPTCHARS_H
