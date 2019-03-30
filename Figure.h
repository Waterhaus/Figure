#pragma once
#include <windows.h>
#include <math.h>
#define PI 3.14159265359

using namespace std;

//Абстрактный класс - интерфейс
class Figure
{
private:
	COLORREF color;
protected:
	int center_x, center_y; // базовая точка
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
		this->center_x = x;
		this->center_y = y;
	}
	
	virtual double area() = 0;
	virtual void draw() = 0;
	virtual ~Figure() = 0 {}

};

class MyCircle : public Figure
{
private:
	int diameter;
public:
	MyCircle(COLORREF c, int x, int y, int d) 
	{
		set_color(c);
		this->center_x = x;
		this->center_y = y;
		this->diameter = d;
	}
	~MyCircle()
	{
	
	}

	virtual double area()
	{
		double rr = (double)(diameter*diameter)/4.0;
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
		Ellipse(dc, center_x - diameter/2, center_y + diameter/2, center_x + diameter/2, center_y - diameter/2);
		ReleaseDC(console, dc);
	}


};



class MyRectangle : public Figure
{
private:
	int height;
	int width;

public:
	MyRectangle(COLORREF c, int x, int y, int h, int w)
	{
		set_color(c);
		this->center_x = x;
		this->center_y = y;
		this->height = h;
		this->width = w;
	}
	~MyRectangle()
	{

	}

	virtual double area()
	{
		
		return height*width;
	}
	virtual void draw()
	{
		HWND console = FindWindow("ConsoleWindowClass", NULL);
		HDC dc = GetDC(console);
		COLORREF bcolor = get_color();


		HPEN pen = CreatePen(PS_SOLID, 2, bcolor);
		COLORREF fcolor = RGB(0, 0, 0);


		HBRUSH brush = CreateSolidBrush(fcolor);
		SelectObject(dc, pen);
		SelectObject(dc, brush);
		Rectangle(dc, center_x - height / 2, center_y + width / 2, center_x + height / 2, center_y - width / 2);
		ReleaseDC(console, dc);
	}


};


class MyTriangle : public Figure
{
private:
	int side;

public:
	MyTriangle(COLORREF c, int x, int y, int s)
	{
		set_color(c);
		this->center_x = x;
		this->center_y = y;
		this->side = s;
	
	}
	~MyTriangle()
	{

	}

	virtual double area()
	{

		return sqrt(3.0)*(side*side)/4.0;
	}
	virtual void draw()
	{
		HWND console = FindWindow("ConsoleWindowClass", NULL);
		HDC dc = GetDC(console);
		COLORREF bcolor = get_color();


		HPEN pen = CreatePen(PS_SOLID, 2, bcolor);
		COLORREF fcolor = RGB(0, 0, 0);


		HBRUSH brush = CreateSolidBrush(fcolor);
		SelectObject(dc, pen);
		SelectObject(dc, brush);
		POINT vertices[] = { { center_x - side/2, center_y - side / 2 },{ center_x, center_y + side / 2 },{ center_x + side / 2, center_y - side / 2 } };
		Polygon(dc, vertices, sizeof(vertices) / sizeof(vertices[0]));
		
		ReleaseDC(console, dc);
	}


};