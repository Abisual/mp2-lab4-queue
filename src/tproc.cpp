#include "tproc.h"

TProc::TProc(int lenght) : TJobStream(lenght)
{
	q2 = 0;
	tactNum = 0;
	completedComNum = 0;
	averTuctNumToComplete = 0;
}

void TProc::SetQ2(float m2)
{
	if (m2 <= 0 || m2 > 1)
		throw - 1;
	q2 = m2;
}

bool TProc::TryToComplete()
{
	if (IsEmpty())
	{
		idleNum++;
		return false;
	}
	srand(time(NULL));
	if (distribution(generator) < q2)
	{
		Get();
		completedComNum++;
	}
}

void TProc::CPUSim(float m1, float m2,  int tNum)
{
	//unsigned long int current = 0; // ����/������ ����, ��� ������� �����������
	//unsigned long int totalTactToComplete = 0;
	//int tactCount=0;
	//SetQ1(m1);
	//SetQ2(m2);
	//tactNum = tNum;

	//while (tNum != 0)
	//{
	//	TryToAdd(comandToDoNum);
	//	TryToComplete();
	//	if (!IsEmpty())
	//	{
	//		tactCount++;
	//	}
	//	if (current != completedComtNum)
	//	{
	//		current++;
	//		totalTactToComplete += tactCount;
	//		tactCount = 0;
	//	}

	//	tNum--;
	//}
	//averTuctNumToComplete = totalTactToComplete / comandToDoNum;
	//Report();
	
	int totalTactToComplete = 0;
	int count = 1;
	SetQ1(m1);
	SetQ2(m2);
	tactNum = tNum;

	completedComNum = 0; // ���������� ���=�������� ������
	averTuctNumToComplete = 0; // ������� ����� ������ ��� ����������
	idleNum = 0; // ���������� ������ �������
    failAddNum = 0; // ���������� �������
	comandToDoNum = 0;// ���������� ����������� ������

	while (tNum != 0)
	{
		TryToAdd(comandToDoNum);
		if (TryToComplete())
		{
			totalTactToComplete += count;
			count = 1;
		}
		else
			count++;

		//Report();

		tNum--;
	}
	if (completedComNum != 0)
		averTuctNumToComplete = totalTactToComplete / completedComNum;
	else
		averTuctNumToComplete = tactNum;
	Report();
}

void TProc::Report()
{
	std::cout << "���������� ������ ���������: " << tactNum << std::endl;
	std::cout << "����������� ��������� ����� ������� q1: " << q1 << std::endl;
	std::cout << "����������� ���������� ������� ������� q2: " << q2 << std::endl;
	std::cout << "����� ����������� ������: " << comandToDoNum << std::endl;
	std::cout << "����� �������: " << (failAddNum*1.0)/comandToDoNum *100<<'%'<< std::endl;
	std::cout << "����� �������: " << (idleNum*1.0)/comandToDoNum*100<<"%" << std::endl;
	std::cout << "������� ���������� ������ �� ���������� �������: " << averTuctNumToComplete << std::endl;
}