
#ifndef II_MANAGERCLIENTES_H
#define II_MANAGERCLIENTES_H
#include "Cliente.h"
#include <vector>

class ManagerClientes {

private:
    std::vector<Cliente*> clientes;

public:
    void add(Cliente* cliente);
    void remove(Cliente* cliente);

    const std::vector<Cliente *> &getClientes() const;
    void setClientes(const std::vector<Cliente *> &clientes);
};


#endif //II_MANAGERCLIENTES_H
