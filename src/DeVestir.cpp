
#include "DeVestir.h"

DeVestir::DeVestir(double precio, const string &color, const string &talla, bool casimir) : PantalonAbstr(precio,
                                                                                                           color,
                                                                                                           talla),
                                                                                             casimir(casimir) {}

DeVestir::~DeVestir() {

}

bool DeVestir::isCasimir() const {
    return casimir;
}

void DeVestir::setCasimir(bool casimir) {
    DeVestir::casimir = casimir;
}

string DeVestir::toString() {
    std::stringstream ss;
    ss<<(*this);
    return ss.str();
}

std::ostream &operator<<(std::ostream &os, const DeVestir &vestir) {
    os << "[De vestir]" << " casimir: ";
    if(vestir.casimir){
        os<<"si";
    }
    else{
        os<<"no";
    }
    os<<" precio: "<<vestir.getPrecio()<<" color: "<<vestir.getColor()
      <<" talla: "<<vestir.getTalla();
    return os;
}
