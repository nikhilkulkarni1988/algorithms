/*********************************

File:   binarySearchRegular.c
Date:   10 Jan 2018
Author: nikhilkulkarni88@gmail.com 

**********************************/
#include <stdio.h>

//-----------------------------------------------------------------------
//          binarySearch()
//-----------------------------------------------------------------------
//DESCRIPTION: Search for an element in a sorted array.
//COMPLEXITY:  O(log(n))
//
//-----------------------------------------------------------------------
//Assuming array in ascending order
void binarySearch (int *pArray, unsigned int size, int elem)
{
    unsigned int l = 0;
    unsigned int r = size;
    unsigned int m = (l+r)/2;

    while (r - l > 1)
    {
        //if elem is greater than middle element go to the higher half
        if (pArray [m] < elem)
        {
            l = m;
            m = (l+r)/2;
        }
        //if elem is lesser than middle element go to the lower half
        else if (pArray [m] > elem)
        {
            r = m;
            m = (l+r)/2;
        }
        //we have an exact match return exact index
        else
        {
            printf("Found element %d at position %d of the array\n", elem, m+1);
            return;
        }
    }
    printf("No element found in the array\n");
    return;
}

int main ()
{
    int array1[10] = {1,3,5,7,9,11,13,15,17,19};
    int array2[10] = {2,4,6,8,10,12,14,16,18,20};

    binarySearch(array1, 10, 15);
    binarySearch(array1, 10, 16);
    binarySearch(array2, 10, 18);
    binarySearch(array2, 10, 19);
}
