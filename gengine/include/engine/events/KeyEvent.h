#pragma once

#include "Event.h"

#include <sstream>

namespace ge
{
	class GE_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_keyCode; }

		// virtual int GetCategoryFlags() const override { return category; }
		DEF_GET_EVENT_CATEGORY_FLAG_OVERRIDE(eEventCategoryInput | eEventCategoryKeyboard)

	protected:
		KeyEvent(int keycode)
			: m_keyCode(keycode)
		{}

	protected:
		int m_keyCode;

	};

	class GE_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount)
			: KeyEvent(keycode)
			, m_repeatCount(repeatCount)
		{}

		inline int GetRepeatCount() const { return m_repeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "eKeyPressedEvent: " << m_keyCode << " (" << m_repeatCount << " repeats)";
			return ss.str();
		}

		// static EventType GetStaticType() { return EventType::eKeyPressed; }
		// virtual EventType GetEventType() const override { return GetStaticType(); }
		// virtual const char* GetName() const override { return "eKeyPressed"; }
		DEF_GET_EVENT_TYPE_OVERRIDE(eKeyPressed)

	private:
		int m_repeatCount;
	};

	class GE_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode)
		{}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "eKeyReleasedEvent: " << m_keyCode;
			return ss.str();
		}

		DEF_GET_EVENT_TYPE_OVERRIDE(eKeyReleased)
	};

} // namespace ge