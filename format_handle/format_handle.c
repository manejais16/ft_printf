/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzarins <kzarins@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:08:02 by kzarins           #+#    #+#             */
/*   Updated: 2024/11/03 22:12:22 by kzarins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "format_handle.h"

static int	collect_format_flags(char **str);
static int	handle_format_leters(char *str, va_list args, \
		struct s_field_specifiers field, int form_flags);
static int	get_field_width(char **str, int *form_flags);
static int	get_precision(char **str, int *format_flags);

int	format_handle(char **str, va_list args)
{
	int							len;
	int							format_flags;
	struct s_field_specifiers	field;

	*str = *str + 1;
	len = 0;
	format_flags = collect_format_flags(str);
	field.field_width = get_field_width(str, &format_flags);
	field.precision = get_precision(str, &format_flags);
	if (**str == '%')
	{
		len = c_handle('%', field.field_width, format_flags);
		return (len);
	}
	len = handle_format_leters(*str, args, field, format_flags);
	return (len);
}

static int	handle_format_leters(char *str, va_list args, \
		struct s_field_specifiers field, int form_flags)
{
	if (*str == 'c')
		return (c_handle(va_arg(args, int), field.field_width, form_flags));
	else if (*str == 's')
		return (s_handle(va_arg(args, char *), field.field_width, form_flags));
	else if (*str == 'p')
		return (p_handle(va_arg(args, void *), field.field_width, form_flags));
	else if (*str == 'd')
		return (d_handle(va_arg(args, int), field, form_flags));
	else if (*str == 'i')
		return (i_handle(va_arg(args, int), field, form_flags));
	else if (*str == 'u')
		return (u_handle(va_arg(args, unsigned int), field, form_flags));
	else if (*str == 'x')
		return (x_handle(va_arg(args, unsigned int), field, form_flags));
	else if (*str == 'X')
	{
		form_flags |= UPPER_CASE_CHAR;
		return (x_handle(va_arg(args, unsigned int), field, form_flags));
	}
	else
		return (-1);
}

static int	collect_format_flags(char **str)
{
	int	flag;

	flag = 0;
	while (**str == '#' || **str == ' ' || **str == '+' || \
			**str == '0' || **str == '-')
	{
		if (**str == '#')
			flag |= NUMBER_SIGN;
		if (**str == ' ')
			flag |= SPACE;
		if (**str == '+')
			flag |= PLUS_SING;
		if (**str == '0')
			flag |= ZEROS;
		if (**str == '-')
			flag |= RIGHT_PAD;
		*str = *str + 1;
	}
	return (flag);
}

static int	get_field_width(char **str, int *form_flags)
{
	int	width_requirement;

	width_requirement = 0;
	if (ft_isdigit(**str))
	{
		*form_flags |= WITH_PADDING;
		width_requirement = ft_atoi(*str);
	}
	while (ft_isdigit(**str))
		*str = *str + 1;
	return (width_requirement);
}

static int	get_precision(char **str, int *format_flags)
{
	int	precision;

	precision = 1;
	if (**str == '.')
	{
		*format_flags |= WITH_PRECISION;
		*str = *str + 1;
	}
	if (ft_isdigit(**str))
		precision = ft_atoi(*str);
	while (ft_isdigit(**str))
		*str = *str + 1;
	return (precision);
}
