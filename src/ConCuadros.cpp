
#include "ConCuadros.h"

ConCuadros::ConCuadros(double precio, const string &color, const string &talla, bool grande) : CamisAbstr(precio,
                                                                                                           color,
                                                                                                           talla),
                                                                                                grande(grande) {}

bool ConCuadros::isGrande() const {
    return grande;
}

void ConCuadros::setGrande(bool grande) {
    ConCuadros::grande = grande;
}

string ConCuadros::toString() {
    std::stringstream ss;
    ss<<(*this);
    return ss.str();
}

std::ostream &operator<<(std::ostream &os, const ConCuadros &cuadros) {
    os << "[Con cuadros]" << " cuadros grandes: ";
    if(cuadros.grande){
        os<<"si";
    }
    else{
        os<<"no";
    }
    os<<" precio: "<<cuadros.getPrecio()<<" color: "<<cuadros.getColor()
      <<" talla: "<<cuadros.getTalla();
    return os;
}

ConCuadros::~ConCuadros() = default;

