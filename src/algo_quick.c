/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:41:03 by tdesmet           #+#    #+#             */
/*   Updated: 2022/02/14 08:35:39 by tdesmet          ###   ########.fr       */
/*   Updated: 2022/01/24 08:55:54 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_2_bis(t_pile **pile)
{
	if ((*pile)->val > (*pile)->next->val)
		ft_swap(pile, "sa\n");
	ft_rotate(pile, "ra\n");
	ft_rotate(pile, "ra\n");
}

void	ft_check_3_bis(t_pile **a, t_pile **b)
{
	if ((*a)->val > (*a)->next->val && (*a)->val > (*a)->next->next->val
		&& (*a)->next->val > (*a)->next->next->val)
	{
		ft_push(b, a, "pb\n");
		ft_swap(a, "sa\n");
		ft_rotate(a, "ra\n");
		ft_rotate(a, "ra\n");
		ft_push(a, b, "pa\n");
		ft_rotate(a, "ra\n");
		return ;
	}
	if ((*a)->val > (*a)->next->val && (*a)->next->val < (*a)->next->next->val
		&& (*a)->val < (*a)->next->next->val)
	{
		ft_swap(a, "sa\n");
		ft_rotate(a, "ra\n");
		ft_rotate(a, "ra\n");
		ft_rotate(a, "ra\n");
		return ;
	}
	ft_check_3_1_bis(a, b);
}

void	ft_check_3_1_bis(t_pile **a, t_pile **b)
{
	if ((*a)->val > (*a)->next->val && (*a)->next->val < (*a)->next->next->val
		&& (*a)->val > (*a)->next->next->val)
	{
		ft_push(b, a, "pb\n");
		ft_rotate(a, "ra\n");
		ft_rotate(a, "ra\n");
		ft_push(a, b, "pa\n");
		ft_rotate(a, "ra\n");
		return ;
	}
	if ((*a)->val < (*a)->next->val && (*a)->val > (*a)->next->next->val)
	{
		ft_rotate(a, "ra\n");
		ft_swap(a, "sa\n");
		ft_reverse_rotate(a, "rra\n");
		ft_swap(a, "sa\n");
		ft_rotate(a, "ra\n");
		ft_rotate(a, "ra\n");
		ft_rotate(a, "ra\n");
		return ;
	}
}
