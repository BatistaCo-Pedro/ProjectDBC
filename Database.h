#pragma once
#include <string>
#include "Composer.h"
#include <list>

class Database {
	private:	
		list<Composer> composerDatabase_;
	public:
		Database();
		~Database();

		Composer createComposer();
		Composer& addComposer_back(Composer);
		Composer& addComposer_front(Composer);
		Composer& addComposer_at(Composer, int);

		Composer& removeComposer(Composer);
		Composer& removeComposer(string, string, Database&);
		void removeComposer_back();
		void removeComposer_front();
		void removeComposer_at(int);

		bool containsItems() { return composerDatabase_.size() > 0; }

		Composer& getComposer(string in_firstName, string in_lastName);
		Composer& getComposer(string in_firstName);

		void display();
		void displayByRank();
};