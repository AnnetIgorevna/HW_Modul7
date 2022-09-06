#include <iostream>
#include <exception>
#include "Exceptions.h"

const char* bad_range::what() const noexcept
{
	return "ERROR Bad range of array!";
}

const char* bad_length::what() const noexcept
{
	return "ERROR Bad length of array!";
}