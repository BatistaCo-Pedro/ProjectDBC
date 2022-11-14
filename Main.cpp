#include "Composer.h"
#include "DatabaseInterface.h"
#include "Database.h"
#include <iostream>
#include <string>
#include "Exceptions.h"

using namespace DatabaseInterface;
Database database;

void handleAddingComposerMenu() {
	int response = 1;
	while (response != 0) {
		int index;
		printAddingComposerMenu();
		cin >> response;
		if (response == 1) {
			database.addComposer_back(database.createComposer());
			return;
		}
		if (response == 2) {
			database.addComposer_front(database.createComposer());
			return;
		}
		if (response == 3) {
			cout << endl << "What index? ", cin >> index, cout << endl;
			database.addComposer_at(database.createComposer(), index);
		}		
	}
	return;
}

void handleDisplayingTheElements() {
	int response = 1;
	while (response != 0) {
		printDisplayMenu();
		cin >> response;
		if (response == 1) {
			database.display();
			return;
		}
		if (response == 2) {
			database.displayByRank();
			return;
		}
	}
	return;
}

void handleComposerDataRetrieval() {
	if (!database.containsItems()) {
		cout << "Database contains no items" << endl << endl;
		return; 
	}
	string firstName, lastName;
	cout << "Composers first name: ", cin >> firstName, 
	cout << "Composers last name: ", cin >> lastName;
	try {
		Composer comp = database.getComposer(firstName, lastName);
		comp.display();
	} catch (NotFoundException ex) {
		cout << ex.message() << endl;
	}
}

int& handleMenuChoices() {
	int response = -1;
	while (response != 0) {
		cout << "Enter a number to choose: ", cin >> response;
		switch (response) {
			default: cout << "Invalid number, try again: " << endl;
				break;
			case 1: handleAddingComposerMenu();
				return response;
			case 2: handleComposerDataRetrieval();
				return response;
			case 3: 
				return response;
			case 4: handleDisplayingTheElements();
				return response;
			case 5: return response;
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