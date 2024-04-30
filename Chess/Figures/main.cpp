#include "figures.h"
int main()
{
    figure* figures[6];
    figures[0] = new pawn(1);
    figures[1] = new rook(1);
    figures[2] = new knight(1);
    figures[3] = new bishop(1);
    figures[4] = new queen(1);
    figures[5] = new king(1);
    
    for(int i = 0; i < 6; ++i) {
        figures[i]->moves();
    }
    
    for(int i = 0; i < 6; ++i) {
        delete figures[i];
    }
    return 0;
}