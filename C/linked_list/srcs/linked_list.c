/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:41:33 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/07 09:58:05 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H

#	include "linked_list.h"

#endif

node	*linked_list(int node_number, char **data)
{
	node	*root;
	int		i;

	root = NULL;
	if (node_number > 1)
	{
		i = 1;
		root = create_node(atoi(data[i]));
		++i;
		while (i < node_number)
		{
			add(root, atoi(data[i]));
			++i;
		}
	}
	return (root);
}

int	main(int ac, char **av)
{
	node	*root;

	printf("Normal Display\n");
	root = linked_list(ac, av);
	display_list(root);

	printf("Cut\n");
	cut(&root);
	display_list(root);

	printf("Add\n");
	add(root, atoi(av[ac - 1]));
	display_list(root);

	printf("Delete_data\n");
	delete_data(&root, 3);
	display_list(root);

	printf("Pop\n");
	pop(&root);
	display_list(root);
	
	printf("Insert\n");
	insert(&root, 4, 5);
	display_list(root);
	
	printf("Push\n");
	push(&root, 42);
	display_list(root);

	printf("REVERSE !\n");
	reverse_list(&root);
	display_list(root);
	
	return (EXIT_SUCCESS);
}
