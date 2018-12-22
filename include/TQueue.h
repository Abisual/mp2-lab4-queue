#pragma once
#include "tstack.h"
class TQueue :
	public TStack
{
protected:
	int Li;   //������ ������� �������� ���������
	virtual int GetNextIndex(int index); //�������� ��������� ������
public:
	TQueue(int Size = DefMemSize) : TStack(Size) {Li=0;};
	virtual TData Get();
	virtual TData TopElem();
};

