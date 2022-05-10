/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syracuse_machine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 09:04:11 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/10 13:47:47 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#define NO_NUMBER 0x00
#define ONE 0x01
#define TWO 0x02
#define FOUR 0x04
#define END 0x07

enum e_state
{
	E_ODD,
	E_EVEN,
	E_END
};

typedef unsigned long	t_history;

typedef struct s_machine
{
	enum e_state	state;
	unsigned int	nb;
	t_history		last_numbers;
}					t_machine;

typedef void	(*t_state_fct)(t_machine *const machine);

/*
static bool	is_last_numb(const unsigned int nb)
{
	return (nb == 1 || nb == 2 || nb == 4);
}
*/

static void	odd(t_machine *const machine)
{
	machine->nb = 3 * machine->nb + 1;
	machine->state = (machine->nb % 2 == 0);
	if (machine->nb == 4 || (machine->nb < 4 && machine->last_numbers & (1 << machine->nb)))
		machine->last_numbers |= machine->nb;
	else
		machine->last_numbers = NO_NUMBER;
	printf("%u\n", machine->nb);
}

static void	even(t_machine *const machine)
{
	machine->nb /= 2;
	machine->state = (machine->nb % 2 == 0);
	if (machine->nb == 4 || (machine->nb < 4 && machine->last_numbers & (1 << machine->nb)))
		machine->last_numbers |= machine->nb;
	else
		machine->last_numbers = NO_NUMBER;
	printf("%u\n", machine->nb);
}

void	syracuse(const unsigned int nb)
{
	static t_state_fct		state_function[2] = {odd, even};
	t_machine				machine;

	if (nb > 0)
	{
		printf("%u\n", nb);
		machine.nb = nb;
		machine.state = (nb % 2 == 0);
		machine.last_numbers = 0x00;
		while (machine.state != E_END)
		{
			state_function[machine.state](&machine);
			if ((machine.last_numbers & END) == END)
				machine.state = E_END;
		}
	}
}

int	main(int ac, char **av)
{
	if (ac > 1)
		syracuse(atoi(av[1]));
	return (EXIT_SUCCESS);
}
