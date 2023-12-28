#include "calculator.h"

Calculator* Calculator::calculatorPtr = nullptr;
Calculator::Calculator(){}

Calculator* Calculator::getInstance() {
	if (calculatorPtr == nullptr) {
		calculatorPtr = new Calculator();
	}
	return calculatorPtr;
}

void Calculator::calculateGPA() {
	Student* studentObj = Student::getInstance();
	std::list<Course> completedCourses = studentObj->getCompletedCourses();
	int creditGradeMix{ 0 };
	double GPA{ 0.00 };

	//Making sure there are existing courses
	if (completedCourses.empty()) {
		return;
	}

	//Summing all the course X grade multiplications
	for (auto i = completedCourses.begin(); i != completedCourses.end(); i++) {
		creditGradeMix = creditGradeMix + (i->getCredits() * i->getGrade());
	}

	//Dividing creditGradeMix with the total credits
	GPA = creditGradeMix / studentObj->getTotalCredits();

	studentObj->setGPA(GPA);	//Assigning the new GPA with a setter
}

void Calculator::calculateCredits() {
	Student* studentObj = Student::getInstance();
	std::list<Course> completedCourses = studentObj->getCompletedCourses();
	int totalCredits{ 0 };

	//Making sure there are existing courses
	if (completedCourses.empty()) {
		return;
	}

	//Iterating through all courses and additioning the credits
	for (auto i = completedCourses.begin(); i != completedCourses.end(); i++) {
		totalCredits = totalCredits + i->getCredits();
	}
	studentObj->setTotalCredits(totalCredits);	//Assigning the new total amount of credits with a setter
}