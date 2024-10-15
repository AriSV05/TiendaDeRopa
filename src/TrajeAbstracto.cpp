
#include "TrajeAbstracto.h"

TrajeAbstracto::TrajeAbstracto() {
    this->codigo = "0";
    this->tipo = "ninguno";
    this->precioTraje = 0;
}

double TrajeAbstracto::getPrecioTraje() const {
    return precioTraje;
}

void TrajeAbstracto::setPrecioTraje(double precioTraje) {
    TrajeAbstracto::precioTraje = precioTraje;
}

const string &TrajeAbstracto::getTipo() const {
    return tipo;
}

void TrajeAbstracto::setTipo(const string &tipo) {
    TrajeAbstracto::tipo = tipo;
}

const string &TrajeAbstracto::getCodigo() const {
    return codigo;
}

void TrajeAbstracto::setCodigo(const string &codigo) {
    TrajeAbstracto::codigo = codigo;
}
