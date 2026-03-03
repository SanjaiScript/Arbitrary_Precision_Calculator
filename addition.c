#include "apc.h"

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR){
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;
    int carry = 0, sum;

    while(temp1 || temp2 || carry){
        int d1 = (temp1) ? temp1->data : 0;
        int d2 = (temp2) ? temp2->data : 0;

        sum = d1 + d2 + carry;
        carry = sum / 10;
        insert_at_first(sum % 10, headR, tailR);

        if(temp1){
            temp1 = temp1->prev;
        }
        if(temp2){
            temp2 = temp2->prev;
        }
    }
    return SUCCESS;
}

int insert_at_first(int data, Dlist **head, Dlist **tail){
    Dlist *new = malloc(sizeof(Dlist));

    if(new == NULL){
        return FAILURE;
    }

    new -> data = data;
    new -> prev = NULL;
    new -> next = *head;

    if(*head == NULL){
        *tail = new;
    } 
    else{
        (*head)->prev = new;
    }

    *head = new;
    return SUCCESS;
    
}
