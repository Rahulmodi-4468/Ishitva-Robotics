#include "ProductManagement.h"
int main()
{
	head = NULL;
	int id;
	string Name, desc;
	float price;

	while (true) {
		cout << "\n\t\tWelcome to Product Management System"
		        "\n\n\tPress\n\t1 to Insert a new Product Record"
		        "\n\t2 to delete a product"
		        "\n\t3 to Search a Product Record"
		        "\n\t4 to view all Product's Details"
		        "\n\t5 to Exit\n";
		cout << "\nEnter your Choice\n";
		int Choice;

		cin >> Choice;
		if (Choice == 1) {
			cout << "Enter Product ID : ";
			cin >> id;
			cout << "Enter Name of Product : ";
			cin >> Name;
			cout << "Enter Description of Product : ";
			cin >> desc;
			cout << "Enter Price of Product : ";
			cin >> price;
			Insert_Product(id, Name, desc, price);
		}
		else if (Choice == 2) {
			cout << "Enter Product ID whose Details is to be deleted\n";
			cin >> id;
			Delete_Product(id);
		}
		else if (Choice == 3) {
			cout << "Enter Product ID whose record you want to Search\n";
			cin >> id;
			Search_Product(id);
		}
		else if (Choice == 4) {
			Display_Products();
		}
		else if (Choice == 5) {
			exit(0);
		}
		else {
			cout << "Invalid Choice... Try Again\n";
		}
	}
	return 0;
}
