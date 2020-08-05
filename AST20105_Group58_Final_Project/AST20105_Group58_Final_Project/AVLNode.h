#ifndef AVLNODE_H
#define AVLNODE_H
#include <iostream>
#include "person.h"
using namespace std;
class AVLNode
{
public:
	AVLNode(person* data) {
		this->data = data;
		height = 0;
		left = NULL;
		right = NULL;
	}
	person* data;
	int height;
	AVLNode* left;
	AVLNode* right;
};
#endif 

