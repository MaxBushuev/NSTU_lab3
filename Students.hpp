#define MATHAN 0
#define ALGEM 1
#define DISMAT 2
#define PHYSICS 3
#include <string>
using namespace std;
class Students{
	private:
		string _name;
		string _group;
		int* _marks;
		Students* _next;
	public:
		Students();
		void setMark(int subject, int mark);
		void setName(string _name);
		void setGroup(string _group);
		void setNext(Students* next);
		void print();
		Students* next();
		string name();
		string group();
		int* marks();

		friend ostream& operator<< (ostream &out, Students &student);
		friend istream& operator>> (istream &in, Students &student);
		friend ofstream& operator<< (ofstream &fout, Students &student);
		friend ifstream& operator>> (ifstream &fin, Students &student);
};
