#include "functions.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "AVLNode.h"
#include "AVLTree.h"
#include "person.h"
using namespace std;

void insert(AVLTree* myTree) {
	person *data = new person;
	cout << "Please input the Title:" << endl;
	cin.ignore();
	getline(cin, data->Title);
	cout << "Please input the Surname:" << endl;
	getline(cin, data->Surname);
	cout << "Please input the Given name:" << endl;
	getline(cin, data->Givenname);
	cout << "Please input the Gender:" << endl;
	getline(cin, data->Gender);
	cout << "Please input the Birthady:" << endl;
	getline(cin, data->Birthday);
	cout << "Please input the Street address:" << endl;
	getline(cin, data->StreetAddress);
	cout << "Please input the City:" << endl;
	getline(cin, data->City);
	cout << "Please input the State:" << endl;
	getline(cin, data->StateFull);
	cout << "Please input the Zip code:" << endl;
	getline(cin, data->ZipCode);
	cout << "Please input the Country:" << endl;
	getline(cin, data->CountryFull);
	cout << "Please input the Telephone country code:" << endl;
	getline(cin, data->TelephoneCountryCode);
	cout << "Please input the Telephone number(integers only):" << endl;
	string str;
	getline(cin, str);
	for (char& ch : str) {
		if (ch != '(' && ch != ')' && ch != '-' && ch != ' ')
			data->TelephoneNumber += ch;
	}
	cout << "Please input the Email address:" << endl;
	getline(cin, data->EmailAddress);
	cout << "Please input the Occupation:" << endl;
	getline(cin, data->Occupation);
	cout << "Please input the Company:" << endl;
	getline(cin, data->Company);
	myTree->root = myTree->insert(data, myTree->root);
	system("cls");
	cout << "------------------------------------------------" << endl;
	cout << "Insert success!" << endl;
	cout << "------------------------------------------------" << endl;

}

void modify(AVLTree* myTree) {
	bool check = true;
	long long number;
	cout << "Please input the phone number: ";
	cin >> number;
	AVLNode* myNode = myTree->findNode(myTree->root, number);
	if (myNode) {
		cout << "The following is the record you want to modify." << endl;
		myNode->data->dispaly();

	}
	else {
		cout << "The record is not exist.";
		check = false;
	}

	cout << endl;
	cin.ignore();
	if (check == true) {
		do {
			int choose;
			cout << "------------------------------------------------" << endl;
			cout << "Please select the entry you want to modify." << endl;
			cout << "1) Title" << endl;
			cout << "2) Surname" << endl;
			cout << "3) Given name" << endl;
			cout << "4) Gender" << endl;
			cout << "5) Birthday" << endl;
			cout << "6) Street address" << endl;
			cout << "7) City" << endl;
			cout << "8) State" << endl;
			cout << "9) Zip code" << endl;
			cout << "10) Country" << endl;
			cout << "11) Telephone country code" << endl;
			cout << "12) Telephone number" << endl;
			cout << "13) Email address" << endl;
			cout << "14) Occupation" << endl;
			cout << "15) Company" << endl;
			cout << "-1) Leave" << endl;
			cout << "Please input your choice:";
			cin >> choose;
			if (choose == 1) {
				string newValue;
				cout << "Please input the new value: ";
				cin.ignore();
				getline(cin, newValue);
				myNode->data->Title = newValue;
				system("cls");
				cout << "------------------------------------------------" << endl;
				cout << "Modification success!" << endl;
				cout << "------------------------------------------------" << endl;
				cout << "The following is the record you want to modify." << endl;
				myNode->data->dispaly();
			}
			else if (choose == 2) {
				string newValue;
				cout << "Please input the new value: ";
				cin.ignore();
				getline(cin, newValue);
				myNode->data->Surname = newValue;
				system("cls");
				cout << "------------------------------------------------" << endl;
				cout << "Modification success!" << endl;
				cout << "------------------------------------------------" << endl;
				cout << "The following is the record you want to modify." << endl;
				myNode->data->dispaly();
			}
			else if (choose == 3) {
				string newValue;
				cout << "Please input the new value: ";
				cin.ignore();
				getline(cin, newValue);
				myNode->data->Givenname = newValue;
				system("cls");
				cout << "------------------------------------------------" << endl;
				cout << "Modification success!" << endl;
				cout << "------------------------------------------------" << endl;
				cout << "The following is the record you want to modify." << endl;
				myNode->data->dispaly();
			}
			else if (choose == 4) {
				string newValue;
				cout << "Please input the new value: ";
				cin.ignore();
				getline(cin, newValue);
				myNode->data->Gender = newValue;
				system("cls");
				cout << "------------------------------------------------" << endl;
				cout << "Modification success!" << endl;
				cout << "------------------------------------------------" << endl;
				cout << "The following is the record you want to modify." << endl;
				myNode->data->dispaly();
			}
			else if (choose == 5) {
				string newValue;
				cout << "Please input the new value: ";
				cin.ignore();
				getline(cin, newValue);
				myNode->data->Birthday = newValue;
				system("cls");
				cout << "------------------------------------------------" << endl;
				cout << "Modification success!" << endl;
				cout << "------------------------------------------------" << endl;
				cout << "The following is the record you want to modify." << endl;
				myNode->data->dispaly();
			}
			else if (choose == 6) {
				string newValue;
				cout << "Please input the new value: ";
				cin.ignore();
				getline(cin, newValue);
				myNode->data->StreetAddress = newValue;
				system("cls");
				cout << "------------------------------------------------" << endl;
				cout << "Modification success!" << endl;
				cout << "------------------------------------------------" << endl;
				cout << "The following is the record you want to modify." << endl;
				myNode->data->dispaly();
			}
			else if (choose == 7) {
				string newValue;
				cout << "Please input the new value: ";
				cin.ignore();
				getline(cin, newValue);
				myNode->data->City = newValue;
				system("cls");
				cout << "------------------------------------------------" << endl;
				cout << "Modification success!" << endl;
				cout << "------------------------------------------------" << endl;
				cout << "The following is the record you want to modify." << endl;
				myNode->data->dispaly();
			}
			else if (choose == 8) {
				string newValue;
				cout << "Please input the new value: ";
				cin.ignore();
				getline(cin, newValue);
				myNode->data->StateFull = newValue;
				system("cls");
				cout << "------------------------------------------------" << endl;
				cout << "Modification success!" << endl;
				cout << "------------------------------------------------" << endl;
				cout << "The following is the record you want to modify." << endl;
				myNode->data->dispaly();
			}
			else if (choose == 9) {
				string newValue;
				cout << "Please input the new value: ";
				cin.ignore();
				getline(cin, newValue);
				myNode->data->ZipCode = newValue;
				system("cls");
				cout << "------------------------------------------------" << endl;
				cout << "Modification success!" << endl;
				cout << "------------------------------------------------" << endl;
				cout << "The following is the record you want to modify." << endl;
				myNode->data->dispaly();
			}
			else if (choose == 10) {
				string newValue;
				cout << "Please input the new value: ";
				cin.ignore();
				getline(cin, newValue);
				myNode->data->CountryFull = newValue;
				system("cls");
				cout << "------------------------------------------------" << endl;
				cout << "Modification success!" << endl;
				cout << "------------------------------------------------" << endl;
				cout << "The following is the record you want to modify." << endl;
				myNode->data->dispaly();
			}
			else if (choose == 11) {
				string newValue;
				cout << "Please input the new value: ";
				cin.ignore();
				getline(cin, newValue);
				myNode->data->TelephoneCountryCode = newValue;
				system("cls");
				cout << "------------------------------------------------" << endl;
				cout << "Modification success!" << endl;
				cout << "------------------------------------------------" << endl;
				cout << "The following is the record you want to modify." << endl;
				myNode->data->dispaly();
			}
			else if (choose == 12) {
				string newValue;
				cout << "Please input the new value: ";
				cin.ignore();
				getline(cin, newValue);
				myNode->data->TelephoneNumber = newValue;
				system("cls");
				cout << "------------------------------------------------" << endl;
				cout << "Modification success!" << endl;
				cout << "------------------------------------------------" << endl;
				cout << "The following is the record you want to modify." << endl;
				myNode->data->dispaly();
			}

			else if (choose == 13) {
				string newValue;
				cout << "Please input the new value: ";
				cin.ignore();
				getline(cin, newValue);
				myNode->data->EmailAddress = newValue;
				system("cls");
				cout << "------------------------------------------------" << endl;
				cout << "Modification success!" << endl;
				cout << "------------------------------------------------" << endl;
				cout << "The following is the record you want to modify." << endl;
				myNode->data->dispaly();
			}

			else if (choose == 14) {
				string newValue;
				cout << "Please input the new value: ";
				cin.ignore();
				getline(cin, newValue);
				myNode->data->Occupation = newValue;
				system("cls");
				cout << "------------------------------------------------" << endl;
				cout << "Modification success!" << endl;
				cout << "------------------------------------------------" << endl;
				cout << "The following is the record you want to modify." << endl;
				myNode->data->dispaly();
			}

			else if (choose == 15) {
				string newValue;
				cout << "Please input the new value: ";
				cin.ignore();
				getline(cin, newValue);
				myNode->data->Company = newValue;
				system("cls");
				cout << "------------------------------------------------" << endl;
				cout << "Modification success!" << endl;
				cout << "------------------------------------------------" << endl;
				cout << "The following is the record you want to modify." << endl;
				myNode->data->dispaly();
			}
			else if (choose == -1) {
				system("cls");
				break;

			}
		} while (true);
	}
}

void deletion(AVLTree* myTree) {

	cout << "Please enter the phone number: ";
	long long number;
	cin >> number;
	AVLNode* myNode = myTree->findNode(myTree->root, number);
	if (myNode) {
		myTree->root = myTree->deleteNode(myTree->root, number);
		system("cls");
		cout << "------------------------------------------------" << endl;
		cout << "Deletion success!" << endl;
		cout << "------------------------------------------------" << endl;
	}
	else {
		cout << "The record is not exist." << endl;
	}

}

void search(AVLTree* myTree) {
	do {
		cout << "------------------------------------------------" << endl;
		cout << "Select your searching criteria" << endl;
		cout << "------------------------------------------------" << endl;
		cout << "1) Phone number" << endl;
		cout << "2) Other" << endl;
		cout << "-1) Return to main menu" << endl;
		cout << "Please input your choice" << endl;
		int choose;
		cin >> choose;
		if (choose == 1) {
			long long number;
			cout << "Please input the phone number: ";
			cin >> number;
			AVLNode* myNode = myTree->findNode(myTree->root, number);
			system("cls");
			cout << "The following is the record." << endl;
			if (myNode)
				myNode->data->dispaly();
			else {
				system("cls");
				cout << "The record is not exist.";
			}
			cout << endl;

		}
		else if (choose == 2) {
			system("cls");
			cout << "------------------------------------------------" << endl;
			cout << "Please enter the attributes you know. Enter -1 if you don't know a attribute." << endl;
			string Title;
			string Surname;
			string Givenname;
			string Gender;
			string Birthday;
			string StreetAddress;
			string City;
			string StateFull;
			string ZipCode;
			string CountryFull;
			string TelephoneCountryCode;
			string EmailAddress;
			string Occupation;
			string Company;
			cin.ignore();
			cout << "Title: " << endl;
			getline(cin, Title);
			cout << "Surname: " << endl;
			getline(cin, Surname);
			cout << "Given name: " << endl;
			getline(cin, Givenname);
			cout << "Gender: " << endl;
			getline(cin, Gender);
			cout << "Brithday: " << endl;
			getline(cin, Birthday);
			cout << "Street address: " << endl;
			getline(cin, StreetAddress);
			cout << "City: " << endl;
			getline(cin, City);
			cout << "State: " << endl;
			getline(cin, StateFull);
			cout << "Zip code: " << endl;
			getline(cin, ZipCode);
			cout << "Country: " << endl;
			getline(cin, CountryFull);
			cout << "Telephone country code :" << endl;
			getline(cin, TelephoneCountryCode);
			cout << "Email address: " << endl;
			getline(cin, EmailAddress);
			cout << "Occupation: " << endl;
			getline(cin, Occupation);
			cout << "Company: " << endl;
			getline(cin, Company);
			cout << endl;
			myTree->findNodes(myTree->root, Title, Surname, Givenname, Gender, Birthday, StreetAddress, City, StateFull, ZipCode, CountryFull, TelephoneCountryCode, EmailAddress, Occupation, Company);
		}
		else if (choose == -1) {
			system("cls");
			break;
		}
		else
			cout << "------------------------------------------------" << endl;
		"Please enter again!";

	} while (true);

}

void printAll(AVLTree* myTree) {
	myTree->inOrder(myTree->root);
}

person getData(person *Person, string str) {

	int count = 0;
	for (char& ch : str)                                     //read the string character by character
	{
		if (ch == '\t')
			count++;
		else if (count == 0 && ch != '\t')
			Person->Title += ch;
		else if (count == 1 && ch != '\t')
			Person->Surname += ch;
		else if (count == 2 && ch != '\t')
			Person->Givenname += ch;
		else if (count == 3 && ch != '\t')
			Person->Gender += ch;
		else if (count == 4 && ch != '\t')
			Person->Birthday += ch;
		else if (count == 5 && ch != '\t')
			Person->StreetAddress += ch;
		else if (count == 6 && ch != '\t')
			Person->City += ch;
		else if (count == 7 && ch != '\t')
			Person->StateFull += ch;
		else if (count == 8 && ch != '\t')
			Person->ZipCode += ch;
		else if (count == 9 && ch != '\t')
			Person->CountryFull += ch;
		else if (count == 10 && ch != '\t')
			Person->TelephoneCountryCode += ch;
		else if (count == 11 && ch != '\t') {
			if (ch != '(' && ch != ')' && ch != '-' && ch != ' ')
				Person->TelephoneNumber += ch;
		}
		else if (count == 12 && ch != '\t') {
			Person->EmailAddress += ch;
		}
		else if (count == 13 && ch != '\t')
			Person->Occupation += ch;

		else if (count == 14 && ch != '\t')
			Person->Company += ch;
	}
	return *Person;
}
