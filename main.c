#include <stdlib.h>
#include <gtk/gtk.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define LATO 4   //definisco la costante del lato della tabella
#define N 26    //definisco la costante del numero delle lettere dell'alfabeto


#include "strutture.h"
#include "variabili_globali.h"
#include "dichiarazione_funzioni.h"

#include "eventi.h"
#include "record.h"
#include "list.h"
#include "ricerca.h"
#include "generazione-matrice.h"
#include "interfaccia-menu.h"
#include "interfaccia-gioco.h"
#include "verifica.h"


int main (int argc, char *argv[])
{

    int i,j;
    diz=fopen("data.txt", "r"); //apro il dizionario
    for (i=0; i<LATO; i++) for (j=0; j<LATO; j++) pulsanti [i] [j] = (Matrice*)malloc(sizeof(Matrice)); //alloco dinamicamente i pulsanti
    for (i=0; i<LATO; i++) for (j=0; j<LATO; j++) lettere  [i] [j] = (Matrice*)malloc(sizeof(Matrice)); //alloco dinamicamente le labels dei pulsanti



    gtk_init (&argc,&argv) ;


    menu(); //carico il menu
    gtk_main();


}






