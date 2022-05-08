/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   after_sort_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:24:39 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/08 16:05:23 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#define DELIM " -> "

static void	display_list(t_list *list)
{
	if (list != NULL)
	{
		printf("%d", list->nb);
		printf("%s", DELIM);
		display_list(list->next);
	}
}

static t_list	*create_list(int nb, t_list *link)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new != NULL)
	{
		new->nb = nb;
		new->next = link;
	}
	return (new);
}

static void	add_list(t_list *list, int nb)
{
	if (list->next != NULL)
		add_list(list->next, nb);
	else
		list->next = create_list(nb, NULL);
}

////////////////////////////////////////////////////////////////////////////////

static int	is_list_sort(t_list *list, int (*cmp)(int, int))
{
	if (list != NULL)
	{
		if (list->next != NULL)
		{
			if (cmp(list->nb, list->next->nb) == 1)
				return (is_list_sort(list->next, cmp));
			return (0);
		}
	}
	return (1);
}

static void	reverse(t_list *node1, t_list *node2)
{
	int	temp;

	temp = node1->nb;
	node1->nb = node2->nb;
	node2->nb = temp;
}

static void	mini_sort(t_list *lst, int (*cmp)(int, int))
{
	if (lst != NULL && lst->next != NULL)
	{
		if (cmp(lst->nb, lst->next->nb) == 0)
			reverse(lst, lst->next);
		mini_sort(lst->next, cmp);
	}
}


static t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	while (is_list_sort(lst, cmp) == 0) // boolean
		mini_sort(lst, cmp);
	return (lst);
}

/*
static void	sort_list(t_list *head, int (*cmp)(int, int))
{
	t_list	*lst = head;

	while (lst != NULL)
	{
		if (cmp(lst->nb, lst->next->nb) == 0)
		{
			reverse(lst, lst->next);
			lst = head;
		}
		else
			lst = lst->next;
	
	}
}
*/

static int	ascending(int a, int b)
{
	return (a <= b);
}

int	main(int ac, char **av)
{
	t_list	*list;
	size_t	i;

	list = NULL;
	if (ac > 1)
	{
		i = 1;
		list = create_list(atoi(av[1]), NULL);
		++i;
		while (av[i] != NULL)
		{
			add_list(list, atoi(av[i]));
			++i;
		}
	}
	display_list(list);
	printf("\n");
	list = sort_list(list, ascending);
	display_list(list);
	printf("\n");
	return (EXIT_SUCCESS);
}
