#include <stdio.h>
#include <gtk/gtk.h>

int main(int argc, char *argv[]) {
	// launch GUI
	GtkBuilder *builder;
	GtkWidget *window;

	gtk_init(&argc, &argv);

	builder = gtk_builder_new();
	gtk_builder_add_from_file(builder, "../res/login.glade", NULL);

	window = GTK_WIDGET(gtk_builder_get_object(builder, "window_login"));
	gtk_builder_connect_signals(builder, NULL);

	g_object_unref(builder);

	gtk_window_show(window);
	gtk_main();

	
	// Connect To Database
	

	return 0;
}

void on_window_main_destroy() {
	gtk_main_quit();
}
