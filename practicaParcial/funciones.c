#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funciones.h"

char menuOpciones()
{
    char opcion;
    printf("*** Bienvenido al taller de lavado***\n\n");
    printf("a_ Alta de Auto\n");
    printf("b_ Modificar Auto\n");
    printf("c_ Baja Auto\n");
    printf("d_ Listar Autos\n");
    printf("e_ Listar Marcas\n");
    printf("f_ Listar Colores\n");
    printf("g_ Listar Servicios\n");
    printf("h_ Alta Trabajo\n");
    printf("i_ Listar Trabajos\n");
    printf("j_ Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());
    return opcion;
}

int inicializarAutos(eAuto autito[], int tam)
{
    int error = 1;
    if (autito!=NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            autito[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}

int buscarLibre(eAuto autito[], int tam) //////para dar de alta
{
    int indice = -1;
    for(int i = 0; i < tam; i++)
    {
        if(autito[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarAuto(eAuto autito[], int tam, int id)
{
	int retorno = -1;

	if( autito != NULL && tam > 0)
	{
		for( int i = 0 ; i < tam ; i++ )
		{
			if(autito[i].id == id && autito[i].isEmpty == 0 )
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int bajaAuto(eAuto autito[], int tam)
{
	int error = 1;
	int id;
	int indice;
	char confirma;

	if( autito != NULL && tam > 0)
	{
		system("cls");
		printf("	*** Baja AUTO *** 	\n\n");

		mostrarAutos(autito, tam);

		printf("Ingrese el ID: ");
		scanf("%d", &id);

		indice = buscarAuto(autito, tam, id);

		if(indice == -1)
		{
			printf("No existe una persona con ese id... \n");
		}
		else
		{
			mostrarAuto(autito[indice]);
			printf("\nDesa dar de baja esta auto? s/n ");
			fflush(stdin);
			scanf("%c", &confirma);

			if(confirma == 's')
			{
				autito[indice].isEmpty = 1;

				error=0;
			}
			else
			{
				error = 2 ;
			}

		}
	}

	return error;
}

int altaAuto(eColor color[], eMarca marca[], eAuto autito[],int tam,int id)
{
    int error=1;
    int indice;
    eAuto nuevoAuto;
    if(autito!=NULL && tam > 0 && id > 0)
    {
        system("cls");
        printf("***ALTA DE AUTO***\n\n");
        indice = buscarLibre(autito, tam);
        printf("%d",indice);
        if(indice == -1)
        {
            printf("El sistema esta completo.\n\n");
        }
        else
        {
            //aplicar validaciones a las cargas
            nuevoAuto.id = id;
            nuevoAuto.isEmpty = 0;
            mostrarMarcas(marca,tam);
            printf("\nIngrese ID de la marca: ");
            scanf("%d",&nuevoAuto.idMarca);
            //nuevoAuto.marca=nuevoAuto.idMarca;
            printf("\nIngrese patente: ");
            fflush(stdin);
            scanf("%s",&nuevoAuto.patente);
            mostrarColores(color,tam);
            printf("\nIngrese ID color: ");
            scanf("%d", &nuevoAuto.idColor);
            printf("\nIngrese modelo: ");
            fflush(stdin);
            scanf("%d", &nuevoAuto.modelo);
            autito[indice] = nuevoAuto;

            /*mostrarDeportes(sports,t);
            printf("\n\nIngrese id del deporte: ");
            scanf("%d",&nuevoAuto.idDeporte);
            autito[indice] = nuevoAuto;*/
            error = 0;
        }
    }
    return error;
}

int mostrarMarcas(eMarca autito[], int tam)
{
    int error = 1;
    int flag = 0;

    if(autito!= NULL && tam > 0)
    {
        system("cls");
        printf(" ID     Marca     \n");
        printf("-------------------\n\n");
        for(int i=0; i<tam; i++)
        {
            if(autito[i].id != 0)
            {
                mostrarMarca(autito[i],tam);
                flag = 1;
            }
        }

        if( flag == 0)
        {
            printf("No hay autos en la lista");
        }
        printf("\n\n");

        error = 0;
    }
    return error;
}

void mostrarMarca(eMarca unaMarca, int t)
{
    printf(" %d   %s \n",unaMarca.id,unaMarca.descripcion);
}


int mostrarColores(eColor color[], int tam)
{
    int error = 1;
    int flag = 0;

    if(color!= NULL && tam > 0)
    {
        system("cls");
        printf(" ID      Marca     \n");
        printf("-------------------\n\n");
        for(int i=0; i<tam; i++)
        {
            if(color[i].id != 0)
            {
                mostrarColor(color[i],tam);
                flag = 1;
            }
        }

        if( flag == 0)
        {
            printf("No hay autos en la lista");
        }
        printf("\n\n");

        error = 0;
    }
    return error;
}

void mostrarColor(eColor unColor, int t)
{
    printf(" %d   %s \n",unColor.id,unColor.nombreColor);
}

int mostrarAutos(eAuto autos[], int tam)
{
    int error = 1;
    int flag = 0;
    if(autos!= NULL && tam > 0)
    {
        system("cls");
        printf(" ID      Color    Marca    Modelo\n");
        printf("-------------------------------\n\n");
        for(int i=0; i<tam; i++)
        {
            if(autos[i].isEmpty == 0)
            {

                mostrarAuto(autos[i]);
                flag = 1;
            }
        }
        if( flag == 0)
        {
            printf("No hay autos en la lista");
        }
        printf("\n\n");

        error = 0;
    }
    return error;
}

void mostrarAuto(eAuto unAuto)
{
    printf(" %d   %d  %d   %d    \n",unAuto.id,unAuto.idColor,unAuto.idMarca,unAuto.modelo);
}


