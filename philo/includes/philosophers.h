/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:02:59 by educastro         #+#    #+#             */
/*   Updated: 2024/10/28 15:43:24 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
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
	enum e_bool			stop;
	t_philo				*philos;
	pthread_mutex_t		m_print;
	pthread_mutex_t		m_dead;
}						t_data;

typedef struct s_philo
{
	int					n;
	int					eat_count;
	long int			t_last_eat;
	t_data				*data;
	pthread_t			thread;
	pthread_mutex_t		m_eat;
	pthread_mutex_t		*fork_r;
	pthread_mutex_t		fork_l;
}						t_philo;

// Exit
void				free_all(t_data *data);

// Philosophers
enum e_bool			philo_handler(t_data *data);

// Init
enum e_bool			init_data(t_data *data, char **argv);

// Utils
void				msleep(int ms);
enum e_bool			is_dead(t_philo *philo, enum e_bool set_dead);
long int			timestamp(void);
void				print(t_philo *philo, char *str);
enum e_bool			philo_init(t_data *data, int i);

// Lib
long int			ft_atoi(const char *str);
enum e_bool			ft_isdigit(int c);
enum e_bool			ft_isspace(int c);
void				*ft_memset(void *s, int c, size_t n);

#endif
