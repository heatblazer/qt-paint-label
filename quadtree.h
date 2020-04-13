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

    struct Node
    {
        T userData;
        Point coordinates;

        Node(T&& d, Point&& p)
        {
            userData = std::move(d);
            coordinates = std::move(p);
        }

    };


    struct QuadTree
    {
        QuadTree* topLeft;
        QuadTree* bottomRight;
        QuadTree* topRight;
        QuadTree* bottomLeft;
        Dimension dim;
        Node* node;

        QuadTree(Dimension&& dim_) : topLeft{0}, bottomRight{0}, topRight{0},bottomLeft{0}
        {
            dim = std::move(dim_);
        }

        inline bool inBoundary(const Point& p1) {
            return  p1.x >= dim.topLeft.x &&
                   p1.x <= dim.bottomRight.x &&
                   p1.y >= dim.topLeft.y &&
                   p1.y <= dim.bottomRight.y;
        }


        void insert(Node* n)
        {
            if (!n) return;
            if (n->coordinates.x < 0 || n->coordinates.y < 0) return;

            if (::abs(dim.topLeft.x-dim.bottomRight.x) <= 1 &&
                ::abs(dim.topLeft.y-dim.bottomRight.y) <= 1 )
            {
                node = n;
                return;
            }
            if (!inBoundary(n->coordinates))
                return;

            int centrex = (int)(dim.topLeft.x + dim.bottomRight.x) /2;
            int centrey = (int)(dim.topLeft.y + dim.bottomRight.y) /2 ;
            Point p1 (n->coordinates.x, n->coordinates.y);

            Directions d = Nowhere;
            if (p1.x <=  centrex && p1.y <= centrey )
                p1.quadrant = d = TopLeft;
            else if (p1.x >= centrex && p1.y >= centrey)
                p1.quadrant = d = BottomRight;
            else if (p1.x >= centrex && p1.y <= centrey)
                p1.quadrant = d = TopRight;
            else if (p1.x <= centrex && p1.y >= centrey)
                p1.quadrant = d =  BottomLeft;

            switch (d) {
            case TopLeft:
                if (!topLeft) {
                    topLeft = new QuadTree(
                        Dimension(Point(dim.topLeft.x, dim.topLeft.y),
                                  Point((dim.topLeft.x+dim.bottomRight.x)/2,
                                        (dim.topLeft.y+dim.bottomRight.y)/2)));
                }
                topLeft->insert(n);
                break;
            case TopRight:
                if (!topRight) {
                    topRight = new QuadTree(
                        Dimension(Point((dim.topLeft.x+dim.bottomRight.x)/2, dim.topLeft.y),
                                  Point(Point(dim.bottomRight.x,
                                              (dim.topLeft.y+dim.bottomRight.y)/2))));
                }
                topRight->insert(n);
                break;
            case BottomLeft:
                if (!bottomLeft) {
                    bottomLeft = new QuadTree(
                        Dimension(
                            Point(dim.topLeft.x, (dim.topLeft.y+dim.bottomRight.y)/2),
                            Point((dim.topLeft.x+dim.bottomRight.x/2), dim.bottomRight.y)));
                }
                bottomLeft->insert(n);
                break;
            case BottomRight:
                if (!bottomRight) {
                    bottomRight = new QuadTree(
                        Dimension(Point((dim.topLeft.x + dim.bottomRight.x)/2,
                                        (dim.topLeft.y + dim.bottomRight.y)/2),
                                  Point(dim.bottomRight.x, dim.bottomRight.y)));
                    bottomRight->insert(n);
                }
                break;
            case Nowhere:
            default:
                break;
            }
        }


#if 0
        void insert(Point p1)
        {
            if (p1.x < 0 || p1.y < 0) return;

            if (::abs(dim.topLeft.x-dim.bottomRight.x) <= 1 &&
                ::abs(dim.topLeft.y-dim.bottomRight.y) <= 1 )
                return;

            if (!inBoundary(p1))
                return;

            int centrex = (int)(dim.topLeft.x + dim.bottomRight.x) /2;
            int centrey = (int)(dim.topLeft.y + dim.bottomRight.y) /2 ;

            Directions d = Nowhere;
            if (p1.x <=  centrex && p1.y <= centrey )
                p1.quadrant = d = TopLeft;
            else if (p1.x >= centrex && p1.y >= centrey)
                p1.quadrant = d = BottomRight;
            else if (p1.x >= centrex && p1.y <= centrey)
                p1.quadrant = d = TopRight;
            else if (p1.x <= centrex && p1.y >= centrey)
                p1.quadrant = d =  BottomLeft;

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
                if (!topRight) {
                    topRight = new QuadTree(
                        Dimension(Point((dim.topLeft.x+dim.bottomRight.x)/2, dim.topLeft.y),
                                  Point(Point(dim.bottomRight.x,
                                              (dim.topLeft.y+dim.bottomRight.y)/2))));
                }
                topRight->insert(p1);
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
                if (!bottomRight) {
                    bottomRight = new QuadTree(
                        Dimension(Point((dim.topLeft.x + dim.bottomRight.x)/2,
                                        (dim.topLeft.y + dim.bottomRight.y)/2),
                                  Point(dim.bottomRight.x, dim.bottomRight.y)));
                    bottomRight->insert(p1);
                }
                break;
            case Nowhere:
            default:
                break;
            }
        }
#endif
    };

};
#endif // QUADTREE_H
