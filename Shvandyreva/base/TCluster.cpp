#include "TCluster.h"
#include <iostream>
#include <ctime>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;
//Подготовка кластера к работе
void TCluster::PreparationForWork(int _SizeQ)
{
	if ((_SizeQ > MAX_QUEUE_SIZE) || (_SizeQ < MIN_QUEUE_SIZE))
		throw exception();
	else 
	{
		//создание очереди необходимого размера
		TQueue<TTask> WorkQ(_SizeQ);
		//Запуск работы кластера
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
//Работа кластера
void TCluster::Work(TQueue<TTask>& _Queue)
{
	srand(time(NULL));
	for (int i = 0; i < Tacts; i++)
	{
		double Chance = ((double)rand() / (RAND_MAX));
		if (Chance < Intensity)
		{
			TTask Task(Processors, Tacts); //Создали задачу
			NumberTasks++;
			if (_Queue.Full() == true)
				NumberImpossibleTask++; //задачу невозможно выполнить (нет процессоров или некуда положить на ожидание)
			else
				_Queue.AddElQueue(Task); //добавили задачу в очередь
		}
		//если есть, что взять из очереди
		if (_Queue.Empty() == false)
		{
			int TempProcessors;
			int TempTact;
			TempProcessors = _Queue.GetTop().GetNumberProcessors(); //количество процессоров нужных для выполнения задания
			TempTact = _Queue.GetTop().GetNumberTacts();//количсетво тактов нужных для выполнения
			int TempBusyProcessors = TempProcessors; //количество процессов которые ЕЩЁ нужны для выполнения задачи
			//если хватит места для выполнения задачи
			if (NumberFreeProcessors >= TempBusyProcessors)
			{
				for (int i = 0; i < Processors; i++)
				{
					if ((MasBusyProcessors[i] == 0) && (TempBusyProcessors > 0)) //Процессор не занят и еще нужны процессоры задаче
					{
						MasBusyProcessors[i] = TempTact; //занимаем процессор
						TempBusyProcessors--; //необходимые минус 1
					}
					if (TempBusyProcessors == 0)
						break;
				}
				NumberFreeProcessors = NumberFreeProcessors - TempProcessors; //пересчет свободных согласно только что занятым
				_Queue.TakeElQueue().GetNumberProcessors(); //задача поставлена на выполнение - забираем из очереди
			}
		}
		if (EmptyOFCluster() == true)
			NumberSleepingTactsOFCluster++;
		//проход по микропроцессорам
		for (int i = 0; i < Processors; i++)
		{
			if (MasBusyProcessors[i] > 0) //если процессор занят
			{
				MasBusyProcessors[i]--; //уменьшаем количество оставшихся тактов
				if (MasBusyProcessors[i] == 0) //если процессор освободился
					NumberFreeProcessors++; //+1 свободный процессор
			}
		}
		BusyProcessorsOnTacts = BusyProcessorsOnTacts + (Processors - NumberFreeProcessors);//число занятых процессоров на такте
	}
	NumberNotCompletedTask = _Queue.BusyElSize();//сколько задач осталось в очереди
}
//Вывод сбора статистики из работы кластера
void TCluster::GetStatistics()
{
	NumberCompletedTasks = NumberTasks - (NumberNotCompletedTask + NumberImpossibleTask);
	cout << "Число, созданных задач: " << NumberTasks << endl;
	cout << "Число, успешно выполненных задач: " << NumberCompletedTasks << endl;
	cout << "Число задач, оставшихся в очереди: " << NumberNotCompletedTask << endl;
	cout << "Число выполняющихся задач: " << NumberTasks- NumberCompletedTasks-NumberNotCompletedTask- NumberImpossibleTask << endl;
	cout << "Число невозможных для выполнения задач: " << NumberImpossibleTask << endl;
	cout << "Средняя загруженность процессоров: " << BusyProcessorsOnTacts / Tacts << " из " << Processors << endl;
	cout << "Число тактов простоя кластера: "<< NumberSleepingTactsOFCluster << endl;
}