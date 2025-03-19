// user create array, (iterative) search, update data, remove (shift back)
// change position to simply number

#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int n);
void add_item(int *arr);
void update_item(int *arr);
void remove_item(int *arr);
void search(int *arr);

int size = 100; // to handle array expansion
int realSize = 5; // increment as array grows

int main(void)
{
 
    int Arr[100] = {1, 2, 3, 4, 5};
    
    /*
        int arr[size];
        printf("How many numbers would you like to be in the array?: ");
        scanf("%d", &realSize);
        printf("Type Numbers: \n");
        for (int i = 0; i < realSize; i++) 
        {
            scanf("%d", &arr[i]);
        }
         print_array(arr);
        */

    int choice;
    do {
    print_array(Arr, realSize);
    printf("1. Update item\n2. Delete item\n3. Search for item\n4. Add Item\n5. Exit\n\nPress according number for choice\n");

    scanf("%d", &choice);
    switch (choice) {
        case 1:
            update_item(Arr);
            break;
        case 2:
            remove_item(Arr);
            break;
        case 3:
            search(Arr);
            break;
        case 4:
            add_item(Arr);
            break;
        case 5:
            exit(1);
        default:
            printf("Out of Range");
            break;
    }

} while(1);

}

void print_array(int *arr, int n)
{
    printf("\n[ ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("]\n\n");
}

void add_item(int *arr)
{
    realSize++;
    int num;
    printf("What element would you like to add? ");
    scanf("%d", &num);
    arr[realSize - 1] = num; // change last item
}
                

void update_item(int *arr) 
{
    int el, newel;
    printf("Which element would you like to update? ");
    scanf("%d", &el);

    printf("Change to: ");
    scanf("%d", &newel);

    for (int i = 0; i < realSize; i++) 
    {
        if (arr[i] == el) 
        {
            arr[i] = newel;
        }
    }
}

void remove_item(int *arr)
{
    int el;
    printf("Which element(s) would you like to remove?\n");
    scanf("%d", &el);

    int n = realSize;
    int i = 0;
    while (i < realSize)
    {
        if (arr[i] == el)
        {
            // replace current element with next
            arr[i] = arr[i + 1];

            // put inital iteration on pause in order to push back all next elements
            for (int j = i; j < realSize - 1; j++) // realSize - 1 as last element should = 0
            {
                arr[j] = arr[j + 1];
            }
            realSize--; 
            // end and go back to looking for items to deleted
        }
        else 
        {
            i++;
        }
    }
    
    
     arr[realSize] = 0;
    
}

// must accept duplicates, dont end loop early
void search(int *arr) 
{
    int num;
    printf("Search array for: \n");
    scanf("%d", &num);
    for (int i = 0; i < realSize; i++) 
    {
        if (arr[i] == num)
        {
            printf("Number found in position %d\n", i);
            return;
        }
    }
    printf("Number wasn't found\n");
}


