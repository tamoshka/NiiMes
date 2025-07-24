#pragma once
#include <iostream>
#include "exception"

class MinMaxException : public std::exception
{
private:
	std::string message;
public:
	MinMaxException(const std::string& message) : message{ message }
	{}
	const char* what() const noexcept override
	{
		return message.c_str();
	}
};