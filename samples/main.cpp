#include <iostream>

#include "tqueue.h"
#include "tjobstream.h"
#include "tproc.h"

using namespace std;

void imitation(double q1, double q2, int size, int num_tacts)
{
	TProc proc(q1);
	TJobStream stream(q2);
	TQueue queue(size);
	
	int tasks_completed = 0; // ����� �������� �����
	int refusing = 0; // ����� ������� � ������������
	int downtime = 0; // ���������� ������ �������

	for (int i = 0; i < num_tacts; ++i)
	{
		if (stream.GetNewTask()) // ���� ������������� ����� �������
		{
			if (!queue.IsFull()) // ���� ������� �� ���������
			{
				queue.Put(stream.GetTaskNum()); // �� ����� ����� ���������������� ������� � �������
			}
			else // ����� ���������� � ������������
			{
				refusing++;
			}
		}

		if (!proc.IsReady()) // ���� ��������� ������ ������
		{
			if (proc.SolveTask()) // ����� �� �� � �� ���� �����?
			{
				proc.ComplitedTask(); // ��������� �������������
				tasks_completed++; // ������ ������
			}
		}
		if (proc.IsReady()) // ���� ��������� ��������
		{
			if (!queue.IsEmpty()) // ���� �� ������� ���� �������
			{
				proc.TakeNewTask(); // ����� ��� ������ �� ����������
				queue.Get(); // ����������� ����� � �������
			}
			else // ���� �� ������� �����, �� ��������� �� ���� ����� �����������
			{
				downtime++;
			}
		}
	}

	/*
	if (!proc.IsReady()) // ���� ����� num_tacts ������ � ���������� �������� ������
	{
		refusing++; // �� ������� � ����������
	}
	*/

	// ����� ���������� � ������ ����������

	cout << "Number of completed tasks: " << tasks_completed << ";" << endl;
	cout << "Refusing percentage: " << double(refusing) * 100.0 / double(stream.GetTaskNum()) << "%;" << endl;
	cout << "Average number of tacts: " << double(num_tacts - downtime) / double(tasks_completed) << ";" << endl;
	cout << "Downtime percentage: " << double(downtime) * 100.0 / double(num_tacts) << "%." << endl;
}

int main()
{
	imitation(0.2, 0.6, 50, 500);

	return 0;
}