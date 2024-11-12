/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzarins <kzarins@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 00:20:46 by kzarins           #+#    #+#             */
/*   Updated: 2024/11/11 22:26:46 by kzarins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_handle.h"
#define SUCCESS 		2
#define HEX_PREFIX_LEN 	2

int	write_trailing_padding(int *field_size_left, int len, int format_flags);
int	add_hex_zero_front(char **p_in_hex, struct s_field_specifiers field, \
		int format_flags);
int	add_zeros_after_prefix(char **p_in_hex, int hex_len_wo_prefix);

int	write_leading_padding(int *field_size_left, int len, int format_flags)
{
	if (len > *field_size_left)
		*field_size_left = len;
	if ((format_flags & (WITH_PADDING | RIGHT_PAD)) == WITH_PADDING)
	{
		while (*field_size_left > len)
		{
			if (write(STD_OUT, " ", sizeof(char)) == ERROR)
				return (ERROR);
			(*field_size_left)--;
		}
	}
	return (*field_size_left);
}

int	write_trailing_padding(int *field_size_left, int len, int format_flags)
{
	while (*field_size_left > len)
	{
		if (write(STD_OUT, " ", sizeof(char)) == ERROR)
			return (ERROR);
		(*field_size_left)--;
	}
	return (SUCCESS);
}

int	add_hex_zero_front(char **p_in_hex, struct s_field_specifiers field, \
		int format_flags)
{
	int	hex_num_len;

	hex_num_len = ft_strlen(*p_in_hex) - HEX_PREFIX_LEN;
	if ((field.precision > hex_num_len) && ((format_flags & \
				WITH_PRECISION) == WITH_PRECISION))
	{
		if (add_zeros_after_prefix(p_in_hex, field.precision) == ERROR)
			return (ERROR);
	}
	else if ((format_flags & (WITH_PRECISION | ZEROS)) == ZEROS)
	{
		if (add_zeros_after_prefix(p_in_hex, field.field_width - 2) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

int	add_zeros_after_prefix(char **p_in_hex, int hex_len_wo_prefix)
{
	int		p_in_hex_len;
	char	*result;
	int		current_loc;
	int		loc_in_result;

	p_in_hex_len = ft_strlen(*p_in_hex) - HEX_PREFIX_LEN;
	if (p_in_hex_len > hex_len_wo_prefix)
		return (SUCCESS);
	result = (char *)malloc(HEX_PREFIX_LEN + hex_len_wo_prefix + \
			+ NULL_SPACE_LEN);
	if (!result)
		return (ERROR);
	current_loc = 0;
	loc_in_result = 0;
	while (current_loc < 2)
		*(result + loc_in_result++) = *(*p_in_hex + current_loc++);
	while (loc_in_result < hex_len_wo_prefix - p_in_hex_len + HEX_PREFIX_LEN)
		*(result + loc_in_result++) = '0';
	while (loc_in_result < hex_len_wo_prefix + p_in_hex_len + HEX_PREFIX_LEN)
		*(result + loc_in_result++) = *(*p_in_hex + current_loc++);
	*(result + loc_in_result) = '\0';
	free (*p_in_hex);
	*p_in_hex = result;
	return (SUCCESS);
}

int	free_and_error(char **mem_to_free, int is_null)
{
	if (is_null)
	{
		free(*mem_to_free);
		*mem_to_free = 0;
	}
	return (ERROR);
}

//#include <stdio.h>
//int	main(void)
//{
//	char **test;
//	test = (char **)malloc(1);
//	*test = (char *)malloc(ft_strlen("0xabc") + 1);
//	ft_strlcpy(*test, "0xabc", ft_strlen("0xabc") + 1);
//	struct s_field_specifiers field;
//	field.field_width = 0;
//	field.precision = 5;
//	
//add_hex_zero_front(test, field,	WITH_PRECISION | ZEROS);
//int	test_len;
//test_len = ft_strlen(*test);
//printf("%s", *test);
//printf("\n%d", test_len);
//}
