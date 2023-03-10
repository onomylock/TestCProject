// #ifndef UI_H
// #define Ui_H

#include <gtk-3.0/gtk/gtk.h>
#include "../Calculation/direct.h"

typedef struct UI 
{
	GtkWidget*	main_window;
	GtkBuilder* builder;	
	GtkGLArea*  view2d;
	GtkGLArea*  curve;
	//GtkWidget*  open;
} UI;

extern UI* ui;

void ui_init(void);
void on_exit_app(GtkWidget *window);
void on_file_chooser_file_set(GtkFileChooserButton *fileChooserButton);
void on_button_direct_clicked(GtkWidget *button_direct);
void on_button_inverce_clicked(GtkWidget *button_inverce);
void render_curve(GtkWidget *curve_area);
void resize_curve(GtkWidget *curve_area);
void draw_curve(GtkWidget *curve_area);
void render_view2d(GtkWidget *view2d_area);
void resize_view2d(GtkWidget *view2d_area);
void draw_view2d(GtkWidget *view2d_area);

//#endif */UI_H*/