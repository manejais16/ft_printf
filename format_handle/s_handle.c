/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_handle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzarins <kzarins@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 01:12:43 by kzarins           #+#    #+#             */
/*   Updated: 2024/11/12 23:17:17 by kzarins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_handle.h"
#include <stdio.h>

#define NULL_PTR_OUTPUT "(null)"
#define SUCCESS 		2

static int	change_null_to_str(char **str);

int	s_handle(char *str, int field_width, int format_flags)
{
	int	field_size_left;
	int	str_len;
	int	is_null;

	field_size_left = field_width;
	is_null = 0;
	if (!str)
		if (change_null_to_str(&str) == ERROR || !++is_null)
			return (ERROR);
	str_len = ft_strlen(str);
	if (write_leading_padding(&field_size_left, str_len, format_flags) \
			== ERROR)
		return (free_and_error(&str, is_null));
	if (putstr_fd(str, STD_OUT) == ERROR)
		return (free_and_error(&str, is_null));
	if (write_trailing_padding(&field_size_left, str_len, format_flags) \
			== ERROR)
		return (free_and_error(&str, is_null));
	if (is_null)
		free (str);
	if (field_width > str_len)
		return (field_width);
	return (str_len);
}

static int	change_null_to_str(char **str)
{
	int		word_len;

	word_len = ft_strlen(NULL_PTR_OUTPUT);
	*str = (char *)malloc(word_len + NULL_SPACE_LEN);
	if (!*str)
		return (ERROR);
	ft_strlcpy(*str, NULL_PTR_OUTPUT, word_len + NULL_SPACE_LEN);
	return (SUCCESS);
}
