
#include "Camiseta.h"

Camiseta::Camiseta(double precio, const string &color, const string &talla, bool cuelloV) : CamisAbstr(precio, color,
                                                                                                        talla),
                                                                                             cuelloV(cuelloV) {}

bool Camiseta::isCuelloV() const {
    return cuelloV;
}

void Camiseta::setCuelloV(bool cuelloV) {
    Camiseta::cuelloV = cuelloV;
}

string Camiseta::toString() {
    std::stringstream ss;
    ss<<(*this);
    return ss.str();
}

Camiseta::~Camiseta() {

}

std::ostream &operator<<(std::ostream &os, const Camiseta &camiseta) {
    os << "[Camiseta]" << " cuello en v: ";
    if(camiseta.cuelloV){
        os<<"si";
    }
    else{
        os<<"no";
    }
    os<<" precio: "<<camiseta.getPrecio()<<" color: "<<camiseta.getColor()
      <<" talla: "<<camiseta.getTalla();
    return os;
}

