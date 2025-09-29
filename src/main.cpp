#include <raylib.h>
#include <raymath.h>

// Draw capsule (approx) using rays - draw cylinder and spheres on ends
void DrawCapsule(const Vector3 &pos, float radius, float length, Color color) {
    
    DrawCylinderWires({pos.x, pos.y - length/2.0f, pos.z}, radius, radius, length, 16, DARKGRAY);
    DrawCylinder({pos.x, pos.y, pos.z}, radius, radius, length, 16, color);
    DrawSphere({pos.x, pos.y + length, pos.z}, radius, color);
    DrawSphere({pos.x, pos.y - length/2.0f, pos.z}, radius, color);
}

int main()
{
	InitWindow(400, 224, "Template-4.0.0");
	
	// Create a player capsule
	float playerRadius = 0.4;
	float playerLength = 1.2f; // Cylinder length
	Vector3 playerPosition = { 0.0f, 1.0f, 0.0f };

	// Raylib Camera (3rd person setup)
	Camera camera =	{ 0 };
	camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };
	camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
	camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
	camera.fovy = 45.0f;
	camera.projection = CAMERA_PERSPECTIVE;		

	while (!WindowShouldClose()) {
        	
	 
	    // -- Rendering --	
		BeginDrawing();
		ClearBackground(RAYWHITE);

		BeginMode3D(camera);	

		// Sample Plane
		DrawPlane((Vector3){ 0.0f, 0.0f, 0.0f }, (Vector2){ 10.0f, 10.0f }, LIGHTGRAY);
		DrawGrid(20, 1.0f);

		// Draw player capsule
		DrawCapsule(playerPosition, playerRadius, playerLength , RED);

		EndDrawing();
	}
   	 CloseWindow();
   	 return 0;
}