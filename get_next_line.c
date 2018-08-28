/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:56:09 by xlim              #+#    #+#             */
/*   Updated: 2018/08/27 22:28:41 by xlim             ###   ########.fr       */
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
	char			*toextract;

	i = 0;
	while (*(*base + i) != '\0' && *(*base + i) != '\n' && *(*base + i) != -1)
		i++;
	out = (i == *size) ? -1 : 1;
	toextract = ft_strsub(*base, 0, i);
	*extract = (!(*extract)) ? toextract : ft_strjoin(*extract, toextract);
	*size = (*size == i) ? 0 : *size - ++i;
	if (*size)
		*base = ft_strsub(*base, i, *size);
	else
		ft_strclr(*base);
	return (out);
}

int					get_next_line(const int fd, char **line)
{
	static t_listx	*list;
	t_listx			*curr;
	char			*buf;
	int				status;
	size_t			len;

	if (*line)
		ft_strclr(*line);
	buf = malloc(sizeof(char) * (BUFF_SIZE + 1));
	status = -1;
	curr = ft_searchlst(list, fd);
	if (curr && curr->len)
		status = extract(&(curr->remain), line, &(curr->len));
	while (status < 0)
	{
		status = read(fd, buf, BUFF_SIZE);
		if (status < 0)
			return (-1);
		else if (status == 0)
		{
			ft_lstdel_mod(&list, fd);
			break ;
		}
		len = status;
		status = extract(&buf, line, &len);
		ft_lstadd_mod(&list, fd, buf, len);
	}
	free(buf);
	return (**line) ? 1 : status;
}
