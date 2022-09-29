#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }

}


//Case 1

struct Node * deletefirst(struct Node * head){
    struct Node * ptr = head ;
    head = head ->next;
    free(ptr);
    return head;
}

//Case 2

struct Node * deleteatindex(struct Node * head , int index){

    struct Node * p = head ;
    struct Node * q = head -> next; 
    for (int i = 0; i < index -1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}
//Case 3

struct Node * deleteatend(struct Node * head){

    struct Node * p = head ;
    struct Node * q = head -> next; 
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

//Case 4

struct Node * deleteatvalue(struct Node * head , int value){

    struct Node * p = head ;
    struct Node * q = head -> next; 
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
         p->next = q-> next;
         free(q);
    }
    
    return head;
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 54;
    second->next = third;

    third->data = 45;
    third->next = fourth;

    fourth->data = 15;
    fourth->next = NULL;
    printf("linklist before deletion\n");
    linkedListTraversal(head);
    printf("\nlinklist after deletion\n");
    // head = deletefirst(head);
    // head = deleteatindex(head ,2);
   // head = deleteatend(head);
    head = deleteatvalue(head , 45);


    linkedListTraversal(head);
    return 0;
}