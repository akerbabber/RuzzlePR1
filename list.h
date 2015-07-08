/**Queste due funzioni si occupano di gestire la lista delle parole gi� trovate, la peculiarit� delle stringa sta nell'fatto che
   ogni nodo � composto da sue elementi, la chiave che contiene il dato da memorizzare in se, e il link che � un puntatore
   che punta all'elemento successivo
**/


void inserisci(list_pointer *ptr,char word[17])
{
    ///Questa funzione si occupa di inserire in cima alla lista un nuovo elemento
    ///ptr � la lista in entrata, mentre word � la stringa da inserire
    list_pointer temp; //dichiaro il nuovo elemento

    temp=(list_pointer)malloc(sizeof(lista)); //lo alloco dinamicamente
    if(!(temp))
    {
        fprintf(stderr,"La memoria e' piena"); //controllo se la memoria � piena
        exit(1);

    }
    strcpy(&(temp->key),word); //inserisco nella chiave della lista la stringa che riceve in input la funzion
    temp->link= *ptr; //faccio puntare temp all'primo elemento della lista, in modo cosi da inserirlo alla cima della lista
    *ptr=temp; //faccio diventare temp il primo elemento della lista
}

int visita (list_pointer ptr,char word[17])
{
    ///Questa funzione si occupa di visitare la lista elemento per elemento
    ///ptr � la lista in entrata, e word � la parola da cercare
    ///se ritorna 0 l'elemento non � presente, se ritorna 1 l'elemento � gi� presente
    if (!(ptr)) return 0; //controlla se la lista � vuota, se lo � ritorna 0
    for(; (ptr); ptr=ptr->link) //a ogni ciclo porta va avanti di un elemento nella lista
        if (strcmp(word,ptr->key)==0) return 1; //controlla se se la chiave dell'elemento � uguale alla stringa in input
    return 0;//se non trova nulla ritorna 0
}
