
#include "gtest/gtest.h"
#include "../src/TrajeAbstracto.h"
#include "../src/TrajeDeportivo.h"
#include "../src/ManagerTrajes.h"
#include "../src/CatalogoEnLinea.h"
#include "../src/Cliente.h"
#include "../src/Persona.h"
#include "../src/ManagerClientes.h"
#include "../src/ServicioTraslado.h"
#include "../src/Venta.h"

TEST(TrajeStockSuite,TrajesStock){

    TrajeAbstracto *trajeAbstracto;

    trajeAbstracto = new TrajeDeportivo;
    trajeAbstracto->setCodigo("E300");

    ManagerTrajes trajesDeportivos;
    ManagerClientes clientes;
    Persona persona1, persona2;
    CatalogoEnLinea catalogoEnLinea;
    catalogoEnLinea.setClientes(&clientes);
    trajesDeportivos.add(trajeAbstracto);
    trajesDeportivos.add(trajeAbstracto);
    trajesDeportivos.add(trajeAbstracto);

    string pais = "EE-UU";
    string ciudad = "California";
    persona1.setCiudad(ciudad);
    persona1.setPais(pais);
    catalogoEnLinea.registerObserver(&persona1);

    ServicioTraslado servicioTraslado;
    ServicioTraslado::obtenerPrecioTraslado(pais,ciudad);
    catalogoEnLinea.setTrajes(&trajesDeportivos);

    EXPECT_EQ(catalogoEnLinea.getTrajes()->getTrajes().size(),3);
    EXPECT_EQ(catalogoEnLinea.getClientes()->getClientes().size(),1);
    catalogoEnLinea.stock("E300");  //segun los clientes que haya, a esa cantidad notifica

    Venta venta(&persona2,&catalogoEnLinea);
    venta.setCompradores(&clientes);

    catalogoEnLinea.registerObserver(&persona2);
    venta.realizarVenta("E300",3);
    EXPECT_EQ(catalogoEnLinea.getTrajes()->getTrajes().size(),0);
    EXPECT_EQ(catalogoEnLinea.getClientes()->getClientes().size(),2);
    catalogoEnLinea.stock("E300");

}