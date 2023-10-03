/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:39:51 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/02 16:28:44 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define W "\033[0m"
# define R "\033[91m"
# define G "\033[92m"

typedef struct s_data
{
	int				ok;
	int				n_f;
	long			t_d;
	long			t_e;
	long			t_s;
	int				nt_me;
	long			time;
	int				*eat_n;
	long			*t_left;
	pthread_t		*phi;
	pthread_mutex_t	get_t;
	pthread_mutex_t	print;
	pthread_mutex_t	ded;
	pthread_mutex_t	eat;
	pthread_mutex_t	*fork;
}				t_data;

typedef struct s_phi
{
	int				p_n;
	int				f1;
	int				f2;
	t_data			*d;
}				t_phi;

/*MAIN*/
int			main(int argc, char **argv);
int			ft_set_fork_phi_eat(t_data *d);
long int	ft_atoi(char *s);
long int	ft_get_t(void);

/*ERROR*/
int			ft_error_spe(int argc, char **argv);
int			ft_char_check(char *s);

/*THREAD*/
int			ft_thread(t_data *d);
void		ft_mutex_init(t_data *d);
void		ft_mutex_destroy(t_data *d);
void		*ft_born(void *arg);
void		ft_usleep(size_t t);

/*WHACH*/
void		ft_whach(t_phi *f);
void		ft_whach_t_d(t_phi *f);
void		ft_whach_nt_me(t_phi *f);

/*LIVING*/
void		ft_live(t_phi *f);
void		ft_eat(t_phi *f);
void		ft_eating(t_phi *f, int p_n);
void		ft_dead(t_phi *f, int p_n);
int			ft_check_ok(t_phi *f);

#endif