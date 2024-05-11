

#include<conio.h>
#include "Game.h"
static bool s_finished = false;
#define SOLID 0xDB    // Represents a solid block (█)
#define LIGHT 0xB0    // Represents a light shade (░)
#define MEDIUM 0xB2   // Represents a medium shade (▒)
#define SQUARE 0x25A0       // Represents a filled square (■)
#define CIRCLE 0x25CF       // Represents a filled circle (●)
#define TRIANGLE 0x25B2     // Represents a filled triangle pointing up (▲)
#define DIAMOND 0x2666 
typedef struct Element {
    int data;
    struct Element* next;

}Element;
Element* createElement(int data) {
    Element* el = new Element();
    el->data = data;
    el->next = NULL;
    return el;
}
void insertData(int data, Element** Ll) {
    Element* e = createElement(data);
    *Ll = (Element*)malloc(sizeof(Element));
    e->next = *Ll;
    *Ll = e;
}
void DisplayList(Element* L) {
    while (L)
    {
        std::cout << L->data<< std::endl;
        L = L->next;
    }
}
int main() {

   
    Game g;
    _getch();
    return 0;
}


