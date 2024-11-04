/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_handle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzarins <kzarins@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:35:11 by kzarins           #+#    #+#             */
/*   Updated: 2024/11/03 22:41:26 by kzarins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "format_handle.h"

static char	*add_num_precision(char *int_in_char, int precision);
static void	add_front_spacing(int *width_left, int len, int format_flags);
static void	add_back_spacing(int width_left, int len, int format_flags);

int	i_handle(int num, struct s_field_specifiers field, int format_flags)
{
	char	*int_in_char;
	int		len;
	int		width_left;

	int_in_char = ft_itoa(num);
	width_left = field.field_width;
	if (!int_in_char)
		return (-1);
	int_in_char = add_num_precision(int_in_char, field.precision);
	len = ft_strlen(int_in_char);
	add_front_spacing(&width_left, len, format_flags);
	write(STD_OUT, int_in_char, len);
	add_back_spacing(width_left, len, format_flags);
	free(int_in_char);
	if (field.field_width > len)
		return (field.field_width);
	return (len);
}

static char	*add_num_precision(char *int_in_char, int precision)
{
	int		num_len;
	char	*null_char_filler;
	char	*result;

	null_char_filler = 0;
	result = int_in_char;
	num_len = ft_strlen(int_in_char);
	if (num_len < precision)
	{
		null_char_filler = (char *)malloc(precision - num_len + 1);
		if (!null_char_filler)
			return (0);
		*(null_char_filler + precision - num_len) = '\0';
		while (precision-- > num_len)
			*(null_char_filler + precision - num_len) = '0';
		result = ft_strjoin(null_char_filler, int_in_char);
		if (!result)
		{
			free(null_char_filler);
			return (int_in_char);
		}
		free(int_in_char);
	}
	return (result);
}

static void	add_front_spacing(int *width_left, int len, int format_flags)
{
	if ((format_flags & (WITH_PADDING | RIGHT_PAD)) == WITH_PADDING)
	{
		while (*width_left > len)
		{
			if ((format_flags & (ZEROS | WITH_PRECISION)) == ZEROS)
				write (STD_OUT, "0", 1);
			else
				write (STD_OUT, " ", 1);
			*width_left = *width_left - 1;
		}
	}
}

static void	add_back_spacing(int width_left, int len, int format_flags)
{
	while (width_left > len)
	{
		write (STD_OUT, " ", 1);
		width_left = width_left - 1;
	}
}
