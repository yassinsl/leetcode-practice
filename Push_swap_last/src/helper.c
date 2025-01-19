void    rebuild_list(t_list **stack_a, t_list **stack_b)
{
    while (*stack_b)
        push_to_a(stack_a, pop_from_b(stack_b));
}

/* Value retrieval functions */
int get_value(t_list *stack_a, int pos)
{
    int i;

    i = 0;
    while (i < pos && stack_a)
    {
        stack_a = stack_a->next;
        i++;
    }
    return (stack_a ? stack_a->content : 0);
}

int get_max_value(t_list *stack_a)
{
    int max;

    if (!stack_a)
        return (0);
    max = stack_a->content;
    while (stack_a)
    {
        if (max < stack_a->content)
            max = stack_a->content;
        stack_a = stack_a->next;
    }
    return (max);
}

int get_min_value(t_list *stack_a)
{
    int min;

    if (!stack_a)
        return (0);
    min = stack_a->content;
    while (stack_a)
    {
        if (min > stack_a->content)
            min = stack_a->content;
        stack_a = stack_a->next;
    }
    return (min);
}

/* Count elements functions */
int    count_elements_less_than(t_list *stack, int value)
{
    int count;

    count = 0;
    while (stack)
    {
        if (stack->content < value)
            count++;
        stack = stack->next;
    }
    return (count);
}

int    count_elements_between(t_list *stack, int min_val, int max_val)
{
    int count;

    count = 0;
    while (stack)
    {
        if (stack->content >= min_val && stack->content <= max_val)
            count++;
        stack = stack->next;
    }
    return (count);
}

int    count_elements_greater_than(t_list *stack, int value)
{
    int count;

    count = 0;
    while (stack)
    {
        if (stack->content > value)
            count++;
        stack = stack->next;
    }
    return (count);
}

/* Pivot selection */
void    choose_pivot(t_list *stack_a, int len, t_prev *pevot)
{
    if (!stack_a || !pevot)
        return ;
    pevot->first = stack_a->content;
    pevot->last = get_value(stack_a, len - 1);
    pevot->midd = get_value(stack_a, len / 2);
    pevot->max = get_max_value(stack_a);
    pevot->min = get_min_value(stack_a);

    if (len <= 5)
    {
        pevot->major = pevot->max - ((pevot->max - pevot->min) / 3);
        pevot->minor = pevot->min + ((pevot->max - pevot->min) / 3);
    }
    else
    {
        pevot->major = get_median(pevot->first, pevot->midd, pevot->last);
        pevot->minor = get_median(pevot->min, 
                                get_value(stack_a, len / 4),
                                get_value(stack_a, (len * 3) / 4));
    }
    if (pevot->minor > pevot->major)
    {
        int temp = pevot->minor;
        pevot->minor = pevot->major;
        pevot->major = temp;
    }
}

/* Partitioning */
void    change_partition(t_list **stack_a, t_list **stack_b, t_prev *pevot)
{
    t_list *current;
    
    current = *stack_a;
    while (current)
    {
        int value = (*stack_a)->content;
        if (value <= pevot->minor)
            push_to_b(stack_b, pop_from_a(stack_a));
        else if (value > pevot->major)
        {
            push_to_b(stack_b, pop_from_a(stack_a));
            if (*stack_b && (*stack_b)->next)
                rb(stack_b);
        }
        else
            ra(stack_a);
        current = *stack_a;
    }
}

/* Recursive sorting i change this */
void    recursive_sort(t_list **stack_a, t_list **stack_b, int len)
{
    t_prev  *pevot;

    if (len <= 1)
        return ;
    pevot = malloc(sizeof(t_prev));
    if (!pevot)
        return ;
    choose_pivot(*stack_a, len, pevot);
    change_partition(stack_a, stack_b, pevot);
    
    int len_low = count_elements_less_than(*stack_b, pevot->minor);
    //int len_mid = count_elements_between(*stack_a, pevot->minor, pevot->major);
    //int len_high = count_elements_greater_than(*stack_b, pevot->major);
    
    
    free(pevot);
}

void    three_way_quick_sort(t_list **stack_a, t_list **stack_b, int len)
{
    if (len <= 1)
        return ;
    recursive_sort(stack_a, stack_b, len);
    rebuild_list(stack_a, stack_b);
}

/* Input handling and error checking */
void    ft_free_array(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
        free(arr[i++]);
    free(arr);
}

int is_check(char *arr)
{
    while (*arr)
    {
        if (!(*arr >= '0' && *arr <= '9') && *arr != '-')
            return (0);
        arr++;
    }
    return (1);
}

int is_duplicate(t_list *list, int number)
{
    while (list)
    {
        if (list->content == number)
            return (1);
        list = list->next;
    }
    return (0);
}

void    error(t_list **list)
{
    write(2, "Error\n", 6);
    if (list)
        ft_lstclear(list);
    exit(EXIT_FAILURE);
}

static t_list    *first_stack(char **arr, int len_size)
{
    int     i;
    int     j;
    int     num;
    t_list  *list;
    t_list  *tmp;
    char    **args;

    i = -1;
    list = NULL;
    while (++i < len_size)
    {
        if (ft_strchr(arr[i], ' '))
        {
            args = ft_split(arr[i], ' ');
            j = 0;
            while (args[j])
            {
                num = ft_atoi(args[j]);
                if (!is_check(args[j]) || is_duplicate(list, num))
                {
                    ft_free_array(args);
                    ft_lstclear(&list);
                    error(&list);
                }
                tmp = ft_lstnew(num);
                ft_lstadd_back(&list, tmp);
                j++;
            }
            ft_free_array(args);
            continue;
        }
        num = ft_atoi(arr[i]);
        if (!is_check(arr[i]) || is_duplicate(list, num))
        {
            ft_lstclear(&list);
            error(&list);
        }
        tmp = ft_lstnew(num);
        ft_lstadd_back(&list, tmp);
    }
    return (list);
}

int main(int ac, char **av)
{
    t_list  *stack_a;
    t_list  *stack_b;

    if (ac < 2)
        error(NULL);
    stack_a = first_stack(&av[1], ac - 1);
    stack_b = NULL;
    three_way_quick_sort(&stack_a, &stack_b, ft_lstsize(stack_a));
    
    while (stack_a)
    {
        printf("%d->", stack_a->content);
        stack_a = stack_a->next;
    }
    printf("NULL\n");
    ft_lstclear(&stack_a);
    return (0);
}

