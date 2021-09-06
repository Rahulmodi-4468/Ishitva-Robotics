#include <bits/stdc++.h>
using namespace std;

// Structure of Product Details
class Node {
public:
	int ProductID;
	string ProName;
	string ProDESC;
	float price;
	Node* next;
};

Node* head = new Node();

// Product is Already Exist or Not
bool check(int id)
{
	if (head == NULL)
		return false;

	Node* t = new Node;
	t = head;

	// Traverse the Linked List
	while (t != NULL) {
		if (t->ProductID == id)
			return true;
		t = t->next;
	}

	return false;
}

//  Insert the record
void Insert_Product(int id, string Name,string Desc, float price)
{
	// Check Record Already Exist or Not
	if (check(id)) {
		cout << "Product with this record Already Exists\n";
		return;
	}

	// Create new Node to Insert Record
	Node* t = new Node();
	t->ProductID = id;
	t->ProName = Name;
	t->ProDESC = Desc;
	t->price = price;
	t->next = NULL;

	// Insert at Begin
	if (head == NULL || (head->ProductID >= t->ProductID)) {
		t->next = head;
		head = t;
	}

	// Insert at middle or End
	else {
		Node* temp = head;
		while (temp->next != NULL && temp->next->ProductID < t->ProductID) {
			temp = temp->next;
		}
		t->next = temp->next;
		temp->next = t;
	}

	cout << "Product Inserted Successfully\n";
}


void Search_Product(int id)
{
	// if head is NULL
	if (!head) {
		cout << "No such Product Available"<<endl;
		return;
	}
	else {
		Node* p = head;
		while (p) {
			if (p->ProductID == id ) {
				cout << "Product ID  \t\t"<< p->ProductID << endl;
				cout << "Product Name\t\t"<< p->ProName << endl;
				cout << "Product Description\t"<< p->ProDESC << endl;
				cout << "Product Price\t\t"	<< p->price << endl;
				return;
			}
			p = p->next;
		}

		if (p == NULL)
			cout << "No such product Available\n";
	}
}
//Delete Record from LL
int Delete_Product(int id)
{
	Node* t = head;
	Node* p = NULL;

	// Deletion at Begin
	if (t != NULL && t->ProductID == id) {
		head = t->next;
		delete t;

		cout << "Product Deleted Successfully\n";
		return 0;
	}

	// Deletion Other than Begin
	while (t != NULL && t->ProductID != id) {
		p = t;
		t = t->next;
	}
	if (t == NULL) {
		cout << "Product does not Exist\n";
		return -1;
		p->next = t->next;

		delete t;
		cout << "Product Deleted Successfully\n";

		return 0;
	}
}

void Display_Products()
{
	Node* p = head;
	if (p == NULL) {
		cout << "No Product's Available\n";
	}
	else {
		cout << "ProductID ProductName Product_Description Product_Price\n";

		while (p != NULL) {
			cout << p->ProductID << " \t"<< p->ProName << "\t"
				<< p->ProDESC << "\t"<< p->price << endl;
			p = p->next;
		}
	}
}

