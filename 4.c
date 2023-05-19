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

/*int getNth(struct node *head ,int index)
{
	int count = 0;
	struct node *current = head;
	while(current != NULL){
		if(count == index)
			return(current -> data);
		count++;
		current = current -> next;
	}
	printf("Not found!!\n");
}	

*/

/*void deletelist(struct node **headref)
{
	struct node *current;
	struct node *temp;
	current = *headref;
	while(current != NULL){
		temp = current -> next;
		printf("Deleting element %d\n",current -> data);
		free(current);
		current = temp;
	}
	*headref = NULL;
	free(*headref);
	printf("Entire list is removed\n");
}

*/

int pop(struct node **headref)
{
	struct node *current = *headref;
	if(current != NULL){
		*headref = current -> next;
		int data = current -> data;
		free(current);
		return data;
	}
	else {
		printf("Empty list\n");
		return -1;
	}
}


main()
{
	int ch = 1,element,index;
	struct node *head = NULL;
	while(ch == 1){
		printf("Enter the number\n");
		scanf("%d",&element);
		push(&head,element);
		printf("If you want to enter more press 1 else 0\t");
		scanf("%d",&ch);
	}
	ch =1;
	while(ch == 1){
		printf("Enter 666 to pop the list\t");
		scanf("%d",&index);
		if(index == 666)
			printf("Poped value is : %d\n",pop(&head));
		printf("press 1 to continue\n");
		scanf("%d",&ch);
	}
	return 0;
}


		



