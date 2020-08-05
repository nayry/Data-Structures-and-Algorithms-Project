#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "AVLTree.h"

void insert(AVLTree* myTree);					//insert a data after inputted all requied information and back to Main Mennu
void modify(AVLTree* myTree);					//modify a existing record and check the input number is existing or not
void deletion(AVLTree* myTree);					//delete by a phone number and check the phone number's data is exis or not
void search(AVLTree* myTree);					//search a data by phone number or other 14 criteria
void printAll(AVLTree* myTree);					//print all with asending order
person getData(person *son, string str);		//get the string and change it to different data

#endif