#include "TProc.h"
#include <iostream>
using namespace std;
bool Processor::Tact() //���������� ���������� �� ������� ������� �� ������ �����?
{
	double tmp = dist(generator); // ��������� �����
	//cout << tmp << " " << endl;
	if (tmp <= q2)
		return 1;
	else return 0;
}

bool Processor::GetFlag()
{
	return flag;
}
void Processor::SetFlag(bool t)
{
	flag = t;
}