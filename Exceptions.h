#pragma once
#include <exception>
#include <string>
using namespace std;

struct NotFoundException : public exception {
	const string message() const throw() {
		return "Exception: Element doesnt exist in Container";
	}
};