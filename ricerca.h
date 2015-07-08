
/** Algoritmo di ricerca binaria: e' un algoritmo di ricerca che rende possibile trovare un elemento in una lista ordinata.
    Nel nostro caso andremo a cercare una stringa in un vocabolario.
    Si dispone dell'inizio, della fine e del punto medio della lista ordinata, dividendola in due meta'.
    Si controlla in quale delle due metà è compresa la parola, si scarta la meta' nella quale non è compresa.
    Si continua a dividere per due la lista, fino a che non si isola la parola ricercata.
**/


void aquista_lettera (char lettera,int valore,int molt)
{
    ///questa funzione si occupa di aquisire una lettera e il suo valore, e inserirli nell'ottica della stringa che verrà poi cercata.
    ///lettera è il carattere da aquisire, e valore è il suo valore in termini di punteggio
    int c=0;
    while (stringa_ricerca[c]!='\0') c++; //sposto il cursore alla fine della stringa
    stringa_ricerca[c]=lettera; //aggiungo la lettera inserita nella stringa di ricerca
    punteggio_stringa+=valore; //e aggiungo il suo valore nel punteggio della stringa
    printf ("%d\t%d\n",punteggio_stringa,valore);
    moltiplicatore*=molt;




}

int next_bin(int indice,FILE *fp)
{
    ///questa funzione di occupa di spostare il cursone a fine parola
    ///indice è il punto nella quale attualmente è il cursore del file, mentre fp è il puntatore al file stesso
    ///ritorna la nuova posizione spostata del puntatore
    char lettera;
    int flag=0;
    while (flag==0)
    {

        fseek(fp,indice,SEEK_SET); //sposto il cursore nell'valore dell'indice
        fscanf(fp,"%c",&lettera);
        if (lettera=='\n')     flag=1;


        indice++; //sposto l'indice fino alla fine della parola, che è delimitata dal carattere '\n'

    }
    return indice;

}

int forward_bin(int indice,FILE *fp)
{
    ///questa funzione di occupa di spostare il cursone a inizio parola
    ///indice è il punto nella quale attualmente è il cursore del file, mentre fp è il puntatore al file stesso
    ///ritorna la nuova posizione spostata del puntatore

    char lettera;
    int flag=0;
    while (flag==0)
    {

        fseek(fp,indice,SEEK_SET);
        fscanf(fp,"%c",&lettera);
        if (lettera=='\n')     flag=1;
        indice--;




    }
    return indice;

}


void leggi(char *word,FILE *fp)
{
    ///questa funzione si occupa di leggere la parola presente nel dizionario
    ///word è la stringa della parola letta(passaggio per indirizzo) fp è il puntatore al file

    char lettera;
    int flag=0,indice=0;
    while (flag==0)
    {

        fseek(fp,indice,SEEK_CUR);
        fscanf(fp,"%c",&lettera);
        if (lettera=='\n')
        {
            flag=1;
            indice++;
        }
        else indice=indice-1;
    }

    fscanf(fp,"%s",word);

}

void pulisci_stringa (char *word)
{
    ///questa funzione si occupa di pulire la stringa da caratteri che non siano alfbetici,
    ///dopo che viene individuato il primo carattere non alfabetico gli altri vengono impostati a '\0'
    ///word è la stringa da ripulire
    int c,flag=0;
    for (c=0; c<16; c++)
    {
        if ((!(word[c]>=97&&word[c]<=122))||flag==1)
        {
            flag=1;
            word[c]='\0';
        }
    }


}

int file_size(FILE *fp)
{
///questa funzione si occupa di calcolare la dimensione del file
///fp è il file da misurare
    int current,last;

    current=ftell(fp); //viene salvata l'attuale posizione del cursore
    fseek(fp,0,SEEK_END); //il cursore viene spostato alla fine del file
    last=ftell(fp); //viene salvata la posizione alla fine del file
    fseek(fp,current,SEEK_SET); //il puntatore viene riportato alla posizione precedente
    return last;  //ritorna la posizione del cursore finale del file, che qeuivale alla sua dimensione



}



void ricerca_binaria (char word[17],int select)
{
///questa e' la funzione dove viene svolta la ricerca binaria
    ///word è la stringa da cercare
    ///il valore select viene utilizzato per determinare se la ricerca viene utlizzata durante il gioco o durate la verifica delle parole non trovate
    int min,max,med,flag,indice;
    char control[17];
    indice=0;
    max=file_size(diz);
    min=0;
    flag=100; //do a flag un valore arbitrario diverso da zero
    if (strlen(word)==1)
    {
        moltiplicatore=1;
        return;
    }
    //se la stringa è formata da un solo carattere la ricerca non viene effettuata
    if (visita(testa,word)==1)   //se la parola è gia prensente nella lista delle parole già trovate la ricerca non viene effettuata
    {
        if (select==0) printf("parola gia' trovata");
        return;
    }
    while (min<=max)

    {
        med=(min+max)/2;
        fseek(diz,med,SEEK_SET); //sposto il cursore nel vaore medio
        leggi(control,diz); //leggo la stringa nel dizionario
        pulisci_stringa(control); //la pulisco
        flag=strcmp(control,word); //la confronto
        if (flag==0) break; //se control e word sono uguali termino il ciclo
        else if (strcmp(word,control)<0) max=forward_bin(med,diz); //altrimenti se word è minore di control il valore medio diviene il massimo
        else min=next_bin(med,diz); //al controario se word è maggiore di control il valore medio diviene il minimo
        indice++;
    }

    if (min<=max)    //se la ricerca è andata a buon fine
    {
        printf("\n%s",word);
        printf ("\tparola trovata ");
        inserisci(&testa,word); //la parole viene inserita nelle parole già trovate
        ver_n++; // viene incrementato il contatore delle parole trovate
        punteggio_stringa*=moltiplicatore;
        punteggio+=punteggio_stringa; // il punteggio della stringa viene aggiunto all' punteggio totale }

        punteggio_stringa=0;


        if (select==0)
        {
            //il punteggio viene aggiornato nell'intefaccia del gioco
            sprintf (s,"<span foreground='#CEF' font_weight='500' font='14'>%d</span>",punteggio);
            gtk_label_set_markup(score,s);
        }
    }

    moltiplicatore=1;
}


int ricerca_parziale (char *word)
{
///e' uguale alla ricerca precedente solo che si occupa della ricerca delle parole parzialmente, viene utilizzata esclusivamente nella ricerca delle parole non trovate
    int min,max,med,flag,indice;
    int n,len;
    char control[17];
    indice=0;
    max=file_size(diz);
    min=0;
    flag=100;
    len=strlen(word); //legge la lunghezza della stringa
    if (len==1) return 1;


    while (min<=max)
    {
        med=(min+max)/2;
        fseek(diz,med,SEEK_SET);
        leggi(control,diz);
        pulisci_stringa(control);
        for (n=0; n<17; n++) if (n>=len) control[n]='\0'; //la stringa che viene letta viene pulita dai caratteri in eccesso
        flag=strcmp(control,word);
        if (flag==0) break;
        else if (strcmp(word,control)<0) max=forward_bin(med,diz);
        else min=next_bin(med,diz);
        indice++;
    }

    if (min<=max) return 1;

    else return 0;


}

