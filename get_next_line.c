/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:56:09 by xlim              #+#    #+#             */
/*   Updated: 2018/08/25 17:53:38 by xlim             ###   ########.fr       */
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
	char *ptr1 = *extract;
	if (!(*extract))
		*extract = ft_strsub(*base, 0, i);
	else
		*extract = ft_strjoin(*extract, ft_strsub(*base, 0, i));
	ft_strclr(ptr1);
	ft_strdel(&ptr1);
	char *ptr2 = *base;
	if (*size - i)
		*base = ft_strsub(*base, ++i, *size);
	//else
	//	ft_strclr(*base);
	ft_strclr(ptr2);
	//ft_strdel(&ptr2);
//	*size = *size - i;
	if (*base)
		*size = ft_strlen(*base);
	else
		*size = 0;
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
	{
		if (*(curr->remain) == '\0' && curr->len == 1)
		{
			ft_lstdel_mod(&list, fd);
			return (0);
		}
		status = extract(&(curr->remain), line, &(curr->len));
	}
	while (status < 0)
	{
		status = read(fd, buf, BUFF_SIZE);
		if (status <= 0)
			break ;
		buf[status] = '\0';
		len = BUFF_SIZE;
		//len = ft_strlen(buf);
		status = extract(&buf, line, &len);
		if (status == 0)
		{
			ft_lstadd_mod(&list, fd, "\0", 1);
			return (1);
		}
		else
			ft_lstadd_mod(&list, fd, buf, len);
	}
	//if (status == 0)
	//{
	//	ft_lstadd_mod(&list, fd, "", 1);
	//	return (1);
	//	ft_lstdel_mod(&list, fd);
	//}
	free(buf);
	return (status);
}
