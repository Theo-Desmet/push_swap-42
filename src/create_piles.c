/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_piles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 10:46:22 by tdesmet           #+#    #+#             */
/*   Updated: 2022/02/11 15:19:02 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*ft_new_pile(int nb)
{
	t_pile	*new;

	new = malloc(sizeof(t_pile));
	if (!new)
		return (NULL);
	new->val = nb;
	new->next = NULL;
	return (new);
}

void	ft_push_pile(t_pile **pile, t_pile *push)
{
	if (!push || !pile)
		return ;
	push->next = *pile;
	*pile = push;
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	neg;

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
	return (result);
}

t_pile	**ft_create_pile(int argc, char **argv)
{
	int		i;
	int		j;
	char	**tab;
	t_pile	**pile;

	i = argc;
	j = 0;
	pile = malloc(sizeof(t_pile));
	*pile = NULL;
	while (i - 1 > 0)
	{
		tab = ft_split(argv[i - 1], ' ');
		while (tab[j])
			j++;
		while (j > 0)
		{
			ft_push_pile(pile, ft_new_pile(ft_atoi(tab[j - 1])));
			free(tab[j - 1]);
			j--;
		}
		free(tab);
		i--;
		j = 0;
	}
	return (pile);
}

void	aff(t_pile **pile)
{
	t_pile	*temp;

	temp = *pile;
	while (temp)
	{
		ft_putnbr(temp->val);
		ft_putstr(" -> ");
		temp = temp->next;
	}
	ft_putstr("NULL\n");
}
