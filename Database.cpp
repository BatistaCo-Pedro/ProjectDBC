#include <string>
#include <iostream>
#include <list>
#include "Database.h"
#include "Composer.h"
#include "Exceptions.h"

using namespace std;

Database::Database() { }

Database::~Database() { }

int getCorrectRankingInput() {
	int ranking = 0;
	cout << "Ranking: ", cin >> ranking;
	while (!cin >> ranking) {
		cout << "Needs to be a number, try again: ", cin >> ranking;
	}
	while (ranking > 10 || ranking < 1) {
		cout << "Number needs to be between 1-10" << endl << "Input new number: ", cin >> ranking;
	}
	return ranking;
}

Composer Database::createComposer() {
	string firstName, lastName, composerGenre, fact;
	int yearOfBirth, ranking;
	cout << "*****************************************************" << endl
		<< "First name: ", cin >> firstName, cout << "Last name: ", cin >> lastName, cout
		<< "Year of birth: ", cin >> yearOfBirth, cout
		<< "Genre: ", cin.ignore(), getline(cin, composerGenre), cout
		<< "Fact: ", getline(cin, fact);
	ranking = getCorrectRankingInput();
	cout << "*****************************************************" << endl;
	Composer comp(firstName, lastName, yearOfBirth, composerGenre, fact, ranking);
	return comp;
}

Composer& Database::addComposer_back(Composer composer) {
	this->composerDatabase_.push_back(composer);
	return composer;
}

Composer& Database::addComposer_front(Composer composer) {
	this->composerDatabase_.push_front(composer);
	return composer;
}

Composer& Database::addComposer_at(Composer composer, int index) {
	auto insertionIndex = this->composerDatabase_.begin();
	if (checkIfIndexIsOutOfBounds(index)) return composer;
	advance(insertionIndex, index);
	this->composerDatabase_.insert(insertionIndex, composer);
	return composer;
}

void Database::removeComposer(Composer comp) {
	auto deletionIndex = composerDatabase_.begin();
	for (auto& element : composerDatabase_) {
		if ((element.getFirstName() == comp.getFirstName()) && (element.getLastName() == comp.getLastName())) {
			this->composerDatabase_.erase(deletionIndex);
		}
		deletionIndex++;
	}
}

void Database::removeComposer_at(int index) {
	auto deletionIndex = composerDatabase_.begin();
	if ((index > this->composerDatabase_.size() - 1) || (index < 0)){
		cout << endl << "Index " << index << " is out of bounds" << endl << endl;
		return;
	}
	advance(deletionIndex, index);
	this->composerDatabase_.erase(deletionIndex);
}

void Database::removeComposer_back() {
	composerDatabase_.pop_back();
}

void Database::removeComposer_front() {
	composerDatabase_.pop_front();
}

Composer& Database::getComposer(string in_firstName, string in_lastName) {
	for (auto& element : composerDatabase_) {
		if ((element.getFirstName() == in_firstName) && (element.getLastName() == in_lastName)) {
			return element;
		}
	}
	throw NotFoundException();
}

Composer& Database::getComposer(string in_firstName) {
	for (auto& element : composerDatabase_) {
		if (element.getFirstName() == in_firstName) {
			return element;
		}
	}
	throw NotFoundException();
}

void Database::display() {
	for (auto& element : composerDatabase_) {
		element.display();
		cout << endl;
	}
}

void Database::displayByRank() {
	list<Composer> listSortedByRank = composerDatabase_;
	listSortedByRank.sort();
	for (auto& element : listSortedByRank) {
		element.display();
		cout << endl;
	}
}