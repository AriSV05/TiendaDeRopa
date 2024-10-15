
#include "Ejecutivo.h"

Ejecutivo::Ejecutivo(double precio, const string &color, const string &talla, bool fino) : ZapatoAbstr(precio, color,
                                                                                                        talla),
                                                                                            fino(fino) {}

bool Ejecutivo::isFino() const {
    return fino;
}

void Ejecutivo::setFino(bool fino) {
    Ejecutivo::fino = fino;
}

Ejecutivo::~Ejecutivo() {

}

string Ejecutivo::toString() {
    std::stringstream ss;
    ss<<(*this);
    return ss.str();
}

std::ostream &operator<<(std::ostream &os, const Ejecutivo &ejecutivo) {
    os << "[Ejecutivo]" << " fino: ";
    if(ejecutivo.fino){
        os<<"si";
    }
    else{
        os<<"no";
    }
    os<<" precio: "<<ejecutivo.getPrecio()<<" color: "<<ejecutivo.getColor()
      <<" talla: "<<ejecutivo.getTalla();
    return os;
}





