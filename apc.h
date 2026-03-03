#include<stdio.h>
#include<stdlib.h>
#ifndef APC_H
#define APC_H

#define RESET "\033[0m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define RED "\033[0;31m"
#define CYAN "\033[0;36m"
#define GREEN "\033[0;32m"

#define SUCCESS 0
#define FAILURE -1

typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
}Dlist;

/* Include the prototypes here */

/*store the operands into the list */
int digit_to_list(Dlist **head, Dlist **tail, char *argv, int *is_neg);

/*Addition */
int addition(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/*subtraction*/
int subtraction(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/*Multiplication*/
int multiplication(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);


/*Division */
int division(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

int insert_at_first(int data, Dlist **head, Dlist **tail);

int ascii_to_int(char character );

void print_list(Dlist **head, Dlist **tail);

int compare(Dlist *head1, Dlist *head2);

int is_integer(char* str1, char* str2);

void free_list(Dlist **head, Dlist **tail);
#endif
