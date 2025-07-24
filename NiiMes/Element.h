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
public:
	Element(map<mode, Parameters>);
	map<mode, Parameters> GetElement();
	void SetElement(map<mode, Parameters>);
	void SetParameters(mode, Parameters);
	Parameters GetParameters(mode);
};