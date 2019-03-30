#include "Figure.h"
#include <vector>
#include <algorithm>
#include <memory>

int main(void)
{
	int SIZE = 100; // ������� ���� �������� �� ��� ������
	int x = 0, y = 0;
	std::vector<std::unique_ptr<Figure>> vec;
	

	vec.push_back(std::unique_ptr<Figure>(new MyCircle(RGB(255, 0, 0), x, y, SIZE))); //����
	vec.push_back(std::unique_ptr<Figure>(new MyRectangle(RGB(0, 255, 0), x, y, SIZE,SIZE))); //�������
	vec.push_back(std::unique_ptr<Figure>(new MyTriangle(RGB(0, 0, 255), x, y, SIZE))); //�������������� �����������
	
	
	auto func = [](const auto & a, const auto & b) -> bool
	{
		return a->area() > b->area();
	};
	//��������� ������ �� �������
	std::sort(vec.begin(), vec.end(),func);
	
	x = 150;
	y = 400;
	int step = SIZE + 50;

	//������� �� �����
	for (size_t i = 0; i < vec.size(); i++)
	{
		vec[i]->set_position(x + i * step, y);
		vec[i]->draw();
	}
	/**/

	system("pause");
	return 0;
}