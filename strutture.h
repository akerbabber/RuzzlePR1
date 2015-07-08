typedef struct
{

    char lettera; //la lettera visualizzata sopra il pulsante, che verrà successivamente inviata alla ricerca binaria
    GtkWidget *pulsante;    //il widget del pulsante
    int valore;         //il valore della lettera, determinato dalla frequenza della lettera nel dizionario
    int moltiplicatore_lettera; //indica se è attivato il bonus moltiplicatore della parola
    int moltiplicatore_parola; //indica se è attivato il bonus moltiplicatore della lettera
    int premuto;    //indica se il bottone e' stato gia' premuto
    GtkWidget *evento;

} Matrice;

typedef struct
{
    int *contatore;  //conta il numero delle letttere nel dizionario
    int lettere[N];


} Parola;

typedef struct
{

    GtkWidget *labvalore;
    GtkWidget *label;
    GtkWidget *img_multiplier;

}  lettera;

typedef struct
{

    int *pnt;
    char name[16];

} Record;

typedef struct list_node *list_pointer;
typedef struct list_node
{

    char key[17];
    list_pointer link;

} lista;
