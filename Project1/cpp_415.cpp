#include <iostream>
#include "Simple_window.h"
#include "Graph.h"

int main(int argc, char** argv)
{
	using namespace Graph_lib;
	Point p{ 100,100 };

	Simple_window win3{ p,600,400,"two lines" };
	//Graph_lib::Lines x = { {100,100},{200,100} };
	//Lines xs = {{100,100},{200,100}, {100,100},{200,100}};

	int x_size = win3.x_max();
	int y_size = win3.y_max();
	int x_grid = 120;
	int y_grid = 40;

	Lines grid;
	grid.set_color(Color::red);

	for (int x = x_grid;x < x_size;x += x_grid)
		grid.add(Point{ x,0 }, Point{ x,y_size });
	
	for (int y = y_grid;y < y_size;y += y_grid)
		grid.add(Point{ 0,y }, Point{ x_size, y });

	win3.attach(grid);
	
	win3.wait_for_button();


	return 0;
}

/*
struct Lines : Shape {
	Lines() {}
	Lines(initializer_list<Point> lst);

	void draw_lines() const;
	void add(Point p1, Point p2);
};
*/

void before_page445(void)
{
	using namespace Graph_lib;

	Point tl{ 0,0 };

	Simple_window win{ tl, 600, 400, "Canvas" };

	Graph_lib::Polygon poly;

	Graph_lib::Axis xa{ Axis::x, Point {20,300}, 280, 10, "x-axis" };
	Graph_lib::Axis ya{ Axis::y, Point {20,300}, 280, 10, "y-axis" };
	ya.set_color(Color::cyan);
	ya.label.set_color(Color::dark_red);

	Function sine{ sin,0,10,Point{20,300},500,50,50 };

	sine.set_color(Color::blue);


	Graph_lib::Rectangle r{ Point {200,200}, 100, 50 };
	r.set_fill_color(Color::yellow);

	Graph_lib::Text t{ Point {150,150}, "hello world" };
	t.set_font(Font::times_bold);
	t.set_font_size(20);

	Graph_lib::Image ii{ Point{100,50},"image.jpg" };

	ostringstream oss;

	oss << "screen size: " << x_max() << "*" << y_max() << "; window size: " << win.x_max() << "*" << win.y_max();

	Text sizes{ Point {0,200}, oss.str() };


	win.attach(sizes);
	win.attach(ii);
	win.attach(t);
	win.attach(r);
	win.attach(sine);
	win.attach(xa);
	win.attach(ya);

	poly.add(Point{ 300, 200 });
	poly.add(Point{ 350, 100 });
	poly.add(Point{ 400, 200 });

	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);
	poly.set_style(Line_style(Line_style::dash, 2));

	win.attach(poly);

	win.wait_for_button();
}