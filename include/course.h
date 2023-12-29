#pragma once

#include <iostream>
#include <string>

class Course {
private:
	std::string name{};
	int credits{};
	int grade{};


public:
	Course(std::string name, int credits, int grade);

	std::string getName() const;
	int getCredits() const;
	int getGrade() const;

	void setName(std::string inputName);
	void setCredits(int inputCredits);
	void setGrade(int inputGrade);
	void printInfo() const;
};
