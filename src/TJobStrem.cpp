#include "TJobStream.h"
#include <iostream>
using namespace std;
bool Stream::Tact()
{
	double tmp = dist(generator); // ��������� �����
	if (tmp <= q1)
	{
		count++;
		return 1;
	}
	else return 0;
}

int Stream::GetCount()
{
	return count;
}