/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 13:10:49 by xuwang            #+#    #+#             */
/*   Updated: 2021/08/01 19:46:09 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int creat_pthread(t_philo *philo)
{
    int i ;
    
    i = 0;
    while (i < philo->nbr_philo)
    {
        if (pthread_mutex_init(&philo->fork[i++], NULL) != 0)
            return(FAILURE);
    }
    i = 0;
    while (i < philo->nbr_philo)   //线程的函数
    {
        if (pthread_create(&philo->each_philo->philo, NULL, philo, (void*)i) != 0)
            return (FAILURE);
        i++;
    }
    return (SUCCESS);
}

static int run_pthread(t_philo *philo)
{
    int i;

    if (creat_pthread(philo) != SUCCESS)
        return(FAILURE);
    i = 0;
    while(i < philo->nbr_philo)
    {
        if (pthread_join(philo->each_philo->philo, NULL) != 0)
            return (FAILURE);
    }
    i = 0;
    while(i < philo->nbr_philo)
        pthread_mutex_destroy(&philo->fork[i++]);
    return (SUCCESS); 
}

static int  check_args(char **av)
{
    int i;
    int j;
    
    i = 1;
    while (av[i])
    {
        j = 0;
        while (av[i][j])
        {
            if (ft_atoi(av[i]) > INT32_MAX)
                return (FAILURE);
            if (av[i][0] == '-')
                return (FAILURE);
            if (av[i][0] == '0' && av[i][1] == '\0')
                return (FAILURE);
            if (!(av[i][j] >= '0' && av[i][j] <= '9'))
                return (FAILURE);
            j++;
        }
        i++;
    }
    return (SUCCESS);
}


int main(int ac,  char **av)
{
    t_philo *philo;
    
    if (ac > 6 || ac < 5)
        __exit__(NULL, philo, FAILURE);
    check_args(av);
    philo = ft_calloc (sizeof(t_philo), 1);
    if (!philo)
         __exit__("Error", philo, FAILURE);
    if (init_value(philo, av) == FAILURE)
         __exit__("Init Error", philo, FAILURE);
    philo->start_time = get_time();
    if (philo->start_time == -1)
        __exit__("Time error", philo, FAILURE);
    if (run_pthread(philo) == FAILURE)
        __exit__(NULL, philo, FAILURE);
    __exit__(NULL, philo, SUCCESS);          
}