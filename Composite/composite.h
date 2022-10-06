#include <list>
#include <algorithm>
#include <iostream>
#include <string>


class File
{
public:
	virtual ~File() = default;
	virtual void Add(File* file) = 0;
	virtual void Remove(File* file) = 0;
	virtual void SetParent(File* file) {
		throw(-1);
	}

protected:
	File* parent_folder;
};

class Folder :public File
{
public:
	void Add(File* file) override
	{
		children.push_back(file);
		children.back()->SetParent(this);
	}

	virtual void Remove(File* file) override
	{

	}

	virtual void SetParent(File* file) override
	{

	}

	std::list<File*> GetChildren()
	{
		return children;
	}

protected:
	std::list<File*> children;
};

class MediaFile :public File
{
public:
	void Add(File* file) override
	{

	}

	void Remove(File* file) override
	{
		parent_folder->Remove(file);
	}

	void SetParent(File* file) override
	{
		Folder* cast_check = dynamic_cast<Folder*>(file);
		if (cast_check)
		{
			this->parent_folder = file;
		}
	}

protected:
	int age;
}


class Component
{

protected:
	Component* parent_;
public:
	virtual ~Component(){}
	void SetParent(Component* parent)
	{
		this->parent_ = parent;
	}
	Component* GetParent() const {
		return this->parent_;
	}

	virtual void Add(Component* component){}
	virtual void Remove(Component* component){}

	virtual bool IsComposite()const
	{
		return false;
	}

	virtual std::string Operation() const = 0;


};

class Leaf :public Component
{
public:
	std::string Operation() const override
	{
		return "Leaf";
	}
};

class Composite :public Component
{

protected:
	std::list<Component*> children_;
public:
	void Add(Component* component) override
	{
		this->children_.push_back(component);
		component->SetParent(this);
	}

	void Remove(Component* component) override
	{
		children_.remove(component);
		component->SetParent(nullptr);
	}

	bool IsComposite() const override
	{
		return true;
	}

	std::string Operation() const override
	{
		std::string result;
		for (const Component* c : children_)
		{
			if (c == children_.back())
			{
				result += c->Operation();
			}
			else
			{
				result += c->Operation() + "+";
			}
		}

		return "Branch(" + result + ")";
	}
};

void ClientCode(Component* component)
{
	std::cout << "RESULT: " << component->Operation();
}


void ClientCode2(Component* component1, Component* component2)
{
	if (component1->IsComposite())
	{
		component1->Add(component2);
	}
	std::cout << "RESULT: " << component1->Operation();
}


class BaseComponent
{
public:
	virtual void Add(BaseComponent* file) = 0;
	virtual void Remove(BaseComponent* file) = 0;
protected:
	BaseComponent* parent;
};

class Folder :public BaseComponent {

public:
	void Add(BaseComponent* file) override
	{

	}

	void Remove(BaseComponent* file) override
	{

	}

protected:
	std::list<BaseComponent*> children;
};