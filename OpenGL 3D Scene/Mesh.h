#pragma once

// general includes
#include <iostream>
#include <vector>
#include <cstdlib>

// glew includes
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// GLM Math Header inclusions
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// camera
#include <learnOpengl/camera.h>

// Structure to store the data of a mesh object
struct GLMesh
{
    GLuint vao; // Vertex Array Object
    GLuint vbo; // Vertex Buffer Object
    GLuint vbos[2]; // Vertex Buffer Object array
    GLuint nIndices; // Number of indices

    // Vector arrays to store the vertex data and parameter data of the mesh
    std::vector<float> v;
    std::vector<float> p;

    // Variables to store mesh properties
    float height;
    float length;
    float radius;
    float number_of_sides;

    // Matrices to store transformations for the mesh
    glm::mat4 scale;
    glm::mat4 xrotation;
    glm::mat4 yrotation;
    glm::mat4 zrotation;
    glm::mat4 rotation;
    glm::mat4 translation;
    glm::mat4 model;

    // Vector to store texture scaling parameters
    glm::vec2 gUVScale;

    // File name of the texture image
    const char* texFilename;

    // Texture identifier
    GLuint textureId;

    // Wrap mode for the texture
    GLint gTextWrapMode = GL_REPEAT;

    // Empty class for the mesh
    class Mesh
    {};
};