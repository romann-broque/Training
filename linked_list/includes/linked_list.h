/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:40:52 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/07 10:24:42 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>

#define	MIN_SIZE 1
#define	SEPARATOR " - "

typedef	struct node_struct
{
	int		data;
	struct	node_struct *link;
}node;

//struct.c//

node	*create_node(int data);
void	destroy_node(node **prev);
void	destroy_list(node **prev);

//push.c//

void	add(node *prev, int input_data);
void	insert(node **prev, int	input_data, size_t rank);
void	push(node **prev, int input_data);

//pop.c//

void	pop(node **prev);
void	cut(node **prev);
void	delete_data(node **prev, int input_data);

//get_info.c//

size_t	get_size(node **prev);

//display.c//

void	display_list(node *prev);

//reverse.c//

void	reverse_list(node **prev);
