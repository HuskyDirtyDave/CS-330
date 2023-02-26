#include "Scene.h"
#include "Mesh.h"
#include "Shapes.h"

using namespace std;

void Scene::UBuildScene(vector<GLMesh>& scene)
{
	// seed the random number generator with the current time
	srand(time(nullptr));

	// Create a GLMesh object for the vase
	GLMesh vase_gMesh;
	// Vase
	// Set the properties of the vase_gMesh object
	vase_gMesh.p = {
		1.0f, 1.0f, 1.0f, 1.0f,				// color r, g, b a
		0.5f, 0.5f, 0.5f,					// scale x, y, z
		0.0f, 1.0f, 0.0f, 0.0f,				// x amount of rotation, rotate x, y, z
		0.0f, 0.0f, 1.0f, 0.0f,				// y amount of rotation, rotate x, y, z
		0.0f, 0.0f, 0.0f, 1.0f,				// z amount of rotation, rotate x, y, z
		1.0f, 0.0f, 0.0f,					// translate x, y, z aka move the shape
		1.0f, 1.0f
	};
	vase_gMesh.length = 1.0f;
	vase_gMesh.radius = 2.0f;
	vase_gMesh.number_of_sides = 6.0f;
	vase_gMesh.texFilename = "Textures/Vase/Vase.jpg";

	// Build the cube for the vase using the Vase class
	Shapes::UBuildCube(vase_gMesh);

	// Add the vase_gMesh object to the scene vector
	scene.push_back(vase_gMesh);

	// Create a GLMesh object for the stem
	GLMesh stem_gMesh;
	// Stem
	// Set the properties of the vase_gMesh object
	stem_gMesh.p = {
		1.0f, 1.0f, 1.0f, 1.0f,				// color r, g, b a
		0.25f, 0.25f, 0.25f,				// scale x, y, z
		90.0f, -45.0f, 0.0f, 1.0f,			// x amount of rotation, rotate x, y, z
		0.0f, 90.0f, 0.0f, 1.0f,			// y amount of rotation, rotate x, y, z
		0.0f, 0.0f, 0.0f, 1.0f,				// z amount of rotation, rotate x, y, z
		0.875f, 0.0f, 0.125f,				// translate x, y, z aka move the shape
		1.0f, 1.0f
	};
	stem_gMesh.length = 2.0f;	
	stem_gMesh.radius = 0.3f; 
	stem_gMesh.number_of_sides = 128.0f;
	stem_gMesh.texFilename = "Textures/Vase/stem.jpg";

	// Build the cube for the stem using the Vase class
	Shapes::UBuildCylinder(stem_gMesh);

	// Add the stem_gMesh object to the scene vector
	scene.push_back(stem_gMesh);

	// Create a GLMesh object for the flower
	GLMesh flower_gMesh;
	// Flower Top
	// Set the properties of the flower_gMesh object
	flower_gMesh.p = {
		1.0f, 1.0f, 1.0f, 1.0f,				// color r, g, b a
		0.25f, 0.25f, 0.25f,				// scale x, y, z
		0.0f, 1.0f, 0.0f, 0.0f,				// x amount of rotation, rotate x, y, z
		0.0f, 0.0f, 1.0f, 0.0f,				// y amount of rotation, rotate x, y, z
		0.0f, 0.0f, 0.0f, 1.0f,				// z amount of rotation, rotate x, y, z
		1.11f, 0.5f, 0.0f,				// translate x, y, z aka move the shape
		1.0f, 1.0f
	};
	flower_gMesh.length = 1.0f;	
	flower_gMesh.radius = 0.3f;	
	flower_gMesh.number_of_sides = 8.0f;
	flower_gMesh.texFilename = "Textures/Vase/flowerPetal.jpg";
	
	// Build the cube for the flower using the Vase class
	Shapes::UBuildDimond(flower_gMesh);
	
	// Add the flower_gMesh object to the scene vector
	scene.push_back(flower_gMesh);



	// Create a GLMesh object for the floor
	GLMesh floor_gMesh;
	// Floor
	// Set the properties of the floor_gMesh objec
	floor_gMesh.p = {
		1.0f, 1.0f, 1.0f, 1.0f,				// color r, g, b a
		1.0f, 1.0f, 1.0f,					// scale x, y, z
		0.0f, 1.0f, 0.0f, 0.0f,				// x amount of rotation, rotate x, y, z
		0.0f, 0.0f, 1.0f, 0.0f,				// y amount of rotation, rotate x, y, z
		0.0f, 0.0f, 0.0f, 1.0f,				// z amount of rotation, rotate x, y, z
		-3.0f, 0.5f, 8.0f,				// translate x, y, z aka move the shape
		1.0f, 1.0f
	};
	floor_gMesh.texFilename = "Textures/Vase/woodFloor.jpg";
	
	// Build the cube for the floor using the Vase class
	Shapes::UBuildPlane(floor_gMesh);
	
	// Add the floor_gMesh object to the scene vector
	scene.push_back(floor_gMesh);

	// Table
	GLMesh desk_gMesh;
	desk_gMesh.p = {
		1.0f, 1.0f, 1.0f, 1.0f,				// color r, g, b a
		0.25f, 0.25f, 0.25f,				// scale x, y, z
		0.0f, 1.0f, 0.0f, 0.0f,				// x amount of rotation, rotate x, y, z
		0.0f, 0.0f, 1.0f, 0.0f,				// y amount of rotation, rotate x, y, z
		0.0f, 0.0f, 0.0f, 1.0f,				// z amount of rotation, rotate x, y, z
		-3.0f, 0.77f, 3.0f,				// translate x, y, z aka move the shape
		1.0f, 1.0f
	};
	desk_gMesh.texFilename = "Textures/Vase/desk.jpg";
	Shapes::UBuildPlane(desk_gMesh);
	scene.push_back(desk_gMesh);


	/*
	* Coffee Table
	*/
	GLMesh coffeTable_gMesh;
	coffeTable_gMesh.p = {
		1.0f, 1.0f, 1.0f, 1.0f,				// color r, g, b a
		12.5f, 2.5f, 7.5f,					// scale x, y, z
		0.0f, 1.0f, 0.0f, 0.0f,				// x amount of rotation, rotate x, y, z
		0.0f, 0.0f, 1.0f, 0.0f,				// y amount of rotation, rotate x, y, z
		0.0f, 0.0f, 0.0f, 1.0f,				// z amount of rotation, rotate x, y, z
		-3.0f, -1.25f, 0.5f,					// translate x, y, z aka move the shape
		1.0f, 1.0f
	};
	coffeTable_gMesh.length = 5.0f;
	coffeTable_gMesh.radius = 1.0f;
	coffeTable_gMesh.number_of_sides = 6.0f;
	coffeTable_gMesh.texFilename = "Textures/Vase/desk.jpg";
	Shapes::UBuildCube(coffeTable_gMesh);
	scene.push_back(coffeTable_gMesh);
	/*
	* Legs
	*/
	// Back Left Leg
	GLMesh bkLftLeg_gMesh;
	bkLftLeg_gMesh.p = {
		1.0f, 1.0f, 1.0f, 1.0f,				// color r, g, b a
		0.5f, 0.5f, -0.5f,				// scale x, y, z
		90.0f, -45.0f, 0.0f, 1.0f,			// x amount of rotation, rotate x, y, z
		0.0f, 90.0f, 0.0f, 1.0f,			// y amount of rotation, rotate x, y, z
		0.0f, 0.0f, 0.0f, 1.0f,				// z amount of rotation, rotate x, y, z
		-9.24391f, -3.37807f, -2.8f,				// translate x, y, z aka move the shape
		1.0f, 1.0f
	};
	bkLftLeg_gMesh.length = 2.0f;
	bkLftLeg_gMesh.radius = 0.3f;
	bkLftLeg_gMesh.number_of_sides = 128.0f;
	bkLftLeg_gMesh.texFilename = "Textures/Vase/desk.jpg";
	Shapes::UBuildCylinder(bkLftLeg_gMesh);
	scene.push_back(bkLftLeg_gMesh);
	// Back Right Leg
	GLMesh bkRgtLeg_gMesh;
	bkRgtLeg_gMesh.p = {
		1.0f, 1.0f, 1.0f, 1.0f,				// color r, g, b a
		0.5f, 0.5f, -0.5f,				// scale x, y, z
		90.0f, -45.0f, 0.0f, 1.0f,			// x amount of rotation, rotate x, y, z
		0.0f, 90.0f, 0.0f, 1.0f,			// y amount of rotation, rotate x, y, z
		0.0f, 0.0f, 0.0f, 1.0f,				// z amount of rotation, rotate x, y, z
		2.8f, -3.37807f, -2.8f,				// translate x, y, z aka move the shape
		1.0f, 1.0f
	};
	bkRgtLeg_gMesh.length = 2.0f;
	bkRgtLeg_gMesh.radius = 0.3f;
	bkRgtLeg_gMesh.number_of_sides = 128.0f;
	bkRgtLeg_gMesh.texFilename = "Textures/Vase/desk.jpg";
	Shapes::UBuildCylinder(bkRgtLeg_gMesh);
	scene.push_back(bkRgtLeg_gMesh);
	// Front Left Leg
	GLMesh frtLftLeg_gMesh;
	frtLftLeg_gMesh.p = {
		1.0f, 1.0f, 1.0f, 1.0f,				// color r, g, b a
		0.5f, 0.5f, -0.5f,				// scale x, y, z
		90.0f, -45.0f, 0.0f, 1.0f,			// x amount of rotation, rotate x, y, z
		0.0f, 90.0f, 0.0f, 1.0f,			// y amount of rotation, rotate x, y, z
		0.0f, 0.0f, 0.0f, 1.0f,				// z amount of rotation, rotate x, y, z
		-9.23017f, -3.44071f, 4.21922f,				// translate x, y, z aka move the shape
		1.0f, 1.0f
	};
	frtLftLeg_gMesh.length = 2.0f;
	frtLftLeg_gMesh.radius = 0.3f;
	frtLftLeg_gMesh.number_of_sides = 128.0f;
	frtLftLeg_gMesh.texFilename = "Textures/Vase/desk.jpg";
	Shapes::UBuildCylinder(frtLftLeg_gMesh);
	scene.push_back(frtLftLeg_gMesh);
	// Front Rigt Leg
	GLMesh frtRgtLeg_gMesh;
	frtRgtLeg_gMesh.p = {
		1.0f, 1.0f, 1.0f, 1.0f,				// color r, g, b a
		0.5f, 0.5f, -0.5f,				// scale x, y, z
		90.0f, -45.0f, 0.0f, 1.0f,			// x amount of rotation, rotate x, y, z
		0.0f, 90.0f, 0.0f, 1.0f,			// y amount of rotation, rotate x, y, z
		0.0f, 0.0f, 0.0f, 1.0f,				// z amount of rotation, rotate x, y, z
		2.8f, -3.44071f, 4.21922f,				// translate x, y, z aka move the shape
		1.0f, 1.0f
	};
	frtRgtLeg_gMesh.length = 2.0f;
	frtRgtLeg_gMesh.radius = 0.3f;
	frtRgtLeg_gMesh.number_of_sides = 128.0f;
	frtRgtLeg_gMesh.texFilename = "Textures/Vase/desk.jpg";
	Shapes::UBuildCylinder(frtRgtLeg_gMesh);
	scene.push_back(frtRgtLeg_gMesh);


	/*
	* Lamp
	*/
	// Lamp Body
	GLMesh lampBody_gMesh;
	lampBody_gMesh.p = {
		1.0f, 1.0f, 1.0f, 1.0f,				// color r, g, b a
		1.0f, 1.0f, 1.0f,				// scale x, y, z
		90.0f, -45.0f, 0.0f, 1.0f,			// x amount of rotation, rotate x, y, z
		0.0f, 90.0f, 0.0f, 1.0f,			// y amount of rotation, rotate x, y, z
		0.0f, 0.0f, 0.0f, 1.0f,				// z amount of rotation, rotate x, y, z
		-4.5f, -0.5f, 1.0f,				// translate x, y, z aka move the shape
		1.0f, 1.0f
	};
	lampBody_gMesh.length = 1.8f;
	lampBody_gMesh.radius = 0.6f;
	lampBody_gMesh.number_of_sides = 128.0f;
	lampBody_gMesh.texFilename = "Textures/Lamp/Lamp.jpeg";
	Shapes::UBuildCylinder(lampBody_gMesh);
	scene.push_back(lampBody_gMesh);
	// Lamp Neck
	GLMesh lampNeck_gMesh;
	lampNeck_gMesh.p = {
		0.6f, 0.6f, 0.6f, 1.0f,				// color r, g, b a
		0.5f, 0.5f, 0.5f,				// scale x, y, z
		90.0f, -45.0f, 0.0f, 1.0f,			// x amount of rotation, rotate x, y, z
		0.0f, 90.0f, 0.0f, 1.0f,			// y amount of rotation, rotate x, y, z
		0.0f, 0.0f, 0.0f, 1.0f,				// z amount of rotation, rotate x, y, z
		-4.3f, 1.0f, 0.75f,				// translate x, y, z aka move the shape
		1.0f, 1.0f
	};
	lampNeck_gMesh.length = 1.8f;
	lampNeck_gMesh.radius = 0.6f;
	lampNeck_gMesh.number_of_sides = 128.0f;
	lampNeck_gMesh.texFilename = "Textures/Lamp/Lamp.jpeg";
	Shapes::UBuildCylinder(lampNeck_gMesh);
	scene.push_back(lampNeck_gMesh);
	// Lamp Shade
	GLMesh lampShade_gMesh;
	lampShade_gMesh.p = {
		1.0f, 1.0f, 1.0f, 1.0f,				// color r, g, b a
		0.7f, 0.7f, 0.7f,				// scale x, y, z
		0.0f, 5.0f, 0.0f, 1.0f,			// x amount of rotation, rotate x, y, z
		0.0f, 90.0f, 0.0f, 1.0f,			// y amount of rotation, rotate x, y, z
		0.0f, 0.0f, 0.0f, 1.0f,				// z amount of rotation, rotate x, y, z
		-4.4f, 1.5f, 0.17f,				// translate x, y, z aka move the shape
		1.0f, 1.0f
	};
	lampShade_gMesh.height = 2.0f;
	lampShade_gMesh.length = 0.1f;
	lampShade_gMesh.radius = 1.5f;
	lampShade_gMesh.number_of_sides = 128.0f;
	lampShade_gMesh.texFilename = "Textures/Lamp/LampShade.jpg";
	Shapes::UBuildCone(lampShade_gMesh);
	scene.push_back(lampShade_gMesh);

	// Rug
	GLMesh rug_gMesh;
	rug_gMesh.p = {
		1.0f, 1.0f, 1.0f, 1.0f,				// color r, g, b a
		0.67f, 0.67f, 0.67f,				// scale x, y, z
		0.0f, 1.0f, 0.0f, 0.0f,				// x amount of rotation, rotate x, y, z
		0.0f, 0.0f, 1.0f, 0.0f,				// y amount of rotation, rotate x, y, z
		0.0f, 0.0f, 0.0f, 1.0f,				// z amount of rotation, rotate x, y, z
		-3.0f, -1.0f, 4.0f,				// translate x, y, z aka move the shape
		1.0f, 1.0f
	};
	rug_gMesh.texFilename = "Textures/WoolRug/WoolRug.jpg";
	Shapes::UBuildPlane(rug_gMesh);
	scene.push_back(rug_gMesh);


}


