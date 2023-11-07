#include <iostream>
#include <windows.h>
#include <string>


class Figure {
protected:
	std::string name = "Фигура";

	virtual bool check() {
		return true;
	}

	virtual int get_sides() {
		int sides = 0;
		return sides;
	}

public:
	virtual void print_info() {
		std::cout << name << std::endl;
		if (check()) {
			std::cout << "Правильная" << std::endl;
		}
		else {
			std::cout << "Неправильная" << std::endl;
		}
		std::cout << "Количество сторон: " << get_sides() << "\n" << std::endl;
	}
};

class Triangle : public Figure {
protected:
	int a, b, c, A, B, C;

	bool check() override {
		if ((a == 0 || b == 0 || c == 0) && (A+B+C != 180)) {
			return false;
		}
		else {
			return true;
		}
	}

	int get_sides() override {
		int sides = 0;
		(a != 0) ? sides++ : sides = sides;
		(b != 0) ? sides++ : sides = sides;
		(c != 0) ? sides++ : sides = sides;
		return sides;
	}

public:
	Triangle(int a, int b, int c, int A, int B, int C) : Figure() {
		name = "Треугольник";
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
	}

	void print_info() override {
		std::cout << name << std::endl;
		if (check()) {
			std::cout << "Правильная" << std::endl;
		}
		else {
			std::cout << "Неправильная" << std::endl;
		}
		std::cout << "Количество сторон: " << get_sides() << std::endl;
		std::cout << "Стороны: a=" << std::to_string(a) << " b=" << std::to_string(b) << " c=" << std::to_string(c) << std::endl;
		std::cout << "Углы: A=" << std::to_string(A) << " B=" << std::to_string(B) << " C=" << std::to_string(C) << "\n" << std::endl;
	}
};

class Quadrangle : public Figure {
protected:
	int a, b, c, d, A, B, C, D;

	bool check() override {
		if ((a == 0 || b == 0 || c == 0 || d == 0) && (A + B + C + D != 360)) {
			return false;
		}
		else {
			return true;
		}
	}

	int get_sides() override {
		int sides = 0;
		(a != 0) ? sides++ : sides = sides;
		(b != 0) ? sides++ : sides = sides;
		(c != 0) ? sides++ : sides = sides;
		(d != 0) ? sides++ : sides = sides;
		return sides;
	}
public:
	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Figure() {
		name = "Четырехугольник";
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
	}

	void print_info() override {
		std::cout << name << std::endl;
		if (check()) {
			std::cout << "Правильная" << std::endl;
		}
		else {
			std::cout << "Неправильная" << std::endl;
		}
		std::cout << "Количество сторон: " << get_sides() << std::endl;
		std::cout << "Стороны: a=" << std::to_string(a) << " b=" << std::to_string(b) << " c=" << std::to_string(c) << " d=" << std::to_string(d) << std::endl;
		std::cout << "Углы: A=" << std::to_string(A) << " B=" << std::to_string(B) << " C=" << std::to_string(C) << " D=" << std::to_string(D) << "\n" << std::endl;
	}
};

class RightTriangle : public Triangle {
protected:
	bool check() override {
		if (Triangle::check() && C == 90) {
			return true;
		}
		else {
			return false;
		}
	}
public:
	RightTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) {
		this->name = "Прямоугольный треугольник";
	};
};

class IsoscelesTriangle : public Triangle {
protected:
	bool check() override {
		if (Triangle::check() && (a == c) && (A == C)) {
			return true;
		}
		else {
			return false;
		}
	}
public:
	IsoscelesTriangle(int a, int c, int A, int B) : Triangle(a, a, c, A, A, B) {
		this->name = "Равнобедренный треугольник";
	};
};

class EquilateralTriangle : public Triangle {
protected:
	bool check() override {
		if (Triangle::check() && (a == b) && (b == c) && (a == c) && (A == B) && (B == C) && (A == C)) {
			return true;
		}
		else {
			return false;
		}
	}
public:
	EquilateralTriangle(int a) : Triangle(a, a, a, 60, 60, 60) {
		this->name = "Равносторонний треугольник";
	};
};

class FRectangle : public Quadrangle {
protected:
	bool check() override {
		if (Quadrangle::check() && (a == c) && (b == d) && (A == 90) && (B == 90) && (C == 90)) {
			return true;
		}
		else {
			return false;
		}
	}
public:
	FRectangle(int a, int b) : Quadrangle(a, b, a, b, 90, 90, 90, 90) {
		this->name = "Прямоугольник";
	};
};


class Square : public FRectangle {
protected:
	bool check() override {
		if (Quadrangle::check() && (a == b) && (b == c) && (a == c) && (a == d) && (b == d) && (c == d) && (A == 90) && (B == 90) && (C == 90)) {
			return true;
		}
		else {
			return false;
		}
	}
public:
	Square(int a) : FRectangle(a, a) {
		this->name = "Квадрат";
	};
};

class Parallelogram : public Quadrangle {
protected:
	bool check() override {
		if (Quadrangle::check() && (a == c) && (b == d) && (A == C) && (B == D)) {
			return true;
		}
		else {
			return false;
		}
	}
public:
	Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B) {
		this->name = "Параллелограмм";
	};
};

class Rhombus : public Parallelogram {
protected:
	bool check() override {
		if (Quadrangle::check() && (a == b) && (b == c) && (a == c) && (a == d) && (b == d) && (c == d) && (A == C) && (B == D)) {
			return true;
		}
		else {
			return false;
		}
	}
public:
	Rhombus(int a, int A, int B) : Parallelogram(a, a, A, B) {
		this->name = "Ромб";
	};
};


int main() {
	Figure fig0;
	Triangle fig1(10, 20, 30, 50, 60, 70);
	RightTriangle fig2(10, 20, 30, 50, 60);
	IsoscelesTriangle fig3(10, 20, 50, 60);
	EquilateralTriangle fig4(30);
	Quadrangle fig5(10, 20, 30, 40, 50, 60, 70, 80);
	FRectangle fig6(10, 20);
	Square fig7(10);
	Parallelogram fig8(10, 20, 30, 40);
	Rhombus fig9(30, 30, 40);

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	fig0.print_info();
	fig1.print_info();
	fig2.print_info();
	fig3.print_info();
	fig4.print_info();
	fig5.print_info();
	fig6.print_info();
	fig7.print_info();
	fig8.print_info();
	fig9.print_info();
}