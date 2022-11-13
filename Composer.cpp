#include <iostream>
#include "Composer.h"
#include <string>

using namespace std;

Composer::Composer() {
	cout << "Constructor called for Composer class" << endl;
};

Composer::Composer(string in_firstName, string in_lastName, int in_YearOfBirth,
					string in_composerGenre, string in_fact, int in_ranking) {
	this->firstName_ = in_firstName;
	this->lastName_ = in_lastName;
	this->composerYearOfBirth_ = in_YearOfBirth;
	this->composerGenre_ = in_composerGenre;
	this->fact_ = in_fact;
	this->ranking_ = in_ranking;
	cout << "Constructor called for Composer class" << endl;
}

Composer::~Composer() {
	cout << "Destructor called for Composer class" << endl;
}

void Composer::promote(int increment) {
	char response = '.';
	int newIncrement = 0;
	cout << "Current ranking: " << this->ranking_ << endl
		<< "Promoting ranking by: " << increment << endl;
	this->ranking_ += increment;
	if (this->ranking_ > 10) {
		cout << endl << "Ranking cannot be bigger than 10.\tRanking: " << this->ranking_ << endl
			<< "Type 'y' to set ranking to 10, 'n' to promote ranking by another number: ",
			cin >> response;
		this->ranking_ -= increment; //offset the rankin (set it back to first value)
		if (response == 'y') {
			this->ranking_ = 10;
			return;
		}
		cout << "Input new number to increment: ", cin >> newIncrement;
		promote(newIncrement); //recursevily call promote() with inpute int
	}
}

void Composer::demote(int decrement) {
	char response = '.';
	int newDecrement = 0;
	cout << "Current ranking: " << this->ranking_ << endl
		<< "Demoting ranking by: " << decrement << endl;
	this->ranking_ -= decrement;
	if (this->ranking_ < 1) {
		cout << endl << "Ranking cannot be smaller than 1. \tRanking: " << this->ranking_ << endl
			<< "Type 'y' to set ranking to 1, 'n' to demote rank by another number: ",
			cin >> response;
		this->ranking_ += decrement;
		if (response == 'y') {
			this->ranking_ = 1;
			return;
		}
		cout << "Input new number to decrement: ", cin >> newDecrement;
		demote(newDecrement);
	}
}

void Composer::display() {
	cout << "First Name: " << firstName_ << endl
		<< "Last Name: " << lastName_ << endl
		<< "Year Of Birth: " << composerYearOfBirth_ << endl
		<< "Genre: " << composerGenre_ << endl
		<< "Fact: " << fact_ << endl
		<< "Rank: " << ranking_ << endl;
}