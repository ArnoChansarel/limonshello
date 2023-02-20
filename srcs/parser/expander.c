/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:24:39 by achansar          #+#    #+#             */
/*   Updated: 2023/02/20 19:20:34 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// char    *replace_env(char *str, char *env, int size)
// {
//    char *rtr;
//    int i;

//    i = 0;
//    rtr = malloc (sizeof(char *) * (ft_strlen(str) - size - 1 + ft_strlen(env)));
//    while (*str && *str != '$')
//     {
//         rtr[i] = *str;
//         i++;
//     }
//     while(env)
//         rtr[i] = *env++;
//     str += size;
//     while (*str)
//         rtr[i] = *str;
//    free(str);
//    return (rtr);
// }

// int lookfor_env(t_lexlst *lex, t_node **env)
// {
//     int     i;
//     int     size;
//     t_node  *head;

//     i = 0;
//     size = 0;
//     head = *env;
//     while(lex->word[i])
//     {
//         if(lex->word[i] == '$')
//         {
//             while (head)
//             {
//                 size = ft_strlen(head->key);
//                 if(ft_strncmp(lex->word[i + 1], head->key, size) != 0)
//                 {
//                     lex->word = replace_env(lex->word, head->value, size);
//                     break ;
//                 }
//                 head = head->next;
//             }
//         }
//         i++;
//     }
//     //        => $?
// }

static int expand_quotes(t_lexlst *lex, t_node **env)
{
    int i;
    char *str;
    int len;

    i = 0;
    len = ft_strlen(lex->word);
    str = malloc(sizeof(char *) * len - 2);
    // if (lex->word[0] == '\"')
    //     lookfor_env(lex);
    while (i <= len - 3)
    {
        str[i] = lex->word[i + 1];
        i++;
    }
    free(lex->word);
    lex->word = str;
    return (0);
}

int expander(t_lexlst **lex, t_node **env)
{
    t_lexlst *head;

    head = *lex;
    while (head)
    {
        if (head->word[0] == '\'' || head->word[0] == '\"')
            expand_quotes(head, env);
        // else
        //     lookfor_env(head);
        head = head->next;
    }
    return (0);
}