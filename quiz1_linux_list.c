#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
typedef struct {
    int value;
    struct list_head list;
} element_t;
void list_construct(struct list_head *head, int n)
{
    element_t *node = malloc(sizeof(element_t));
    node->value = n;
    list_add(&node->list, head);
}
// /* Verify if list is order */
static bool list_is_ordered(struct list_head *head)
{
    element_t *cur, *safe;
    list_for_each_entry_safe (cur, safe, head, list) {
        if (&safe->list == head) {
            break;
        } else {
            if (cur->value > safe->value)
                return false;
        }
    }
    return true;
}

/* shuffle array, only work if n < RAND_MAX */
void shuffle(int *array, size_t n)
{
    if (n <= 0)
        return;

    for (size_t i = 0; i < n - 1; i++) {
        size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
        int t = array[j];
        array[j] = array[i];
        array[i] = t;
    }
}
// void quick_sort(node_t **list)
// {
//     int n = list_length(list);
//     int value;
//     int i = 0;
//     int max_level = 2 * n;
//     node_t *begin[max_level], *end[max_level];
//     node_t *result = NULL, *left = NULL, *right = NULL;

//     begin[0] = *list;
//     end[0] = list_tail(list);

//     while (i >= 0) {
//         node_t *L = begin[i], *R = end[i];
//         // print_list(L);
//         if (L != R) {
//             node_t *pivot = L;
//             value = pivot->value;
//             node_t *p = pivot->next;
//             pivot->next = NULL;

//             while (p) {
//                 node_t *n = p;
//                 p = n->next;
//                 list_add(n->value > value ? &right : &left, n);
//             }

//             begin[i] = left;
//             end[i] = list_tail(&left);
//             begin[i + 1] = pivot;
//             end[i + 1] = pivot;
//             begin[i + 2] = right;
//             end[i + 2] = list_tail(&right);

//             left = right = NULL;
//             i += 2;
//         } else {
//             if (L)
//                 list_add(&result, L);
//             i--;
//         }
//     }
//     *list = result;
// }
int main(int argc, char **argv)
{
    LIST_HEAD(head);

    size_t count = 10;

    int *test_arr = malloc(sizeof(int) * count);

    for (int i = 0; i < count; ++i)
        test_arr[i] = i;
    // shuffle(test_arr, count);

    while (count--)
        list_construct(&head, test_arr[count]);
    // print_list(list);
    // quick_sort(&list);
    // print_list(list);
    assert(list_is_ordered(&head));
    element_t *cur;
    list_for_each_entry (cur, &head, list)
        printf("%d ", cur->value);
    printf("\n");
    // list_free(&list);

    // free(test_arr);

    return 0;
}