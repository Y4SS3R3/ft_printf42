/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:29:07 by ymassiou          #+#    #+#             */
/*   Updated: 2023/11/22 13:14:05 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned(unsigned int num)
{
	size_t	count;

	count = 0;
	if (num >= 0 && num <= 9)
		count += print_char(num + 48);
	else
	{
		count += print_unsigned(num / 10);
		count += print_char(num % 10 + 48);
	}
	return (count);
}
