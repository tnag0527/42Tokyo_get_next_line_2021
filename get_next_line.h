/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagumo <tnagumo@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 11:00:36 by tnagumo           #+#    #+#             */
/*   Updated: 2021/09/25 12:28:02 by tnagumo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define FD_MAX 256

char	*get_next_line(int fd);

int		ft_strlenc(const char *s, int c, int if_null_return);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_gnl_free_rtn(char *f1, char *f2, char *rtn);
char	*ft_gnl_strforward(char *stock, int n);

#endif
