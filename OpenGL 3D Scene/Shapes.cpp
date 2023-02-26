#include <cstdlib>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <cmath>
#include "Shapes.h"

using namespace std;

void Shapes::UBuildDimond(GLMesh& mesh)
{


	mesh.v = {

		// Positions		// Color			// Texture Coordinates
		// front face Top
		-0.5f, 0.8f, 0.0f,		1.0f, 0.6f, 1.0f, 1.0f,		1.0f, 1.0f, // top vertex
		-1.0f, 0.0f, 0.5f,		1.0f, 0.6f, 1.0f, 1.0f,		0.0f, 1.0f, // left vertex
		0.0f, 0.0f, 0.5f,		1.0f, 0.6f, 1.0f, 1.0f,		0.0f, 0.0f, // right vertex
		//Front Face Bottom
		-0.5f,-0.8f, 0.0f,		1.0f, 0.6f, 1.0f, 1.0f,		1.0f, 1.0f, // bottom vertex
		-1.0f, 0.0f, 0.5f,		1.0f, 0.6f, 1.0f, 1.0f,		0.0f, 0.0f, // left vertex
		0.0f, 0.0f, 0.5f,		1.0f, 0.6f, 1.0f, 1.0f,		0.0f, 1.0f, // right vertex
		//Right face Top
		-0.5f, 0.8f, 0.0f,		1.0f, 0.6f, 1.0f, 1.0f,		1.0f, 1.0f, // top vertex
		0.0f, 0.0f, 0.5f,		1.0f, 0.6f, 1.0f, 1.0f,		0.0f, 0.0f, // front vertex
		0.0f, 0.0f, -0.5f,		1.0f, 0.6f, 1.0f, 1.0f,		0.0f, 1.0f, // back vertex
		//Right Face Bottom
		-0.5f, -0.8f, 0.0f,		1.0f, 0.6f, 1.0f, 1.0f,		1.0f, 1.0f, // bottom vertex
		0.0f, 0.0f, 0.5f,		1.0f, 0.6f, 1.0f, 1.0f,		0.0f, 1.0f, // front vertex
		0.0f, 0.0f, -0.5f,		1.0f, 0.6f, 1.0f, 1.0f,		0.0f, 0.0f, // back vertex
		//Back Face Top
		-0.5f, 0.8f, 0.0f,		1.0f, 0.6f, 1.0f, 1.0f,		1.0f, 1.0f, // top vertex
		0.0f, 0.0f, -0.5f,		1.0f, 0.6f, 1.0f, 1.0f,		0.0f, 1.0f, // back vertex
		-1.0f, 0.0f, -0.5f,		1.0f, 0.6f, 1.0f, 1.0f,		0.0f, 0.0f, // left vertex
		//Back Face Bottom
		-0.5f, -0.8f, 0.0f,		1.0f, 0.6f, 1.0f, 1.0f,		1.0f, 1.0f, // bottom vertex
		0.0f, 0.0f, -0.5f,		1.0f, 0.6f, 1.0f, 1.0f,		0.0f, 0.0f, // back vertex
		-1.0f, 0.0f, -0.5f,		1.0f, 0.6f, 1.0f, 1.0f,		0.0f, 1.0f, // left vertex
		//Left Face Top
		-0.5f, 0.8f, 0.0f,		1.0f, 0.6f, 1.0f, 1.0f,		1.0f, 1.0f, // top vertex
		-1.0f, 0.0f, -0.5f,		1.0f, 0.6f, 1.0f, 1.0f,		0.0f, 0.0f, // left vertex
		-1.0f, 0.0f, 0.5f,		1.0f, 0.6f, 1.0f, 1.0f,		0.0f, 1.0f, // front vertex
		//Left face Bootom
		-0.5f, -0.8f, 0.0f,		1.0f, 0.6f, 1.0f, 1.0f,		1.0f, 1.0f, // bottom vertex
		-1.0f, 0.0f, -0.5f,		1.0f, 0.6f, 1.0f, 1.0f,		0.0f, 1.0f, // left vertex
		-1.0f, 0.0f, 0.5f,		1.0f, 0.6f, 1.0f, 1.0f,		0.0f, 0.0f, // front vertex
	};

	UTranslator(mesh);

}
void Shapes::UBuildCube(GLMesh& mesh)
{
	vector<float> c = { mesh.p[0], mesh.p[1], mesh.p[2], mesh.p[3] };
	float h = mesh.height;

	mesh.v = {
		// vertex position		// vertex color					// texture coordinate
		//Left Side Front
		-0.5f,-1.0f,-0.5f,		0.84f, 0.84f, 0.87f, 1.0f,		0.0f, 0.0f,
		-0.5f,-1.0f,0.5f,		0.84f, 0.84f, 0.87f, 1.0f,		1.0f, 1.0f,
		-0.5f,0.3f,0.5f,		0.84f, 0.84f, 0.87f, 1.0f,		0.0f, 1.0f,
		//Back Side Left
		0.5f,0.3f,-0.5f,		0.84f, 0.84f, 0.87f, 1.0f,		0.0f, 0.0f,
		-0.5f,-1.0f,-0.5f,		0.84f, 0.84f, 0.87f, 1.0f,		1.0f, 1.0f,
		-0.5f,0.3f,-0.5f,		0.84f, 0.84f, 0.87f, 1.0f,		0.0f, 1.0f,
		//Bottom Side Right
		0.5f,-1.0f,0.5f,		0.84f, 0.84f, 0.87f, 1.0f,		0.0f, 0.0f,
		-0.5f,-1.0f,-0.5f,		0.84f, 0.84f, 0.87f, 1.0f,		1.0f, 1.0f,
		0.5f,-1.0f,-0.5f,		0.84f, 0.84f, 0.87f, 1.0f,		0.0f, 1.0f,
		//Back Side Right
		0.5f,0.3f,-0.5f,		0.84f, 0.84f, 0.87f, 1.0f,		0.0f, 1.0f,
		0.5f,-1.0f,-0.5f,		0.84f, 0.84f, 0.87f, 1.0f,		1.0f, 1.0f,
		-0.5f,-1.0f,-0.5f,		0.84f, 0.84f, 0.87f, 1.0f,		0.0f, 0.0f,
		//Left Side Back
		-0.5f,-1.0f,-0.5f,		0.84f, 0.84f, 0.87f, 1.0f,		1.0f, 1.0f,
		-0.5f,0.3f,0.5f,		0.84f, 0.84f, 0.87f, 1.0f,		0.0f, 0.0f,
		-0.5f,0.3f,-0.5f,		0.84f, 0.84f, 0.87f, 1.0f,		0.0f, 1.0f,
		//Bottom Side Left
		0.5f,-1.0f,0.5f,		0.84f, 0.84f, 0.87f, 1.0f,		0.0f, 1.0f,
		-0.5f,-1.0f,0.5f,		0.84f, 0.84f, 0.87f, 1.0f,		1.0f, 1.0f,
		-0.5f,-1.0f,-0.5f,		0.84f, 0.84f, 0.87f, 1.0f,		0.0f, 0.0f,
		//Front Side Left
		-0.5f,0.3f,0.5f,		0.84f, 0.84f, 0.87f, 1.0f,		0.0f, 1.0f,
		-0.5f,-1.0f,0.5f,		0.84f, 0.84f, 0.87f, 1.0f,		1.0f, 1.0f,
		0.5f,-1.0f,0.5f,		0.84f, 0.84f, 0.87f, 1.0f,		0.0f, 0.0f,
		//Right Side Back
		0.5f,0.3f,0.5f,			0.84f, 0.84f, 0.87f, 1.0f,		0.0f, 0.0f,	
		0.5f,-1.0f,-0.5f,		0.84f, 0.84f, 0.87f, 1.0f,		0.0f, 1.0f,
		0.5f,0.3f,-0.5f,		0.84f, 0.84f, 0.87f, 1.0f,		1.0f, 1.0f,
		//Right Side Front
		0.5f,-1.0f,-0.5f,		0.84f, 0.84f, 0.87f, 1.0f,		0.0f, 0.0f, 
		0.5f,0.3f,0.5f,			0.84f, 0.84f, 0.87f, 1.0f,		0.0f, 1.0f,
		0.5f,-1.0f,0.5f,		0.84f, 0.84f, 0.87f, 1.0f,		1.0f, 1.0f,
		//Top Side Right 
		0.5f,0.3f,0.5f,			0.84f, 0.84f, 0.87f, 1.0f,		1.0f, 0.0f,
		0.5f,0.3f,-0.5f,		0.84f, 0.84f, 0.87f, 1.0f,		1.0f, 1.0f,
		-0.5f,0.3f,-0.5f,		0.84f, 0.84f, 0.87f, 1.0f,		0.0f, 0.0f,
		//Top Side Left
		0.5f,0.3f,0.5f,			0.84f, 0.84f, 0.87f, 1.0f,		0.0f, 0.0f,
		-0.5f,0.3f,-0.5f,		0.84f, 0.84f, 0.87f, 1.0f,		1.0f, 0.0f,
		-0.5f,0.3f,0.5f,		0.84f, 0.84f, 0.87f, 1.0f,		1.0f, 1.0f,
		//Front Side Right
		0.5f,0.3f,0.5f,			0.84f, 0.84f, 0.87f, 1.0f,		1.0f, 1.0f,
		-0.5f,0.3f,0.5f,		0.84f, 0.84f, 0.87f, 1.0f,		0.0f, 0.0f,
		0.5f,-1.0f,0.5f,		0.84f, 0.84f, 0.87f, 1.0f,		0.0f, 1.0f,

	};

	UTranslator(mesh);
}

void Shapes::UBuildCone(GLMesh& mesh)
{
	vector<float> c = { mesh.p[0], mesh.p[1], mesh.p[2], mesh.p[3] };

	float r = mesh.radius;
	float h = mesh.height;
	float s = mesh.number_of_sides;

	constexpr float PI = 3.14f;
	const float sectorStep = 2.0f * PI / s;
	const float textStep = 1.0f / s;
	float textureXLoc = 0.0f;

	vector<float> v;

	for (auto i = 1; i < s + 1; i++) {

		float one = 0.5f + r * cos(i * sectorStep);
		float two = 0.5f + r * sin(i * sectorStep);

		one -= 0.5f;
		one *= 2.0f;
		two -= 0.5f;
		two *= 2.0f;

		c[0] = one;
		c[2] = two;

		v.insert(v.end(), { 0.5f, 0.0f, 0.5f, c[0], -1.0f, c[2], c[3], 0.5f, 0.25f });		// center point; x, y, z, r, g, b, a, texture x, texture y
		v.insert(v.end(), { 0.5f + r * cos(i * sectorStep) ,				// first outer point
										0.0f ,
										0.5f + r * sin(i * sectorStep) ,
										c[0], -1.0f, c[2], c[3],
			/*textureXLoc,
			0.0f*/
			0.5f + (r * cos((i)*sectorStep)) ,			// texture x; adding the origin for proper alignment
			0.25f + (0.25f * sin((i)*sectorStep))
			});
		v.insert(v.end(), { 0.5f + (r * cos((i + 1) * sectorStep)) ,		// second outer point
										0.0f ,
										0.5f + (r * sin((i + 1) * sectorStep)) ,
										c[0], -1.0f, c[2], c[3],
			/*textureXLoc + textStep,
			0.0f*/
			0.5f + (r * cos((i + 1) * sectorStep)) ,
			0.25f + (0.25f * sin((i + 1) * sectorStep))
			});


		// side triangle + point
		v.insert(v.end(), { 0.5f + (r * cos(i * sectorStep)) ,
										0.0f ,
										0.5f + (r * sin(i * sectorStep)) ,
										c[0], 1.0f, c[2], c[3],
										textureXLoc ,
										0.5f });
		v.insert(v.end(), { 0.5f + (r * cos((i + 1) * sectorStep)) ,
										0.0f ,
										0.5f + (r * sin((i + 1) * sectorStep)) ,
										c[0], 1.0f, c[2], c[3],
										textureXLoc + textStep,
										0.5f });
		v.insert(v.end(), { 0.5f , h , 0.5f , c[0], 1.0f, c[2], c[3], textureXLoc + (textStep / 2), 1.0f });
		textureXLoc += textStep;
	}
	mesh.v = v;
	v.clear();

	UTranslator(mesh);
}

void Shapes::UBuildCylinder(GLMesh& mesh)
{
	vector<float> c = { mesh.p[0], mesh.p[1], mesh.p[2], mesh.p[3] };

	// Declaring variables to store mesh properties
	float r = mesh.radius;
	float l = mesh.length;
	float s = mesh.number_of_sides;
	float h = mesh.height;

	// Constant variable PI to store value of Pi
	constexpr float PI = 3.14f;

	// Calculating sector step for each iteration
	const float sectorStep = 2.0f * PI / s;

	// Vector v to store vertex data
	vector<float> v;

	// Loop to add vertices to v
	for (auto i = 1; i < s + 1; i++)
	{
		// Adding first vertex
		v.insert(v.end(), { 0.5f, 0.5f, 0.0f, c[0],	c[1], c[2],	c[3], 0.5f, 0.125f });
		// Adding second vertex
		v.insert(v.end(), { 0.5f + r * cos(i * sectorStep) ,
											0.5f + r * sin(i * sectorStep) ,
											0.0f ,
											c[0], c[1], c[2], c[3],
											0.5f + (r * cos((i)*sectorStep)) ,
											(0.125f + (0.125f * sin((i)*sectorStep))) });

		// Adding third vertex
		v.insert(v.end(), { 0.5f + r * cos((i + 1) * sectorStep) ,
											0.5f + r * sin((i + 1) * sectorStep) ,
											0.0f ,
											c[0], c[1], c[2], c[3],
											0.5f + (r * cos((i + 1) * sectorStep)) ,
											(0.125f + (0.125f * sin((i + 1) * sectorStep))) });
	}

	// For loop to generate the top and bottom vertices of the cylinder
	for (auto i = 1; i < s + 1; i++)
	{
		// Insert the vertices for the top of the cylinder
		v.insert(v.end(), { 0.5f, 0.5f, l, c[0], c[1], c[2], c[3], 0.5f, 0.875f });

		// Insert the vertices for the side of the cylinder
		v.insert(v.end(), { 0.5f + r * cos(i * sectorStep) ,
							0.5f + r * sin(i * sectorStep) ,
							l ,
							c[0], c[1], c[2], c[3],
							0.5f + (r * cos((i)*sectorStep)) ,
							0.875f + (0.125f * sin((i)*sectorStep)) });
		v.insert(v.end(), { 0.5f + r * cos((i + 1) * sectorStep) ,
							0.5f + r * sin((i + 1) * sectorStep) ,
							l ,
							c[0], c[1], c[2], c[3],
							0.5f + (r * cos((i + 1) * sectorStep)) ,
							0.875f + (0.125f * sin((i + 1) * sectorStep)) });
	}

	// Constants for generating the bottom of the cylinder
	constexpr float x = 1.0f;
	float j = 1.0f / (s / x);
	float k = 0.0f;

	// For loop to generate the bottom vertices of the cylinder
	for (auto i = 1; i < s + 1; i++)
	{
		// Insert the vertices for the bottom of the cylinder
		v.insert(v.end(), { 0.5f + r * cos(i * sectorStep) ,
							0.5f + r * sin(i * sectorStep) ,
							0.0f ,
							c[0], c[1], c[2], c[3],
							k ,
							0.25f });
		v.insert(v.end(), { 0.5f + r * cos(i * sectorStep) ,
							0.5f + r * sin(i * sectorStep) ,
							l ,
							c[0], c[1], c[2], c[3],
							k ,
							0.75f });
		v.insert(v.end(), { 0.5f + r * cos((i + 1) * sectorStep) ,
							0.5f + r * sin((i + 1) * sectorStep) ,
							l ,
							c[0], c[1], c[2], c[3],
							k + j ,
							0.75f });

		v.insert(v.end(), { 0.5f + r * cos((i + 1) * sectorStep) ,
							0.5f + r * sin((i + 1) * sectorStep) ,
							l ,
							c[0], c[1], c[2], c[3],
							k + j ,
							0.75f });
		v.insert(v.end(), { 0.5f + r * cos((i + 1) * sectorStep) ,
							0.5f + r * sin((i + 1) * sectorStep) ,
							0.0f ,
							c[0], c[1], c[2], c[3],					
							k + j ,
							0.25f });
		v.insert(v.end(), { 0.5f + r * cos(i * sectorStep) ,
							0.5f + r * sin(i * sectorStep) ,
							0.0f ,
							c[0], c[1], c[2], c[3],					
							k,
							0.25f });
		// Increment k by the value of j
		k += j;
	}

	// Assign the vector "v" to the member variable "v" of the "mesh" object
	mesh.v = v;

	// Clear the contents of the vector "v"
	v.clear();

	// Call the function "UTranslator" with the "mesh" object as argument
	UTranslator(mesh);

}


void Shapes::UBuildPlane(GLMesh& mesh)
{
	// Use this to build the ground, for proper lighting
	vector<float> c = { mesh.p[0], mesh.p[1], mesh.p[2], mesh.p[3] };
	mesh.v = {
		// vertex position			// vertex color				// texture coordinate	
		-25.0f, -5.0f, 5.0f,		0.84, 0.77, 0.68, 1.0f,		0.0f, 0.0f,		// bottom left
		25.0f, -5.0f, -25.0f,		0.84, 0.77, 0.68, 1.0f,		1.0f, 1.0f,		// bottom right
		-25.0f, -5.0f, -25.0f,		0.84, 0.77, 0.68, 1.0f,		0.0f, 1.0f,		// top left
		25.0f, -5.0f, 5.0f,			0.84, 0.77, 0.68, 1.0f,		1.0f, 0.0f,		// top right

		-25.0f, -5.0f, 5.0f,		0.84, 0.77, 0.68, 1.0f,		0.0f, 0.0f,		// bottom left
		25.0f, -5.0f, -25.0f,		0.84, 0.77, 0.68, 1.0f,		1.0f, 1.0f,		// bottom right
		-25.0f, -5.0f, -25.0f,		0.84, 0.77, 0.68, 1.0f,		0.0f, 1.0f,		// top left
		25.0f, -5.0f, 5.0f,			0.84, 0.77, 0.68, 1.0f,		1.0f, 0.0f,		// top right

	};
	// Call the function "UTranslator" with the "mesh" object as argument
	UTranslator(mesh);

}

void Shapes::UTranslator(GLMesh& mesh)
{
	// Constants for the number of floats per vertex for position, color, and UVs
	constexpr GLuint floatsPerVertex = 3;
	constexpr GLuint floatsPerColor = 4;
	constexpr GLuint floatsPerUV = 2;

	// Calculate the number of indices in the vertex data
	mesh.nIndices = mesh.v.size() / (floatsPerVertex + floatsPerUV + floatsPerColor);

	// Generate a Vertex Array Object (VAO)
	glGenVertexArrays(1, &mesh.vao);
	glBindVertexArray(mesh.vao);

	// Generate a Vertex Buffer Object (VBO)
	glGenBuffers(1, &mesh.vbo);
	glBindBuffer(GL_ARRAY_BUFFER, mesh.vbo);

	// Copy vertex data into the VBO
	glBufferData(
		GL_ARRAY_BUFFER,
		mesh.v.size() * sizeof(float),
		&mesh.v.front(),
		GL_STATIC_DRAW
	);

	// Calculate the stride for the vertex data
	constexpr GLint stride = sizeof(float) * (floatsPerVertex + floatsPerUV + floatsPerColor);

	// Specify the format of the vertex position data and enable it
	glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, (void*)0);
	glEnableVertexAttribArray(0);

	// Specify the format of the vertex color data and enable it
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride, (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// Specify the format of the vertex UV data and enable it
	glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (void*)(7 * sizeof(float)));
	glEnableVertexAttribArray(2);

	// Calculate the scale matrix for the mesh
	mesh.scale = glm::scale(glm::vec3(mesh.p[4], mesh.p[5], mesh.p[6]));

	// Create a default identity matrix for rotation
	const glm::mat4 rot = glm::mat4(1.0f);

	// Calculate the x-rotation matrix for the mesh
	mesh.xrotation = glm::rotate(rot, glm::radians(mesh.p[7]), glm::vec3(mesh.p[8], mesh.p[9], mesh.p[10]));

	// Calculate the y-rotation matrix for the mesh
	mesh.yrotation = glm::rotate(rot, glm::radians(mesh.p[11]), glm::vec3(mesh.p[12], mesh.p[13], mesh.p[14]));

	// Calculate the z-rotation matrix for the mesh
	mesh.zrotation = glm::rotate(rot, glm::radians(mesh.p[15]), glm::vec3(mesh.p[16], mesh.p[17], mesh.p[18]));

	// Translate the mesh based on the values in the p array at indices 19, 20, and 21
	mesh.translation = glm::translate(glm::vec3(mesh.p[19], mesh.p[20], mesh.p[21]));

	// Calculate the final model matrix by combining the translation, rotations, and scale
	mesh.model = mesh.translation * mesh.xrotation * mesh.zrotation * mesh.yrotation * mesh.scale;

	// Set the UV scale for the mesh using the values in the p array at indices 22 and 23
	mesh.gUVScale = glm::vec2(mesh.p[22], mesh.p[23]);

}

