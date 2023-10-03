/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:35:33 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/02 16:09:52 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_usleep(size_t t)
{
	size_t	start;

	start = ft_get_t();
	while ((ft_get_t() - start) < t)
		usleep(500);
}

void	ft_finish(t_data *d)
{
	int	i;
	int	status;

	i = 0;
	while (i < d->n_f)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = 0;
			while (i < d->n_f)
				kill(d->pid[i++], SIGKILL);
			break ;
		}
		i++;
	}
}

int	ft_thread_init(t_data *d)
{
	pthread_t	whach;

	d->clock = d->time;
	sem_unlink("n_eat");
	sem_unlink("a_clock");
	d->n_eat = sem_open("n_eat", O_CREAT, 0600, 1);
	d->a_clock = sem_open("a_clock", O_CREAT, 0600, 1);
	if (pthread_create(&whach, NULL, &ft_whach, d) != 0)
		return (1);
	ft_live(d);
	if (pthread_join(whach, NULL) != 0)
		return (1);
	sem_close(d->n_eat);
	sem_close(d->a_clock);
	return (0);
}

int	ft_proces(t_data *d)
{
	int		i;

	sem_unlink("fork");
	sem_unlink("print");
	d->fork = sem_open("fork", O_CREAT, 0600, d->n_f);
	d->print = sem_open("print", O_CREAT, 0600, 1);
	i = 0;
	while (i < d->n_f)
	{
		d->pid[i] = fork();
		if (d->pid[i] == 0)
		{
			d->p_n = i;
			ft_thread_init(d);
		}
		i++;
	}
	sem_close(d->fork);
	sem_close(d->print);
	ft_finish(d);
	return (0);
}
