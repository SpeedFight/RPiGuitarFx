/*
 * mainGtkView.cpp
 *
 *  Created on: 8 kwi 2018
 *      Author: SF
 */

#include "mainGtkView.hpp"

#define UI_FILE "glade/mainFxWindow.ui"

ViewGtk::ViewGtk(int argc, char * argv[]){
	GtkWidget * okno;

	//gtk_set_locale();
	gtk_init( & argc, & argv );

	okno = buildMainWindow();
	gtk_widget_show( okno );

	gtk_main();
}

GtkWidget *ViewGtk::buildMainWindow(){

    GtkWidget * okno;
    GtkBuilder * builder;
    GError * error = NULL;

    /* Tworzy obiekt buildera */
    builder = gtk_builder_new();
    /* Wczytuje zawartość interfejsu i sprawdza ewentualne błędy */
    if( !gtk_builder_add_from_file( builder, UI_FILE, & error ) )
    {
        g_warning( "Nie można wczytać plilu buildera: %s", error->message );
        g_error_free( error );
    }

    /* Łączy sygnały zawarte w pliku interfejsu z odpowiednimi funkcjami */
    gtk_builder_connect_signals( builder, NULL );

    /* Pobiera obiekt z nazwą "window1" */
    okno = GTK_WIDGET( gtk_builder_get_object( builder, "MainFxWindow" ) );

//    informacje.reset(new InfoLabels(builder));

    /* Obiekt buildera nie będzie już nam potrzebny, więc go "zwalniamy" */
    g_object_unref( builder );

    return okno;

}


