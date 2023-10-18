/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:25:44 by jdefayes          #+#    #+#             */
/*   Updated: 2022/11/15 16:26:48 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Fichiers de rendu -
Paramètres lst: L’adresse du pointeur vers un élément.
f: L’adresse de la fonction à appliquer.
Valeur de retour Aucune
Fonctions externes autorisées
Aucune
Description Itère sur la liste ’lst’ et applique la fonction
’f’ au contenu chaque élément.
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f (lst->content);
		lst = lst->next;
	}
}
