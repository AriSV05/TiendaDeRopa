
#include "gtest/gtest.h"
#include "../src/CatalogoEnLinea.h"
#include "../src/Cliente.h"
#include "../src/Persona.h"
#include "../src/ManagerClientes.h"

TEST(EmpresaOPersona,isEmpresa_isPersona){


    Persona persona1;
    persona1.setNombre("Ana");
    persona1.setCedula("111");
    persona1.setCiudad("Paris");
    persona1.setNacionalidad("francesa");
    persona1.setPais("Francia");
    persona1.setCorreoElec("ana@una.cr");

    Empresa empresa1;
    empresa1.setNombre("Econo");
    empresa1.setCedula("2020");
    empresa1.setCiudad("New York");
    empresa1.setPais("EEUU");
    empresa1.setCorreoElec("econo@una.cr");
    empresa1.setClienteFrecuente(true);

    ManagerClientes managerClientes;
    managerClientes.add(&persona1);
    managerClientes.add(&empresa1);

    CatalogoEnLinea catalogo;
    catalogo.setClientes(&managerClientes);

    EXPECT_STREQ(catalogo.isPersona().c_str(),"[Persona] nombre: Ana cedula fisica: 111 correo electronico: ana@una.cr pago por suscripcion: 200$ anuales nacionalidad: francesa ciudad: Paris pais: Francia\n");

    EXPECT_STREQ(catalogo.isEmpresa().c_str(),"[Empresa] nombre: Econo cedula juridica: 2020 correo electronico: econo@una.cr pago por suscripcion: 400$ anuales ciudad: New York pais: EEUU cliente frecuente: si\n");

}
