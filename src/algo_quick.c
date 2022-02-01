/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:41:03 by tdesmet           #+#    #+#             */
/*   Updated: 2022/01/31 14:31:17 by tdesmet          ###   ########.fr       */
/*   Updated: 2022/01/24 08:55:54 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void	ft_check_min(t_pile **pile, t_pile **pile_temp, t_pile **pivot, s_index *cnt)
{

	if (ft_rotate_sort(pile, cnt->nb_r - 1, (*pile)->val)
		&& ft_rotate_sort_temp(pile_temp, (*pile)->val))
	{
		cnt->nb_s++;
		cnt->nb_r--;
		cnt->nb_p--;
		if (*pivot && (*pile)->val == (*pivot)->val)
			free(ft_pop(pivot));
		ft_rotate(pile, "ra\n");
	}
	if (!(*pile_temp) || (*pile)->val > (*pivot)->val)
	{
		cnt->nb_r--;
		cnt->nb_p--;
		ft_push(pile_temp, pile, "pb\n");
	}
	else
	{
		cnt->nb_r--;
		cnt->nb_p--;
		ft_push(pile_temp, pile, "pb\n");
		ft_rotate(pile_temp, "rb\n");
	}
}

void	ft_check_2(t_pile **pile)
{
	if ((*pile)->val > (*pile)->next->val)
		ft_swap(pile, "sa\n");
}
*/
void	ft_check_2_bis(t_pile **pile)
{
	if ((*pile)->val > (*pile)->next->val)
		ft_swap(pile, "sa\n");
	ft_rotate(pile, "ra\n");
	ft_rotate(pile, "ra\n");
}
/*
void	ft_check_4(t_pile **a, t_pile **b)
{
	int	first = (*a)->val;
	int	second = (*a)->next->val;
	int	pre_last = (*a)->next->next->val;
	int	last = (*a)->next->next->next->val;

	if (first > second && first > pre_last && first > last)
	{
		ft_push(b, a, "pb\n");
		ft_check_3_bis(a, b);
		ft_push(a, b, "pa\n");
		ft_rotate(a, "ra\n");
	}
	else if (second < first && second < pre_last && second < last)
	{
		ft_swap(a, "sa\n");
		ft_rotate(a, "ra\n");
		ft_check_3_bis(a, b);
	}
	else
	{
		if (last > pre_last && last > second && last > first)
		{
			ft_check_3_bis(a, b);
			ft_rotate(a, "ra\n");
		}
		else 
		{
			ft_push(b, a, "pb\n");
			ft_push(b, a, "pb\n");
			ft_rotate(a, "ra\n");
			if (first > last)
			{
				ft_rotate(a, "ra\n");
				ft_push(a, b, "pa\n");
				ft_push(a, b, "pa\n");
				ft_rotate(a, "ra\n");
			}
			else
			{
				ft_swap(b, "sb\n");
				ft_push(a, b, "pa\n");
				ft_rotate(a, "ra\n");
				ft_rotate(a, "ra\n");
				ft_push(a, b, "pa\n");
			}
			ft_rotate(a, "ra\n");
		}
	}
}
*/ 
void	ft_check_3(t_pile **a)
{
	if ((*a)->val < (*a)->next->val && (*a)->val < (*a)->next->next->val
		&& (*a)->next->val > (*a)->next->next->val)
	{
		ft_rotate(a, "ra\n");
		ft_swap(a, "sa\n");
		ft_reverse_rotate(a, "rra\n");
	}
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
	if ((*a)->val < (*a)->next->val && (*a)->val < (*a)->next->next->val)
	{
		if ((*a)->next->val > (*a)->next->next->val)
		{
			ft_rotate(a, "ra\n");
			ft_swap(a, "sa\n");
		}
		else
			ft_rotate(a, "ra\n");
		ft_rotate(a, "ra\n");
		ft_rotate(a, "ra\n");
		return ;
	}
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
	ft_check_3_1_bis(a, b);
}

void	ft_check_3_1_bis(t_pile **a, t_pile **b)
{
	if((*a)->val > (*a)->next->val && (*a)->next->val < (*a)->next->next->val
		&& (*a)->val < (*a)->next->next->val)
	{
		ft_swap(a, "sa\n");
		ft_rotate(a, "ra\n");
		ft_rotate(a, "ra\n");
		ft_rotate(a, "ra\n");
		return ;
	}
	if((*a)->val > (*a)->next->val && (*a)->next->val < (*a)->next->next->val
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

int	ft_check_sort(t_pile **pile, s_index *cnt)
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
