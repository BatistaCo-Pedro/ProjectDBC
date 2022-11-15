#include "handlerMethods.h"
#include "Composer.h"
#include "DatabaseInterface.h"
#include "Database.h"
#include "Exceptions.h"
#include <map>

using namespace std;
using namespace DatabaseInterface;

Database database;

void handlerMethods::handleAddingComposerMenu() {
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
			if (database.checkIfIndexIsOutOfBounds(index)) {
				cout << "Index is out of bounds" << endl;
				continue;
			}
			database.addComposer_at(database.createComposer(), index);
		}
	}
	return;
}

void handlerMethods::handleDisplayingTheElements() {
	int response = 1;
	if (!database.containsItems()) {
		cout << "Database contains no items" << endl << endl;
		return;
	}
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

void handlerMethods::handleComposerDataRetrieval() {
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
	}
	catch (NotFoundException ex) {
		cout << ex.message() << endl;
	}
}

Composer& handlerMethods::handleComposerSearchChoice() {
	int response = -1;
	int iterator = 1;
	map<int, Composer> composerMap;
	while (response != 0) {
		printChooseComposerMenu();
		cin >> response;
		if (response == 1) {
			int composerChoice = 0;
			for (auto& element : database.getList()) {
				cout << iterator << ") ";
				element.display();
				composerMap[iterator] = element;
				iterator++;
			}
			cin >> composerChoice;
			Composer comp = composerMap.find(composerChoice)->second;
			return comp;
		}
		if (response == 2) {
			string firstName, lastName;
			cout << "First Name: ", cin >> firstName, cout << "Last Name: ", cin >> lastName;
			try {
				return database.getComposer(firstName, lastName);
			} catch (NotFoundException ex) {
				cout << ex.message() << endl;
				break;
			}
		}
	}
	throw exception();
}

void handlerMethods::handleComposersRanking() {
	if (!database.containsItems()) {
		cout << "Database contains no items" << endl << endl;
		return;
	}
	int response = -1;
	while (response != 0) {
		try {
			Composer& comp = handleComposerSearchChoice();
			cout << comp.getFirstName() << " " << comp.getLastName() << " choosen" << endl << endl;
			printComposersRankingMenu();
			cin >> response;
			if (response == 1) {
				int increment;
				cout << "Promote composers rank by? ", cin >> increment;
				comp.promote(increment);
				return;
			}
			if (response == 2) {
				int decrement;
				cout << "Demote composers rank by? ", cin >> decrement;
				comp.demote(decrement);
				return;
			}
		} catch (exception ex) {
			cout << "Get fucked " << endl;
		}
		
	}
	return;
}