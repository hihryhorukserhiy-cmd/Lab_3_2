#include "MenuWindow.h"

using namespace std;



MenuWindow::MenuWindow() : Window()
{
	SetMenu("File | Edit");
}

MenuWindow::MenuWindow(int x1, int y1, int x2, int y2, const std::string& color, const std::string& menuBar)
	: Window(x1, y1, x2, y2, color)
{
	SetMenu(menuBar);
}

MenuWindow::MenuWindow(const MenuWindow& other)
{
	SetMenu(other.menu);
}

MenuWindow::~MenuWindow()
{
}

void MenuWindow::ReassingBgColor(const string& newColor)
{
	SetBgColor(newColor);
}

void MenuWindow::ReassingMenu(const string& newMenu)
{
	SetMenu(newMenu);
}

MenuWindow& MenuWindow::operator=(const MenuWindow& other)
{
	Window::operator=(other);
	SetMenu(other.menu);
	return *this;
}

MenuWindow::operator std::string() const
{
	return Window::operator std::string() + ", Menu: [" + menu + "]";
}

std::ostream& operator<<(std::ostream& out, const MenuWindow& mw)
{
	out << string(mw);
	return out;
}

std::istream& operator>>(std::istream& in, MenuWindow& mw)
{
	
	in >> (Window&)mw;

	std::cout << "¬вед≥ть р€док меню (одним словом без проб≥л≥в дл€ cin): ";
	std::string tempMenu;
	in >> tempMenu;
	mw.SetMenu(tempMenu);

	return in;
}



