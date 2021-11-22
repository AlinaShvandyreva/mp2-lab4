#ifndef __TCluster_H__
#define __TCluster_H__
#include <string>
#include "TQueue.h"
#include "TTask.h"

using namespace std;
class TCluster
{
private:
	int Processors;//���������� ����������������
	int* MasBusyProcessors;//������ ��������� �����������			
	int NumberFreeProcessors;//���������� ��������� �����������	
	double Intensity;//����� ��������� �������

	int NumberTasks;//���������� �����	
	int NumberSleepingTactsOFCluster; //����� ������ ������� ��������
	int NumberCompletedTasks;//���������� ����������� �����
	int NumberNotCompletedTask;//���������� �� ����������� �����
	int NumberImpossibleTask;//���������� �����, ������� ������ ���������		
	int BusyProcessorsOnTacts;//���������� ������� ����������� �� ���������� �����
	int Tacts;//�����	
public:

	//�����������
	TCluster()
	{
		Processors = 0;
		NumberFreeProcessors = 0;
		Tacts = 0;
		NumberTasks = 0;
		NumberCompletedTasks = 0;
		NumberNotCompletedTask = 0;
		NumberSleepingTactsOFCluster = 0;
		NumberImpossibleTask = 0;
		BusyProcessorsOnTacts = 0;
		//Intensity=1;
		MasBusyProcessors = new int[10];
	}
	TCluster(int _Processors, int _Tacts, double _Intensity)
	{
		if ((_Processors > MAX_PROCESSORS_SIZE) || (_Processors < MIN_PROCESSORS_SIZE) || (_Tacts > MAX_TACTS_SIZE) || (_Tacts < MIN_TACTS_SIZE)
			|| (_Intensity > MAX_INTENSITY_SIZE) || (_Intensity < MIN_INTENSITY_SIZE))
			throw exception();
		else
		{
			Processors = _Processors;
			Tacts = _Tacts;
			Intensity = _Intensity;
			NumberFreeProcessors = Processors; //� ������ ������ ��� ��������
			MasBusyProcessors = new int[Processors]; //��������� ������ � ������� ���������
			for (int i = 0; i < Processors; i++)
				MasBusyProcessors[i] = 0; //� ������ ������ ��� ��������
			NumberTasks = 0;
			NumberCompletedTasks = 0;
			NumberNotCompletedTask = 0;
			NumberSleepingTactsOFCluster = 0;
			NumberImpossibleTask = 0;
			BusyProcessorsOnTacts = 0;
			//Intensity = 1;
		}
	}
	//����������
	~TCluster()
	{
		if (MasBusyProcessors != nullptr)//���� ������ ��� �� ����
			delete[]  MasBusyProcessors;
	}
	//���������������� �������� ����� �������� ��������
	void PreparationForWork(int _SizeQ);
	//������ ��������
	void Work(TQueue<TTask>& _queue);
	//������� ����������
	void GetStatistics();
	bool EmptyOFCluster();
};
#endif
