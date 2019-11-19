#include <stdio.h>
#include "linked_list.c"
#include <string.h>

int main(void)
{
	linked_list *data = (linked_list*)malloc(sizeof(linked_list));
	int choose;
	while(choose != 0)
	{
		printf("1:add\n2:delete\n3:print list\n0:quit\n");
		scanf("%d",&choose);
		switch(choose)
		{
			case 1:{
				char str[10]="zero";
				printf("Input data:\n");
				//scanf("%s",str);
				add_to_list(data,str);
				break;
			}
			case 2:{
				int id;
				printf("Input id:");
				scanf("%d",&id);
				delete_from_list(&data,id);
				break;
			}
			case 3:{
				display_list(data);
				break;
			}
			case 0:{
				printf("Exit\n");
				break;
			}
			default:
				printf("Invalid\n");
		}
	}
    	return 0;
}
