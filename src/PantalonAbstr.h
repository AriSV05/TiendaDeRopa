
#ifndef PROGRA2_PROJECT_2_BRAVO_PANTALONABSTR_H
#define PROGRA2_PROJECT_2_BRAVO_PANTALONABSTR_H

#include <iostream>
#include <sstream>

using std::string;

class PantalonAbstr {
private:
    double precio;
    string color;
    string talla;

public:
    PantalonAbstr(double precio, const string &color, const string &talla);

    virtual ~PantalonAbstr();

    double getPrecio() const;
    void setPrecio(double precio);
    const string &getColor() const;
    void setColor(const string &color);
    const string &getTalla() const;
    void setTalla(const string &talla);

    virtual string toString() = 0;
};


#endif //PROGRA2_PROJECT_2_BRAVO_PANTALONABSTR_H
