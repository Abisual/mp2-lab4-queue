#include "tdataroot.h"
#include "tqueue.h"
#include "tjobstream.h"

class TProc
{
public:
	TProc();
	int GetCountOfWorkTacts();				//������� ���-�� ������ ������
	int GetCountOfFreeTacts();				//������� ���-�� ������ �������
	void BusynessOfProc(TQueue &queue);	//�������� �� ���������
private:
	int tactsOfWork;						//����� ������
	int tactsOfFree;						//����� �������

};

