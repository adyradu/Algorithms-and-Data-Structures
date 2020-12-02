#include<iostream>

struct Rect
{
	int x, y, width, height;
};

struct Line
{
	int a, b;
};

bool intersect_line(Line l1, Line l2, Line& res)
{
    if (l1.b < l2.a ||
        l2.b < l1.a)
    {
        return false;
    }
    else
    {
        res.a = std::max(l1.a, l2.a);
        res.b = std::min(l1.b, l2.b);
        return true;
    }
}

/// <summary>
/// Compute the intersection between two rectangles.
/// Rectangles are guaranteed to have all sides parallel X-axis and Y-axis.
/// If the rectangles do not intersect, return false.
/// The idea is to first see if the lines parallel to X-axis intersect.
/// Second, we can check if the lines parallel to Y-axis intersect.
/// If both these are true then we can calculate the intersection.
/// </summary>
/// <param name="r1"></param>
/// <param name="r2"></param>
/// <param name="result"></param>
/// <returns></returns>
bool intersect_rectangle(const Rect& r1, const Rect& r2, Rect result) {
    Rect result = { 0, 0, -1, -1 };
    Line intersectX = { 0, 0 };
    if (!intersect_line({ r1.x, r1.x + r1.width }, { r2.x, r2.x + r2.width }, intersectX))
    {
        return false;
    }

    Line intersectY = { 0, 0 };
    if (!intersect_line({ r1.y, r1.y + r1.height }, { r2.y, r2.y + r2.height }, intersectY))
    {
        return false;
    }

    result = { intersectX.a, intersectY.a, intersectX.b - intersectX.a, intersectY.b - intersectY.a };

    return true;
}

int main(void)
{
	return 0;
}