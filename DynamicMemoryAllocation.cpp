#include<iostream>
using namespace std;
int main(){
	int a = 20;
	int *ptr = &a;
	cout<<"value of a is : " <<*(ptr) <<endl;
	int *p = new int(50);
	cout<<"value at address p is : " <<*(p) <<endl;
	cout<<"address p is : " <<(p) <<endl;
	cout<<"Size of p is : " <<sizeof(p) <<endl;
	
	
	void *p1 = new float(50.69);
	cout<<"value at address p1 is : " <<*(float*)(p1) <<endl;
	cout<<"address p1 is : " <<(p1) <<endl;
	cout<<"Size of p1 is : " <<sizeof(p1) <<endl;
	
}
