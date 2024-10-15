
#include "gtest/gtest.h"
#include "../src/TrajeAbstracto.h"
#include "../src/TrajeDeportivo.h"
#include "../src/ServicioTraslado.h"
#include "../src/ManagerTrajes.h"
#include "../src/CatalogoEnLinea.h"
#include "../src/ServicioTraslado.h"
#include "../src/Empresa.h"
#include "../src/Venta.h"
#include "../src/ManagerVentas.h"
#include "../lib/googletest/googletest/include/gtest/gtest.h"

TEST(VentaTestSuite,realizarVenta){

    TrajeAbstracto *trajeAbstracto;
    trajeAbstracto = new TrajeDeportivo;

    trajeAbstracto->setCodigo("E300");
    trajeAbstracto->crearCamisa(200, "azul", "G", true);
    trajeAbstracto->crearPantalon(110, "azul", "G", false);
    trajeAbstracto->crearCalzado(225, "azul", "G", false);

    EXPECT_EQ(trajeAbstracto->getPrecioTraje(),535);    //check

    ManagerTrajes trajesDeportivos;
    CatalogoEnLinea catalogoEnLinea;
    trajesDeportivos.add(trajeAbstracto);

    Persona personaCliente;
    ManagerClientes clientes;

    catalogoEnLinea.setClientes(&clientes);
    catalogoEnLinea.setTrajes(&trajesDeportivos);
    string pais = "EE-UU";
    string ciudad = "California";
    personaCliente.setCiudad(ciudad);
    personaCliente.setPais(pais);
    catalogoEnLinea.registerObserver(&personaCliente);

    catalogoEnLinea.catalogo();

    ServicioTraslado servicioTraslado;
    ServicioTraslado::obtenerPrecioTraslado(pais,ciudad);

    Venta venta(&personaCliente,&catalogoEnLinea);
    venta.setCompradores(&clientes);

    ManagerVentas ventas;
    ventas.add(&venta);
    venta.realizarVenta("E300",1);

    EXPECT_EQ(venta.ventaTotalSinGanancia(),745);   //check
    EXPECT_EQ(venta.ventaTotalConGanancia(),1173);  //check
    EXPECT_EQ(venta.getGanacia(),997.05);

    EXPECT_STREQ(ventas.trajeMasVendido().c_str(),"E300");  //check

    trajesDeportivos.add(trajeAbstracto);
    trajesDeportivos.add(trajeAbstracto);
    trajesDeportivos.add(trajeAbstracto);

    Venta venta2(&personaCliente,&catalogoEnLinea);
    venta2.setCompradores(&clientes);
    venta2.realizarVenta("E300",2);
    EXPECT_EQ(venta2.getGanacia(),1815.6);

    ventas.add(&venta2);

    EXPECT_EQ(ventas.ventasTotales(),2812.65);  //check - se basa en mi total de la valor neto final

}