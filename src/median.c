/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 08:56:26 by tdesmet           #+#    #+#             */
/*   Updated: 2022/01/27 11:49:48 by tdesmet          ###   ########.fr       */
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

int	ft_push_pivot(t_pile **pile, t_pile **pile_temp, t_pile **pivot, s_index *cnt)
{
	int		new_pivot;
	int		size;
	int		i;
	t_pile	*temp;

	i = 0;
	if (!pile)
		return (0);
	temp = *pile;
	size = cnt->nb_p;
	new_pivot = ft_search_med(pile, cnt->nb_p);
	if (cnt->nb_p == 1/* || (new_pivot == (*pile)->val
		&& ft_rotate_sort(pile, cnt->nb_r - 1, (*pile)->val))*/)
	{
		ft_rotate(pile, "ra\n");
		free(ft_pop(pivot));
		cnt->nb_s++;
		return (0);
	}
	if (cnt->nb_p ==2)
	{
		ft_check_2_bis(pile, cnt);
		free(ft_pop(pivot));
		return (0);
	}
	if (!(*pile_temp) && !(*pivot) && cnt->nb_s == 0)
	{
		while (size--)
		{
			if ((*pile)->val == new_pivot)
			{
				ft_push_pile(pivot, ft_new_pile((*pile)->val));
				ft_push(pile_temp, pile, "pb\n");
				ft_rotate(pile_temp, "rb\n");
			}
			else if ((*pile)->val > new_pivot)
			{
				ft_rotate(pile, "ra\n");
				cnt->nb_p--;
			}
			else
				ft_push(pile_temp, pile, "pb\n");
			cnt->nb_r--;
		}
		ft_reverse_rotate(pile_temp, "rrb\n");
		//aff(pile);
		//aff(pile_temp);
		new_pivot = ft_search_med(pile_temp, cnt->nb_p);
		cnt->nb_r = cnt->nb_p;
		size = cnt->nb_p;
		while (cnt->nb_p > 2)
		{
			while (size--)
			{
				if ((*pile_temp)->val == new_pivot)
				{
					ft_push_pile(pivot, ft_new_pile((*pile_temp)->val));
					ft_push(pile, pile_temp, "pa\n");
					ft_rotate(pile, "ra\n");
				}
				else if ((*pile_temp)->val > new_pivot)
				{
					ft_push(pile, pile_temp, "pa\n");
					cnt->nb_p--;
				}
				else
					ft_rotate(pile_temp, "rb\n");
				cnt->nb_r--;
			}
			ft_reverse_rotate(pile, "rra\n");
			ft_push(pile_temp, pile, "pb\n");
			//aff(pile);
			//aff(pile_temp);
			new_pivot = ft_search_med(pile_temp, cnt->nb_p);
			cnt->nb_r = cnt->nb_p;
			size = cnt->nb_p;
		}
		return (0);
	}
	/*
	else
	{
		while (temp->val != new_pivot)
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
		ft_push_pile(pivot, ft_new_pile((*pile_temp)->val));
		cnt->nb_r--;
		cnt->nb_p--;
	}*/
	while ((*pile)->val != new_pivot)
	{	
		if (ft_rotate_sort(pile, cnt->nb_r - 1, (*pile)->val) && ft_rotate_sort_temp(pile_temp, (*pile)->val))
		{
			ft_rotate(pile, "ra\n");
			cnt->nb_s++;
		}
		else if ((*pile)->val > new_pivot)
		{
			ft_push(pile_temp, pile, "pb\n");
			ft_rotate(pile_temp, "rb\n");
			i++;
		}
		else
			ft_push(pile_temp, pile, "pb\n");
		cnt->nb_r--;
		cnt->nb_p--;
	}
	ft_push_pile(pivot, ft_new_pile((*pile)->val));
	ft_push(pile_temp, pile, "pb\n");
	while (i-- > 0)
		ft_reverse_rotate(pile_temp, "rrb\n");
	return (cnt->nb_p);
}
