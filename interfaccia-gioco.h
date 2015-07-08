/** Questa libreria, contenente una funzione principale, si occupa esclusivamente di caricare l'interfaccia grafica della finestra nella quale il gioco
    stesso viene svolto.
    Vi è inoltre una funzione secondaria che si occupa di assegnare l'immagine dei moltiplicatori al pulsante
**/
void interfaccia_gioco()
{
    GtkWindow *finestra_gioco; //widget finestra
    GtkHBox *hbox; //widget hbox contenuto nella finestra
    GdkBitmap *sfondo_gioco;
    GdkPixbuf *carica_sfondo;
    GtkFixed *fixed; //il fixed contenuto nell'hbox
    GtkStyle  *style;
    GtkEntry *invio_ricerca; //l'evento per l'invio della ricerca

    int i,j;
    char stringa_supporto[2];

#define STARTX      15
#define STARTY      128
#define DISTANCE    77
#define SPACE       10
#define MULTSC      0


    //creo la finestra nella quale si svolger' il gioco
    finestra_gioco=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (finestra_gioco,"chinazzle");
    gtk_window_set_position (finestra_gioco,GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(finestra_gioco,329,473);
    g_signal_connect(finestra_gioco,"destroy",gtk_main_quit,NULL);



    //creo un hbox dove inserire tutti gli elementi
    hbox=gtk_event_box_new ();
    gtk_container_add(GTK_CONTAINER(finestra_gioco),hbox);
    gtk_event_box_set_visible_window (hbox,FALSE);
    gtk_event_box_set_above_child (hbox,FALSE);


    //carico un immagine e' a imposto come nuovo sfono attraverso l'uso degli stili
    carica_sfondo=gdk_pixbuf_new_from_file("img/sfondo.png",NULL);
    gdk_pixbuf_render_pixmap_and_mask (carica_sfondo, &sfondo_gioco, NULL, 0);

    style = gtk_style_new ();
    style->bg_pixmap[0] = sfondo_gioco;
    gtk_widget_set_style (GTK_WIDGET(finestra_gioco), GTK_STYLE(style));


    //creo un fixed per l'inserimento manuale di tutti gli elmenti
    fixed=gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(hbox),fixed);

    stringa_supporto[1]='\0';

    for (i=0; i<LATO; i++) for (j=0; j<LATO; j++)
        {
            //questo ciclo si occupa di ripetere per ogni singolo pulsante (dunque per 16 volte) le seguenti operazioni
            pulsanti[i][j]->evento=gtk_event_box_new(); //creo il pulsante
            gtk_widget_set_usize(pulsanti[i][j]->evento,47,47); //ne determino la dimensione
            gtk_fixed_put(fixed,pulsanti[i][j]->evento,STARTX+i*DISTANCE+10,STARTY+j*DISTANCE+10); //lo posiziono
            gtk_widget_set_events (pulsanti[i][j]->evento, GDK_BUTTON_PRESS_MASK); //setto il tipo d'evento alla quale deve rispondere
            gtk_event_box_set_visible_window (pulsanti[i][j]->evento,FALSE);//rendo il pulsante evento invisibile,
            //                                                              //in modo che non interferisca con l'interfaccia

            pulsanti[i][j]->pulsante=gtk_image_new_from_file("img/pulsante.png"); //carico l'immagine del pulsante
            gtk_fixed_put(fixed,pulsanti[i][j]->pulsante,STARTX+i*DISTANCE,STARTY+j*DISTANCE); //e la posiziono

            lettere[i][j]->img_multiplier=gtk_image_new_from_file("img/white.png"); //carico un immagine trasparente che verrà sostituita
            //dall'moltiplicatore del pulsante
            gtk_fixed_put(fixed,lettere[i][j]->img_multiplier,STARTX+i*DISTANCE-MULTSC,STARTY+j*DISTANCE-MULTSC); //e lo posiziono


            lettere[i][j]->label=gtk_label_new(stringa_supporto); //creo la label dove verrà inserita la lettera corrispndente al pulsante
            sprintf(s,"<span foreground='#333' font_weight='heavy' font='21'><tt>%c</tt></span>",pulsanti[i][j]->lettera); //ne definisco lo stile
            gtk_label_set_markup(lettere[i][j]->label,s); //e lo applico

            gtk_fixed_put(fixed,lettere[i][j]->label,STARTX+i*DISTANCE+22,STARTY+j*DISTANCE+15); //e la posiziono

            gtk_misc_set_alignment ( lettere[i][j]->label , 0, 0.5 ) ; //le metto in posizione centrale

            lettere[i][j]->labvalore=gtk_label_new(stringa_supporto); //creo la label ove verrà inserito il valore corrispondente alla lettera
            sprintf(s,"<span foreground='#333' font='7'><tt>%d</tt></span>",pulsanti[i][j]->valore); //ne definisco lo stile
            gtk_label_set_markup(lettere[i][j]->labvalore,s); //lo applico
            gtk_fixed_put(fixed,lettere[i][j]->labvalore,STARTX+i*DISTANCE+40,STARTY+j*DISTANCE+3); //e lo posiziono

            img_mult(i,j); //assegno la giusta immagine al moltiplicatore del pulsante


        }




    invio_ricerca=gtk_event_box_new(); //creo il pulsante evento per l'invio della parola
    gtk_fixed_put(fixed,invio_ricerca,15,63); //lo posiziono
    gtk_widget_set_usize(invio_ricerca,298,43); //e ne definisco la dimensione
    g_signal_connect(G_OBJECT(invio_ricerca),"button_press_event",G_CALLBACK(evento_ricerca),NULL); //stabilisco a che tipo di segnale deve essere associato
//g_signal_connect(G_OBJECT(hbox),"button_press_event",G_CALLBACK(evento_ricerca),NULL);

    gtk_event_box_set_visible_window (invio_ricerca,FALSE); //lo rendo invisibile in modo da non disturbare l'interfaccia
    gtk_event_box_set_above_child (invio_ricerca,FALSE); //e faccio in modo che sia sensibile ache se sovrapposto
    stringa=gtk_label_new("0"); //creo la stringa che visualizza la parola ricercata
    gtk_fixed_put(fixed,stringa ,50,63); //la posiziono

    tempo=gtk_label_new(stringa_supporto); //creo la label del tempo

    if (cronometro%60<10) sprintf(s,"<span foreground='#CEF' font_weight='500' font='14'>%d:0%d</span>",cronometro/60,cronometro%60); //e stampo il tempo in modo
    else sprintf(s,"<span foreground='#CEF' font_weight='500' font='14'>%d:%d</span>",cronometro/60,cronometro%60); //che sia scritto in maniera corretta

    gtk_label_set_markup(tempo,s); //gli imposto il carattere
    gtk_fixed_put(fixed,tempo,36,12); //e lo posiziono

    score=gtk_label_new(stringa_supporto); //creo la label del punteggio
    sprintf(s,"<span foreground='#CEF' font_weight='500' font='14'>0</span>"); //ne definisco lo stile
    gtk_label_set_markup(score,s);
    gtk_fixed_put(fixed,score,160,12); //e la posiziono


    inizializza_eventi(); //inizializzo gli eventi per ogni singolo pulsante

    g_timeout_add(1000,timer_func,finestra_gioco); //imposto un timer asincrono utilizzando le librerie gtk, esso a ogni 1000 ms aggiorna il suo stato
//la funzione timer_func e passandogli in argomento il widget finestra_gioco


    gtk_widget_show_all(finestra_gioco); //mostro tutta la finestra

}

void img_mult(int i,int j)
{
    /** questa funzione si occupa di assegnare l'immagine del moltiplicatore giusta a ogni pulsante
        ha come argomenti i e j, che sono la riga e la colonna del pulsante da controllare
    **/


    if (pulsanti[i][j]->moltiplicatore_lettera==2) gtk_image_set_from_file(GTK_IMAGE(lettere[i][j]->img_multiplier),"img/dl.png");

    if (pulsanti[i][j]->moltiplicatore_lettera==3) gtk_image_set_from_file(GTK_IMAGE(lettere[i][j]->img_multiplier),"img/tl.png");

    if (pulsanti[i][j]->moltiplicatore_parola==2) gtk_image_set_from_file(GTK_IMAGE(lettere[i][j]->img_multiplier),"img/dw.png");

    if (pulsanti[i][j]->moltiplicatore_parola==3) gtk_image_set_from_file(GTK_IMAGE(lettere[i][j]->img_multiplier),"img/tw.png");


}
