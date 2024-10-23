/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 13:43:59 by educastro         #+#    #+#             */
/*   Updated: 2024/10/22 21:10:23 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


static enum e_bool	check_args(char **argv)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (ft_isspace(argv[i][j]))
			j++;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		if (argv[i][j] == '\0')
			return (FALSE);
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
				return (FALSE);
			j++;
		}
	}
	return (TRUE);
}

static enum e_bool	init_mutex(t_data *data)
{
	if (pthread_mutex_init(data->m_print, NULL) != 0 \
		|| pthread_mutex_init(data->m_dead, NULL) != 0)
		return (FALSE);
	return (TRUE);
}

static enum e_bool	init_args(t_data *data, char **argv)
{
	data->n_philo_eat = 0;
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	if (data->t_die <= 0 || data->t_eat <= 0 || data->t_sleep <= 0)
		return (FALSE);
	if (argv[5] != NULL)
	{
		data->n_eat = ft_atoi(argv[5]);
		if (data->n_eat <= 0)
			return (FALSE);
	}
	return (TRUE);
}

enum e_bool	init_data(t_data *data, char **argv)
{
	if (!check_args(argv))
	{
		printf("Error: Invalid arguments\n");
		return (FALSE);
	}
	memset(data, 0, sizeof(t_data));
	if (!init_mutex(data))
		return (FALSE);
	data->n_philo = ft_atoi(argv[1]);
	if (data->n_philo <= 0)
		return (FALSE);
	data->philos = malloc(data->n_philo * sizeof(t_philo));
	if (data->philos == NULL)
		return (FALSE);
	memset(data->philos, 0, data->n_philo * sizeof(t_philo));
	if (!init_args(data, argv))
	{
		printf("Error: Invalid arguments\n");
		return (FALSE);
	}
	return (TRUE);
}
