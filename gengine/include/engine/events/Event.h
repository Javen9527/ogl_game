#pragma once

#include "dllDefine.h"

#include <string>
#include <functional>

namespace ge
{
	enum class EventType
	{
		eNone = 0,
		eWindowClose,
		eWindowResize, 
		eWindowFocus, // not use
		eWindowLostFocus, // not use
		eWindowMoved, // not use
		eAppTick,
		eAppUpdate,
		eAppRender,

		eKeyPressed,
		eKeyReleased,

		eMouseButtonPressed,
		eMouseButtonReleased,
		eMouseMoved,
		eMouseScrolled
	};

	enum EventCategory
	{
		eNone = 0,
		eEventCategoryApplication = BIT(0),
		eEventCategoryInput		  = BIT(1),
		eEventCategoryKeyboard	  = BIT(2),
		eEventCategoryMouse		  = BIT(3),
		eEventCategoryMouseButton = BIT(4)

	};


	#define DEF_GET_EVENT_TYPE_OVERRIDE(type)	static EventType GetStaticType() { return EventType::##type; }\
												virtual EventType GetEventType() const override { return GetStaticType(); }\
												virtual const char* GetName() const override { return #type; }

	#define DEF_GET_EVENT_CATEGORY_FLAG_OVERRIDE(category) virtual int GetCategoryFlags() const override { return category; }


	class GE_API Event
	{
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;

		virtual int GetCategoryFlags() const = 0;

		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}

	private:
		friend class EventDispatcher;

	protected:
		bool m_handled = false;
	};

	class EventDispatcher
	{
	public:
		template<typename T>
		using EventFunc = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& event)
			: m_event(event)
		{
		}

		template<typename T>
		bool Dispatch(EventFunc<T> func)
		{
			if (m_event.GetEventType() == T::GetStaticType())
			{
				m_event.m_handled = func(*(T*)&m_event);
				return true;
			}
			return false;
		}

	private:
		Event& m_event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}


} // namespace ge
