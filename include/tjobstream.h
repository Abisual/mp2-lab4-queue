#pragma once
#include <random>
#include <ctime>

class TJobStream
{
private:

	int tasknum;  //index zadaniya
	double boundValue; //��������� ��������
	double boundTask; //����� ������

public:

	TJobStream(double q1, double q2);
	int taskGeneration(); //��������� ������
	int getTaskNum(); //������ ��������
	int taskWork(); //��������� ���������� ���������

};