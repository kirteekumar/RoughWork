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

	grid.set_style(Line_style{ Line_style::dash, 2 });

	Closed_polyline cpl;


	cpl.add(Point(100, 100));
	cpl.add(Point(150, 200));
	cpl.add(Point(250, 250));
	cpl.add(Point(300, 200));

	cpl.add(Point(100, 250));

	Graph_lib::Rectangle rect00 { Point{50, 100}, 200, 100 };
	rect00.set_fill_color(Color::yellow);

	Vector_ref<Graph_lib::Rectangle> rect;

	Graph_lib::Rectangle x{ Point{100,200},Point{200,300} };
	rect.push_back(x);

	rect.push_back(new Graph_lib::Rectangle{ Point{50,60},Point{80,90} });

	for (int i = 0;i < rect.size();++i) rect[i].move(10, 10);

	Vector_ref<Graph_lib::Rectangle> vr;

	for (int i = 0;i < 16;++i)
		for (int j = 0;j < 16;++j) {
			vr.push_back(new Graph_lib::Rectangle{ Point{i * 20,j * 20},20,20 });
			vr[vr.size() - 1].set_fill_color(Color( i * 16 + j ));
			//win3.attach(vr[vr.size() - 1]);
		}

	Text t{ Point{200,200}, "A closed polyline"};
	t.set_color(Color::blue);

	Circle c1{ Point{100,200},50 };
	Circle c2{ Point{100,200},25 };

	Graph_lib::Ellipse e1{ Point{200,200},50,50 };

	Graph_lib::Ellipse e2{ Point{200,200},100,50 }; 
	Graph_lib::Ellipse e3{ Point{200,200},100,150 };
	

	Marked_polyline mpl{ "1234" };
	mpl.add(Point{ 100,100 });
	mpl.add(Point{ 150,200 });
	mpl.add(Point{ 250,250 });
	mpl.add(Point{ 300,200 });

	win3.attach(mpl);
	win3.attach(e1);
	win3.attach(e2);
	win3.attach(e3);
	win3.attach(c1);
	win3.attach(c2);

	//Closed_polyline cpl = { {100,100},{150,200}, {250,250},{300,200} };


	//win3.attach(grid);
	
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