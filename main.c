/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratwi <ratwi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:16:57 by ratwi             #+#    #+#             */
/*   Updated: 2024/07/26 14:16:59 by ratwi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_single_argument(t_stack *s, char *arg)
{
	ft_split(s, arg);
	if (*s == NULL)
	{
		write(1, "Error", 5);
		exit(-1);
	}
}

void	handle_multiple_arguments(int argc, char **argv, t_stack *s)
{
	if (!validate_and_add_arguments(argc, argv, s))
		cleanup_and_exit(s);
}

int	validate_and_add_arguments(int argc, char **argv, t_stack *s)
{
	int	i;

	i = 1;
	if (!has_duplicates(argc, argv))
	{
		write(1, "Error", 5);
		return (0);
	}
	while (i < argc)
	{
		if (!is_valid_integer(argv[i]))
		{
			write(1, "Error", 5);
			return (0);
		}
		if (!check_long(ft_atol(argv[i])))
		{
			write(1, "Error", 5);
			return (0);
		}
		add_tail(s, (int)ft_atol(argv[i]));
		i++;
	}
	return (1);
}

void	cleanup_and_exit(t_stack *s)
{
	delete_t_stack(s);
	exit(-1);
}

int	main(int argc, char **argv)
{
	t_stack		s;

	s = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
		handle_single_argument(&s, argv[1]);
	else
		handle_multiple_arguments(argc, argv, &s);
	edge_case_sort(&s);
	return (0);
}

// int main(int argc, char **argv)
// {
//     t_stack s = NULL;
//     int i = 1;
//     if (argc == 1)
//         return (0);
//     else if (argc == 2)
//     { 
//         ft_split(&s,argv[1]);
//         if (s == NULL)
//         {
//             //write(1,"Error",5);
//             printf("Error");
//             exit(-1);
//         }
//     }
//     else
//     {
//         if(!has_duplicates(argc,argv))
//         {
//             //write(1,"Error",5);
//             printf("Error");
//             delete_t_stack(&s);
//             exit(-1);
//         }
//         while (i < argc)
//         {
//             if(!is_valid_integer(argv[i]))
//             {
//                 delete_t_stack(&s);
//                 //write(1,"Error",5);
//                 printf("Error");
//                 exit(-1);
//             }
//             if(!check_long(ft_atol(argv[i])))
//             {
//                 delete_t_stack(&s);
//                 //write(1,"Error",5);
//                 printf("Error");
//                 exit(-1);
//             }
//             add_tail(&s, (int)ft_atol(argv[i]));
//             i++;
//         }
//     }
//     edge_case_sort(&s);
//     return (0);
// }
