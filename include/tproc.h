
class TProc
{
private:
	double q2; // 0 <= q2 <= 1
	int status; // ���������� ���������� ����� �� ������� ������
public:
	TProc(double q);
	bool SolveTask();
	bool IsReady() const;
	void TakeNewTask();
	void ComplitedTask();
};