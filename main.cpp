#include <iostream>
#include <string>
#include <limits>
#include "student.h"
#include "calculator.h"

#define OPTION_ONE		"1) Add course"
#define OPTION_TWO		"2) Remove course"
#define OPTION_THREE	"3) Change course credits"
#define OPTION_FOUR		"4) Change course grade"
#define OPTION_FIVE		"5) Print courses"
#define OPTION_SIX		"6) Print GPA and total credits"
#define OPTION_ZERO		"0) Exit program"

int main() {
	std::string userOptionString;
	int userOption{ 0 };
	bool endProgram{ false };

	Student* pStudent = Student::getInstance();
	Calculator* pCalculator = Calculator::getInstance();

	while (!endProgram) {
		//Listing all the possible choices before asking the user to choose one
		std::cout << "Select one of the following options" << std::endl;
		std::cout << "======================================" << std::endl;
		std::cout << OPTION_ONE << std::endl;
		std::cout << OPTION_TWO << std::endl;
		std::cout << OPTION_THREE << std::endl;
		std::cout << OPTION_FOUR << std::endl;
		std::cout << OPTION_FIVE << std::endl;
		std::cout << OPTION_SIX << std::endl;
		std::cout << OPTION_ZERO << std::endl;
		std::cout << "======================================" << std::endl;

		//Requesting an input based on the given choices.
		std::cout << "Insert your choice: ";
		std::getline(std::cin, userOptionString);

		try {
			if (userOptionString.empty()) {
				std::cout << "Given input is empty. Try again." << std::endl;
				continue;
			}

			userOption = stoi(userOptionString);
			//Defining all the possible scenarios
			switch (userOption) {

			case 1:		//Adding a course
				pStudent->addCourse();
				pCalculator->calculateCredits();
				pCalculator->calculateGPA();
				break;

			case 2:		//Removing a course
				if (!pStudent->getCompletedCourses().empty()) {
					pStudent->removeCourse();
					pCalculator->calculateCredits();
					pCalculator->calculateGPA();
				} else {
					std::cout << "No existing courses found." << std::endl;
				}
				break;

			case 3:		//Changing course credits
				if (!pStudent->getCompletedCourses().empty()) {
					pStudent->changeCredits();
					pCalculator->calculateCredits();
					pCalculator->calculateGPA();
				}
				else {
					std::cout << "No existing courses found." << std::endl;
				}
				break;

			case 4:		//Changing a course grade
				if (!pStudent->getCompletedCourses().empty()) {
					pStudent->changeGrade();
					pCalculator->calculateCredits();
					pCalculator->calculateGPA();
				} else {
					std::cout << "No existing courses found." << std::endl;
				}
				break;

			case 5:		//Printing all the courses (name, credits, grade)
				pStudent->printCourses();
				break;

			case 6:		//Printing GPA and total credits
				pStudent->printTotalCreditsGPA();
				break;

			case 0:		//Ending the program
				endProgram = true;
				break;

			default:
				std::cout << "Invalid choice. Try again." << std::endl;
				break;
			};
		} catch (const std::invalid_argument& e) { //Catching invalid input types
			std::cerr << "Given input is not an integer. Try again.\n" << std::endl;
		}
	}
	return 0;
}