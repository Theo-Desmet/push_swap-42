/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:41:03 by tdesmet           #+#    #+#             */
/*   Updated: 2022/02/11 13:47:42 by tdesmet          ###   ########.fr       */
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

void	ft_check_3(t_pile **a)
{
	if ((*a)->val > (*a)->next->val && (*a)->next->val < (*a)->next->next->val)
	{
		if ((*a)->val < (*a)->next->next->val)
		{
			ft_swap(a, "sa\n");
		}
		else
			ft_rotate(a, "ra\n");
	}
	if ((*a)->val < (*a)->next->val && (*a)->val > (*a)->next->next->val)
		ft_reverse_rotate(a, "rra\n");
	if ((*a)->val > (*a)->next->val && (*a)->val > (*a)->next->next->val)
	{
		ft_swap(a, "sa\n");
		ft_reverse_rotate(a, "rra\n");
	}
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

int	ft_check_sort(t_pile **pile, t_index *cnt)
{
	int		i;
	t_pile	*temp;
	t_pile	*temp2;

	if (!(*pile))
		return (0);
	i = 0;
	temp = *pile;
	temp2 = temp->next;
	while (i < cnt->nb_p && cnt->nb_p > 1)
	{
		while (temp2)
		{
			if (temp->val > temp2->val)
				return (0);
			temp2 = temp2->next;
		}
		i++;
		temp = temp->next;
		temp2 = temp->next;
	}
	return (1);
}
