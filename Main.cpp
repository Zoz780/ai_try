#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include <stdlib.h>
#include <time.h> 
#include <GLUT.h>
using namespace std;

int m_screen_width = 1280;
int m_screen_hight = 720;
bool go_forward = false;
bool go_backward = false;
bool go_right = false;
bool go_left = false;


Player player;
Enemy enemy[5];

static void resize(int width, int height)    
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, height, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);

}

void timer(int) {
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer, 0);
	float posx, posy;

	for (int i = 0; i < 5; i++)
	{
		enemy[i].FollowPlayer();
	}

	if (go_forward)
	{
		posy = player.GetPosY();
		posy -= 5.0f;
		player.SetPosY(posy);
	}
	if (go_backward)
	{
		posy = player.GetPosY();
		posy += 5.0f;
		player.SetPosY(posy);
	}
	if (go_left)
	{
		posx = player.GetPosX();
		posx -= 5.0f;
		player.SetPosX(posx);
	}
	if (go_right)
	{
		posx = player.GetPosX();
		posx += 5.0f;
		player.SetPosX(posx);
	}

}

static void display(void)              
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glLoadIdentity();
	glDisable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);

	srand(time(NULL));
	float posx = rand() % 1270 + 5;
	float posy = rand() % 710 + 5;

	for (int i = 0; i < 5; i++)
	{
		enemy[i].Draw();
		enemy[i].SetDestinaiton(player.GetPosX(), player.GetPosY());
	}
	player.Draw();

	glPopMatrix();

	glutSwapBuffers();                

}

static void key(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
		go_forward = true;
		break;
	case 's':
		go_backward = true;
		break;
	case 'a':
		go_left = true;
		break;
	case 'd':
		go_right = true;
		break;
	}

	glutPostRedisplay();          
}

static void keyup(unsigned char key, int x, int y)
{
	float posx, posy;
	switch (key)
	{
	case 'w':
		go_forward = false;
		break;
	case 's':
		go_backward = false;
		break;
	case 'a':
		go_left = false;
		break;
	case 'd':
		go_right = false;
		break;
	}

	glutPostRedisplay();
}


void Init()
{
	srand(time(NULL));
	float posx, posy;

	for (int i = 0; i < 5; i++)
	{
		posx = rand() % 1270 + 5;
		posy = rand() % 710 + 5;
		enemy[i].SetPosX(posx);
		enemy[i].SetPosY(posy);
	}
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(m_screen_width, m_screen_hight);                
	glutInitWindowPosition(100, 100);             
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_ALPHA);

	glutCreateWindow("MI try");
	Init();


	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutKeyboardFunc(key);
	glutKeyboardUpFunc(keyup);
	glutTimerFunc(0, timer, 0);

	glClearColor(0.0, 0.0, 0.0, 1);                 

	glutMainLoop();

	return 0;
}