
void aquista_lettera (char lettera,int valore,int molt);
int next_bin(int indice,FILE *fp);
int forward_bin(int indice,FILE *fp);
void leggi(char *word,FILE *fp);
void pulisci_stringa (char *word);
int file_size(FILE *fp);
void ricerca_binaria (char word[17],int select);

void salva_punteggio (GtkWidget *exwindow);
void verifica_punteggio (int pnt);
void generazione_matrix();
void generazione_scrabble ();
int valore_lettera(int lettera);
void moltiplicatori();

void verifica ();
void trova_parole(int i,int j, int premuti[16],char *cerca);

void interfaccia_gioco();
void menu ();
void custom();
void interfaccia_punteggi();
void finestra_punteggio();

void evento_gioca ();
void evento_custom (GtkWidget *window);
void evento_personalizza ();
void evento_tempo (GtkWidget *entry);
void evento_nome (GtkWidget *entry);
void evento_toggle0 ();
void evento_toggle1 ();
void button_clicked00(GtkWidget *widget, GdkEvent *event);
void button_clicked01(GtkWidget *widget, GdkEvent *event);
void button_clicked02(GtkWidget *widget, GdkEvent *event);
void button_clicked03(GtkWidget *widget, GdkEvent *event);
void button_clicked10(GtkWidget *widget, GdkEvent *event);
void button_clicked11(GtkWidget *widget, GdkEvent *event);
void button_clicked12(GtkWidget *widget, GdkEvent *event);
void button_clicked13(GtkWidget *widget, GdkEvent *event);
void button_clicked20(GtkWidget *widget, GdkEvent *event);
void button_clicked21(GtkWidget *widget, GdkEvent *event);
void button_clicked22(GtkWidget *widget, GdkEvent *event);
void button_clicked23(GtkWidget *widget, GdkEvent *event);
void button_clicked30(GtkWidget *widget, GdkEvent *event);
void button_clicked31(GtkWidget *widget, GdkEvent *event);
void button_clicked32(GtkWidget *widget, GdkEvent *event);
void button_clicked33(GtkWidget *widget, GdkEvent *event);
void evento_ricerca(GtkWidget *widget,GdkEvent *event);
void gestione_pulsanti(GtkWidget *widget,int x,int y);
void inizializza_eventi ();
void fine_partita(GtkWidget* finestra_gioco);
GSourceFunc timer_func (GtkWidget* finestra_gioco);

void inserisci(list_pointer *ptr,char word[17]);
int visita (list_pointer ptr,char word[17]);

void img_mult(int i,int j);
void interfaccia_gioco() ;



