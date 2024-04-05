#pragma once
#include "shape_node.h"
class Plateau
{
private:
	static const int min_supp = 3;
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
	void show(int);
	
	//manipulation du liste
	void inserer_right(piece P);
	void inserer_left(piece P);
	void inserer_right_shapes(Plateau* p, piece P);
	void inserer_left_shapes(Plateau* p, piece P);
	void inserer_left_colors(Plateau* p, piece P);
	void inserer_right_colors(Plateau* p, piece P);
	void evaluate_plate(Plateau* colors, Plateau* shapes);

	void supprimer3_left();
	void supprimer3_right();
	void supprimer_left();
	void supprimer_right();
	void afficher(bool dis_last);

	//piece supprimer();

};

