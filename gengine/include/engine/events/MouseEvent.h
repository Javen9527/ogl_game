#pragma once

#include "Event.h"

#include <sstream>

namespace ge
{
	class GE_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(double x, double y)
			: m_mouseX(x)
			, m_mouseY(y)
		{}

		inline double GetX() const { return m_mouseX; }
		inline double GetY() const { return m_mouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "eMouseMoveEvent: " << m_mouseX << ", " << m_mouseY;
			return ss.str();
		}

		DEF_GET_EVENT_TYPE_OVERRIDE(eMouseMoved)
		DEF_GET_EVENT_CATEGORY_FLAG_OVERRIDE(eEventCategoryInput | eEventCategoryMouse)

	private:
		double m_mouseX;
		double m_mouseY;
	};

	class GE_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(double xOffset, double yOffset)
			: m_xOffset(xOffset)
			, m_yOffset(yOffset)
		{}

		inline double GetXOffset() const { return m_xOffset; }
		inline double GetYOffset() const { return m_yOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "eMouseScrolledEvent: " << m_xOffset << ", " << m_yOffset;
			return ss.str();
		}

		DEF_GET_EVENT_TYPE_OVERRIDE(eMouseScrolled)
		DEF_GET_EVENT_CATEGORY_FLAG_OVERRIDE(eEventCategoryInput | eEventCategoryMouse)

	private:
		double m_xOffset;
		double m_yOffset;
	};

	class GE_API MouseButtonEvent : public Event
	{
	public:
		MouseButtonEvent(int button)
			: m_button(button)
		{}

		inline int GetMouseButton() const { return m_button; }

		DEF_GET_EVENT_CATEGORY_FLAG_OVERRIDE(eEventCategoryInput | eEventCategoryMouse)

	protected:
		int m_button;
	};

	class GE_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button)
		{}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "eMouseButtonPressedEvent: " << m_button;
			return ss.str();
		}

		DEF_GET_EVENT_TYPE_OVERRIDE(eMouseButtonPressed)
	};

	class GE_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button)
		{}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "eMouseButtonReleasedEvent: " << m_button;
			return ss.str();
		}

		DEF_GET_EVENT_TYPE_OVERRIDE(eMouseButtonReleased)
	};

} // namespace ge
