/** Verifica delle parole: per trovare quali parole non sono state trovate dal giocatore, chiamo per ogni pulsante la funzione ricorsiva trova_parole()
    Il sistema è molto semplice, trova parole verifica ogni combinazione di pulsanti, fermandosi quando la combinazione non corrisponde a nessuna parole
    del dizionario, anche parzialmente, ad esempio ipotizziamo di dover verificare una parola come "rig" e che adiacentemente abbia le lettere 'o' 'a' 'z':
    la funzione si comporterà nel seguente modo
    1)Vede se la stringa "rig" sia presente in una delle stringhe del dizionario anche se parzialmente, quindi magari trovando che
    "rig" è presente nella parola "righello" procede con la funzione
    2)Controlla se la parola rig è presente nel dizionario, non trovandola
    3)Richiama ricorsivamente la funzione per le stringhe "rigo" "riga" "rigz"
    4)"rigo" e "riga" sono prensenti nel dizionario e dunque chiamerà una funzione ricorsiva per la ricerca aggiungendo le lettere adiacenti,
      invece "rigz" prima non viene trovata nella ricerca parziale, e dunque poi nella totale, causando cosi la fine del ramo ricorsive che parte da "rigz"
**/
void verifica ()
{
///Questa funzione non fà altro che  richiamare 16 volte (una per ogni pulsante) la funzione "trova_parole"
    int i,j,premuti[4*4];
    char cerca[17];
    pulisci_stringa(cerca);
    for (i=0; i<16; i++)
    {

        premuti[i]=0; //azzera tutti i pulsanti in modo che risultino tutti non premuti
    }
    for (i=0; i<4; i++) for (j=0; j<4; j++)
        {

            trova_parole(i,j,&premuti[0],cerca); //richiama ricorsivamente per ogni singolo pulsante

        }
    printf("\n%d\n",ver_n);

}

void trova_parole(int i,int j, int premuti[4*4],char *cerca)
{
/// Questa funzione ricorsiva si occupa della ricerca automatica delle parole non trovate dall'giocatore
/// i e j sono riga e colonna della lettera che sta venendo aggiunta alla stringa
/// il vettore premuti e un vettore di 16 elementi che si occupa di indicare quali pulsanti siano già stati premuti, in modo che il percorso
/// non possa sovrapporsi, dato che in ruzzle se un pulsante è già stato premuto non può essere ripremuto
/// cerca invece è la parola che sta venendo attualmente cercata
    int n,nuovo_premuti[4*4]; //creo un nuovo vettore dei pulsanti premuti
    char nuovo_cerca[17]; //creo una nuova stringa ricerca
    for (n=0; n<4*4; n++) nuovo_premuti[n]=premuti[n]; // copio i vecchi pulsanti premuti nel nuovo vettore
    strcpy(nuovo_cerca,cerca); //copio la vecchia stringa nella nuova
    n=strlen(nuovo_cerca);
    nuovo_cerca[n]=pulsanti[i][j]->lettera;
    nuovo_cerca[n+1]='\0';
    nuovo_premuti[i*4+j]=1; //aggiungo la nuova posizione ai pulsanti premuti
    if (ricerca_parziale(nuovo_cerca)==1) //se la ricerca parziale và a buon fine
    {

        for (n=0; n<4*4; n++) if ((((n/4<=i+1)&&(n/4>=i-1))&&((n%4<=j+1)&&(n%4>=j-1)))&&(nuovo_premuti[n]==0)) //in tutti i pulsanti adiacenti
            {

                trova_parole(n/4,n%4,&nuovo_premuti[0],nuovo_cerca); //presegue ricorsivamente la ricerca delle parole
            }
        pulisci_stringa(nuovo_cerca);
        ricerca_binaria(nuovo_cerca,1); //la funzione termina con la ricerca della parola stessa
    }
}
