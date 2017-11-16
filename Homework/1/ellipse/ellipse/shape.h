//
//  shape.h
//  ellipse
//
//  Created by Laura Kirby on 9/27/17.
//  Copyright © 2017 LK. All rights reserved.
//

#ifndef shape_h
#define shape_h


// ----------------- Shape

class Shape {

public:

    //create a shape with initial position (0,0)
    Shape() : xPos(0), yPos(0) {}

    //set shape position
    void setPosition(double xPosition, double yPosition){
        xPos = xPosition;
        yPos = yPosition;
    }

    double get_xPosition() const { return xPos; }
    double get_yPosition() const { return yPos; }

private:
    double xPos; // The x position of this shape
    double yPos; // The y position of this shape
};


// ----------------- Ellipse

class Ellipse : public Shape{

public:
    Ellipse();

    //calculate area
    virtual double calculateArea(double xRadius, double yRadius);

    //calculate perimeter
    virtual double calculatePerimeter(double xRadius, double yRadius);

private:
    double xRadius;  //Half the x-axis of the ellipse
    double yRadius;  //Half the y-axis of the ellipse
};


// ----------------- Circle

class Circle : public Ellipse{
public:

    //creates an Circle with given radius
    Circle(double radius);

private:
    double xRadius;  //Radius of the Circle
    double yRadius;  //Radius of the Circle
};




#endif /* shape_h */
