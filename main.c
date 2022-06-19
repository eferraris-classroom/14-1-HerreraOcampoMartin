#include "Numeros.h"

int main() {

    ListaNumeros *lista1 = crearListaNumeros();
    ListaNumeros *lista2 = crearListaNumeros();

    agregarNumero(lista1, crearNumero(12000));
    agregarNumero(lista1, crearNumero(432));
    agregarNumero(lista1, crearNumero(6456));
    agregarNumero(lista1, crearNumero(234));
    agregarNumero(lista2, crearNumero(-3));
    agregarNumero(lista2, crearNumero(34));
    agregarNumero(lista2, crearNumero(534));
    agregarNumero(lista2, crearNumero(-756));

    imprimirNumeros(lista1);
    imprimirNumeros(lista2);

    ListaNumeros *concatenada = concatenarLista(lista1, lista2);

    imprimirNumeros(concatenada);

    liberarNumeros(concatenada);


    return 0;
}
