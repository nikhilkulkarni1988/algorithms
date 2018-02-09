/*********************************

File:   KMPSearching.c
Date:   7 Jan 2018
Author: nikhilkulkarni88@gmail.com 

**********************************/
#include "KMPSearching.h"

//-----------------------------------------------------------------------
//          createLPS()
//-----------------------------------------------------------------------
//DESCRIPTION: Create LPS pattern for a given sub-string.
//COMPLEXITY:  O(len)
//
//-----------------------------------------------------------------------
static int * createLPS(char *pPattern)
{
    if (pPattern == NULL)
    {
        printf ("Unexpected NULL pattern\n");
        return NULL;
    }

    int len = 0;
    len = strlen(pPattern);

    //Create an array of size len
    int *pLPS = (int *)calloc(len, sizeof(int));

    if (pLPS == NULL)
    {
        printf("Memory Allocation Error! \n");
        return NULL;
    }

    int i = 1, j = 0; //counters for keeping track of LPS array
    pLPS[0] = 0; //always 0
    
    //Logic for creating LPS array.
    //When pPattern[i] == pPattern[j], pLPS[i] = j+1, increment both i and j.
    //When pPattern[i] != pPattern[j],
    //  -if (j == 0): pLPS[i] = 0, increment i.
    //  -else       : j = pLPS[j-1].
    while (i < len )
    {
        if (pPattern[i] == pPattern[j])
        {
            pLPS[i] = j+1;
            i++;
            j++;
        }
        else //pPattern[i] != pPattern[j]
        {
            if (j == 0)
            {
                pLPS[i] = 0;
                i++;
            }
            else
            {
                j = pLPS[j-1];
            }
        }
    }

    //Print the LPS array

    printf("LPS array for pattern %s is \n[",pPattern);
    for (i = 0; i < len; i++)
    {
        printf("%d,",pLPS[i]);
    }
    printf("]\n");
    return pLPS;
}

void checkForPattern(const char *pString, const char *pSubString, const int *pLPS)
{
   if ( (pString == NULL) ||
        (pSubString == NULL) ||
        (pLPS == NULL) )
   {
    printf("Error:Unexpected NULL pointer\n");
    return;
   }

   unsigned int i = 0, j = 0;

   size_t lenString    = strlen(pString);
   size_t lenSubString = strlen(pSubString);

   if (lenSubString > lenString)
   {
       printf("Pattern Length greater than String Length\n");
       return;
   }

   while (i < lenString )
   {
       //Check Char in both String and Pattern
       //If at the end of Pattern, we have found a match
       //Else increment position to next character
       if (pString[i] == pSubString [j])
       {
           if (j == lenSubString - 1)
           {
               printf ("substring found at location at %d\n", (i-j+1));
               return;
           }
           else
           {
               i++;
               j++;
           }
       }
       
       //No Match found.
       //if j = 0, increment i.
       //else manipulate position of j, j = pLPS[j-1]
       else
       {
           if (j == 0)
           {
               i++;
           }
           else
           {
               j = pLPS[j-1];
           }
       }
   }
   printf ("No match found!\n");
   return;
}

int main()
{
    char *pString1 = "XXAABAACAABAAXX";
    char *pSubString1 = "AABAACAABAA";
    char *pSubString2 = "ABCD";
    int *pPrefix1 = createLPS(pSubString1);
    int *pPrefix2 = createLPS(pSubString2);
    
    if (pPrefix1 == NULL)
    {
        printf("Error creating prefix1 LPS\n");
        return -1;
    }
    
    checkForPattern(pString1, pSubString1, pPrefix1);
    free(pPrefix1);

    if (pPrefix2 == NULL)
    {
        printf("Error creating prefix2 LPS\n");
        return -1;
    }
    
    checkForPattern(pString1, pSubString2, pPrefix1);
    free(pPrefix2);
    
    return 0;
}
