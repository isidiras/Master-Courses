#ifndef CALORIMETER_HH
#define CALORIMETER_HH

#include "CaloGrid.h"
#include "Point.h"
#include <iomanip>

class Calorimeter {
public:

    Calorimeter(int sizex, int sizey, Point position = Point(0, 0, 0)) :
        _grid(sizex, sizey), _pos(position)
    {}

    CaloGrid& grid() { return _grid; }

    const CaloGrid& grid() const { return _grid; }
    Point& position() { return _pos; }
    const Point& position() const { return _pos; }
    
    void dumpReadoutMap(std::ostream& os = std::cout) const {
        int i=0, j = 0;
        while (_grid.cell(i, j) != 0) {/*Because if we are outside the grid the cell function is designed that way that a null
                                       pointer will be returned. So that way we aremaking sure that we stay inside the grid*/
            while (_grid.cell(i, j) != 0) {
                os << setw(10) << _grid.cell(i, j)->readoutID();
                j++;
            }
            i++;
            j = 0;
        } 
        os << endl;
    }
    CaloCell* findCellByID(int id) {
        int i = 0, j = 0;

        while (_grid.cell(i, j) != 0) {
            while (_grid.cell(i, j) != 0) {
                if (_grid.cell(i, j)->readoutID() == id) {
                    return _grid.cell(i, j);
                }
                
                j++;
            }
            i++;
            j = 0;
        }
        return 0;
    }
    
    void clear() {
        int i = 0, j = 0;
        while (_grid.cell(i, j) != 0) {
            while (_grid.cell(i, j) != 0) {
                _grid.cell(i, j)->setEnergy(0);
           
                j++;
            }
            i++;
            j = 0;
        }

    }
    void dumpEvent(std::ostream& os = cout) {
        int i = 0, j = 0;
        while (_grid.cell(i, j) != 0) {
            while (_grid.cell(i, j) != 0) {
                if (_grid.cell(i, j)->energy() < 0.5) { os << setw(10) << "."; }
                else if (_grid.cell(i, j)->energy()>=0.5 && _grid.cell(i, j)->energy()<=2.0){ os << setw(10) << "x"; }
                else if (_grid.cell(i, j)->energy() > 2.0 ) { os << setw(10) << "X"; }
                j++;
            }
            i++;
            j = 0;
        }
        os << endl;
    }


private:

    CaloGrid _grid;
    Point _pos;


};

#endif 
