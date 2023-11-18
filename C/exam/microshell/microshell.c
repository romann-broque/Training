/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 01:42:18 by romannbroque      #+#    #+#             */
/*   Updated: 2023/11/18 09:15:40 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

static size_t	ft_strlen(const char *const str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}

static void	error(const char *const str)
{
	write(STDERR_FILENO, str, ft_strlen(str));
}

static bool	is_pipe(const char *const str)
{
	return (str[0] == '|' && str[1] == '\0');
}

static bool	is_semicolon(const char *const str)
{
	return (str[0] == ';' && str[1] == '\0');
}

static int	execute_cmd(
	char **const cmd,
	char *const *const env,
	const int i
	)
{
	bool has_pipe = cmd[i] != NULL && is_pipe(cmd[i]);
	int	fd[2];
	int	pid;
	int	status;

	if (has_pipe && pipe(fd) == -1)
	{
		error("error pipe\n");
		return (EXIT_FAILURE);
	}
	pid = fork();
	if (pid != 0)
	{
		cmd[i] = NULL;
		if (has_pipe && (dup2(fd[1], STDOUT_FILENO) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
			error("dup or close error!\n");
		else
		{
			execve(*cmd, cmd, env);
			error("error!\n");
		}
		return (EXIT_FAILURE);
	}
	waitpid(pid, &status, 0);
	if (has_pipe && (dup2(fd[0], STDIN_FILENO) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		error("dup or close error!\n");
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

int	main(int ac, char **av, char **env)
{
/*
	int	i;
	int	status;

	if (ac == 1)
		return (EXIT_SUCCESS);
	--ac;
	++av;
	i = 0;
	while (av[i] != NULL && av[i + 1]  != NULL)
	{
		av += i;
		i = 0;
		while (av[i] != NULL
			&& is_pipe(av[i]) == false && is_semicolon(av[i]) == false)
		{
			++i;
		}
		if (i > 0)
			status = execute_cmd(av, env, i);
	}
	return (status);
*/
	int    i = 0;
    int    status = 0;

    if (ac > 1) 
    {
        while (av[i] && av[++i]) 
        {
            av += i;
            i = 0;
            while (av[i] && is_pipe(av[i]) == false && is_semicolon(av[i]) == false)
                i++;
            if (i > 0)
                status = execute_cmd(av, env, i);
        }
    }
    return status;
}
