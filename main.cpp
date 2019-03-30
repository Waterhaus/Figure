#include "Figure.h"
#include <vector>
#include <algorithm>
#include <memory>

int main(void)
{
	int SIZE = 100; // выберем одно значение на все фигуры
	int x = 0, y = 0;
	std::vector<std::unique_ptr<Figure>> vec;
	

	vec.push_back(std::unique_ptr<Figure>(new MyCircle(RGB(255, 0, 0), x, y, SIZE))); //Круг
	vec.push_back(std::unique_ptr<Figure>(new MyRectangle(RGB(0, 255, 0), x, y, SIZE,SIZE))); //Квадрат
	vec.push_back(std::unique_ptr<Figure>(new MyTriangle(RGB(0, 0, 255), x, y, SIZE))); //Равносторонний треугольник
	
	
	auto func = [](const auto & a, const auto & b) -> bool
	{
		return a->area() > b->area();
	};
	//Сортируем фигуры по площади
	std::sort(vec.begin(), vec.end(),func);
	
	x = 150;
	y = 400;
	int step = SIZE + 50;

	//Выводим на экран
	for (size_t i = 0; i < vec.size(); i++)
	{
		vec[i]->set_position(x + i * step, y);
		vec[i]->draw();
	}
	/**/

	system("pause");
	return 0;
}