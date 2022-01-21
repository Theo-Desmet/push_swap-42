/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 08:56:26 by tdesmet           #+#    #+#             */
/*   Updated: 2022/01/19 16:29:18 by tdesmet          ###   ########.fr       */
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

int	ft_push_pivot(t_pile **pile, t_pile **pile_temp, s_index *cnt)
{
	int		pivot;
	int		i;
	int		j;
	t_pile	*temp;

	i = 0;
	if (!pile)
		return (0);
	temp = *pile;
	pivot = ft_search_med(pile, cnt->nb_p);
	if (cnt->nb_p == 1 || (pivot == (*pile)->val
		&& ft_rotate_sort(pile, cnt->nb_r - 1, (*pile)->val)))
	{
		ft_rotate(pile, "ra\n");
		cnt->nb_s++;
		return (0);
	}
	while (temp->val != pivot)
	{
		temp = temp->next;
		i++;
	}
	j = i;
	while (i-- > 0)
		ft_rotate(pile, "ra\n");
	ft_push(pile_temp, pile, "pb\n");
	while (j-- > 0)
		ft_reverse_rotate(pile, "rra\n");
	cnt->nb_r--;
	cnt->nb_p--;
	return (cnt->nb_p);
}
