#pragma once
#include <string>
#include <iostream>
using namespace std;

struct Course {
	string Name;
	int Hours;
	float Grade;
};

istream& operator >> (istream& in, Course& course);
ostream& operator << (ostream& out, const Course& course);

class Student
{
public:
	Student(int id, string first, string last);
	Student();
	~Student();
	const Student& operator = (const Student& rhs);
	bool isEnrolled(const string& CourseName) const;
	bool enroll(const Course& course);
	bool recordGrade(const Course& course);
	int hoursCompleted() const;
	float GPA() const;
	int GetID() { return ID; }
	string GetName() const { return Last + ", " + First; }
	string getFirst() const { return First; }
	string getLast() const { return Last; }

	friend istream& operator >> (istream& in, Student& student);
	friend ostream& operator << (ostream& out, const Student& student);
	friend istream& operator >> (istream& in, Course& course);
	friend ostream& operator << (ostream& out, const Course& course);


private:

	int ID, number_courses;
	string First, Last;
	Course *courses_taken;
};