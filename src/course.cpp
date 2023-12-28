#include "course.h"

Course::Course(std::string name, int credits, int grade) : name(name), credits(credits), grade(grade) {}

std::string Course::getName() const{
	return name;
}

int Course::getCredits() const {
	return credits;
}

int Course::getGrade() const{
	return grade;
}

void Course::setName(std::string inputName) {
	name = inputName;
}

void Course::setCredits(int inputCredits) {
	credits = inputCredits;
}

void Course::setGrade(int inputGrade) {
	grade = inputGrade;
}

void Course::printInfo() {
	std::cout << "Course name: " << name << " Credits: " << credits << " Grade: " << grade << std::endl;
}