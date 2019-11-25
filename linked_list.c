#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

int add_to_list(linked_list *ll, char *s)
{
	int index=0;
	linked_list *list = ll;
	if(ll == NULL)	//check if pointer is NULL
	{
		//printf("NULL pointer\n");
		return -1;
	}
	else if(s == NULL)	//check if string pointer is NULL
	{
		//printf("NULL string pointer\n");
		return -1;
	}
	else
	{
		while(list->next != NULL)		//find end of list
			list = list->next;
		list->next = (linked_list*)malloc(sizeof(linked_list));	//create new element
		if(list->next == NULL)
			return -1;
		list->next->data = s;		//add s to data item of new element
		list->next->index = list->index+1;	//write new index (last+1) to new elements index
		list->next->next = NULL;			//add NULL to new elements next
		index = list->next->index;
	}
	return index;
}

int display_item(linked_list *ll)
{
	if(ll == NULL)
	{
		//printf("NULL pointer\n");
		return -1;
	}
	else
	{
		/*printf("Display item:\n");
		printf("\tItem %d\n", ll->index);
		printf("\tItem's data: %s\n", ll->data);
		printf("\tItem's next: %p\n", ll->next);*/
		return 0;
	}
}

int display_list(linked_list *ll)
{
	int num_element = 0;
	if(ll == NULL)
        {
                //printf("NULL pointer\n");
                return -1;
        }
	else
	{
		//printf("Display list:\n");
		while(ll != NULL)
		{
			display_item(ll);
			num_element = ll->index;
			ll = ll->next;
		}
		num_element+=1;
	}
	return num_element;
}

linked_list *search_from_list(linked_list *ll, char *s)
{
	linked_list *found;
	if(ll == NULL)
	{
		//printf("NULL pointer\n");
		found = NULL;
		return found;
	}
	if(s == NULL)
	{
		//printf("Invalid data pointer\n");
		found = NULL;
		return found;
	}
	while(ll != NULL)
	{
		if(strcmp(s, ll->data) == 0)
		{
			found = ll;
			return found;
		}
		ll = ll->next;
	}
}

int delete_from_list(linked_list *ll, int index)
{
	linked_list *temp = ll, *prev;
	int n = display_list(ll);
	if(ll == NULL)
	{
		//printf("NULL pointer\n");
		return -1;
	}
	if(index == NULL || index <0 || index > n)
	{
		//printf("Invalid index\n");
		return -1;
	}
	if(temp == NULL)
		return -1;
	//Delete data
	if(ll->index == index)
	{
		ll= temp->next;	//change head
		free(temp);		//free old head
	}
	if(ll->index != index)
	{	
		prev=temp;
		temp=temp->next;
	}
	prev->next=temp->next;	//Unlink the node from linked list
	free(temp);	//free memory
	
	if(prev == NULL)
		ll = temp;
	else if(prev->next != NULL)
		ll = prev->next;
	else
		return prev->index + 1;
	
	while(true)
	{
		ll->index--;
		if(ll->next == NULL)
			break;
		ll = ll->next;
	}
	
	return ll->index + 1;
}

int linkedlist_status(linked_list *ll)
{
	if(ll == NULL)
		return 0;
	return 1 + linkedlist_status(ll->next);
}

int empty_list(linked_list *ll)
{
	if(ll == NULL)
		return -1;
	int count = linkedlist_status(ll);
	for(int i=0; i<count; i++)
	{
			delete_from_list(ll, i);
	}
	return count;
}

int swap_items(linked_list *f, linked_list *s)
{
	if(f == NULL || s == NULL)
		return -1;
	else
	{
		linked_list *temp = f->next;
		f->next = s->next;
		s->next = temp;
		return 0;
	}
}

int sort_list(linked_list *ll)
{
	linked_list *temp = ll, *prev;
	if(prev->data > temp->data)
		swap_items(prev,temp);
	return 0;
}
