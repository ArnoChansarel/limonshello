/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:00:50 by achansar          #+#    #+#             */
/*   Updated: 2023/02/28 14:10:13 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H
#include "structs.h"


// EXECUTOR FUNCTIONS
int		executor(t_process *process, t_cmd **cmd_lst, int pipes, char **env);

// EXECUTOR UTILS
char	*get_cmd(t_process *process, char **cmd);
int		open_infile(t_process *process, t_cmd *ele);
int		open_outfile(t_process *process, t_cmd *ele);
// int		get_here_doc(t_process *process, char *eof);

#endif
