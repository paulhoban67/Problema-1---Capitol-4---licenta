/*
1-Scrieți un program ȋntr-unul din limbajele de programare Python, C++, Java, C# care:
a. Definește o clasă Student avȃnd:
   un atribut nume de tip șir de caractere;
   un atribut note conținȃnd un șir de note (numere ȋntregi),
   constructori, accesori și o metodă care calculează media notelor studentului.
b. Definește o funcție care primind un obiect de tip Student returnează adevărat dacă toate
   notele elevului sunt >4.
c. Scrieți specificațiile metodelor definite ȋn clasa Student precum și a funcției de la
   punctul b.

2- Definește un subprogram care primind un obiect de tip Student tiparește numele
   studentului și notele acestuia ȋn ordine descrescătoare.
*/

#include <iostream>
#include <vector>
using namespace std;

class Student {
private: 
	string nume;
	vector<int> note;

public:
	Student() {}
	Student(string nume, vector<int> note) {
		this->nume = nume;
		this->note = note;
	}
	~Student() {}

	string getNume() { return this->nume; }
	vector<int> getNote() { return this->note; }

	double medie() {
		int s = 0;
		for (int i = 0; i < this->note.size(); i++) {
			s += this->note[i];
		}
		return (double)s / this->note.size();
	}
};

bool checkNote(Student student) {
	for (int i = 0; i < student.getNote().size(); i++) {
		if (student.getNote()[i] <= 4) return false;
	}
	return true;
}

void studentWithNote(Student student) {
	cout << student.getNume() << ": ";
	for (int i = 0; i < student.getNote().size() - 1; i++) {
		for (int j = i + 1; j < student.getNote().size(); j++) {
			if (student.getNote()[i] < student.getNote()[j]) {
				int aux = student.getNote()[i];
				student.getNote()[i] = student.getNote()[j];
				student.getNote()[j] = aux;
			}
		}
	}
	for (int i = 0; i < student.getNote().size(); i++) {
		cout << student.getNote()[i] << "  ";
	}
}

int main() {
	vector<int> note1;
	note1.push_back(2); 	note1.push_back(4); 	note1.push_back(5); 	note1.push_back(8);

	vector<int> note2;
	note2.push_back(6); 	note2.push_back(7); 	note2.push_back(8); 	note2.push_back(8);

	Student ana("ana", note1);
	Student andrei("andrei", note2);

	cout << "Medie Ana: " << ana.medie() << endl;
	cout << "Medie Andrei: " << andrei.medie() << endl;
	cout << "Ana nu are note sub 4: " << checkNote(ana) << endl;
	cout << "Andrei nu are note sub 4: " << checkNote(andrei) << endl;
	
	studentWithNote(ana);
	cout << endl;
	studentWithNote(andrei);
}