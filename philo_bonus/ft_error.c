/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:50:33 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/02 15:47:41 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_char_check(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ' && (s[i] < '0' || s[i] > '9'))
			return (printf("Error, invalid argument\n"), 1);
		i++;
	}
	i = 0;
	while (s[i] != '\0' && s[i] == ' ')
		i++;
	while (s[i] != '\0' && s[i] >= '0' && s[i] <= '9')
		i++;
	while (s[i] != '\0')
	{
		if (s[i++] != ' ')
			return (printf("Error, invalid argument\n"), 1);
	}
	return (0);
}

int	ft_error_spe(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_char_check(argv[i++]))
			return (1);
	}
	if (argc == 6 && ft_atoi(argv[5]) == 0)
		return (1);
	if (ft_atoi(argv[1]) == 1)
	{
		printf("0 1 has taken a fork\n");
		ft_usleep(ft_atoi(argv[2]));
		printf(R"%ld 1 died\n"W, ft_atoi(argv[2]));
		return (1);
	}
	if (ft_atoi(argv[1]) < 1)
		return (1);
	return (0);
}
