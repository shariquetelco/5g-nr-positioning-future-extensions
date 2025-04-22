#include "nghttp2srv.h"

void
freeHTTPList(struct http_list *list)
{
	struct http_entry *entry = 0;

	/*Check passed HTTP header list*/
	if(!list)
	{
		return;
	}

	/*If list is empty: free root and return*/
	if(!list->cnt)
	{
		free(list);
		return;
	}

	/*Iterate through linked HTTP header list*/
	for(entry = list->first; entry != NULL; entry = list->first)
	{
		list->first = entry->next;
		list->cnt--;
		if(entry->data)
		{
			free(entry->data);
		}
		free(entry);
	}

	free(list);
}
