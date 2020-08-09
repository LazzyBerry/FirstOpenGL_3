#include <gl/glut.h>
#include <iostream>

//�O���ϐ�
int status = 0; //�{�^���̏��


//�e��R�[���o�b�N�֐�

//�f�B�X�v���C
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

//�{�^���������C�x���g�̓o�^�ƁA�}�E�X�̍��{�^���ɂ������������鏈��
void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		printf("(%d,%d)�ō��{�^����������܂���\n", x, y);
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) 
	{
		printf("(%d,%d)�ō��{�^���𗣂��܂���\n", x, y);
	}
}

//�h���b�O��
void dragMotion(int x, int y)
{
	printf("DragMotion ! @ (%d,%d)\n", x, y);
}

//�{�^�����������}�E�X�ړ����Ă���ۂɌĂяo�����֐�
void passiveMotion(int x, int y)
{
	printf("Passive Motion ! @ (%d,%d)\n", x, y);
}

//�L�[�{�[�h�����i�������Ƃ��j
void keyboard(unsigned char key, int x, int y)
{
	printf("%c ��������܂��� @ (%d, %d)\n", key, x, y);

	//ESC�L�[�̎�
	if (key == 27) {
		puts("Exit...");
		exit(0);
	}

}

//�L�[�{�[�h�����i�������Ƃ��j
void keyboardUp(unsigned char key, int x, int y)
{
	printf("%c ��������܂��� @ (%d, %d)\n", key, x, y);
}

//����L�[���������Ƃ�
void specialKey(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		printf("[��]��������܂��� @ (%d,%d)\n", x, y);
		break;
	case GLUT_KEY_UP:
		printf("[��]��������܂��� @ (%d,%d)\n", x, y);
		break;
	case GLUT_KEY_RIGHT:
		printf("[��]��������܂��� @ (%d,%d)\n", x, y);
		break;
	case GLUT_KEY_DOWN:
		printf("[��]��������܂��� @ (%d,%d)\n", x, y);
		break;
	}
}

//����L�[�𗣂����Ƃ�
void specialUpKey(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		printf("[��]������܂��� @ (%d,%d)\n", x, y);
		break;
	case GLUT_KEY_UP:
		printf("[��]������܂��� @ (%d,%d)\n", x, y);
		break;
	case GLUT_KEY_RIGHT:
		printf("[��]������܂��� @ (%d,%d)\n", x, y);
		break;
	case GLUT_KEY_DOWN:
		printf("[��]������܂��� @ (%d,%d)\n", x, y);
		break;
	}
}

//���C���֐�

int main(int argc, char* argv[])
{
	glutInit(&argc, argv); //GLUT�̏�����

	//Window�̍쐬
	//glutInitWindowSize(640, 480);
	glutInitWindowSize(400, 400);
	glutInitDisplayMode(GLUT_RGBA); //�f�B�X�v���C���[�h
	glutCreateWindow("Mouse And Keyboard");

	//�R�[���o�b�N�֐��o�^
	glutDisplayFunc(display);

	//�}�E�X�A�N�V�����̃R�[���o�b�N�֐��o�^
	//glutMouseFunc(mouse);
	//glutMotionFunc(dragMotion);
	//glutPassiveMotionFunc(passiveMotion);

	//�L�[�{�[�h�A�N�V�����̃R�[���o�b�N�֐��o�^
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyboardUp);
	glutSpecialFunc(specialKey);
	glutSpecialUpFunc(specialUpKey);
	glutIgnoreKeyRepeat(GL_TRUE); //�L�[���s�[�g����

	//�J���[�o�b�t�@�̏�����
	glClearColor(1.f, 1.f, 1.f, 1.f);

	glutMainLoop(); //���C�����[�v��

	return 0;
}