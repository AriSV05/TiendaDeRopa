
#include "Bota.h"

Bota::Bota(double precio, const string &color, const string &talla, bool alta) : ZapatoAbstr(precio, color, talla),
                                                                                  alta(alta) {}

bool Bota::isAlta() const {
    return alta;
}

void Bota::setAlta(bool alta) {
    Bota::alta = alta;
}

Bota::~Bota() {

}

string Bota::toString() {
    std::stringstream ss;
    ss<<(*this);
    return ss.str();
}

std::ostream &operator<<(std::ostream &os, const Bota &bota) {
    os << "[Botas]" << " altas: ";
    if(bota.alta){
        os<<"si";
    }
    else{
        os<<"no";
    }
    os<<" precio: "<<bota.getPrecio()<<" color: "<<bota.getColor()
      <<" talla: "<<bota.getTalla();
    return os;
}


