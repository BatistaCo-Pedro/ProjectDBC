#pragma once

#include <string>;

using namespace std;

class Composer {
    private:
        string firstName_ = "";
        string lastName_ = "";
        int composerYearOfBirth_ = 0;
        string composerGenre_ = ""; // baroque, classical, romantic, etc.
        string fact_ = "";
        int ranking_ = 0;
    public:
        void set_firstName(string in_firstName) { this->firstName_ = in_firstName; }
        void set_lastName(string in_lastName) { this->lastName_ = in_lastName; }
        void set_composerYearOfBirth(int in_YearOfBirth) { this->composerYearOfBirth_ = in_YearOfBirth; }
        void set_composerGenre(string in_composerGenre) { this->composerGenre_ = in_composerGenre; }
        void set_fact(string in_fact) { this->fact_ = in_fact; }
        void set_ranking(int in_ranking) { this->ranking_ = in_ranking; }
        string getFirstName() { return firstName_; }
        string getLastName() { return lastName_; }

        Composer();
        Composer(string, string, int, string, string, int);
        ~Composer();

        void promote(int increment);
        void demote(int decrement);
        void display();
};