/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_handle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzarins <kzarins@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:10:05 by kzarins           #+#    #+#             */
/*   Updated: 2024/11/12 23:11:00 by kzarins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_handle.h"

int	x_handle(unsigned int num, struct s_field_specifiers field, \
		int format_flags)
{
	char	*result;
	int		len;

	result = int_to_hex(num, format_flags);
	if (!result)
		return (-1);
	len = ft_strlen(result);
	if (write(STD_OUT, result, len) == ERROR)
	{
		free(result);
		return (ERROR);
	}
	free(result);
	return (len);
}
