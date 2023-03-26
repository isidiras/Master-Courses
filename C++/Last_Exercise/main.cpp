#include<iostream>
#include"CaloCell.h"
#include"CaloGrid.h"
#include"Calorimeter.h"
#include"Point.h"
#include "CaloReader.h"
#include"CaloReaderException.h"

using namespace std;

int main() {
	
		Calorimeter clmtr(10, 10, (0, 0, 0));

		try {/*If we enter a file name that dousn't exist a CaloReaderException object will be thrown*/
			CaloReader alpha("calodat.txt");

		}
		catch (CaloReaderException x) {
			cout << x.what() << endl;
		}
		
		CaloReader r("calodat.txt");
		r.calo().dumpReadoutMap();

		CaloReader* reader=&r;
		
		while (reader->readEvent()) {/*prints both events*/
			reader->calo().dumpEvent();
		}



	
	return 0;
}