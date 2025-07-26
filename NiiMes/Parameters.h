#pragma once
#include "ValueException.h"
#include "MinMaxException.h"

using namespace std;

class Parameters
{
private:
	int _value;
	int _min;
	int _max;
	int _step;
	bool _tune;
	bool _optimization;
public:
	Parameters();
	Parameters(int, int, int, int, bool, bool);
	int GetValue();
	int GetMin();
	int GetMax();
	int GetStep();
	bool GetTune();
	bool GetOptimization();
	void SetValue(int);
	void SetMin(int);
	void SetMax(int);
	void SetStep(int);
	void SetTune(bool);
	void SetOptimization(bool);
	void Validate(int);
	void MinMaxValidate(int, int);
};