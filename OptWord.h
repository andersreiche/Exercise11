#ifndef OPTWORD_H
#define OPTWORD_H
#include "Options.h"

class OptWord : public Options			  //derived from class Options
{
public:
    OptWord();
    OptWord(int argc, const char **argv); //saves args to private vars
    OptWord(const OptWord &rhs);		  //copy constructor
    virtual ~OptWord();
	string getopt(void);				  //returns all valid WORDS on cmd
};

#endif // OPTWORD_H
