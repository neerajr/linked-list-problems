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
        int ch = 1,element;
        struct node *source, *dest, *result;
        source = dest = NULL;
        while(ch == 1){
                printf("Enter the number for list1\n");
                scanf("%d",&element);
                push(&source,element);
                printf("If you want to enter more press 1 else 0\t");
                scanf("%d",&ch);
        }
        ch = 1;
        while(ch == 1){
                printf("Enter the number for list2\n");
                scanf("%d",&element);
                push(&dest,element);
                printf("If you want to enter more press 1");
                scanf("%d",&ch);
        }
        printlist(source);
        printf("\n");
        printlist(dest);
        printf("\n");
        result = sortedmerge(source, dest);
        printlist(result);
        return 0;
}

