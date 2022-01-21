/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 08:05:27 by tdesmet           #+#    #+#             */
/*   Updated: 2022/01/20 08:03:43 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_digit(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	while (str[i])
		i++;
	if (ft_str_size(str))
		return (0);
	if (check_int(str) == 0)
		return (0);
	return (1);
}

int	check_doublons(char *str, int argc, char **argv, int i)
{
	int	j;

	j = i + 1;
	if (argc == 2)
		return (1);
	while (j < argc)
	{
		if (ft_strcmp(str, argv[j]) == 0)
			return (0);
		j++;
	}
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (-1);
	if (s1[i] == '+')
		i++;
	if (s2[j] == '+')
		j++;
	while (s1[i] && s2[j] && s1[i] == s2[j])
	{
		if (s1[i] == '\0' && s2[j] == '\0')
			return (0);
		if (s1[i] == '\0')
			return (-1);
		if (s2[j] == '\0')
			return (1);
		i++;
		j++;
	}
	return (s1[i] - s2[j]);
}

int	check_args(int argc, char **argv)
{
	int		i;
	int		j;
	char	**tab;

	i = 1;
	j = 0;
	while (i < argc)
	{
		tab = ft_split(argv[i], ' ');
		if (check_doublons_split(tab) == 0)
		{
			write(2, "Error", 5);
			return (0);
		}
		while (tab[j])
		{
			if (check_digit(tab[j]) && check_doublons(tab[j], argc, argv, i))
				free(tab[j]);
			else
			{
				write(2, "Error", 5);
				return (0);
			}
			j++;
		}
		free(tab);
		i++;
		j = 0;
	}
	return (1);
}

int	check_int(const char *nptr)
{
	int			i;
	long long	result;
	int			neg;

	i = 0;
	neg = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] > 8 && nptr[i] < 14))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		result *= 10;
		result += nptr[i] - 48;
		i++;
	}
	result *= neg;
	if (result > 2147483647 || result < -2147483648)
		return (0);
	return (1);
}
