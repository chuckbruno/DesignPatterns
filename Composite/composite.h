
#include <list>

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
};