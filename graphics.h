#ifndef GRAPHICS_H
#define GRAPHICS_H

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <math.h>

class Point {
protected:
    double x, y, z;

public:
    Point(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
    virtual void move(double dx, double dy, double dz) {
        x += dx;
        y += dy;
        z += dz;
    }
    virtual void print() const {
        std::cout << "Point(" << x << ", " << y << ", " << z << ")\n";
    }
    virtual ~Point() = default;
};

class Color {
protected:
    int r, g, b;

public:
    Color(int r = 0, int g = 0, int b = 0) : r(r), g(g), b(b) {}
    virtual void setColor(int nr, int ng, int nb) {
        r = nr;
        g = ng;
        b = nb;
    }
    virtual void printColor() const {
        std::cout << "Color(" << r << ", " << g << ", " << b << ")\n";
    }
    virtual ~Color() = default;
};

class Shape : public Point, public Color {
public:
    Shape(double x = 0, double y = 0, double z = 0, int r = 0, int g = 0, int b = 0) :
        Point(x, y, z), Color(r, g, b) {}
    virtual void resize(double factor) = 0;
    virtual void rotate(double angle) = 0;
    virtual void print() const override {
        Point::print();
        Color::printColor();
    }
    virtual ~Shape() = default;
};

class Parallelepiped : public Shape {
private:
    double length, width, height;

public:
    Parallelepiped(double x = 0, double y = 0, double z = 0, int r = 0, int g = 0, int b = 0,
        double length = 1, double width = 1, double height = 1) :
        Shape(x, y, z, r, g, b), length(length), width(width), height(height) {}

    void resize(double factor) override {
        length *= factor;
        width *= factor;
        height *= factor;
    }

    void rotate(double angle) override {
        // Simple rotation logic (not actual 3D rotation)
        double radians = angle * M_PI / 180.0;
        double new_x = x * cos(radians) - y * sin(radians);
        double new_y = x * sin(radians) + y * cos(radians);
        x = new_x;
        y = new_y;
    }

    void print() const override {
        Shape::print();
        std::cout << "Parallelepiped(length=" << length << ", width=" << width << ", height=" << height << ")\n";
    }
};

#endif // GRAPHICS_H
