#include <iostream>
using namespace std;
namespace Interface {
	inline void printMenu() {
		cout << "*****************************************************" << endl
			<< "1) Add a new Composer" << endl
			<< "2) Retrieve a composers data" << endl
			<< "3) Promote/Demote a composers rank" << endl
			<< "4) List all composers" << endl
			<< "5) List all composers by rank" << endl
			<< "0) Quit" << endl
			<< "******************************************************";
	}
}