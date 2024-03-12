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
void print_list(struct list_head *head)
{
    element_t *cur;
    list_for_each_entry (cur, head, list)
        printf("%d ", cur->value);
    printf("\n");
    return;
}
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
int list_length(struct list_head *head)
{
    int len = 0;
    struct list_head *cur;
    list_for_each (cur, head) {
        len++;
    }
    return len;
}
void quick_sort(struct list_head *head)
{
    int n = list_length(head);
    int value;
    int i = 0;
    int max_level = 2 * n;
    struct list_head *begin[max_level];
    for (int j = 0; j < max_level; j++) {
        begin[j] = malloc(sizeof(struct list_head));
        INIT_LIST_HEAD(begin[j]);
    }
    int end[max_level];
    LIST_HEAD(result);
    LIST_HEAD(left);
    LIST_HEAD(right);

    list_splice_init(head, begin[0]);
    end[0] = list_length(begin[0]);
    while (i >= 0) {
        LIST_HEAD(L);
        list_splice_init(begin[i], &L);
        int len = end[i];
        if (len > 1) {
            element_t *pivot = list_first_entry(&L, element_t, list);
            value = pivot->value;
            list_del_init(&pivot->list);
            element_t *cur, *safe;
            list_for_each_entry_safe (cur, safe, &L, list) {
                if (cur->value > value)
                    list_move(&cur->list, &right);
                else
                    list_move(&cur->list, &left);
            }
            list_splice_init(&left, begin[i]);
            end[i] = list_length(begin[i]);
            list_splice_init(&right, begin[i + 2]);
            end[i + 2] = list_length(begin[i + 2]);
            list_add(&(pivot->list), begin[i + 1]);
            end[i + 1] = 1;
            i += 2;


        } else {
            if (len > 0) {
                element_t *pivot = list_first_entry(&L, element_t, list);
                list_move(&pivot->list, head);
            }
            i--;
        }
    }
    for (int j = 0; j < max_level; j++) {
        free(begin[j]);
    }
}
void list_free(struct list_head *head)
{
    element_t *cur, *safe;
    list_for_each_entry_safe (cur, safe, head, list) {
        free(cur);
    }
    return;
}
int main(int argc, char **argv)
{
    LIST_HEAD(head);

    size_t count = 20;

    int *test_arr = malloc(sizeof(int) * count);

    for (int i = 0; i < count; ++i)
        test_arr[i] = i;
    shuffle(test_arr, count);

    while (count--)
        list_construct(&head, test_arr[count]);
    print_list(&head);
    quick_sort(&head);
    print_list(&head);
    assert(list_is_ordered(&head));

    list_free(&head);

    free(test_arr);

    return 0;
}
