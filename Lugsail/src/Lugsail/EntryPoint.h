#pragma once

#ifdef LS_PLATFORM_WINDOWS

extern Lugsail::Application* Lugsail::CreateApplication();

int main(int argc, char** argv)
{
	Lugsail::Log::Init();
	LS_CORE_WARN("Initialised Log.");

	int a = 0;
	LS_INFO("Started. Var={0}.", a);

	auto app = Lugsail::CreateApplication();
	app->Run();
	delete app;
}

#endif