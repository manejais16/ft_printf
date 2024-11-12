/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzarins <kzarins@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:17:31 by kzarins           #+#    #+#             */
/*   Updated: 2024/11/11 22:31:57 by kzarins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "format_handle.h"

int	putstr_fd(char *str, int fd)
{
	while (*str)
	{
		if (write(STD_OUT, str, 1) == ERROR)
			return (ERROR);
		str++;
	}
	return (SUCCESS);
}
