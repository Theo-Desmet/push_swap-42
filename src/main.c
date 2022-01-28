/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 07:58:53 by tdesmet           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/01/28 11:27:53 by tdesmet          ###   ########.fr       */
=======
/*   Updated: 2022/01/24 09:00:04 by tdesmet          ###   ########.fr       */
>>>>>>> 1eab80868c12352b9aa263f070939600c5fdd3af
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pile_size(t_pile **pile)
{
	t_pile	*temp;
	int	i;

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
	while ((*pile))
		free(ft_pop(pile));
	free(pile);
}

int	main(int argc, char **argv)
{
	t_pile	**a;
	t_pile	**b;

	b = malloc(sizeof(t_pile));
	*b = NULL;
	if (check_args(argc, argv) == 0)
		return (0);
	else
	{
		a = ft_create_pile(argc, argv);
		//ft_putstr("a: ");
		aff(a);
		sort2(a, b);
		//ft_putstr("a: ");
		aff(a);
	}
	ft_free_pile(b);
	ft_free_pile(a);
	return (0);
}
