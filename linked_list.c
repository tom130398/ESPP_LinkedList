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
		printf("NULL pointer\n");
		return -1;
	}
	else if(s == NULL)	//check if string pointer is NULL
	{
		printf("NULL string pointer\n");
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
		printf("NULL pointer\n");
		return -1;
	}
	else
	{
		printf("Display item:\n");
		printf("\tItem %d\n", ll->index);
		printf("\tItem's data: %s\n", ll->data);
		printf("\tItem's next: %p\n", ll->next);
		return 0;
	}
}

int display_list(linked_list *ll)
{
	int num_element = 0;
	if(ll == NULL)
        {
                printf("NULL pointer\n");
                return -1;
        }
	else
	{
		printf("Display list:\n");
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
		printf("NULL pointer\n");
		found = NULL;
		return found;
	}
	if(s == NULL)
	{
		printf("Invalid data pointer\n");
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
	int count = 0;
	linked_list *temp = ll, *prev;
	if(ll == NULL)
	{
		printf("NULL pointer\n");
		return -1;
	}
	if(index == NULL || index <0)
	{
		printf("Invalid index\n");
		return -1;
	}
	/*Delete data*/
	if(temp != NULL && temp->index == index)
	{
		ll = temp->next;
		free(temp);
		display_list(ll);
	}
	while(temp != NULL && temp->index != index)
	{
		prev=temp;
		temp=temp->next;
	}
	if(temp == NULL)
		return -1;
	prev->next=temp->next;
	free(temp);
}
