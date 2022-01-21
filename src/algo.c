/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 07:55:31 by tdesmet           #+#    #+#             */
/*   Updated: 2022/01/21 09:08:48 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	ft_rotate_sort(t_pile **pile, int j, int val)
{
	int		i;
	t_pile	*temp;

	i = 0;
	if (!pile)
		return (0);
	if (!ft_pile_size(*pile))
		return (1);
	temp = *pile;
	while (i <= j)
	{
		if (!ft_pile_size(temp))
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
	if (!ft_pile_size(*pile))
		return (1);
	temp = *pile;
	while (temp)
	{
		if (!ft_pile_size(temp))
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
	cnt->nb_r = ft_pile_size(*pile);
	cnt->nb_p = cnt->nb_r;
	pivot = malloc(sizeof(t_pile));
//	aff(pile);
	while (cnt->nb_s < ft_pile_size(*pile))
	{
		cnt->nb_p = ft_push_pivot(pile, pile_temp, pivot, cnt);
		while (cnt->nb_p > 0)
			ft_check_min(pile, pile_temp, pivot, cnt);
		while (*pile_temp)
			ft_push(pile, pile_temp, "pa\n");
		cnt->nb_r = ft_pile_size(*pile) - cnt->nb_s;
		if (!(*pivot))
			cnt->nb_p = cnt->nb_r;
		else
			cnt->nb_p = ft_search_pivot(pile, (*pivot)->val);
		if (cnt->nb_p > cnt->nb_r)
			cnt->nb_p = cnt->nb_r;
		
//		aff(pile);
//		aff(pivot);
	}
	free(pivot);
	free(cnt);
}
/*
void	sort2(t_pile **pile, t_pile **pile_temp)
{
	int		i;
	int		j;
	int		k;
	t_pile	**pivot;
	t_pile	*temp;

	i = 0;
	j = ft_pile_size(*pile);
	k = j;
	pivot = malloc(sizeof(t_pile));
	while (i < ft_pile_size(*pile))
	{
		k = ft_push_pivot(pile, pile_temp, &k, &j, cnt);
		if (k > 1)
		{
			temp = ft_new_pile((*pile_temp)->val);
			ft_push_pile(pivot, temp);
		}
		else if (!(*pivot) || (ft_pile_last(*pile))->val == (*pivot)->val)
			free(ft_pop(pivot));
		while (k > 0)
		{
			if (!(*pivot))
			{	
				temp = ft_new_pile((*pile)->val);
				ft_push_pile(pivot, temp);
				k = j;
			}
			else if (ft_rotate_sort(pile, j - 1, (*pile)->val) && ft_rotate_sort_temp(pile_temp, (*pile)->val))
			{
				i++;
				j--;
				k--;
				if ((*pile)->val == (*pivot)->val)
					free(ft_pop(pivot));
				ft_rotate(pile, "ra\n");
			}
			else if (!(*pile_temp) || (*pile)->val > (*pivot)->val)
			{
				j--;
				k--;
				ft_push(pile_temp, pile, "pa\n");
			}
			else
			{
				j--;
				k--;
				ft_push(pile_temp, pile, "pa\n");
				ft_rotate(pile_temp, "rb\n");
			}
		}
		while (*pile_temp)
			ft_push(pile, pile_temp, "pb\n");
		j = ft_pile_size(*pile) - i;
		if (!(*pivot))
			k = j;
		else
			k = ft_search_pivot(pile, (*pivot)->val);
		if (k > j)
			k = j;
	}
}*/
