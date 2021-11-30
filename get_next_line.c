/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagumo <tnagumo@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 11:00:06 by tnagumo           #+#    #+#             */
/*   Updated: 2021/09/25 17:22:01 by tnagumo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnl_read_sub(char *buf, char *rtn, ssize_t rs, ssize_t *sum_rs)
{
	if (rs == 0)
		return (ft_gnl_free_rtn(buf, NULL, rtn));
	*sum_rs = -1;
	return (ft_gnl_free_rtn(buf, rtn, NULL));
}

char	*ft_gnl_read(int fd, ssize_t *sum_read_size)
{
	char	*buf;
	char	*rtn;
	char	*tmp;
	ssize_t	read_size;

	rtn = NULL;
	while (1)
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return (ft_gnl_free_rtn(buf, rtn, NULL));
		read_size = read(fd, buf, BUFFER_SIZE);
		*sum_read_size += read_size;
		if (read_size <= 0)
			return (ft_gnl_read_sub(buf, rtn, read_size, sum_read_size));
		buf[read_size] = '\0';
		tmp = ft_strjoin(rtn, buf);
		rtn = ft_gnl_free_rtn(rtn, buf, tmp);
		if (rtn == NULL)
			*sum_read_size = -1;
		if (ft_strlenc(rtn, '\n', 0) >= 0)
			return (rtn);
	}
}

char	*ft_gnl_join(char *stock, char *tmp, int n)
{
	char	*rtn;
	char	*s;
	int		i;

	s = ft_strsub(tmp, 0, n + 1);
	if (s == NULL)
		return (ft_gnl_free_rtn(NULL, tmp, NULL));
	rtn = ft_strjoin(stock, s);
	if (rtn == NULL)
		return (ft_gnl_free_rtn(s, tmp, rtn));
	i = 0;
	while (1)
	{
		stock[i] = tmp[n + 1 + i];
		if (stock[i] == '\0')
			break ;
		i++;
	}
	return (ft_gnl_free_rtn(s, tmp, rtn));
}

char	*ft_gnl_rtn(char *stock, char *tmp, ssize_t read_size)
{
	int		n;
	char	*rtn;

	if (read_size == 0)
	{
		if (stock[0] == '\0')
			return (NULL);
		rtn = ft_strjoin(stock, tmp);
		stock[0] = '\0';
		return (ft_gnl_free_rtn(NULL, tmp, rtn));
	}
	n = ft_strlenc(tmp, '\n', -1);
	if (n >= 0)
		return (ft_gnl_join(stock, tmp, n));
	rtn = ft_strjoin(stock, tmp);
	stock[0] = '\0';
	return (ft_gnl_free_rtn(NULL, tmp, rtn));
}

char	*get_next_line(int fd)
{
	static char	stock[BUFFER_SIZE + 1];
	int			n;
	char		*tmp;
	ssize_t		read_size;

	n = ft_strlenc(stock, '\n', -1);
	if (n >= 0)
		return (ft_gnl_strforward(stock, n));
	read_size = 0;
	tmp = ft_gnl_read(fd, &read_size);
	if (read_size < 0)
		return (NULL);
	return (ft_gnl_rtn(stock, tmp, read_size));
}
