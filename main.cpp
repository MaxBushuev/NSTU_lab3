#include "List.hpp"
#include <iostream>
using namespace std;
int main(int argc, char* argv[]){
	bool flag = true;
	int action;
	int n, num;
	string s_temp, s_temp1;
	int sub, mrk;
	if(argc != 2){
		cout << "Incorrect number of arguments" << endl;
		return -1;
	}
	List studList;
	studList.readFromFile(argv[1]);
	while(flag){
		cout << "Choose what to do" << endl;
		cout << "1. Add new student" << endl;
		cout << "2. Remove a student" << endl;
		cout << "3. Change student's data" << endl;
		cout << "4. Find a student" << endl;
		cout << "5. Print the whole database" << endl;
		cout << "6. Save the list to the file" << endl;
		cout << "7. Exit" << endl;
		cin >> action;
		Students* temp;
		switch(action){
			case 1:
				temp = new Students;
				cout << "Enter student's name: ";
				cin >> s_temp;
				temp->setName(s_temp);
				cout << "Enter student's group: ";
				cin >> s_temp;
				temp->setGroup(s_temp);
				studList.add(temp);
				break;
			case 2:
				cout << "Enter student's number: ";
				cin >> n;
				if(n == 0)
					studList.popHead();
				else
					studList.remove(n);
				break;
			case 3:
				cout << "Enter student's number: ";
				cin >> num;
				cout << "What would you like to change?" << endl;
				cout << "1. Name" << endl;
				cout << "2. Group" << endl;
				cout << "3. Marks" << endl;
				cin >> n;
				switch(n){
					case 1:
						cout << "Enter new name: ";
						cin >> s_temp;
						studList.changeName(num, s_temp);
						break;
					case 2:
						cout << "Enter new group: ";
						cin >> s_temp;
						studList.changeGroup(num, s_temp);
						break;
					case 3:
						cout << "What mark do you want to change?" << endl;
						cout << "0. Math analysis" << endl;
						cout << "1. Algebra and geometry" << endl;
						cout << "2. Discrete math" << endl;
						cout << "3. Physics" << endl;
						cout << "Enter subject number: ";
						cin >> sub;
						cout << "Enter mark: ";
						cin >> mrk;
						studList.changeMark(num, sub, mrk);
						break;
					default:
						cout << "Wrong subject" << endl;
						break;
	
				}
				break;
			case 4: 
				cout << "Enter the way to find" << endl;
				cout << "1. Name" << endl;
				cout << "2. Group" << endl;
				cout << "3. Name and group" << endl;
				cout << "4. Mark" << endl;
				cin >> n;
				switch(n){
					case 1:
						cout << "Enter name: ";
						cin >> s_temp;
						studList.find(s_temp);
						break;
					case 2:
						cout << "Enter group: ";
						cin >> s_temp;
						studList.find1(s_temp);
						break;
					case 3:
						cout << "Enter name: ";
						cin >> s_temp;
						cout << "Enter group: ";
						cin >> s_temp1;
						studList.find(s_temp, s_temp1);
					case 4:
						cout << "What mark do you want to find?" << endl;
						cout << "0. Math analysis" << endl;
						cout << "1. Algebra and geometry" << endl;
						cout << "2. Discrete math" << endl;
						cout << "3. Physics" << endl;
						cout << "Enter subject number: ";
						cin >> sub;
						cout << "Enter mark: ";
						cin >> mrk;
						studList.find(sub, mrk);
						break;
				}
				break;
			case 5:
				studList.printAll();
				break;
			case 6:
				studList.writeToFile(argv[1]);
				break;
			case 7:
				flag = false;
				break;
			default:
				cout << "Incorrect action" << endl;
				break;

		}
	}
	return 0;
}
