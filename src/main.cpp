#include <raylib.h>
#include <raymath.h>
#include "Systems/camera.cpp"


class Game {
	private:
		RtsCamera camera;	
		float playerRadius = 0.4;
		float playerLength = 1.2f; // Cylinder length
		Vector3 playerPosition = { 0.0f, 1.0f, 0.0f };
	public:
		Game(){
			InitWindow(400, 224, "Town Caretaker");
	
			// Create a player capsule
			playerRadius = 0.4f;
			playerLength = 1.2f; // Cylinder length
			playerPosition = { 0.0f, 1.0f, 0.0f };

		}
		~Game(){
			CloseWindow();
		}

		void Run(){
			while (!WindowShouldClose()) {
				float deltaTime = GetFrameTime();
				//HandleInput();
				Update(deltaTime);
				Draw();
			}
		}
	private:
		// Draw capsule (approx) using rays - draw cylinder and spheres on ends
		void DrawCapsule(const Vector3 &pos, float radius, float length, Color color) {
			
			DrawCylinderWires({pos.x, pos.y - length/2.0f, pos.z}, radius, radius, length, 16, DARKGRAY);
			DrawCylinder({pos.x, pos.y, pos.z}, radius, radius, length, 16, color);
			DrawSphere({pos.x, pos.y + length, pos.z}, radius, color);
			DrawSphere({pos.x, pos.y - length/2.0f, pos.z}, radius, color);
		}

		void Update(float deltaTime) {
			// Update camera
			camera.Update();
		}


		void Draw(){
			// -- Rendering --	
			BeginDrawing();
			ClearBackground(RAYWHITE);

			BeginMode3D(camera);	

			// Sample Plane
			DrawPlane((Vector3){ 0.0f, 0.0f, 0.0f }, (Vector2){ 10.0f, 10.0f }, LIGHTGRAY);
			DrawGrid(20, 1.0f);

			// Draw player capsule
			DrawCapsule(playerPosition, playerRadius, playerLength , RED);

			// End 3D mode
			EndMode3D();

			EndDrawing();
		}


};





int main()
{
	Game game;
    game.Run();
	return 0;
}