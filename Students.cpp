#include "Students.hpp"
#include <iostream>
#include <fstream>
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
ostream& operator<< (ostream &out, Students &student){
	out << "Name: " << student._name << endl;
	out << "Group: " << student._group << endl;
       	out << "Math analisys:" << student._marks[MATHAN] << endl;
	out << "Algebra and geometry: " << student._marks[ALGEM] << endl;
	out << "Discrete math: " << student._marks[DISMAT] << endl;
	out << "Physics: " << student._marks[PHYSICS] << endl; 
	return out;
}
istream& operator>> (istream &in, Students &student){
	cout << "Name: ";
	in >> student._name;
	cout << "Group: ";
	in >> student._group;
	cout << "Math analysis: ";
       	in >> student._marks[MATHAN];
	cout << "Algebra and geometry: ";
	in >> student._marks[ALGEM];
	cout << "Discrete math: ";
	in >> student._marks[DISMAT];
	cout << "Physics: ";
	in >> student._marks[PHYSICS];
        return in;	
}
ofstream& operator<< (ofstream &fout, Students &student){
	fout << student._name << endl;
	fout << student._group << endl;
       	fout << student._marks[MATHAN] << endl;
	fout << student._marks[ALGEM] << endl;
	fout << student._marks[DISMAT] << endl;
	fout << student._marks[PHYSICS] << endl;
        return fout;	
}
ifstream& operator>> (ifstream &fin, Students &student){
	fin >> student._name;
	fin >> student._group;
       	fin >> student._marks[MATHAN];
	fin >> student._marks[ALGEM];
	fin >> student._marks[DISMAT];
	fin >> student._marks[PHYSICS];
        return fin;	
}
