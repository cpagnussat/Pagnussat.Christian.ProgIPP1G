#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

#define TAM 6



int main()
{
    char seguir = 's';
    char confirma;
    eAuto movil[TAM];
    eMarca datosMarca [20]= {{1000,"Renault"},{1001,"Fiat"},{1002,"Ford"},{1003,"Chevrolet"},{1004,"Peugeot"},};
    eColor datosColor [20]= { {5000,"rojo"}, {5001,"Negro"}, {5002,"blanco"}, {5003,"gris"}, {5004,"Azul"},  };


    int proximoIdAuto=0001;

    if(inicializarAutos(movil, TAM)==0)
    {
        printf("Autos inicializadas con exito!");
    }
    else
    {
        printf("Ha ocurrido un problema al inicializar autos");
    }

    do
    {

        system("cls");
        switch(menuOpciones())
        {

        case 'a':
            if(altaAuto(datosColor,datosMarca,movil, TAM, proximoIdAuto) == 0)
            {
                proximoIdAuto++;
                printf("ALTA EXITOSA!\n");
            }
            else
            {
                printf("Problema para realizar el alta\n\n");
            }
            break;
        case 'b':
            break;
        case 'c':
            bajaAuto(movil, TAM);
            break;
        case 'd':
            mostrarAutos(movil,TAM);
            break;
        case 'e':
            break;
        case 'f':
            break;
        case 'g':
            break;
        case 'h':
            break;
        case 'i':
            break;
        case 'j':
            printf("Confirma salida? Ingrese s/n: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }

            break;
        default:
            printf("Opcion invalida!!!\n");
        }
        system("pause");
    }
    while( seguir == 's');
    return 0;
}
