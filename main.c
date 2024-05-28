#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "list.h"

#define MAX_LISTS 10

int main()
{
    list **lists = (list **)malloc(MAX_LISTS * sizeof(list *));
    list *current_list = NULL;

    int num_lists = 0;
    int choice;
    int list_index;
    int value;


    while (1)
    {
        printf("1. Create new list\n2. Select list\n3. Create copy\n4. Delete the list\n5. Add after\n6. Add before\n7. Delete current\n8. Go next\n");
        printf("9. Go prev\n10. Print current\n11. Print the list\n12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (num_lists < MAX_LISTS)
                {
                    lists[num_lists] = create();
                    current_list = lists[num_lists];
                    printf("New list created at index %d.\n", num_lists);
                    num_lists++;
                }
                else
                {
                    printf("Maximum number of lists reached (%d).\n", MAX_LISTS);
                }
                break;
            case 2:
                printf("Enter the index of the list to select: ");
                scanf("%d", &list_index);
                if (list_index >= 0 && list_index < num_lists)
                {
                    current_list = lists[list_index];
                }
                else
                {
                    printf("Invalid list index.\n");
                }
                break;
            case 3:
                lists[num_lists] = create_copy(current_list);
                current_list = lists[num_lists];
                printf("Copy of the current list created at index %d.\n", num_lists);
                num_lists++;
                break;
            case 4:
                list_free(current_list);
                printf("List deleted.\n");
                break;

            case 5:
                printf("Enter value to add after: ");
                scanf("%d", &value);
                current_list = add_after(current_list, value);
                printf("\n");
                break;

            case 6:
                printf("Enter value to add before: ");
                scanf("%d", &value);
                current_list = add_before(current_list, value);
                printf("\n");
                break;

            case 7:
                current_list = elem_delete(current_list);
                printf("\n");

                break;
            case 8:
                current_list = move_next(current_list);
                printf("\n");

                break;
            case 9:
                current_list = move_prev(current_list);
                printf("\n");

                break;
            case 10:
                printf("Current value: %d\n", print_elem(current_list));
                printf("\n");

                break;
            case 11:
                print_list(current_list);
                printf("\n");

                break;
            case 12:
                 for (int i = 0; i < num_lists; i++)
                {
                    list_free(lists[i]);
                }
                free(lists);
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice\n");
                printf("\n");

        }
    }

    return 0;
}
