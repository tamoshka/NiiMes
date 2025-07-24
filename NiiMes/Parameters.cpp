#include "Parameters.h"

Parameters::Parameters(int value, int power, int min, int max, int step, bool tune, bool optimization)
{
	try
	{
		this->MinMaxValidate(min, max);
		this->_min = min;
		this->_max = max;
		this->Validate(value);
		this->_value = value;
		this->SetPower(power);
		this->SetStep(step);
		this->SetTune(tune);
		this->SetOptimization(optimization);
	}
	catch(const MinMaxException& err)
	{
		throw err;
	}
	catch (const ValueException& err)
	{
		throw err;
	}
	catch (const exception& err)
	{
		throw err;
	}
}

Parameters::Parameters()
{

}

void Parameters::SetValue(int value)
{
	try
	{
		this->Validate(value);
		this->_value = value;
	}
	catch (const ValueException& err)
	{
		throw err;
	}
}

void Parameters::MinMaxValidate(int min, int max)
{
	if (min > max || min < 0)
	{
		throw MinMaxException("MinMaxException");
	}
}

void Parameters::Validate(int value)
{
	if (value < _min || value>_max)
	{
		throw ValueException("ValueException");
	}
}

void Parameters::SetMin(int min)
{
	try
	{
		this->MinMaxValidate(min, this->_max);
		this->_min = min;
	}
	catch (const MinMaxException& err)
	{
		throw err;
	}
}

void Parameters::SetMax(int max)
{
	try
	{
		this->MinMaxValidate(this->_min, max);
		this->_max = max;
	}
	catch (const MinMaxException& err)
	{
		throw err;
	}
}

void Parameters::SetPower(int power)
{
	if (power < 0 || power>3)
	{
		throw exception();
	}
	this->_power = power;
}

void Parameters::SetStep(int step)
{
	if (step<0 || step>(this->_max - this->_min))
	{
		throw exception();
	}
	this->_step = step;
}

void Parameters::SetTune(bool tune)
{
	this->_tune = tune;
}

void Parameters::SetOptimization(bool optimization)
{
	this->_optimization = optimization;
}

int Parameters::GetValue()
{
	return this->_value;
}

int Parameters::GetPower()
{
	return this->_power;
}

int Parameters::GetMin()
{
	return this->_min;
}

int Parameters::GetMax()
{
	return this->_max;
}

int Parameters::GetStep()
{
	return this->_step;
}

bool Parameters::GetOptimization()
{
	return this->_optimization;
}

bool Parameters::GetTune()
{
	return this->_tune;
}