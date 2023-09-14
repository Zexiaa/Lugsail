#pragma once

#include "Core.h"

namespace Lugsail {

	class LUGSAIL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// Define in client
	Application* CreateApplication();
}

