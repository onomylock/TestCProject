#include "shader_program.h"

char* get_shader_content(const char* fileName)
{
    FILE *fp;
    long size = 0;
    char* shaderContent;
    
    /* Read File to get size */
    fp = fopen(fileName, "rb");
    if(fp == NULL) {
        return "";
    }
    fseek(fp, 0L, SEEK_END);
    size = ftell(fp)+1;
    fclose(fp);

    /* Read File for Content */
    fp = fopen(fileName, "r");
    shaderContent = memset(malloc(size), '\0', size);
    fread(shaderContent, 1, size-1, fp);
    fclose(fp);

    return shaderContent;
}

void compile_shader(GLuint *shaderId, GLenum shaderType, const char* shaderFilePath)
{
    GLint isCompiled = 0;
    /* Calls the Function that loads the Shader source code from a file */
    const char* shaderSource = get_shader_content(shaderFilePath); 

    *shaderId = glCreateShader(shaderType);
    if(*shaderId == 0) 
    {
        printf("COULD NOT LOAD SHADER: %s!\n", shaderFilePath);
    }

    glShaderSource(*shaderId, 1, (const char**)&shaderSource, NULL);
    glCompileShader(*shaderId);
    glGetShaderiv(*shaderId, GL_COMPILE_STATUS, &isCompiled);

    if(isCompiled == GL_FALSE) 
    {
        printf("Shader Compiler Error: %s\n", shaderFilePath);
        glDeleteShader(*shaderId);
        return;
    }
}

void link_shader(GLuint vertexShaderID, GLuint fragmentShaderID)
{
    GLuint programID = 0;
    GLint isLinked = 0;
    GLint maxLength = 0;
    char* infoLog = malloc(1024);

    programID = glCreateProgram();

    glAttachShader(programID, vertexShaderID);
    glAttachShader(programID, fragmentShaderID);

    glLinkProgram(programID);

    glGetProgramiv(programID, GL_LINK_STATUS, &isLinked);
    if(isLinked == GL_FALSE) {
        printf("Shader Program Linker Error\n");
        
	    glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &maxLength);
        glGetProgramInfoLog(programID, maxLength, &maxLength, &infoLog[0]);

        printf("%s\n", infoLog);

        glDeleteProgram(programID);

        glDeleteShader(vertexShaderID);
        glDeleteShader(fragmentShaderID);
        free(infoLog);

        return;
    }

    glDetachShader(programID, vertexShaderID);
    glDetachShader(programID, fragmentShaderID);

    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);
    free(infoLog);
}