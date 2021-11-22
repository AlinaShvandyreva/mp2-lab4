#ifndef __TQueue_H__
#define __TQueue_H__
#include <iostream>
const int MAX_QUEUE_SIZE = 50;
const int MIN_QUEUE_SIZE = 5;

using namespace std;

template <class T>
class TQueue
{
private:
	T* pQueue;
	int SizeQueue;
	int TopQueue;
public:
	TQueue()
	{
		SizeQueue = 0;
		TopQueue = -1;
		pQueue = new T[SizeQueue];
	}
	TQueue(int _Size)
	{
		if ((_Size < MIN_QUEUE_SIZE) || (_Size > MAX_QUEUE_SIZE))
			throw exception();
		else
		{
			SizeQueue = _Size;
			TopQueue = -1;
			pQueue = new T[SizeQueue];
		}
	}
	bool Full()
	{
		if (TopQueue == (SizeQueue - 1))
			return true;
		else
			return false;
	}
	bool Empty()
	{
		if (TopQueue == -1)
			return true;
		else 
			return false;
	}
	void AddElQueue(const T _Elem)
	{
		if (Full() == true)
			throw exception();
		else
		{
			TopQueue = TopQueue + 1;
			pQueue[TopQueue] = _Elem;
		}
	}
	T TakeElQueue()
	{
		if (Empty() == true)
			throw exception();
		else
		{
			T Task = pQueue[0];
			for (int i = 0; i < TopQueue; i++)
				pQueue[i] = pQueue[i + 1];
			TopQueue = TopQueue - 1;
			return Task;
		}
	}
	T GetTop()
	{
		return pQueue[0];
	}
	int BusyElSize()
	{
		int Temp = TopQueue + 1;
		return Temp;
	}
	~TQueue()
	{
		delete[] pQueue;
	}
};
#endif