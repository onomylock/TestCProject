// #ifndef UI_H
// #define Ui_H

#include <gtk-3.0/gtk/gtk.h>
#include "../Calculation/direct.h"
#include "../Render/graph.h"

typedef struct UI 
{
	GtkWidget*	main_window;
	GtkBuilder* builder;	
	GtkGLArea*  view2d;
	GtkGLArea*  curve;	
} UI;

extern UI* ui;

void ui_init(void);
void on_exit_app();
void on_directory_chooser(GtkFileChooserButton *fileChooserButton);
void on_button_direct_clicked(GtkWidget *button_direct);
void on_button_inverce_clicked(GtkWidget *button_inverce);
//#endif */UI_H*/