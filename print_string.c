/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:22:15 by ymassiou          #+#    #+#             */
/*   Updated: 2023/11/22 15:23:54 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", ft_strlen("(null)")));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
