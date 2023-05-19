#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
};

struct node *makenode(int data)
{
	struct node *node;
	node = (struct node*) malloc(sizeof(struct node));
	node -> next = NULL;
	node -> data = data;
	return node;
}

void push(struct node **head,int data)
{
	struct node *temp;
	temp = makenode(data);
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

/*void insertnth(struct node **headref,int data, int pos)
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
*/

void sortedinsert(struct node **headref, struct node *newnode)
{
	if(*headref == NULL || (*headref) -> data >= newnode -> data){
		newnode -> next = *headref;
		*headref = newnode;
	}
	else {
		struct node *current = *headref;
		while(current -> next != NULL && current -> next -> data < newnode ->data)
			current = current -> next;
		newnode -> next = current -> next;
		current -> next = newnode;
	}
}

void insertsort(struct node **headref)
{
	struct node *new,*current,*next;
	current = *headref;
	while(current != NULL){
		next = current -> next;
		sortedinsert(&new, current);
		current = next;
	}
	*headref = new;
}


main()
{
	int ch = 1, element;
	struct node *head = NULL;
	while(ch == 1){
		printf("Enter the element\t");
		scanf("%d",&element);
		push(&head, element);
		printf("press 1 to contiue\t");
		scanf("%d",&ch);
	}
	printlist(head);
	insertsort(&head);
	printf("\nAfter sorting\n");
	printlist(head);
	return 0;
}



