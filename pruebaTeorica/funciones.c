#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


void actualizarRecuperados(ePais pais, int recuperadosHoy)
{
    pais.recuperados = pais.recuperados + recuperadosHoy;

}
