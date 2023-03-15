/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:00:50 by achansar          #+#    #+#             */
/*   Updated: 2023/03/15 11:11:02 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H
#include "structs.h"


// EXECUTOR FUNCTIONS
int		executor(t_process *process, t_cmd **cmd_lst, int pipes, char **env);
int     execute_process(t_cmd *ele, t_process *process, char **env);
int     first_process(t_process *process, int pi);
int     next_process(t_process *process, int pi);
int     last_process(t_process *process, int pi);

// EXECUTOR UTILS
char	*get_cmd(t_process *process, char **cmd);
int		open_infile(t_process *process, t_cmd *ele);
int		open_outfile(t_process *process, t_cmd *ele);
int	    create_pipes(t_process *process, int pipes);
int	    close_pipes(int *array);
int	    create_here_doc(t_process *process, t_cmd **cmd_lst);

#endif
