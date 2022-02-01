/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_first.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 08:28:59 by tdesmet           #+#    #+#             */
/*   Updated: 2022/02/01 08:34:40 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_search_min(t_pile **pile, t_pile **pile_temp, s_index *cnt)
{
	int	first;
	while (ft_rotate_sort(*pile, cnt->nb_r -1, (*pile)->val))
	{
		if (new_pivot == (*pile)->val)
			free(ft_pop(pivot));
		ft_rotate(pile, "ra\n");
		cnt->nb_s++;
		cnt->nb_r--;
		return (0);
	}
	while (ft_rotate_sort(*pile, cnt->nb_r - 3, (*pile)->next->val) && ft_rotate_sort((*pile)->next->next, cnt->nb_r - 3, (*pile)->val))
	{
		if (new_pivot == (*pile)->val || new_pivot == (*pile)->next->val)
			free(ft_pop(pivot));
		ft_check_2_bis(pile);
		cnt->nb_s+=2;
		cnt->nb_r-=2;
		return (0);
	}
	while (ft_rotate_sort((*pile)->next->next->next, cnt->nb_r - 4, (*pile)->val)
		&& ft_rotate_sort((*pile)->next->next->next, cnt->nb_r - 4, (*pile)->next->val)
		&& ft_rotate_sort((*pile)->next->next->next, cnt->nb_r - 4, (*pile)->next->next->val))
	{
		if (new_pivot == (*pile)->val || new_pivot == (*pile)->next->val || new_pivot == (*pile)->next->val)
			free(ft_pop(pivot));
		ft_check_3_bis(pile, pile_temp);
		cnt->nb_s+=3;
		cnt->nb_r-=3;
		return (0);
	}
}
