/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:41:53 by achansar          #+#    #+#             */
/*   Updated: 2023/04/11 15:55:59 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H
# include "structs.h"

// EXPANDER FUNCTIONS
int			expander(char **cmd, t_env **env);
int			expand_redirections(char **rd, t_env **env);
int			send_to_expander(t_cmd **cmd_lst);
int	        expand_error_var(char **cmd, int i);

// EXPANDER VAR
int			lookfor_var(char **cmd, t_env **env, int dq);
char	    *replace_var(char *str, char *env, int size, int j);
int	        find_var_and_replace(char **cmd, t_env **env, int i);

// EXPANDER UTILS
int			get_var_size(char *str);
int			ft_strncmp2(const char *s1, const char *s2, size_t n);
int			expand_quotes(char **cmd);

#endif