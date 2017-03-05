#include <gtk/gtk.h>

void button_login_button_press_event(GtkWidget *widget, gpointer data) {
	g_print("login clicked\n");
}

void button_cancel_button_press_event(GtkWidget *widget, gpointer data) {
	g_print("cancel clicked\n");
}

void on_window_login_destroy() {
	gtk_main_quit();
}

int main(int argc, char *argv[]) {
	// launch GUI
	GtkBuilder *builder;
	GtkWidget *window;
	GtkWidget *buttonLogin;
	gtk_init(&argc, &argv);

	builder = gtk_builder_new();
	gtk_builder_add_from_file(builder, "../res/login.glade", NULL);

	window = GTK_WIDGET(gtk_builder_get_object(builder, "window_login"));
	buttonLogin = GTK_WIDGET(gtk_builder_get_object(builder, "button_login"));
	gtk_builder_connect_signals(builder, NULL);

	g_object_unref(builder);

	gtk_widget_show(window);
	gtk_main();

	
	// Connect To Database
	

	return 0;
}

