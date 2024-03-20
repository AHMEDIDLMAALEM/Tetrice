#pragma once
#include "shape_node.h"
class Plateau
{
private:
	shape_node *head, *tail;
	int size;

public:
	Plateau();
	~Plateau();
	//getter:
	shape_node* get_head();
	shape_node* get_tail();
	int get_size() const;
	//setter
	void set_head(shape_node*);
	void set_tail(shape_node*);
	
	//manipulation du liste
	void inserer_right(piece P);
	void inserer_left(piece P);
	void inserer_right_shapes(Plateau* p, piece P);
	void inserer_left_shapes(Plateau* p, piece P);
	void inserer_left_colors(Plateau* p, piece P);
	void inserer_right_colors(Plateau* p, piece P);

	void supprimer3_left();
	void supprimer3_right();
	void supprimer_left();
	void supprimer_right();
	void afficher(bool dis_last);

	//piece supprimer();

};

