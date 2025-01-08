/* ************************************************************************** */
/*                                                                            */
/*                                             	_____                         */
/*   main.c                                    |  __ \  ___   __ _ ________   */
/*                                             | |  | |/ _ \ / _` |_  |_  /   */
/*   By: tstephan <thomas.stephan@live.fr>     | |__| | (_) | (_| |/ / / /    */
/*                                             |_____/ \___/ \__, /___/___|   */
/*   Created: 2025/01/08 18:57:50 by tstephan                 __/ |           */
/*   Updated: 2025/01/08 19:08:25 by tstephan                |___/            */
/*                                                                            */
/* ************************************************************************** */

#include "inc.h"

/*
* Oui
*/
static void	ft_signal_handler(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	set_signal_action(void)
{
	signal(SIGINT, ft_signal_handler);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

int	main(int argc, char *argv[])
{
	char	*line;
	int		count;

	count = 1;
	set_signal_action();
	line = readline("Retreive line: ");
	add_history(line);
	while (1)
	{
		if (*line == EOF)
		{
			printf("EOF here\n");
		}
		if (strcmp(line, "exit") == 0)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		free(line);
		line = readline("Retreive line: ");
		add_history(line);
	}
	free(line);
	rl_clear_history();
	return (EXIT_SUCCESS);
	(void) argc;
	(void) argv;
}
