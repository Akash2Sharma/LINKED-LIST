#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ll.h"
#include "ui.h"
                                                                                                                                                                        
/*****************************************
 * Singly Linked Lists
 *
 *****************************************/

/*
 * Singly Linked List Test code: lets you print the contents of an
 * list with a message.
 */

int first(list l)
{
  if (NULL == l) {
    printf("Error taking first of empty list\n");
    return 0;
  }
  return l->value;
}
  
list rest(list l)
{
  if (NULL == l) {
    printf("Error taking rest of empty list\n");
    return l;
  } 
  return l->next; 
} 
                                                                                     
void pl(list l)  
{
  if (l == NULL) {
    printf(")");
  } else if (rest(l) == NULL) {
    printf("%d)", first(l));
  } else {
    printf("%d ", first(l));
    pl(rest(l));
  }
}

void print_list(char *msg, list l)
{
  printf("%s: (", msg);
  pl(l);
  printf("\n");
}

void print_list_plus(char *before, list l, char *after)
{
  printf("%s(", before);
  pl(l);
  printf("%s", after);
}

/* Story 1
 * As a programmer, print a linked list, so I can see the results of
 * my programs.
 */

void print_sll(list l)
   {	list temp; 
 	temp=l;
    	printf("(");
    	while(temp!=NULL)
    	    {	    printf(" %d ",temp->value);
		    temp=temp->next;
	    }
    	  printf(") \n ");
    }

/* Story 2
 * As a programmer, I want to add an item to a linked list, so I can
 * learn how linked lists work.
 */

list add_sll(list l, int val)
{
        list fresh=(list)malloc (sizeof (list));
 	fresh->value=val;
	if (l== NULL)
 		{
			l=fresh;
			l->next=NULL;
		}
 	else
		{	fresh->next=l;
			l=fresh;
    		}

  return l;
}

/* Story 3
 * As a programmer, I want to find an item in a singly linked list, so
 * I can learn how linked lists work.
 */

list find_sll(list l, int target)
{   int count=1;
   list temp=(list)malloc (sizeof (list));
	temp=l;
	while(temp!=NULL)
	  { if(temp->value==target) { printf("%d found at position %d in list\n",target,count); return  temp ; }
	    temp=temp->next;
	     count++;
	   }
	printf("The No. you are searching is not in list\n");
  return l;
} 

/* Story 4
 * As a programmer, I want to Insert an item at a point in a singly
 * linked list, so I can learn how linked lists work.
 */
list insert_sll(list l, int val, int location)
{  list fresh=(list)malloc(sizeof(list));
   list pehleka;
   int count;
   fresh->value=val;
	if(location==1){
		fresh->next=l;
		l=fresh;
		}
	else
	   {
		pehleka=l;
		count=1;
		while((count<location-1) && (pehleka->next!=NULL))
		{ pehleka=pehleka->next;
		  count++;
		}
	    }
        fresh->next=pehleka->next;
	pehleka->next=fresh;
  return l;
}

/* Story 5
 * As a programmer, I want to delete an item in a singly linked list,
 * so I can learn how linked lists work.
 */
list delete_sll(list l, int location)
{  list current=(list)malloc (sizeof (list));
   list previous=(list)malloc (sizeof (list));
   current=l;
   previous=NULL;
  	if(l==0) printf("/n****UNDERFLOW****/n");
	else
	   { if(location==1){
			l=l->next;
			current->next=NULL;
			free(current);
	   		}
	     else
                { for(int i=0;i<location-1;i++){
			previous=current;
			current=current->next; }
			 previous->next=current->next;
			 current->next=NULL;
			free(current);
	   }}
return l;
}

/* Story 6
 * As a programmer, I want to add an item to a sorted singly linked
 * list so that the list remains sorted, so I can learn how linked
 * lists work.
 */
list  maintain_sorted_sll(list l, int val)
{  list fresh=(list)malloc (sizeof (list));
	fresh->value=val;
   list pehleka=(list)malloc (sizeof (list));
   list abhika=(list)malloc (sizeof (list));
//	int abhika;  
	if(val<=l->value)
		{ fresh->next=l;
		  l=fresh;
		}
	else
           { abhika=l;
	    pehleka=NULL;
	    while((val>=abhika->value) && (abhika!=NULL))
		{ pehleka=abhika;
		 abhika=abhika->next;
		}}
	fresh->next=abhika;
	pehleka->next=fresh;
  return l;
}

/*****************************************
 *
 * Doubly Linked Lists
 *
 *****************************************/

/*
 * Doubly Linked List Test code: lets you print the contents of an
 * list with a message.
 */

int first_dll(dlist l)
{
  if (NULL == l) {
    printf("Error taking first of empty dll\n");
    return 0;
  }
  return l->value;
}

dlist rest_dll(dlist l)
{
  if (NULL == l) {
    printf("Error taking rest of empty dll\n");
    return l;
  }
  return l->next;
}

dlist prev_dll(dlist l)
{
  if (NULL == l) {
    printf("Error taking prev of empty dll\n");
    return l;
  }
  return l->prev;
}

void print_dll_pair(dlist l)
{
  if (NULL == l) {
    printf("Error: printing dll pair of NULL\n");
  }
  if (prev_dll(l) == NULL) {
    printf("[() %d]", first_dll(l));
  } else {
    printf("[%d %d]", first_dll(prev_dll(l)), first_dll(l));
  }
}

void p_dll(dlist l)
{
  if (l == NULL) {
    printf(")");
  } else if (rest_dll(l) == NULL) {
    print_dll_pair(l);
    printf(")");
  } else {
    print_dll_pair(l);
    printf(" ");
    p_dll(rest_dll(l));
  }
}

/*
 * print_dll
 * prints a doubly linked list as a list of pairs. It prints the
 * value of the previous element before printing the value of the
 * first element. It produces lists that look like:
 * [() 1] [1 2] [2 3])
 */
 void print_dll(char *msg, dlist l)
{
  printf("%s(", msg);
  p_dll(l);
  printf("\n");
}

void print_dll_plus(char *before, dlist l, char *after)
{
  printf("%s(", before);
  p_dll(l);
  printf("%s", after);
}

/* Story 7
 * As a programmer, I want to add an item to a doubly linked list, so
 * I can learn how doubly linked lists work.
 */
dlist add_dll(dlist dl, int val)
{ dlist fresh=(dlist) malloc(sizeof(dlist));
  fresh->value=val;
  if(dl==NULL){
	fresh->next=NULL;
	fresh->prev=NULL;
	dl=fresh; 
	}
 else
   {
	fresh->next=dl;
	dl->prev=fresh;
	fresh->prev=NULL;
	dl=fresh;
   }
  return dl;
}

/* Story 8
 * As a programmer, I want to print a doubly linked list toward the
 * front, so I can learn how doubly linked lists work.
 */
void rprint_dll(dlist dl)
{  dlist last=(dlist) malloc(sizeof(dlist)); 
	while(dl!=NULL)
	{ last=dl;
	  dl=dl->next;
	}
	while(last!=NULL){
	printf(" %d",last->value);
	last=last->prev;}
	printf("\n");
}


/* Story 9
 * As a programmer, I want to delete an item from a doubly linked
 * list, so I can learn how doubly linked lists work.
 */
dlist delete_dll(dlist dl, int position)
{ dlist current=(dlist) malloc(sizeof(dlist));
  dlist previous=(dlist) malloc(sizeof(dlist));
  current=dl;
  previous=NULL;
  if(dl==0) printf("****UNDERFLOW****\n");
  else if (position==1) 
	{ dl=dl->next;
	  dl->prev=NULL;
	  current->next=NULL;
	  free(current);
	}
  else
	{ for(int i=1;i<position;i++) { previous=current;
					current=current->next;
				      }
	  if(current->next==NULL) previous->next=NULL;
	  else
		{ previous->next=current->next;
		  current->next->prev=previous;
		}

	  current->next=NULL;
	  current->prev=NULL;
	  free(current);
	}			   
  return dl;
}

/*****************************************
 *
 * Circular Linked Lists
 *
 *****************************************/

/* Story 10
 * As a programmer, I want to print a circular linked list, so I can
 * learn how doubly linked lists work.
 */
void print_cll(list cl)
{	list temp;
	temp=cl->next;
	printf("( %d ",cl->value);
	while(temp!=cl){
	printf("%d ",temp->value);
	temp=temp->next;
	}
	//free(temp);
  printf(")\n");
}

/* Story 11
 * As a programmer, I want to add an item to a circular linked list,
 * so I can learn how circular linked lists work.
 */
list add_cll(list cl, int val)
{	list add=(list)malloc(sizeof(list));   
        add->value=val;
        list temp;
	if(cl==NULL){
		add->next=add;
		cl=add;
		}
	else
		{temp=cl;
		while(temp->next!=cl)  temp=temp->next;
		temp->next=add;
		add->next=cl;
		cl=add;
		}
  return cl;
}

/* Story 12
 * As a programmer, I want to delete an item from a circular linked
 * list, so I can learn how circular linked lists work.
 */
list delete_cll(list cl, int position)
{ 	if(cl == NULL) printf("Underflow");
	else{
	list temp = cl, last;
	while(temp->next != cl)  temp = temp->next;
	last = temp;
	list current = last->next, previous = NULL;
	if(position == 1){
		last->next = current->next;
		current->next = NULL;
		cl = last->next;
		free(current);
		}
	else{
		for(int i=1 ; i < position ; i++){
			previous = current;
			current = current->next;
			}
		if(current == last){
			previous->next = current->next;
			last = previous;
			free(current);
			}
		else{
			previous->next = current->next;
			current->next = NULL;
			free(current);
		   }
	   }
	}
return cl;
}
