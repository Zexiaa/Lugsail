#pragma once

#ifdef LS_PLATFORM_WINDOWS

extern Lugsail::Application* Lugsail::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Lugsail::CreateApplication();
	app->Run();
	delete app;
}

#endif