#include <iostream>
using namespace std;
namespace DatabaseInterface {
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

	void printAddingComposerMenu() {
		cout << "*****************************************************" << endl
			<< "1) Add a new composer" << endl
			<< "2) Add a new composer front" << endl
			<< "3) Add a new composer at" << endl
			<< "0) Back" << endl
			<< "******************************************************";
	}
}