#include <ctime>
#include <iostream>
#include <cstdlib>
#include "tstack.h"
#include "tqueue.h"
#include "TJobStream.h"
#include "TProc.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int countOfTacts = 0;
	int sizeOfQueue = 0;
	int countOfDenied = 0;
	int countOfAccept = 0;
	double tasksBound;
	double executionBound;

	//----------------------------------------------------

	cout << "������� ���-�� ������: ";
	cin >> countOfTacts;
	cout << "������� ������ ������� : ";
	cin >> sizeOfQueue;
	cout << "������� ������� ������� ��� ��������� ������ ( �������� 10% ��� 0.1 ) : ";
	cin >> tasksBound;
	cout << "������� ������� ��� ��������� ���������� ������ ( �������� 10% ��� 0.1 ) : ";
	cin >> executionBound;
	cout << "\n\n----------------------------------------------\n\n";

	//----------------------------------------------------

	TQueue queue(sizeOfQueue);
	TJobStream tasks(tasksBound , executionBound);
	TProc tacts;

	//----------------------------------------------------

	while ((tacts.GetCountOfFreeTacts() + tacts.GetCountOfWorkTacts()) != countOfTacts)		//������� ������
	{

		if (tasks.taskGeneration() != 0)
		{
			if(queue.IsFull())
				countOfDenied++;
			else
				queue.Put(tasks.getTaskIndex());
		}

		tacts.BusynessOfProc(queue);

		if (!queue.IsEmpty() && tasks.taskWork() == 1)
		{
			countOfAccept++;
			queue.Get();
		}
	}

	while (!queue.IsEmpty())				
	{
		countOfDenied++;
		queue.Get();
	}
	

	cout << "����� ������: " << tacts.GetCountOfWorkTacts() + tacts.GetCountOfFreeTacts() << endl;
	cout << "������� ������: " << tacts.GetCountOfWorkTacts() << endl;
	cout << "��������� ������: " << tacts.GetCountOfFreeTacts() << endl;
	cout << "��� ������: " << (tacts.GetCountOfFreeTacts() * 100 /
		(tacts.GetCountOfWorkTacts() + tacts.GetCountOfFreeTacts()))<< "%" << endl;
	cout << "������� ���-�� ������ ����������� �����: " << (tacts.GetCountOfWorkTacts() + tacts.GetCountOfFreeTacts())
		/(countOfAccept) << endl;

	cout << "\n\n----------------------------------------------\n\n";

	cout << "���������� ���� �����: " << tasks.getTaskIndex() << endl;
	cout << "���������� ������: " << countOfDenied << endl;
	cout << "�������� ������: " << countOfAccept << endl;
	cout << "������� �������: " << countOfDenied * 100 / tasks.getTaskIndex() << "%" << endl;

	cout << "\n\n----------------------------------------------\n\n";

}

