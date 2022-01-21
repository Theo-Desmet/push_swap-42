/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_piles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:06:52 by tdesmet           #+#    #+#             */
/*   Updated: 2022/01/12 12:20:32 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_pile **pile_to, t_pile **pile_from, char *str)
{
	t_pile	*temp;

	if (!(*pile_from))
		return ;
	temp = *pile_from;
	*pile_from = (*pile_from)->next;
	temp->next = *pile_to;
	*pile_to = temp;
	ft_putstr(str);
}
