/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wach.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:12:05 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/02 13:50:22 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_whach_nt_me(t_phi *f)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (i < f->d->n_f)
	{
		pthread_mutex_lock(&f->d->eat);
		if (f->d->eat_n[i++] >= f->d->nt_me)
			c++;
		pthread_mutex_unlock(&f->d->eat);
	}
	if (c == f->d->n_f)
	{
		pthread_mutex_lock(&f->d->ded);
		f->d->ok = 0;
		pthread_mutex_unlock(&f->d->ded);
	}
}

void	ft_whach_t_d(t_phi *f)
{
	int	i;

	i = 0;
	while (ft_check_ok(f) && i < f->d->n_f)
	{
		pthread_mutex_lock(&f->d->get_t);
		if ((ft_get_t() - f->d->t_left[i]) >= f->d->t_d)
			ft_dead(f, i);
		pthread_mutex_unlock(&f->d->get_t);
		i++;
	}
}

void	ft_whach(t_phi *f)
{
	while (ft_check_ok(f))
	{
		usleep(100);
		if (f->d->nt_me != -1)
			ft_whach_nt_me(f);
		ft_whach_t_d(f);
	}
}
