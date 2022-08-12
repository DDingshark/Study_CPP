#ifndef GARUDE_grade_h
#define GARUDE_grade_h

#include<vector>
#include"Student_info.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);
bool fgrade(const Student_info&);
std::vector<Student_info>extract_fails(std::vector<Student_info>&);
double median_analysis(const vector<Student_info>&);
void write_analysis(std::ostream& out, const std::string& name, double analysis(const std::vector<Student_info>&),const std::vector<Student_info>&,const std::vector<Student_info>&);
double average_analysis(const vector<Student_info>& students);
double average_grade(const Student_info& s);
double optimaistic_median(const Student_info& s);


#endif