/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_handle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzarins <kzarins@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:18:24 by kzarins           #+#    #+#             */
/*   Updated: 2024/11/03 19:09:18 by kzarins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "format_handle.h"

static void	add_front_spacing(int *width_left, int len, int format_flags);
static void	add_back_spacing(int width_left, int len, int format_flags);

int	d_handle(int num, int field_width, int format_flags)
{
	char	*int_in_char;
	int		len;
	int		width_left;

	int_in_char = ft_itoa(num);
	width_left = field_width;
	if (!int_in_char)
		return (-1);
	len = ft_strlen(int_in_char);
	add_front_spacing(&width_left, len, format_flags);
	write(STD_OUT, int_in_char, len);
	add_back_spacing(width_left, len, format_flags);
	free(int_in_char);
	if (field_width > len)
		return (field_width);
	return (len);
}

static void	add_front_spacing(int *width_left, int len, int format_flags)
{
	if ((format_flags & (WITH_PADDING | RIGHT_PAD)) == WITH_PADDING)
		while (*width_left > len)
		{
			if ((format_flags & ZEROS) == ZEROS)
				write (STD_OUT, "0", 1);
			else
				write (STD_OUT, " ", 1);
			*width_left = *width_left - 1;
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
