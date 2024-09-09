#include <stdio.h>
#include <stdlib.h>

struct item
{
    int data;
    struct item* next;
};

void Add(int x, int p, struct item** start)
{
    struct item* neues_element = malloc(sizeof(struct item));
    neues_element->data = x;
    
    // Einfügen am Anfang start wird auch verschoben
    if (p == 0 || *start == NULL)
    {
        neues_element->next = *start;
        *start = neues_element;
        return;
    }
    
    // Schleife zum durchlaufen zum Element vorher und verschieben des next Zeigers
    struct item* current_ptr = *start;
    for (int i = 0; i < p - 1 && current_ptr->next != NULL; i++)
    {
        current_ptr = current_ptr->next;
    }
    
    // Neues Element einfügen
    neues_element->next = current_ptr->next;
    current_ptr->next = neues_element;
}

void Delete(int p, struct item** start)
{
    // Leere Liste
    if (*start == NULL)
    {
        printf("Liste ist leer. Füge ein Element ein! \n");
        return;
    }
    // p=0 und verschieben des Start Zeigers
    if (p == 0)
    {
        struct item* temp = *start;
        *start = (*start)->next;
        free(temp);
        return;
    }
    
    // Schleife zum durchlaufen zum Element vorher und verschieben des next Zeigers
    struct item* current = *start;
    for (int i = 0; i < p - 1 && current->next != NULL; i++)
    {
        current = current->next;
    }
    
    // Spezialfall: p ist außerhalb der Liste
    if (current->next == NULL)
    {
        printf("Die Liste hat weniger als %d Elemente.\n", p);
        return;
    }
    
    // Element löschen
    struct item* temp = current->next;
    current->next = temp->next;
    free(temp);
}

int main()
{
    struct item* start = NULL;
    int eingabe, wert, position;

    do
    {
        printf("\nWas möchten Sie tun? 1: Add, 2: Delete, 3: Ausgabe, 4: Ende ");
        scanf("%d", &eingabe);

        // Add
        if (eingabe == 1)
        {
            printf("Wert für neues Element: ");
            scanf("%d", &wert);
            printf("Position für das neue Element: ");
            scanf("%d", &position);
            Add(wert, position, &start);
        }
        
        // Delete
        else if (eingabe == 2)
        {
            printf("Position des zu löschenden Elements: ");
            scanf("%d", &position);
            Delete(position, &start);
        }

        // Ausgabe
        else if (eingabe == 3) 
        {
            printf("Inhalt der Liste: ");
            for (struct item* i = start; i != NULL; i = i->next)
            {
                printf("%d ", i->data);
            }
            printf("\n");
        }
    }
    while (eingabe != 4);
    
    return 0;
}
