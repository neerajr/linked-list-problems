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

int count(struct node *node, int searchfor)
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


main()
{
	int ch = 1,element;
	struct node *head = NULL;
	while(ch == 1){
		printf("Enter the number\n");
		scanf("%d",&element);
		push(&head,element);
		printf("If you want to enter more press 1 else 0\t");
		scanf("%d",&ch);
	}
	printf("Enter the element to search\t");
	scanf("%d",&element);
	printf("Found %d times\n",count(head,element));
	return 0;
}


		



