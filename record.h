/**Questa libreria si occupa di salvare il punteggio su un file, vengono salvati al massimo 10 punteggi in un file composto in questo modo:
punteggiogiocatore1;nomegiocatore1 '\n' punteggiogiocatore2;nomegiocatore2 '\n' punteggiogiocatore3;nomegiocatore3 '\n'

**/

void salva_punteggio (GtkWidget *exwindow)
{
///Questa funzione si occupa di salvare su file un nuovo punteggio, dato che il c non è stato pensato per modificare i file questa funzione
///salva su un array di strutture il nome e il punteggi dei record già slvati, inserisce quello nuovo, e lo ristampa
    Record *record[10]; //l'array di strutture che ci ausilia nel inserimento del nuovo punteggio
    int n,i=0,temp; //dichiaro una variabile temporanea della quale mi servo per inserire il punteggio
    FILE *fp=NULL;
    fp=fopen("record.txt","r"); //apro il file dove inserirò i nuovi punteggi
    for (n=0; n<10; n++) record[n] = (Record*)calloc(sizeof(Record),1); //alloco dinamicamente l'array di strutture

    for (n=0; !feof(fp); n++)
    {
//questo ciclo di occupa di leggere sequenzialmente:
        fscanf(fp,"%d",&temp); //il punteggio
        record[n]->pnt=temp;
        fscanf(fp,";"); //il punto e virgla che separa il punteggio dal nome
        fscanf(fp,"%s",record[n]->name); //il nome
        printf("%d\t%s\n",record[n]->pnt,record[n]->name);
        fscanf(fp,"\n"); //e il carattere d'accapo
        if (punteggio<record[n]->pnt) i++; //controllo se il punteggio è da inserire è minore di quello che viene letto attualmente
        //in modo da sarepere in quale posizione i devo inserire il nuovo punteggio
    }
    for (n=8; n>=i; n--)
    {
//questo ciclo di occupa far scalare tutti gli elementi successivi alla posizione nella quale il nuovo record deve essere inserito
        record[n+1]->pnt=record[n]->pnt;
        strcpy(record[n+1]->name,record[n]->name);

    }
    if (i<10)
    {
//inserisco il nuovo punteggio
        record[i]->pnt=punteggio;
        strcpy(record[i]->name,nome);
    }
    fclose(fp);
    remove("record.txt"); //cancello il vecchio file

    fp=fopen("record.txt","w"); //ne creo uno nuovo

    for (n=0; n<10; n++)
    {
//creo un nuovo ciclo dove stamo di nuovo il file record, con il nuovo elemento inserito
        fprintf(fp,"%d",record[n]->pnt);
        fprintf(fp,";");
        fprintf(fp,"%s",record[n]->name);
        fprintf(fp,"\n");
    }
    fclose(fp);
    free(record);

    interfaccia_punteggi(); //carico l'interfaccia grafica che stampa la lista dei punteggi
}


void verifica_punteggio (int pnt)
{

///questa funzione si occupa di capire se il punteggio che si è ottenuto durante la partita è un record
    Record *cache; //dichiarp una struttura temporanea per la lettura del file
    int n,i=0;//i in questo caso può essere 0 o 1, se è 0 il punteggio non è un record, viceversa lo è
    FILE *fp=NULL;
    fp=fopen("record.txt","r");

    cache = (Record*)calloc(sizeof(Record),1); //alloco dinamicamente la struttura temporanea


    for (n=0; !feof(fp); n++)
    {
//questo ciclo scorre tutto il file fino a che non è terminato
        fscanf(fp,"%d",&(cache->pnt)); //legge il punteggio

        fscanf(fp,";");
        fscanf(fp,"%s",cache->name); //e il nome
        fscanf(fp,"\n");
        if (pnt>cache->pnt) i=1; //se il punteggio da verificare è maggiore di uno dei punteggi presenti nel file di testo i:=0
    }

    free(cache);
    fclose(fp);
    if (i==1)
        finestra_punteggio(); //se il punteggio è da salvare viene caricata l'interfacia per l'inserimento del nome del giocatore
    else interfaccia_punteggi(); //altrimenti viene caricata direttamente l'interfaccia con la lista dei record


}
