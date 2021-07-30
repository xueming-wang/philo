/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 13:10:49 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/30 19:12:26 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
    printf("OK");
    return (SUCCESS);
}


int main(int ac,  char **av)
{
    t_philo *philo;
    
    if (ac > 6 || ac < 5)
        return (FAILURE);
    check_args(av);
    philo = ft_calloc (sizeof(t_philo), 1);
    if (!philo)
         __exit__("Error", philo, FAILURE);
    if (init_value(philo, av) == FAILURE)
         __exit__("Init Error", philo, FAILURE);
     
    
    // pthread_t a;

    // pthread_create(&a, NULL, t, NULL);
    
    // // pthread_join(a, NULL);
    // printf("quit\n");
    return (SUCCESS);
}