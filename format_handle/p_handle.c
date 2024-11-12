/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_handle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzarins <kzarins@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:15:43 by kzarins           #+#    #+#             */
/*   Updated: 2024/11/11 22:28:28 by kzarins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "format_handle.h"
#define NULL_CASE "0x0"

int	handle_null_ptr(void *p, int field_width, int format_flags);

int	p_handle(void *p, struct s_field_specifiers field, int format_flags)
{
	char	*p_in_hex;
	int		str_len;
	int		field_size_left;

	if (!p)
		return (handle_null_ptr(p, field.field_width, format_flags));
	field_size_left = field.field_width;
	p_in_hex = int_to_hex((unsigned long) p, WITH_PREFIX);
	if (!p_in_hex)
		return (ERROR);
	if (add_hex_zero_front(&p_in_hex, field, format_flags) == ERROR)
		return (free_and_error(&p_in_hex, 1));
	str_len = ft_strlen(p_in_hex);
	if (write_leading_padding(&field_size_left, str_len, format_flags) \
			== ERROR)
		return (free_and_error(&p_in_hex, 1));
	if (write(STD_OUT, p_in_hex, str_len) == ERROR)
		return (free_and_error(&p_in_hex, 1));
	if (write_trailing_padding(&field_size_left, str_len, format_flags) \
			== ERROR)
		return (ERROR);
	free(p_in_hex);
	if (field.field_width > str_len)
		return (field.field_width);
	return (str_len);
}

int	handle_null_ptr(void *p, int field_width, int format_flags)
{
	int	str_len;
	int	field_size_left;

	field_size_left = field_width;
	str_len = ft_strlen(NULL_CASE);
	if (write_leading_padding(&field_size_left, str_len, format_flags) \
			== ERROR)
		return (ERROR);
	if (write(STD_OUT, NULL_CASE, str_len) == ERROR)
		return (ERROR);
	if (write_trailing_padding(&field_size_left, str_len, format_flags) \
			== ERROR)
		return (ERROR);
	if (str_len > field_width)
		return (str_len);
	return (field_width);
}

//int	main(void)
//{
//	int a, *b;
//	struct s_field_specifiers field;
//	int format_flags;
//
//	a = 7;
//	b = &a;
//	format_flags = WITH_PADDING;
//	field.field_width = 21;
//	field.precision = 22; 
//	
//	p_handle(b, field, format_flags);
//	return (0);
//}
