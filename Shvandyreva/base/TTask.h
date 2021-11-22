#ifndef __TTask_H__
#define __TTask_H__
#include <ctime>
#include <cstdlib>
#include <iostream>

const int MAX_PROCESSORS_SIZE = 64;
const int MIN_PROCESSORS_SIZE = 1;
const int MAX_TACTS_SIZE = 1000;
const int MIN_TACTS_SIZE = 10;
const int MAX_INTENSITY_SIZE = 1;
const int MIN_INTENSITY_SIZE = 0;

using namespace std;

class  TTask
{
private:
	int NumberProcessors;
	int Tacts;
public:
	TTask()
	{
		NumberProcessors = 0;
		Tacts = 0;
	}
	TTask(int _Processors, int _Tacts)
	{
		if((_Processors > MAX_PROCESSORS_SIZE)||(_Processors < MIN_PROCESSORS_SIZE)||(_Tacts > MAX_TACTS_SIZE)||(_Tacts < MIN_TACTS_SIZE))
			throw exception();
		else 
		{
			srand(time(NULL));
			NumberProcessors = rand() % (_Processors)+1;
			Tacts = rand() % (_Tacts)+1;
		}
	}
	int GetNumberProcessors()
	{
		return NumberProcessors;
	}
	int GetNumberTacts()
	{
		return Tacts;
	}
};
#endif