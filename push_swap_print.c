void print_list(t_stack *stack) {
    t_stack *current = stack;

    while (current != NULL) {
        printf("%d\n", current->nbr);
        current = current->next;
    }
}
