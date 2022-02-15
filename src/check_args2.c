/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:54:51 by tdesmet           #+#    #+#             */
/*   Updated: 2022/02/15 14:09:25 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_str_size(char *str)
{
	int	i;
	int	j;

	if (!str)
		return (0);
	i = 0;
	j = 0;
	if (((str[i] == '-' || str[i] == '+') && str[i + 1] == 0)
		|| ((str[i] == '-' || str[i] == '+') && str[i + 1] == '0'))
		return (1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '0' && str[i + 1] != 0)
		return (1);
	if (j > 1)
		return (1);
	j = 0;
	while (str[i])
	{
		i++;
		j++;
	}
	if (j <= 10)
		return (0);
	return (1);
}

int	check_doublons_split(char **tab)
{
	int	j;
	int	i;
	int	cnt;

	i = 0;
	j = i + 1;
	cnt = 0;
	while (tab[cnt])
		cnt++;
	if (cnt == 1)
		return (1);
	while (i < cnt)
	{
		while (j <= cnt)
		{
			if (ft_strcmp(tab[i], tab[j]) == 0)
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

int	ft_error(char **tab, int i)
{
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	write(2, "Error", 5);
	return (0);
}
