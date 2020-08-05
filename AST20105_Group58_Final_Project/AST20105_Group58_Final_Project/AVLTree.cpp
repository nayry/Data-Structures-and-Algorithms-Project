#include "AVLNode.h"
#include "AVLTree.h"
#include <fstream>
AVLTree::AVLTree() {
	root = NULL;
	temp = NULL;
}
AVLTree::~AVLTree(){
	deleteAll(root);
}

void AVLTree::deleteAll(AVLNode* n) {
	if (n != NULL) { 
		deleteAll(n->left); 
		deleteAll(n->right); 
		delete n->data;
		delete n;
	}
}
int AVLTree::getBalance(AVLNode* N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

AVLNode* AVLTree::findNode(AVLNode* n, long long v) {
	if (n == NULL) 
		return NULL; 
	long long key = stoull(n->data->TelephoneNumber);
	if (v < key) 
		return findNode(n->left, v); 
	else if (v > key) 
		return findNode(n->right, v);
	else return n;
}
void AVLTree::findNodes(AVLNode* n, string& Title, string& Surname, string& Givenname, string& Gender, string& Birthday, string& StreetAddress, string& City, string& StateFull, string& ZipCode, string& CountryFull, string& TelephoneCountryCode, string& EmailAddress, string& Occupation, string& Company) {
	if (n != NULL) {
		if ((Title == n->data->Title || Title == "-1") &&
			(Surname == n->data->Surname || Surname == "-1") &&
			(Givenname == n->data->Givenname || Givenname == "-1") &&
			(Gender == n->data->Gender || Gender == "-1") &&
			(Birthday == n->data->Birthday || Birthday == "-1") &&
			(StreetAddress == n->data->StreetAddress || StreetAddress == "-1") &&
			(City == n->data->City || City == "-1") &&
			(StateFull == n->data->StateFull || StateFull == "-1") &&
			(ZipCode == n->data->ZipCode || ZipCode == "-1") &&
			(CountryFull == n->data->CountryFull || CountryFull == "-1") &&
			(TelephoneCountryCode == n->data->TelephoneCountryCode || TelephoneCountryCode == "-1") &&
			(EmailAddress == n->data->EmailAddress || EmailAddress == "-1") &&
			(Occupation == n->data->Occupation || Occupation == "-1") &&
			(Company == n->data->Company || Company == "-1")
			) {
			n->data->dispaly();
		}
		findNodes(n->left, Title, Surname, Givenname, Gender, Birthday, StreetAddress, City, StateFull, ZipCode, CountryFull, TelephoneCountryCode, EmailAddress, Occupation, Company);
		findNodes(n->right, Title, Surname, Givenname, Gender, Birthday, StreetAddress, City, StateFull, ZipCode, CountryFull, TelephoneCountryCode, EmailAddress, Occupation, Company);

	}
}

AVLNode* AVLTree::findMin(AVLNode* n) {
	if (n == NULL) 
		return NULL; 
	else if (n->left == NULL) 
		return n;
	else return 
		findMin(n->left);
}

int AVLTree::height(AVLNode* p)
{
	if (p == NULL)
		return -1;
	else
		return p->height;
}
int AVLTree::max(int l, int r)
{
	if (l > r)
		return l;
	else
		return r;
}

AVLNode* AVLTree::singleRotateWithLeft(AVLNode* k2) {
	AVLNode* k1;
	k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2->height = max(height(k2->left), height(k2->right)) + 1;
	k1->height = max(height(k1->left), k2->height) + 1;
	return k1;
}
AVLNode* AVLTree::singleRotateWithRight(AVLNode* k1) {
	AVLNode* k2;
	k2 = k1->right;
	k1->right = k2->left;
	k2->left = k1;
	k1->height = max(height(k1->left), height(k1->right)) + 1;
	k2->height = max(height(k2->right), k1->height) + 1;
	return k2;
}
AVLNode* AVLTree::doubleRotateWithLeft(AVLNode* k) {
	k->left = singleRotateWithRight(k->left);
	return singleRotateWithLeft(k);
}
AVLNode* AVLTree::doubleRotateWithRight(AVLNode* k) {
	k->right = singleRotateWithLeft(k->right);
	return singleRotateWithRight(k);
} 

AVLNode* AVLTree::insert(person* x, AVLNode* t) {
	long long key = stoull(x->TelephoneNumber);
	if (t == NULL) {
		t = new AVLNode(x);
		if (t == NULL) {
			cout << "Out of memory" << endl; exit(1);
		}
	}
	else {
		long long rootKey = stoull(t->data->TelephoneNumber);
		if (key < rootKey) {
			t->left = insert(x, t->left);
			if (height(t->left) - height(t->right) >= 2) {
				long long leftKey = stoull(t->left->data->TelephoneNumber);
				if (key < leftKey)
					t = singleRotateWithLeft(t);
				else
					t = doubleRotateWithLeft(t);
			}
		}
		else
			if (key > rootKey) {
				t->right = insert(x, t->right);
				if (height(t->right) - height(t->left) >= 2) {
					long long rightKey = stoull(t->right->data->TelephoneNumber);
					if (key > rightKey)
						t = singleRotateWithRight(t);
					else
						t = doubleRotateWithRight(t);
				}
			}
	}
	t->height = max(height(t->left), height(t->right)) + 1;
	return t;
}

AVLNode* AVLTree::deleteNode(AVLNode* t, long long key) {
	if (t == NULL)
		return t;
	long long rootKey = stoull(t->data->TelephoneNumber);
	if (key < rootKey)
		t->left = deleteNode(t->left, key);
	else if (key > rootKey)
		t->right = deleteNode(t->right, key);
	else {
		if (t->left == NULL || t->right == NULL) {
			AVLNode *temp = t->left ? t->left : t->right;

			if (temp == NULL)
			{
				temp = t;
				t = NULL;
			}
			else
				*t = *temp;
			free(temp->data);
			free(temp);
		}
		else {
			AVLNode* temp = findMin(t->right);
			delete t->data;
			t->data = new person(*temp->data);
			long long key2 = stoull(t->data->TelephoneNumber);
			t->right = deleteNode(root->right, key2);
		}
	}
	if (t == NULL)
	return t;

	t->height = 1 + max(height(t->left), height(t->right));
	int balance = getBalance(t);

	if (balance > 1 && getBalance(t->left) >= 0)
		return singleRotateWithLeft(t);
	if (balance>1 && getBalance(t->right)<0)
	{
		t->left = singleRotateWithRight(t->left);
		return singleRotateWithLeft(t);
	}

	if (balance < -1 && getBalance(t->right) <= 0)
		return singleRotateWithRight(t);

	// Right Left Case
	if (balance < -1 && getBalance(t->right) > 0)
	{

		t->right = singleRotateWithLeft(t->right);
		return singleRotateWithRight(t);
	}

	return t;
}

void AVLTree::inOrder(AVLNode* n) { 
	if (n != NULL) {
		inOrder(n->left);
		cout << n->data->Title << " " << n->data->Surname << " " << n->data->Givenname << endl;
		cout << n->data->Gender << endl;
		cout << n->data->Birthday << endl;
		cout << n->data->StreetAddress << endl;
		cout << n->data->City << endl;
		cout << n->data->StateFull << endl;
		cout << n->data->ZipCode << endl;
		cout << n->data->CountryFull << endl;
		cout << n->data->TelephoneCountryCode << endl;
		cout << n->data->TelephoneNumber << endl;
		cout << n->data->EmailAddress << endl;
		cout << n->data->Occupation << endl;
		cout << n->data->Company << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		inOrder(n->right);
	}
}
void AVLTree::outputData(AVLNode* n, string &allRecords) {
	if (n != NULL) {
		outputData(n->left,allRecords);
		allRecords += n->data->Title + "\t" + n->data->Surname + "\t" + n->data->Givenname + "\t"
		+ n->data->Gender + "\t" +
		n->data->Birthday + "\t" +
		n->data->StreetAddress + "\t" +
		n->data->City + "\t" +
		n->data->StateFull + "\t" +
		n->data->ZipCode + "\t" +
		n->data->CountryFull + "\t" +
		n->data->TelephoneCountryCode + "\t" +
		n->data->TelephoneNumber + "\t" +
		n->data->EmailAddress + "\t" +
		n->data->Occupation + "\t" +
		n->data->Company + " \n";
		outputData(n->right,allRecords);
	}
}

