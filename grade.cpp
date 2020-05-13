#include <vector>
#include <iostream>
#include <ios>
#include <iomanip>
#include "grade.h"
#include "median.h"


double grade(double midterm, double final, double homework) {
	return 0.2*midterm+0.4*final+0.4*homework;
}

double grade(double midterm, double final, const std::vector<double>& hw) {
	if (hw.size() == 0)
		throw std::domain_error("Student has no homework");
	return grade(midterm, final, median(hw));
}

double grade(const Student_info& student_info) {
	return grade(student_info.midterm, student_info.final, student_info.homework);
}
