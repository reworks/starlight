///
/// Widget.cpp
/// starlight
///
/// Created by reworks on 15/09/2018.
/// MIT License.
/// Refer to LICENSE.txt for more details.
///

#include "Widget.hpp"

namespace sl
{
	Widget::Widget(const sl::Rect<int>& bounds) noexcept
		:m_bounds(bounds)
	{
	}

	Widget::~Widget()
	{
	}

	void Widget::isVisible(bool isVisible)
	{
		m_isVisible = isVisible;
	}
}