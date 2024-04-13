
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Envios.h"
#include "LIBT.h"
#include "ABB.h"
#include "LSOBB.h"
int LecturaOperaciones();
char* Mayusculas();
void mostrarestructura();
void mostrarSubmenu()
{

    printf("--Submenu--\n");
    printf("1. Mostrar Lista Invertida con busqueda por Triseccion (LIBT).\n");
    printf("2. Mostrar Lista Secuencial con Busqueda Binaria (LSOBB)\n");
    printf("3. Mostrar Arbol Binario de Busqueda (ABB)\n");
    printf("4. Volver al Menu Principal\n");
}
char *Mayusculas(char string[])
{
    int i;
    for(i=0; string[i]!='\0'; i++)
    {
        string[i]= toupper(string[i]);
    }
    return  string;
}
void mostrarestructuraLIBT(libt *lista)
{
    int i;

    for(i = 0 ; i < lista->contador; i++)
    {
        mostrarenvio(lista->envios[i]);
        getchar();
    }
    printf("Total de %d envios\n", lista->contador);

}
void mostrarestructuraLSOBB(lsobb *lista)
{
    int i;

    for(i = 0 ; i < lista->contador; i++)
    {
        mostrarenvio(lista->envios[i]);
        getchar();
    }
    printf("Total de %d envios\n", lista->contador);

}





int main()
{
    // Crea las estructuras de datos (LSO, ABB) aquí

    int opcion, submenu_opcion;

    libt libt;
    libt.contador=0;
    initLIBT(&libt);

    arbol a;
    initABB(&a);


    lsobb lsobb;
    lsobb.contador=0;
    initLSOBB(&lsobb);

    LecturaOperaciones(&libt, &a, &lsobb);

    do
    {
        // Menú principal

        printf("1. Comparacion de estructuras\n");
        printf("2. Mostrar Estructura\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
            case 1:
                system("cls");


                printf("\n         AltaMax | AltaMed | BajaMax | BajaMed | Max.Ev.Ex | Med.Ev.Ex | Max.Ev.Fr | Med.Ev.Fr|\n");
                printf("-----------------------------------------------------------------------------------------------\n");
                printf("LIBT   :: %.2f   |   %.2f |  %.2f  |  %.2f  |   %.2f   |  %.2f    |  %.2f    |  %.2f   | \n",libt.aMax, libt.aMed, libt.bMax, libt.bMed, libt.eExMax, libt.eExMed, libt.eFrMax, libt.eFrMed);
                printf("-----------------------------------------------------------------------------------------------\n");
                printf("LSOBB :: %.2f   |   %.2f |  %.2f  |  %.2f  |    %.2f   |   %.2f    |   %.2f    |   %.2f   | \n",lsobb.aMax, lsobb.aMed, lsobb.bMax, lsobb.bMed, lsobb.eExMax, lsobb.eExMed, lsobb.eFrMax, lsobb.eFrMed);
                printf("-----------------------------------------------------------------------------------------------\n");
                printf("ABB   ::  %.2f   |    %.2f |   %.2f  |   %.2f  |   %.2f   |   %.2f    |  %.2f    |   %.2f   | \n",a.aMax, a.aMed, a.bMax, a.bMed, a.eExMax, a.eExMed, a.eFrMax, a.eFrMed);
                printf("-----------------------------------------------------------------------------------------------\n");
                break;
            case 2:


                system("cls");
                do
                {
                    mostrarSubmenu();
                    printf("Seleccione una opcion: ");
                    scanf("%d", &submenu_opcion);
                    switch (submenu_opcion)
                    {
                        case 1:
                            system("cls");

                            printf("Lista Secuencial Ordenada:\n");
                            mostrarestructuraLIBT(&libt);
                            break;
                        case 2:
                            system("cls");
                            printf("Lista Secuencial Ordenada con Busqueda Binaria (LSOBB):\n");
                            mostrarestructuraLSOBB(&lsobb);

                            break;
                        case 3:
                            system("cls");
                            printf("Arbol Binario de Busqueda (orden ascendente):\n");
                            preOrden(a.raiz);
                            break;
                        case 4:
                            system("cls");
                            // Volver
                            break;
                        default:
                            system("cls");
                            printf("Opcion no valida. Intente de nuevo.\n");
                    }
                }
                while (submenu_opcion != 4);

                break;
            case 3:
                system("cls");
                printf("Saliendo de la aplicacion.\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    }
    while (opcion != 3);


    return 0;
}
int LecturaOperaciones(libt *libt,arbol *arbol, lsobb *lsobb)
{

    // Declaraciones e inicializaciones
    int evocar=0;
    Envio aux;
    FILE* fp;

    if ((fp = fopen("Operaciones-Envios.txt", "r")) == NULL)
    {
        printf("No se pudo abrir el archivo");
        return 0;
    }
    else
    {
        int codigoOperador=0, contadorEnvios=0,i;
        while (!(feof(fp))&&contadorEnvios<=MAX_Envios)
        {


            fscanf(fp, "%d", &codigoOperador);


            fscanf(fp, " %[^\n]", aux.codigo);
             for(i=0;i<=8;i++){
                aux.codigo[i]=toupper(aux.codigo[i]);
            }
            if (codigoOperador == 1 || codigoOperador == 2)
            {

                // Leer y procesar los datos para Alta o Baja
                fscanf(fp, "%d", &aux.dni_receptor);

                fscanf(fp, " %[^\n]", aux.nombre);
                 for(i=0;i<=strlen(aux.nombre);i++){
                aux.nombre[i]=toupper(aux.nombre[i]);
            }
                fscanf(fp, " %[^\n]", aux.direccion);
                  for(i=0;i<=strlen(aux.direccion);i++){
                aux.direccion[i]=toupper(aux.direccion[i]);
            }
                fscanf(fp, "%d", &aux.dni_remitente);
                fscanf(fp, " %[^\n]", aux.nombre_r);
                  for(i=0;i<=strlen(aux.nombre_r);i++){
                aux.nombre_r[i]=toupper(aux.nombre_r[i]);
            }
                fscanf(fp, " %[^\n]", aux.fecha_envio);
                fscanf(fp, " %[^\n]", aux.fecha_recepcion);

                // Llama a la función correspondiente para alta o baja en las estructuras
                if(codigoOperador == 1)
                {
                    //  mostrarenvio(aux);
                    AltaLIBT(libt, aux);
                   AltaLSOBB(lsobb,aux);

                    altaABB(arbol,aux);




                }
                if(codigoOperador == 2)
                {



                    bajaABB(arbol,aux);

                   BajaLSOBB(lsobb,aux);

                    BajaLIBT(libt,aux);





                }

            }
            else if (codigoOperador == 3)
            {

                evocar++;

                int exito=0;
                evocarLIBT(libt,aux.codigo,&aux);
                evocarLSOBB(lsobb,aux.codigo,&aux);
                evocacionABB(arbol,aux.codigo,&exito);

            }
            else
            {
                // Maneja el caso de código de operación no reconocido
                printf("Error: Codigo de operación no reconocido.\n");
                //break;
            }

        }

        fclose(fp);


        return 1;
    }

}
