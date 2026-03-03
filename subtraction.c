#include "apc.h"

// Returns 1 if num1 > num2, -1 if num1 < num2, 0 if equal
int compare(Dlist *head1, Dlist *head2) {
    // 1. Count digits in List 1
    int len1 = 0;
    Dlist *temp1 = head1;
    while (temp1) {
        len1++;
        temp1 = temp1->next;
    }

    // 2. Count digits in List 2
    int len2 = 0;
    Dlist *temp2 = head2;
    while (temp2) {
        len2++;
        temp2 = temp2->next;
    }

    // 3. Different lengths? The longer list is bigger
    if (len1 > len2) return 1;
    if (len1 < len2) return -1;

    // 4. Same length? Compare digit by digit from head to tail
    temp1 = head1;
    temp2 = head2;
    while (temp1) {
        if (temp1->data > temp2->data) return 1;
        if (temp1->data < temp2->data) return -1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    // They are equal
    return 0;
}

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR) {
    int cmp = compare(*head1, *head2);
    
    if (cmp == 0) {
        insert_at_first(0, headR, tailR);
        return 0; 
    }

    Dlist *temp1, *temp2;
    int is_negative = 0;

    // Assign the larger number to temp1 for the subtraction algorithm
    if (cmp == 1) { 
        temp1 = *tail1;
        temp2 = *tail2;
    } else { 
        temp1 = *tail2; 
        temp2 = *tail1;
        is_negative = 1; 
    }

    int diff, borrow = 0;
    while (temp1 != NULL) {
        int val1 = temp1->data;
        int val2 = (temp2 != NULL) ? temp2->data : 0;
        
        diff = val1 - val2 - borrow;

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        insert_at_first(diff, headR, tailR);
        temp1 = temp1->prev;
        if (temp2) temp2 = temp2->prev;
    }

    while ((*headR)->next != NULL && (*headR)->data == 0) {
        Dlist *temp = *headR;
        *headR = (*headR)->next;
        (*headR)->prev = NULL;
        free(temp);
    }

    return is_negative; 
}