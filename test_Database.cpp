#include <iostream>
#include "Composer.h"
#include "Database.h"
#include "Exceptions.h"

/*using namespace std;
Database database;

void setDatabaseMockupValues() {
	database.addComposer_back(Composer("Ludwig", "Beethoven", 1770, "Comedy", "Hes dead", 10));
	database.addComposer_back(Composer("Pedro", "Batista", 2005, "Comedy", "Hes not dead", 8));
	database.addComposer_back(Composer("Ronaldo", "Beethoven", 1770, "Comedy", "Hes dead", 10));
	database.addComposer_back(Composer("Carli", "Beethoven", 1770, "Comedy", "Hes dead", 10));
	database.addComposer_back(Composer("Forri", "Beethoven", 1770, "Comedy", "Hes dead", 10));
	database.addComposer_back(Composer("Furry", "Beethoven", 1770, "Comedy", "Hes dead", 10));
	database.addComposer_back(Composer("Reno", "Beethoven", 1770, "Comedy", "Hes dead", 10));
}

int main(){
	setDatabaseMockupValues();
	cout << endl << "Testing the Database class." << endl << endl;
	try {	
		Composer composer2 = database.getComposer("Ludwig", "Beethoven");
		cout << composer2.getFirstName() << " " << composer2.getLastName() << endl << endl;
		Composer composer1 = database.getComposer("askdak", "dfa");
		cout << composer1.getFirstName() << endl << endl;
	}
	catch (NotFoundException ex) {
		cout << ex.message() << endl << endl;
	}
	database.display();
	database.addComposer_at(Composer("Carlitos", "The Giant", 1980, "Romance", "He kinda big", 6), 10);
	database.addComposer_at(Composer("Hello", "World Guy", 1997, "Not Funny", "Hes annyoing", 6), 5);
	database.removeComposer_at(3);
	database.display();
	database.addComposer_back(Composer("Carlitos", "The Small", 1980, "Romance", "He kinda big", 6));
	database.addComposer_front(Composer("Mama", "Rota", 1980, "Romance", "He kinda big", 6));
	database.display();
	database.removeComposer_back();
	database.removeComposer_front();
	database.display();
	try {
		database.removeComposer("Forri", "Beethoven", database);
	}
	catch (NotFoundException ex) {
		cout << ex.message() << endl << endl;
	}
	database.display();
}*/ 