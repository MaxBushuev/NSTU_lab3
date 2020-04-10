#include <string>
#include <iostream>
#include <fstream>
#include <stack> //ну с ним реально удобно(плюс я чуть-чуть выпендриться хочу)
using namespace std;
int main(int argc, char* argv[]){
	if(argc!=2){
		cout << "Incorrect number of arguments" << endl;
		return -1;
	}
	ifstream input;
	input.open(argv[1]);
	if(!input.is_open()){
		cout << "File cannot be opened" << endl;
		return -1;
	}
	stack<string> strs;
	string temp;
	while(!input.eof()){
		getline(input, temp, ' ');
		if(temp[temp.size()-1] == '\n')
			temp.erase(temp.size()-1);
		strs.push(temp);
	}
	cout << "Количество слов в строке: " << strs.size() << endl;
	string output;
	while(!strs.empty()){
		output.append(strs.top());
		output.push_back(' ');
		strs.pop();
	}
	cout << output << endl;
	input.close();	
	return 0;
}
