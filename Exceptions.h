#pragma once
#include <exception>
#include <string>
using namespace std;

struct NotFoundException : public exception {
	const string message() const throw() {
		return "Element doesnt exist in Container";
	}
};

struct QuitException : public exception { };