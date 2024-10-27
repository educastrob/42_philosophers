/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:57:04 by educastro         #+#    #+#             */
/*   Updated: 2024/10/27 16:05:06 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	philo_init(t_data *data, int i)
{
	data->philos[i].n = i + 1;
	data->philos[i].t_last_eat = 0;
	data->philos[i].data = data;
	data->philos[i].eat_count = 0;
}

long int	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	msleep(int ms)
{
	long int	time;

	time = timestamp();
	while (timestamp() - time < ms)
		usleep(ms / 10);
}

void	print(t_philo *philo, char *str)
{
	long int	time;

	time = timestamp() - philo->data->t_start;
	sem_wait(philo->data->sem_print);
	printf("%ld %d %s", time, philo->n, str);
	sem_post(philo->data->sem_print);
}

void	*stop_handler(void *content)
{
	int		i;
	t_data	*data;

	i = 0;
	data = content;
	sem_wait(data->sem_stop);
	while (i < data->n_philo)
		kill(data->philos[i++].pid, SIGKILL);
	return (NULL);
}
