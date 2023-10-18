/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:20:31 by jdefayes          #+#    #+#             */
/*   Updated: 2022/11/15 16:21:01 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new);
/*
Fichiers de rendu -
Paramètres lst: L’adresse du pointeur vers le premier élément
de la liste.
new: L’adresse du pointeur vers l’élément à
rajouter à la liste.
Valeur de retour Aucune
Fonctions externes autorisées
Aucune
Description Ajoute l’élément ’new’ à la fin de la liste.
*/

/*void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *temp;
	temp = *lst;
		while(temp->next)
			temp = temp->next;
	temp = ft_lstlast(*lst);
	temp->next = new;
	//    temp->next = new;
	 //   new->next = NULL;
}*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}
