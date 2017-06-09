#pragma warning(disable:4996)
//#include"drawCharacters.h"
#include"parameterCal.h"
#include"funcAdd.h"


void Init()//窗口以及视野初始化
{
	//glClearColor(0.3f, 0.3f ,0.45f, 0.0f);
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	
	glLoadIdentity();

	guideWords();
	funcSelection();
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glLineWidth(10.0f);

	AntiAliasingFunc();//抗锯齿算法需要放入glut回调函数才能生效
	if (PWMSwitch == STANDARD_INPUT)
	{
		goStart();
		coordinateDrawer();
		grab();
	}

	if (PWMSwitch == PWMMATRIX_INPUT)
	{
		goStartWithPWM();
		coordinateDrawerPWM();
		grab();
	}
		

	glFlush();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_MULTISAMPLE);

	glutInitWindowPosition(0,100);
	glutInitWindowSize(WindowWidth, WindowHeight);
	
	glutCreateWindow("Biological Consensus Sequences LOGO Generator");

	Init();

	glutDisplayFunc(&myDisplay);
	glutMainLoop();

	return 0;

}