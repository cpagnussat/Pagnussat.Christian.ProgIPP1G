#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{

	int id;
	char nombre[20];
    int infectados;
    int recuperados;
    int muertos;

}ePais;

#endif // FUNCIONES_H_INCLUDED

void actualizarRecuperados(ePais pais, int recuperadosHoy);
