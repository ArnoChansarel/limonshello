/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:02:58 by achansar          #+#    #+#             */
/*   Updated: 2023/05/11 13:06:22 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_head(void)
{
	printf("\n=============================================================="
		"==========================================================\n");
	printf(" __         __     __    __     ______     __   __     ______    "
		" __  __     ______     __         __         ______    \n");
	printf("/\\ \\       /\\ \\   /\\ \"-./  \\   /\\  __ \\   /\\ \"-.\\ \\"
		"   /\\  ___\\   /\\ \\_\\ \\   /\\  ___\\   /\\ \\       /\\ \\       /\\"
		"  __ \\   \n");
	printf("\\ \\ \\____  \\ \\ \\  \\ \\ \\-./\\ \\  \\ \\ \\/\\ \\  \\ \\ "
		"\\-.  \\  \\ \\___  \\  \\ \\  __ \\  \\ \\  __\\   \\ \\ \\____  \\ \\ "
		"\\____  \\ \\ \\/\\ \\  \n");
	printf(" \\ \\_____\\  \\ \\_\\  \\ \\_\\ \\ \\_\\  \\ \\_____\\  \\ \\_"
		"\\\\\"\\_\\  \\/\\_____\\  \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_____\\  \\"
		" \\_____\\  \\ \\_____\\ \n");
	printf("  \\/_____/   \\/_/   \\/_/  \\/_/   \\/_____/   \\/_/ \\/_/   \\/_"
		"____/   \\/_/\\/_/   \\/_____/   \\/_____/   \\/_____/   \\/_____/\n");
	printf("                                                                 "
		"                                                    \n");
	printf("==================================================================="
		"=====================================================\n\n");
}

void	print_error(char **res)
{
	printf("LimonShello: export: '%s': not a valid identifier\n",
		res[0]);
	g_exit_value = 1;
	ft_free_array(res);
}

int	open_error(char *name, int flag)
{
	char	*str;

	str = ft_strjoin("Limonshello: ", name);
	if (flag)
	{
		ft_exit_failure(str);
		return (0);
	}
	else
	{
		perror(str);
		free(str);
		g_exit_value = 1;
		return (1);
	}
}

int	ft_exit_failure(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	err_(char *str)
{
	ft_putstr_fd("exit\n", 1);
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
}
