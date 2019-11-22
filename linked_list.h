typedef struct linked_list linked_list;

struct linked_list{
	char *data;
	int index; /* normally not used with Linked Lists, just for exercise */
	struct linked_list *next;
};

/*Creates a new list item and add that to end of the list*/
/*Return -1 as error (no space left), index position in success*/
int add_to_list(linked_list *ll, char *s);

/*Displays the required element in a list*/
/*Return -1 as element not found, 0 as ok*/
int display_item(linked_list *ll);

/*List all elements in a list*/
/*Return number of elements in list*/
int display_list(linked_list *ll);

/*Search for a data *s from a list*/
linked_list *search_from_list(linked_list *ll, char *s);

/*Delete item from a list and free space*/
/*Return -1 as error, length of remaining list*/
int delete_from_list(linked_list *ll, int index);

/*Remove all items from the list and free allocated memory*/
/*Return value of items deleted from the list*/
int empty_list(linked_list *ll);

/*Swap order of 2 items*/
/*Return 0 for OK and -1 if either items was not in the list (content of the list did not change*/
int swap_items(linked_list *f, linked_list *s);

/*Sort list in rising order based on data*/
int sort_list(linked_list *ll);

/*Count the number of elements in the list*/
/*Return amount of elements*/
int linkedlist_status(linked_list *ll);