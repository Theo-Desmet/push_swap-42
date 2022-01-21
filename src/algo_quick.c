/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:41:03 by tdesmet           #+#    #+#             */
/*   Updated: 2022/01/21 13:58:08 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_min(t_pile **pile, t_pile **pile_temp, t_pile pivot, s_index *cnt)
{
	if (ft_rotate_sort(pile, cnt->nb_r - 1, (*pile)->val) && ft_rotate_sort_temp(pile_temp, (*pile)->val))
	{
		cnt->nb_s++;
		cnt->nb_r--;
		cnt->nb_p--;
		if ((*pile)->val == pivot)
			free(ft_pop(pivot));
		ft_rotate(pile, "ra\n");
	}
	else if (!(*pile_temp) || (*pile)->val > pivot)
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
