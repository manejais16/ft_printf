/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_handle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzarins <kzarins@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 06:50:28 by kzarins           #+#    #+#             */
/*   Updated: 2024/11/12 23:37:58 by kzarins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_handle.h"
#define SUCCESS 		2

static int	add_num_precision(char **int_in_char, int precision, \
		int format_flags);
static int	add_signe(char **int_in_char, int num, int format_flags);
static int	convert_int_to_str(char **int_in_char, int num, \
				struct s_field_specifiers field, int format_flags);

int	d_handle(int num, struct s_field_specifiers field, int format_flags)
{
	char	*int_in_char;
	int		len;
	int		width_left;

	if (convert_int_to_str(&int_in_char, num, field, format_flags) == ERROR)
		return (ERROR);
	width_left = field.field_width;
	if (add_num_precision(&int_in_char, field.precision, format_flags) == ERROR)
		return (free_and_error(&int_in_char, 1));
	if (add_signe(&int_in_char, num, format_flags) == ERROR)
		return (free_and_error(&int_in_char, 1));
	len = ft_strlen(int_in_char);
	if (write_leading_padding(&width_left, len, format_flags) == ERROR)
		return (free_and_error(&int_in_char, 1));
	if (write (STD_OUT, int_in_char, len) == ERROR)
		return (free_and_error(&int_in_char, 1));
	if (write_trailing_padding(&width_left, len, format_flags) == ERROR)
		return (free_and_error(&int_in_char, 1));
	free(int_in_char);
	if (field.field_width > len)
		return (field.field_width);
	return (len);
}

static int	add_num_precision(char **int_in_char, int precision, \
		int format_flags)
{
	int		num_len;
	char	*null_char_filler;
	char	*result;

	null_char_filler = 0;
	result = *int_in_char;
	num_len = ft_strlen(*int_in_char);
	if (num_len < precision && (format_flags & WITH_PRECISION))
	{
		null_char_filler = (char *)malloc(precision - num_len + 1);
		if (!null_char_filler)
			return (ERROR);
		*(null_char_filler + precision - num_len) = '\0';
		while (precision-- > num_len)
			*(null_char_filler + precision - num_len) = '0';
		result = ft_strjoin(null_char_filler, *int_in_char);
		free(null_char_filler);
		if (!result)
			return (ERROR);
		free(*int_in_char);
		*int_in_char = result;
	}
	return (SUCCESS);
}

static int	add_signe(char **int_in_char, int num, int format_flags)
{
	char	*result;

	if (num >= 0 && (format_flags & PLUS_SING))
	{
		result = ft_strjoin("+", *int_in_char);
		if (!result)
			return (ERROR);
		free (*int_in_char);
		*int_in_char = result;
	}
	else if (num >= 0 && (format_flags & SPACE))
	{
		result = ft_strjoin(" ", *int_in_char);
		if (!result)
			return (ERROR);
		free (*int_in_char);
		*int_in_char = result;
	}
	return (SUCCESS);
}

static int	convert_int_to_str(char **int_in_char, int num, \
				struct s_field_specifiers field, int format_flags)
{
	if (num == 0 && field.precision == 0 && (format_flags & WITH_PRECISION))
	{
		*int_in_char = ft_strdup("");
		if (!*int_in_char)
			return (ERROR);
	}
	else
	{
		*int_in_char = ft_itoa(num);
		if (!*int_in_char)
			return (ERROR);
	}
	return (SUCCESS);
}

//#include <stdio.h>
//int	main(void)
//{
//	int	num = 758;
//	int str_len;
//	struct s_field_specifiers field;
//	int format_flags;
//
//	format_flags = WITH_PADDING | PLUS_SING ;//| RIGHT_PAD;
//	field.field_width = 2;
//	field.precision = 5; 
//	
//	str_len = d_handle(num, field, format_flags);
//	printf("E");
//	printf("\n%d", str_len);
//	return (0);
//}
