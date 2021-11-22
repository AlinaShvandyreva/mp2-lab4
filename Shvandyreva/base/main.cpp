#include "TCluster.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int NumberProcessors;
	int SizeQueue;
	int Tacts;
	double Intensity;
	cout << "Введите число процессеров: " << endl;
	cin >> NumberProcessors;
	cout << "Введите размер очереди: " << endl;
	cin >> SizeQueue;
	cout << "Введите число тактов: " << endl;
	cin >> Tacts;
	cout << "Введите порог появления заданий: " << endl;
	cin >> Intensity;
	cout << endl;
	TCluster Cluster(NumberProcessors, Tacts, Intensity);
	Cluster.PreparationForWork(SizeQueue);
	Cluster.GetStatistics();
	return 0;
}