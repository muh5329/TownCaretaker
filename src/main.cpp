#include <raylib.h>
#include <raymath.h>

int main()
{
	InitWindow(400, 224, "Template-4.0.0");
	
	while (!WindowShouldClose()) {
        	BeginDrawing();
            	ClearBackground(RAYWHITE);
    
        	EndDrawing();
    	}
   	 CloseWindow();
   	 return 0;
}