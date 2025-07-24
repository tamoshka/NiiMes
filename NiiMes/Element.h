#pragma once
#include "map"
#include "tuple"
#include "Parameters.h"

enum mode
{
	R,
	W,
	L
};

class Element
{
private:
	map<mode, Parameters> _element;
	//0 - резистор, 1 - катушка
	int _type;
	string _name;
public:
	Element(map<mode, Parameters>, int, string);
	Element();
	map<mode, Parameters> GetElement();
	void SetElement(map<mode, Parameters>);
	void SetParameters(mode, Parameters);
	Parameters GetParameters(mode);
	int GetType();
	void SetType(int);
	string GetName();
	void SetName(string);
};