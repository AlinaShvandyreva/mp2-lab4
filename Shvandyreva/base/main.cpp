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
	cout << "¬ведите число процессеров: " << endl;
	cin >> NumberProcessors;
	cout << "¬ведите размер очереди: " << endl;
	cin >> SizeQueue;
	cout << "¬ведите число тактов: " << endl;
	cin >> Tacts;
	cout << "¬ведите порог по€влени€ заданий: " << endl;
	cin >> Intensity;
	cout << endl;
	TCluster Cluster(NumberProcessors, Tacts, Intensity);
	Cluster.PreparationForWork(SizeQueue);
	Cluster.GetStatistics();
	return 0;
}