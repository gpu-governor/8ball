#include"raylib.h"
#include<stdio.h>
#include"game.h"
const int width = 1150;
const int height = 720;
#define BALL_COUNT 17
#define ROW_SPACING 40
#define BALL_SPACING 40

// =============================MAIN FUNCTION ======================================

int main(){
	init(width,height);
	Asset table = load_asset("Assets/table.png", 20,20,0.24f);
	Asset cue = load_asset("Assets/cue.png", 150, 150, 0.2f);
	Asset triangle = load_asset("Assets/triangle.png", 400, 150, 0.2f);
	// balls
	Asset balls[BALL_COUNT];

	int offsetX =250;
	int offsetY = 300;

	int ballIndex = 1;

	for (int row =5; row>=1; row--){
		int ballsInRow =row;
		int startY = offsetY - (BALL_SPACING * (ballsInRow -1))/2; // centers each row vertically
		int x = offsetX + ROW_SPACING * (5 - row); 
		for (int i = 0; i <ballsInRow; i++){
			int y = startY+ i * BALL_SPACING;

			// create filename
			char filename[50];
			sprintf(filename,"Assets/ball_%d.png",ballIndex);

			// load asset function
			balls[ballIndex]= load_asset(filename, x, y, 0.3f);

			ballIndex++;
		}
		
	}

	// white ball
	balls[16] = load_asset("Assets/ball_16.png", 800,300, 0.3f);

	// collision rectangles walls
	Rectangle topleft = {110,20, 420, 70};
	Rectangle topright = {600,20, 420, 70};
	Rectangle bottomleft = {110,567, 420, 70};
	Rectangle bottomright = {600,567, 420, 70};	
	Rectangle sideright = {20,110, 70, 420};
	Rectangle sideleft = {1040,110,70,420};

	// collisions rectangles pockets hole
	Rectangle topleftpocket = {20,20,80,80};
	Rectangle toprightpocket = {1040,20,80,80};
	Rectangle topmidpocket = {520,20,80,80};
	Rectangle bottomleftpocket = {20,567,80,80};
	Rectangle bottomrightpocket = {1040,567,80,80};
	Rectangle bottommidpocket = {520,567,80,80};
		
	while(!WindowShouldClose()){
		BeginDrawing();
		ClearBackground(RAYWHITE);
		 render_asset(table);
		 render_asset(cue);
		 
		 for (int i= 0; i< BALL_COUNT; i++){
		 	render_asset(balls[i]);
		 }

		
		// // walls
		//  DrawRectangleRec(topleft,BLUE);
		//  DrawRectangleRec(topright,BLUE);
		//  DrawRectangleRec(bottomright,BLUE);
		//  DrawRectangleRec(bottomleft,BLUE);
		//  DrawRectangleRec(sideleft,BLUE);
		//  DrawRectangleRec(sideright,BLUE);
		//  // pockets
		//  DrawRectangleRec(topleftpocket,RED);
		//  DrawRectangleRec(toprightpocket,RED);
		//  DrawRectangleRec(topmidpocket,RED);
		//  DrawRectangleRec(bottomleftpocket,RED);
		//  DrawRectangleRec(bottomrightpocket,RED);
		//  DrawRectangleRec(bottommidpocket,RED);
		// TODO GAME LOGIC
		EndDrawing();
	}
	// cleanup 
	for (int i= 0; i <BALL_COUNT; i++){
		UnloadTexture(balls[i].texture);
	}
	UnloadTexture(table.texture);
	UnloadTexture(cue.texture);
	UnloadTexture(triangle.texture);
	quit();
	return 0;
}
