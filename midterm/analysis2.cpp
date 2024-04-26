#pragma once

// analysis.h

#ifndef GUARD_analysis
#define GUARD_analysis

#include <list>
#include <vector>
#include "Student_info.h"
#include <numeric>
#include <string>
#include <algorithm>
#include <string>
#include <fstream>
#include <ios>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include "median.h"
#include "grade.h"
#include "cctype"

using namespace std;

//did all hw
bool did_all_hw(const Student_info& s)
{
	return((find(s.homework.begin(), s.homework.end(), 0)) ==
		s.homework.end());
}



double grade_aux(const Student_info& s)
{
	try {
		return grade(s);
	}

	catch (domain_error) {
		return grade(s.midterm, s.final, 0);
	}
}
//double median_analysis
double median_analysis(const vector<Student_info>& students)
{
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
	return median(grades);


}



//double optimistic_median
double optimistic_median(const Student_info& s)
{
	vector<double> nonzero;
	remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);


	if (nonzero.empty())
		return grade(s.midterm, s.final, 0);
	else
		return grade(s.midterm, s.final, median(nonzero));
}
//double optimistic_median_analysis
double optimistic_median_analysis(const vector<Student_info>& students) {
	vector<double> grades;

	transform(students.begin(), students.end(),
		back_inserter(grades), optimistic_median);

	return median(grades);
}

//average
double average(const vector<double>& v)
{
	return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double average_grade(const Student_info& s)
{
	return grade(s.midterm, s.final, average(s.homework));
}


double average_analysis(const vector<Student_info>& students)
{
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), average_grade);
	return median(grades);
}



void write_analysis(ostream& out, const string& name,
	double analysis(const vector<Student_info>&),
	const vector<Student_info>& did,
	const vector<Student_info>& didnt)
{
	out << name << ": median(did) = " << analysis(did);
}




//average 


#endif