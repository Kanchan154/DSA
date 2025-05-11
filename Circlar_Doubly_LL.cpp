#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;//theoritically the size is 4byte but actually the size is 8byte
	struct node *next;//8 byte
	struct node *prev;//8 byte
};

void Doubly_Circular_LL(struct node *head,int val){
	struct node *ptr;
	ptr->data = val;
	struct node *temp = head;
	if(head == NULL){
		head = ptr;
	}
	else{
		head = head->next;
		head->prev = ptr;
		ptr = temp;
	}
}

int main(){
	struct node *head = (struct node*)malloc(sizeof(struct node));
	
}
