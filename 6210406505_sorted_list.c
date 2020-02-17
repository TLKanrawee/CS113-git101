//6210406505 Kanrawee Petchonlakram
#include <stdio.h>
#include <stdlib.h>
struct Node
{
   int data;
   struct Node *next;
};

void sorted(struct Node** head_ref, struct Node* new_node)
{
    struct Node* nodE;
    if(*head_ref == NULL || (*head_ref)->data >= new_node->data){
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else{
        nodE = *head_ref;
        while(nodE->next!=NULL && nodE->next->data < new_node->data){
            nodE = nodE->next;
        }
        new_node->next = nodE->next;
        nodE->next = new_node;
    }
}

struct Node *newNode(int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;

    return new_node;
}

void printing(struct Node *head)
{
    struct Node *temp = head;
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main()
{
    struct Node* head = NULL;
    int n;

    while(1){
        scanf("%d", &n);
        if(n>=0){
            struct Node *new_node = newNode(n);
            sorted(&head, new_node);
        }
        else if(n<0){
            break;
        }
    }

    printing(head);
}