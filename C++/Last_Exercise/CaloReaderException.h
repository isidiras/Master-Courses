#ifndef CALOREADEREXCEPTION_HH
#define CALOREADEREXCEPTION_HH


#include"Calorimeter.h"
#include<fstream>
#include<string>

class CaloReaderException {
public:
	CaloReaderException(const char* what) :_what(what) {};
	const char* what() { return  _what.c_str(); }

private:
	string _what;
};



#endif
