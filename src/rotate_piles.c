/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_piles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 08:36:15 by tdesmet           #+#    #+#             */
/*   Updated: 2022/01/20 09:53:00 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_pile **pile, char *str)
{
	t_pile	*temp;
	t_pile	*last;

	if (!pile || !(*pile) || ft_pile_size(*pile) <= 1)
		return ;
	temp = *pile;
	last = *pile;
	*pile = (*pile)->next;
	while (last->next)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
	ft_putstr(str);
}

void	ft_rotate_rr(t_pile **pilea, t_pile **pileb)
{
	ft_rotate(pilea, "ra ");
	ft_rotate(pileb, "rb\n");
}
