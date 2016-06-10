#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <math.h>
#include <chrono>

#include "models/objmodelloader.h"
#include "entity/entity.h"
#include "renderer/entityrenderer.h"
#include "entity/camera.h"
#include "util/coloro.h"
#include "models/loader.h"
#include "shader/shaderprogram.h"
#include "util/matrix.h"
#include "SOIL2.h"


typedef std::chrono::high_resolution_clock Clock;
#define color(x) colord::getColoredOutput(x)

using namespace std;

GLFWwindow *window;
enum VAO {Triangle, numVAO};
enum VBO {vPosition, vColor, numVBO};
GLuint VAO[numVAO];
GLuint VBO[numVBO];
GLuint Attrib[numVBO];
GLuint shader[2];
GLuint program;
int width, height;
Camera camera(0, 0, -80);



///
/// \brief cleanUp: Deletes resources from gpu memory
///
void cleanUp(){
    glDeleteProgram(program);
    glDeleteShader(shader[0]);
    glDeleteShader(shader[1]);
}

///
/// \brief error_callback: Handles errors
/// \param error
/// \param description
///
static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
///
/// \brief key_callback: Handles keypresses
/// \param window: Window to get Key_Callback from
/// \param key: GLFW Keycodes
/// \param scancode
/// \param action: KeyPressed, KeyReleased, KeyTyped
/// \param mods
///
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    //Change the angle of the camera
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
    if (key == GLFW_KEY_LEFT && (action == GLFW_REPEAT || action == GLFW_PRESS)){
        camera.increaseYaw(-5);
        glClearColor(0,1,0,1);
    }
    if (key == GLFW_KEY_RIGHT && (action == GLFW_REPEAT || action == GLFW_PRESS)){
        camera.increaseYaw(5);
        glClearColor(1,0,0,1);
    }
    if (key == GLFW_KEY_DOWN && (action == GLFW_REPEAT || action == GLFW_PRESS))
        camera.increasePitch(-5);
    if (key == GLFW_KEY_UP && (action == GLFW_REPEAT || action == GLFW_PRESS))
        camera.increasePitch(5);

    //Move forward/backward
    if (key == GLFW_KEY_W && (action == GLFW_REPEAT || action == GLFW_PRESS))
        camera.increasePosZ(5);
    if (key == GLFW_KEY_S && (action == GLFW_REPEAT || action == GLFW_PRESS))
        camera.increasePosZ(-5);
}

///
/// \brief cursorpos_callback: Mouselistener
/// \param window
/// \param xPos
/// \param yPos
///
static void cursorpos_callback(GLFWwindow* window, double xPos, double yPos)
{

}

///
/// \brief fpsCounter: Prints fps to screen
///
void fpsCounter(){
    static auto time = Clock::now();
    static uint timePassed;
    static uint frames = 0;
    static char buffer[25];
    timePassed = std::chrono::duration_cast<std::chrono::seconds>( Clock::now() - time ).count();
    if(timePassed>=3){
        cout<< "Fps: "<< frames / timePassed << endl;
        //snprintf(buffer, 25, "Minecraft: %d fps", frames/1);
        //glfwSetWindowTitle(window, buffer);
        time = Clock::now();
        frames = 0;
    }
    frames++;
}

///
/// \brief createProgram: Creates shaderprogram ands checks if it successfully linked
///
void createProgram(){
    program = glCreateProgram();
    glAttachShader(program, shader[0]);
    glAttachShader(program, shader[1]);
    glLinkProgram(program);
    glUseProgram(program);

    GLint isLinked = 0;
    glGetProgramiv(program, GL_LINK_STATUS, &isLinked);

    if(isLinked == GL_FALSE){
        GLint maxLength = 0;
            glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

            //The maxLength includes the NULL character
            GLchar infoLog[maxLength];
            glGetProgramInfoLog(program, maxLength, &maxLength, infoLog);
            cout << "Infolog: ";
            for(uint i = 0; i < sizeof(infoLog)/sizeof(infoLog[0]); i++){
                cout << infoLog[i];
            }
    }
}

///
/// \brief windowInit: initializes window
///
void windowInit(){
    glfwSetErrorCallback(error_callback);

    if(!glfwInit())
        exit(EXIT_FAILURE);
    glfwGetMonitorPhysicalSize(glfwGetPrimaryMonitor(), &width, &height);
    width = width < 1280 ? 1920 : width;
    height = height < 720 ? 1080 : height;
    window = glfwCreateWindow(width, height, "Minecraft", NULL, NULL);


    if(!window){
        glfwTerminate();
        exit(EXIT_FAILURE);
    }


    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, cursorpos_callback);

    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        exit(EXIT_FAILURE);
    }
}


int main(int argc, char *argv[])
{
    windowInit();

    ///
    /// Init
    ///
    glClearColor(.6,.0,.2,1);
    glPointSize(5);
    glEnable(GL_DEPTH_TEST);
 //   glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    
//    glEnable(GL_CULL_FACE);
//    glCullFace(GL_BACK);

//    glFrontFace(GL_CW);
    cout << color(colord::Red)
         << "################################################" << endl
         << "#                     DEBUG                    #" << endl
         << "################################################" << colord::resetAttributes() << endl;
    cout << "GL Shading Language Version: " << glGetString ( GL_SHADING_LANGUAGE_VERSION );
    //cout << "Max uniform locations: "<<  glGetString(GL_MAX_UNIFORM_LOCATIONS);

    shader[0] = shaderprogram::loadShader("/home/mrctje/Dropbox/qtWorkspace/Minecraft/shader/simple.frag", GL_FRAGMENT_SHADER);
    shader[1] = shaderprogram::loadShader("/home/mrctje/Dropbox/qtWorkspace/Minecraft/shader/simple.vsh", GL_VERTEX_SHADER);

    createProgram();

    Attrib[vPosition] = glGetAttribLocation(program, "in_Position");
    Attrib[vColor] = glGetAttribLocation(program, "in_Color");

    cout << endl << "in_Position: " << Attrib[vPosition];

    GLuint tex_2d = SOIL_load_OGL_texture
        (
            "/home/mrctje/Pictures/Screenshot from 2016-03-03 19-46-34.png",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
        );

    Loader loader;
    entityRenderer renderer(camera, program, width, height);
    OBJModelLoader objLoader;
//    Model model = objLoader.loadOBJModel("/home/mrctje/Documents/box.obj");
    Model model = objLoader.loadOBJModel("/home/mrctje/Dropbox/Eclipse/SteenPapierSchaar/alduin2.obj");
    Mesh mesh = loader.loadToMesh(model);
    entity torus(mesh, 0, 0, -80, 1);

    auto Time = Clock::now();

    while (!glfwWindowShouldClose(window))
    {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        ///
        ///Render
        ///

        renderer.render(camera ,torus, Attrib[vPosition]);
//        camera.setPitch(chrono::duration_cast<chrono::milliseconds>(Clock::now() - Time).count()/50);
        glfwSwapBuffers(window);
        glfwPollEvents();
        fpsCounter();
    }

    cleanUp();
    glfwDestroyWindow(window);
    glfwTerminate();
    glDeleteTextures(1, &tex_2d);

//    obj.loadOBJModel("/home/mrctje/Dropbox/Eclipse/SteenPapierSchaar/stall.obj");
//    cout << "\033[31m------------------------------------------\n"
//    <<      "                \033[4;1mWarning\033[24;21m\n"
//    <<      "------------------------------------------\n\n"
//    <<      "Stream closed unexpectedly\033[0m\n";
    return 0;
}
