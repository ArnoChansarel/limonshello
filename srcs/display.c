/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:02:58 by achansar          #+#    #+#             */
/*   Updated: 2023/03/29 18:20:15 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    ft_printlist(t_lexlst *head_a)
{
	t_lexlst *current_a;

	current_a = head_a;
	printf("+-------+\n");
	printf("| LEXER |\n");
	printf("+-------+\n");
	while (current_a)
	{
		if (current_a)
		{
			printf("%s", current_a->word);
			current_a = current_a->next;
		}
		printf("\n");
	}
	printf("+-------+\n\n");
}

void    ft_printparse(t_cmd *head)
{
	int j;
	int i = 0;
	t_cmd *current;

	current = head;
	printf("+------------------------+\n");
	printf("|          PARSER        |\n");
	printf("+------------------------+\n");
    while (current)
	{
		if (current)
		{
			j = 0;
			printf("         ELEMENT %d :\n##########################\nCommand     : ", i++);
			while (current->cmd[j])
				printf("%s ", current->cmd[j++]);
			if (current->builtin)
				printf("\nBuiltin       : %s\n", current->cmd[0]);
			else
				printf("\nBuiltin       : No\n");
			if (current->rd_in)
				printf("Redirection IN  : %s\n", current->rd_in);
			else
				printf("Redirection IN : No\n");
			if (current->rd_out)
				printf("Redirection OUT : %s\n##########################\n\n", current->rd_out);
			else
				printf("Redirection OUT : No\n##########################\n\n");
			current = current->next;
		}
	}
	printf("+------------------------+\n\n");
}

void	print_head(void)
{
	printf("=========================================================================================\n");
	printf(" __                                       ____    __              ___    ___             \n");
	printf("/\\ \\       __                            /\\  _`\\ /\\ \\            /\\_ \\  /\\_ \\            \n");
	printf("\\ \\ \\     /\\_\\    ___ ___     ___     ___\\ \\,\\L\\_\\ \\ \\___      __\\//\\ \\ \\//\\ \\     ___   \n");
	printf(" \\ \\ \\  __\\/\\ \\ /' __` __`\\  / __`\\ /' _ `\\/_\\__ \\ \\  _ `\\  /'__`\\ \\ \\  \\ \\ \\   / __`\\ \n");
	printf("  \\ \\ \\L\\ \\ \\ \\/\\ \\/\\ \\/\\ \\/\\ \\L\\ \\/\\ \\/\\ \\/\\ \\L\\ \\ \\ \\ \\ \\/\\  __/ \\_\\ \\_ \\_\\ \\_/\\ \\L\\ \\ \n");
	printf("   \\ \\____/ \\ \\_\\ \\_\\ \\_\\ \\_\\ \\____/\\ \\_\\ \\_\\ `\\____\\ \\_\\ \\_\\ \\____\\/\\____\\/\\____\\ \\____/\n");
	printf("    \\/___/   \\/_/\\/_/\\/_/\\/_/\\/___/  \\/_/\\/_/\\/_____/\\/_/\\/_/\\/____/\\/____/\\/____/\\/___/ \n\n");
	printf("=========================================================================================\n");
}
