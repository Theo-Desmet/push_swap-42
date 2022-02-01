/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 08:56:26 by tdesmet           #+#    #+#             */
/*   Updated: 2022/02/01 08:30:10 by tdesmet          ###   ########.fr       */
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

int	ft_push_pivot(t_pile **pile, t_pile **pile_temp, t_pile **pivot, s_index *cnt)
{
	int		new_pivot;
	int		size;
	int		i;
	t_pile	*temp;

	if (!pile)
		return (0);
	i = 0;
	temp = *pile;
	size = cnt->nb_p;
	new_pivot = ft_search_med(pile, cnt->nb_p);
	if (!(*pile_temp))
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
			/*	if (*pile_temp && (*pile_temp)->val < new_pivot / 2)
					ft_rotate_rr(pile, pile_temp);
				else
					*/ft_rotate(pile, "ra\n");
				cnt->nb_p--;
				i++;
			}
			else
				ft_push(pile_temp, pile, "pb\n");
			cnt->nb_r--;
		}
		ft_reverse_rotate(pile_temp, "rrb\n");
		//aff(pile);
		//aff(pile_temp);
		if (cnt->nb_s != 0)
		{
			while (i)
			{
				ft_reverse_rotate(pile, "rra\n");
				i--;
			}	
		}	
		new_pivot = ft_search_med(pile_temp, cnt->nb_p);
		cnt->nb_r = cnt->nb_p;
		size = cnt->nb_p;
		while (cnt->nb_p > 4)
		{
			while (size--)
			{
				if ((*pile_temp)->val == new_pivot)
				{
					ft_push_pile(pivot, ft_new_pile((*pile_temp)->val));
					ft_push(pile, pile_temp, "pa\n");
					ft_rotate(pile, "ra\n");
					cnt->nb_p--;
				}
			/*	else if (ft_rotate_sort_temp(pile_temp, (*pile_temp)->val
					&& new_pivot != ft_pile_last(*pile)->val))
				{
					ft_push(pile, pile_temp, "pa\n");
					ft_rotate(pile, "ra\n");
					cnt->nb_p--;
					cnt->nb_r--;
					cnt->nb_s++;
				}*/
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
			//aff(pile);
			//aff(pile_temp);
			new_pivot = ft_search_med(pile_temp, cnt->nb_p);
			cnt->nb_r = cnt->nb_p;
			size = cnt->nb_p;
		}
		return (0);
	}
	return (cnt->nb_p);
	ft_push_med(pile, pile_temp, new_pivot, cnt);
	ft_push_pile(pivot, ft_new_pile((*pile_temp)->val));
	cnt->nb_r--;
	cnt->nb_p--;
	return (cnt->nb_p);
}
void	ft_push_med(t_pile **pile, t_pile **pile_temp, int new_pivot, s_index *cnt)
{
	int		i;
	int		j;
	t_pile	*temp;
	
	i = 0;
	j = 0;
	temp = *pile;
	if (cnt->nb_s)
		;
	while (temp->val != new_pivot)
	{
		temp = temp->next;
		ft_rotate(pile, "ra\n");
		i++;
	}
	ft_push(pile_temp, pile, "pb\n");
	while (i-- > 0)
		ft_reverse_rotate(pile, "rra\n");
}
