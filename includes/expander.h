/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:41:53 by achansar          #+#    #+#             */
/*   Updated: 2023/04/08 16:45:03 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H
# include "structs.h"

// EXPANDER FUNCTIONS
int			expander(char **cmd, t_env **env);
int			expand_redirections(char **rd, t_env **env);
int 		send_to_expander(t_cmd **cmd_lst);
int 		lookfor_var(char **cmd, t_env **env, int size, int dq);

// EXPANDER UTILS
int			get_var_size(char *str);
int			ft_strncmp2(const char *s1, const char *s2, size_t n);
int			expand_quotes(char **cmd);

#endif