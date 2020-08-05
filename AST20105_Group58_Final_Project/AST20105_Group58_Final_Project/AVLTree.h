#ifndef AVLTREE_H
#define AVLTREE_H

#include "AVLNode.h"
#include "person.h"
class AVLTree {
public:
	AVLNode* root;
	AVLNode* temp;

	AVLTree();
	~AVLTree();
	void deleteAll(AVLNode* n);
	int getBalance(AVLNode* N);
	AVLNode* findNode(AVLNode* n, long long v);
	void findNodes(AVLNode* n, string& Title, string& Surname, string& Givenname, string& Gender, string& Birthday, string& StreetAddress, string& City, string& StateFull, string& ZipCode, string& CountryFull, string& TelephoneCountryCode, string& EmailAddress, string& Occupation, string& Company);
	AVLNode* findMin(AVLNode* n);
	int height(AVLNode* p);
	int max(int l, int r);
	AVLNode* singleRotateWithLeft(AVLNode* k2);
	AVLNode* singleRotateWithRight(AVLNode* k1);
	AVLNode* doubleRotateWithLeft(AVLNode* k);
	AVLNode* doubleRotateWithRight(AVLNode* k);
	AVLNode* insert(person* x, AVLNode* t);
	AVLNode* deleteNode(AVLNode* t, long long key);
	void inOrder(AVLNode* n);
	void outputData(AVLNode* n, string &allRecords);
};
#endif // !AVLTREE_H

