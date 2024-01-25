#include <Novice.h>
const char kWindowTitle[] = "LC1D_07_スガワラ_オオスケ_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 800, 900);

	// マップのサイズ

	enum sean {
		TITLE,
		STAGE1,
		STAGE2,
		STAGE3,
		STAGE4,
		STAGE5,
		GAMEOVER,
		GAMECLEAR,
	};

	int SeanCount = 0;

	int a = 0;
	int b = 0;
	int c = 0;

	//アニメーション
	//int time = 0;
	//int playerAnimCount = 0;


	a = Novice::LoadTexture("./re/oke.png");
	b = Novice::LoadTexture("./re/renga.png");
	int FrontgrapHandle[6] = { 0 };
	FrontgrapHandle[0] = Novice::LoadTexture("./re/temae1.png");
	FrontgrapHandle[1] = Novice::LoadTexture("./re/temae2.png");
	FrontgrapHandle[2] = Novice::LoadTexture("./re/temae3.png");
	FrontgrapHandle[3] = Novice::LoadTexture("./re/temae4.png");
	FrontgrapHandle[4] = Novice::LoadTexture("./re/temae5.png");
	FrontgrapHandle[5] = Novice::LoadTexture("./re/temae6.png");


	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	//変数

	

	int map[15][25] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	};

	int px = 64;
	int py = 128;
	int playeroldx = 0;
	int playeroldy = 0;

	

	int oldLeftTopx = 0;
	int oldLeftTopy = 0;

	int oldRightTopx = 0;
	int oldRightTopy = 0;

	int oldLeftBottomx = 0;
	int oldLeftBottomy = 0;

	int oldRightBottomx = 0;
	int oldRightBottomy = 0;
		
	int playerLeftTopx = px - 16;
	int playerLeftTopy = py - 32;

	int playerRightTopx = px + 16;
	int playerRightTopy = py - 32;

	int playerLeftBottomx = px - 16;
	int playerLeftBottomy = py + 32;

	int playerRightBottomx = px + 16;
	int playerRightBottomy = py + 32;

	int  MapChipSize = 32;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);


		switch (SeanCount) {


		case TITLE:
			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				SeanCount += 1;
			}

			///デバッグ用
			Novice::ScreenPrintf(0, 500, "seancount = %d", SeanCount);

			break;
		case STAGE1:

           

			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				SeanCount += 1;
			}

			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
				SeanCount += 5;
			}

            playeroldx = px;
			playeroldy = py;
			
			playerLeftTopx = px / MapChipSize;
			playerLeftTopy = py / MapChipSize;

			playerRightTopx = (px + MapChipSize - 1) / MapChipSize;
			playerRightTopy = py / MapChipSize;

			playerLeftBottomx = px / MapChipSize;
			playerLeftBottomy = (py + MapChipSize - 1) / MapChipSize;

			playerRightBottomx = (px + MapChipSize - 1) / MapChipSize;
			playerRightBottomy = (py + MapChipSize - 1) / MapChipSize;


		    oldLeftTopx = playeroldx / 32;
			oldLeftTopy = playeroldy / 32;

			oldRightTopx = (playeroldx + 32 - 1) / 32;
			oldRightTopy = playeroldy / 32;

			oldLeftBottomx = playeroldx / 32;
			oldLeftBottomy = (playeroldy + 32 - 1) / 32;

			oldRightBottomx = (playeroldx + 32 - 1) / 32;
			oldRightBottomy = (playeroldy + 32 - 1) / 32;





			if (keys[DIK_W] != 0) {
				py -= 2;
			}
			if (keys[DIK_S] != 0) {
				py += 2;
			}
			if (keys[DIK_A] != 0) {
				px -= 2;
			}
			if (keys[DIK_D] != 0) {
				px += 2;
			}



			


			if(map[playerLeftTopy][playerLeftTopx] == 1 ) {
              playerLeftTopx = oldLeftTopx;
			  playerLeftTopy = oldLeftTopy;
			}

			if (map[playerRightTopy][playerRightTopx] == 1) {
				playerRightTopx = oldRightTopx;
				playerRightTopy = oldRightTopy;
			}

			if (map[playerLeftBottomy][playerLeftBottomx] == 1) {
				playerLeftBottomx = oldLeftBottomx;
				playerLeftBottomy = oldLeftBottomy;
			}

			if (map[playerRightBottomy][playerRightBottomx] == 1) {
				playerRightBottomx = oldRightBottomx;
				playerRightBottomy = oldRightBottomy;
			}
			
			




			/*----------------------------------------------*/



			for (int y = 0; y < 15; y++) {
				for (int x = 0; x < 25; x++) {
					int cell = map[y][x];
					if (cell == 1) {
						Novice::DrawSprite(x * 32, y * 32, b, 1, 1, 0.0f, WHITE);
					}
				}
			}

			Novice::DrawQuad(playerLeftTopx, playerLeftTopy,
				playerRightTopx, playerRightTopy,
				playerLeftBottomx, playerLeftBottomy,
				playerRightBottomx, playerRightBottomy,
				0, 0,
				32, 64,
				FrontgrapHandle[0],
				WHITE);

			Novice::ScreenPrintf(0, 820, "current map: map[%d][%d]", py / 32, px / 32);

			///デバッグ用
			Novice::ScreenPrintf(0, 500, "seancount = %d", SeanCount);
			break;
		case STAGE2:

			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				SeanCount += 1;
			}

			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
				SeanCount += 4;
			}

			/*移動処理、当たり判定の処理*/
			playeroldx = px;
			playeroldy = py;

			oldLeftTopx = playeroldx / 32;
			oldLeftTopy = playeroldy / 64;

			oldRightTopx = (playeroldx + 32 - 1) / 32;
			oldRightTopy = playeroldy / 64;

			oldLeftBottomx = playeroldx / 32;
			oldLeftBottomy = (playeroldy + 64 - 1) / 64;

			oldRightBottomx = (playeroldx + 32 - 1) / 32;
			oldRightBottomy = (playeroldy + 64 - 1) / 64;


			if (preKeys[DIK_W] == 0 && keys[DIK_W] != 0) {
				py -= 32;
			}
			if (preKeys[DIK_S] == 0 && keys[DIK_S] != 0) {
				py += 32;
			}
			if (preKeys[DIK_A] == 0 && keys[DIK_A] != 0) {
				px -= 32;
			}
			if (preKeys[DIK_D] == 0 && keys[DIK_D] != 0) {
				px += 32;
			}


			/*----------------------------------------------*/

			for (int y = 0; y < 15; y++) {
				for (int x = 0; x < 25; x++) {
					int cell = map[y][x];
					if (cell == 1) {
						Novice::DrawSprite(x * 32, y * 32, b, 1, 1, 0.0f, WHITE);
					}
				}
			}

			Novice::DrawSprite(px, py, c, 1, 1, 0.0f, WHITE);

			Novice::ScreenPrintf(0, 820, "current map: map[%d][%d]", py / 32, px / 32);
			///デバッグ用
			Novice::ScreenPrintf(0, 500, "seancount = %d", SeanCount);

			break;
		case STAGE3:

			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				SeanCount += 1;
			}

			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
				SeanCount += 3;
			}

			/*移動処理、当たり判定の処理*/
			playeroldx = px;
			playeroldy = py;

			oldLeftTopx = playeroldx / 32;
			oldLeftTopy = playeroldy / 64;

			oldRightTopx = (playeroldx + 32 - 1) / 32;
			oldRightTopy = playeroldy / 64;

			oldLeftBottomx = playeroldx / 32;
			oldLeftBottomy = (playeroldy + 64 - 1) / 64;

			oldRightBottomx = (playeroldx + 32 - 1) / 32;
			oldRightBottomy = (playeroldy + 64 - 1) / 64;


			if (preKeys[DIK_W] == 0 && keys[DIK_W] != 0) {
				py -= 32;

			}
			if (preKeys[DIK_S] == 0 && keys[DIK_S] != 0) {
				py += 32;
			}
			if (preKeys[DIK_A] == 0 && keys[DIK_A] != 0) {
				px -= 32;
			}
			if (preKeys[DIK_D] == 0 && keys[DIK_D] != 0) {
				px += 32;
			}

			

			/*------------------------------------------*/

			for (int y = 0; y < 15; y++) {
				for (int x = 0; x < 25; x++) {
					int cell = map[y][x];
					if (cell == 1) {
						Novice::DrawSprite(x * 32, y * 32, b, 1, 1, 0.0f, WHITE);
					}
				}
			}



			Novice::DrawSprite(px, py, c, 1, 1, 0.0f, WHITE);

			Novice::ScreenPrintf(0, 820, "current map: map[%d][%d]", py / 32, px / 32);

			///デバッグ用
			Novice::ScreenPrintf(0, 500, "seancount = %d", SeanCount);

			break;
		case STAGE4:

			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				SeanCount += 1;
			}

			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
				SeanCount += 2;
			}


			/*移動処理、当たり判定の処理*/
			playeroldx = px;
			playeroldy = py;

			oldLeftTopx = playeroldx / 32;
			oldLeftTopy = playeroldy / 64;

			oldRightTopx = (playeroldx + 32 - 1) / 32;
			oldRightTopy = playeroldy / 64;

			oldLeftBottomx = playeroldx / 32;
			oldLeftBottomy = (playeroldy + 64 - 1) / 64;

			oldRightBottomx = (playeroldx + 32 - 1) / 32;
			oldRightBottomy = (playeroldy + 64 - 1) / 64;


			if (preKeys[DIK_W] == 0 && keys[DIK_W] != 0) {
				py -= 32;

			}
			if (preKeys[DIK_S] == 0 && keys[DIK_S] != 0) {
				py += 32;
			}
			if (preKeys[DIK_A] == 0 && keys[DIK_A] != 0) {
				px -= 32;
			}
			if (preKeys[DIK_D] == 0 && keys[DIK_D] != 0) {
				px += 32;
			}

		

			/*-----------------------------------------------*/

			for (int y = 0; y < 15; y++) {
				for (int x = 0; x < 25; x++) {
					int cell = map[y][x];
					if (cell == 1) {
						Novice::DrawSprite(x * 32, y * 32, b, 1, 1, 0.0f, WHITE);
					}
				}
			}

			Novice::DrawSprite(px, py, c, 1, 1, 0.0f, WHITE);

			Novice::ScreenPrintf(0, 820, "current map: map[%d][%d]", py / 32, px / 32);
			///デバッグ用
			Novice::ScreenPrintf(0, 500, "seancount = %d", SeanCount);

			break;
		case STAGE5:

			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				SeanCount += 2;
			}

			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
				SeanCount += 1;
			}

			/*移動処理、当たり判定の処理*/
			playeroldx = px;
			playeroldy = py;

			oldLeftTopx = playeroldx / 32;
			oldLeftTopy = playeroldy / 64;

			oldRightTopx = (playeroldx + 32 - 1) / 32;
			oldRightTopy = playeroldy / 64;

			oldLeftBottomx = playeroldx / 32;
			oldLeftBottomy = (playeroldy + 64 - 1) / 64;

			oldRightBottomx = (playeroldx + 32 - 1) / 32;
			oldRightBottomy = (playeroldy + 64 - 1) / 64;


			if (preKeys[DIK_W] == 0 && keys[DIK_W] != 0) {
				py -= 32;

			}
			if (preKeys[DIK_S] == 0 && keys[DIK_S] != 0) {
				py += 32;
			}
			if (preKeys[DIK_A] == 0 && keys[DIK_A] != 0) {
				px -= 32;
			}
			if (preKeys[DIK_D] == 0 && keys[DIK_D] != 0) {
				px += 32;
			}

			
			/*----------------------------------------*/

			for (int y = 0; y < 15; y++) {
				for (int x = 0; x < 25; x++) {
					int cell = map[y][x];
					if (cell == 1) {
						Novice::DrawSprite(x * 32, y * 32, b, 1, 1, 0.0f, WHITE);
					}
				}
			}

			Novice::DrawSprite(px, py, c, 1, 1, 0.0f, WHITE);

			Novice::ScreenPrintf(0, 820, "current map: map[%d][%d]", py / 32, px / 32);
			///デバッグ用
			Novice::ScreenPrintf(0, 500, "seancount = %d", SeanCount);

			break;
		case GAMEOVER:

			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				SeanCount = 0;
			}

			///デバッグ用
			Novice::ScreenPrintf(0, 500, "seancount = %d", SeanCount);
			break;
		case GAMECLEAR:

			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				SeanCount = 0;
			}

			///デバッグ用
			Novice::ScreenPrintf(0, 500, "seancount = %d", SeanCount);
			break;
		}
		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
