#ifndef __TCluster_H__
#define __TCluster_H__
#include <string>
#include "TQueue.h"
#include "TTask.h"

using namespace std;
class TCluster
{
private:
	int Processors;//количестов микропроцессоров
	int* MasBusyProcessors;//массив зан€тости процессоров			
	int NumberFreeProcessors;//количество свободных процессоров	
	double Intensity;//порог по€влени€ заданий

	int NumberTasks;//количество задач	
	int NumberSleepingTactsOFCluster; //число тактов просто€ кластера
	int NumberCompletedTasks;//количество выполненных задач
	int NumberNotCompletedTask;//количество не выполненных задач
	int NumberImpossibleTask;// оличество задач, которые нельз€ выполнить		
	int BusyProcessorsOnTacts;//количество зан€тых процессоров на конкретном такте
	int Tacts;//такты	
public:

	// онструктор
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
			NumberFreeProcessors = Processors; //в начале работы все свободны
			MasBusyProcessors = new int[Processors]; //выделение пам€ти в массиве зан€тости
			for (int i = 0; i < Processors; i++)
				MasBusyProcessors[i] = 0; //в начале работы все свободны
			NumberTasks = 0;
			NumberCompletedTasks = 0;
			NumberNotCompletedTask = 0;
			NumberSleepingTactsOFCluster = 0;
			NumberImpossibleTask = 0;
			BusyProcessorsOnTacts = 0;
			//Intensity = 1;
		}
	}
	//ƒеструктор
	~TCluster()
	{
		if (MasBusyProcessors != nullptr)//если массив был не пуст
			delete[]  MasBusyProcessors;
	}
	//ѕодготовительные действи€ перед запуском кластера
	void PreparationForWork(int _SizeQ);
	//–абота кластера
	void Work(TQueue<TTask>& _queue);
	//¬озврат статистики
	void GetStatistics();
	bool EmptyOFCluster();
};
#endif
