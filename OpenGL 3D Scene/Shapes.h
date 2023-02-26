#pragma once
#include "Mesh.h"

using namespace std;

// Class definition for Vase
class Shapes
{
public:
	// Build a diamond shape and store the information in the provided GLMesh object
	static void UBuildDimond(GLMesh& mesh);

	// Build a cube shape and store the information in the provided GLMesh object
	static void UBuildCube(GLMesh& mesh);

	// Build a cone shape and store the information in the provided GLMesh object
	static void UBuildCone(GLMesh& mesh);

	// Build a cylinder shape and store the information in the provided GLMesh object
	static void UBuildCylinder(GLMesh& mesh);

	// Build a plane shape and store the information in the provided GLMesh object
	static void UBuildPlane(GLMesh& mesh);

	// Apply translation on the provided GLMesh object
	static void UTranslator(GLMesh& mesh);

};

