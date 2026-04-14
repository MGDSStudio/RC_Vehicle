//
// Created by gorod on 14.04.2026.
//

#ifndef CMAKESFMLPROJECT_TOUCHPLACE_H
#define CMAKESFMLPROJECT_TOUCHPLACE_H


class TouchPlace
{

public:
    void setX(float x)
    {
        this->x = x;
    }

    void setY(float y)
    {
        this->y = y;
    }

    float getX()
    {
        return x;
    }

    float getY()
    {
        return y;
    }

private:
    float x;
    float y;
};


#endif //CMAKESFMLPROJECT_TOUCHPLACE_H