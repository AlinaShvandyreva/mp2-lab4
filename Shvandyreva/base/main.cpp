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
	cout << "������� ����� �����������: " << endl;
	cin >> NumberProcessors;
	cout << "������� ������ �������: " << endl;
	cin >> SizeQueue;
	cout << "������� ����� ������: " << endl;
	cin >> Tacts;
	cout << "������� ����� ��������� �������: " << endl;
	cin >> Intensity;
	cout << endl;
	TCluster Cluster(NumberProcessors, Tacts, Intensity);
	Cluster.PreparationForWork(SizeQueue);
	Cluster.GetStatistics();
	return 0;
}