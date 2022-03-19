#pragma once

#include "Event.h"

#include <sstream>

namespace ge
{

	class GE_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: m_width(width)
			, m_height(height)
		{}

		inline unsigned int GetWidth() const { return m_width; }
		inline unsigned int GetHeight() const { return m_height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "eWindowResizeEvent: " << m_width << ", " << m_height;
			return ss.str();
		}

		DEF_GET_EVENT_TYPE_OVERRIDE(eWindowResize)
		DEF_GET_EVENT_CATEGORY_FLAG_OVERRIDE(eEventCategoryApplication)

	private:
		unsigned int m_width;
		unsigned int m_height;
	};

	class GE_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		DEF_GET_EVENT_TYPE_OVERRIDE(eWindowClose)
		DEF_GET_EVENT_CATEGORY_FLAG_OVERRIDE(eEventCategoryApplication)
	};

	/// <summary>
	/// not often used
	/// </summary>

	class GE_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}

		DEF_GET_EVENT_TYPE_OVERRIDE(eAppTick)
		DEF_GET_EVENT_CATEGORY_FLAG_OVERRIDE(eEventCategoryApplication)
	};

	class GE_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}

		DEF_GET_EVENT_TYPE_OVERRIDE(eAppUpdate)
		DEF_GET_EVENT_CATEGORY_FLAG_OVERRIDE(eEventCategoryApplication)
	};

	class GE_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}

		DEF_GET_EVENT_TYPE_OVERRIDE(eAppRender)
		DEF_GET_EVENT_CATEGORY_FLAG_OVERRIDE(eEventCategoryApplication)
	};

} // namespace ge