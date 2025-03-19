#include <iostream>

int* add_item(int arr[], int element);

int main(void)
{
    int size = 5;
    int arr[] = {1, 2, 3, 4, 5};


    int *p = add_item(arr, 6);
    std::cout << p[5] << " " << p[4] << std::endl;

    /*
    for (int i = 0; i < 6; i++) 
    {
        std::cout << p[i] << " ";
    }
    std::cout << std::endl;
    */

    // p = add_item(arr, 6);

}

int* add_item(int arr[], int element) 
{
    int *neww = new int[6];
    for (int i = 0; i < 5; i++) 
    {
        neww[i] = arr[i];
    }
    neww[6] = element;

    return neww;

}

/*
int* test (int a[5], int b[5]) {
    int *c = new int[5];

    for (int i = 0; i < 5; i++) 
        c[i] = a[i]+b[i];
    return c;
}
}*/