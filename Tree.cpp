#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left, *right;
};

struct node *create(){
	struct node *temp;
	struct node *new_node;
	int data,choice;
	new_node = (struct node*)malloc(sizeof(struct node));
	printf("\n Press 0 for exit");
	printf("\n Press 1 for new node");
	printf("\n Enter the choice :  ");
	scanf("%d",&choice);
	
	
	if(choice == 0){
		return 0;
	}
	else{
		printf("\n Enter the data : ");
		scanf("%d",&data);
		new_node->data = data;
		printf("\n Enter the left child :");
		new_node->left = create();
		printf("\n Enter the right child : ");
		new_node->right = create();
		return new_node;
	}
	
}
	

int main(){
	struct node *root;
	root = create();
    return 0;	
	
}

