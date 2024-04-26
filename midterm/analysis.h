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
bool did_all_hw(const Student_info& s);



double grade_aux(const Student_info& s);

//double median_analysis
double median_analysis(const vector<Student_info>& students);



//double optimistic_median
double optimistic_median(const Student_info& s);

//double optimistic_median_analysis
double optimistic_median_analysis(const vector<Student_info>& students);

//average
double average(const vector<double>& v);

double average_grade(const Student_info& s);


double average_analysis(const vector<Student_info>& students);



void write_analysis(ostream& out, const string& name,
	double analysis(const vector<Student_info>&),
	const vector<Student_info>& did,
	const vector<Student_info>& didnt);




//average 


#endif