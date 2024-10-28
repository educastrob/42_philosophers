/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:57:22 by educastro         #+#    #+#             */
/*   Updated: 2024/10/28 15:44:35 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_data	t_data;
typedef struct s_philo	t_philo;

enum e_bool
{
	FALSE,
	TRUE
};

typedef struct s_data
{
	int					n_philo_eat;
	int					n_philo;
	int					n_eat;
	long int			t_die;
	long int			t_eat;
	long int			t_sleep;
	long int			t_start;
	t_philo				*philos;
	sem_t				*sem_print;
	sem_t				*sem_stop;
	sem_t				*sem_eat;
	sem_t				*sem_forks;
}						t_data;

typedef struct s_philo
{
	int					n;
	int					eat_count;
	long int			t_last_eat;
	t_data				*data;
	pid_t				pid;
}						t_philo;

// Exit
void					free_all(t_data *data);

// Init
enum e_bool				init_data(t_data *data, char **argv);

// Philosophers
void					philo_handler(t_data *data);

// Utils
void					philo_init(t_data *data, int i);
long int				timestamp(void);
void					msleep(int ms);
void					print(t_philo *philo, char *str);
void					*stop_handler(void *content);

// Lib
long int				ft_atoi(const char *str);
enum e_bool				ft_isdigit(int c);
enum e_bool				ft_isspace(int c);
void					*ft_memset(void *s, int c, size_t n);

#endif