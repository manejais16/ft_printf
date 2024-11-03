/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_handle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzarins <kzarins@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:15:26 by kzarins           #+#    #+#             */
/*   Updated: 2024/11/03 04:16:43 by kzarins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_handle.h"

int	s_handle(char *str, int field_width, int format_flags)
{
	if (!str)
		return (-1);
	ft_putstr_fd(str, STD_OUT);
	return (ft_strlen(str));
}
