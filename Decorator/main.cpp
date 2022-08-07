
#include "shape.h"
#include "webpage.h"

int main() {
	Circle circle;
	ColoredShape colored_shape("red", &circle);

	circle.Resize(20);
	std::cout << colored_shape.GetName() << std::endl;

	std::unique_ptr<WebPage> myPage = std::make_unique<BasicWebPage>();
	myPage = std::make_unique<AuthorizeWebPage>(std::move(myPage));
	myPage = std::make_unique<AuthenticateWebPage>(std::move(myPage));

	myPage->display();
	std::cout << std::endl;

	A::display();

	B b;
	b.display();

	return 0;
}