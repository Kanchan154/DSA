#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *top = NULL;

void push(int x){
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = x;
	new_node->next = top;
	top = new_node;
}

void pop(){
	struct node *temp = top;
	if(top == NULL){
		printf("There is no element in the Stack");
	}
	else{
		top = top->next;
		free(temp);
	}
	
	
}


void peak(){
	if(top == NULL){
		printf("\n Stack is Empty ");
	}
	printf("Element in peak is : %d",top->data);
}

void display(){
	struct node *temp = top;
	if(top == NULL){
		printf("Given Stack is Empty \n");
	}
	else{
		while(temp != NULL){
			printf("\n %d",temp->data);
			temp = temp->next;
		}
	}	
}

void countin_Stack(){
	int count = 0;
	struct node *temp = top;
	while(temp != NULL){
		count++;
		temp = temp->next;
	}
	printf("\n Number of ELements in the Stack is : %d",count);
}


int main(){
	push(68);
	push(75);
	push(87);
	push(78);
	display();
	printf("\n *********************************** \n");
	countin_Stack();
	
	
	printf("\n \n ******************************** \n \n");
	printf("Stack after poping the top element");
	
	pop();
	display();
	
	printf("\n ***********************************\n");
	peak();
	
	printf("\n *********************************** \n");
	countin_Stack();
	
	
}
