#pragma once
class TJobStream
{
private:
	double probEndTask; // ����������� ���� ��� ������� ����������
	double probAddTask; // ����������� ���� ��� ������� ��������
	int cyclesOnTask; // ������ �� ������
public:
	TJobStream();
	TJobStream(const TJobStream& b);
	TJobStream(double probabilityEnd, double probabilityAdd);
	bool GenerateTask();
	bool GenerateAddTask();
	TJobStream& operator=(const TJobStream&b);
	double GetProbEndTask() { return probEndTask; }
	int GetCyclesOnTask() { return cyclesOnTask; }
	void SetCyclesOnTask(int clocks) { cyclesOnTask = clocks; }
};