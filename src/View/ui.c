#include "ui.h"
#include <gtk-3.0/gtk/gtk.h>

//#include "graph.h"

static UI _ui;
UI* ui = &_ui;

void ui_init()
{
	GError *err = NULL;

	ui->builder = gtk_builder_new();

	if(!gtk_builder_add_from_file(ui->builder, "glade/MainWindow.glade", &err))
	{
		g_critical("don't load .glade file : %s", err->message);
		g_error_free(err);
		return;
	}
	
	ui->main_window = GTK_WIDGET(gtk_builder_get_object(ui->builder, "main_window"));
	//ui->open = GTK_WIDGET(gtk_builder_get_object(ui->open, "open"));

	gtk_builder_connect_signals(ui->builder, NULL);
	g_object_unref(G_OBJECT(ui->builder));
	gtk_widget_show_all(ui->main_window);
}

void on_exit_app(GtkWidget *window)
{
	gtk_main_quit();
}

void on_file_chooser_file_set(GtkFileChooserButton *fileChooserButton)
{	
	char *str = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fileChooserButton));
	char *str1 = strstr(str, ".");
	if (str1 == ".cells")
	{		
		load(str, CELLS);
		printf("file name = %s\n", gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fileChooserButton)));
	}
	else if (str1 == ".recivers")
	{		
		load(str, RECEIVERS);
		printf("file name = %s\n", gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fileChooserButton)));
	}	
}

void on_button_direct_clicked(GtkWidget *button_direct)
{
	
}

void on_button_inverce_clicked(GtkWidget *button_inverce)
{
	g_print("Button1 pressed\n");
}

void render_curve(GtkWidget *curve_area)
{

}

void resize_curve(GtkWidget *curve_area)
{

}

void draw_curve(GtkWidget *curve_area)
{
	
}

void render_view2d(GtkWidget *view2d_area)
{

}

void resize_view2d(GtkWidget *view2d_area)
{

}

void draw_view2d(GtkWidget *view2d_area)
{

}
