#ifndef _PARAMETERCAL_H_
#define _PARAMETERCAL_H_

#include"drawCharacters.h"

struct baseMessage
{
	double sequ;
	char base;
};

struct sequenceCounterStruct
{
	struct baseMessage sequA;
	struct baseMessage sequT;
	struct baseMessage sequG;
	struct baseMessage sequC;
	struct baseMessage sequU;
}sequenceCounter;


double uncertaintyOnPosL(struct sequenceCounterStruct seqCounter)
{
	double UncertainOfAlign = 0;

	if (seqCounter.sequA.sequ != 0)
		UncertainOfAlign -= seqCounter.sequA.sequ * log2(seqCounter.sequA.sequ);

	if (seqCounter.sequC.sequ != 0)
		UncertainOfAlign -= seqCounter.sequC.sequ * log2(seqCounter.sequC.sequ);

	if (seqCounter.sequG.sequ != 0)
		UncertainOfAlign -= seqCounter.sequG.sequ * log2(seqCounter.sequG.sequ);

	if (seqCounter.sequT.sequ != 0)
		UncertainOfAlign -= seqCounter.sequT.sequ * log2(seqCounter.sequT.sequ);

	if (seqCounter.sequU.sequ != 0)
		UncertainOfAlign -= seqCounter.sequU.sequ * log2(seqCounter.sequU.sequ);

	return UncertainOfAlign;
}

void heightCalculator_Draw(struct sequenceCounterStruct seqMes, int pos, int KindSel)
{
	struct baseMessage forSort[5];
	struct baseMessage tmp;

	forSort[0] = seqMes.sequA;
	forSort[1] = seqMes.sequC;
	forSort[2] = seqMes.sequG;
	forSort[3] = seqMes.sequT;
	forSort[4] = seqMes.sequU;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4 - i; j++)
		{
			if (forSort[j].sequ >= forSort[j + 1].sequ)
			{
				tmp = forSort[j];

				forSort[j] = forSort[j + 1];
				forSort[j + 1] = tmp;
			}
		}
	}

	double uncertainHL = 0.0;
	double RSequenceL = 0.0;

	GLdouble heightOfBaseA = 0.0;
	GLdouble heightOfBaseC = 0.0;
	GLdouble heightOfBaseG = 0.0;
	GLdouble heightOfBaseT = 0.0;
	GLdouble heightOfBaseU = 0.0;

	GLdouble heightAll = 0.0;

	uncertainHL = uncertaintyOnPosL(seqMes);
	RSequenceL = 2 - uncertainHL;


	standardLenth = PIXEL_LENTH * lenthOfSeq;

	if (KindSel == STA_SOURCE)
	{
		heightOfBaseA = seqMes.sequA.sequ*RSequenceL / SMALLER_VAL;
		heightOfBaseC = seqMes.sequC.sequ*RSequenceL / SMALLER_VAL;
		heightOfBaseG = seqMes.sequG.sequ*RSequenceL / SMALLER_VAL;
		heightOfBaseT = seqMes.sequT.sequ*RSequenceL / SMALLER_VAL;
		heightOfBaseU = seqMes.sequU.sequ*RSequenceL / SMALLER_VAL;

		standardHeight = heightOfSeq * log2(heightOfSeq) + 2;
		standardHeight = standardHeight * heightOfSeq;
		standardHeight /= SMALLER_VAL;
	}

	if (KindSel == PWM_SOURCE)
	{
		heightOfBaseA = seqMes.sequA.sequ*RSequenceL / SMALLER_VAL_PWM;
		heightOfBaseC = seqMes.sequC.sequ*RSequenceL / SMALLER_VAL_PWM;
		heightOfBaseG = seqMes.sequG.sequ*RSequenceL / SMALLER_VAL_PWM;
		heightOfBaseT = seqMes.sequT.sequ*RSequenceL / SMALLER_VAL_PWM;
		heightOfBaseU = seqMes.sequU.sequ*RSequenceL / SMALLER_VAL_PWM;

		standardHeight = KIND_OF_BASE * log2(KIND_OF_BASE) + 2;
		standardHeight = standardHeight * KIND_OF_BASE;
		standardHeight /= SMALLER_VAL_PWM;
	}
	//ͨ������ĸ�߶�ִ��ĳ���������������Ż����յ�ʵ����ʾЧ��
	////////////////////////////////////////++++++++++++

	for (int count = 0, paraAdjustment = 0; count < 5; count++)
	{
		if (forSort[count].sequ == 0)
			continue;

		switch (forSort[count].base)
		{
		case 'A':
			drawCharacterA(heightOfBaseA, pos, (heightAll + paraAdjustment * 30));

			paraAdjustment++;
			heightAll += heightOfBaseA * PIXEL_HEIGHT;
			//����ĸ�ص��߶�ƫ�������
			break;

		case 'C':
			drawCharacterC(heightOfBaseC, pos, (heightAll + paraAdjustment * 50));

			paraAdjustment++;
			heightAll += heightOfBaseC * PIXEL_HEIGHT;

			break;

		case 'G':
			drawCharacterG(heightOfBaseG, pos, (heightAll + paraAdjustment * 50));

			paraAdjustment++;
			heightAll += heightOfBaseG * PIXEL_HEIGHT;

			break;

		case 'T':
			drawCharacterT(heightOfBaseT, pos, (heightAll + paraAdjustment * 50));
			
			paraAdjustment++;
			heightAll += heightOfBaseT * PIXEL_HEIGHT;

			break;

		case 'U':
			drawCharacterU(heightOfBaseU, pos, (heightAll + paraAdjustment * 50));

			paraAdjustment++;
			heightAll += heightOfBaseU * PIXEL_HEIGHT;

			break;

		default:
			printf("illegal value found\n");
			break;
		}
	}
}

void getValue()
{
	int illegaCounter = 0;

	printf("input the lenth and height of sequence:");
	scanf("%d%d", &lenthOfSeq, &heightOfSeq);

	sequenceMessage = (char**)malloc(heightOfSeq * sizeof(char*));

	for (int count = 0; count <= heightOfSeq; count++)
		sequenceMessage[count] = (char*)malloc((lenthOfSeq + 1) * sizeof(char));

	////////////////////////////////Init memory��
	////////////////////////////////get Input��

	printf("input the DNA sequences:\n");

	for (int count = 0; count < heightOfSeq; count++)
	{
		scanf("%s", sequenceMessage[count]);

		if (strlen(sequenceMessage[count]) != lenthOfSeq)
		{
			printf("�� %d ���������г��ȴ������������룡\n", count + 1);
			count--;
			continue;
		}
	}
}

void goStart()
{
	int illegaCounter = 0;

	////////////////////////////////////////
	//check the sequence input
	//out of ATGC�����ҷǷ����룩
	////////////////////////////////////////

	sequenceCounter.sequA.sequ = 0;
	sequenceCounter.sequA.base = 'A';

	sequenceCounter.sequC.sequ = 0;
	sequenceCounter.sequC.base = 'C';

	sequenceCounter.sequG.sequ = 0;
	sequenceCounter.sequG.base = 'G';

	sequenceCounter.sequT.sequ = 0;
	sequenceCounter.sequT.base = 'T';

	sequenceCounter.sequU.sequ = 0;
	sequenceCounter.sequU.base = 'U';
	////////////////////////////////////////seequence counters��ʼ��

	for (int countLen = 0; countLen < lenthOfSeq; countLen++)
	{
		for (int countHei = 0, illegalCounter = 0; countHei < heightOfSeq; countHei++)
		{
			switch (sequenceMessage[countHei][countLen])
			{
			case 'A':
				sequenceCounter.sequA.sequ++;
				break;

			case 'C':
				sequenceCounter.sequC.sequ++;
				break;

			case 'G':
				sequenceCounter.sequG.sequ++;
				break;

			case 'T':
				sequenceCounter.sequT.sequ++;
				break;

			case 'U':
				sequenceCounter.sequU.sequ++;
				break;

			default:
				illegaCounter++;
				break;
			}
		}

		///////////////////////////////////////////////////////////////////////
		//sequenceMessage save all of the input message and sequenceCounter to count one align stack's base number
		//
		///////////////////////////////////////////////////////////////////////

		printf("\nwarning:%d illegal input found!!\n", illegaCounter);

		///////////////////////////////////////////////////////////////////////
		//this place
		//sequenceCounter will be transfer to function to calculate the height of that align stack.
		///////////////////////////////////////////////////////////////////////
		heightCalculator_Draw(sequenceCounter, (countLen * PIXEL_LENTH), STA_SOURCE);

		sequenceCounter.sequA.sequ = 0;
		sequenceCounter.sequC.sequ = 0;
		sequenceCounter.sequG.sequ = 0;
		sequenceCounter.sequT.sequ = 0;
		sequenceCounter.sequU.sequ = 0;

	}
}


////////////////////
//new function++
void getValue_FILE()
{
	int illegaCounter = 0;
	int switch_ST = 0;

	FILE*seqMessFile;
	if ((seqMessFile = fopen("seqMess.txt", "r")) == NULL)
	{
		char ans;
		printf("Can't find your file, please check the file name!\n\n");
		printf("I've create a file for you in witch you can save your sequence message\n\n");
		printf("the file name we create for you is named: \"seqMess.txt\"\n\n");

		seqMessFile = fopen("seqMess.txt", "w");
		system("start C:\\Users\\zhang\\Desktop\\��IՓ��\\code\\��ҵ���\\��ҵ���\\seqMess.txt");
		fclose(seqMessFile);

		printf("have you save your message in the file created?\n(Y for yes and N for no):");
		while (1)
		{
			scanf("%c", &ans);
			getchar();

			if (ans == 'Y' || ans == 'y')
			{
				seqMessFile = fopen("seqMess.txt", "r");
				break;
			}

		}
	}

	printf("are you ready to start, Do you want to check the file again?(Y or N):");

	char choice = 0;
	scanf("%c", &choice);
	getchar();

 	if (choice == 'Y' || choice == 'y')
	{
		system("start C:\\Users\\zhang\\Desktop\\��IՓ��\\code\\��ҵ���\\��ҵ���\\seqMess.txt");

		printf("input 'S' when you are ready:");
		char c = 0;
		while (1)
		{
			scanf("%c", &c);
			getchar();

			if (c == 'S' || c == 's')
				break;
		}
	}

	///////////////////////////////////////////////////////////////////////////////////////////

	int heightCounter = 0;
	sequenceMessage = (char**)malloc(100 * sizeof(char*));
	sequenceMessage[heightCounter] = (char*)malloc(100 * sizeof(char));

	while (fscanf(seqMessFile, "%s", sequenceMessage[heightCounter]) != EOF)
	{
		lenthOfSeq = strlen(sequenceMessage[heightCounter]);
		heightCounter++;
		sequenceMessage[heightCounter] = (char*)malloc(lenthOfSeq * sizeof(char) + 1);
	}

	if (heightCounter == 0)
	{
		printf("�ļ�Ϊ�գ������Ѿ�����\n");
		exit(0);
	}

	heightOfSeq = heightCounter;
	
	fclose(seqMessFile);
	/////////////////////////////////////////////////////////////////////////////////////////
}


void getValuePWM()
{
	printf("please input the lenth of PWM matrix :");

	scanf("%d", &lenthOfPWM);

	lenthOfSeq = lenthOfPWM;//Horizen is based on lenthOfSeq.

	PWMMatrixMessage = (double**)malloc(KIND_OF_BASE * sizeof(double*));
	for (int countHei = 0; countHei < KIND_OF_BASE; countHei++)
		PWMMatrixMessage[countHei] = (double*)malloc(lenthOfPWM * sizeof(double));

	printf("please input your PWM Matrix:\n");

	for (int countHei = 0; countHei < KIND_OF_BASE; countHei++)
	{
		for (int countLen = 0; countLen < lenthOfPWM; countLen++)
		{
			scanf("%lf", &PWMMatrixMessage[countHei][countLen]);
		}
	}
}

void goStartWithPWM()
{
	double valTest = 0;
	double valFin = 0;

	sequenceCounter.sequA.sequ = 0;
	sequenceCounter.sequA.base = 'A';

	sequenceCounter.sequC.sequ = 0;
	sequenceCounter.sequC.base = 'C';

	sequenceCounter.sequG.sequ = 0;
	sequenceCounter.sequG.base = 'G';

	sequenceCounter.sequT.sequ = 0;
	sequenceCounter.sequT.base = 'T';

	sequenceCounter.sequU.sequ = 0;
	sequenceCounter.sequU.base = 'U';
	//////////////////////////////////////////seequence counters��ʼ��
	for (int countLen = 0; countLen < lenthOfPWM; countLen++)
	{
		for (int countHei = 0; countHei < KIND_OF_BASE; countHei++)
		{
			switch (countHei)
			{
			case 0:
				sequenceCounter.sequA.sequ = PWMMatrixMessage[countHei][countLen] * KIND_OF_BASE;
				valTest += PWMMatrixMessage[countHei][countLen];
				break;

			case 1:
				sequenceCounter.sequC.sequ = PWMMatrixMessage[countHei][countLen] * KIND_OF_BASE;
				valTest += PWMMatrixMessage[countHei][countLen];
				break;

			case 2:
				sequenceCounter.sequG.sequ = PWMMatrixMessage[countHei][countLen] * KIND_OF_BASE;
				valTest += PWMMatrixMessage[countHei][countLen];
				break;

			case 3:
				sequenceCounter.sequT.sequ = PWMMatrixMessage[countHei][countLen] * KIND_OF_BASE;
				valTest += PWMMatrixMessage[countHei][countLen];
				break;

			default:
				break;
			}
		}
		//valTest����ͳ��ÿ���ܺͶ� valFine������ȡ����ܺ���1�Ĳ�ֵ��Ҳ���ǻ�ȡ��ȷ��
		valFin = valTest - 1.0;

		if (fabs(valFin) >= 0.05)
		{
			printf("�� %d �� Ȩֵ�ܺ�ƫ����� �뱣֤ÿ�е�Ȩֵ֮����1�Ĳ�ֵ������0.1֮�䣡�����Ѿ�������\n", countLen + 1);
			exit(0);
		}

		heightCalculator_Draw(sequenceCounter, countLen * PIXEL_LENTH, PWM_SOURCE);

		sequenceCounter.sequA.sequ = 0;
		sequenceCounter.sequC.sequ = 0;
		sequenceCounter.sequG.sequ = 0;
		sequenceCounter.sequT.sequ = 0;

		valFin = 1;
		valTest = 0;
	}
}


void getValuePWM_FILE()
{
	//int illegaCounter = 0;
	//int switch_ST = 0;

	FILE*PWMMessFile;
	if ((PWMMessFile = fopen("PWMMess.txt", "r")) == NULL)
	{
		char ans;
		printf("Can't find your file, please check the file name!\n\n");
		printf("I've create a file for you in witch you can save your PWM Matrix message\n\n");
		printf("the file name we create for you is named: \"PWMMess.txt\"\n\n");

		PWMMessFile = fopen("PWMMess.txt", "w");
		fclose(PWMMessFile);
		system("start C:\\Users\\zhang\\Desktop\\��IՓ��\\code\\��ҵ���\\��ҵ���\\PWMMess.txt");
		
		printf("have you save your message in the file created?\n(Y for yes and N for no):");
		while (1)
		{
			scanf("%c", &ans);
			getchar();

			if (ans == 'Y' || ans == 'y')
			{
				PWMMessFile = fopen("PWMMess.txt", "r");
				break;
			}

		}
	}

	printf("ÿ�����ݾ�ȷ��Ҫ����ΧС��0.1��Ҳ����ÿ����ֵ֮���� 1 �������뱣����0.05֮�ڣ�)\n");
	printf("��ACGT��are you ready to start, Do you want to check your file again?(Y or N):");

	char choice = 0;
	scanf("%c", &choice);
	getchar();

	if (choice == 'Y' || choice == 'y')
	{
		system("start C:\\Users\\zhang\\Desktop\\��IՓ��\\code\\��ҵ���\\��ҵ���\\PWMMess.txt");

		printf("input 'S' when you are ready:");
		char c = 0;
		while (1)
		{
			scanf("%c", &c);
			getchar();

			if (c == 'S' || c == 's')
				break;
		}
	}


	double tmpSaver = 0.0;
	int lenthCounter = 0;

	while (fscanf(PWMMessFile, "%lf", &tmpSaver) != EOF)
	{
		lenthCounter++;
	}
	
	if (lenthCounter == 0)
	{
		printf("�ļ�Ϊ�գ����򽫽���\n");
		exit(0);
	}

	if (lenthCounter % KIND_OF_BASE != 0)
	{
		printf("�ļ������ݲ�����������ȱ��ĳЩ���ݻ���ڶ������ݣ������Ѿ�����!\n");
		exit(0);
	}

	lenthOfPWM = lenthCounter / KIND_OF_BASE;
	lenthOfSeq = lenthOfPWM;

	rewind(PWMMessFile);

	PWMMatrixMessage = (double**)malloc(KIND_OF_BASE * sizeof(double*));
	for (int countHei = 0; countHei < KIND_OF_BASE; countHei++)
		PWMMatrixMessage[countHei] = (double*)malloc(lenthOfPWM * sizeof(double));

	for (int countHei = 0; countHei < KIND_OF_BASE; countHei++)
	{
		for (int countLen = 0; countLen < lenthOfPWM; countLen++)
		{
			fscanf(PWMMessFile, "%lf", &PWMMatrixMessage[countHei][countLen]);
		}
	}

	fclose(PWMMessFile);
}

#endif













