#include<iostream>
#include<thread>
using namespace std;
int a=0,b=0;
void addition(){
	a = 1+ (rand() % 100);
	b = 1 + (rand() % 100);
}

int main(){
	thread t(&addition);
	t.join();
	cout<<a+b<<"\n";
	return 0;
}
