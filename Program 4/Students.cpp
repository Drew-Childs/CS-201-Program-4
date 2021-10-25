#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

Student::Student(int id, string first, string last) {
	ID = id;
	First = first;
	Last = last;
}

Student::~Student() {
	delete[] courses_taken;
	courses_taken = nullptr;
}

Student::Student() {
	ID = 0;
	First = "";
	Last = "";
}

const Student& Student::operator = (const Student& rhs) {
	this->Last = rhs.Last;
	this->First = rhs.First;
	this->ID = rhs.ID;
	this->number_courses = rhs.number_courses;
	this->courses_taken = new Course[rhs.number_courses];
	for (int i = 0; i < rhs.number_courses; i++) {
		this->courses_taken[i] = rhs.courses_taken[i];
	}
	return *this;
}

bool Student::isEnrolled(const string& CourseName) const {
	bool enrolled_flag = false;
	for (int i = 0; i < this->number_courses; i++) {
		if (this->courses_taken[i].Name == CourseName) {
			enrolled_flag = true;
		}
	}
	return enrolled_flag;
}

bool Student::enroll(const Course& course) {
	int counter = 0;
	for (int i = 0; i < this->number_courses; i++) {
		if (this->courses_taken[i].Name != course.Name) {
			counter += 1;
		}
	}
	if (counter == this->number_courses) {
		Course *temp_arr = new Course[this->number_courses + 1];
		for (int i = 0; i < this->number_courses; i++) {
			temp_arr[i] = this->courses_taken[i];
		}
		temp_arr[this->number_courses] = course;
		this->courses_taken = temp_arr;
		temp_arr = nullptr;
		return true;
	}
	else {
		return false;
	}
}

bool Student::recordGrade(const Course& course) {
	bool updated = false;
	if (this->isEnrolled(course.Name) && (course.Grade < 4.0 && course.Grade > 0)) {
		for (int i = 0; i < this->number_courses; i++) {
			if (this->courses_taken[i].Name == course.Name) {
				this->courses_taken[i].Grade = course.Grade;
				updated = true;
			}
		}
	}
	return updated;
}

int Student::hoursCompleted() const {
	int yeehaw;
	for (int i = 0; i < this->number_courses; i++) {
		yeehaw += this->courses_taken[i].Hours;
	}
	return yeehaw;
}

float Student::GPA() const {
	return 0;
}

istream& operator >> (istream& in, Student& student) {
	in >> student.ID >> student.First >> student.Last >> student.number_courses;
	student.courses_taken = new Course[student.number_courses];
	for (int i = 0; i < student.number_courses; i++) {
		in >> student.courses_taken[i];
	}
	return in;
}

ostream& operator << (ostream& out, Student& student) {
	cout << "hawyee" << endl;
	return out;
}

istream& operator >> (istream& in, Course& course) {
	in >> course.Name >> course.Hours >> course.Grade;
	return in;
}
ostream& operator << (ostream& out, const Course& course) {
	return out;
}