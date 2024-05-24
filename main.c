#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "list.h"

int main()
{
    list* list = create();
    int choice, value;

    if (!list)
    {
        printf("Failed to create list\n");
        return 1;
    }

    while (1)
    {
        printf("1. Add after\n2. Add before\n3. Delete current\n4. Go next\n5. Go prev\n6. Print current\n7. Print the list\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to add after: ");
                scanf("%d", &value);
                list = add_after(list, value);
                printf("\n");
                break;
            case 2:
                printf("Enter value to add before: ");
                scanf("%d", &value);
                list = add_before(list, value);
                printf("\n");

                break;
            case 3:
                list = elem_delete(list);
                printf("\n");

                break;
            case 4:
                list = move_next(list);
                printf("\n");

                break;
            case 5:
                list = move_prev(list);
                printf("\n");

                break;
            case 6:
                printf("Current value: %d\n", print_elem(list));
                printf("\n");

                break;
            case 7:
                print_list(list);
                printf("\n");

                break;
            case 8:
                list_free(list);
                printf("\n");

                return 0;
            default:
                printf("Invalid choice\n");
                printf("\n");

        }
    }

    return 0;
}
