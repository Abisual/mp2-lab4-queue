
class TJobStream
{
private:
	double q1; // 0 <= q1 <= 1
	int task_num; // ����� ����� ������
public:
	TJobStream(double q);
	bool GetNewTask();
	int GetTaskNum() const;
};