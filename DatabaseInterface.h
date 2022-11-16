#include <iostream>
#include "Composer.h"

using namespace std;

namespace DatabaseInterface {
	inline void printMenu() { 
		cout << "*****************************************************" << endl
			<< "1) Add a new Composer" << endl
			<< "2) Retrieve a composers data" << endl
			<< "3) Promote/Demote a composers rank" << endl
			<< "4) List all composers" << endl
			<< "0) Quit" << endl
			<< "*****************************************************" << endl;
	}

	inline void printAddingComposerMenu() {
		cout << "*****************************************************" << endl
			<< "1) Add a new composer" << endl
			<< "2) Add a new composer front" << endl
			<< "3) Add a new composer at" << endl
			<< "0) Back" << endl
			<< "*****************************************************" << endl;
	}

	inline void printDisplayMenu() {
		cout << "*****************************************************" << endl
			<< "1) Display" << endl
			<< "2) Display by rank" << endl
			<< "0) Back" << endl
			<< "*****************************************************" << endl;
	}

	inline void printComposersRankingMenu() {
		cout << "*****************************************************" << endl
			<< "1) Promote Composer " << endl
			<< "2) Demote Composer " << endl
			<< "0) Quit" << endl
			<< "*****************************************************" << endl;
	}

	inline void printChooseComposerMenu() {
		cout << "*****************************************************" << endl
			<< "1) Choose Composer " << endl
			<< "2) Choose Composer by name " << endl
			<< "0) Quit" << endl
			<< "*****************************************************" << endl;
	}

	inline void printComposersDataRetrievalMenu() {
		cout << "*****************************************************" << endl
			<< "1) Choose Composer " << endl
			<< "2) Choose Composer by name " << endl
			<< "0) Quit" << endl
			<< "*****************************************************" << endl;
	}

	inline void printComposersRemovalMenu() {
		cout << "*****************************************************" << endl
			<< "1) Choose Composer " << endl
			<< "2) Choose Composer by name " << endl
			<< "0) Quit" << endl
			<< "*****************************************************" << endl;
	}
}