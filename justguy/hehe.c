// user create array, (iterative) search, update data, remove (shift back)

#include <stdio.h>
void print_array(int *arr);
void update_item(int *arr);
void remove_item(int *arr);
void search(int *arr);

// #define SIZE_OF_ARRAY 5

int main(void)
{
    int arr[5] = {1, 2, 3, 4, 5};
    
/*
        int arr[5];
        printf("Type 5 Numbers: \n");
        for (int i = 0; i < 5; i++) 
        {
            scanf("%d", &arr[i]);
        }
         print_array(arr);
*/

    int choice;
    printf("1. Update item\n2. Delete item\n3. Search for item\n\nPress according number for choice");

    scanf("%d", &choice);
    switch (choice) {
        case 1:
            update_item(arr);
            break;
        case 2:
            remove_item(arr);
            break;
        case 3:
            search(arr);
            break;
        default:
            printf("Out of Range");
            break;
    }



}

void print_array(int *arr)
{
    printf("[ ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("]");
}

// pos !> 5
void update_item(int *arr) 
{
    int pos, num;
    printf("Position?\n");
    scanf("%d", &pos);
    printf("Change to: \n");
    scanf("%d", &num);
    arr[pos] = num;
}
// add validation pos !> 5
void remove_item(int *arr)
{
    int pos;

    printf("Position for item to be removed?\n");
    scanf("%d", &pos);

    // keep shifting until pos reach size of array - 1
    while (pos < 4) 
    {
        arr[pos] = arr[pos + 1];
        pos++;
    }
    arr[pos] = 0;

    printf("%d", arr[0]);
    
}

void search(int *arr) 
{
    int num;
    printf("Search array for: \n");
    scanf("%d", &num);
    for (int i = 0; i < 5; i++) 
    {
        if (arr[i] == num)
        {
            printf("Number found in position %d", i);
            return;
        }
    }
    printf("Number wasn't found");
}


