

#include<conio.h>
#include "Game.h"
static bool s_finished = false;
// Function to be executed in a separate thread
//void threadFunction() {
//    int i = 0;
//    while (!s_finished) {
//        if (!(i % 10))
//            system("cls");
//        std::cout << "*";
//        std::this_thread::sleep_for(std::chrono::milliseconds(800));
//        
//        //std::this_thread::sleep_for()
//        i++;
//
//    }
//    std::cout << "hi from thread ";
//}
// g++ -o myprogram main.cpp -lpthread

int main() {

    
     Game g;
    _getch();
    // Create a new thread and pass the function to be executed
    //std::thread t(threadFunction);%
    //char choice = _getch();
    //if (choice == 'p')
    //{
    //    s_finished = true;
    //}

    //// Wait for the thread to finish execution
    //t.join();

    //std::cout << "Hello from main!\n";


   // Plateau L, HS[4], HC[4];
   // piece h(Cercle, Red);
   // piece a(Triangle, Yellow);
   // piece b(Rhombus, Red);
   // piece c(Square, Blue);
   // piece d(Triangle, Green);
   // piece e(Cercle, Red);
   // piece f(Rhombus, Blue);
   // piece g(Cercle, Red);

   // L.inserer_left(a);
   //// /*HC[(int)a.get_color()-1].inserer_left_colors(&L, a);
   //// HS[(int)a.get_shape()-1].inserer_left_shapes(&L, a);*/

   // L.inserer_left(b);
   //// /*HC[(int)b.get_color() - 1].inserer_left_colors(&L, b);
   //// HS[(int)b.get_shape() - 1].inserer_left_shapes(&L, b);*/
   // L.inserer_left(c);
   //// /*HC[(int)c.get_color() - 1].inserer_left_colors(&L, c);
   //// HS[(int)c.get_shape() - 1].inserer_left_shapes(&L, c);*/
   // L.inserer_left(d);
   //// /*HC[(int)d.get_color() - 1].inserer_left_colors(&L, d);
   //// HS[(int)d.get_shape() - 1].inserer_left_shapes(&L, d);*/

   // L.inserer_left(e);
   /////* HC[(int)e.get_color() - 1].inserer_left_colors(&L, e);
   //// HS[(int)e.get_shape() - 1].inserer_left_shapes(&L, e);*/
   // L.inserer_left(f);
   //// /*HC[(int)f.get_color() - 1].inserer_left_colors(&L, f);
   //// HS[(int)f.get_shape() - 1].inserer_left_shapes(&L, f);*/
   // L.inserer_left(g);
   /////* HC[(int)g.get_color() - 1].inserer_left_colors(&L, g);
   //// HS[(int)g.get_shape() - 1].inserer_left_shapes(&L, g);*/
   // L.inserer_left(h);
   // L.afficher(false);
   // std::cout << std::endl;
   // std::cout<<L.PlateauToJson();
   // /*HC[(int)h.get_color() - 1].inserer_left_colors(&L, h);
   // HS[(int)h.get_shape() - 1].inserer_left_shapes(&L, h);*/
   // shape_node* temp = L.get_head();
   // for (int i = 0; i < L.get_size(); i++) {
   //     int k = (int)temp->get_piece().get_color()-1, j = (int)temp->get_piece().get_shape()-1;
   //     HS[j].inserer_right_shapes(&L, temp->get_piece());
   //     HC[k].inserer_right_colors(&L, temp->get_piece());
   //     temp = temp->get_next();
   // }
   // L.afficher(false);
   // std::cout << std::endl;
   // L.decalage_shapes(Cercle, HS, HC);
   // L.afficher(false);
   // std::cout << std::endl;
   // for (int i = 0; i < 4; i++) {
   //     HS[i].afficher(false);
   //     std::cout << std::endl;

   // }
   // for (int i = 0; i < 4; i++) {
   //     HC[i].afficher(false);
   //     std::cout << std::endl;

   // }




    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
