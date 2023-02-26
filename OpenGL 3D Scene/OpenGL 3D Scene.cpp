#include "Shapes.h"
#include "Mesh.h"
#include "Scene.h"
#include "Camera.h"
#include "Shaders.h"
#include "Lighting.h";

using namespace std;

Shapes builder;

//shader program
GLuint gShaderProgram;
GLuint gShadowProgramId;
GLuint gLightProgramId;
GLightMesh ambLightMesh;
GLightMesh keyLightMesh;



// scene vector for drawing shapes
vector<GLMesh> scene;


//initialize program
bool UInitialize(int, char* [], GLFWwindow** window);
//render graphics
void URender(vector<GLMesh> scene);

//free up memory on close
void UDestroyMesh(GLMesh& mesh);
void UDestroyShaderProgram(GLuint programId);
void UDestroyTexture(GLuint textureId);



bool UInitialize(int argc, char* argv[], GLFWwindow** window)
{
	// Initialize the GLFW library
	glfwInit();

	// Specify the context version and profile
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// On MacOS, add compatibility with the forward-compatible core profile
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	// Create the GLFW window
	* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL);

	// Check if the window creation failed
	if (*window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return false;
	}

	// Make the window's context the current one
	glfwMakeContextCurrent(*window);

	// Register the window resize callback function
	glfwSetFramebufferSizeCallback(*window, UResizeWindow);

	// Register the mouse position callback function
	glfwSetCursorPosCallback(*window, UMousePositionCallback);

	// Register the mouse scroll callback function
	glfwSetScrollCallback(*window, UMouseScrollCallback);

	// Register the mouse button callback function
	glfwSetMouseButtonCallback(*window, UMouseButtonCallback);

	// Set the input mode for the cursor to be disabled
	glfwSetInputMode(*window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// Allow the usage of experimental features
	glewExperimental = GL_TRUE;

	// Initialize the GLEW library
	GLenum GlewInitResult = glewInit();

	// Check if the GLEW initialization failed
	if (GLEW_OK != GlewInitResult)
	{
		std::cerr << glewGetErrorString(GlewInitResult) << std::endl;
		return false;
	}

	// Print the version of OpenGL currently in use
	cout << "INFO: OpenGL Version: " << glGetString(GL_VERSION) << endl;

	// Return success
	return true;
}

// Key callback function for processing key inputs
void UKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_P && action == GLFW_PRESS)
	{
		gPerspective = !gPerspective;
	}
}

int main(int argc, char* argv[])
{
	// Initialize the window and OpenGL context
	if (!UInitialize(argc, argv, &window))
		return EXIT_FAILURE;

	// Build the scene
	Scene::UBuildScene(scene);

	// Create the shader program
	if (!UCreateShaderProgram(vertex_shader_source, fragment_shader_source,
		gShaderProgram))
		return EXIT_FAILURE;

	// Load the textures for each mesh in the scene
	for (auto& m : scene)
	{
		// Load the texture
		if (!UCreateTexture(m.texFilename, m.textureId))
		{
			cout << "Failed to load texture " << m.texFilename << endl;
			return EXIT_FAILURE;
		}

		// Create the shader program (duplicate line, may need to remove)
		if (!UCreateShaderProgram(vertex_shader_source, fragment_shader_source,
			gShaderProgram))

			return EXIT_FAILURE;
	}
	if (!UCreateShaderProgram(lampVertexShaderSource, lampFragmentShaderSource, gLightProgramId))
		return EXIT_FAILURE;

	if (!UCreateShaderProgram(shadowVertexShaderSource, shadowFragShaderSource, gShadowProgramId))
		return EXIT_FAILURE;

	UCreateLightMesh(ambLightMesh);
	UCreateLightMesh(keyLightMesh);

	// Use the shader program
	glUseProgram(gShaderProgram);

	// Bind the texture to unit 0
	glUniform1i(glGetUniformLocation(gShaderProgram, "uTexture"), 0);

	// The main loop
	while (!glfwWindowShouldClose(window))
	{
		// Set the clear color
		glClearColor(0.3f, 0.5f, 0.5f, 1.0f);

		// Set the key callback
		glfwSetKeyCallback(window, UKeyCallback);

		// Calculate delta time
		float currentFrame = glfwGetTime();
		gDeltaTime = currentFrame - gLastFrame;
		gLastFrame = currentFrame;

		// Process user input
		UProcessInput(window);

		// Render the scene
		URender(scene);

		// Poll for events
		glfwPollEvents();
	}

	// Destroy the meshes
	for (auto& m : scene)
	{
		UDestroyMesh(m);
	}

	// Clear the scene
	scene.clear();

	// Destroy the shader program
	UDestroyShaderProgram(gShaderProgram);
	UDestroyShaderProgram(gLightProgramId);

	// Exit with success
	exit(EXIT_SUCCESS);
}

// Render Loop
void URender(vector<GLMesh> scene)
{

	// Enable depth testing to remove hidden pixels
	glEnable(GL_DEPTH_TEST);

	// Clear the color and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Calculate the view matrix from the camera's position and orientation
	glm::mat4 view = gCamera.GetViewMatrix();

	// Calculate the projection matrix, either perspective or orthographic
	glm::mat4 projection;
	if (gPerspective)
	{
		// Use the perspective projection matrix
		projection = gPerspectiveProjection;
	}
	else
	{
		// Use the orthographic projection matrix
		projection = gOrthographicProjection;
	}

	// loop to draw each shape individually
	for (auto i = 0; i < scene.size(); ++i)
	{
		auto mesh = scene[i];

		// activate vbo's within mesh's vao
		glBindVertexArray(mesh.vao);

		// set shader
		glUseProgram(gShaderProgram);

		// gets and passes transform matrices to shader prgm for shapes
		GLint modelLocation = glGetUniformLocation(gShaderProgram, "model");
		GLint viewLocation = glGetUniformLocation(gShaderProgram, "view");
		GLint projLocation = glGetUniformLocation(gShaderProgram, "projection");

		glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(mesh.model));
		glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(projLocation, 1, GL_FALSE, glm::value_ptr(projection));

		// Reference matrix uniforms from the shape shader program for the shape color, light color, light position, and camera position
		GLint objectColorLoc = glGetUniformLocation(gShaderProgram, "objectColor");

		// Spotlight
		GLint lightColorLoc = glGetUniformLocation(gShaderProgram, "lightColor");
		GLint lightPositionLoc = glGetUniformLocation(gShaderProgram, "lightPos");

		// Key light
		GLint keyLightColorLoc = glGetUniformLocation(gShaderProgram, "keyLightColor");
		GLint keyLightPositionLoc = glGetUniformLocation(gShaderProgram, "keyLightPos");

		// Camera view
		GLint viewPositionLoc = glGetUniformLocation(gShaderProgram, "viewPosition");

		// Pass color, light, and camera data to the shape shader 
		glUniform3f(objectColorLoc, mesh.p[0], mesh.p[1], mesh.p[2]);

		// Spot Light
		glUniform3f(lightColorLoc, gSpotLightColor.r, gSpotLightColor.g, gSpotLightColor.b);
		glUniform3f(lightPositionLoc, gSpotLightPosition.x, gSpotLightPosition.y, gSpotLightPosition.z);

		// Key Light
		glUniform3f(keyLightColorLoc, gKeyLightColor.r, gKeyLightColor.g, gKeyLightColor.b);
		glUniform3f(keyLightPositionLoc, gKeyLightPosition.x, gKeyLightPosition.y, gKeyLightPosition.z);

		const glm::vec3 cameraPosition = gCamera.Position;
		glUniform3f(viewPositionLoc, cameraPosition.x, cameraPosition.y, cameraPosition.z);


		GLint UVScaleLoc = glGetUniformLocation(gShaderProgram, "uvScale");
		glUniform2fv(UVScaleLoc, 1, glm::value_ptr(mesh.gUVScale));

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, mesh.textureId);

		// Draws the shape
		glDrawArrays(GL_TRIANGLES, 0, mesh.nIndices);


	}

	// Draw the Spot Light
	glUseProgram(gLightProgramId);

	glBindVertexArray(ambLightMesh.vao);

	// Light location and Scale
	glm::mat4 model = glm::translate(gSpotLightPosition) * glm::scale(gSpotLightScale);

	// Matrix uniforms from the Light Shader program
	GLint modelLoc = glGetUniformLocation(gLightProgramId, "model");
	GLint viewLoc = glGetUniformLocation(gLightProgramId, "view");
	GLint projLoc = glGetUniformLocation(gLightProgramId, "projection");

	// Matrix data
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

	// Draw the light
	glDrawArrays(GL_TRIANGLES, 0, ambLightMesh.nVertices);



	// Draw the Key Light
	glUseProgram(gLightProgramId);
	glBindVertexArray(keyLightMesh.vao);

	// Light location and Scale
	model = glm::translate(gKeyLightPosition) * glm::scale(gKeyLightScale);

	// Matrix uniforms from the Light Shader program
	modelLoc = glGetUniformLocation(gLightProgramId, "model");
	viewLoc = glGetUniformLocation(gLightProgramId, "view");
	projLoc = glGetUniformLocation(gLightProgramId, "projection");

	// Matrix data
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

	// Draw the light
	glDrawArrays(GL_TRIANGLES, 0, keyLightMesh.nVertices);

	// deactivate vao's
	glBindVertexArray(0);
	glUseProgram(0);

	// swap front and back buffers
	glfwSwapBuffers(window);
}

// Clean up the Vertex Array Object and Vertex Buffer Object associated with the mesh
void UDestroyMesh(GLMesh& mesh)
{
	glDeleteVertexArrays(1, &mesh.vao);
	glDeleteBuffers(1, &mesh.vbo);
}