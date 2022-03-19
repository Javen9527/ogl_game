#pragma once

#include "engine/windows/Window.h"

#include "GLFW/glfw3.h"

namespace ge
{

	class Windows : public Window
	{
	public:
		Windows(const WindowProps& props);
		virtual ~Windows();

		void OnUpdate() override;
		
		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		inline void SetEventCallback(const EventCallbackFunc& callback) override
		{
			m_Data.EventCallback = callback;
		}

		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

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
			EventCallbackFunc EventCallback;
		};

	private:
		GLFWwindow* m_window;
		WindowData m_Data;
	};
} // namespace ge

