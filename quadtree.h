#ifndef QUADTREE_H
#define QUADTREE_H

#include <iostream>
template  <class T> struct FIZ {
enum Directions
{
    TopLeft,
    BottomLeft,
    TopRight,
    BottomRight,
    Nowhere
};

struct Point
{
    int x, y;
    Directions quadrant;
    Point() : x{0}, y{0}, quadrant{Nowhere} {}
    Point(int x_, int y_) : x{x_}, y{y_},  quadrant{Nowhere}
    {
        if (x <= 100/2 && y <= 100/2) {
            quadrant = TopLeft;
        } else if (x <= 100/2 && y > 100/2) {
            quadrant = BottomLeft;
        } else if (x >= 100/2 && y <= 100/2 ) {
            quadrant = TopRight;
        } else if (x >= 100/2 && y > 100/2) {
            quadrant = BottomRight;
        }
    };

    std::string toString() {
        char dat[100] = {0};
        sprintf(dat, "x:%d\ty:%d\tDIM:%d\r\n", x, y, (int)quadrant);
        return  std::string(dat);
    }
};

struct Dimension
{
    Point topLeft, bottomRight;

    Dimension(Point&& p1, Point&& p2) {
        topLeft = std::move(p1);
        bottomRight = std::move(p2);
    }

    Dimension() :topLeft{0,0}, bottomRight{0,0}{}


    std::string toString() {
        std::string full = topLeft.toString() + bottomRight.toString();
        return  full;
    }
};



struct QuadTree
{
    QuadTree* topLeft;
    QuadTree* bottomRight;
    QuadTree* topRight;
    QuadTree* bottomLeft;

    Dimension dim;
    QuadTree(Dimension&& dim_) : topLeft{0}, bottomRight{0}, topRight{0},bottomLeft{0}
    {
        dim = std::move(dim_);
    }



    void insert(const Point& p1)
    {
        if (p1.quadrant == Nowhere)
            return;

        if (::abs(dim.topLeft.x-dim.bottomRight.x) <= 1 &&
            ::abs(dim.bottomRight.y-dim.bottomRight.y) <= 1 ) {
            return;
        }


        Directions d = p1.quadrant;
        switch (d) {
        case TopLeft:
            if (!topLeft) {
                topLeft = new QuadTree(
                    Dimension(Point(dim.topLeft.x, dim.topLeft.y),
                              Point((dim.topLeft.x+dim.bottomRight.x)/2,
                                    (dim.topLeft.y+dim.bottomRight.y)/2)));
            }
            topLeft->insert(p1);
            break;
        case TopRight:
            break;
        case BottomLeft:
            if (!bottomLeft) {
                bottomLeft = new QuadTree(
                    Dimension(
                        Point(dim.topLeft.x, (dim.topLeft.y+dim.bottomRight.y)/2),
                        Point((dim.topLeft.x+dim.bottomRight.x/2), dim.bottomRight.y)));
            }
            bottomLeft->insert(p1);
            break;
        case BottomRight:
            break;
        default:
            break;
        }
    }
    };
};
#endif // QUADTREE_H
