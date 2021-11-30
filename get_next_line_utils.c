/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagumo <tnagumo@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 11:01:06 by tnagumo           #+#    #+#             */
/*   Updated: 2021/09/25 17:22:36 by tnagumo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlenc(const char *s, int c, int if_null_return)
{
	char	cc;
	char	*ps;
	int		i;

	if (!s)
		return (if_null_return);
	cc = (char)c;
	ps = (char *)s;
	i = 0;
	while (ps[i] != cc)
	{
		if (ps[i] == '\0')
			return (-1);
		i++;
	}
	return (i);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*rtn;
	size_t	i;

	if (s == NULL)
		return (NULL);
	rtn = malloc(len + 1);
	if (rtn == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		rtn[i] = s[start + i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	char	*rtn;
	int		i;
	int		l1;
	int		l2;

	l1 = ft_strlenc(s1, '\0', 0);
	l2 = ft_strlenc(s2, '\0', 0);
	rtn = malloc(l1 + l2 + 1);
	if (rtn != NULL)
	{
		p = rtn;
		i = l1;
		while (i--)
			*(p++) = *(s1++);
		i = l2;
		while (i--)
			*(p++) = *(s2++);
		rtn[l1 + l2] = '\0';
	}
	return (rtn);
}

char	*ft_gnl_free_rtn(char *f1, char *f2, char *rtn)
{
	free(f1);
	f1 = NULL;
	free(f2);
	f2 = NULL;
	return (rtn);
}

char	*ft_gnl_strforward(char *stock, int n)
{
	char	*rtn;
	int		i;

	rtn = ft_strsub(stock, 0, n + 1);
	i = 0;
	while (1)
	{
		stock[i] = stock[n + 1 + i];
		if (stock[i] == '\0')
			break ;
		i++;
	}
	return (rtn);
}
