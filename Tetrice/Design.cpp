#include "Design.h"
#include "raylib.h"

void Design::drawPiece(piece p) {
    Color raylibColor;
    switch (p.get_color()) {
    case Red:
        raylibColor = RED;
        break;
    case Green:
        raylibColor = GREEN;
        break;
    case Yellow:
        raylibColor = YELLOW;
        break;
    case Blue:
        raylibColor = BLUE;
        break;
    default:
        raylibColor = WHITE;
        break;
    }
    switch (p.get_shape()) {
    case Cercle:
        DrawCircle(static_cast<float>(p.get_X()), static_cast<float>(p.get_Y()), 20.0f, raylibColor);
        break;
    case Rhombus:
        DrawRectanglePro(Rectangle{ static_cast<float>(p.get_X()), static_cast<float>(p.get_Y()), 40.0f, 40.0f }, { 20.0f, 20.0f }, 45.0f, raylibColor);
        break;
    case Square:
        DrawRectangleRec(Rectangle{ static_cast<float>(p.get_X()), static_cast<float>(p.get_Y()), 40.0f, 40.0f }, raylibColor);
        break;
    case Triangle:
        DrawTriangle({ static_cast<float>(p.get_X()), static_cast<float>(p.get_Y()) }, { static_cast<float>(p.get_X()) + 40.0f, static_cast<float>(p.get_X()) }, { static_cast<float>(p.get_X()) + 20.0f, static_cast<float>(p.get_X()) - 35.0f }, raylibColor);
        break;
    default:
        break;
    }
}

Design::~Design()
{
    CloseWindow();

}

void Design::drawPlateau(Plateau* myP)
{
    shape_node* tempo = myP->get_head();
    for (int i = 0; i < myP->get_size(); i++) {
        piece* pieceTempo = new piece(tempo->get_piece().get_shape(), tempo->get_piece().get_color(),
            float(80.0f * (i + 1)), float(200.0f));
        drawPiece(*pieceTempo);
        tempo = tempo->get_next();
    }
}

Design::Design()
{
    screenHeight = 600;
    screenWidth = 1200;
    rotation = 45.0f;
    InitWindow(screenWidth, screenHeight, "Dessiner des formes");
    SetTargetFPS(60);
    Color colors[] = { BLUE, YELLOW, RED, GREEN };
}

void Design::render(Plateau* myP)
{
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        drawPlateau(myP);
        EndDrawing();
    }
}


