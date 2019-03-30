#include "Figure.h"

int main(void)
{
	Circle circle(RGB(255,0,0),50,50,10);

	circle.draw();

	system("pause");
	return 0;
}