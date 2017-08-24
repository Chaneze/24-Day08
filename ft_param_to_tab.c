/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caroua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 16:26:39 by caroua            #+#    #+#             */
/*   Updated: 2017/08/21 15:34:21 by caroua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char				*ft_strdup(char *src)
{
	int		i;
	int		length;
	char	*dest;

	i = 0;
	length = ft_strlen(src);
	dest = (char*)malloc(sizeof(*dest) * (length + 1));
	while (i < length)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	t_stock_par	*dest;
	int			i;

	dest = (t_stock_par*)malloc(sizeof(*dest) * (ac + 1));
	i = 0;
	while (i < ac)
	{
		dest[i].size_param = ft_strlen(av[i]);
		dest[i].str = av[i];
		dest[i].copy = ft_strdup(av[i]);
		dest[i].tab = ft_split_whitespaces(av[i]);
		i++;
	}
	dest[i].str = 0;
	return (dest);
}
