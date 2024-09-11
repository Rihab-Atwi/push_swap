/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratwi <ratwi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:16:53 by ratwi             #+#    #+#             */
/*   Updated: 2024/07/26 14:16:54 by ratwi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_and_delete_stack(char *ptr, t_stack *s)
{
	free(ptr);
	delete_t_stack(s);
}

const char	*skip_whitespace(const char *str)
{
	while (is_whitespace(*str))
		str++;
	return (str);
}

char	*extract_word(const char *start, size_t length)
{
	char	*word;

	word = (char *)malloc(length + 1);
	if (word)
	{
		ft_strncpy(word, start, length);
		word[length] = '\0';
	}
	return (word);
}

int	process_word(t_stack *s, const char *word)
{
	long	value;

	if (!is_valid_integer(word))
		return (0);
	value = ft_atol(word);
	if (!check_long(value))
		return (0);
	add_tail(s, (int)value);
	return (!has_duplicates_t_stack(*s));
}

void	ft_split(t_stack *s, const char *str)
{
	const char	*start;
	char		*word;

	while (*str)
	{
		str = skip_whitespace(str);
		start = str;
		while (*str && !is_whitespace(*str))
			str++;
		if (str > start)
		{
			word = extract_word(start, str - start);
			if (!word || !process_word(s, word))
			{
				free_and_delete_stack(word, s);
				return ;
			}
			free(word);
		}
	}
}
