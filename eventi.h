void evento_gioca ()
{
///Questa funzione si occupa di ricervere il segnale di inizio partita, e a seconda della modalita scelta fa generare la matrice.

    if (toggle==0)generazione_matrix(); //richiamo la funzione per generare la matrice basandomi sul dizionario
    else generazione_scrabble(); //richiamo la funzione per generare la matrice basandomi sulle tavole crittografiche

    interfaccia_gioco(); //faccio partire il gioco e con esso la sua interfaccia
}

void evento_custom (GtkWidget *window)
{
///Questa funzione si occupa sostanzialmente di nascondere la finestra precedente e richiamare la funzione per iniziare il gioco
    gtk_widget_hide(window);
    evento_gioca();

}

void evento_personalizza ()
{
///Questo segnale serve a far selezionare la partita personalizzata
    custom();
}

void evento_tempo (GtkWidget *entry)
{
///Questa funzione si occupa di prendere in input il contenuto della entry e trasferirlo nella variabile cronometro
    char *str;
    str=(char*)gtk_entry_get_text(GTK_ENTRY(entry)); //trasferisco il contenuto della entry nella str
    sscanf (str,"%d",&cronometro); //cambio il tipo da stringa a intero

}

void evento_nome (GtkWidget *entry)
{
///Questa funzione si occupa di ricevere il segnale changed e di prendere il contenuto della entry
    nome=(char*)gtk_entry_get_text(GTK_ENTRY(entry));

}


void evento_toggle0 ()
{
///Questa funzione si occupa di cambiare la variabile toggle che si occupa di determinare quale tipo di partita è stata scelta
    toggle=0;
}

void evento_toggle1 ()
{
///idem come sopra
    toggle=1;

}

///Questa serie di 16 funzioni, una per ogni pulsante, si occupa di far attivare un evento a seconda del pulsante premuto, in sostanza aquista la lettera
///e i suoi moltiplicatori, e poi gestisce i pulsanti, in modo che ad esempio vengano evidenziati e non diventino ripremibili

void button_clicked00(GtkWidget *widget, GdkEvent *event)
{


    aquista_lettera(pulsanti[0][0]->lettera,pulsanti[0][0]->valore*pulsanti[0][0]->moltiplicatore_lettera,pulsanti[0][0]->moltiplicatore_parola);
    gestione_pulsanti(widget,0,0);
}

void button_clicked01(GtkWidget *widget, GdkEvent *event)
{


    aquista_lettera(pulsanti[0][1]->lettera,pulsanti[0][1]->valore*pulsanti[0][1]->moltiplicatore_lettera,pulsanti[0][1]->moltiplicatore_parola);
    gestione_pulsanti(widget,0,1);
}

void button_clicked02(GtkWidget *widget, GdkEvent *event)
{

    aquista_lettera(pulsanti[0][2]->lettera,pulsanti[0][2]->valore*pulsanti[0][2]->moltiplicatore_lettera,pulsanti[0][2]->moltiplicatore_parola);
    gestione_pulsanti(widget,0,2);

}
void button_clicked03(GtkWidget *widget, GdkEvent *event)
{

    aquista_lettera(pulsanti[0][3]->lettera,pulsanti[0][3]->valore*pulsanti[0][3]->moltiplicatore_lettera,pulsanti[0][3]->moltiplicatore_parola);
    gestione_pulsanti(widget,0,3);
}

void button_clicked10(GtkWidget *widget, GdkEvent *event)
{

    aquista_lettera(pulsanti[1][0]->lettera,pulsanti[1][0]->valore*pulsanti[1][0]->moltiplicatore_lettera,pulsanti[1][0]->moltiplicatore_parola);
    gestione_pulsanti(widget,1,0);
}
void button_clicked11(GtkWidget *widget, GdkEvent *event)
{

    aquista_lettera(pulsanti[1][1]->lettera,pulsanti[1][1]->valore*pulsanti[1][1]->moltiplicatore_lettera,pulsanti[1][1]->moltiplicatore_parola);
    gestione_pulsanti(widget,1,1);
}
void button_clicked12(GtkWidget *widget, GdkEvent *event)
{

    aquista_lettera(pulsanti[1][2]->lettera,pulsanti[1][2]->valore*pulsanti[1][2]->moltiplicatore_lettera,pulsanti[1][2]->moltiplicatore_parola);
    gestione_pulsanti(widget,1,2);
}
void button_clicked13(GtkWidget *widget, GdkEvent *event)
{

    aquista_lettera(pulsanti[1][3]->lettera,pulsanti[1][3]->valore*pulsanti[1][3]->moltiplicatore_lettera,pulsanti[1][3]->moltiplicatore_parola);
    gestione_pulsanti(widget,1,3);
}
void button_clicked20(GtkWidget *widget, GdkEvent *event)
{

    aquista_lettera(pulsanti[2][0]->lettera,pulsanti[2][0]->valore*pulsanti[2][0]->moltiplicatore_lettera,pulsanti[2][0]->moltiplicatore_parola);
    gestione_pulsanti(widget,2,0);
}
void button_clicked21(GtkWidget *widget, GdkEvent *event)
{


    aquista_lettera(pulsanti[2][1]->lettera,pulsanti[2][1]->valore*pulsanti[2][1]->moltiplicatore_lettera,pulsanti[2][1]->moltiplicatore_parola);
    gestione_pulsanti(widget,2,1);
}
void button_clicked22(GtkWidget *widget, GdkEvent *event)
{

    aquista_lettera(pulsanti[2][2]->lettera,pulsanti[2][2]->valore*pulsanti[2][2]->moltiplicatore_lettera,pulsanti[2][2]->moltiplicatore_parola);
    gestione_pulsanti(widget,2,2);
}
void button_clicked23(GtkWidget *widget, GdkEvent *event)
{

    aquista_lettera(pulsanti[2][3]->lettera,pulsanti[2][3]->valore*pulsanti[2][3]->moltiplicatore_lettera,pulsanti[2][3]->moltiplicatore_parola);
    gestione_pulsanti(widget,2,3);
}
void button_clicked30(GtkWidget *widget, GdkEvent *event)
{

    aquista_lettera(pulsanti[3][0]->lettera,pulsanti[3][0]->valore*pulsanti[3][0]->moltiplicatore_lettera,pulsanti[3][0]->moltiplicatore_parola);
    gestione_pulsanti(widget,3,0);
}
void button_clicked31(GtkWidget *widget, GdkEvent *event)
{

    aquista_lettera(pulsanti[3][1]->lettera,pulsanti[3][1]->valore*pulsanti[3][1]->moltiplicatore_lettera,pulsanti[3][1]->moltiplicatore_parola);
    gestione_pulsanti(widget,3,1);
}
void button_clicked32(GtkWidget *widget, GdkEvent *event)
{


    aquista_lettera(pulsanti[3][2]->lettera,pulsanti[3][2]->valore*pulsanti[3][2]->moltiplicatore_lettera,pulsanti[3][2]->moltiplicatore_parola);
    gestione_pulsanti(widget,3,2);
}
void button_clicked33(GtkWidget *widget, GdkEvent *event)
{

    aquista_lettera(pulsanti[3][3]->lettera,pulsanti[3][3]->valore*pulsanti[3][3]->moltiplicatore_lettera,pulsanti[3][3]->moltiplicatore_parola);
    gestione_pulsanti(widget,3,3);
}


void evento_ricerca(GtkWidget *widget,GdkEvent *event)
{
///Questa funzione si occupa di far partire l'evento della ricerca binaria
    int i;
    FILE *voc=NULL;
    voc=fopen("data.txt", "r");

    ricerca_binaria(stringa_ricerca,0); //faccio partire la ricerca binaria
    for (i=0; i<16; i++)
    {
        //questo ciclo si occupa di far si che tutti i pulsanti che sono stati premuti ritornino allo stato originale in modo da poter essere riutilizzati
        stringa_ricerca[i]='\0';
        pulsanti[i/4][i%4]->premuto=0;
        gtk_widget_set_sensitive(pulsanti[i/4][i%4]->evento,TRUE);
        gtk_image_set_from_file(pulsanti[i/4][i%4]->pulsante,"img/pulsante.png");
    }


}

void gestione_pulsanti(GtkWidget *widget,int x,int y)
{
///Questa funzione si occupa della gestione dei pulsanti, prende in input i valori dei pulsanti e il puntatore al loro widget
    int i,j;
    pulsanti[x][y]->premuto=1; //fa si che il pulsanti xy venga considerato come premuto
    gtk_image_set_from_file(pulsanti[x][y]->pulsante,"img/illuminato.png"); //ne cambia l'immagine
    for (i=0; i<4; i++) for (j=0; j<4; j++)
        {

            if ((((i<=x+1)&&(i>=x-1))&&((j<=y+1)&&(j>=y-1))))
            {
                gtk_widget_set_sensitive(pulsanti[i][j]->evento,TRUE); //e con questo ciclo fa in modo che tutti i pulsanti adiacenti vengano resi come premibili
            }
            else
            {
                gtk_widget_set_sensitive(pulsanti[i][j]->evento,FALSE); //altrimenti non possono essere premuti
            }
            if (pulsanti[i][j]->premuto==1) gtk_widget_set_sensitive(pulsanti[i][j]->evento,FALSE); //inoltre fa in modo che se un pulsante è gia stato premuto
            //non possa esserlo per una seconda volta
        }
    sprintf(s,"<span background='#FFAB00' font_weight='500' font='14'>%s</span>",stringa_ricerca); //cambia la stringa di ricerca
    gtk_label_set_markup(stringa,s); //e ne inserisce lo stile
}

void inizializza_eventi ()
{

///Questa funzione richiama i segnali di ogni singolo pulsante, l'ho utilizzata solamente per pulire un po il codice

    g_signal_connect(G_OBJECT(pulsanti[0][0]->evento),"button_press_event",G_CALLBACK(button_clicked00),NULL);
    g_signal_connect(G_OBJECT(pulsanti[0][1]->evento),"button_press_event",G_CALLBACK(button_clicked01),NULL);
    g_signal_connect(G_OBJECT(pulsanti[0][2]->evento),"button_press_event",G_CALLBACK(button_clicked02),NULL);
    g_signal_connect(G_OBJECT(pulsanti[0][3]->evento),"button_press_event",G_CALLBACK(button_clicked03),NULL);

    g_signal_connect(G_OBJECT(pulsanti[1][0]->evento),"button_press_event",G_CALLBACK(button_clicked10),NULL);
    g_signal_connect(G_OBJECT(pulsanti[1][1]->evento),"button_press_event",G_CALLBACK(button_clicked11),NULL);
    g_signal_connect(G_OBJECT(pulsanti[1][2]->evento),"button_press_event",G_CALLBACK(button_clicked12),NULL);
    g_signal_connect(G_OBJECT(pulsanti[1][3]->evento),"button_press_event",G_CALLBACK(button_clicked13),NULL);

    g_signal_connect(G_OBJECT(pulsanti[2][0]->evento),"button_press_event",G_CALLBACK(button_clicked20),NULL);
    g_signal_connect(G_OBJECT(pulsanti[2][1]->evento),"button_press_event",G_CALLBACK(button_clicked21),NULL);
    g_signal_connect(G_OBJECT(pulsanti[2][2]->evento),"button_press_event",G_CALLBACK(button_clicked22),NULL);
    g_signal_connect(G_OBJECT(pulsanti[2][3]->evento),"button_press_event",G_CALLBACK(button_clicked23),NULL);

    g_signal_connect(G_OBJECT(pulsanti[3][0]->evento),"button_press_event",G_CALLBACK(button_clicked30),NULL);
    g_signal_connect(G_OBJECT(pulsanti[3][1]->evento),"button_press_event",G_CALLBACK(button_clicked31),NULL);
    g_signal_connect(G_OBJECT(pulsanti[3][2]->evento),"button_press_event",G_CALLBACK(button_clicked32),NULL);
    g_signal_connect(G_OBJECT(pulsanti[3][3]->evento),"button_press_event",G_CALLBACK(button_clicked33),NULL);


}

void fine_partita(GtkWidget* finestra_gioco)
{

///Questa funzione determina la fine della partita e viene richiamata quando il timer è terminato

    gtk_widget_hide(finestra_gioco); //distrugge la finestra del gioco
    verifica(); //verifica quali parole non sono state trovate dal giocatore

    verifica_punteggio(punteggio); //e verifica che il punteggio sia stato uno tra i record


}



GSourceFunc timer_func (GtkWidget* finestra_gioco)
{

///Questa funzione viene richiamata dal timer ogni volta che passano 1000 ms (un secondo) e si occupa di diminuire di uno la variabile cronometro
///e di aggiornare il timer dell'interfaccia
    if (cronometro!=0)
    {
        cronometro--;
        if (cronometro%60<10) sprintf(s,"<span foreground='#CEF' font_weight='500' font='14'>%d:0%d</span>",cronometro/60,cronometro%60);
        else sprintf(s,"<span foreground='#CEF' font_weight='500' font='14'>%d:%d</span>",cronometro/60,cronometro%60);

        gtk_label_set_markup(tempo,s);

        return 1;
    }
    else
    {
        fine_partita(finestra_gioco);
        return 0;
    }

}


