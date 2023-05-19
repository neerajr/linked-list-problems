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

void append(struct node **aref, struct node **bref)
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

main()
{
	int ch = 1,element;
	struct node *ahead, *bhead;
	ahead = bhead = NULL;
	while(ch == 1){
		printf("Enter the number for list1\n");
		scanf("%d",&element);
		push(&ahead,element);
		printf("If you want to enter more press 1 else 0\t");
		scanf("%d",&ch);
	}
	ch = 1;
	while(ch == 1){
		printf("Enter the number for list2\n");
		scanf("%d",&element);
		push(&bhead,element);
		printf("If you want to enter more press 1");
		scanf("%d",&ch);
	}
	printlist(ahead);
	printf("\n");
	printlist(bhead);
	printf("\n");
	append(&ahead, &bhead);
	printlist(ahead);
	return 0;
}


		



