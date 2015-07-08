Parola globale;           //diciaro la matrice per la gestione del dizionario

/** Questa libreria si occupa di generare la matrice di lettere, valori e moltiplicatori, la generazione può essere fatta attraverso due modi:
    il primo crea conta le lettere presenti nel dizionario e di conseguenza crea le probabilità per la generazione delle singole lettere della matrice
    il secondo utilizza dei valori predefiniti in stile scrabble, anche se in realtà mi sono avvalso delle tavole di verita della lingua italiana.
**/


void generazione_matrix()
{

///Questa funzione si occupa del conteggio delle lettere del dizionario per crare le probabilità di generazione, e poi genera la matrice
    srand(time(NULL)); //creo il seme per la gnerazione randomica



    char a,b,x;
    int i=0, flag=0, j=0, num=0, random=0,cont1=0,cont2=0,aux=0,doppia=0;



    //associo al puntatore di tipo FILE data.txt

    globale.contatore = calloc (N, sizeof(int)); //alloco dinamicamente il contatore

    //Popolo il vettore delle lettere dell'alfabeto
    for(i=0; i<N; i++)
        globale.lettere[i]=97+i;


    //Conto quante lettere ci sono
    for(; !feof(diz);)
    {
        a=fgetc(diz);
        if (a!=doppia) globale.contatore[a-97]++;
        doppia=a;
    }

    printf("Nel vocabolario sono presenti %d lettere\n\n", num/100);

    //Calcolo la frequenza delle lettere
    for(i=0; i<N; i++)
        printf("%c: (Totale: %d)\t(Frequenza: %0.2f)\n", globale.lettere[i], globale.contatore[i], (float)globale.contatore[i]/num);

    //Ordino le lettere in base alla loro apparizione
    for(i=0; i<N; i++)
    {
        for(j=i+1; j<N; j++)
        {
            if(globale.contatore[i]>globale.contatore[j])
            {
                //Ordino le lettere in base al conteggio
                b=globale.lettere[i];
                globale.lettere[i]=globale.lettere[j];
                globale.lettere[j]=b;

                //Ordino le più frequenti
                flag=globale.contatore[i];
                globale.contatore[i]=globale.contatore[j];
                globale.contatore[j]=flag;
            }
        }
        printf("\n%c: %d", globale.lettere[i], globale.contatore[i]/100);
        num += globale.contatore[i]/100;
    }

    printf("\n\n");



///Generazione matrice
///Mi avvalgo di un sistema semplice , sommo il numero di tutte le lettere presenti nel dizionario come se fossero in fila
///questa fila è formata da vari range che appartengono ognuno a una determinata lettera dell'alfabeto
///ad esempio ipotizzando che a b c siano presenti 10 volte caduna nel file
/// minletteraa=0 maxletteraa=10 minletterab=10 maxletterab=20 minletterac=20 maxletterac=30
/// poi creo un cico che sequenzialmente controlla in quale range appartiene il numero random

    for(i=0; i<LATO; i++)
    {
        for(j=0; j<LATO; j++)
        {
            cont1=0; //cont1 rappresenta il minimo del range
            cont2=globale.contatore[0]/100; //cont2 rappresenta il massimo, qesto numero è il numero di volte che appare il primo carattere
            random =(rand()%(num)); //genero il numero random
            for(x=0; x<26; x++)
            {

                if(cont2>=random && random>=cont1) //se il numero appartiene al range
                {

                    pulsanti[i][j]->lettera=globale.lettere[x]; //la lettera nella matrice diviene quella del range
                    pulsanti[i][j]->valore=valore_lettera(x); //e anche il suo valore

                    break;
                }
                else
                {

                    aux=cont2; //salvo il massimo in una variabile ausiliaria
                    cont2+=globale.contatore[x+1]/100; //passo al nuovo massimo che non è altro che la somma tra il massimo precedente e il
                    //di lettere x presenti nl dizionario
                    cont1=aux; //il vecchio massimo diventa il nuovo minimo, spostando così in avanti il range



                }
            }
            printf("%d....%c...%d\t",random, pulsanti[i][j]->lettera,pulsanti[i][j]->valore);

        }
        printf("\n");
    }
    moltiplicatori(); //chiamo la funzione per la generazione dei moltiplicatori


}


void generazione_scrabble ()
{


///Utilizzo le frequenze direttaemente importate da Scrabble per aumentare la giocabilita'

    int b,flag,i,j,cont1=0,cont2=0,random,num=0,x,aux;
    globale.contatore = calloc (N, sizeof(int));
    srand(time(NULL));


    for(i=0; i<N; i++)  globale.lettere[i]=97+i;

    int letterescra[N]= {1174,92,450,373,1179,95,164,154,1128,0,0,651,251,688,983,305,51,637,498,562,301,210,0,0,0,49}; //creo un array contenente le
    //frequenze preseda wikipedia.org
    for (i=0; i<N; i++)
    {
        globale.contatore[i]=letterescra[i]; //le trasferisco nella struct per la generazione della matrice
        num=num+letterescra[i]; //e le sommo
    }
    for(i=0; i<N; i++)
    {
        for(j=i+1; j<N; j++)
        {
            if(globale.contatore[i]>globale.contatore[j])
            {
                //Ordino le lettere in base al conteggio
                b=globale.lettere[i];
                globale.lettere[i]=globale.lettere[j];
                globale.lettere[j]=b;

                //Ordino le più frequenti
                flag=globale.contatore[i];
                globale.contatore[i]=globale.contatore[j];
                globale.contatore[j]=flag;
            }
        }
    }

    for(i=0; i<LATO; i++)
    {
        for(j=0; j<LATO; j++)
        {
            cont1=0;
            cont2=globale.contatore[0];
            random =(rand()%(num));
            for(x=0; x<26; x++)
            {

                if(cont2>=random && random>=cont1)
                {

                    pulsanti[i][j]->lettera=globale.lettere[x];
                    pulsanti[i][j]->valore=valore_lettera(x);

                    break;
                }
                else
                {

                    aux=cont2;
                    cont2+=globale.contatore[x+1];
                    cont1=aux;



                }
            }
            printf("%d....%c...%d\t",random, pulsanti[i][j]->lettera,pulsanti[i][j]->valore);

        }
        printf("\n");
    }
    moltiplicatori();

}

int valore_lettera(int lettera)
{
///Questa funzione si occupa di leggere la posizione nella quale è stata posizionata una lettera(poste in ordine di frequenza) e determinarne il valore
///se la lettera è tra le prime 6 ha valore 8, tra successive 6 ha valore 4, poi tra le successive 7 vale 2, e infine le ultime 7 valgono 1.
///lettera è la posizione della lettera e dev essere tra 0 e 25
///la funzione ritorna il suo valore
    if (lettera<6) return 8;
    if (lettera<12) return 4;
    if (lettera<19) return 2;
    if (lettera<26) return 1;

}

void moltiplicatori()
{
///questa funzione si occupa di generare i moltiplicatori presenti sui pulsanti della matrice
    int i,j,n;
    srand(time(NULL));

    for (i=0; i<4; i++)for (j=0; j<4; j++)
        {

            pulsanti[i][j]->moltiplicatore_lettera=1; //imposto i moltiplicatori di default a 1

            pulsanti[i][j]->moltiplicatore_parola=1;

            n=rand()%16; //genero un numero da 0 a 15
            if (n==1) pulsanti [i][j] -> moltiplicatore_lettera=2;

            if (n==2) pulsanti [i][j] -> moltiplicatore_lettera=3;

            if (n==3) pulsanti [i][j] -> moltiplicatore_parola=2;

            if (n==4) pulsanti [i][j] -> moltiplicatore_parola=3;

        }


}

