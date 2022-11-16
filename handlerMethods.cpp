#include "handlerMethods.h"
#include "Composer.h"
#include "DatabaseInterface.h"
#include "Database.h"
#include "Exceptions.h"
#include <map>

using namespace std;
using namespace DatabaseInterface;

Database database;

bool DatabaseContainsItems() {
	if (!database.containsItems()) {
		cout << "Database contains no Composers" << endl << endl;
		return false;
	}
	return true;
}

Composer& chooseComposer() {
	int composerChoice = 0;
	int iterator = 1;
	map<int, Composer> composerMap;
	for (auto& element : database.getList()) {
		cout << iterator << ") " << element.getFirstName() << " " << element.getLastName() << endl;
		composerMap[iterator] = element;
		iterator++;
	}
	cout << endl << "Which composer do you want to chose? ", cin >> composerChoice;
	while (composerChoice >= iterator || composerChoice <= 0) {
		cout << endl << "That composer doesnt exist, try again: ", cin >> composerChoice;
	}
	Composer comp = composerMap[composerChoice];
	return database.getComposer(comp.getFirstName(), comp.getLastName());
}

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
			return;
		}
	}
	return;
}

void handlerMethods::handleDisplayingTheElements() {
	int response = 1;
	if (!DatabaseContainsItems()) return;
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
	if (!DatabaseContainsItems()) return;
	int response = -1;
	while (response != 0) {
		printComposersDataRetrievalMenu();
		cin >> response;
		if (response == 1) {
			Composer comp = chooseComposer();
			comp.display();
			return;
		}
		if (response == 2) {
			string firstName, lastName;
			cout << "Composers first name: ", cin >> firstName, cout << "Composers last name: ", cin >> lastName;
			try {
				Composer comp = database.getComposer(firstName, lastName);
				comp.display();
				return;
			}
			catch (NotFoundException ex) {
				cout << ex.message() << endl;
				return;
			}
		}
	}
}

Composer& handlerMethods::handleComposerSearchChoice() {
	int response = -1;
	while (response != 0) {
		printChooseComposerMenu();
		cin >> response;
		if (response == 1) {
			return chooseComposer();
		}
		if (response == 2) {
			string firstName, lastName;
			cout << "First Name: ", cin >> firstName, cout << "Last Name: ", cin >> lastName;
			return database.getComposer(firstName, lastName);
		}
	}
	throw QuitException();
}

void handlerMethods::handleComposersRanking() {
	if (!DatabaseContainsItems()) return;
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
		} catch (NotFoundException ex) {
			cout << ex.message() << endl;
		} catch (QuitException ex) {
			return;
		}
	}
	return;
}