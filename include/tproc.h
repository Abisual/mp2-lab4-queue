#include "tjobstream.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>


class  TProc : protected TJobStream
{
protected:
	float q2;
	unsigned long int tactNum; // ���������� ������
	unsigned long int completedTactNum; // ���������� ���=�������� ������
	float averTuctNumToComplete; // ������� ����� ������ ��� ����������
	unsigned long int idleNum; // ���������� ������ �������
public:
	TProc(int lenght);
	bool TryToComplete();
	void Report();
	void CPUSim(float m1, float m2, unsigned long int tNum);
	void SetQ2(float x);
};