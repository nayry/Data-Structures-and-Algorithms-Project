#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "AVLNode.h"
#include "AVLTree.h"
#include "person.h"
#include "functions.h"

using namespace std;


int main() {
	AVLTree myTree;                                                            //create the tree
	ifstream inputFile("Contacts for Project.txt");                            //import the file
	int counter = 0;                                                           //this variable controls the amount of records that will be loaded to this program  
	cout << "Please wait a moment. The data is loading." << endl;
	while (!inputFile.eof())
	{
		person *Person = new person;                                           //person class is for storing the data
		string str;
		getline(inputFile, str);
		*Person = getData(Person,str);                                         //getData() is a function in functions.h
	
		myTree.root = myTree.insert(Person, myTree.root);                      //insert a new AVLNode
		if (counter == 149999)
			break;
		counter++;
	}
	bool quit = false;                                                         //this variable controls when to leave the do-while loop bellow
	do {
		int choose;                                                            //this variable controls which function to be executed
		cout << "------------------------------------------------" << endl;
		cout << "Welcome to the Main menu!(Address Book)" << endl;
		cout << "------------------------------------------------" << endl;
		cout << "Please select a function:" << endl;
		cout << "1) Insert a new record" << endl;
		cout << "2) Modify an existing record" << endl;
		cout << "3) Delete an existing record" << endl;
		cout << "4) Search a record" << endl;
		cout << "5) Print all entries" << endl;
		cout << "6) Output the updated data" << endl;
		cout << "-1) Leave" << endl;
		cout << "Input your choice:";
		cin >> choose;
		system("cls");
		switch (choose) {
		case 1:
			insert(&myTree);                                                    //insert a new record(this function is in the functions.h)
			break;
		case 2:
			modify(&myTree);
			break;                                                              //modify an existing record(this function is in the functions.h)
		case 3:
			deletion(&myTree);                                                  //delete an existing record(this function is in the functions.h)
			break;
		case 4: 
			search(&myTree);                                                    //search a record(this function is in the functions.h)
			break;
		case 5:
			cout << "Print all entris will cost a lot of time. Do you really want to print all?" << endl;
			cout << "1)Continue" << endl;
			cout << "2)Return to main menu" << endl;
			cout << "Input your choice:";
			int really;
			cin >> really;
			system("cls");
			if (really == 1) {
				printAll(&myTree);                                              //print all entries(this function is in the functions.h)
			}
			break;
		case 6:
			cout << "Ouput all entris will cost a lot of time. Do you really want to print all?" << endl;
			cout << "1)Continue" << endl;
			cout << "2)Return to main menu" << endl;
			cout << "Input your choice:";
			int sure;
			cin >> sure;
			system("cls");
			if (sure == 1) {
				string allRecords = "";
				cout << "Please wait a moment." << endl;
				myTree.outputData(myTree.root, allRecords);
				ofstream myfile;
				myfile.open("outputted_data.txt");
				myfile << allRecords;                                           //output all records in a text file
				myfile.close();
				system("cls");
				cout << "Output completed. Please go to outputted_data.txt to check" << endl;
			}
			break;
		case -1: 
			quit = true;                                                        //leave the program
			break;
		default:
			cout << "Please enter again."<<endl;
		}
	
	} while (!quit);

	system("pause");
	return 0;
}