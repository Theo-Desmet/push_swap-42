/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_piles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:25:52 by tdesmet           #+#    #+#             */
/*   Updated: 2022/01/12 12:22:41 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_pile **pile, char *str)
{
	int	temp;

	if (*pile != NULL || (*pile)->next != NULL)
	{	
		temp = (*pile)->val;
		(*pile)->val = (*pile)->next->val;
		(*pile)->next->val = temp;
	}
	ft_putstr(str);
}

void	ft_swap_ss(t_pile **pilea, t_pile **pileb)
{
	ft_swap(pilea, "sa");
	ft_swap(pileb, "sb");
}
