/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:24:39 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/04 16:43:33 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#define DELIM " -> "

void	display_list(t_list *list)
{
	if (list != NULL)
	{
		printf("%d", list->nb);
		printf("%s", DELIM);
		display_list(list->next);
	}
}

void	reverse(t_list *node1, t_list *node2)
{
	int	temp;

	temp = node1->nb;
	node1->nb = node2->nb;
	node2->nb = temp;
}

int		is_list_sort(t_list *list, int (*cmp)(int, int))
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

void	mini_sort(t_list *lst, int (*cmp)(int, int))
{
	if (lst != NULL && lst->next != NULL)
	{
		if (cmp(lst->nb, lst->next->nb) == 0)
			reverse(lst, lst->next);
	}
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	while (is_list_sort(lst, cmp) == 0)
	{
		mini_sort(lst, cmp);
		display_list(lst);
	}
	return (lst);
}

int	ascending(int a, int b)
{
	return (a <= b);
}

t_list	*create_list(int nb, t_list *link)
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

void	add_list(t_list *list, int nb)
{
	if (list->next != NULL)
		add_list(list->next, nb);
	else
		list->next = create_list(nb, NULL);
}

int	main(void)
{
	t_list	*list;

	list = create_list(1, NULL);
	add_list(list, 2);
	add_list(list, 7);
	add_list(list, 5);
	add_list(list, 1);
	display_list(list);
	printf("\n");
	list = sort_list(list, ascending);
	display_list(list);
	printf("\n");
	printf("%d\n", is_list_sort(list, ascending));
	return (EXIT_SUCCESS);
}
