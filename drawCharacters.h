#ifndef  _DRAWCHARACTERS_H_
#define _DRAWCHARACTERS_H_

#include<stdlib.h>
#include<stdio.h>
#include<GL\glut.h>
#include<math.h>
#include<string.h>
#include<GL\GL.h>

#define WindowWidth 500//HORIZEN_LENTH 
#define WindowHeight 300//HORIZEN_HEIGHT 

#define HORIZEN_LENTH (lenthOfSeq * PIXEL_LENTH)
#define HORIZEN_HEIGHT (standardHeight * PIXEL_HEIGHT)//(heightOfSeq * PIXEL_HEIGHT * 3)

#define SMALLER_VAL 6
#define SMALLER_VAL_PWM 1.3

#define PIXEL_HEIGHT 100.0
#define PIXEL_LENTH 80.0

#define KIND_OF_BASE 4

#define STANDARD_INPUT 0
#define PWMMATRIX_INPUT 1

#define PWM_SOURCE 0
#define STA_SOURCE 1

#define BMP_Header_Length 54 

int PWMSwitch = 0;

int lenthOfPWM = 0;
int lenthOfSeq = 0;
int heightOfSeq = 4;
//Ϊ�˱�֤��PWMģʽ�»�ͼ�����ܹ�����ȷ�����ţ����� heightOfSeq ����Ϊ������������

double **PWMMatrixMessage = NULL;
char **sequenceMessage = NULL;

GLfloat standardHeight = 0;
GLfloat standardLenth = 0;

void setRespawn()     //�����Ӵ���ʼ������
{
	glLoadIdentity();
	gluOrtho2D(-20, HORIZEN_LENTH + 30, -10, HORIZEN_HEIGHT);
}

//A:green  T:red   G:yellow   C:blue
void drawCharacterA(GLfloat heightOfCharacterA, GLfloat pos_X, GLfloat pos_Y)
{
	char TEMP_CHA = 'A';

	setRespawn();
	glTranslated(pos_X, pos_Y, 0.0);
	glScaled(1.0, heightOfCharacterA, 1.0);
	glColor3f(0.0f, 1.0f, 0.0f);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, TEMP_CHA);
	glScaled(1.0, 1 / heightOfCharacterA, 1.0); //��ԭ����ϵ
}

//draw character T(red)
void drawCharacterT(GLfloat heightOfCharacterT, GLfloat pos_X, GLfloat pos_Y)
{
	char TEMP_CHA = 'T';

	setRespawn();
	glTranslated(pos_X+5, pos_Y, 0.0);
	glScaled(1.0, heightOfCharacterT, 1.0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, TEMP_CHA);
	glScaled(1.0, 1 / heightOfCharacterT, 1.0); //��ԭ����ϵ
}

//draw character G
void drawCharacterG(GLfloat heightOfCharacterG, GLfloat pos_X, GLfloat pos_Y)
{
	char TEMP_CHA = 'G';

	setRespawn();
	glTranslated(pos_X, pos_Y, 0.0);
	glScaled(1.0, heightOfCharacterG, 1.0);
	glColor3f(1.0f, 1.0f, 0.0f);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, TEMP_CHA);
	glScaled(1.0, 1 / heightOfCharacterG, 1.0); //��ԭ����ϵ
}

//draw character C(blue)
void drawCharacterC(GLfloat heightOfCharacterC, GLfloat pos_X, GLfloat pos_Y)
{
	char TEMP_CHA = 'C';

	setRespawn();
	glTranslated(pos_X, pos_Y, 0.0);
	glScaled(1.0, heightOfCharacterC, 1.0);
	glColor3f(0.0f, 0.0f, 1.0f);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, TEMP_CHA);
	glScaled(1.0, 1 / heightOfCharacterC, 1.0); //��ԭ����ϵ
}

void drawCharacterU(GLfloat heightOfCharacterU, GLfloat pos_X, GLfloat pos_Y)
{
	char TEMP_CHA = 'U';

	setRespawn();
	glTranslated(pos_X - 5, pos_Y, 0.0);
	glScaled(1.0, heightOfCharacterU, 1.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, TEMP_CHA);
	glScaled(1.0, 1 / heightOfCharacterU, 1.0); //��ԭ����ϵ
}


void AntiAliasingFunc()
{
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_POLYGON_SMOOTH);

	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}


void coordinateDrawer()
{
	GLdouble topY = 0.0;
	topY = standardHeight * PIXEL_HEIGHT;

	glLineWidth(5.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	setRespawn();

	glBegin(GL_LINES);
	glVertex2f(-10, 0);
	glVertex2f(-10, topY);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	glLineWidth(10.0f);

	glBegin(GL_LINES);
	glVertex2f(-10, topY / 2);
	glVertex2f(0, topY / 2);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	glLineWidth(10.0f);

	glBegin(GL_LINES);
	glVertex2f(-10, topY - 15);
	glVertex2f(0, topY - 15);
	glEnd();
}

void coordinateDrawerPWM()
{









	GLdouble topY = 0.0;
	topY = standardHeight * PIXEL_HEIGHT;

	glLineWidth(5.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	setRespawn();

	glBegin(GL_LINES);
	glVertex2f(-10, 0);
	glVertex2f(-10, topY);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	glLineWidth(10.0f);

	glBegin(GL_LINES);
	glVertex2f(-10, topY / 2);
	glVertex2f(-2.0, topY / 2);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	glLineWidth(10.0f);

	glBegin(GL_LINES);
	glVertex2f(-10, topY - 8);
	glVertex2f(0, topY - 8); 
	glEnd();
}


/* ����grab
* ץȡ�����е�����
* ���贰�ڿ��ΪWindowWidth���߶�ΪWindowHeight
*/

void grab(void)
{
	FILE* pDummyFile;
	FILE* pWritingFile;

	GLubyte* pPixelData;
	GLubyte BMP_Header[BMP_Header_Length];

	GLint i, j;
	GLint PixelDataLength;

	// �����������ݵ�ʵ�ʳ��� 
	i = WindowWidth * 3; // �õ�ÿһ�е��������ݳ��� 

	while (i % 4 != 0) // �������ݣ�ֱ��i�ǵı��� 
		++i; 
	// �������и�����㷨�� 
	// �������׷��ֱ�ۣ����ٶ�û��̫��Ҫ�� 
	PixelDataLength = i * WindowHeight;

	// �����ڴ�ʹ��ļ� 
	pPixelData = (GLubyte*)malloc(PixelDataLength);
	if (pPixelData == 0)
		exit(0);

	printf("\n\n���ڴ�ʾ��BMP�ļ�...\n");
	pDummyFile = fopen("C:\\BisheProgram\\dummy.bmp", "rb");
	if (pDummyFile == 0)
	{
		printf("�ļ������ڣ���ͨ��Windows��ͼ�ȹ��ߴ���һ����׼BMP�ļ�������Ϊdummy.bmp�������ѽ���\n");
		exit(0);
	}
		

	printf("���ڴ���Ŀ��BMP�ļ�...\n");
	pWritingFile = fopen("C:\\BisheProgram\\grab.bmp", "wb");
	if (pWritingFile == 0)
	{
		exit(0);
		printf("�ļ�����ʧ�ܣ����������\n");
	}

	printf("�ɹ�\n");
	// ��ȡ���� 
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
	glReadPixels(0, 0, WindowWidth, WindowHeight,
		GL_BGR_EXT, GL_UNSIGNED_BYTE, pPixelData);

	// ��dummy.bmp���ļ�ͷ����Ϊ���ļ����ļ�ͷ 
	fread(BMP_Header, sizeof(BMP_Header), 1, pDummyFile);
	fwrite(BMP_Header, sizeof(BMP_Header), 1, pWritingFile);

	fseek(pWritingFile, 0x0012, SEEK_SET);

	i = WindowWidth;
	j = WindowHeight;

	fwrite(&i, sizeof(i), 1, pWritingFile);
	fwrite(&j, sizeof(j), 1, pWritingFile);

	// д���������� 
	printf("��ʼд����������...\n");

	fseek(pWritingFile, 0, SEEK_END);
	fwrite(pPixelData, PixelDataLength, 1, pWritingFile);
	
	printf("��������д����ɣ�\n��С��%d �ֽ�\n", PixelDataLength);
	printf("�ֱ��ʣ�%d x %d\n", WindowWidth, WindowHeight);

	system("start C:\\BisheProgram");
	// �ͷ��ڴ�͹ر��ļ� 
	fclose(pDummyFile);
	fclose(pWritingFile);
	free(pPixelData);
}



#endif // !_DRAWCHARACTERS_H_
