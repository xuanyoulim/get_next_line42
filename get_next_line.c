/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:56:09 by xlim              #+#    #+#             */
/*   Updated: 2018/08/23 14:06:22 by xlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_listx				*ft_searchlst(t_listx *alst, int fd)
{
	while (alst)
	{
		if (alst->key == fd)
			return (alst);
		alst = alst->next;
	}
	return (NULL);
}

void				ft_lstdel_mod(t_listx **alst, int fd)
{
	t_listx			*ptr;
	t_listx			*tmp;

	ptr = *alst;
	if (*alst && (*alst)->key == fd)
	{
		ft_strdel(&((*alst)->remain));
		tmp = *alst;
		*alst = (*alst)->next;
		free(tmp);
	}
	while (ptr && ptr->next)
	{
		if (ptr->next->key == fd)
		{
			ft_strdel(&(ptr->next->remain));
			tmp = ptr->next;
			ptr = ptr->next->next;
			free(tmp);
		}
		else
			ptr = ptr->next;
	}
}

t_listx				*ft_lstadd_mod(t_listx **alst, int fd, char *s, size_t len)
{
	t_listx			*new;
	t_listx			*ptr;

	ptr = ft_searchlst(*alst, fd);
	if (!ft_searchlst(*alst, fd))
	{
		new = malloc(sizeof(t_listx));
		new->key = fd;
		new->remain = malloc(sizeof(char) * len);
		ft_strcpy(new->remain, s);
		new->len = len;
		new->next = *alst;
		*alst = new;
		return (new);
	}
	else
	{
		free(ptr->remain);
		ptr->remain = malloc(sizeof(char) * len);
		ft_strcpy(ptr->remain, s);
		ptr->len = len;
	}
	return (NULL);
}

int					extract(char **base, char **extract, size_t *size)
{
	size_t			i;
	int				out;
	char			*str;

	i = 0;
	str = *base;
	while (i < *size && str[i] != '\0' && str[i] != '\n' && str[i] != -1)
		i++;
	if (str[i] == '\n' || str[i] == -1)
		out = 1;
	else if (i == *size)
		out = -1;
	else //(str[i] == '\0')
		out = 0;
	if (!(*extract))
		*extract = ft_strsub(*base, 0, i);
	else
		*extract = ft_strjoin(*extract, ft_strsub(*base, 0, i));
	if (*size - i)
		*base = ft_strsub(*base, ++i, *size);
	else
		ft_strclr(*base);
	*size = *size - i;
	return (out);
}

int					get_next_line(const int fd, char **line)
{
	static t_listx	*list;
	t_listx			*curr;
	char			*buf;
	int				status;
	size_t			len;

	ft_strclr(*line);
	buf = malloc(sizeof(char) * BUFF_SIZE);
	status = -1;
	curr = ft_searchlst(list, fd);
	if (curr && curr->len)
		status = extract(&(curr->remain), line, &(curr->len));
	while (status < 0)
	{
		status = read(fd, buf, BUFF_SIZE);
		if (status <= 0)
			break ;
		len = BUFF_SIZE;
		status = extract(&buf, line, &len);
		ft_lstadd_mod(&list, fd, buf, len);
	}
	if (status == 0)
		ft_lstdel_mod(&list, fd);
	free(buf);
	return (status);
}
