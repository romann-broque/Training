/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:53:09 by romannbroque      #+#    #+#             */
/*   Updated: 2022/03/06 09:30:58 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
node	*destroy_node(node **prev);

//push.c//

void	add(node *prev, int input_data);
void	insert(node **prev, int	input_data, size_t rank);
void	push(node **prev, int input_data);

//pop.c//

node	*pop(node **prev);
node	*cut(node **prev);
void	delete_data(node **prev, int input_data);

//get_info.c//

size_t	get_size(node **prev);

//display.c//

void	display_list(node *prev);

//reverse.c//

void	reverse(node **prev);
