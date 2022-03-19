#pragma once

#include <string>
#include <functional>

#include "define.h"
#include "engine/events/Event.h"

namespace ge
{
	struct WindowProps
	{
		WindowProps(const std::string& title = "GE Engine", unsigned int width = 1280, unsigned int height = 720)
			: Title(title)
			, Width(width)
			, Height(height)
		{}

		std::string Title;
		unsigned int Width;
		unsigned int Height;
	};

	class GE_API Window
	{
	public:
		using EventCallbackFunc = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFunc& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};

} // namespace ge
