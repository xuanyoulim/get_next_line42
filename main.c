#include "get_next_line.h"
#include <assert.h>
#include <stdio.h>

void	printlist(t_list *list)
{
	t_list *ptr = list;
	while (ptr)
	{
		int *arr = (int *)(ptr->content);
		printf("[%i, %i]\n", arr[0], arr[1]);
		ptr = ptr->next;
	}
}

int main()
{
	//test ft_strlen_mod
	char test1str1[] = "abcde\n";
	int index = 0;
	int len = 5;
	assert(ft_strlen_mod(test1str1, &index, &len) == 1);
	assert(index == 5);
	assert(len == 5);
	//test ft_strlen_mod 2
	char test2str1[] = "abcde\0";
	index = 0;
	assert(ft_strlen_mod(test2str1, &index, &len) == 0);
	assert(index == 5);
	assert(len == 5);
	//prepare list - test ft_lstadd_mod (just adding)
	t_list *list = NULL;
	ft_lstadd_mod(&list, 0, 5);
	ft_lstadd_mod(&list, 1, 2);
	ft_lstadd_mod(&list, 2, 3);
	printlist(list);
	//test ft_searchlst
	assert(ft_searchlst(list, 0) == 5);
	assert(ft_searchlst(list, 1) == 2);
	assert(ft_searchlst(list, 2) == 3);
	assert(ft_searchlst(list, 3) == -1);
	//test ft_lstadd_mod with integration with searchlst (update func)
	printf("\n");
	ft_lstadd_mod(&list, 0, 0);
	ft_lstadd_mod(&list, 1, 1);
	ft_lstadd_mod(&list, 2, 2);
	printlist(list);
	ft_lstadd_mod(&list, 3, 3);
	ft_lstadd_mod(&list, 4, 4);
	ft_lstadd_mod(&list, 5, 5);
	printf("\n");
	printlist(list);
	return (0);
}
