#pragma once
#include "tdataroot.h"
#include <random>
#include <ctime>

class TJobStream
{
private:
	int taskIndex;						//������ ������
	double boundOfExecution;			//����� ��������� ���������� ���������
	double boundOfTasks;				//����� ��������� ������
	
public:
	TJobStream(double q1 , double q2);
	int taskGeneration();				//��������� ������
	int taskWork();						//��������� ���������� ���������
	int getTaskIndex();					//����������� ������� ������
};

