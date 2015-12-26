#include <iostream>
#include <exception>
using namespace std;
#ifndef LISTEXCEPTION_H
#define LISTEXCEPTION_H

class ListException: public exception
{
virtual const char* what() const throw()
{
	return "Exception: List Empty";
}
} listEmpty;

#endif
