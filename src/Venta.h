

#ifndef PROGRA2_PROJECT_2_BRAVO_VENTA_H
#define PROGRA2_PROJECT_2_BRAVO_VENTA_H

#include "ManagerClientes.h"
#include "CatalogoEnLinea.h"
#include "ServicioTraslado.h"

class Venta {

private:
    double ganacia;
    double precioTraslado;
    double precioTraje;
    string codTrajeVendido;
    std::vector<TrajeAbstracto*> trajesVendidos;
    ManagerClientes* compradores;
    Cliente* comprador;
    CatalogoEnLinea* catalogo;

public:
    Venta(Cliente *comprador, CatalogoEnLinea *catalogo);

    virtual ~Venta();

    double getGanacia() const;
    void setGanacia(double ganacia);
    double getPrecioTraslado() const;
    void setPrecioTraslado(double precioTraslado);
    double getPrecioTraje() const;
    void setPrecioTraje(double precioTraje);
    ManagerClientes *getCompradores() const;
    void setCompradores(ManagerClientes *compradores);
    Cliente *getComprador() const;
    const string &getCodTrajeVendido() const;
    void setCodTrajeVendido(const string &codTrajeVendido);
    void setComprador(Cliente *comprador);
    CatalogoEnLinea *getCatalogo() const;
    void setCatalogo(CatalogoEnLinea *catalogo);
    const std::vector<TrajeAbstracto *> &getTrajesVendidos() const;
    void setTrajesVendidos(const std::vector<TrajeAbstracto *> &trajesVendidos);

    void agregarComprador();
    double ventaTotalConGanancia() const;
    double ventaTotalSinGanancia() const;
    double gananciaNeta();
    string realizarVenta(string, int);

    string toString();

    friend std::ostream &operator<<(std::ostream &os, const Venta &venta);


};


#endif //PROGRA2_PROJECT_2_BRAVO_VENTA_H
