#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Rectange class
class Rectangle
{
private:
    // coordinates of bottom left corner
    int leftX_;
    int bottomY_;

    // dimensions
    int width_;
    int height_;

public:
    Rectangle() :
        leftX_(0),
        bottomY_(0),
        width_(0),
        height_(0)
    {
    }

    Rectangle(int leftX, int bottomY, int width, int height) :
        leftX_(leftX),
        bottomY_(bottomY),
        width_(width),
        height_(height)
    {
    }

    int getLeftX() const
    {
        return  leftX_;
    }

    int getBottomY() const
    {
        return  bottomY_;
    }

    int getWidth() const
    {
        return  width_;
    }

    int getHeight() const
    {
        return  height_;
    }

    bool operator==(const Rectangle& other) const
    {
        return
            leftX_ == other.leftX_
            && bottomY_ == other.bottomY_
            && width_ == other.width_
            && height_ == other.height_;
    }

    bool operator!=(const Rectangle& other) const
    {
        return !(*this == other);
    }
};

// Complete Consumption - Check if A consumes B
bool checkConsumption(Rectangle a, Rectangle b)
{
    if ((b.getLeftX() >= a.getLeftX() && b.getLeftX() + b.getWidth() <= a.getLeftX() + a.getWidth()) && (b.getBottomY() >= a.getBottomY() && b.getBottomY() + b.getHeight() <= a.getBottomY() + a.getHeight()))
        return true;
    return false;
}

// Partial Overlap - Check if A and B partially overlap - treats B as the smaller rectangle
bool checkPartialOverlap(Rectangle a, Rectangle b, int &intersectLeftX, int &intersectBottomY, int &intersectWidth, int &intersectHeight)
{
    if (b.getLeftX() >= a.getLeftX() && b.getLeftX() <= a.getLeftX() + a.getWidth())
    {
        intersectLeftX = b.getLeftX();
        intersectBottomY = 0;
        intersectWidth = a.getLeftX() + a.getWidth() - b.getLeftX();
        intersectHeight = 0;

        if (b.getBottomY() >= a.getBottomY() && b.getBottomY() <= a.getBottomY() + a.getHeight())
        {
            intersectHeight = a.getBottomY() + a.getHeight() - b.getBottomY();
            intersectBottomY = b.getBottomY();
        }
        else
        {
            intersectHeight = b.getBottomY() + b.getHeight() - a.getBottomY();
            intersectBottomY = b.getBottomY() + b.getHeight() - intersectHeight;
        }

        return true;
    }
    return false;
}

Rectangle getIntersection(Rectangle a, Rectangle b)
{
    // Perfect Overlap - Perfect Intersection
    if (a == b)
        return Rectangle(a.getLeftX(), a.getBottomY(), a.getWidth(), a.getHeight());
   
    // No Overlap - Zero Intersection
    else if (abs(a.getLeftX() - b.getLeftX()) > max(a.getWidth(), b.getWidth()) || abs(a.getBottomY() - b.getBottomY()) > max(a.getHeight(), b.getHeight()))
        return Rectangle(a.getLeftX(), a.getBottomY(), -1, -1);

    // A consumes B -> Intersection = B
    else if (checkConsumption(a, b))
        return b;

    // B consumes A -> Intersection = A
    else if (checkConsumption(b, a))
        return a;
    
    // Partial Overlap
    else
    {
        int intersectLeftX = 0;
        int intersectBottomY = 0;
        int intersectWidth = 0;
        int intersectHeight = 0;

        if (checkPartialOverlap(a, b, intersectLeftX, intersectBottomY, intersectWidth, intersectHeight) || checkPartialOverlap(b, a, intersectLeftX, intersectBottomY, intersectWidth, intersectHeight))
            return Rectangle(intersectLeftX, intersectBottomY, intersectWidth, intersectHeight);
    }
}

int main()
{
    Rectangle first = Rectangle(-2, 0, 6, 9);
    Rectangle second = Rectangle(0, 0, 4, 7);
    Rectangle intersection = getIntersection(first, second);

    if (intersection.getWidth() < 0 || intersection.getHeight() < 0)
        cout << "Rectangles don't intersect" << endl;
    else
    {
        cout << "Intersection Origin: (" << intersection.getLeftX() << ", " << intersection.getBottomY() << ")" << endl;
        cout << "Intersection Width: " << intersection.getWidth() << endl;
        cout << "Intersection Height: " << intersection.getHeight() << endl;
    }

    return 0;
}