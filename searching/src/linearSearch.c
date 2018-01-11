/*********************************

File:   linearSearch.c
Date:   6 Jan 2018
Author: nikhilkulkarni88@gmail.com 

**********************************/

#include "linearSearch.h"

//-----------------------------------------------------------------------
//          linearSearch()
//-----------------------------------------------------------------------
//DESCRIPTION: Search for a given element in an array iteratively.
//COMPLEXITY:  O(n)
//
//-----------------------------------------------------------------------
void linearSearch (const int array[], uint32_t max, int32_t elem)
{
    uint32_t i = 0;

    for (i = 0; i < max; i++)
    {
        if (array[i] == elem)
        {
            printf("Found element %d in the array at index %d\n", elem, i);
            return;
        }
    }
    printf ("Element %d not found in the array\n", elem);
    return;
}

//-----------------------------------------------------------------------
//          main()
//-----------------------------------------------------------------------
//DESCRIPTION: Main
//
//-----------------------------------------------------------------------
int main ()
{
    int array[10] = {4, 1, 77, 33, 6, 457, 54, 99, 13, 420};
    linearSearch (array, 10, 420);
    return 0;
}
