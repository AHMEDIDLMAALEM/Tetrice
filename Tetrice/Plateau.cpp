#include "Plateau.h"

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
		new_ptr->set_next_shape(this->get_head());
		new_ptr->set_prev_shape(this->get_tail());


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
		new_ptr->set_next_color(this->get_head());
		new_ptr->set_prev_color(this->get_tail());

		
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
	shape_node* new_ptr = p->get_tail();
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
	shape_node* new_ptr = p->get_tail();
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

void Plateau::supprimer3_left()
{
	
	for (int i = 0; i < 3; i++) {
		supprimer_left();
	}

}

void Plateau::supprimer3_right()
{
	
	for (int i = 0; i < 3; i++) {
		supprimer_right();
	}
	
}

void Plateau::supprimer_left()
{
	if (size == 0) {
		std::cout << "la liste est vise" << std::endl;

	}
	else {
		shape_node* supp=head;
		tail->set_next(supp->get_next());
		head = head->get_next();
		supp->set_next(nullptr);
		size--;
		//delete(supp);
	}
}

void Plateau::supprimer_right()
{
	if (size == 0) {
		std::cout << "la liste est vise" << std::endl;

	}
	else {
		shape_node* supp = nullptr;
		shape_node *temp = head;
		for (int i = 0; i < size - 2; i++) {
			temp = temp->get_next();
		}
			tail = temp;
			supp = temp->get_next();
			temp->set_next(head);
			supp->set_next(nullptr);
			size--;
			//delete(supp);

		
	
	}


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

