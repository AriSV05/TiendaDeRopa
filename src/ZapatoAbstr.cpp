
#include "ZapatoAbstr.h"

ZapatoAbstr::ZapatoAbstr(double precio, const string &color, const string &talla) : precio(precio), color(color),
                                                                                     talla(talla) {}


ZapatoAbstr::~ZapatoAbstr() {

}

double ZapatoAbstr::getPrecio() const {
    return precio;
}

void ZapatoAbstr::setPrecio(double precio) {
    ZapatoAbstr::precio = precio;
}

const string &ZapatoAbstr::getColor() const {
    return color;
}

void ZapatoAbstr::setColor(const string &color) {
    ZapatoAbstr::color = color;
}

const string &ZapatoAbstr::getTalla() const {
    return talla;
}

void ZapatoAbstr::setTalla(const string &talla) {
    ZapatoAbstr::talla = talla;
}

