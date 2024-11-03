/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_handle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzarins <kzarins@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:18:24 by kzarins           #+#    #+#             */
/*   Updated: 2024/11/03 04:16:13 by kzarins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "format_handle.h"

int	d_handle(int num, int field_width, int format_flags)
{
	char	*int_in_char;
	int		len;

	int_in_char = ft_itoa(num);
	if (!int_in_char)
		return (-1);
	len = ft_strlen(int_in_char);
	write(STD_OUT, int_in_char, len);
	free(int_in_char);
	return (len);
}
