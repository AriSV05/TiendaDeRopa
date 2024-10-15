
#include "CamisAbstr.h"

CamisAbstr::CamisAbstr(double precio, const string &color, const string &talla) : precio(precio), color(color),
                                                                                   talla(talla) {}

double CamisAbstr::getPrecio() const {
    return precio;
}

void CamisAbstr::setPrecio(double precio) {
    CamisAbstr::precio = precio;
}

const string &CamisAbstr::getColor() const {
    return color;
}

void CamisAbstr::setColor(const string &color) {
    CamisAbstr::color = color;
}

const string &CamisAbstr::getTalla() const {
    return talla;
}

void CamisAbstr::setTalla(const string &talla) {
    CamisAbstr::talla = talla;
}

CamisAbstr::~CamisAbstr() {

}



