#include<iostream>
#include<stdlib.h>
using namespace std;

class node{
	public:
		int value,pos;
		node *next;
	node(){
		value = 0;
		next = NULL;
	}
};

class LinkedList{
	node *head;
	int size;
	public:
		LinkedList(){
			head = NULL;
		}
		
		void insertAtEnd(int v){
			node *temp = new node();
			node *p = head;
			temp -> value = v;
			temp->next = head;
			
		if(head == NULL){
			temp->next = temp;
			head = temp;
		}
		else{
			while(p->next!=head){
				p = p -> next;
				}
			p -> next = temp;
			}
		}
		
		
		void printLL(){
		node *t = head;
		do{
			cout << t -> value << "  ";
			t = t -> next;
		}
		while(t != head);

		cout << endl << endl;
		}
	
	};
	
	int main(){
		LinkedList l1;
		l1.insertAtEnd(45);
		l1.insertAtEnd(456);
		l1.printLL();
	}
	
	

