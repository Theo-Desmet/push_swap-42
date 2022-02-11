/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 07:55:31 by tdesmet           #+#    #+#             */
/*   Updated: 2022/02/11 12:40:08 by tdesmet          ###   ########.fr       */
/*   Updated: 2022/01/21 15:38:03 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate_sort(t_pile *pile, int j, int val)
{
	int		i;
	t_pile	*temp;

	i = 0;
	if (!pile)
		return (1);
	temp = pile;
	while (i <= j)
	{
		if (!temp)
			return (1);
		if (temp->val < val)
			return (0);
		i++;
		temp = temp->next;
	}
	return (1);
}

int	ft_rotate_sort_temp(t_pile **pile, int val)
{
	int		i;
	t_pile	*temp;

	i = 0;
	if (!pile)
		return (0);
	if (!(*pile))
		return (1);
	temp = *pile;
	while (temp)
	{
		if (!temp)
			return (1);
		if (temp->val < val)
			return (0);
		i++;
		temp = temp->next;
	}
	return (1);
}

t_pile	*ft_pop(t_pile **pile)
{
	t_pile	*temp;

	if (!pile || !(*pile))
		return (NULL);
	temp = *pile;
	*pile = (*pile)->next;
	return (temp);
}

int	ft_search_pivot(t_pile **pile, int pivot)
{
	int		i;
	t_pile	*temp;

	i = 1;
	temp = *pile;
	while (temp->val != pivot)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void	sort2(t_pile **a, t_pile **b)
{
	t_index	*cnt;
	t_pile	**pivot;

	cnt = malloc(sizeof(t_index));
	cnt->nb_s = 0;
	cnt->nb_r = ft_pile_size(a);
	cnt->nb_p = cnt->nb_r;
	pivot = malloc(sizeof(t_pile));
	*pivot = NULL;
	while (cnt->nb_s < ft_pile_size(a))
	{
		cnt->nb_p = ft_push_pivot(a, b, pivot, cnt);
		while (*b)
			ft_push(a, b, "pa\n");
		cnt->nb_r = ft_pile_size(a) - cnt->nb_s;
		if (!(*pivot))
			cnt->nb_p = cnt->nb_r;
		else
			cnt->nb_p = ft_search_pivot(a, (*pivot)->val);
		if (cnt->nb_p > cnt->nb_r)
			cnt->nb_p = cnt->nb_r;
	}
	free(pivot);
	free(cnt);
}
