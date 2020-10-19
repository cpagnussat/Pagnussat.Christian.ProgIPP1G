#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


typedef struct //fecha
{
    int dia;
    int mes;
    char anio;
}eFecha;

typedef struct //marca
{
    int id;
    char descripcion[20];
}eMarca;

typedef struct //color
{
    int id;
    char nombreColor[20];
}eColor;

typedef struct //auto/tiene isEmpty
{
    int id;
    char patente;
    int idMarca;
    eMarca marca;
    eColor color;
    int idColor;
    int modelo;
    int isEmpty;// 1 esta vacia 0 esta llena
}eAuto;

typedef struct //servicio
{
    int id;
    char descripcion[20];
    int precio;
}eServicio;

typedef struct //trabajo
{
    int id;
    int patente;
    int idServicio;
    int fecha;
}eTrabajo;

#endif // FUNCIONES_H_INCLUDED



char menuOpciones();
int altaAuto(eColor color[], eMarca marca[], eAuto movil[],int tam,int id);
int inicializarAutos(eAuto movil[], int tam);
int mostrarMarcas(eMarca movil[], int tam);
void mostrarMarca(eMarca unaMarca, int t);
int mostrarColores(eColor color[], int tam);
void mostrarColor(eColor unColor, int t);
int mostrarAutos(eAuto autos[], int tam);
void mostrarAuto(eAuto unAuto);
int bajaAuto(eAuto movil[], int tam);
