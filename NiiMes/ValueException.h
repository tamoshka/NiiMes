#pragma once
#include <iostream>
#include "exception"

class ValueException : public std::exception
{
private:
	std::string message;
public:
	ValueException(const std::string& message) : message{ message }
	{}
	const char* what() const noexcept override
	{
		return message.c_str();
	}
};