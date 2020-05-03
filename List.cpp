#include "List.hpp"
#include <fstream>
#include <iostream>
using namespace std;
List::List(){
	head = NULL;
	_size = 0;
}
List::~List(){
	while(head != NULL){
		Students* temp = head->next();
		delete head;
		head = temp;
	}
}
void List::add(Students* temp){
	temp->setNext(head);
	head = temp;
	_size++;
}
void List::popHead(){
	Students* temp = head->next();
	delete head;
	head = temp;
	_size--;
}
void List::remove(int n){
	Students* temp = head;
	if(head == NULL || n > _size)
		return;
	for(int i = 0; i < n-1; i++)
		temp = temp->next();
	Students* del = temp->next();
	temp->setNext(del->next());
	delete del;	
	_size--;	
}
void List::printAll(){
	Students* temp = head;
	for(int i = 0; i < _size; i++){
		cout << "Number of element: " << i << endl;
		temp->print();
		cout << endl;
		temp = temp->next();
	}
}
void List::readFromFile(string filename){
	ifstream input;
	input.open(filename);
	if(!input.is_open()){
		cout << "Can't open the file" << endl;
		return;
	}
	string s_temp;
	int i_temp;
	do{
		Students* temp = new Students;
		input >> s_temp;
		temp->setName(s_temp);
		input >> s_temp;
		temp->setGroup(s_temp);
		input >> i_temp;
		temp->setMark(MATHAN, i_temp);
		input >> i_temp;
		temp->setMark(ALGEM, i_temp);
		input >> i_temp;
		temp->setMark(DISMAT, i_temp);
		input >> i_temp;
		temp->setMark(PHYSICS, i_temp);

		this->add(temp);
	} while(!input.eof());
	input.close();
	this->popHead();
}
void List::writeToFile(string filename){
	ofstream output;
	output.open(filename);
	if(!output.is_open()){
		cout << "Can't open the file" << endl;
		return;
	}
	Students* temp = head;
	while(temp != NULL){
		output << temp->name() << endl;
		output << temp->group() << endl;
		output << *temp->marks() << endl;
		output << *(temp->marks()+1) << endl;
		output << *(temp->marks()+2) << endl;
		output << *(temp->marks()+3) << endl;
		temp = temp->next();
	}
	output.close();
}
void List::find(string name){
	Students* temp = head;
	int num = 0;
	while(temp != NULL){
		if(temp->name() == name){
			cout << "Number of element: " << num << endl;
			temp->print();
		}
		temp = temp->next();
		num++;
	}
}
void List::find1(string group){
	Students* temp = head;
	int num = 0;
	while(temp != NULL){
		if(temp->group() == group){
			cout << "Number of element: " << num << endl;
			temp->print();
		}
		temp = temp->next();
		num++;
	}
}
void List::find(string name, string group){
	Students* temp = head;
	int num = 0;
	while(temp != NULL){
		if(temp->name() == name && temp->group() == group){
			cout << "Number of element: " << num << endl;
			temp->print();
		}
		temp = temp->next();
	}
}
void List::find(int subject, int mark){
	Students* temp = head;
	int num = 0;
	while(temp != NULL){
		if(*(temp->marks() + subject) == mark){
			cout << "Number of element: " << num << endl;
			temp->print();
			cout << endl;
		}
		temp = temp->next();
		num++;
	}
}
void List::changeName(int n, string name){
	Students* temp = new Students;
	temp = head;
	for(int i = 0; i < n; i++)
		temp = temp->next();
	temp->setName(name);
}
void List::changeGroup(int n, string group){
	Students*temp = new Students;
	temp = head;
	for(int i = 0; i < n; i++)
		temp = temp->next();
	temp->setGroup(group);
}
void List::changeMark(int n, int sub, int mrk){
	Students* temp = new Students;
	temp = head;
	for(int i = 0; i < n; i++)
		temp = temp->next();
	temp->setMark(sub, mrk);
}

ostream& operator<< (ostream &out, List &list){
	Students* temp = list.head;
	for(int i = 0; i < list._size; i++){
		out << "Number of element: " << i << endl;
		out << *temp;
		out << endl;
		temp = temp->next();
	}
	return out;
}

ofstream& operator<< (ofstream &fout, List &list){
	Students* temp = list.head;
	while(temp != NULL){
		fout << *temp;
		temp = temp->next();
	}
	return fout;
}
ifstream& operator>> (ifstream &fin, List &list){
	
	do{
		Students* temp = new Students;
		fin >> *temp;

		list.add(temp);
	} while(!fin.eof());
	list.popHead();
	return fin;
}
