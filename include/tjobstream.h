#include "tqueue.h"
#include <stdlib.h>
#include <time.h>

class TJobStream : protected TQueue
{
protected:
	float q1; // ����������� ��������� ����� �������
	unsigned long int failAddNum; // ���������� �������
	unsigned long int comandToDoNum;// ���������� ����������� ������
public:
	TJobStream(int lenght);
	bool TryToAdd(int n);
	void SetQ1(float x);
};