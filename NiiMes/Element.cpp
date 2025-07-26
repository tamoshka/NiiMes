#include "Element.h"

Element::Element(elementDictionary element, int type, string name)
{
	try
	{
		this->SetElement(element);
		this->SetType(type);
		this->SetName(name);
	}
	catch (const exception& err)
	{
		throw err;
	}
}

Element::Element()
{

}

elementDictionary Element::GetElement()
{
	return this->_element;
}

void Element::SetElement(elementDictionary element)
{
	this->_element = element;
}

Parameters Element::GetParameters(mode mode)
{
	return this->_element[mode];
}

void Element::SetParameters(mode mode, Parameters parameters)
{
	if (this->_element.count(mode) == 1)
	{
		this->_element.erase(mode);
	}
	this->_element[mode] = parameters;
}

int Element::GetType()
{
	return this->_type;
}

void Element::SetType(int type)
{
	if (type < 0 || type>1)
	{
		throw exception();
	}
	this->_type = type;
}

void Element::SetName(string name)
{
	this->_name = name;
}

string Element::GetName()
{
	return this->_name;
}