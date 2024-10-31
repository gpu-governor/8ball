#include"raylib.h"
#include<stdio.h>
// ============================= Global variables  ======================================

const int width = 800;
const int height = 600;
#define BALL_COUNT 16

typedef struct{
	int x;
	int y;
	Texture2D texture;
	float scale;
	char * file_path;
}Asset;


void init();
void quit();
Asset load_asset(char * file_path, int x, int y, float scale);
void render_asset(Asset new_asset);
// =============================MAIN FUNCTION ======================================

int main(){
	init();
	Asset table = load_asset("Assets/table.png", 0,0,0.13f);
	Asset cue = load_asset("Assets/cue.png", 150, 150, 0.2f);
	Asset triangle = load_asset("Assets/triangle.png", 400, 150, 0.2f);

	// balls
	Asset balls[BALL_COUNT];

	// char filepath[32];
// 
// 	for (int i = 0; i <BALL_COUNT; i++){
// 		sprintf(filepath, "Assets/ball_%d.png", i+1);
// 		balls[i] = load_asset(filepath, 0,0,0.2f);
// 	}

	balls[1] = load_asset("Assets/ball_1.png", 0, 50, 0.2f);
	balls[2] = load_asset("Assets/ball_2.png", 10, 50, 0.2f);
	balls[3] = load_asset("Assets/ball_3.png", 20, 50, 0.2f);
	balls[4] = load_asset("Assets/ball_4.png", 30, 50, 0.2f);
	balls[5] = load_asset("Assets/ball_5.png", 40, 50, 0.2f);
	balls[6] = load_asset("Assets/ball_6.png", 50, 50, 0.2f);
	balls[7] = load_asset("Assets/ball_7.png", 60, 50, 0.2f);
	
	while(!WindowShouldClose()){
		BeginDrawing();
		ClearBackground(RAYWHITE);
		 render_asset(table);
		 render_asset(cue);
		 render_asset(triangle);
		 for (int i= 0; i< BALL_COUNT; i++){
		 	render_asset(balls[i]);
		 }
		// TODO GAME LOGIC
		EndDrawing();
	}

	for (int i= 0; i <BALL_COUNT; i++){
		UnloadTexture(balls[i].texture);
	}
	UnloadTexture(table.texture);
	UnloadTexture(cue.texture);
	UnloadTexture(triangle.texture);
	quit();
	return 0;
}

// =============================FUNCTION Implementation ======================================


void init(){
	InitWindow(width, height, "8ball pool game");
		SetTargetFPS(60);
}
void quit(){
	CloseWindow();
	// TODO unload assets
}

Asset load_asset(char * file_path, int x, int y, float scale){
	Asset new_asset;
	new_asset.file_path = file_path;
	new_asset.x = x;
	new_asset.y= y;
	new_asset.scale = scale;
	new_asset.texture= LoadTexture(file_path);
	return new_asset;
}

void render_asset(Asset new_asset){
	float scale = new_asset.scale;
	Rectangle src = {0,0, new_asset.texture.width,new_asset.texture.height};
	Rectangle dst = {new_asset.x,new_asset.y, new_asset.texture.width * scale,new_asset.texture.height*scale};
	Vector2 origin ={0,0};
	double rotation = 0.0f;
	DrawTexturePro(new_asset.texture, src, dst, origin, rotation, WHITE);
}
