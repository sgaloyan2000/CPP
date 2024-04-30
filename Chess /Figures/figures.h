#ifndef CHESS_H
#define CHESS_H

#include <iostream>

class figure {
public:
    figure() {}
    figure(int input_color) : color(input_color) {}
    virtual ~figure() {}
    virtual void moves() = 0;

protected:
    int color;
};

class pawn : public figure {
public:
    pawn() {}
    pawn(int input_color) : figure(input_color) {}
    virtual ~pawn() {}
    virtual void moves();
};

class rook : public figure {
public:
    rook() {}
    rook(int input_color) : figure(input_color) {}
    virtual ~rook() {}
    virtual void moves();
};

class knight : public figure {
public:
    knight() {}
    knight(int input_color) : figure(input_color) {}
    virtual ~knight() {}
    virtual void moves();
};

class bishop : public figure {
public:
    bishop() {}
    bishop(int input_color) : figure(input_color) {}
    virtual ~bishop() {}
    virtual void moves();
};

class queen : public figure {
public:
    queen() {}
    queen(int input_color) : figure(input_color) {}
    virtual ~queen() {}
    virtual void moves();
};

class king : public figure {
public:
    king() {}
    king(int input_color) : figure(input_color) {}
    virtual ~king() {}
    virtual void moves();
};

#endif // CHESS_H
