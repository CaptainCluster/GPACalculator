#include "student.h"

#define INPUT_COURSE_NAME		"Add course name: "
#define INPUT_COURSE_CREDITS	"Add course credits: "
#define INPUT_COURSE_GRADE		"Add course grade: "

#define NOTIFY_COURSE_DELETED	"The course has been deleted."

const int GRADE_LOWER_BOUNDARY{ 1 };
const int GRADE_UPPER_BOUNDARY{ 5 };

Student* Student::studentPtr = nullptr;

Student::Student(){}

Student* Student::getInstance() {
	if (studentPtr == nullptr) {
		studentPtr = new Student();
	}
	return studentPtr;
}

void Student::addCourse() {
	std::string inputName;
	std::string inputGradeString;
	std::string inputCreditsString;
	int inputGrade;
	int inputCredits;

	std::cout << INPUT_COURSE_NAME;						//Asking for the course name
	std::getline(std::cin, inputName);

	std::cout << INPUT_COURSE_CREDITS;					//Asking for the course credits
	std::getline(std::cin, inputCreditsString);			
	inputCredits = std::stoi(inputCreditsString);

	std::cout << INPUT_COURSE_GRADE;					//Asking for the course grade
	std::getline(std::cin, inputGradeString);
	inputGrade = std::stoi(inputGradeString);

	//Making sure the given grade is within the boundaries
	if (GRADE_LOWER_BOUNDARY > inputGrade || GRADE_UPPER_BOUNDARY < inputGrade) {
		std::cout << "The grade you gave is not within the boundaries." << std::endl;
		return;
	}

	//Creating the Course object and pushing it to the list
	Course newCourse = Course(inputName, inputCredits, inputGrade);
	completedCourses.push_back(newCourse);

	//Increasing the total credits
	setTotalCredits(studentPtr->getTotalCredits() + inputCredits);
}

void Student::changeCredits() {
	std::string inputName;
	std::string inputCreditsString;
	int inputCredits;

	//Making sure there are existing courses
	if (completedCourses.empty()) {
		return;
	}

	std::cout << INPUT_COURSE_NAME;
	std::getline(std::cin, inputName);

	//Iterating through all the course in the list.
	for (auto i = completedCourses.begin(); i != completedCourses.end();) {
		if (inputName == i->getName()) {
			std::cout << "Course found. Insert new amount of credits: ";
			std::getline(std::cin, inputCreditsString);
			inputCredits = std::stoi(inputCreditsString);
			i->setCredits(inputCredits);	//Replacing the stored grade within the object with the given input
			return;
		}
	}
}

void Student::changeGrade() {
	std::string inputName;
	std::string inputGradeString;
	int inputGrade;

	//Making sure there are existing courses
	if (completedCourses.empty()) {
		return;
	}

	std::cout << INPUT_COURSE_NAME;
	std::getline(std::cin, inputName);

	//Iterating through all the course in the list.
	for (auto i = completedCourses.begin(); i != completedCourses.end(); i++) {
		if (inputName == i->getName()) {
			std::cout << "Course found. Give a new grade: ";
			std::getline(std::cin, inputGradeString);
			inputGrade = std::stoi(inputGradeString);
			i->setGrade(inputGrade);	//Replacing the stored grade within the object with the given input
			return;
		}
	}
}

void Student::removeCourse() {
	std::string inputName;

	//Making sure there are existing courses
	if (completedCourses.empty()) {
		return;
	}

	std::cout << INPUT_COURSE_NAME;
	std::getline(std::cin, inputName);

	//Iterating through all the courses until a match is found
	for (auto i = completedCourses.begin(); i != completedCourses.end(); i++) {
		if (inputName == i->getName()) {
			//Deleting the course from the list and exiting the function
			completedCourses.erase(i);
			std::cout << NOTIFY_COURSE_DELETED << std::endl;
			return;
		} 
	}
}

void Student::printCourses() {
	std::cout << std::endl;
	for (Course course : completedCourses) {
		course.printInfo();
	}
}

void Student::printTotalCreditsGPA() {
	std::cout << "Total credits: " << studentPtr->getTotalCredits() << " GPA: " << studentPtr->getGPA() << std::endl;
}

double Student::getGPA() const {
	return GPA;
}

int Student::getTotalCredits() const {
	return totalCredits;
}

std::list<Course> Student::getCompletedCourses() const {
	return completedCourses;
}

void Student::setGPA(double inputGPA) {
	GPA = inputGPA;
}

void Student::setTotalCredits(int inputTotalCredits) {
	totalCredits = inputTotalCredits;
}

void Student::setCompletedCourses(std::list<Course> inputCompletedCourses) {
	completedCourses = inputCompletedCourses;
}