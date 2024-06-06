#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to add a student's result
void add_result() {
    ofstream file("results.txt", ios::app);
    string name, roll_no;
    float marks;

    system("cls");
    cout << "Enter student's name: "; 
    cin >> name;
    cout << "Enter Matric number: ";
    cin >> roll_no;
    cout << "Enter marks: ";
    cin >> marks;

    file << name << " " << roll_no << " " << marks << "\n";
    cout << "Recorded Added!" << endl;
    system("pause");
    file.close();
}

// Function to display all results
void display_results() {
    fstream file;
    string name, mat;
	float marks;
   
	system("cls");
	file.open("results.txt", ios::in);
	if (!file)
	{
		cout << "Database Failed To Open!" << endl;
	} else {
		cout << "Student Name\t\tMatric Number\t\tMarks" << endl;
		file >> name >> mat >> marks; 
		while(!file.eof()) {
			cout << name << "\t\t\t" << mat << "\t\t\t" << marks << endl; 
			file >> name >> mat >> marks;
		}
		system("pause");
		file.close();
	}
}

// Function to search a student's result
void search_result() {
    fstream file;
    string roll_no, mat, name;
    float marks;
    int count = 0;
    system("cls");
    file.open("results.txt", ios::in);
	if (!file) {
		cout << "Database Failed To Open!" << endl;
	} else {
		cout << "Enter Matric number to search: ";
    	cin >> roll_no;
		file >> name >> mat >> marks; 
		while(!file.eof()) {
			if (roll_no == mat) {
				cout << "Name: " << name << ", Matric No: " << mat << ", Marks: " << marks << "\n\n";
				count = 1;
				break;
			}
			file >> name >> mat >> marks; 
		}
		if (count == 0) {
			cout << "Record Not Found!" << endl;
		}
		system("pause");
		file.close();
	}

}

int main() {
    int choice;

    while (true) {
        system("cls");
		cout << "1. Add Result\n";
        cout << "2. Display All Results\n";
        cout << "3. Search Result\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                add_result();
                break;
            case 2:
                display_results();
                break;
            case 3:
                search_result();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
