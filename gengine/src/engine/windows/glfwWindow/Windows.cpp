
#include "engine/windows/glfwWindow/Windows.h"
#include "engine/log/Log.h"

#include "engine/events/KeyEvent.h"
#include "engine/events/AppEvent.h"
#include "engine/events/MouseEvent.h"


namespace ge
{
	static bool b_GLFWInitialized = false;
	static void GLFWErrorCallback(int error_code, const char* description)
	{
		GE_ERROR("GLFW error ({0}): {1}", error_code, description);
	}

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

			// set glfw error callback
			glfwSetErrorCallback(GLFWErrorCallback);

			b_GLFWInitialized = true;
		}

		m_window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_window);

		// glad
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		GE_ASSERT(status, "Failed to initialized glad!");
		if(status)
			GE_INFO("Initialized glad Successfully!");

		glfwSetWindowUserPointer(m_window, &m_Data); // for windows callback function
		SetVSync(true);

		// set glfw window callback
		glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height) {
			auto data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.Width = width;
			data.Height = height;

			WindowResizeEvent event(width, height);
			data.EventCallback(event);
		});
		glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window) {
			auto data = *(WindowData*)glfwGetWindowUserPointer(window);

			WindowCloseEvent event;
			data.EventCallback(event);
		});
		glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			auto data = *(WindowData*)glfwGetWindowUserPointer(window);
			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data.EventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					data.EventCallback(event);
					break;
				}
				default:
					break;
			}
		});
		glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods) {
			auto data = *(WindowData*)glfwGetWindowUserPointer(window);
			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data.EventCallback(event);
					break;
				}
				default:
					break;
			}
		});
		glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xoffset, double yoffset) {
			auto data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseScrolledEvent event(xoffset, yoffset);
			data.EventCallback(event);
		});
		glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xpos, double ypos) {
			auto data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseMovedEvent event(xpos, ypos);
			data.EventCallback(event);
		});
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
