#ifndef _FUNCADD_H_
#define _FUNCADD_H_

#include<stdio.h>

void guideWords()
{
	printf("* * * * * * * *����һ������LOGOͼ�������* * * * * * * * * * * * * * * * * * *\n*\n*");
	printf("\n*\t��ѡ�����뷽ʽ\n*\n*\n*");
	printf("\t1.ͨ�������д���ֱ�������׼�������\n*\n*");
	printf("\t2.ͨ���ļ���seqMess.txt��ϵͳ���Զ��������򿪣������׼�������\n*\n*");
	printf("\t3.ͨ�������д���ֱ������PWM��λ��Ȩֵ����\n*\n*");
	printf("\t4.ͨ���ļ���PWMMess.txt��ϵͳ���Զ��������򿪣�����PWM��λ��Ȩֵ����\n*\n*");
	printf(" *\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n���ѡ��:");
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