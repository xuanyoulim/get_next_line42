/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:56:09 by xlim              #+#    #+#             */
/*   Updated: 2018/08/29 23:21:16 by xlim             ###   ########.fr       */
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
		new->remain = ft_memalloc(sizeof(char) * (len + 1));
		ft_strcpy(new->remain, s);
		new->len = len;
		new->next = *alst;
		*alst = new;
		return (new);
	}
	else
	{
		free(ptr->remain);
		ptr->remain = ft_memalloc(sizeof(char) * (len + 1));
		ft_strcpy(ptr->remain, s);
		ptr->len = len;
	}
	return (NULL);
}

int					extract(char **base, char **ret, size_t *size)
{
	size_t			i;
	int				out;
	char			*tmp;
	char			*tofree;

	i = 0;
	while (*(*base + i) != '\0' && *(*base + i) != '\n' && *(*base + i) != -1)
		i++;
	out = (i == *size) ? -1 : 1;
	tmp = ft_strsub(*base, 0, i);
	tofree = *ret;
	*ret = (*ret && **ret != '\0') ? ft_strjoin(*ret, tmp) : ft_strdup(tmp);
	ft_strdel(&tmp);
	ft_strdel(&tofree);
	*size = (*size == i) ? 0 : *size - ++i;
	if (*size)
	{
		tofree = ft_strsub(*base, i, *size);
		ft_strdel(base);
		*base = ft_strdup(tofree);
	}
	else
		ft_strclr(*base);
	ft_strdel(&tofree);
	return (out);
}

int					get_next_line(const int fd, char **line)
{
	static t_listx	*list;
	t_listx			*cur;
	char			*buf;
	int				state;
	size_t			len;

	buf = ft_memalloc(sizeof(char) * (BUFF_SIZE + 1));
	if (line == NULL || read(fd, buf, 0) < 0 || fd < 0)
		state = 2;
	else
		*line = ft_strnew(0);
	cur = ft_searchlst(list, fd);
	state = (cur && cur->len) ? extract(&(cur->remain), line, &(cur->len)) : -1;
	while (state < 0)
	{
		if ((state = read(fd, buf, BUFF_SIZE)) <= 0)
			break ;
		len = state;
		state = extract(&buf, line, &len);
		ft_lstadd_mod(&list, fd, buf, len);
	}
	if (state == 0)
		ft_lstdel_mod(&list, fd);
	ft_strdel(&buf);
	return (line != NULL && *line && **line != '\0') ? 1 : TRANSLATE(state);
}
