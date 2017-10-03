#ifndef OPTIONS_H_
#define OPTIONS_H_
#include <string>
using namespace std;
class Options
{
protected: 				//protected vars are inherrited as private
	int argC,count;
	char **argV;
	string optstring;	//optstring is to be tested against in getopt()
public:
    Options();
    virtual ~Options();
	void setOptstring(string validopt);
	virtual string getopt(void) = 0;	//=0 makes the class abstract
	int numopt(void);
	void resetcounter(void);
};

#endif /* OPTIONS_H_ */
