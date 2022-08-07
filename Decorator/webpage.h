#include <memory>
#include <iostream>
#include <string>


struct WebPage
{
	virtual void display() = 0;
	virtual ~WebPage() = default;
};

struct BasicWebPage : WebPage
{
	std::string html;
	void display() override
	{
		std::cout << "Basic WEB page " << std::endl;
	}
};

struct WebPageDecorator: WebPage
{
	WebPageDecorator(std::unique_ptr<WebPage> webPage) : _webPage(std::move(webPage))
	{}

	void display() override
	{
		_webPage->display();
	}

private:
	std::unique_ptr<WebPage> _webPage;

};

struct AuthenticateWebPage:WebPageDecorator
{
	AuthenticateWebPage(std::unique_ptr<WebPage> webPage):
	WebPageDecorator(std::move(webPage))
	{}

	void authorizeUser()
	{
		std::cout << "authorized done" << std::endl;
	}

	void display() override
	{
		authorizeUser();
		WebPageDecorator::display();
	}
};

struct AuthorizeWebPage : WebPageDecorator
{
	AuthorizeWebPage(std::unique_ptr<WebPage> webPage):
	WebPageDecorator(std::move(webPage))
	{}

	void authorizeUser()
	{
		std::cout << "authorized done" << std::endl;
	}

	void display() override
	{
		authorizeUser();
		WebPageDecorator::display();
	}
};

class A
{
public:
	A(){}
	void static display()
	{
		std::cout << "A" << std::endl;
	}
};

class B : A
{
public:
	B():A()
	{}

	void display()
	{
		A::display();
		std::cout << "B" << std::endl;
	}

};