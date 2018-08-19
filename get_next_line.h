/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:53:06 by xlim              #+#    #+#             */
/*   Updated: 2018/08/19 14:30:57 by xlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <libft.h>

int		ft_strlen_mod(char *str, int *index, int *len);
int		ft_searchlst(t_list *alst, int key);
void	ft_lstadd_mod(t_list **alst, int key, int value);
int		get_next_line(const int fd, char **line);

#endif
