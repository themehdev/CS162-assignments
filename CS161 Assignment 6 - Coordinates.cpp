#include <iostream>
#include <cmath>
#include <limits.h>
#include <sstream>
using namespace std;

class Point {
    private: 
    double x, y;
    
    public:
    Point(double x = 0, double y = 0){
        this->x = x;
        this->y = y;
    }

    double getX() { return x; }
    double getY() { return y; }

    void setPos (double x = 0, double y = 0) { 
        this->x = x; 
        this->y = y; 
    }

    string toString() { return "(" + to_string(x) + ", " + to_string(y) + ")"; }

    double getDistance(Point other) {
        double dx = x - other.getX();
        double dy = y - other.getY();
        return sqrt(dx * dx + dy * dy);
    }

    double getSlope(Point other) {
        double dx = x - other.getX();
        double dy = y - other.getY();
        if (dx == 0) 
            return INT_MAX; // slope is undefined for vertical lines
        return dy/dx;
    }

    int getQuadrant(){
        if(x == 0 || y == 0) return 0;
        if(x > 0 && y > 0) return 1;
        if(x < 0 && y > 0) return 2;
        if(x < 0 && y < 0) return 3;
        return 4;
    }


};

int main() {
    int x1, y1, x2, y2 = 0;
    Point p1(x1, y1);
    Point p2(x2, y2);
    bool continuing = true;
    while (continuing) {
        cout << "Enter the X and Y values for point 1 (separated by a space): ";
        cin >> x1 >> y1;
        p1.setPos(x1, y1);
        cout << "Enter the X and Y values for point 2 (separated by a space): ";
        cin >> x2 >> y2;
        p2.setPos(x2, y2);

        cout << "Point 1: " << p1.toString() << ((p1.getQuadrant() == 0) ? " is not in a quadrant" : (" is in quadrant " + to_string(p1.getQuadrant()))) << endl;
        cout << "Point 2: " << p2.toString() << ((p2.getQuadrant() == 0) ? " is not in a quadrant" : (" is in quadrant " + to_string(p2.getQuadrant()))) << endl;

        cout << "The distance between the points is " << p1.getDistance(p2) << endl;

        cout << "The slope of the line passing through them is " << p1.getSlope(p2) << endl;

        cout << "Would you like to continue? (Y/N)? ";
        string input;
        cin >> input;
        while (input != "Y" && input != "N"){
            cout << "Please respond with Y or N: ";
            cin >> input;
        }

        continuing = (input == "Y");
    }
    return 0;
}
