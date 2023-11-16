/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 01:43:28 by romannbroque      #+#    #+#             */
/*   Updated: 2023/11/16 02:10:25 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICROSHELL_H
# define MICROSHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

typedef enum e_type
{
	E_CMD,
	E_PIPE,
	E_SEMICOLON
}		t_type;

typedef struct s_command
{
	char 	*cmd;
	char 	**arg;
	char 	**env;
	t_type	type;	
}		t_command;

#endif
