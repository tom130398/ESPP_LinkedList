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
