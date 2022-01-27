/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 07:58:53 by tdesmet           #+#    #+#             */
/*   Updated: 2022/01/26 13:39:40 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pile_size(t_pile *pile)
{
	t_pile	*temp;
	int	i;

	if (!pile)
		return (0);
	i = 0;
	temp = pile;
	while (temp)
	{
		i++;
		temp = temp -> next;
	}
	return (i);
}

void	ft_free_pile(t_pile **pile)
{
	if (!pile)
		return ; 
	while (*pile)
		free(ft_pop(pile));
	free(pile);
}

int	main(int argc, char **argv)
{
	t_pile	**a;
	t_pile	**b;

	b = malloc(sizeof(t_pile));
	if (check_args(argc, argv) == 0)
		return (0);
	else
	{
		a = ft_create_pile(argc, argv);
		//ft_putstr("a: ");
		//aff(a);
		sort2(a, b);
		//ft_putstr("a: ");
		//aff(a);
	}
	ft_free_pile(a);
	ft_free_pile(b);
	return (0);
}
