#include "Plateau.h"
#include <conio.h>

Plateau::Plateau()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

Plateau::~Plateau()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

shape_node* Plateau::get_head()
{
	return head;
}

shape_node* Plateau::get_tail()
{
	return tail;
}

int Plateau::get_size() const
{
	return size;
}

void Plateau::set_head(shape_node* tete)
{
	head = tete;
}

void Plateau::set_tail(shape_node* queue)
{
	tail = queue;
}

void Plateau::inserer_right(piece P)
{
	shape_node* NEW = new shape_node(P,NULL,NULL,NULL,NULL,NULL);

	if (size == 0) {
		head = NEW;
		tail = NEW;
		NEW->set_next(NEW);
	}
	else {
		NEW->set_next(head);
		tail->set_next(NEW);
		tail = NEW;
	}
	size++;
}
void Plateau::inserer_right_shapes(Plateau * p,piece P)
{
	shape_node* new_ptr = p->get_tail();
	// link the main plate tail (new piece)
	// to tail by prev_col
	// to head by next_col
	if (this->size == 0)
	{
		this->head = new_ptr;
		this->tail = new_ptr;


	}
	else
	{
		new_ptr->set_next_shape(this->get_head());
		new_ptr->set_prev_shape(this->get_tail());
		this->head->set_prev_shape(new_ptr);
		this->tail->set_next_shape(new_ptr);
		this->tail = new_ptr;
	}
	size++;
	
}
void Plateau::inserer_right_colors(Plateau* p, piece P) 
{
	shape_node* new_ptr = p->get_tail();
	// link the main plate tail (new piece)
	// to tail by prev_col
	// to head by next_col
	if (this->size == 0)
	{
		this->head = new_ptr;
		this->tail = new_ptr;
		/*new_ptr->set_next_color(this->get_head());
		new_ptr->set_prev_color(this->get_tail());*/

		
	}
	else
	{
		new_ptr->set_next_color(this->get_head());
		new_ptr->set_prev_color(this->get_tail());
		this->head->set_prev_color(new_ptr);
		this->tail->set_next_color(new_ptr);
		this->tail = new_ptr;
	}
	size++;

}
void Plateau::inserer_left_shapes(Plateau* p, piece P)
{
	shape_node* new_ptr = p->get_head();
	// link the main plate tail (new piece)
	// to tail by prev_col
	// to head by next_col
	if (this->size == 0)
	{
		this->head = new_ptr;
		this->tail = new_ptr;
		new_ptr->set_next_shape(this->get_head());
		new_ptr->set_prev_shape(this->get_tail());


	}
	else
	{
		new_ptr->set_next_shape(this->get_head());
		new_ptr->set_prev_shape(this->get_tail());
		this->head->set_prev_shape(new_ptr);
		this->tail->set_next_shape(new_ptr);
		this->head = new_ptr;
	}
	size++;
}
void Plateau::inserer_left_colors(Plateau* p, piece P)
{
	shape_node* new_ptr = p->get_head();
	// link the main plate tail (new piece)
	// to tail by prev_col
	// to head by next_col
	if (this->size == 0)
	{
		this->head = new_ptr;
		this->tail = new_ptr;
		new_ptr->set_next_color(this->get_head());
		new_ptr->set_prev_color(this->get_tail());

	}
	else
	{
		new_ptr->set_next_color(this->get_head());
		new_ptr->set_prev_color(this->get_tail());
		this->head->set_prev_color(new_ptr);
		this->tail->set_next_color(new_ptr);
		this->head = new_ptr;
	}
	size++;
}

void Plateau::inserer_left(piece P)
{
	shape_node* NEW = new shape_node(P, NULL, NULL, NULL, NULL, NULL);

	if (size == 0) {
		head = NEW;
		tail = NEW;
		NEW->set_next(NEW);
	}
	else {
		NEW->set_next(head);
		tail->set_next(NEW);

		head = NEW;
	}
	size++;
}

int Plateau::supprimer3_left(Plateau(*color)[4], Plateau(*shape)[4])
{
	
	if (this->get_size() > 2)
	{
		// verify delatbility
		shape_node* tmp = this->get_head();

		if ((tmp->get_next() == tmp->get_next_color() && tmp->get_next()->get_next() == tmp->get_next()->get_next_color()) && (tmp->get_next() == tmp->get_next_shape() && tmp->get_next()->get_next() == tmp->get_next()->get_next_shape()))
		{
			for (int i = 0; i < 3; i++) {
				supprimer_left(&((*color)[static_cast<int>(this->get_head()->get_piece().get_color()) - 1]), &((*shape)[static_cast<int>(this->get_head()->get_piece().get_shape()) - 1]));
			}
			return 50;
		}
		if ((tmp->get_next() == tmp->get_next_color() && tmp->get_next()->get_next() == tmp->get_next()->get_next_color() ) || (tmp->get_next() == tmp->get_next_shape() && tmp->get_next()->get_next() == tmp->get_next()->get_next_shape()))
		{
			for (int i = 0; i < 3; i++) {
				Plateau* c = &((*color)[static_cast<int>(this->get_head()->get_piece().get_color()) - 1]);
				Plateau* s = &((*shape)[static_cast<int>(this->get_head()->get_piece().get_shape()) - 1]);
				supprimer_left(c, s);
			}
			return 10;
		}

	}
	return 0;

}

void show(int tables) {
	shape_node* tmp;
	//switch 
}

void Plateau::evaluate_plate(Plateau* colors, Plateau* shapes) {
	shape_node* pos = this->head;
	while (pos != this->tail)
	{
		int max_streak_color = 0 ,max_streak_shape = 0;
		int streak_color = 0, streak_shape = 0;
		shape_node* tmp_c = pos;
		while (tmp_c->get_piece().get_color() == tmp_c->get_next()->get_piece().get_color()) {
			streak_color++;
			tmp_c = tmp_c->get_next();
		}
		shape_node* tmp_s = pos;
		while (tmp_s->get_piece().get_color() == tmp_s->get_next()->get_piece().get_color()) {
			streak_shape++;
			tmp_s = tmp_s->get_next();
		}
		if (streak_color >= this->min_supp || streak_shape >= this->min_supp)
		{
			//(streak_color >= streak_shape) ? delete() : ;
		}


		
	}

}

int Plateau::supprimer3_right(Plateau(*color)[4], Plateau(*shape)[4])
{
	if (this->get_size() > 2 )
	{
		// verify delatbility
		shape_node* tmp = this->get_tail();
		if ((tmp == tmp->get_prev_color()->get_next() && tmp->get_prev_color() == tmp->get_prev_color()->get_prev_color()->get_next()) && (tmp == tmp->get_prev_shape()->get_next() && tmp->get_prev_shape() == tmp->get_prev_shape()->get_prev_shape()->get_next()))
		{
			for (int i = 0; i < 3; i++) {
				supprimer_right(&((*color)[static_cast<int>(this->get_tail()->get_piece().get_color())-1]), &((*shape)[static_cast<int>(this->get_tail()->get_piece().get_shape())-1]));
			}
			return 50;
		}
		if ((tmp == tmp->get_prev_color()->get_next() && tmp->get_prev_color() == tmp->get_prev_color()->get_prev_color()->get_next()) || (tmp == tmp->get_prev_shape()->get_next() && tmp->get_prev_shape() == tmp->get_prev_shape()->get_prev_shape()->get_next()))
		{
			for (int i = 0; i < 3; i++) {
				Plateau* c = &((*color)[static_cast<int>(this->get_tail()->get_piece().get_color())-1]);
				Plateau* s = &((*shape)[static_cast<int>(this->get_tail()->get_piece().get_shape())-1]);
				supprimer_right(c,s);
			}
			return 10;
		}
		
	}
	return 0;
	
}

void Plateau::delete_node()
{
	//head
	////color
	////shape

	//tail
	////color
	////shape
}

void Plateau::decalage_shapes(shape p, Plateau HS[4], Plateau HC[4])
{
	if (size != 0) {
		int i = (int)(p - 1);
		shape_node* temp = HS[i].get_head(), * inter = HS[i].get_head();

		piece p = temp->get_piece();
		do {
			temp = temp->get_next_shape();
			inter->set_piece(temp->get_piece());
			inter = temp;

		} while (temp != HS[i].get_head());
		HS[i].get_tail()->set_piece(p);

		for (int k = 0; k < 4; k++) {
			HC[k].set_head(nullptr);
			HC[k].set_tail(nullptr);
			HC[k].set_size(0);

		}

		temp = head;
		for (int k = 0; k < size; k++) {
			int i = ((int)temp->get_piece().get_color() - 1);
			HC[i].inserer_right_colors(this ,temp->get_piece());
			temp = temp->get_next();
		}
	}
}

void Plateau::decalage_colors(shape_color p, Plateau HS[4], Plateau HC[4])
{
	if (size != 0) {
		int i = (int)(p - 1);
		shape_node* temp = HC[i].get_head(), * inter = HC[i].get_head();

		piece p = temp->get_piece();
		do {
			temp = temp->get_next_shape();
			inter->set_piece(temp->get_piece());
			inter = temp;

		} while (temp != HS[i].get_head());
		HC[i].get_tail()->set_piece(p);

		for (int k = 0; k < 4; k++) {
			HS[k].set_head(nullptr);
			HS[k].set_tail(nullptr);
			HS[k].set_size(0);

		}

		temp = head;
		for (int k = 0; k < size; k++) {
			int i = ((int)temp->get_piece().get_color() - 1);
			HS[i].inserer_right_shapes(this, temp->get_piece());
			temp = temp->get_next();
		}
	}
}

void Plateau::supprimer_left(Plateau* color, Plateau* shape)
{
	// delete trace from main plate
	shape_node* supp=head;
	if (size == 1) {
		head = nullptr;
		tail = nullptr;
	}
	else {
		head = head->get_next();
		tail->set_next(head);
	}
	size--;

	// delete trace from color plate
	if (color->get_size() == 1) {
		color->set_head(nullptr);
		color->set_tail(nullptr);
	}
	else {
		color->get_tail()->set_next_color(color->get_head()->get_next_color());
		color->set_head(color->get_head()->get_next_color());
		color->get_head()->set_prev_color(color->get_tail());
	}
	color->set_size(color->get_size()-1);

	// delete trace from shape plate
	if (shape->get_size() == 1) {
		shape->set_head(nullptr);
		shape->set_tail(nullptr);
	}
	else {
		shape->get_tail()->set_next_shape(shape->get_head()->get_next_shape());
		shape->set_head(shape->get_head()->get_next_shape());
		shape->get_head()->set_prev_shape(shape->get_tail());
	}
	shape->set_size(shape->get_size() - 1);
	delete supp;
}

void Plateau::supprimer_right(Plateau* color, Plateau* shape)
{
	// delete trace from main plate
	shape_node* supp = tail;
	if (size == 1) {
		head = nullptr;
		tail = nullptr;
	}
	else {
		shape_node* prv = tail->get_prev_color();
		while (prv->get_next() != tail) {
			prv = prv->get_next();
		}
		tail = prv;
		tail->set_next(head);
	}
	size--;

	// delete trace from color plate
	if (color->get_size() == 1) {
		color->set_head(nullptr);
		color->set_tail(nullptr);
	}
	else {
		color->set_tail(supp->get_prev_color());
		color->get_tail()->set_next_color(supp->get_next_color());
		color->get_head()->set_prev_color(color->get_tail());
	}
	color->set_size(color->get_size() - 1);

	// delete trace from shape plate
	if (shape->get_size() == 1) {
		shape->set_head(nullptr);
		shape->set_tail(nullptr);
	}
	else {
		shape->set_tail(supp->get_prev_shape());
		shape->get_tail()->set_next_shape(supp->get_next_shape());
		shape->get_head()->set_prev_shape(shape->get_tail());
	}
	shape->set_size(shape->get_size() - 1);
	delete supp;


}

void Plateau::afficher(bool dis_last = false)
{
	shape_node *temp=head;
	for (int i = 0; i < size; i++) {
		if (dis_last && tail == temp)
		{
			cout << " -> ";
		}
		temp->get_piece().afficher();
		temp = temp->get_next();
	}
}
void Plateau::set_size(int s) {
	this->size = s;
}

