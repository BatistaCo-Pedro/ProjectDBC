#include "Composer.h"
#include "DatabaseInterface.h"
#include "Database.h"
#include <iostream>
#include <string>

void handleAddingComposermenu() {
	DatabaseInterface::printAddingComposerMenu();
	int response = 1;
	while (response != 0) {
		cin >> response;
		if (response == 1) { 
			Database database;
			database.addComposer_back();
		}
	}
}

void handleMenuChoises() {
	int response = 1;
	while (response != 0) {
		cin >> response;
		if (response == 1) { handleAddingComposermenu(); }
	}
}

int main() {
	DatabaseInterface::printMenu();
	return 0;
}