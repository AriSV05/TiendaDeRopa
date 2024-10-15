
#include "Pantaloneta.h"

Pantaloneta::Pantaloneta(double precio, const string &color, const string &talla, bool estampado) : PantalonAbstr(
        precio, color, talla), estampado(estampado) {}

Pantaloneta::~Pantaloneta() {

}

bool Pantaloneta::isEstampado() const {
    return estampado;
}

void Pantaloneta::setEstampado(bool estampado) {
    Pantaloneta::estampado = estampado;
}

string Pantaloneta::toString() {
    std::stringstream ss;
    ss<<(*this);
    return ss.str();
}

std::ostream &operator<<(std::ostream &os, const Pantaloneta &pantaloneta) {
    os << "[Pantaloneta]" << " estampado: ";
    if(pantaloneta.estampado){
        os<<"si";
    }
    else{
        os<<"no";
    }
    os<<" precio: "<<pantaloneta.getPrecio()<<" color: "<<pantaloneta.getColor()
      <<" talla: "<<pantaloneta.getTalla();
    return os;
}
