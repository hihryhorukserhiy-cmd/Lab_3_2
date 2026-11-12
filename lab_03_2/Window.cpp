#include "Window.h"
#include <cstdlib> 

using namespace std;

bool Window::isValidWindow(int x1, int y1, int x2, int y2)
{
    return (x1 < x2) && (y1 < y2);
}

Window::Window()
{
    x1 = -9999; y1 = -9999;
    x2 = 9999; y2 = 9999;
    bgColor = new string(""); 

    SetX1(0);
    SetY1(0);
    SetX2(0);
    SetY2(0);
    SetBgColor("White");
}

Window::Window(int nx1, int ny1, int nx2, int ny2, const std::string& color)
{
    if (!isValidWindow(nx1, ny1, nx2, ny2))
    {
        cout << "\nПомилка. Некоректні координати вікна.\n";
        exit(1);
    }
    x1 = -9999; y1 = -9999;
    x2 = 9999; y2 = 9999;
    bgColor = new string("");

    SetX1(nx1);
    SetY1(ny1);
    SetX2(nx2);
    SetY2(ny2);
    SetBgColor(color);
}

Window::Window(const Window& other)
{
    x1 = -9999; y1 = -9999;
    x2 = 9999; y2 = 9999;
    bgColor = new string("");

    SetX1(other.x1);
    SetY1(other.y1);
    SetX2(other.x2);
    SetY2(other.y2);
    SetBgColor(*(other.bgColor));
}

Window::~Window()
{
    delete bgColor;
}

void Window::SetX1(int val)
{
    if (!isValidWindow(val, y1, x2, y2)) { cout << "\nПомилка. Некоректне Х1.\n"; exit(1); }
    x1 = val;
}

void Window::SetY1(int val)
{
    if (!isValidWindow(x1, val, x2, y2)) { cout << "\nПомилка. Некоректне Y1.\n"; exit(1); }
    y1 = val;
}

void Window::SetX2(int val)
{
    if (!isValidWindow(x1, y1, val, y2)) { cout << "\nПомилка. Некоректне Х2.\n"; exit(1); }
    x2 = val;
}

void Window::SetY2(int val)
{
    if (!isValidWindow(x1, y1, x2, val)) { cout << "\nПомилка. Некоректне Y2.\n"; exit(1); }
    y2 = val;
}

void Window::SetBgColor(const std::string& color)
{
    *bgColor = color;
}

Window& Window::operator=(const Window& other)
{
    if (this != &other)
    {
        SetX1(other.x1);
        SetY1(other.y1);
        SetX2(other.x2);
        SetY2(other.y2);
        SetBgColor(*(other.bgColor));
    }
    return *this;
}

Window::operator std::string() const
{
    return "Windows [(" + to_string(x1) + ", " + to_string(y1) + ") - ("
        + to_string(x2) + ", " + to_string(y2) + "), BG Color: " + *bgColor + "]";
}

std::ostream& operator<<(std::ostream& out, const Window& w)
{
    out << string(w);
    return out;
}

std::istream& operator>>(std::istream& in, Window& w)
{ 
    int nx1, ny1, nx2, ny2;
    string nColor;
    cout << "Введіть X1 та Y1 (верхній лівий кут): "; in >> nx1 >> ny1;
    cout << "Введіть X2 та Y2 (нижній правий кут): "; in >> nx2 >> ny2;
    cout << "Введіть колір фону: "; in >> nColor;

    if (!Window::isValidWindow(nx1, ny1, nx2, ny2))
    {
        cout << "\nПомилка. Некоректні координати при введенні!\n";
        exit(1);
    }

    w.SetX1(nx1);
    w.SetY1(ny1);
    w.SetX2(nx2);
    w.SetY2(ny2);
    w.SetBgColor(nColor);
    return in;
}



