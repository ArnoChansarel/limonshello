/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:02:58 by achansar          #+#    #+#             */
/*   Updated: 2023/04/11 15:39:09 by ade-bast         ###   ########.fr       */
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
