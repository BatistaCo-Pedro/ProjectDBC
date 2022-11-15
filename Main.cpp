#include <iostream>
#include <string>
#include "DatabaseInterface.h"
#include "handlerMethods.h"

using namespace DatabaseInterface;

int& handleMenuChoices() {
	int response = -1;
	while (response != 0) {
		cout << "Enter a number to choose: ", cin >> response;
		switch (response) {
			default: cout << "Invalid number, try again: " << endl;
				break;
			case 1: handlerMethods::handleAddingComposerMenu();
				return response;
			case 2: handlerMethods::handleComposerDataRetrieval();
				return response;
			case 3: handlerMethods::handleComposersRanking();
				return response;
			case 4: handlerMethods::handleDisplayingTheElements();
				return response;
			case 0: return response;
		}	
	}
	return response;
}

int main() {
	int response = -1;
	while (response != 0) {
		printMenu();
		response = handleMenuChoices();
	}
	return 0;
}