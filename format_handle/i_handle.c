/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_handle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzarins <kzarins@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:35:11 by kzarins           #+#    #+#             */
/*   Updated: 2024/10/29 21:30:28 by kzarins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "format_handle.h"

int	i_handle(int num)
{
	char	*int_in_char;
	int		len;

	int_in_char = ft_itoa(num);
	if (!int_in_char)
		return ;
	len = ft_strlen(int_in_char)
	write(STD_OUT, int_in_char, len);
	free(int_in_char);
	return (len);
}
