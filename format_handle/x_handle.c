/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_handle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzarins <kzarins@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:26:13 by kzarins           #+#    #+#             */
/*   Updated: 2024/10/29 21:34:11 by kzarins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "format_handle.h"

int	x_handle(unsigned int num, e_hex_convert_flags flags)
{
	char	*result;
	int		len;

	result = int_to_hex(num, flags);
	if (!result)
		return ;
	len = ft_strlen(result);
	write(STD_OUT, result, len);
	free(result);
	return (len);
}

