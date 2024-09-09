#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct item
{
    int data;
    struct item* next;
};

void push(struct item** start, int value)
{
    struct item* new_element = malloc(sizeof(struct item));
    new_element->data = value;
    new_element->next = *start;
    *start = new_element;
}
void pop(struct item* start)
{
    struct item* old_element = start;
    int wert = old_element->data; 
    start = old_element->next; 
    free(old_element--); 
}

int main()
{
    struct item* start = NULL;
    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        int randNumber=rand() % 100;
        push(&start, randNumber);
    }

    
    // Output the stack 
    printf("Stack contents: ");
    for (struct item* i = start; i != NULL; i = i->next)
    {
        printf("%d ", i->data);
    }
    printf("\n");
    

}
