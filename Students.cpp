#include "Students.hpp"
#include <iostream>
using namespace std;
Students::Students(){
	_name = "";
	_group = "";
	_marks = new int[4];
	for(int i = 0; i < 4; i++)
		_marks[i] = -1;
	_next = NULL;
}
void Students::setMark(int subject, int mark){
	_marks[subject] = mark;
}
void Students::setName(string name){
	_name = name;
}
void Students::setGroup(string group){
	_group = group;
}
void Students::setNext(Students* next){
	_next = next;
}
void Students::print(){
	cout << "Name: " << _name << endl;
	cout << "Group: " << _group << endl;
       	cout << "Math analisys:" << _marks[MATHAN] << endl;
	cout << "Algebra and geometry: " << _marks[ALGEM] << endl;
	cout << "Discrete math: " << _marks[DISMAT] << endl;
	cout << "Physics: " << _marks[PHYSICS] << endl;  	
}
Students* Students::next(){
	return _next;
}
string Students::name(){
	return _name;
}
string Students::group(){
	return _group;
}
int* Students::marks(){
	return _marks;
}
