/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_handle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzarins <kzarins@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:15:26 by kzarins           #+#    #+#             */
/*   Updated: 2024/10/29 21:20:19 by kzarins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_handle.h"

int	s_handle(char *str)
{
	ft_putstr_fd(str, STD_OUT);
	return (ft_strlen(str));
}
