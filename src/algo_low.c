/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_low.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 08:34:07 by tdesmet           #+#    #+#             */
/*   Updated: 2022/02/14 09:10:02 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_2(t_pile **a)
{
	ft_swap(a, "sa\n");
}

void	ft_algo_low(t_pile **a, int argc)
{
	if (argc == 2)
		return ;
	else if (argc == 3)
		ft_check_2(a);
	else if (argc == 4)
		ft_check_3(a);
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
		ft_swap(a, "sa\n");
		ft_rotate(a, "ra\n");
	}
	else if ((*a)->val > (*a)->next->val && (*a)->val < (*a)->next->next->val)
		ft_swap(a, "sa\n");
	else
		ft_reverse_rotate(a, "rra\n");
}
