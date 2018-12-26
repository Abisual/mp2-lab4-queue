#pragma once
#include"tjobstream.h"
class TStatistic
{
protected:
	int amountOfAddedTask; // ����� ������������ �������
	int amountDoneTask; //���������� ����������� �������
	int amountIgnoreTask; //���������� ����������������� �������
	int clocksOfIdle; //���-�� ������ �������
	int amountOfClocks;// ���������� �������� ������
	int clocksTarget; // ���������� �������� �������� ������ 
public:
	TStatistic();
	~TStatistic() {};
	static void GetStatistic(int amountOfClocksOfTest,int clockFrequencyMhz, 
		TJobStream& task, int qSize, int intensivityInOut);
	
};