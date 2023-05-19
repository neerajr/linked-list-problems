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

void printlist(struct node *head)
{
        struct node *current = head;
        while(current != NULL){
                printf("%d -> ",current -> data);
                current = current -> next;
        }
}

void push(struct node **head,int data)
{
	struct node *temp;
	temp = makenode(temp, data);
	temp -> next = *head;
	*head = temp;
}

/*static void reverse(struct node **headref)
{
	struct node *result = NULL;
	struct node *current = *headref;
	struct node *next;
	while(current != NULL){
		next = current -> next;
		current -> next = result;
		result = current;
		current = next;
	}
	*headref = result;
}	
*/

void recursive_reverse(struct node **headref)
{
	struct node *first, *rest;
	if(*headref == NULL)
		return;
	first = *headref;
	rest = first -> next;
	if(rest == NULL)
		return;
	recursive_reverse(&rest);
	first -> next -> next = first;
	first -> next = NULL;
	*headref = rest;
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
	printf("Original ");
	printlist(head);
	recursive_reverse(&head);
	printf("\t reversed ");
	printlist(head);
	return 0;
}


		



