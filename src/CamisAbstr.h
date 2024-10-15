
#ifndef PROGRA2_PROJECT_2_BRAVO_CAMISABSTR_H
#define PROGRA2_PROJECT_2_BRAVO_CAMISABSTR_H

#include <iostream>
#include <sstream>

using std::string;

class CamisAbstr {
private:
    double precio;
    string color;
    string talla;

public:

    CamisAbstr(double precio, const string &color, const string &talla);

    virtual ~CamisAbstr();

    double getPrecio() const;
    void setPrecio(double precio);
    const string &getColor() const;
    void setColor(const string &color);
    const string &getTalla() const;
    void setTalla(const string &codigo);

    virtual string toString() = 0;

};


#endif //PROGRA2_PROJECT_2_BRAVO_CAMISABSTR_H
