/** Questa libreria contiene tutte le funzione che chiamano le interfaccie che non vengono direttamente coinvolte nello svolgimento del gioco, ma sono
    necessarie per le funzioni secodarie dell'applicazioni, di cui abbiamo: il menu, un interfaccia per personalizzare la partita, l'interfaccia dove
    viene chiesto il nome del giocatore che abbia fatto un record, e l'intergaccia che stampa la lista dei punteggi migliori.
**/

void menu ()
{
///Questa funzione si occupa di visualizzare il menu principale, è da qui che l'intero programma ha inizio, ed è la singola funzione richiamata dal main.
///E' da qui che parte la chiamata a tutte le funzioni e le operazioni svolte dal programma.
    GtkWindow *finestra_menu; //la finestra del menu
    GtkVBox *vbox; //la vbox dove vengono inseriti tutti gli elementi
    GtkButton *pulsante_gioca; //il pulsante per far partire subito la partita
    GtkButton *pulsante_personalizza; //il pulsante per la partita personalizzata
    GtkButton *pulsante_esci; //il pulsante per l'uscita


    finestra_menu=gtk_window_new(GTK_WINDOW_TOPLEVEL); //genero la finestra
    gtk_window_set_title (finestra_menu,"chinazzle"); //le do il nome
    gtk_window_set_position (finestra_menu,GTK_WIN_POS_CENTER); //ne definisco la posizione
    gtk_window_set_default_size(finestra_menu,329,473); //la dimensione
    g_signal_connect(finestra_menu,"destroy",gtk_main_quit,NULL); //dichiaro che se la finestra dovesse essere distrutta anche l'intero prpogramma dovrebbe
    //fermarsi

    vbox=gtk_vbox_new (TRUE,50); //creo la vbox
    gtk_container_add(GTK_CONTAINER(finestra_menu),vbox); //e la inserisco nella finestra

    pulsante_gioca=gtk_button_new_with_label("Gioca ora!");//creo il pulsante per far partire la partita
    gtk_box_pack_start(GTK_BOX(vbox),pulsante_gioca,FALSE,FALSE,0); //lo inserisco nella vbox
    gtk_widget_set_usize(pulsante_gioca,47,47);//e ne decido la dimensione


    pulsante_personalizza=gtk_button_new_with_label("partita personalizzata"); //creo il pulsante per la personalizzazione della partita
    gtk_box_pack_start(GTK_BOX(vbox),pulsante_personalizza,FALSE,FALSE,0); //lo inserisco nella vbox
    gtk_widget_set_usize(pulsante_personalizza,47,47);//e ne stabilisco la dimensione

    pulsante_esci=gtk_button_new_with_label("Uscita");// creo il pulsante per l'uscita dal programma
    gtk_box_pack_start(GTK_BOX(vbox),pulsante_esci,FALSE,FALSE,0); //lo inserisco nella vbox
    gtk_widget_set_usize(pulsante_esci,47,47);//e ne stabilisco la dimensione


    //connetto i pulsanti alle rispettive funzioni
    g_signal_connect(G_OBJECT(pulsante_gioca),"button_press_event",G_CALLBACK(evento_gioca),NULL);
    g_signal_connect(G_OBJECT(pulsante_personalizza),"button_press_event",G_CALLBACK(evento_personalizza),NULL);
    g_signal_connect(G_OBJECT(pulsante_esci),"button_press_event",gtk_main_quit,NULL);


    gtk_widget_show_all(finestra_menu);




}

void custom()
{
///Questa funzione si occupa di mostrare la finestra per la personalizzazione della partita
    GtkWindow *finestra_personalizza; //la finestra principale
    GtkVBox *vbox; //la vbox dove inserisco tutto
    GtkVBox *boxtempo; //il box dove viene inserito il tempo che deve durare la partita
    GtkVBox *boxmodalita; //il box dove viene selezionata la modalità di partita
    GtkEntry *entry_time; //la entry dove viene inserito il tempo
    GtkLabel *label_time; //la label che gli sta sopra
    GtkRadioButton *radiobutton0; //i due radiobutton che servono per la selezione della modalità
    GtkRadioButton *radiobutton1;
    GtkButton *playbutton; //il pulsante gioca
    GtkHBox *hbox; //un hbox ausiliario per la posizione del playbutton

    char *str; //una stringa ausiliaria


    finestra_personalizza=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (finestra_personalizza,"chinazzle");

    gtk_window_set_position (finestra_personalizza,GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(finestra_personalizza,329,473);
    g_signal_connect(finestra_personalizza,"destroy",gtk_main_quit,NULL);

    vbox=gtk_vbox_new (TRUE,50);
    gtk_container_add(GTK_CONTAINER(finestra_personalizza),vbox);

    boxtempo=gtk_vbox_new (FALSE,50);
    boxmodalita=gtk_vbox_new (TRUE,50);

    label_time=gtk_label_new("Imposta il tempo in secondi");
    entry_time=gtk_entry_new(); //creo la entry che riceve in input il tempo che deve durare la partita
    gtk_entry_set_text(GTK_ENTRY(entry_time),"120"); //e ne imposto il testo di default

    str = gtk_entry_get_text(GTK_ENTRY(entry_time)); //imposto la stringa nella quale deve essere inserito il testo
    sscanf(str,"%d",&cronometro); //e casto il tipo in modo da renderlo intero

    //creo i radiobutton per selezionare il tipo di partita
    radiobutton0=gtk_radio_button_new_with_label(NULL,"Utilizza la frequenza dal dizionario(predefinita)");
    radiobutton1=gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(radiobutton0),"Utilizza le frequenze di scrabble (consigliata)");

    hbox=gtk_hbox_new (TRUE,50);

    playbutton=gtk_button_new_with_label("Gioca!");

    //imposto quali widget devono essere contenuti nelle varie box
    gtk_container_add(GTK_CONTAINER(vbox),boxtempo);
    gtk_container_add(GTK_CONTAINER(vbox),boxmodalita);

    gtk_container_add(GTK_CONTAINER(boxtempo),label_time);
    gtk_container_add(GTK_CONTAINER(boxtempo),entry_time);

    gtk_container_add(GTK_CONTAINER(boxmodalita),radiobutton0);
    gtk_container_add(GTK_CONTAINER(boxmodalita),radiobutton1);

    gtk_container_add(GTK_CONTAINER(boxmodalita),hbox);


    gtk_container_add(GTK_CONTAINER(hbox),playbutton);

    //e i segnali che devono essere associati ai vari pulsanti
    g_signal_connect(G_OBJECT(playbutton),"button_press_event",G_CALLBACK(evento_custom),finestra_personalizza);

    g_signal_connect(G_OBJECT(entry_time),"changed",G_CALLBACK(evento_tempo),entry_time);

    g_signal_connect(G_OBJECT(radiobutton0),"toggled",G_CALLBACK(evento_toggle0),NULL);
    g_signal_connect(G_OBJECT(radiobutton1),"toggled",G_CALLBACK(evento_toggle1),NULL);


    gtk_widget_show_all(finestra_personalizza);

}

void interfaccia_punteggi()
{
///Questa funzione si occupa di visualizzare la lista dei record fatti dai vari giocatori che hanno giocato

    while (gtk_events_pending ())
        gtk_main_iteration ();//attendo che le varie funzioni gtk vengano svolte in modo che il programma non crashi

    GtkWindow *finestra_lista;
    GtkVBox *vbox;
    GtkTreeView *tree_view;
    GtkListStore *list_store; //puntatore alla lista
    GtkTreeViewColumn *column;  //puntatore delle colonne
    GtkTreeIter iter;//iter per la visualizzazione delle liste
    FILE *fp;
    Record *cache; //struttura di tipo record per la memorizzazione temporanea dei punteggi
    int n;

    cache = (Record*)calloc(sizeof(Record),1); //alloco dinamicamente la struttura cache

    fp=fopen("record.txt","r"); //apro il file dove vengono letti i record

    finestra_lista=gtk_window_new(GTK_WINDOW_TOPLEVEL); //creo la finestra dove verrà visualizzata la lista dei punteggi migliori
    gtk_window_set_title (finestra_lista,"chinazzle");
    gtk_window_set_position (finestra_lista,GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(finestra_lista,329,473);
    g_signal_connect(finestra_lista,"destroy",gtk_main_quit,NULL);

    vbox=gtk_vbox_new(TRUE,50);
    list_store=gtk_list_store_new(3,G_TYPE_INT,GTK_TYPE_STRING,GTK_TYPE_INT); //creo la lista delle visualizzazioni
    tree_view=gtk_tree_view_new_with_model(GTK_TREE_MODEL(list_store)); //creo l'albero per la visita delle colonne

    column=gtk_tree_view_column_new_with_attributes("N.",gtk_cell_renderer_text_new(),"text",0,NULL); //creo una colonna che visualiza la posizione del giocatore
    gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view),column);

    column=gtk_tree_view_column_new_with_attributes("Nome",gtk_cell_renderer_text_new(),"text",1,NULL); //una che visualizza il nome del giocatore
    gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view),column);

    column=gtk_tree_view_column_new_with_attributes("Punteggio",gtk_cell_renderer_text_new(),"text",2,NULL);//una che ne visualizza il punteggio
    gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view),column);



    for (n=0; !feof(fp); n++)
    {
//creo un ciclio for che si occupa di leggere e visualizzare nella lista n su 10 volte le linee del file
        fscanf(fp,"%d",&(cache->pnt)); //prendo il punteggio

        fscanf(fp,";"); //scarto il ';'
        fscanf(fp,"%s",cache->name); //prendo il nome
        fscanf(fp,"\n");//ricevo l'accapo

        gtk_list_store_append(list_store,&iter); //inizializzo la tabella e le righe
        gtk_list_store_set(list_store,&iter,
                           0, n+1,
                           1,cache->name,
                           2,cache->pnt,
                           -1); //inserisco i campi nelle caselle

    }


    gtk_box_pack_start(GTK_BOX(vbox),tree_view,TRUE,TRUE,0); //inserisco la tabella nella vbox

    gtk_container_add(GTK_CONTAINER(finestra_lista),vbox);

    fclose(fp);

    gtk_widget_show_all(finestra_lista);

}

void finestra_punteggio()
{
///Questa funzione si occupa della richesta del nome utente che ha ottenuto un nuovo record
    GtkWindow *finestra_nome;
    GtkVBox *vbox;
    GtkLabel *label;
    GtkEntry *entry;
    GtkButton *button;


    finestra_nome=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (finestra_nome,"chinazzle");

    gtk_window_set_position (finestra_nome,GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(finestra_nome,329,473);
    g_signal_connect(finestra_nome,"destroy",gtk_main_quit,NULL);


    vbox=gtk_vbox_new (FALSE,50);

    label=gtk_label_new("Inserisci il tuo nome");
    entry=gtk_entry_new(); //creo la label che richiede la stringa che contiene il nome dell'utente

    button=gtk_button_new_with_label("Salva"); //creo il pulsante che si occupa dell'invio del nome utente
    g_signal_connect(G_OBJECT(button),"button_press_event",G_CALLBACK(salva_punteggio),finestra_nome); //lo connetto al segnale che si occupa di chiamare
    //la funzione per salvare il punteggio

    g_signal_connect(G_OBJECT(entry),"changed",G_CALLBACK(evento_nome),NULL); //questo segnale si occupa di leggere la stringa presente nella entry


    nome= gtk_entry_get_text(GTK_ENTRY(entry)); //attribuisco la entry al puntatore di una stringa in modo che venga salvata li
    //salva_punteggio(score,str);
    //inserisco gli elementi nella vbox
    gtk_container_add(GTK_CONTAINER(vbox),label);

    gtk_container_add(GTK_CONTAINER(vbox),entry);

    gtk_container_add(GTK_CONTAINER(vbox),button);

    gtk_container_add(GTK_CONTAINER(finestra_nome),vbox);



    gtk_widget_show_all(finestra_nome);



}
