#pragma once

#include "engine/windows/Window.h"

#include "glad/glad.h" // keep this order before glfw
#include "GLFW/glfw3.h"

namespace ge
{

	class Windows : public Window
	{
	public:
		Windows(const WindowProps& props);
		virtual ~Windows();

	public:
		void OnUpdate() override;

		inline void SetEventCallback(const EventCallbackFunc& callback) override
		{
			m_Data.EventCallback = callback;
		}

		void SetVSync(bool enabled) override;
		bool IsVSync() const override;
		
		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

	private:
		virtual void Init(const WindowProps& props);
		virtual void ShutDown();

	private:
		struct WindowData
		{
			std::string Title;
			unsigned int Width;
			unsigned int Height;

			bool VSync;
			// using EventCallbackFunc = std::function<void(Event&)>;
			EventCallbackFunc EventCallback;
		};

	private:
		WindowData m_Data;
		GLFWwindow* m_window;
	};
} // namespace ge

