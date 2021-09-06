#include<bits/stdc++.h>
#include "User.h"
#include "products.h"

int main(){
	
 	UserRegistration newObj;
	int choice;
	cout<<"\n1: Register\n2: Login\nEnter Your Choice: ";
	cin>>choice;
	int flag=0;
	if(choice == 1)
	{
		newObj.Register();
		flag=1;
	}
	else if(choice == 2)
	{
		newObj.Login();	
		flag=1;	
	}
	if(flag == 1){
		again:
		cout<<"\n\t\t\t\t--------------------------Wellcome--------------------------"<<endl;
		cout<<"\t\t\t\t--------------------------------------------------------------"<<endl;
		cout<<"\t\t\t\t\t Add Product Details Press Y|y :"<<endl;
		cout<<"\t\t\t\t\t Display All Products Details Press D|d:"<<endl;
		cout<<"\t\t\t\t\t Logout press Any Key except y|Y & d|D"<<endl;
		cout<<"\t\t\t\t--------------------------------------------------------------"<<endl;
		char ch;
		cin>>ch;
		if(ch == 'Y' || ch == 'y'){
			Product p;
			p.setData();
			goto again;
		}
		else if(ch == 'D' || ch == 'd'){
			
			Product q;
			q.printData();
			system("PAUSE");
		}
		else{
			cout<<"LogOut.......\nExiting........";
			exit(0);
		}
	}
}

