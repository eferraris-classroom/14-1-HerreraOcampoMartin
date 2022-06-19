#include "Numeros.h"
#include <stdlib.h>
#include <stdio.h>

ListaNumeros *crearListaNumeros(){
    ListaNumeros *lista = (ListaNumeros*) malloc(sizeof (ListaNumeros));

    if(lista == NULL){
        printf("No hay memoria libre.");
        exit(-1);
    }

    lista->tam = 0;
    lista->primero = NULL;

    return lista;
}

Numero *crearNumero(int valor){

    Numero *num = (Numero*) malloc(sizeof (Numero));

    if(num == NULL){
        printf("No hay memoria libre.");
        exit(-1);
    }

    num->siguiente = NULL;
    num->valor = valor;

    return num;
}

void agregarNumero(ListaNumeros *lista, Numero *nuevo){
    nuevo->siguiente = lista->primero;
    lista->primero = nuevo;
    lista->tam++;
}

void eliminarNumero(ListaNumeros *lista, int valor){
    Numero *aux = lista->primero;

    if(aux == NULL){
        return;
    }

    Numero *act = NULL, *ant = NULL;
    act = aux;
    ant = act;

    while(act != NULL && act->valor != valor){
        ant = act;
        act = act->siguiente;
    }

    if(act == NULL){
        return;
    }

    if(act == ant){
        lista->primero = act->siguiente;
        free(act);
    }else {
        ant->siguiente = act->siguiente;
        free(act);
    }
    lista->tam--;

}

void imprimirNumeros(ListaNumeros *lista){
    Numero *aux = lista->primero;

    if(aux == NULL){
        printf("La lista está vacía.\n");
        return;
    }

    for (; aux != NULL; aux = aux->siguiente){
        printf("%d ", aux->valor);
    }

    printf("\n");
}

void liberarNumeros(ListaNumeros *lista){
    Numero *aux = lista->primero;

    if(aux != NULL){
        while(aux->siguiente != NULL){
            Numero *ant = aux;
            aux = aux->siguiente;
            free(ant);
        }

        free(aux);
    }

    free(lista);
}

