#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{

//// prueba de ejercicio de acumulacion
    ePais Argentina;

    Argentina.recuperados = 50;


    actualizarRecuperados(Argentina, 200);

    printf("%d", Argentina.recuperados);





}

/// ejercicio de ordenamiento

void ordenarCaracteres(char vec[], int tam)
{

    char aux;
    for(int i=0; i< tam -1 ; i++)
    {
        for(int j=i+1; j < tam; j++)
        {
            if(vec[i] > vec[j])
            {
                aux = vec[i];
                vec[i] = vec[j];
                vec[j]=aux;
            }
        }
    }
}
