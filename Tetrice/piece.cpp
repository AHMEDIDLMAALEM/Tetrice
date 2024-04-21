#include "piece.h"
#include <iostream>
#include <windows.h>


using namespace std;

piece::piece() {
    _color = color_ni;
    _shape = shape_ni;

}

piece::piece(shape s, shape_color c) {
    _shape = s;
    _color = c;

}
piece::piece(int shapes_count, int colors_count) {
    int s = (rand() % shapes_count) + 1,c = (rand() % colors_count) + 1;


    _shape = (shape)(s);
    _color = (shape_color)(c);

}


void piece::set_shape(shape s) {
    _shape = s;
}

void piece::set_color(shape_color c) {
    _color = c;
}

shape piece::get_shape() {
    return _shape;
}

shape_color piece::get_color() {
    return _color;
}
piece::~piece() {
    //std::cout << "la piece est morte"<<std::endl;
 }

 piece& piece:: operator=(const piece& other) {
    // Check for self-assignment (optimization)
        _shape = other._shape;
        _color = other._color;
    return *this; // Return a reference to the modified object
}

 void piece::afficher() const {
     switch (_color)
     {
     case Red:
         cout << "\033[31m"; // Code d'échappement ANSI pour le rouge
         break;
     case Green:
         cout << "\033[32m"; // Code d'échappement ANSI pour le vert
         break;
     case Yellow:
         cout << "\033[33m"; // Code d'échappement ANSI pour le jaune
         break;
     case Blue:
         cout << "\033[34m"; // Code d'échappement ANSI pour le bleu
         break;
     default:
         break;
     }

     // Affichez la forme (ici, nous utilisons un exemple avec un cercle)
     switch (_shape)
     {
     case Cercle:
         cout << "C";
         break;
     case Rhombus:
         cout << "R";
         break;
     case Square:
         cout << "S";
         break;
     case Triangle:
         cout << "T";
         break;
     default:
         break;
     }

     // Rétablissez la couleur par défaut
     cout << "\033[0m  ";
 }

 string piece::toString(){
     string res;

     // Affichez la forme (ici, nous utilisons un exemple avec un cercle)
     switch (_shape)
     {
     case Cercle:
         res.append("C");
         break;
     case Rhombus:
         res.append("R");
         break;
     case Square:
         res.append("S");
         break;
     case Triangle:
         res.append("T");
         break;
     default:
         break;
     }

     switch (_color)
     {
     case Red:
         res.append("r"); // Code d'échappement ANSI pour le rouge
         break;
     case Green:
         res.append("g"); // Code d'échappement ANSI pour le vert
         break;
     case Yellow:
         res.append("y"); // Code d'échappement ANSI pour le jaune
         break;
     case Blue:
         res.append("b"); // Code d'échappement ANSI pour le bleu
         break;
     default:
         break;
     }
     // Rétablissez la couleur par défaut
     
     return res;
 }
 




