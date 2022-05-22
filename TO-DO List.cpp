#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

void printTaskList();
void menu();

vector <string> ToDoList;

int main()
{
	string task;
	int choice;

	do
	{
		printTaskList();
		while (true) {
			menu();
			cout << "Enter you command : ";
			cin >> choice;
			if (choice == 1) {
				cout << "Enter the task : ";
				cin.ignore();
				getline(cin, task);
				ToDoList.push_back(task);
				break;
			}
			else if (choice == 2) {
				ToDoList.erase(ToDoList.begin());
				break;
			}
			else if (choice == 2 && ToDoList.size() == 0) {
				cout << "Can not remove the task. TO-Do list is Empty." << endl;
				continue;
			}
			else if (choice == 0) {
				cout << "exiting the program..." << endl;
				exit(0);
			}
			else {
				cout << "Invalid Input.";
				continue;
			}
		} system("cls");
	} while (choice != 0);
	printTaskList();
} 

void printTaskList() {

	cout << "\t\t------------------------------------" << endl;
	cout << "\t\t|          TO-DO LIST              |" << endl;
	cout << "\t\t------------------------------------" << endl;
	cout << "\n\n\n";

	for (int i = 0; i < ToDoList.size(); i++)
	{
		cout << setw(18) << i + 1 << " : " << ToDoList.at(i) << endl;
	}

	cout << "\t\t-----------------------------------" << endl;
	cout << "\n\n\n";
}

void menu() {
	cout << "------------------------------------" << endl;
	cout << "|     Press 1 for ADD              |" << endl;
	cout << "|     Press 2 for REMOVE TASK      |" << endl;
	cout << "|     Press 0 for EXIT             |" << endl;
	cout << "------------------------------------" << endl;
	cout << "\n";
}