#pragma once
#include <iostream>
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

class shape_node
{
private:
    shape _shape;
    shape_color _color;
    shape_node* next;
    shape_node* next_shape;
    shape_node* next_color;
    shape_node* prev_color;
    shape_node* prev_shape;

public:
    // constructur
    shape_node(bool set,shape s = shape_ni, shape_color c = color_ni, shape_node* next = NULL, shape_node* next_shape = NULL, shape_node* next_color = NULL, shape_node* prev_shape = NULL, shape_node* prev_color = NULL)
    {
        this->_shape = s;
        this->_color = c;
        this->next = next;
        this->next_shape = next_shape;
        this->next_color = next_color;
        this->prev_shape = prev_shape;
        this->prev_color = prev_color;
    }
    // constructeur aleatoire 
    shape_node(int possible_shapes=4,int possible_colors= 4) {
        this->_shape = static_cast<shape>((rand() % possible_shapes) + 1);
        this->_color = static_cast<shape_color>((rand() % possible_colors) + 1);
        
        cout << "\nDBUGGING: allocated shape with color : "<<this->get_color() <<" , shape : "<<this->get_shape()<<std::endl;
    }
    string toString() {
        switch (_shape) {
        case 0:
            return "N";
            break;
        case 1:
            return "R";
            break;
        case 2:
            return "G";
            break;
        case 3:
            return "Y";
            break;
        case 4:
            return "B";
            break;
        }
    }

    // getters
    shape get_shape()
    {
        return this->_shape;
    }
    shape_color get_color()
    {
        return this->_color;
    }
    shape_node* get_next()
    {
        return this->next;
    }
    shape_node* get_next_shape()
    {
        return this->next_shape;
    }
    shape_node* get_next_color()
    {
        return this->next_color;
    }
    shape_node* get_prev_color()
    {
        return this->prev_color;
    }
    shape_node* get_prev_shape()
    {
        return this->prev_shape;
    }

    // setters
    void set__shape(shape v)
    {
        this->_shape = v;
    }
    void set__color(shape_color v)
    {
        this->_color = v;
    }
    void set_next(shape_node* v)
    {
        this->next = v;
    }
    void set_next_shape(shape_node* v)
    {
        this->next_shape = v;
    }
    void set_next_color(shape_node* v)
    {
        this->next_color = v;
    }
    void set_prev_color(shape_node* v)
    {
        this->prev_color = v;
    }
    void set_prev_shape(shape_node* v)
    {
        this->prev_shape = v;
    }
};



// realloc <- <cstdlib>


