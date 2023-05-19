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


void movenode(struct node **destref, struct node **sourceref)
{
	struct node *temp = *sourceref;
	if(*sourceref == NULL){
		printf("Error\n");
		return;
	}
	*sourceref = temp -> next;
	temp -> next = *destref;
	*destref = temp;
}

/*struct node *shufflemerge(struct node *a, struct node *b)
{
	struct node dummy;
	struct node *tail = &dummy;
	dummy.next = NULL;

	while(1){
		if(a == NULL){
			tail -> next = b;
			break;
		}
		else if(b == NULL){
			tail -> next = a;
			break;
		}
		else {
			tail -> next = a;
			tail = a;
			a = a-> next;
			tail -> next = b;
			tail = b;
			b = b -> next;
		}
	}	
	return dummy.next;
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

struct node *sortedmerge(struct node *a, struct node *b)
{
	struct node dummy;
	struct node *tail = &dummy;
	dummy.next = NULL;
	while(1){
		if(a == NULL){
			tail -> next = b;
			break;
		}
		if(b == NULL){
			tail -> next = a;
		       break;
		}
		if(a -> data <= b -> data)
			movenode(&(tail -> next), &a);
		else
			movenode(&(tail -> next), &b);
		tail = tail -> next;
	}
	return dummy.next;
}

void mergesort(struct node **headref)
{
	struct node *head = *headref;
	struct node *a, *b;
	if(head == NULL || head -> next == NULL)
		return;
	frontbacksplit(head, &a, &b);
	mergesort(&a);
	mergesort(&b);
	*headref = sortedmerge(a,b);
}

main()
{
	int ch = 1,element;
	struct node *source;
	source = NULL;
	while(ch == 1){
		printf("Enter the number for list1\n");
		scanf("%d",&element);
		push(&source,element);
		printf("If you want to enter more press 1 else 0\t");
		scanf("%d",&ch);
	}
	printlist(source);
	printf("\n");
	mergesort(&source);
	printlist(source);
	return 0;
}


		



