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
void printlist(struct node *head)
{
	struct node *current = head;
	while(current != NULL){
		printf("%d -> ",current -> data);
		current = current -> next;
	}
}


int length(struct node *node)
{
	int length = 0;
	struct node *current = node;
	while(current != NULL){
		length++;
		current = current -> next;
	}
	return length;
}


/*void append(struct node **aref, struct node **bref)
{
	struct node *current;
	if(*aref == NULL)
		*aref = *bref;
	else {
		current = *aref;
		while(current -> next != NULL)
			current = current -> next;
		current -> next = *bref;
	}
	*bref = NULL;
}
*/

void frontbacksplit(struct node *source, struct node **frontref, struct node **backref)
{
	int len = 0, count;
	struct node *current;
	len = length(source);
	current = source;
	if(len < 2){
		*frontref = source;
		*backref = NULL;
	}
	else {
		count = (len -1) / 2;
		while(count){
			current = current -> next;
			count --;
		}
		*frontref = source;
		*backref = current -> next;
		current -> next = NULL;
	}
}

main()
{
	int ch = 1,element;
	struct node *source,*front,*back;
	source = front = back = NULL;
	while(ch == 1){
		printf("Enter the number for list1\n");
		scanf("%d",&element);
		push(&source,element);
		printf("If you want to enter more press 1 else 0\t");
		scanf("%d",&ch);
	}
	printlist(source);
	printf("\n");
	frontbacksplit(source, &front, &back);
	printlist(front);
	printf("\n");
	printlist(back);
	printf("\n");
	return 0;
}

