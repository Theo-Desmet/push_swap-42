/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 07:58:53 by tdesmet           #+#    #+#             */
/*   Updated: 2022/02/15 14:13:12 by tdesmet          ###   ########.fr       */
/*   Updated: 2022/01/24 09:00:04 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pile_size(t_pile **pile)
{
	t_pile	*temp;
	int		i;

	if (!pile || !(*pile))
		return (0);
	i = 0;
	temp = *pile;
	while (temp)
	{
		i++;
		temp = temp -> next;
	}
	return (i);
}

void	ft_free_pile(t_pile **pile)
{
	while (*pile)
		free(ft_pop(pile));
	free(pile);
}

int	main(int argc, char **argv)
{
	t_pile	**a;
	t_pile	**b;

	b = malloc(sizeof(t_pile));
	*b = NULL;
	if (argc == 1 || check_args(argc, argv) == 0)
	{
		ft_free_pile(b);
		return (0);
	}
	a = ft_create_pile(argc, argv);
	if (ft_pre_sort(a))
	{
		ft_free_pile(b);
		ft_free_pile(a);
		return (0);
	}
	else if (ft_pile_size(a) < 6)
		ft_algo_low(a, b);
	else
		sort2(a, b);
	ft_free_pile(b);
	ft_free_pile(a);
	return (0);
}
