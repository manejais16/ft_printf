/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_handle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzarins <kzarins@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:15:26 by kzarins           #+#    #+#             */
/*   Updated: 2024/11/03 18:27:17 by kzarins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_handle.h"

int	s_handle(char *str, int field_width, int format_flags)
{
	int	width_count;

	width_count = field_width;
	if (!str)
		return (-1);
	if ((format_flags & (WITH_PADDING | RIGHT_PAD)) == WITH_PADDING)
		while (width_count > ft_strlen(str))
		{
			write(STD_OUT, " ", 1);
			width_count--;
		}
	ft_putstr_fd(str, STD_OUT);
	while (width_count > ft_strlen(str))
	{
		write(STD_OUT, " ", 1);
		width_count--;
	}
	if (field_width > ft_strlen(str))
		return(field_width);
	return (ft_strlen(str));
}
