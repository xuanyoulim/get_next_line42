/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:56:09 by xlim              #+#    #+#             */
/*   Updated: 2018/08/19 16:39:19 by xlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					ft_strlen_mod(char *str, int *index, int *len)
{
	*len = 0;
	while (*len < BUFF_SIZE)
	{
		if (str[*index] == '\n' || str[*index] == -1)
			return (1);
		else if (str[*index] == '\0')
			return (0);
		(*len)++;
		(*index)++;
	}
	return (-1);
}

int					ft_searchlst(t_list *alst, int key)
{
	int				*arr;

	while (alst)
	{
		arr = (int *)(alst->content);
		if (arr[0] == key)
			return (arr[1]);
		alst = alst->next;
	}
	return (-1);
}

void				ft_lstadd_mod(t_list **alst, int key, int value)
{
	int				*arr;
	t_list			*ptr;

	if (ft_searchlst(*alst, key) == -1)
	{
		arr = malloc(sizeof(int) * 2);
		arr[0] = key;
		arr[1] = value;
		ft_lstadd(alst, ft_lstnew(arr, sizeof(int) * 2));
	}
	else
	{
		ptr = *alst;
		arr = (int *)(ptr->content);
		while (arr[0] != key)
		{
			ptr = ptr->next;
			arr = (int *)(ptr->content);
		}
		arr = (int *)(ptr->content);
		arr[1] = value;
	}
}

/*int					get_next_line(const int fd, char **line)
{
	static t_list	*ass_arr;
	int				index;
	char			*save;
	char			*buf;
	int				len;

	buf = malloc(sizeof(char) * BUFF_SIZE);
	if (!(*ass_arr))
		ass_arr = malloc(sizeof(t_list));
	index = ft_searchlst(ass_arr, fd);
	if (index == -1)
		ft_lstadd_mod(&ass_arr, fd, 0);
	while (index >= BUFF_SIZE)
	{
		if (!read(fd, buf, BUFF_SIZE))
			return (-1);
		index -= BUFF_SIZE;
	}
	len = ft_strlen_mod(buf, &index);
	save = malloc(sizeof(char) * len);
	if (len == BUFF_SIZE)
	{
		get_next_line(fd, &save);
	}
	else
	{
		ft_lstadd_mod(&ass_arr, fd, index);
		if (!read(fd, save, len))
			return (-1);
	}
	line = ft_strjoin(&line, save);
}*/
