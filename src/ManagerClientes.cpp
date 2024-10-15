
#include "ManagerClientes.h"

void ManagerClientes::add(Cliente *cliente) {
    int j = 0;
    for(auto cliente_ : getClientes()){
        if(cliente == cliente_){
            j = 1;
        }
        else{
            continue;
        }
    }
    if(j !=1 ){
        clientes.push_back(cliente);
    }
}

void ManagerClientes::remove(Cliente *cliente) {

    auto iterator= std::find(clientes.begin(),clientes.end(),cliente);

    if (iterator != clientes.end()) { // observer found
        clientes.erase(iterator); // remove the observer
    }

}

const std::vector<Cliente *> &ManagerClientes::getClientes() const {
    return clientes;
}

void ManagerClientes::setClientes(const std::vector<Cliente *> &clientes) {
    ManagerClientes::clientes = clientes;
}
