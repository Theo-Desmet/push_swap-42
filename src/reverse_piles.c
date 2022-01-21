/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_piles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 09:26:31 by tdesmet           #+#    #+#             */
/*   Updated: 2022/01/12 13:34:47 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_pile **pile, char *str)
{
	t_pile	*last;
	t_pile	*temp;

	if (ft_pile_size(*pile) == 2)
	{
		ft_swap(pile, str);
		return ;
	}
	if (pile && *pile && ft_pile_size(*pile) > 1)
	{	
		last = *pile;
		while (last->next)
		{	
			temp = last;
			last = last->next;
		}
		last->next = *pile;
		*pile = last;
		temp->next = NULL;
	}
	ft_putstr(str);
}

void	ft_reverse_rotate_rrr(t_pile **pilea, t_pile **pileb)
{
	ft_reverse_rotate(pilea, "rra");
	ft_reverse_rotate(pileb, "rrb");
}
