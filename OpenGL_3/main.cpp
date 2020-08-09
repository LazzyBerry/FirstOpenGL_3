#include <gl/glut.h>
#include <iostream>

//外部変数
int status = 0; //ボタンの状態


//各種コールバック関数

//ディスプレイ
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

//ボタンを押すイベントの登録と、マウスの左ボタンにだけ反応させる処理
void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		printf("(%d,%d)で左ボタンが押されました\n", x, y);
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) 
	{
		printf("(%d,%d)で左ボタンを離しました\n", x, y);
	}
}

//ドラッグ時
void dragMotion(int x, int y)
{
	printf("DragMotion ! @ (%d,%d)\n", x, y);
}

//ボタンを押さずマウス移動している際に呼び出される関数
void passiveMotion(int x, int y)
{
	printf("Passive Motion ! @ (%d,%d)\n", x, y);
}

//キーボード処理（押したとき）
void keyboard(unsigned char key, int x, int y)
{
	printf("%c が押されました @ (%d, %d)\n", key, x, y);

	//ESCキーの時
	if (key == 27) {
		puts("Exit...");
		exit(0);
	}

}

//キーボード処理（押したとき）
void keyboardUp(unsigned char key, int x, int y)
{
	printf("%c が離されました @ (%d, %d)\n", key, x, y);
}

//特殊キーを押したとき
void specialKey(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		printf("[←]が押されました @ (%d,%d)\n", x, y);
		break;
	case GLUT_KEY_UP:
		printf("[↑]が押されました @ (%d,%d)\n", x, y);
		break;
	case GLUT_KEY_RIGHT:
		printf("[→]が押されました @ (%d,%d)\n", x, y);
		break;
	case GLUT_KEY_DOWN:
		printf("[↓]が押されました @ (%d,%d)\n", x, y);
		break;
	}
}

//特殊キーを離したとき
void specialUpKey(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		printf("[←]が離れました @ (%d,%d)\n", x, y);
		break;
	case GLUT_KEY_UP:
		printf("[↑]が離れました @ (%d,%d)\n", x, y);
		break;
	case GLUT_KEY_RIGHT:
		printf("[→]が離れました @ (%d,%d)\n", x, y);
		break;
	case GLUT_KEY_DOWN:
		printf("[↓]が離れました @ (%d,%d)\n", x, y);
		break;
	}
}

//メイン関数

int main(int argc, char* argv[])
{
	glutInit(&argc, argv); //GLUTの初期化

	//Windowの作成
	//glutInitWindowSize(640, 480);
	glutInitWindowSize(400, 400);
	glutInitDisplayMode(GLUT_RGBA); //ディスプレイモード
	glutCreateWindow("Mouse And Keyboard");

	//コールバック関数登録
	glutDisplayFunc(display);

	//マウスアクションのコールバック関数登録
	//glutMouseFunc(mouse);
	//glutMotionFunc(dragMotion);
	//glutPassiveMotionFunc(passiveMotion);

	//キーボードアクションのコールバック関数登録
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyboardUp);
	glutSpecialFunc(specialKey);
	glutSpecialUpFunc(specialUpKey);
	glutIgnoreKeyRepeat(GL_TRUE); //キーリピート無視

	//カラーバッファの初期化
	glClearColor(1.f, 1.f, 1.f, 1.f);

	glutMainLoop(); //メインループへ

	return 0;
}