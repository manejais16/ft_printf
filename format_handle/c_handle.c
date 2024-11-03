/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_handle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzarins <kzarins@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:49:04 by kzarins           #+#    #+#             */
/*   Updated: 2024/11/03 04:10:56 by kzarins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_handle.h"

int	c_handle(char c, int field_width, int format_flags)
{
	int	field_size;

	field_size = 1;
	if (field_width > 1)
		field_size = field_width;
	if ((format_flags & (WITH_PADDING | RIGHT_PAD)) == WITH_PADDING)
		while (field_width > 1)
		{
			write(STD_OUT, " ", sizeof(char));
			field_width--;
		}
	write(STD_OUT, &c, sizeof(char));
	while (field_width > 1)
	{
		write(STD_OUT, " ", sizeof(char));
		field_width--;
	}
	return (field_size);
}
