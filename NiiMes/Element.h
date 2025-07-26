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

typedef map<mode, Parameters> elementDictionary;

class Element
{
private:
	elementDictionary _element;
	//0 - резистор, 1 - катушка
	int _type;
	string _name;
public:
	Element(elementDictionary, int, string);
	Element();
	elementDictionary GetElement();
	void SetElement(elementDictionary);
	void SetParameters(mode, Parameters);
	Parameters GetParameters(mode);
	int GetType();
	void SetType(int);
	string GetName();
	void SetName(string);
};