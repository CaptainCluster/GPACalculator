#pragma once

#include <iostream>
#include <list>
#include "course.h"
#include <string>
#include <limits>

class Student {
private:
	double GPA;
	int totalCredits;
	std::list<Course> completedCourses{};

	static Student* studentPtr;
	Student();

public:
	Student(const Student& obj) = delete;
	static Student* getInstance();

	double getGPA() const;
	int getTotalCredits() const;
	std::list<Course> getCompletedCourses() const;

	void setGPA(double inputGPA);
	void setTotalCredits(int inputCredits);
	void setCompletedCourses(std::list<Course> inputCompletedCourses);

	void addCourse();
	void changeCredits();
	void changeGrade();
	void removeCourse();

	void printCourses();
	void printTotalCreditsGPA();
};