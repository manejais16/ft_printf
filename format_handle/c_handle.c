/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_handle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzarins <kzarins@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 04:08:09 by kzarins           #+#    #+#             */
/*   Updated: 2024/11/09 23:53:52 by kzarins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_handle.h"

int	c_handle(char c, int field_width, int format_flags)
{
	int	field_size_left;

	if (field_width < 1)
		field_width = 1;
	field_size_left = field_width;
	if (write_leading_padding(&field_size_left, 1, format_flags) == ERROR)
		return (ERROR);
	if (write(STD_OUT, &c, sizeof(char)) == ERROR)
		return (ERROR);
	if (write_trailing_padding(&field_size_left, 1, format_flags) == ERROR)
		return (ERROR);
	return (field_width);
}
