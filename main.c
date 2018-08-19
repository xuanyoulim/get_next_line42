#include "get_next_line.h"
#include <assert.h>

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
	return (0);
}
