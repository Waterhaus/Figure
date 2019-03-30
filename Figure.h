#pragma once
#include <windows.h>
#define PI 3.14159265359


class Figure
{
private:
	COLORREF color;
protected:
	int x, y; // базовая точка
public:
	
	void set_color(COLORREF c)
	{
		this->color = c;
	}
	COLORREF get_color()
	{
		return this->color;
	}
	void set_position(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	
	virtual double area() = 0;
	virtual void draw() = 0;
	virtual ~Figure() = 0 {}

};

class Circle : public Figure
{
private:
	int radius;
public:
	Circle(COLORREF c, int x, int y, int r) 
	{
		set_color(c);
		this->x = x;
		this->y = y;
		this->radius = r;
	}
	~Circle()
	{
	
	}

	virtual double area()
	{
		double rr = (double)(radius*radius);
		return PI*rr;
	}
	virtual void draw()
	{
	

		HWND console = FindWindow("ConsoleWindowClass", NULL);
		HDC dc = GetDC(console);

		COLORREF bcolor = get_color();

	
		HPEN pen = CreatePen(PS_SOLID, 2, bcolor);
		COLORREF fcolor = RGB(0,0,0);

	
		HBRUSH brush = CreateSolidBrush(fcolor);
		SelectObject(dc, pen);
		SelectObject(dc, brush);
		Ellipse(dc, x - radius, y + radius, x + radius, y - radius);
		ReleaseDC(console, dc);
	}


};