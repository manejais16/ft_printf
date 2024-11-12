/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzarins <kzarins@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 00:16:16 by kzarins           #+#    #+#             */
/*   Updated: 2024/11/12 23:18:32 by kzarins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define HEX_PREFIX_LEN 		2
#define HEX_CHAR_L_CASE 	"0123456789abcdef"
#define HEX_CHAR_U_CASE		"0123456789ABCDEF"
#define HEX_PREFIX_L_CASE	"0x"
#define HEX_PREFIX_U_CASE	"0X"
#include "format_handle.h"

static int	char_spaces_needed(unsigned long num);
static void	add_prefix(char *hex_represent, unsigned int flags);
static char	digit_to_hex(int dig, unsigned int flags);
static char	*free_and_return_zero(char *str);

char	*int_to_hex(unsigned long num, unsigned int fla)
{
	int		output_len;
	char	*hex_represent;
	int		char_iter;
	int		prefix_len;

	prefix_len = 0;
	output_len = char_spaces_needed(num);
	char_iter = output_len;
	if (fla & WITH_PREFIX)
		prefix_len = HEX_PREFIX_LEN;
	hex_represent = (char *) malloc(output_len + NULL_SPACE_LEN + \
			prefix_len);
	if (!hex_represent)
		return (0);
	if (prefix_len)
		add_prefix(hex_represent, fla);
	while (char_iter-- > 0)
	{
		*(hex_represent + prefix_len + char_iter) = digit_to_hex(num % 16, fla);
		if (*(hex_represent + prefix_len + char_iter) == ERROR)
			return (free_and_return_zero(hex_represent));
		num /= 16;
	}
	*(hex_represent + prefix_len + output_len) = '\0';
	return (hex_represent);
}

static int	char_spaces_needed(unsigned long num)
{
	int	char_spaces;

	char_spaces = 1;
	num /= 16;
	while (num)
	{
		num /= 16;
		char_spaces++;
	}
	return (char_spaces);
}

static void	add_prefix(char *hex_represent, unsigned int flags)
{
	if (flags & UPPER_CASE_PREFIX)
		ft_memcpy(hex_represent, HEX_PREFIX_U_CASE, HEX_PREFIX_LEN);
	else
		ft_memcpy(hex_represent, HEX_PREFIX_L_CASE, HEX_PREFIX_LEN);
}

static char	digit_to_hex(int dig, unsigned int flags)
{
	char	*hex_chart;
	char	hex_code;

	hex_chart = (char *)malloc(ft_strlen(HEX_CHAR_L_CASE) + 1);
	if (!hex_chart)
		return (ERROR);
	if (flags & UPPER_CASE_CHAR)
		ft_strlcpy(hex_chart, HEX_CHAR_U_CASE, ft_strlen(HEX_CHAR_U_CASE) + 1);
	else
		ft_strlcpy(hex_chart, HEX_CHAR_L_CASE, ft_strlen(HEX_CHAR_L_CASE) + 1);
	hex_code = *(hex_chart + (dig % 16));
	free(hex_chart);
	return (hex_code);
}

static char	*free_and_return_zero(char *str)
{
	free(str);
	return (0);
}
//
//#include <stdio.h>
//int	main(void)
//{
//	int flags = WITH_PREFIX /*| UPPER_CASE_PREFIX*/ | UPPER_CASE_CHAR;
//	printf("%s\n", int_to_hex(0, flags));
//	printf("%s\n", int_to_hex(1234, flags));
//}
///* For compilation :
//gcc int_to_hex.c ../libft/ft_memcpy.c 
//../libft/ft_strlcpy.c ../libft/ft_strlen.c */
