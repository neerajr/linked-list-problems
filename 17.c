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

static void reverse(struct node **headref)
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
	reverse(&head);
	printf("\t reversed ");
	printlist(head);
	return 0;
}


		



