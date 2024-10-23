/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:40:09 by edcastro          #+#    #+#             */
/*   Updated: 2024/10/22 20:40:10 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long int	ft_atoi(const char *str)
{
	size_t		i;
	long int	ret;
	int			sig;

	i = 0;
	sig = 1;
	ret = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sig = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		ret = ret * 10 + (sig * (str[i] - '0'));
		i++;
	}
	return (ret);
}
