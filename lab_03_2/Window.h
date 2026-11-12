#pragma once
#include <string>
#include <iostream>

class Window
{
private:
	int x1, y1; // Координати верхнього лівого кута
	int x2, y2; // Координати нижнього правого кута
	std::string* bgColor;

public:
	static bool isValidWindow(int x1, int y1, int x2, int y2);

	Window();
	Window(int x1, int y1, int x2, int y2, const std::string& color);
	Window(const Window& other);
	virtual ~Window();

	int GetX1() const { return x1; }
	int GetY1() const { return y1; }
	int GetX2() const { return x2; }
	int GetY2() const { return y2; }
	std::string GetBgColor() const { return *bgColor; }

	void SetX1(int val);
	void SetY1(int val);
	void SetX2(int val);
	void SetY2(int val);
	void SetBgColor(const std::string& color);

	Window& operator=(const Window& other);
	operator std::string() const;

	friend std::ostream& operator<<(std::ostream& out, const Window& w);
	friend std::istream& operator>>(std::istream& in, Window& w);
};

