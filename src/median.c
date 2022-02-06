/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 08:56:26 by tdesmet           #+#    #+#             */
/*   Updated: 2022/02/01 16:40:58 by tdesmet          ###   ########.fr       */
/*   Updated: 2022/01/24 09:17:24 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_search_med(t_pile **pile, int size)
{
	t_pile		*temp;

	temp = *pile;
	while (ft_check_med(pile, temp, size))
		temp = temp->next;
	return (temp->val);
}

int	ft_check_med(t_pile **pile, t_pile *check, int size)
{
	t_pile	*temp;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	temp = *pile;
	while (k < size)
	{
		if (temp->val > check->val)
			i++;
		if (temp->val < check->val)
			j++;
		temp = temp->next;
		k++;
	}
	if (size % 2 == 0 && (i == j + 1 || j == i - 1))
		return (0);
	else if (size % 2 == 1 && i == j)
		return (0);
	else
		return (1);
}

int	ft_push_pivot(t_pile **a, t_pile **b, t_pile **pivot, s_index *cnt)
{
	int		size;
	int		i;
	t_pile	*temp;

	if (!a)
		return (0);
	i = 0;
	temp = *a;
	cnt->new_pivot = ft_search_med(a, cnt->nb_p);
	if (ft_search_min(a, b, pivot, cnt))
		return (0);
	size = cnt->nb_p;
	if (!(*b))
	{
		ft_first_split(a, b, pivot, cnt);
		size = cnt->nb_p;
		while (cnt->nb_p > 4)
			ft_next_split(a, b, pivot, cnt);
		return (0);
	}
	return (cnt->nb_p);
}
