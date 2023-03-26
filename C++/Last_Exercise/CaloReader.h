#ifndef CALOREADER_HH
#define CALOREADER_HH

#include <iostream>
#include <fstream>
#include<string>
#include"Calorimeter.h"
#include"CaloReaderException.h"

using namespace std;



class CaloReader {
public:
	CaloReader(const char* filename):_file(filename),_calo(0) {
		if (_file.fail()) {throw CaloReaderException("Error file could not open correctly");}

		_file >> word;
		if (word != "BEGIN_CALO_DEF") { throw CaloReaderException("Error file does not have the correct structure"); }
		_file >> word;
		if(word!="SIZE"){ throw CaloReaderException("Error file does not have the correct structure"); }
		_file >> size_x;
		_file >> size_y;
		_calo = new Calorimeter(size_x, size_y);
		_file >> word;
		while (word == "POSITION") {
			_file >> readoutID;
			_file >> ix;
			_file >> iy;
			_calo->grid().cell(ix, iy)->setReadoutID(readoutID);
			_file >> word;
		}
		if(word!="END_CALO_DEF"){ throw CaloReaderException("Error file does not have the correct structure"); }

	}



	~CaloReader() {};

	Calorimeter& calo() { return *_calo; }//Accessor

	bool readEvent() {
		if (_file.fail()) { return false; }
		_calo->clear();
		_file >> word;
		if (word != "BEGIN_EVENT") { return false; }
		_file >> word;
		if (word != "ENERGY") { return false; }
		while (word == "ENERGY") {
			_file >> readoutID;
			_file >> energy;
			_calo->findCellByID(readoutID)->setEnergy(energy);
			_file >> word;

		}
		
		if (word != "END_EVENT") { return false; }
		return true;
		
	}
	
private:
	Calorimeter* _calo;
	ifstream _file;
	string word = " ";
	int size_x, size_y;
	int readoutID, ix, iy;
	double energy;

	


};




#endif



