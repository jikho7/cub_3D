/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:35:16 by jdefayes          #+#    #+#             */
/*   Updated: 2023/10/18 16:30:52 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
Fonctions externes autorisées
malloc
Description Alloue (avec malloc(3)) et renvoie un nouvel
élément. La variable membre ’content’ est
initialisée à l’aide de la valeur du paramètre
’content’. La variable ’next’ est initialisée à
NULL
*/
/*int main()
{
	t_list *list; //creation ptr de type t_list
	list = NULL; // list pointe sur NULL;

	return (0);
}*/

t_list	*ft_lstnew(char *content)
{
	t_list	*new_element;

	new_element = ft_calloc(1, (sizeof(t_list)));
	if (new_element == NULL)
		return (NULL);
	(*new_element).content = content;
	new_element->next = NULL;
	return (new_element);
}

/*
typedef struct s_list
{

void *content;
struct s_list *next;
} t_list;
*/
