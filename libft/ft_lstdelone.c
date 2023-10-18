/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:25:01 by jdefayes          #+#    #+#             */
/*   Updated: 2022/11/15 16:25:37 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Fichiers de rendu -
Paramètres lst: L’élément à free
del: L’adresse de la fonction permettant de
supprimer le contenu de l’élément.
Valeur de retour Aucune
Fonctions externes autorisées
free
Description Libère la mémoire de l’élément passé en argument en
utilisant la fonction ’del’ puis avec free(3). La
mémoire de ’next’ ne doit pas être free.
*/

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{	
	del(lst->content);
	free (lst);
}

/*char	*ft_strmapi(char const	*s, char (*f)(unsigned int, char))
{
	result[i] = f(i, s[i]);         // ft
	str1 = (unsigned char *)s1;     // cast
}*/