#include <iostream>
#include <fstream>
#include "Header.h"
using namespace std;

int student_size() {		//allows me to count how many items are in students.txt so I can create a dynamic array according to that size later on
	int count = 0;
	ifstream counter("students.txt");

	while (counter.good()) {
		string x;
		int y;

		for (int i = 0; i < 3; i++) {
			counter >> x;
		}
		counter >> y;
		for (int i = 0; i < y; i++) {
			counter >> x;
			counter >> x;
			counter >> x;
		}
		count++;
	}
	counter.close();
	return count;
}

int course_size() {		//allows me to count how many items are in courses.txt so I can create a dynamic array according to that size later on
	int count = 0, first, third;
	double fourth;
	string second;
	ifstream counter("courses.txt");

	while (counter.good()) {
		counter >> first;
		counter >> second;
		counter >> third;
		counter >> fourth;
		++count;
	}
	--count;		//accounts for newline character at the end of file
	counter.close();
	return count;
}

int main() {
	int x = 0, student_count = student_size(), course_count = course_size();
	ifstream stu_file("students.txt");
	ifstream cour_file("courses.txt");
	Student *stu_list = new Student[student_count];
	Course *cour_list = new Course[course_count];

	while (stu_file.good()) {		//reads in data from students.txt and puts their information into stu_list array accordingly
		stu_file >> stu_list[x];
		x++;
	}

	x = 0;		//resets iterable variables

	for (int i = 0; i < course_count; i++) {		//runs enroll function and adds new classes to students course list
		int id;
		cour_file >> id;
		cour_file >> cour_list[x];
		for (int i = 0; i < student_count; i++) {
			if (id == stu_list[i].GetID()) {
				stu_list[i].enroll(cour_list[x]);		//enroll function
				stu_list[i].recordGrade(cour_list[x]);
			}
		}
		x++;
	}


	return 0;
}