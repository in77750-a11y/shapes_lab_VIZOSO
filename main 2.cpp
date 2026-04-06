//
//  main.cpp
//  shape activity
//
//  Created by Andres Vizoso on 3/18/26.
//

#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

class shape {
   
    
protected:
    string name;
public:
    virtual double get_area() = 0;
    
    virtual double get_perimeter() = 0;
    
    

    shape(string n){
        name = n;
    }
    virtual void pretty_print(){
        cout << name << ": " << endl;
            cout << "Area: " << get_area() << endl;
            cout << endl;
            cout << "Perimeter: " << get_perimeter() << endl;
        }
    virtual void pretty_print_Area(){
        cout << name << ": " << endl;
            cout << "Area: " << get_area() << endl;
            
        }
};

class cirle : public shape {
private:
    double radius;
    
    
public:
    
    cirle(double r) : shape("circle"){
        radius = r;
    }
    
    double get_area(){
        return 3.14159 * radius * radius;
    }
    double get_perimeter(){
        return 2 * 3.14159 * radius;
    }
    void pretty_print(){
        shape::pretty_print();
    }
    void pretty_print_Area(){
        shape::pretty_print_Area();
    }
};

class rectangle : public shape {
protected:
    double rec_length;
    double rec_width;
    
public:
    
    rectangle(double l, double w) : shape("rectangle"){
        rec_length = l;
        rec_width = w;
    }
    
        
    
    double get_area(){
        
        return rec_length * rec_width;
    }
    double get_perimeter(){
        return 2 *(rec_length + rec_width);
    }
    
    void pretty_print(){
        shape::pretty_print();
    }
    
    void pretty_print_Area(){
        shape::pretty_print_Area();
    }
};

class square : public rectangle {

    
public:
    square(double side) : rectangle(side, side) {
        name = "Square";
    }
        
    void pretty_print(){
        shape::pretty_print();
    }
    
    void pretty_print_Area(){
        shape::pretty_print_Area();
    }
    
};

class right_triangle : public shape {
protected:
    double tri_length;
    double tri_width;
    double hypotenuse;
    
    
public:
    
    right_triangle(double l, double w) : shape("right triangle"){
        tri_length = l;
        tri_width = w;
        
        
    }
    
    double get_area(){
        return (tri_length * tri_width) * (0.5);
    }
    double get_perimeter(){
        return tri_length + tri_width + sqrt(pow(tri_length, 2) + pow(tri_length, 2));
    }
    
    void pretty_print(){
        shape::pretty_print();
    }
    
    void pretty_print_Area(){
        shape::pretty_print_Area();
    }
};


class Isoceles_right_triangle : public right_triangle {
        
public:
    
    Isoceles_right_triangle(double Isoceles_l, double Isoceles_w) : right_triangle(Isoceles_l, Isoceles_w){
        
        name = "Isoceles Right Triangle";
    }
    
    void pretty_print(){
        shape::pretty_print();
    }
    
    void pretty_print_Area(){
        shape::pretty_print_Area();
    }
};

void printAreaToScreen(shape* s){
    vector<shape*> shapes;
    shapes.push_back(s);
    for (auto& shape : shapes) {
        shape->pretty_print_Area(); // Calls the derived play()
        cout << endl;
    }
}

int main() {
    //cout << "Cirle:" << endl;
    cirle c = cirle(4);
    c.pretty_print();
    //cout << c.get_area() << endl;
    cout << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    //cout << "Rectangle:" << endl;
    rectangle r = rectangle(4, 5);
    r.pretty_print();
    
    cout << endl;
    cout << "========================================" << endl;
    cout << endl;
    
   // cout << "Right Triangle:" << endl;
    right_triangle r_tri = right_triangle(4, 5);
    r_tri.pretty_print();
    
    cout << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    square s = square(4);
    s.pretty_print();
    
    cout << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    Isoceles_right_triangle I_r_tri = Isoceles_right_triangle(15, 2);
    I_r_tri.pretty_print();
    
    cout << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    
    printAreaToScreen(&c);
    printAreaToScreen(&r);
    printAreaToScreen(&r_tri);
    printAreaToScreen(&s);
    printAreaToScreen(&I_r_tri);
    
}
