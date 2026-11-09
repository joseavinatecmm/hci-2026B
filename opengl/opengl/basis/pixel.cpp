
#define GL_SILENCE_DEPRECATION
#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>
#include <iostream>

// 1. Vertex Shader
const char* vertexShaderSource = R"(
    #version 330 core

    layout (location = 0) in vec2 aPos;
    layout (location = 1) in vec3 aColor;

    out vec3 vertexColor;

    void main() {
        gl_Position = vec4(aPos, 0.0, 1.0);
        gl_PointSize = 8.0;
        vertexColor = aColor;
    }
)";

// 2. Fragment Shader
const char* fragmentShaderSource = R"(
    #version 330 core

    in vec3 vertexColor;
    out vec4 FragColor;

    void main() {
        FragColor = vec4(vertexColor, 1.0);
    }
)";

int main() {

    // 3. Inicializar GLFW
    if (!glfwInit()) {
        std::cerr << "Error al iniciar GLFW\n";
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(
        800, 600,
        "OpenGL - Varios Pixeles",
        nullptr, nullptr
    );

    if (!window) {
        std::cerr << "Error al crear la ventana\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    // 4. Compilar Vertex Shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(
        vertexShader, 1,
        &vertexShaderSource, nullptr
    );

    glCompileShader(vertexShader);

    // 5. Compilar Fragment Shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(
        fragmentShader, 1,
        &fragmentShaderSource, nullptr
    );

    glCompileShader(fragmentShader);

    // 6. Crear Shader Program
    GLuint shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);

    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // 7. Coordenadas y colores de siete puntos
    // Cada punto: x, y, R, G, B
    float pixels[] = {
        -0.75f,  0.60f,  1.0f, 0.0f, 0.0f,
        -0.50f,  0.40f,  0.0f, 1.0f, 0.0f,
        -0.25f,  0.20f,  0.0f, 0.0f, 1.0f,
         0.00f,  0.00f,  1.0f, 1.0f, 0.0f,
         0.25f, -0.20f,  1.0f, 0.0f, 1.0f,
         0.50f, -0.40f,  0.0f, 1.0f, 1.0f,
         0.75f, -0.60f,  1.0f, 1.0f, 1.0f
    };

    // 8. Configurar VAO y VBO
    GLuint VAO, VBO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(
        GL_ARRAY_BUFFER,
        sizeof(pixels),
        pixels,
        GL_STATIC_DRAW
    );

    // Atributo 0: posición (x, y)
    glVertexAttribPointer(
        0, 2, GL_FLOAT, GL_FALSE,
        5 * sizeof(float),
        (void*)0
    );

    glEnableVertexAttribArray(0);

    // Atributo 1: color (R, G, B)
    glVertexAttribPointer(
        1, 3, GL_FLOAT, GL_FALSE,
        5 * sizeof(float),
        (void*)(2 * sizeof(float))
    );

    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // 9. Controlar el tamaño desde el Vertex Shader
    glEnable(GL_PROGRAM_POINT_SIZE);

    // 10. Ciclo de renderizado
    while (!glfwWindowShouldClose(window)) {

        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);

        glDrawArrays(GL_POINTS, 0, 7);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // 11. Liberar recursos
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

