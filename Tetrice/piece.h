#pragma once

#include <iostream>
#include <string>


using namespace std;

typedef enum
{
    color_ni,
    Red,
    Green,
    Yellow,
    Blue
} shape_color;
typedef enum
{
    shape_ni,
    Cercle,
    Rhombus,
    Square,
    Triangle
} shape;
class piece
{
private:
    shape _shape;
    shape_color _color ;

public:
    piece();
    piece(shape s, shape_color c);
    piece(int shapes_count, int colors_count);
    void set_shape(shape s);
    void set_color(shape_color c);
    shape get_shape();
    shape_color get_color();
    piece& operator=(const piece& other);
    void afficher() const;
    string PieceToJson();
    string toString();
    
    ~piece();
    

	
};

