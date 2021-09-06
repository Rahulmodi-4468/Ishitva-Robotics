#include<string>
#include<iostream>
#include<fstream>
#include<exception>
using namespace std;

class category{
    private:
    	string catId;
    	string catName;
    public:
    void setCatID(string catId){
        this->catId = catId;
    }
    void setCatName(string catName){
        this->catName = catName;
    }
    string getCatID(){
    	return catId;	
	}
	string getCatName(){
		return catName;
	}
};

class Product : public category{
    
    private:
        string productId;
        string name ;
        string desc;
        float price;
        
    public:
    Product(){
        this->productId = "";
        this->name = "";
        this->desc = "";
        this->price = 0;
        
    }
    
    void setData(){
    	string catId,catName;
        cout << "Enter the Category ID : ";
        cin>>catId;
        setCatID(catId);
        cout << "Enter the Category Name : ";
        cin >> catName;
        setCatName(catName);
        cout << "Enter the Product ID : ";
        cin >> productId;
        cout << "Enter the Product Name : ";
        cin >> name;
        cin.ignore();
        cout << "Enter the Description : ";
        cin >> desc;
        cout << "Enter the Price : ";
        cin >> price;
        
              
        ofstream write;
        write.open("productsDetails.txt",ios::app);
        write<<catId<<" "<<catName<<" "<<productId<<" "<<name<<" "<<desc<<" "<<price<<endl;
    	write.close();
		
		
    }
    void printData(){
    
      	ifstream read;
		read.open("productsDetails.txt");
		
		cout <<"CatID  CatName ProductId Product_name Product_desc Price"<<endl;
		
		if ( read.is_open())  
		{
	    	string line;
	    	while (getline(read, line)) {
	    	    cout<<line<<endl;
	    	}
	    	read.close();
		}
		
    }

    
};
//class NegativeValException : public exception{  
//    public:  
//        const char * what() const throw()  
//        {  
//            return "Negative value not allowed!\n";  
//        }  
//};

