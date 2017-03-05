#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>


GtkBuilder *builder;

// Global Variables for all Widgets on the Gtk login GUI
GtkWidget *windowLogin;
GtkWidget *buttonLogin;
GtkWidget *buttonCancel;
GtkEntry *entryUsername;
GtkEntry *entryPassword;
GtkWidget *labelWarningUsername;
GtkWidget *labelWarningPassword;

// Global Variables for all Widgets on the Gtk Main GUI

void setLoginWidgets() {
	windowLogin = GTK_WIDGET(gtk_builder_get_object(builder, "window_login"));
	buttonLogin = GTK_WIDGET(gtk_builder_get_object(builder, "button_login"));
	buttonCancel = GTK_WIDGET(gtk_builder_get_object(builder, "button_cancel"));
	entryUsername = GTK_ENTRY(gtk_builder_get_object(builder, "entry_username"));
	entryPassword = GTK_ENTRY(gtk_builder_get_object(builder, "entry_password"));
	labelWarningUsername = GTK_WIDGET(gtk_builder_get_object(builder, 
				"label_warning_username"));
	labelWarningPassword = GTK_WIDGET(gtk_builder_get_object(builder, 
				"label_warning_password"));
}

/*
 *	Button actions for login GUI
 *		- Login button verifies all textfields are not empty
 *		Gives user feedback if requirements aren't met
 *		- Cancel Button shuts down the program with the value 0
 */

void button_login_button_press_event(GtkWidget *widget, gpointer data) {
	if(strcmp(gtk_entry_get_text(entryUsername), "") == 0) {
		gtk_widget_show(labelWarningUsername);
	}

	if(strcmp(gtk_entry_get_text(entryUsername), "") == 0) {
		gtk_widget_show(labelWarningPassword);
	}
}

void button_cancel_button_press_event(GtkWidget *widget, gpointer data) {
	exit(0);
}

void on_window_login_destroy() {
	gtk_main_quit();
}

int main(int argc, char *argv[]) {
	// launch GUI
	gtk_init(&argc, &argv);

	builder = gtk_builder_new();
	gtk_builder_add_from_file(builder, "../res/login.glade", NULL);

	setLoginWidgets();

	gtk_builder_connect_signals(builder, NULL);

	/*
	Commented out because of unwanted side effect of not allowing editing of a launched GUI
	g_object_unref(builder);
	
	*/
	gtk_widget_show(windowLogin);
	gtk_main();

	
	// Connect To Database
	

	return 0;
}

