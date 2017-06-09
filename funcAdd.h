#ifndef _FUNCADD_H_
#define _FUNCADD_H_

#include<stdio.h>

void guideWords()
{
	printf("* * * * * * * *生物一致序列LOGO图绘制软件* * * * * * * * * * * * * * * * * * *\n*\n*");
	printf("\n*\t请选择输入方式\n*\n*\n*");
	printf("\t1.通过命令行窗口直接输入标准碱基矩阵\n*\n*");
	printf("\t2.通过文件：seqMess.txt（系统会自动创建并打开）输入标准碱基矩阵\n*\n*");
	printf("\t3.通过命令行窗口直接输入PWM（位置权值矩阵）\n*\n*");
	printf("\t4.通过文件：PWMMess.txt（系统会自动创建并打开）输入PWM（位置权值矩阵）\n*\n*");
	printf(" *\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n你的选择:");
}

void funcSelection()
{
	int funcSt = 0;
	scanf("%d", &funcSt);
	getchar();

	switch (funcSt)
	{
	case 1:
		PWMSwitch = 0;
		getValue();
		//goStart();
		break;

	case 2:
		PWMSwitch = 0;
		getValue_FILE();
		//goStart();
		break;

	case 3:
		PWMSwitch = 1;
		getValuePWM();
		break;

	case 4:
		PWMSwitch = 1;
		getValuePWM_FILE();
		break;

	default:
		printf("illegal selection!\n");
		exit(0);
		break;
	}
}

#endif // !_FUNCADD_H_