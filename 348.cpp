#include <iostream>
#include <fstream>

using namespace std;

struct Point
{
    int x;
    int y;
};

bool Intersect(Point p1, Point q1, Point p2, Point q2)
{
    int orientation1 = (q1.y - p1.y) * (p2.x - q1.x) - (q1.x - p1.x) * (p2.y - q1.y);
    int orientation2 = (q1.y - p1.y) * (q2.x - q1.x) - (q1.x - p1.x) * (q2.y - q1.y);
    int orientation3 = (q2.y - p2.y) * (p1.x - q2.x) - (q2.x - p2.x) * (p1.y - q2.y);
    int orientation4 = (q2.y - p2.y) * (q1.x - q2.x) - (q2.x - p2.x) * (q1.y - q2.y);

    if (orientation1 * orientation2 < 0 && orientation3 * orientation4 < 0)
    {
        return true;
    }

    if (orientation1 == 0 && ((p2.x <= p1.x && p1.x <= q2.x) || (q2.x <= p1.x && p1.x <= p2.x)))
    {
        return true;
    }

    if (orientation2 == 0 && ((p2.x <= q1.x && q1.x <= q2.x) || (q2.x <= q1.x && q1.x <= p2.x)))
    {
        return true;
    }

    if (orientation3 == 0 && ((p1.x <= p2.x && p2.x <= q1.x) || (q1.x <= p2.x && p2.x <= p1.x)))
    {
        return true;
    }

    if (orientation4 == 0 && ((p1.x <= q2.x && q2.x <= q1.x) || (q1.x <= q2.x && q2.x <= p1.x)))
    {
        return true;
    }

    return false;
}

int main()
{
    ifstream input;
    input.open("348(input).txt");

    ofstream output;
    output.open("348(output).txt");

    Point p1, q1, p2, q2;

    input >> p1.x >> p1.y >> q1.x >> q1.y;
    input >> p2.x >> p2.y >> q2.x >> q2.y;

    if (Intersect(p1, q1, p2, q2))
    {
        output << "Yes" << endl;
    }
    else
    {
        output << "No" << endl;
    }

    input.close();
    output.close();

    return 0;
}
