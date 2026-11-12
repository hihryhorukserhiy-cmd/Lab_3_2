#pragma once
#include "Window.h"
#include <string>

class MenuWindow : public Window
{
private:
	std::string menu;
public:
	MenuWindow();
	MenuWindow(int x1, int y1, int x2, int y2, const std::string& color, const std::string& menuBar);
	MenuWindow(const MenuWindow& other);
	~MenuWindow();

	std::string GetMenu() const { return menu; }
	void SetMenu(const std::string& menuBar) { menu = menuBar; }
	void ReassingBgColor(const std::string& newColor);
	void ReassingMenu(const std::string& newMenu);

	MenuWindow& operator=(const MenuWindow& other);
	operator std::string() const;

	friend std::ostream& operator<<(std::ostream& out, const MenuWindow& mw);
	friend std::istream& operator>>(std::istream& in, MenuWindow& mw);
};

