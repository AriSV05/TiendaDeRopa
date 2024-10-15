
#ifndef PROGRA2_PROJECT_2_BRAVO_ZAPATOABSTR_H
#define PROGRA2_PROJECT_2_BRAVO_ZAPATOABSTR_H

#include <iostream>
#include <sstream>

using std::string;

class ZapatoAbstr {
private:
    double precio;
    string color;
    string talla;

public:
    ZapatoAbstr(double precio, const string &color, const string &talla);

    virtual ~ZapatoAbstr();

    double getPrecio() const;
    void setPrecio(double precio);
    const string &getColor() const;
    void setColor(const string &color);
    const string &getTalla() const;
    void setTalla(const string &talla);

    virtual string toString() = 0;
};


#endif //PROGRA2_PROJECT_2_BRAVO_ZAPATOABSTR_H
