//
// Created by Raquel on 15/6/2022.
//

#include "gtest/gtest.h"
#include "../src/Cliente.h"
#include "../src/Persona.h"
#include "../src/Empresa.h"
#include "../src/ManagerClientes.h"
#include "../src/CatalogoEnLinea.h"


TEST(ClienteTestSuite, ingresar_clientes) {
    Persona persona1;
    persona1.setNombre("Ana");
    persona1.setCedula("111");
    persona1.setCiudad("Paris");
    persona1.setNacionalidad("francesa");
    persona1.setPais("Francia");
    persona1.setCorreoElec("ana@una.cr");

    Empresa empresa1, em2;
    empresa1.setNombre("Econo");
    empresa1.setCedula("2020");
    empresa1.setCiudad("New York");
    empresa1.setPais("EEUU");
    empresa1.setCorreoElec("econo@una.cr");
    empresa1.setClienteFrecuente(true);

    ManagerClientes managerClientes;
    managerClientes.add(&persona1);
    managerClientes.add(&empresa1);

    EXPECT_EQ(managerClientes.getClientes().size(), 2);

    managerClientes.remove(&persona1);
    EXPECT_EQ(managerClientes.getClientes().size(), 1);
    managerClientes.add(&persona1);

    //si agrego unn cliente exactamente igual
    managerClientes.add(&empresa1);
    EXPECT_EQ(managerClientes.getClientes().size(), 2);

    //catalogo utiliza los mismo clientes, los guarda y remueve en el mismo sentido

    CatalogoEnLinea catalogo;
    catalogo.setClientes(&managerClientes);
    catalogo.registerObserver(&em2);
    EXPECT_EQ(managerClientes.getClientes().size(), 3);

    catalogo.registerObserver(&em2);
    EXPECT_EQ(managerClientes.getClientes().size(), 3);

    catalogo.removeObserver(&persona1);
    EXPECT_EQ(managerClientes.getClientes().size(), 2);

}
