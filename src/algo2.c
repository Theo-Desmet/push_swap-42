/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:03:22 by tdesmet           #+#    #+#             */
/*   Updated: 2022/02/01 17:05:37 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_first_split(t_pile **a, t_pile **b, t_pile **pivot, s_index *cnt)
{
	int	size;	
	int	i;

	i = 0;
	size = cnt->nb_p;
	while (size--)
	{
		if ((*a)->val == cnt->new_pivot)
		{
			ft_push_pile(pivot, ft_new_pile((*a)->val));
			ft_push(b, a, "pb\n");
			ft_rotate(b, "rb\n");
		}
		else if ((*a)->val > cnt->new_pivot)
		{	
			ft_rotate(a, "ra\n");
			cnt->nb_p--;
			i++;
		}
		else
			ft_push(b, a, "pb\n");
		cnt->nb_r--;
	}
	ft_first_split2(a, b, i, cnt);
}

void	ft_first_split2(t_pile **a, t_pile **b, int i, s_index *cnt)
{
	ft_reverse_rotate(b, "rrb\n");
	if (cnt->nb_s != 0)
	{
		while (i)
		{
			ft_reverse_rotate(a, "rra\n");
			i--;
		}	
	}	
	cnt->new_pivot = ft_search_med(b, cnt->nb_p);
	cnt->nb_r = cnt->nb_p;
}

void	ft_next_split(t_pile **a, t_pile **b, t_pile **pivot, s_index *cnt)
{
	int	size;

	size = cnt->nb_p;
	while (size--)
	{
		if ((*b)->val == cnt->new_pivot)
		{
			ft_push_pile(pivot, ft_new_pile((*b)->val));
			ft_push(a, b, "pa\n");
			ft_rotate(a, "ra\n");
			cnt->nb_p--;
		}
		else if ((*b)->val > cnt->new_pivot)
		{
			ft_push(a, b, "pa\n");
			cnt->nb_p--;
		}
		else if (ft_rotate_sort(*b, cnt->nb_r -1, (*b)->val)
				&& ft_pile_last(*a)->val != cnt->new_pivot)
		{
			ft_push(a, b, "pa\n");
			ft_rotate(a, "ra\n");
			cnt->nb_p--;
			cnt->nb_s++;
			
		}
		else
			ft_rotate(b, "rb\n");
		cnt->nb_r--;
	}
	ft_reverse_rotate(a, "rra\n");
	cnt->new_pivot = ft_search_med(b, cnt->nb_p);
	cnt->nb_r = cnt->nb_p;
	size = cnt->nb_p;
}
