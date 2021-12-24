/* File for practice on chapter 12 */
#include <ios>
#include <iostream>
#include <stdexcept>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>

#include "Point.h"
#include "Window.h"

using namespace Graph_lib;

int main()
{
    try {
        const Point x (100, 100);
        Graph_lib::Window win {x, 600, 400, "Canvas"};
        win.activate();
    } catch (std::runtime_error& e) {
        // error reporting
        return 1;
    } catch (...) {
        // error reporting
        return 2;
    }


    std::cout << "\nexit with code 0..";
    return 0;
}