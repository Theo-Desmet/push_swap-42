/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 07:55:31 by tdesmet           #+#    #+#             */
/*   Updated: 2022/02/01 13:30:51 by tdesmet          ###   ########.fr       */
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
	t_pile *temp;

	if (!pile || !(*pile))
		return (NULL);
	temp = *pile;
	*pile = (*pile)->next;
	return (temp);
}

t_pile	*ft_pile_last(t_pile *pile)
{
	if (!pile)
		return (NULL);
	while (pile && pile -> next)
		pile = pile -> next;
	return (pile);
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

void	sort2(t_pile **pile, t_pile **pile_temp)
{
	s_index	*cnt;
	t_pile	**pivot;

	cnt = malloc(sizeof(s_index));
	cnt->nb_s = 0;
	cnt->nb_r = ft_pile_size(pile);
	cnt->nb_p = cnt->nb_r;
	pivot = malloc(sizeof(t_pile));
	*pivot = NULL;
	while (cnt->nb_s < ft_pile_size(pile))
	{
		cnt->nb_p = ft_push_pivot(pile, pile_temp, pivot, cnt);
		while (*pile_temp)
			ft_push(pile, pile_temp, "pa\n");
		cnt->nb_r = ft_pile_size(pile) - cnt->nb_s;
		if (!(*pivot))
			cnt->nb_p = cnt->nb_r;
		else
			cnt->nb_p = ft_search_pivot(pile, (*pivot)->val);
		if (cnt->nb_p > cnt->nb_r)
			cnt->nb_p = cnt->nb_r;
	}
	free(pivot);
	free(cnt);
}
