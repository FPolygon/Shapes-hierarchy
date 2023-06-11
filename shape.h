/*The given header file implements a hierarchy of shapes in C++. It defines a base class called "Shape" with x and y coordinates representing the position of a shape. The "Shape" class provides default and parameterized constructors, accessor and mutator functions for the coordinates, and a virtual function to print information about the shape. It also includes a virtual copy() function to create a copy of a shape. The header file then defines three derived classes: "Circle," "Rectangle," and "RightTriangle." These classes inherit from the "Shape" class and add their specific attributes such as radius for circles, width and height for rectangles, and base and height for right triangles. Each derived class provides its own constructors, accessor and mutator functions, and an overridden printShape() function. The header file allows users to create instances of different shapes, manipulate their properties, and retrieve information about them. It provides a flexible and extensible framework for working with shapes in an object-oriented manner.*/

#pragma once

using namespace std;

// Base class for all shapes
class Shape
{
protected:
    int x; // x-coordinate of the shape
    int y; // y-coordinate of the shape
    
public:
    
    // Constructors
    Shape(); // default constructor
    Shape(int x, int y); // constructor with x and y coordinates
    
    virtual ~Shape(); // destructor
    virtual Shape* copy(); // virtual copy function
    
    // Accessors
    int getX() const; // get x-coordinate of shape
    int getY() const; // get y-coordinate of shape
    
    // Mutators
    void setX(int); // set x-coordinate of shape
    void setY(int); // set y-coordinate of shape
    
    virtual void printShape() const; // virtual function to print information about the shape
};

// Default constructor for Shape
inline Shape::Shape()
{
    x = 0;
    y = 0;
}

// Constructor for Shape with x and y coordinates
inline Shape::Shape(int x, int y)
{
    this->x = x;
    this->y = y;
}

// Virtual destructor for Shape
Shape::~Shape()
{
    // No dynamic memory to delete
}

// Virtual copy function for Shape
inline Shape* Shape::copy()
{
    Shape* copy = new Shape(x, y);
    return copy;
}

// Accessor for x-coordinate of Shape
int Shape::getX() const
{
    return x;
}

// Accessor for y-coordinate of Shape
int Shape::getY() const
{
    return y;
}

// Mutator for x-coordinate of Shape
void Shape::setX(int x)
{
    this->x = x;
}

// Mutator for y-coordinate of Shape
void Shape::setY(int y)
{
    this->y = y;
}

// Virtual function to print information about the shape
void Shape::printShape() const
{
    cout << "Shape at x: " << x << ", y: " << y << endl;
}


// Circle class derived from Shape
class Circle : public Shape
{
private:
    int radius; // radius of the circle
    
public:
    
    // Constructors
    Circle(); // default constructor
    Circle(int r); // constructor with radius
    Circle(int x, int y, int r); // constructor with x and y coordinates, and radius
    
    // Destructor
    virtual ~Circle(); // virtual destructor
    
    virtual Circle* copy(); // virtual copy function
    
    // Accessor
    int getRadius() const; // get radius of the circle
    
    // Mutator
    void setRadius(int); // set radius of the circle
    
    virtual void printShape() const; // virtual function to print information about the circle
};

// Default constructor for Circle
inline Circle::Circle() : Shape(), radius(0) {
}

// Constructor for Circle with radius
inline Circle::Circle(int r) : Shape(), radius(r) {
}

// Constructor for Circle with x and y coordinates, and radius
inline Circle::Circle(int x, int y, int r) : Shape(x, y), radius(r) {
}

// Virtual destructor for Circle
Circle::~Circle()
{
    // No dynamic memory to delete
}

// Virtual copy function for Circle
Circle* Circle::copy() {
    Circle* newCircle = new Circle(*this);
    return newCircle;
}

// Accessor for radius of Circle
int Circle::getRadius() const
{
    return radius;
}


void Circle::setRadius(int radius)
{
    this->radius = radius;
}

void Circle::printShape() const
{
    cout << "Circle at x: " << x << ", y: " << y << ", radius: " << radius << endl;
}


// Rectangle class
class Rectangle : public Shape
{
private:
    int width;
    int height;
    
public:
    // Constructors
    Rectangle();
    Rectangle(int w, int h);
    Rectangle(int x, int y, int w, int h);
    
    // Destructor
    virtual ~Rectangle();
    virtual Rectangle* copy();
    
    // Accessors
    int getWidth() const;
    int getHeight() const;
    
    // Mutators
    void setWidth(int);
    void setHeight(int);
    
    // Overridden method
    virtual void printShape() const;
};

inline Rectangle::Rectangle() : Shape(), width(0), height(0) {
}

inline Rectangle::Rectangle(int w, int h) : Shape(), width(w), height(h) {
}

inline Rectangle::Rectangle(int x, int y, int w, int h) : Shape(x, y), width(w), height(h) {
}

Rectangle::~Rectangle()
{
    // No dynamic memory to delete
}

Rectangle* Rectangle::copy()
{
    Rectangle* newRectangle = new Rectangle(*this);
    return newRectangle;
}

int Rectangle::getWidth() const
{
    return width;
}

int Rectangle::getHeight() const
{
    return height;
}

void Rectangle::setWidth(int width)
{
    this->width = width;
}

void Rectangle::setHeight(int height)
{
    this->height = height;
}

// Function to print the details of the Rectangle
void Rectangle::printShape() const {
    cout << "Rectangle at x: " << x << ", y: " << y << " with width: " << width << " and height: " << height << endl;
}

// RightTriangle class definition
class RightTriangle : public Shape
{
private:
    int base;
    int height;
    
public:
    // Constructors
    RightTriangle();
    RightTriangle(int b, int h);
    RightTriangle(int x, int y, int b, int h);
    
    // Destructor
    virtual ~RightTriangle();
    
    // Copy constructor
    virtual RightTriangle* copy();
    
    //Accessors
    int getBase() const;
    int getHeight() const;
    
    // Mutators
    void setBase(int);
    void setHeight(int);
    
    // Function to print the details of the RightTriangle
    virtual void printShape() const;
};

// Default constructor for RightTriangle class
inline RightTriangle::RightTriangle() : Shape(), base(0), height(0) {
}

// Parameterized constructor for RightTriangle class
inline RightTriangle::RightTriangle(int b, int h) : Shape(), base(b), height(h) {
}

// Parameterized constructor for RightTriangle class
inline RightTriangle::RightTriangle(int x, int y, int b, int h) : Shape(x, y), base(b), height(h) {
}

// Destructor for RightTriangle class
RightTriangle::~RightTriangle()
{
    // No dynamic memory to delete
}

// Copy constructor for RightTriangle class
RightTriangle* RightTriangle::copy()
{
    RightTriangle* newRightTriangle = new RightTriangle(*this);
    return newRightTriangle;
}

// Accessor function for the base of the RightTriangle
int RightTriangle::getBase() const
{
    return base;
}

// Accessor function for the height of the RightTriangle
int RightTriangle::getHeight() const
{
    return height;
}

// Mutator function for the base of the RightTriangle
void RightTriangle::setBase(int base)
{
    this->base = base;
}

// Mutator function for the height of the RightTriangle
void RightTriangle::setHeight(int height)
{
    this->height = height;
}

// Function to print the details of the RightTriangle
void RightTriangle::printShape() const
{
    cout << "Right Triangle at x: " << x << ", y: " << y << " with base: " << base << " and height: " << height << endl;
}
