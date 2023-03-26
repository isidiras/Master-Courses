#ifndef CALOCELL_HH
#define CALOCELL_HH

class CaloCell {
public:

	CaloCell(double energy = 0, int readoutID = 0) : _e(energy), _id(readoutID) {}

	double energy() const { return _e; }
	int readoutID() const { return _id; }

	void setEnergy(double energy) { _e = energy; }
	void setReadoutID(int id) { _id = id; }

private:

	double _e;
	int _id;

};

#endif 
