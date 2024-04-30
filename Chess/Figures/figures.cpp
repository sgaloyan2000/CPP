#include "figures.h"

void pawn::moves() {
    std::cout << "If pawn is on start position, can move forward 2 steps." << std::endl
              << "If pawn is in the opposite border of board, it can transform to any other figure except king and itself"
              << std::endl
              << "Otherwise pawns can move only 1 step forward" << std::endl;
}

void rook::moves() {
    std::cout << "Rooks can move on both horizontal and vertical lines" << std::endl;
}

void knight::moves() {
    std::cout << "Knights moves are described like L-shape" << std::endl;
}

void bishop::moves() {
    std::cout << "Bishops can move diagonally" << std::endl;
}

void queen::moves() {
    std::cout << "Queens have all abilities of rooks and bishops" << std::endl;
}

void king::moves() {
    std::cout << "Kings are able to move one step to all possible directions" << std::endl;
}
