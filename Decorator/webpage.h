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