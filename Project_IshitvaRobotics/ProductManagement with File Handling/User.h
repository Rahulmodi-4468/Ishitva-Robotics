#include<bits/stdc++.h>
using namespace std;
class UserRegistration{
	
	
	public:
		static int counter;
		bool isLoggedIn();
		void Register();
		void Login();
};

bool UserRegistration :: isLoggedIn(){
	
	string username,password,uname,pwd;
	cout<<"Enter Username : ";
	cin>>username;
	cout<<"Enter  password : ";
	cin>>password;
	
	
 	vector< pair<string , string> > p;
	
	ifstream read("smart.txt");
    string s,s1;

    while( !read.eof() ){
        read >> s;
        read >> s1;

        p.push_back( make_pair(s,s1) );
    }

    read.close();

    for (int i=0; i<p.size(); i++){

        if(p[i].first == username && p[i].second == password){
            cout << "user found:\n";
            return true;
        }
        
    }
	return false;
}
void  UserRegistration :: Register(){
		string username,password;
		cout<<"Enter a username: ";
		cin>>username;	
		cout<<"Enter a password: ";
		cin>>password;

		ofstream file;
		file.open("smart.txt",ios::app);
		file<<username<<" "<<password<<endl;
		file.close();
		cout<<"User Registred Successfully\n";
		Login();
		
}
void  UserRegistration :: Login(){
	static int counter=0;
	bool status = isLoggedIn();
		if(!status){
			int ch;
			cout<<"User not Found";
			cout<<"\n-------------------------------------";
			cout<<"\nIF You Want to 'Register' press  : 1 : ";
			cout<<"\nIf You Want to 'Login' Try Again press : 2 : ";
			cout<<"\n-------------------------------------\n";
			cin>>ch;
			if(ch == 1){
				Register();
			}
			else if(ch == 2){
				counter++;
				if(counter >= 2){
					cout<<"\nYou must to Register First : \n";
					Register();
				}
				else{
					Login();
				}
				
			}
			
		}
		else{
			cout<<"Successfully Logged In......"<<endl;
			system("PAUSE");
		
		}
}



