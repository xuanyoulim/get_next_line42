/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:53:06 by xlim              #+#    #+#             */
/*   Updated: 2018/08/27 22:34:08 by xlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1000000
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <libft.h>

typedef struct		s_listx
{
	char			*remain;
	size_t			len;
	int				key;
	struct s_listx	*next;
}					t_listx;

t_listx				*ft_searchlst(t_listx *alst, int fd);
void				ft_lstdel_mod(t_listx **alst, int fd);
t_listx				*ft_lstadd_mod(t_listx **alst, int fd, char *s, size_t len);
int					extract(char **base, char **extract, size_t *size);
//int					extract(char **base, char **extract);
int					get_next_line(const int fd, char **line);

#endif
