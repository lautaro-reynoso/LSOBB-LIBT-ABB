//
// Created by lautaro on 19/8/2023.
//
#include "Envios.h"
#include <String.h>
#ifndef UNTITLED_LSO_H
#define UNTITLED_LSO_H
#define MAX_Envios 250
#endif //UNTITLED_LSO_H
char *Mayusculas(char string[]);


int LocalizarLIBT(Envio *lista[], char codigo[], int *pos, int p, int *contador) {

    int celdas_consultadas = 0;
    int li = 0; // li inclusivo
    int ls = (*contador); // ls exclusivo
    int m;

    while (li < ls) {
        m = (li + ls) / 2; //Segmento mas grande a izquierda
        celdas_consultadas++;


        if (strcmp(codigo, lista[m]->codigo) == 0) {


            *pos = m;


            return 1; // Elemento encontrado
        } else if (strcmp(codigo, lista[m]->codigo) < 0) {
            ls = m;
        } else {
            li = m + 1;
        }
    }

    *pos = li;
    return 0; // Elemento no encontrado

}


int AltaLIBT(Envio *lista[], Envio envio, int *contador) {
    int pos,i;
    if(LocalizarLIBT(lista,envio.codigo,&pos,0, contador)==0){
        Envio *aux;
        aux = (Envio*)malloc(sizeof(Envio));

        if(aux==NULL){
            return 2;
        }

        strcpy(aux->codigo,envio.codigo);
        strcpy(aux->nombre,envio.nombre);
        strcpy(aux->fecha_recepcion,envio.fecha_recepcion);
        strcpy(aux->fecha_envio,envio.fecha_envio);
        strcpy(aux->direccion,envio.direccion);
        strcpy(aux->nombre_r,envio.nombre_r);
        aux->dni_remitente=envio.dni_remitente;
        aux->dni_receptor=envio.dni_receptor;



        for (i = (*contador); i >= pos; i--) {
            lista[i + 1] = lista[i];
        }

        lista[pos] = aux;



        (*contador)++;

        return 1;

    }

    return 0;

}


/*
int BajaLIBT(libt *lista,Envio envio) {
    lista->costo =0.0;





    int pos, i;

    int localizar_resultado = LocalizarLIBT(lista, envio.codigo , &pos,1);

    if( (strcmp(lista->envios[pos].direccion , envio.direccion)==0) && (lista->envios[pos].dni_receptor == envio.dni_receptor)
        && (lista->envios[pos].dni_remitente == envio.dni_remitente) && (strcmp(lista->envios[pos].fecha_envio,envio.fecha_envio)==0)
        && (strcmp(lista->envios[pos].fecha_recepcion,envio.fecha_recepcion)==0) && (strcmp(lista->envios[pos].nombre,envio.nombre)==0)
        && (strcmp(lista->envios[pos].nombre_r,envio.nombre_r)==0)){

        if (localizar_resultado) {
            for (i = pos; i < lista->contador-1; i++) {
                lista->costo++; //corrimiento
                lista->envios[i] = lista->envios[i + 1];
            }



            lista->contador--;


            if (lista->costo > lista->bMax) {

                lista->bMax = lista->costo; //maximo

            }

            lista->tempb+=lista->costo; //promedio


            lista->bMed=lista->tempb/(lista->bCant+1);



            lista->bCant++; //cantidad de bajas



            return 0;

        }

    }else {
        return 1;
    }


return 0;
}
*/
int evocarLIBT (Envio *lista[], char codigo[], Envio *envio, int *contador){
    int pos;
    int res = LocalizarLIBT(lista,codigo,&pos,0,contador);
    if (res == 1){
        (*envio)= *lista[pos];
        return 1;// se
        // econtro
    }else
    return 0;
}