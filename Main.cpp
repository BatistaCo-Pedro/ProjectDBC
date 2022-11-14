#include "Composer.h"
#include "DatabaseInterface.h"
#include "Database.h"
#include <iostream>
#include <string>

Database database;

void handleAddingComposerMenu() {
	DatabaseInterface::printAddingComposerMenu();
	int response = 1;
	cin >> response; 
	if (response == 0) return;
	if (response == 1) { 
		database.addComposer_back(DatabaseInterface::createComposer());
		return;
	}
	if (response == 2) {
		database.addComposer_front(DatabaseInterface::createComposer());
		return;
	}
	int index;
	cout << endl << "What index? ", cin >> index, cout << endl;
	database.addComposer_at(DatabaseInterface::createComposer(), index);
}

void handleMenuChoices() {
	int response = 1;
	while (response != 0) {
		cin >> response;
		if (response == 1) { handleAddingComposerMenu(); }
	}
}

int main() {
	DatabaseInterface::printMenu();
	handleMenuChoices();
	return 0;
}