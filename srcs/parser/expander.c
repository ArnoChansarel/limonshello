/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:24:39 by achansar          #+#    #+#             */
/*   Updated: 2023/02/28 16:03:07 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// char    *replace_var(char *str, char *env, int size)//       => getenv("VARIABLE") !!!
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

int lookfor_var(t_lexlst *lex, t_env **env)
{
    int     i;
    int     size;
    t_env  *head;

    i = 0;
    size = 0;
    head = *env;
    printf("HERE1\n");
    while(lex->word[i])
    {
        if(lex->word[i] == '$')
        {
            printf("HERE1bis\n");
            while (head)
            {
                printf("HERE2\n");
                size = ft_strlen(head->key);
                if(ft_strncmp(&lex->word[i + 1], head->key, size) != 0)
                {
                    // lex->word = replace_var(lex->word, head->value, size);
                    printf("HERE3\n");
                    break ;
                }
                head = head->next;
            }
        }
        i++;
    }
    //        => $?
    return (0);
}

static int expand_quotes(t_lexlst *lex, t_env **env)
{
    int i;
    char *str;
    int len;

    (void)env;
    i = 0;
    len = ft_strlen(lex->word);
    str = malloc(sizeof(char *) * len - 2);
    // if (lex->word[0] == '\"')
    //     lookfor_var(lex);
    while (i <= len - 3)
    {
        str[i] = lex->word[i + 1];
        i++;
    }
    free(lex->word);
    lex->word = str;
    return (0);
}

int expander(t_lexlst **lex, t_env **env)
{
    t_lexlst *head;

    head = *lex;
    while (head)
    {
        if (head->word[0] == '\'' || head->word[0] == '\"')
            expand_quotes(head, env);
        else
            lookfor_var(head, env);
        head = head->next;
    }
    return (0);
}

