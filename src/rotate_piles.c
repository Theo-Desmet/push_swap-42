/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_piles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 08:36:15 by tdesmet           #+#    #+#             */
/*   Updated: 2022/01/28 11:09:23 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_pile **pile, char *str)
{
	t_pile	*temp;
	t_pile	*last;

	if (!pile || !(*pile) || !(*pile)->next)
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
	ft_rotate(pilea, "");
	ft_rotate(pileb, "rr\n");
}
