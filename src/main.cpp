#include <raylib.h>
#include <raymath.h>

int main()
{
	InitWindow(400, 224, "Template-4.0.0");
	
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

		EndDrawing();
	}
   	 CloseWindow();
   	 return 0;
}