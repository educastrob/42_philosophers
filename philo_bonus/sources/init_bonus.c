/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:57:16 by educastro         #+#    #+#             */
/*   Updated: 2024/10/27 17:28:20 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static enum e_bool	check_args(char **argv);
static enum e_bool	init_semaphores(t_data *data);
static enum e_bool	init_args(t_data *data, char **argv);

enum e_bool	init_data(t_data *data, char **argv)
{
	if (!check_args(argv))
	{
		printf("Invalid Arguments\n");
		return (FALSE);
	}
	ft_memset(data, 0, sizeof(t_data));
	data->n_philo = ft_atoi(argv[1]);
	if (data->n_philo <= 0)
		return (FALSE);
	if (!init_semaphores(data))
		return (FALSE);
	data->philos = malloc(sizeof(t_philo) * data->n_philo);
	if (data->philos == NULL)
		return (FALSE);
	ft_memset(data->philos, 0, sizeof(t_philo) * data->n_philo);
	if (!init_args(data, argv))
	{
		printf("Invalid Arguments\n");
		return (FALSE);
	}
	return (TRUE);
}

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
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		if (argv[i][j] == '\0')
			return (FALSE);
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

static enum e_bool	init_semaphores(t_data *data)
{
	sem_unlink("print");
	sem_unlink("stop");
	sem_unlink("eat");
	sem_unlink("forks");
	data->sem_print = sem_open("print", O_CREAT, 0666, 1);
	data->sem_stop = sem_open("stop", O_CREAT, 0666, 1);
	data->sem_eat = sem_open("eat", O_CREAT, 0666, 1);
	data->sem_forks = sem_open("forks", O_CREAT, 0666, data->n_philo);
	if (data->sem_print == SEM_FAILED || data->sem_stop == SEM_FAILED
		|| data->sem_eat == SEM_FAILED || data->sem_forks == SEM_FAILED)
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