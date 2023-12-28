#pragma once

#include <iostream>
#include <string>
#include <list>
#include "course.h"
#include "student.h"

class Calculator {
private:
	static Calculator* calculatorPtr;
	Calculator();

public:
	Calculator(const Calculator& obj) = delete;
	static Calculator* getInstance();

	void calculateGPA();
	void calculateCredits();
};