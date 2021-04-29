// ========================================= RADIX SORT ON LINKED LIST SINGLE ============================================

#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct  NODE
{
    int data;
    struct NODE* pNext;
};

struct NODE* start = NULL;

void radix_sort();
int larger_digit();
int digit_finder(int number, int k);

int main()
{
    struct NODE* temp, * x;
    int count, limit, element;
    printf("\nEnter Total Number of Elements:\t");
    cin >> limit;
    for (count = 0; count < limit; count++)
    {
        printf("Element No. %d : \t", count + 1);
        cin >> element;
        temp = (struct NODE*)malloc(sizeof(struct NODE));
        temp->data = element;
        temp->pNext = NULL;
        if (start == NULL)
        {
            start = temp;
        }
        else
        {
            x = start;
            while (x->pNext != NULL)
            {
                x = x->pNext;
            }
            x->pNext = temp;
        }
    }
    radix_sort();
    printf("\nSorted List\n");
    x = start;
    while (x != NULL)
    {
        printf("%3d", x->data);
        x = x->pNext;
    }
    printf("\n");
    return 0;
}

void radix_sort()
{
    int count, k, digit, least_significant, most_significant;
    struct NODE* rear[10], * front[10], * p;
    least_significant = 1;
    most_significant = larger_digit();
    for (k = least_significant; k <= most_significant; k++)
    {
        for (count = 0; count <= 9; count++)
        {
            rear[count] = NULL;
            front[count] = NULL;
        }
        for (p = start; p != NULL; p = p->pNext)
        {
            digit = digit_finder(p->data, k);
            if (front[digit] == NULL)
            {
                front[digit] = p;
            }
            else
            {
                rear[digit]->pNext = p;
            }
            rear[digit] = p;
        }
        count = 0;
        while (front[count] == NULL)
        {
            count++;
        }
        start = front[count];
        while (count < 9)
        {
            if (rear[count + 1] != NULL)
            {
                rear[count]->pNext = front[count + 1];
            }
            else
            {
                rear[count + 1] = rear[count];
            }
            count++;
        }
        rear[9]->pNext = NULL;
    }
}

int larger_digit()
{
    struct NODE* p = start;
    int temp = 0, digit = 0;
    while (p != NULL)
    {
        if (p->data > temp)
        {
            temp = p->data;
        }
        p = p->pNext;
    }
    while (temp != 0)
    {
        digit++;
        temp = temp / 10;
    }
    return(digit);
}

int digit_finder(int number, int k)
{
    int term, count;
    for (count = 1; count <= k; count++)
    {
        term = number % 10;
        number = number / 10;
    }
    return(term);
}