#include <Lugsail.h>

class Sandbox : public Lugsail::Application
{
public:
	Sandbox() 
	{

	}

	~Sandbox() 
	{

	}
};

Lugsail::Application* Lugsail::CreateApplication()
{
	return new Sandbox();
}