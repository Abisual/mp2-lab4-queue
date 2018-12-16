#pragma once
class TJobStream
{
private:
	double probEndTask; // ����������� ���� ��� ������� ��������
	int cyclesOnTask; // ������ �� ������
public:
	TJobStream();
	TJobStream(const TJobStream& b);
	TJobStream(double probability);
	bool GenerateTask();
	TJobStream& operator=(const TJobStream&b);
	double GetProbEndTask() { return probEndTask; }
	int GetCyclesOnTask() { return cyclesOnTask; }
	void SetCyclesOnTask(int clocks) { cyclesOnTask = clocks; }
};