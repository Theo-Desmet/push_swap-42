/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_first.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 08:28:59 by tdesmet           #+#    #+#             */
/*   Updated: 2022/02/11 13:48:42 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_search_min(t_pile **a, t_pile **b, t_pile **pivot, t_index *cnt)
{
	if (ft_search_first(a, pivot, cnt) || ft_search_second(a, pivot, cnt)
		|| ft_search_third(a, b, pivot, cnt))
		return (1);
	return (0);
}

int	ft_search_first(t_pile **a, t_pile **pivot, t_index *cnt)
{
	if (ft_rotate_sort(*a, cnt->nb_r -1, (*a)->val) && cnt->nb_r)
	{
		if (cnt->new_pivot == (*a)->val)
			free(ft_pop(pivot));
		ft_rotate(a, "ra\n");
		cnt->nb_s++;
		cnt->nb_r--;
		cnt->nb_p--;
		return (1);
	}
	return (0);
}

int	ft_search_second(t_pile **a, t_pile **pivot, t_index *cnt)
{
	if (ft_rotate_sort(*a, cnt->nb_r - 3, (*a)->next->val) && cnt->nb_r
		&& ft_rotate_sort((*a)->next->next, cnt->nb_r - 3, (*a)->val))
	{
		if (cnt->new_pivot == (*a)->val
			|| cnt->new_pivot == (*a)->next->val)
			free(ft_pop(pivot));
		ft_check_2_bis(a);
		cnt->nb_s += 2;
		cnt->nb_r -= 2;
		cnt->nb_p -= 2;
		return (1);
	}
	return (0);
}

int	ft_search_third(t_pile **a, t_pile **b, t_pile **pivot, t_index *cnt)
{
	t_pile	*first;
	t_pile	*second;
	t_pile	*third;
	t_pile	*last;

	first = *a;
	second = (*a)->next;
	third = (*a)->next->next;
	last = (*a)->next->next->next;
	if (ft_rotate_sort(last, cnt->nb_r - 4, first->val) && cnt->nb_r
		&& ft_rotate_sort(last, cnt->nb_r - 4, second->val)
		&& ft_rotate_sort(last, cnt->nb_r - 4, third->val))
	{
		if (cnt->new_pivot == first->val
			|| cnt->new_pivot == second->val
			|| cnt->new_pivot == third->val)
			free(ft_pop(pivot));
		ft_check_3_bis(a, b);
		cnt->nb_s += 3;
		cnt->nb_r -= 3;
		cnt->nb_p -= 3;
		return (1);
	}
	return (0);
}
