/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostal- <acostal-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:51:55 by acostal-          #+#    #+#             */
/*   Updated: 2021/11/10 17:51:57 by acostal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	fill_struct(int argc, char **argv, t_table *table)
{
	(*table).t_philo = ft_atoi(argv[1]);
	(*table).t_to_die = ft_atoi(argv[2]);
	(*table).t_to_eat = ft_atoi(argv[3]);
	(*table).t_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		(*table).t_food = ft_atoi(argv[5]);
	(*table).philo = malloc(sizeof(t_philo) * (*table).t_philo);
	if ((*table).philo == NULL)
	{
		table = NULL;
		return (1);
	}
	(*table).time = get_time();
	(*table).philo->table = table;
	return (0);
}

int	validate_args(t_table *table, int argc)
{
	if (table->t_philo > 200)
		return (1);
	if (table->t_to_die <= 0 || table->t_to_die > 2147483647)
		return (1);
	if (table->t_to_eat <= 0 || table->t_to_eat > 2147483647)
		return (1);
	if (table->t_to_sleep <= 0 || table->t_to_eat > 2147483647)
		return (1);
	if (argc == 6 && (table->t_food <= 0 || table->t_food > 2147483647))
		return (1);
	return (0);
}

int	ft_isspace(int c)
{
	if ((char)c == '\t' || (char)c == '\n' || (char)c == '\v'
		|| (char)c == '\f' || (char)c == '\r' || (char)c == ' ')
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

long	ft_atoi(const char *str)
{
	long				i;
	long				sign;
	unsigned long		res;

	res = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(str[i]) != 0)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) != 0)
	{
		if (ft_isdigit(str[i] != 0))
			return (-1);
		res = res * 10 + (str[i++] - '0');
	}
	return (res * sign);
}
