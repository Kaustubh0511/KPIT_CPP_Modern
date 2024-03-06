#include <iostream>
#include <cmath> // Include for mathematical functions
using namespace std;

#define line(msg) cout << "---------" #msg "----------\n";

class Polar
{
    double angle;
    double distance;

public:
    Polar(double angle, double distance) : angle(angle), distance(distance)
    {
    }

    // Public member functions to access private members
    double getAngle() const { return angle; }
    double getDistance() const { return distance; }

    // Declare Rect as a friend class to allow access to private members
    friend class Rect;
};

class Rect
{
    double x_cor;
    double y_cor;

public:
    Rect(const Polar &p) // Conversion Constructor
    {
        // Convert Polar coordinates to Rectangular coordinates
        x_cor = p.getDistance() * cos(p.getAngle());
        y_cor = p.getDistance() * sin(p.getAngle());
    }

    Rect &operator=(const Polar &p)
    {
        // Convert Polar coordinates to Rectangular coordinates
        x_cor = p.getDistance() * cos(p.getAngle());
        y_cor = p.getDistance() * sin(p.getAngle());
        return *this;
    }
    double getX()
    {
        return x_cor;
    }

    double getY()
    {
        return y_cor;
    }

    operator Polar() const
    {
        // Convert Rectangular coordinates to Polar coordinates
        double angle = atan2(y_cor, x_cor);
        double distance = sqrt(x_cor * x_cor + y_cor * y_cor);
        return Polar(angle, distance);
    }
};

int main()
{
    Polar p(90, 100);
    Rect r = p; // Conversion from Polar to Rect
    p = r;      // Conversion from Rect to Polar

    // Output the converted values
    cout << "x: " << r.getX() << ", y: " << r.getY() << endl;

    return 0;
}