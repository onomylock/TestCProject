#include <glad/glad.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *vertexShader = 
"#version 460"
"layout(location = 0) in vec3 vertex_position;"
"out vec4 vertex_color;"
"void main()"
"{"
   "gl_Position = vec4(vertex_position, 1.0);"
   "vertex_color = vec4(0.5, 0.0, 0.0, 1.0);"
"}";

const char *fragmentShader = 
"#version 460"
"out vec4 frag_color;"
"uniform vec4 ourColor;"
"void main()"
"{"   
   "frag_color = ourColor;"
"}";

// typedef struct
// {
//     char *vertexShaderPath;
//     char *fragmentShaderPath;
//     char *vertexShader;
//     char *fragmentShader;
// } shader_info;

void compile_shader(GLuint *shaderID, GLenum shaderType, const char* shaderFilePath);
void link_shader(GLuint vertexShaderID, GLuint fragmentShaderID);
void create_shader(char *source, const GLenum shaderType, GLuint shaderID);
char* get_shader_content(const char* fileName);
void use_shaders();
