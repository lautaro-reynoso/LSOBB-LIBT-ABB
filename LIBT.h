//
// Created by lautaro on 19/8/2023.
//
#include "Envios.h"
#include <String.h>
#ifndef UNTITLED_LSO_H
#define UNTITLED_LSO_H
#endif //UNTITLED_LSO_H
char *Mayusculas(char string[]);

typedef struct {
    Envio *envios [MAX_Envios];
    int contador;
    int vector_aux[MAX_Envios];
    float eExMax, eExMed, eFrMax, eFrMed, aMax, aMed, bMax, bMed, celCont,tempa,tempb, eExCant,eFrCant,aCant,bCant,costo,costoEvoE,costoEvoF,tempe,tempef;
}libt;

void initLIBT(libt *lista) {

    lista->eExMax = 0.0;
    lista->eExMed = 0.0;
    lista->eFrMax = 0.0;
    lista->eFrMed = 0.0;
    lista->aMax = 0.0;
    lista->aMed = 0.0;
    lista->bMax = 0.0;
    lista->bMed = 0.0;
    lista->celCont = 0.0;
    lista->eExCant = 0.0;
    lista->eFrCant = 0.0;
    lista->aCant = 0.0;
    lista->bCant = 0.0;
    lista->tempa = 0.0;
    lista->tempb = 0.0;
    lista->tempe= 0.0;
    lista->tempef= 0.0;

}

int LocalizarLIBT(libt *lista, char codigo[], int *pos, int p) {

    int celdas_consultadas = 0;
    int li = 0; // li inclusivo
    int ls = (*lista).contador; // ls exclusivo
    int m;

    while (li < ls) {
        m = (li + ls) / 2; //Segmento mas grande a izquierda
        celdas_consultadas++;


        if (strcmp(codigo, lista->envios[m]->codigo) == 0) {


            *pos = m;


            return 1; // Elemento encontrado
        } else if (strcmp(codigo, lista->envios[m]->codigo) < 0) {
            ls = m;
        } else {
            li = m + 1;
        }
    }

    *pos = li;
    return 0; // Elemento no encontrado

}


int AltaLIBT(libt *lista, Envio envio) {
    int pos,i;
    if(LocalizarLIBT(lista,envio.codigo,&pos,0)==0){
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


        if((*lista).contador!=0){
            for (i = lista->contador; i >= pos; i--) {
                lista->costo++;
                lista->envios[i + 1] = lista->envios[i];


            }
        }


        lista->envios[pos] = aux;

        lista->contador++;

        if (lista->costo > lista->aMax) {
            lista->aMax = lista->costo; //maximo
        }
        lista->aCant++; //cantidad de altas

        lista->tempa+=lista->costo; //promedio

        lista->aMed=lista->tempa/(lista->aCant);

        return 1;

    }

    return 0;

}



int BajaLIBT(libt *lista,Envio envio) {
    lista->costo =0.0;





    int pos, i;


    int localizar_resultado = LocalizarLIBT(lista,envio.codigo,&pos,0);

    if( (strcmp(lista->envios[pos]->direccion , envio.direccion)==0) && (lista->envios[pos]->dni_receptor == envio.dni_receptor)
        && (lista->envios[pos]->dni_remitente == envio.dni_remitente) && (strcmp(lista->envios[pos]->fecha_envio,envio.fecha_envio)==0)
        && (strcmp(lista->envios[pos]->fecha_recepcion,envio.fecha_recepcion)==0) && (strcmp(lista->envios[pos]->nombre,envio.nombre)==0)
        && (strcmp(lista->envios[pos]->nombre_r,envio.nombre_r)==0)){

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
            lista->bCant++;
            lista->bMed=lista->tempb/(lista->bCant);



             //cantidad de bajas



            return 0;

        }

    }else {
        return 1;
    }


return 0;
}

int evocarLIBT (libt lista, char codigo[], Envio *envio, int *contador){
    int pos;
    int res = LocalizarLIBT(&lista,codigo,&pos,0);
    Envio *aux;
    if (res == 1){
        strcpy(aux->codigo,lista.envios[pos]->codigo);
        strcpy(aux->nombre,lista.envios[pos]->nombre);
        strcpy(aux->fecha_recepcion,lista.envios[pos]->fecha_recepcion);
        strcpy(aux->fecha_envio,lista.envios[pos]->fecha_envio);
        strcpy(aux->direccion,lista.envios[pos]->direccion);
        strcpy(aux->nombre_r,lista.envios[pos]->nombre_r);
        aux->dni_remitente=lista.envios[pos]->dni_remitente;
        aux->dni_receptor=lista.envios[pos]->dni_receptor;

        *envio = *aux;
        return 1;// se
        // econtro
    }else
    return 0;
}
