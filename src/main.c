#include <gtk/gtk.h>
#include "View/ui.h"

int main (int argc, char **argv) 
{
	gtk_init(&argc, &argv);
	ui_init();
	gtk_main();
}
