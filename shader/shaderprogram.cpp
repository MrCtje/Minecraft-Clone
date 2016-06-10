#include "shaderprogram.h"

shaderprogram::shaderprogram()
{

}

 GLuint shaderprogram::loadShader(const char * filepath, GLenum shader_type){
    GLuint shader_id = 0;
    std::string buffer;
    std::string buffer2;
    std::ifstream shader_file(filepath);
    if(shader_file.is_open()){
        while(std::getline(shader_file, buffer)){ //Reads file
            buffer2.append("\n"+buffer);
        }
        shader_file.close();
    }
    const GLchar * result;
    result = buffer2.c_str();
    shader_id = glCreateShader(shader_type);
    glShaderSource(shader_id, 1, &result, NULL);
    glCompileShader(shader_id);
    GLint compiled;
    glGetShaderiv( shader_id , GL_COMPILE_STATUS, &compiled );
    if ( !compiled ) {  //Error Message

        GLsizei len;
        glGetShaderiv( shader_id , GL_INFO_LOG_LENGTH, &len );

        GLchar* log = new GLchar[len+1];
        glGetShaderInfoLog( shader_id , len, &len, log );
        std::cerr << "Shader compilation failed: " << log << std::endl;
        delete[] log;
    }
    return shader_id;
}
