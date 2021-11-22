#include "TCluster.h"
#include <iostream>
#include <ctime>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;
//���������� �������� � ������
void TCluster::PreparationForWork(int _SizeQ)
{
	if ((_SizeQ > MAX_QUEUE_SIZE) || (_SizeQ < MIN_QUEUE_SIZE))
		throw exception();
	else 
	{
		//�������� ������� ������������ �������
		TQueue<TTask> WorkQ(_SizeQ);
		//������ ������ ��������
		Work(WorkQ);
	}
}
bool TCluster::EmptyOFCluster()
{
	int Count = 0;
	for (int i = 0; i < Processors; i++)
		if (MasBusyProcessors[i] != 0)
			Count++;
	if (Count == 0)
		return true;
	return false;
}
//������ ��������
void TCluster::Work(TQueue<TTask>& _Queue)
{
	srand(time(NULL));
	for (int i = 0; i < Tacts; i++)
	{
		double Chance = ((double)rand() / (RAND_MAX));
		if (Chance < Intensity)
		{
			TTask Task(Processors, Tacts); //������� ������
			NumberTasks++;
			if (_Queue.Full() == true)
				NumberImpossibleTask++; //������ ���������� ��������� (��� ����������� ��� ������ �������� �� ��������)
			else
				_Queue.AddElQueue(Task); //�������� ������ � �������
		}
		//���� ����, ��� ����� �� �������
		if (_Queue.Empty() == false)
		{
			int TempProcessors;
			int TempTact;
			TempProcessors = _Queue.GetTop().GetNumberProcessors(); //���������� ����������� ������ ��� ���������� �������
			TempTact = _Queue.GetTop().GetNumberTacts();//���������� ������ ������ ��� ����������
			int TempBusyProcessors = TempProcessors; //���������� ��������� ������� �٨ ����� ��� ���������� ������
			//���� ������ ����� ��� ���������� ������
			if (NumberFreeProcessors >= TempBusyProcessors)
			{
				for (int i = 0; i < Processors; i++)
				{
					if ((MasBusyProcessors[i] == 0) && (TempBusyProcessors > 0)) //��������� �� ����� � ��� ����� ���������� ������
					{
						MasBusyProcessors[i] = TempTact; //�������� ���������
						TempBusyProcessors--; //����������� ����� 1
					}
					if (TempBusyProcessors == 0)
						break;
				}
				NumberFreeProcessors = NumberFreeProcessors - TempProcessors; //�������� ��������� �������� ������ ��� �������
				_Queue.TakeElQueue().GetNumberProcessors(); //������ ���������� �� ���������� - �������� �� �������
			}
		}
		if (EmptyOFCluster() == true)
			NumberSleepingTactsOFCluster++;
		//������ �� ����������������
		for (int i = 0; i < Processors; i++)
		{
			if (MasBusyProcessors[i] > 0) //���� ��������� �����
			{
				MasBusyProcessors[i]--; //��������� ���������� ���������� ������
				if (MasBusyProcessors[i] == 0) //���� ��������� �����������
					NumberFreeProcessors++; //+1 ��������� ���������
			}
		}
		BusyProcessorsOnTacts = BusyProcessorsOnTacts + (Processors - NumberFreeProcessors);//����� ������� ����������� �� �����
	}
	NumberNotCompletedTask = _Queue.BusyElSize();//������� ����� �������� � �������
}
//����� ����� ���������� �� ������ ��������
void TCluster::GetStatistics()
{
	NumberCompletedTasks = NumberTasks - (NumberNotCompletedTask + NumberImpossibleTask);
	cout << "�����, ��������� �����: " << NumberTasks << endl;
	cout << "�����, ������� ����������� �����: " << NumberCompletedTasks << endl;
	cout << "����� �����, ���������� � �������: " << NumberNotCompletedTask << endl;
	cout << "����� ������������� �����: " << NumberTasks- NumberCompletedTasks-NumberNotCompletedTask- NumberImpossibleTask << endl;
	cout << "����� ����������� ��� ���������� �����: " << NumberImpossibleTask << endl;
	cout << "������� ������������� �����������: " << BusyProcessorsOnTacts / Tacts << " �� " << Processors << endl;
	cout << "����� ������ ������� ��������: "<< NumberSleepingTactsOFCluster << endl;
}