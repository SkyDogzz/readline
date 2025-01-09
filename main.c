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

int	main(void)
{
	char	*line;

	set_signal_action();
	while (1)
	{
		line = readline("Retreive line: ");
		if (!line)
			break;
		else if (strcmp(line, "exit") == 0)
		{
			free(line);
			break;
		}
		if (strcmp(line, "") != 0)
			add_history(line);
		free(line);
	}
	rl_clear_history();
	printf("exit\n");
	return (EXIT_SUCCESS);
}
