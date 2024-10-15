
#ifndef PROYECTO_2_CONCUADROS_H
#define PROYECTO_2_CONCUADROS_H

#include <ostream>
#include "CamisAbstr.h"

class ConCuadros  : public CamisAbstr{
private:
    bool grande;

public:
    ConCuadros(double precio, const string &color, const string &talla, bool grande);

    ~ConCuadros() override;

    bool isGrande() const;
    void setGrande(bool grande);

    string toString() override;
    friend std::ostream &operator<<(std::ostream &os, const ConCuadros &cuadros);

};


#endif //PROYECTO_2_CONCUADROS_H
