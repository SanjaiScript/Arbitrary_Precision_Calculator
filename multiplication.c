#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR) {
    Dlist *t2 = *tail2;
    int shift = 0;

    // Create a temporary list to hold the running total
    Dlist *headTotal = NULL, *tailTotal = NULL;
    insert_at_first(0, &headTotal, &tailTotal); // Initialize total as 0

    while (t2 != NULL) {
        Dlist *t1 = *tail1;
        Dlist *headStep = NULL, *tailStep = NULL;
        int carry = 0;

        // Add "shifting" zeros based on the current digit's place value
        for (int i = 0; i < shift; i++) {
            insert_at_first(0, &headStep, &tailStep);
        }

        // Multiply list1 by a single digit of list2
        while (t1 != NULL || carry) {
            int d1 = (t1) ? t1->data : 0;
            int prod = (d1 * t2->data) + carry;
            
            insert_at_first(prod % 10, &headStep, &tailStep);
            carry = prod / 10;
            
            if (t1) t1 = t1->prev;
        }

        // Add this partial product to our running total
        Dlist *headNewTotal = NULL, *tailNewTotal = NULL;
        addition(&headTotal, &tailTotal, &headStep, &tailStep, &headNewTotal, &tailNewTotal);
        
        // Free old total and update to new total (pseudo-code for memory management)
        headTotal = headNewTotal;
        tailTotal = tailNewTotal;

        t2 = t2->prev;
        shift++;
    }

    *headR = headTotal;
    *tailR = tailTotal;
    return SUCCESS;
}