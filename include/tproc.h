#pragma once
#include "tdataroot.h"
#include "tqueue.h"
#include "TJobStream.h"

class TProc
{
private:

	int tactsWork;  // ��������� ����������(����� ������)
	int tactsFree; // �������

public:
	TProc();
	int GetWorkTacts(); // ���������� ������ ������
	int GetFreeTacts(); // ���������� ������ �������
	void SetBusy(TQueue &queue); //��������(���������) ���������
};