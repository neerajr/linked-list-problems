#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
};

struct node *makenode(struct node *node, int data)
{
	node = (struct node*) malloc(sizeof(struct node));
	node -> next = NULL;
	node -> data = data;
	return node;
}

void push(struct node **head,int data)
{
	struct node *temp;
	temp = makenode(temp, data);
	temp -> next = *head;
	*head = temp;
}

/*int count(struct node *node, int searchfor)
{
	int count = 0;
	struct node *current = node;
	while(current != NULL){
		if(current -> data == searchfor)
			count++;
		printf("%d\t",count);
		current = current -> next;
	}
	return count;
}

*/
void printlist(struct node *head)
{
	struct node *current = head;
	while(current != NULL){
		printf("%d -> ",current -> data);
		current = current -> next;
	}
}

void insertnth(struct node **headref,int data, int pos)
{
	if(pos == 0)
		push(headref,data);
	else{
		struct node *current = *headref;
		while(current != NULL && pos-1){
			current = current -> next;
			pos--;
		}
		if(current != NULL){
			struct node *newnode = makenode(newnode,data);
			newnode -> next = current -> next;
			current -> next = newnode;
		}	
	}
}	

main()
{
	int ch = 1,element,pos;
	struct node *head = NULL;
	while(ch == 1){
		printf("Enter the element\n");
		scanf("%d",&element);
		printf("Emter the position\t");
		scanf("%d",&pos);
		insertnth(&head,element,pos);		
		printf("If you want to enter more press 1 else 0\t");
		scanf("%d",&ch);
	}
	printlist(head);
	return 0;
}


		



