#include "libft.h"

t_list	*ft_lstnew_GC(void *data, t_list **gc_lst)
{
	t_list	*list;

	list = my_malloc(0, sizeof(t_list), gc_lst);
	if (!list)
		return (NULL);
	list->content = data;
	list->next = NULL;
	return (list);
}
