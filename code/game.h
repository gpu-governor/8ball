typedef struct{
	int x;
	int y;
	Texture2D texture;
	float scale;
	char * file_path;
}Asset;



// =============================FUNCTION Implementation ======================================


void init(int w, int h){
	InitWindow(w, h, "8ball pool game");
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
