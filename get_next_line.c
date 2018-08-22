/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:56:09 by xlim              #+#    #+#             */
/*   Updated: 2018/08/21 18:31:18 by xlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
int					ft_strlen_mod(char *str, int *index, int *len)
{
	*len = 0;
	if (*index == -1)
		*index = 0;
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

int					ft_searchlst(t_list *alst, int key, int isindex)
{
	int				*arr;

	while (alst)
	{
		arr = (int *)(alst->content);
		if (arr[0] == key)
			return (isindex) ? arr[2] : arr[1];
		alst = alst->next;
	}
	return (-1);
}

void				ft_lstadd_mod(t_list **alst, int key, int value, int v2)
{
	int				*arr;
	t_list			*ptr;

	if (ft_searchlst(*alst, key, v2) == -1)
	{
		arr = malloc(sizeof(int) * 3);
		arr[0] = key;
		arr[1] = value;
		arr[2] = v2;
		ft_lstadd(alst, ft_lstnew(arr, sizeof(int) * 3));
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
		arr[2] = v2;
	}
}

/*int					get_next_line(const int fd, char **line)
{
	static t_list	*ass_arr;
	int				index;
	char			*save;
	int				len;
	int				status;

	ass_arr = NULL;
	len = 0;
	index = ft_searchlst(ass_arr, fd, 0);
	status = ft_searchlst(ass_arr, fd, 1);
	save = malloc(sizeof(char) * BUFF_SIZE);
	while (index >= BUFF_SIZE && status)
	{
		if (!read(fd, save, BUFF_SIZE))
			return (-1);
		index -= BUFF_SIZE;
	}
	if (!read(fd, save, BUFF_SIZE))
		return (-1);
	status = ft_strlen_mod(save, &index, &len);
	if (status == -1)
	{
		ft_lstadd_mod(&ass_arr, fd, index + 1);
		get_next_line(fd, &save);
	}
	line = ft_strjoin(&line, save);
}*/

/*int 	ft_whatend(char *str, int *i)
{
	*i = 0;
	while (*i < BUFF_SIZE)
	{
		if (str[*i] == '\n')
			return (1);
		else if (str[*i] == -1)
			return (2);
		else if (str[*i] == '\0')
			return (3);
		(*i)++;
	}
	return (0);
}*/

int	extract(char **base, char **extract, size_t *size)
{
	size_t 	i;
	int		out;

	i = 0;
	char *str = *base;
	while (i < *size && str[i] != '\0' && str[i] != '\n' && str[i] != -1)
		i++;
	if (str[i] == '\n' || str[i] == -1)
		out = 1;
	else if (i == *size)
		out = -1;
	else //(str[i] == '\0')
		out = 0;
	*extract = ft_strjoin(*extract, ft_strsub(*base, 0, i));
	if (*size - i)
		*base = ft_strsub(*base, ++i, *size);
	else
		ft_strclr(*base);
	*size = *size - i;
	return (out);
}


int get_next_line(const int fd, char **line)
{
	static char *left;
	static size_t len;
	char *buf;
	int status;
	
	buf = malloc(sizeof(char) * BUFF_SIZE);
	status = -1;
	if (left && len)
		status = extract(&left, line, &len);
	while (status < 0)
	{
		if (read(fd, buf, BUFF_SIZE) == 0)
			return (0);
		len = BUFF_SIZE;
		status = extract(&buf, line, &len);
		left = buf;
	}
	free(buf);
	return (status);
}
