#include <iostream>
#include "piece.h"
using namespace std;

class shape_node
{
private:
    piece P;
    shape_node* next = NULL;//zr9a
    shape_node* next_shape = NULL;
    shape_node* next_color = NULL;
    shape_node* prev_color = NULL;
    shape_node* prev_shape = NULL;
    

public:
    int imp = 0;
    int icp = 0;
    int isp = 0;
    // constructur
    shape_node(shape_node *);
    shape_node(piece PI , shape_node*  , shape_node*  , shape_node* , shape_node*, shape_node* );

    // getters
   

        piece get_piece();

        shape_node* get_next();

        shape_node* get_next_shape();
        int get_imp();
        shape_node* get_next_color();

        shape_node* get_prev_color();

        shape_node* get_prev_shape();


        // setters
        void set_piece(piece v);

        void set_next(shape_node* v);

        void set_next_shape(shape_node* v);

        void set_next_color(shape_node* v);

        void set_prev_color(shape_node* v);

        void set_prev_shape(shape_node* v);

        void NodeToJson();
};
