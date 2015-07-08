
Matrice *pulsanti[4][4];  //dichiaro la struttura globale su cui si poggia il programma
lettera *lettere[4][4];   //dichiaro la struttura globale che si occupa della visualizzazione grafica dei pulsanti
char stringa_ricerca[17]; //la stringa attraverso la quale passa la ricerca
int punteggio_stringa,punteggio; //rispettivamente: il punteggio temporaneo dlla parola e il punteggio della partita
GtkWidget *stringa; //widget che stampa a schermo la stringa_ricerca
char s[100]; //variabile temporanea utilizzata per fare i vari cast verso tipo char, utile per usare i widget gtk
int cronometro=120; //il tempo della partita
GtkWidget *tempo; //il widget che visualizza il tempo
GtkWidget *score; //il widget che visualizza il punteggio
int toggle=0; //l'intero che indica che tipo di partit si sta eseguendo (partit normale, partita scrabble)
int ver_n=0;    //conta quante parole sono stte trovate dalla ricerca automatica a fine partita
FILE *diz=NULL; //pntatore al file del dizionario
int n_spazi; //
char *nome; //e' la stringa che contiene l'imput della entry dove viene inserito il nome dell'utente
list_pointer testa=NULL; //puntatore lista
int moltiplicatore=1;
