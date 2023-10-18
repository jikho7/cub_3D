/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:27:35 by jdefayes          #+#    #+#             */
/*   Updated: 2022/11/15 16:34:38 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Fichiers de rendu -
Paramètres lst: L’adresse du pointeur vers un élément.
f: L’adresse de la fonction à appliquer.
del: L’adresse de la fonction permettant de
supprimer le contenu d’un élément.
Valeur de retour La nouvelle liste.
NULL si l’allocation échoue
Fonctions externes autorisées
malloc, free
Description Itère sur la liste ’lst’ et applique la fonction
’f ’au contenu de chaque élément. Crée une nouvelle
liste résultant des applications successives de
’f’. La fonction ’del’ est là pour détruire le
contenu d’un élément si nécessaire.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_bloc;

	new_list = NULL;
	while (lst)
	{
		new_bloc = ft_lstnew(f(lst->content));
		if (new_bloc == NULL)
		{	
			del(lst->content);
			free(lst);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_bloc);
		lst = lst->next;
	}
	return (new_list);
}

/*
void ft_lstclear(t_list **lst, void (*del)(void*))
	//ft_lstdelone(*lst, del);
void ft_lstiter(t_list *lst, void (*f)(void *))
{
		while(lst)
		{
			f(lst->content);
			lst = lst->next;
		}
}

t_list *ft_lstnew(void *content)
{
	t_list *new_element;

	new_element = ft_calloc(1, (sizeof(t_list)));
	if (new_element == NULL)
		return (NULL);
	(*new_element).content = content;
	new_element->next = NULL;
	return(new_element);
}  
void ft_lstadd_front(t_list **lst, t_list *new);

void ft_lstiter(t_list *lst, void (*f)(void *))
{
		while(lst)
		{
			f(lst->content);
			lst = lst->next;
		}
}


*/