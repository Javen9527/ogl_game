#include "platform/windows/Windows.h"
#include "engine/log/Log.h"

namespace ge
{
	static bool b_GLFWInitialized = false;

	Window* Window::Create(const WindowProps& props)
	{
		return new Windows(props);
	}

	Windows::Windows(const WindowProps& props)
	{
		Init(props);
	}

	Windows::~Windows() 
	{
		ShutDown();
	}

	void Windows::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		GE_INFO("Createing Window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!b_GLFWInitialized)
		{
			int success = glfwInit();
			GE_ASSERT(success, "Coud not initialize GLFW!");

			b_GLFWInitialized = true;
		}

		m_window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_window);
		glfwSetWindowUserPointer(m_window, &m_Data); // for windows callback function
		SetVSync(true);
	}

	void Windows::ShutDown()
	{
		glfwDestroyWindow(m_window);
	}

	void Windows::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}

	void Windows::SetVSync(bool enabled)
	{
		enabled ? glfwSwapInterval(1) : glfwSwapInterval(0);
		m_Data.VSync = enabled;
	}

	bool Windows::IsVSync() const
	{
		return m_Data.VSync;
	}

} // namespace ge
