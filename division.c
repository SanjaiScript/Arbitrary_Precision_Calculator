#include "apc.h"

int division(Dlist **dividend_head, Dlist **dividend_tail, Dlist **divisor_head, Dlist **divisor_tail, Dlist **quotient_head, Dlist **quotient_tail) 
{
    /* 1. Division by zero check */
    if ((*divisor_head)->data == 0 && (*divisor_head)->next == NULL) 
    {
        return FAILURE;
    }

    /* 2. Initialize Quotient to 0 */
    Dlist *head_quotient = NULL, *tail_quotient = NULL;
    insert_at_first(0, &head_quotient, &tail_quotient); 
    
    /* 3. Constant 1 list used to increment the quotient */
    Dlist *head_one = NULL, *tail_one = NULL;
    insert_at_first(1, &head_one, &tail_one); 

    /* 4. Create working pointers for the dividend so we don't lose the original */
    Dlist *working_dividend_head = *dividend_head;
    Dlist *working_dividend_tail = *dividend_tail;

    /* 5. Repeated Subtraction Loop: While (Dividend >= Divisor) */
    while (compare(working_dividend_head, *divisor_head) >= 0) 
    {
        Dlist *sub_result_head = NULL, *sub_result_tail = NULL;
        
        /* working_dividend = working_dividend - divisor */
        subtraction(&working_dividend_head, &working_dividend_tail, divisor_head, divisor_tail, &sub_result_head, &sub_result_tail);

        // If this isn't the original head1, free it to save memory
        if (working_dividend_head != *dividend_head) {
            free_list(&working_dividend_head, &working_dividend_tail);
        }
        
        /* Update pointers to the new reduced value */
        working_dividend_head = sub_result_head;
        working_dividend_tail = sub_result_tail;

        /* Increment Quotient: head_quotient = head_quotient + 1 */
        Dlist *new_quotient_head = NULL, *new_quotient_tail = NULL;
        addition(&head_quotient, &tail_quotient, &head_one, &tail_one, &new_quotient_head, &new_quotient_tail);
        
        head_quotient = new_quotient_head;
        tail_quotient = new_quotient_tail;
        
        /* Stop if we hit exactly zero */
        if (working_dividend_head->data == 0 && working_dividend_head->next == NULL) 
        {
            break; 
        }
    }

    /* Assign the final quotient lists to the output pointers */
    *quotient_head = head_quotient;
    *quotient_tail = tail_quotient;
    
    return SUCCESS;
}