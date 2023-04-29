#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <epoxy/gl.h>
//#include <glad/glad.h>
#include <glib.h>

//shaders
// const char *vertexShader = 
// "#version 460"
// "layout(location = 0) in vec3 vertex_position;"
// "out vec4 vertex_color;"
// "void main()"
// "{"
//    "gl_Position = vec4(vertex_position, 1.0);"
//    "vertex_color = vec4(0.5, 0.0, 0.0, 1.0);"
// "}";

// const char *fragmentShader = 
// "#version 460"
// "out vec4 frag_color;"
// "uniform vec4 ourColor;"
// "void main()"
// "{"   
//    "frag_color = ourColor;"
// "}";

// void compile_shader(GLuint *shaderID, GLenum shaderType, const char* shaderFilePath);
// void link_shader(GLuint vertexShaderID, GLuint fragmentShaderID);
// void create_shader(char *source, const GLenum shaderType, GLuint shaderID);
// char* get_shader_content(const char* fileName);
// void use_shaders();
//end shaders

//grapth
typedef struct point 
{
	GLfloat x;
	GLfloat y;
} Point;


void resize_curve(GtkGLArea* gl_area, int width, int height);
void realize_curve(GtkGLArea* gl_area);
gboolean render_curve(GtkGLArea* gl_area, GdkGLContext* gl_context);

void resize_view2d(GtkGLArea* gl_area, int width, int height);
void realize_view2d(GtkGLArea* gl_area);
gboolean render_view2d(GtkGLArea* gl_area, GdkGLContext* gl_context);
//end grapth


//ui
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
//end ui

//direct
typedef enum FileType
{
    CELLS,
    RECEIVERS,
    OUTPUT
} FileType;

typedef struct Cell
{
    double I;
    Point *Center;
    Point *P;
    Point *nodes[2];    

} Cell;

typedef struct Receiver
{
    Point *B;
    Point *Point;
} Receiver;

typedef struct Direct
{
    int N, K;
    Cell *cellObjects;
    Receiver *receivers;
    char *fileName;
} Direct;

extern Direct* direct_calc;

int load(const char* fileName, enum FileType fileType);
int save(const char* fileName, enum FileType fileType);
int calculate();
double get_r(Cell cell, Receiver receiver);
double get_cell_area(Cell cell);
//end direct
