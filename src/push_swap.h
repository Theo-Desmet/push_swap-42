/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 10:48:45 by tdesmet           #+#    #+#             */
/*   Updated: 2022/01/20 07:43:28 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef	struct	t_pile	t_pile;
struct t_pile
{
	int		val;
	t_pile	*next;
};

typedef	struct s_index	s_index;
struct s_index
{
	int	nb_s;
	int	nb_r;
	int	nb_p;
};

void	aff(t_pile **pile);
void	ft_free_pile(t_pile **pile);
void	ft_swap(t_pile **pile, char *str);
void	ft_rotate(t_pile **pile, char *str);
void	sort2(t_pile **pile, t_pile **pile_temp);
void	ft_reverse_rotate(t_pile **pile, char *str);
void	ft_push_pile(t_pile **pile, t_pile *push);
void	ft_swap_ss(t_pile **pilea, t_pile **pileb);
void	ft_push(t_pile **pile1, t_pile **pile2, char *str);
void	ft_rotate_rr(t_pile **pilea, t_pile **pileb);
void    quicksort(t_pile **pile, t_pile **pile_temp, int first, int last);
void	ft_check_min(t_pile **pile, t_pile **pile_temp,
		t_pile **pivot, s_index *cnt);

t_pile	*ft_new_pile(int nb);
t_pile	*ft_pop(t_pile **pile);
t_pile	**ft_create_pile(int cont, char **str);
t_pile 	**sort(t_pile **pile, t_pile **pile_temp);

int	check_digit(char *str);
int	ft_str_size(char *str);
int	ft_atoi(const char *nptr);
int	ft_pile_size(t_pile *pile);
int	check_int(const char *nptr);
int	ft_strcmp(char *s1, char *s2);
int	check_args(int argc, char **argv);
int	check_doublons_split(char **tab);
int	ft_search_med(t_pile **pile, int size);
int	ft_rotate_sort(t_pile **pile, int j, int val);
int	ft_rotate_sort_temp(t_pile **pile, int val);
int	ft_push_pivot(t_pile **pile, t_pile **pile_temp, s_index *cnt);
int	ft_check_med(t_pile **pile, t_pile *check, int size);
int	check_doublons(char *str, int argc, char **argv, int i);

#endif
