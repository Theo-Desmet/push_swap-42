/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_low.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 08:34:07 by tdesmet           #+#    #+#             */
/*   Updated: 2022/02/15 14:14:28 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algo_low(t_pile **a, t_pile **b)
{
	if (ft_pile_size(a) == 1)
		return ;
	else if (ft_pile_size(a) == 2)
		ft_swap(a, "sa\n");
	else if (ft_pile_size(a) == 3)
		ft_check_3(a);
	else if (ft_pile_size(a) == 4)
		ft_check_4(a, b);
	else if (ft_pile_size(a) == 5)
		ft_check_5(a, b);
}

void	ft_check_3(t_pile **a)
{
	if ((*a)->val > (*a)->next->val && (*a)->val > (*a)->next->next->val)
	{
		ft_rotate(a, "ra\n");
		if ((*a)->val > (*a)->next->val)
			ft_swap(a, "sa\n");
	}
	else if ((*a)->val < (*a)->next->val && (*a)->val < (*a)->next->next->val)
	{
		if ((*a)->next->val < (*a)->next->next->val)
			return ;
		ft_swap(a, "sa\n");
		ft_rotate(a, "ra\n");
	}
	else if ((*a)->val > (*a)->next->val && (*a)->val < (*a)->next->next->val)
		ft_swap(a, "sa\n");
	else
		ft_reverse_rotate(a, "rra\n");
}

int	ft_research_min(t_pile **a)
{
	t_pile	*temp;
	int		i;
	int		min;

	temp = *a;
	min = (*a)->val;
	i = 1;
	while (temp->next)
	{
		if (min > temp->next->val)
			min = temp->next->val;
		temp = temp->next;
	}
	temp = *a;
	while (temp->val != min)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	ft_check_4(t_pile **a, t_pile **b)
{
	int	i;

	i = ft_research_min(a);
	if (i == 2)
		ft_rotate(a, "ra\n");
	else if (i == 3)
	{
		ft_reverse_rotate(a, "rra\n");
		ft_reverse_rotate(a, "rra\n");
	}
	if (i == 4)
		ft_reverse_rotate(a, "rra\n");
	ft_push(b, a, "pb\n");
	ft_check_3(a);
	ft_push(a, b, "pa\n");
}

void	ft_check_5(t_pile **a, t_pile **b)
{
	int	i;

	i = ft_research_min(a);
	if (i == 2)
		ft_rotate(a, "ra\n");
	else if (i == 3)
	{
		ft_rotate(a, "ra\n");
		ft_rotate(a, "ra\n");
	}
	if (i == 4)
	{
		ft_reverse_rotate(a, "rra\n");
		ft_reverse_rotate(a, "rra\n");
	}
	if (i == 5)
		ft_reverse_rotate(a, "rra\n");
	ft_push(b, a, "pb\n");
	ft_check_4(a, b);
	ft_push(a, b, "pa\n");
}
