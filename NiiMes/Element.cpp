#include "Element.h"

Element::Element(map<mode, Parameters> element)
{
	this->SetElement(element);
}

map<mode, Parameters> Element::GetElement()
{
	return this->_element;
}

void Element::SetElement(map<mode, Parameters> element)
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