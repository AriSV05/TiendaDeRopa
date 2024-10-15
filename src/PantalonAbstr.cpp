
#include "PantalonAbstr.h"

PantalonAbstr::PantalonAbstr(double precio, const string &color, const string &talla) : precio(precio), color(color),
                                                                                         talla(talla) {}

PantalonAbstr::~PantalonAbstr() {

}

double PantalonAbstr::getPrecio() const {
    return precio;
}

void PantalonAbstr::setPrecio(double precio) {
    PantalonAbstr::precio = precio;
}

const string &PantalonAbstr::getColor() const {
    return color;
}

void PantalonAbstr::setColor(const string &color) {
    PantalonAbstr::color = color;
}

const string &PantalonAbstr::getTalla() const {
    return talla;
}

void PantalonAbstr::setTalla(const string &codigo) {
    PantalonAbstr::talla = codigo;
}
