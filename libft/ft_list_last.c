#include "libft.h"

t_list			*ft_list_last(t_list *begin_list)
{
	if (begin_list->next == NULL)
		return (begin_list);
	return (ft_list_last(begin_list->next));
}
