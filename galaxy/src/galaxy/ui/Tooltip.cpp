///
/// Tooltip.cpp
/// galaxy
///
/// Refer to LICENSE.txt for more details.
///

#include "galaxy/core/ServiceLocator.hpp"
#include "galaxy/graphics/Renderer2D.hpp"
#include "galaxy/res/ShaderBook.hpp"

#include "Tooltip.hpp"

namespace galaxy
{
	namespace ui
	{
		Tooltip::Tooltip() noexcept
		    : m_draw {false}, m_theme {nullptr}, m_text_shader {nullptr}
		{
			m_cursor_size = SL_HANDLE.window()->cursor_size();
		}

		Tooltip::Tooltip(Tooltip&& t) noexcept
		{
			this->m_draw           = t.m_draw;
			this->m_text           = std::move(t.m_text);
			this->m_text_transform = std::move(t.m_text_transform);
			this->m_theme          = t.m_theme;
			this->m_text_shader    = t.m_text_shader;
			this->m_cursor_size    = std::move(t.m_cursor_size);
		}

		Tooltip& Tooltip::operator=(Tooltip&& t) noexcept
		{
			if (this != &t)
			{
				this->m_draw           = t.m_draw;
				this->m_text           = std::move(t.m_text);
				this->m_text_transform = std::move(t.m_text_transform);
				this->m_theme          = t.m_theme;
				this->m_text_shader    = t.m_text_shader;
				this->m_cursor_size    = std::move(t.m_cursor_size);
			}

			return *this;
		}

		Tooltip::~Tooltip() noexcept
		{
			m_theme       = nullptr;
			m_text_shader = nullptr;
		}

		void Tooltip::create(std::string_view text, std::string_view font)
		{
			m_text.load(font, m_theme->m_font_col);
			m_text.create(text);

			m_text_shader = SL_HANDLE.shaderbook()->get("text");
		}

		void Tooltip::render()
		{
			m_text_shader->bind();
			m_text_shader->set_uniform("u_cameraProj", m_theme->m_camera.get_proj());
			m_text_shader->set_uniform("u_cameraView", m_theme->m_camera.get_view());
			graphics::Renderer2D::draw_text(&m_text, &m_text_transform, m_text_shader);
		}

		void Tooltip::update_text(std::string_view text)
		{
			m_text.create(text);
		}

		void Tooltip::update_pos(double x, double y) noexcept
		{
			x += m_cursor_size.x;
			y += m_cursor_size.y;

			m_text_transform.set_pos(x, y);
		}

		void Tooltip::can_draw(const bool can_draw) noexcept
		{
			m_draw = can_draw;
		}

		const bool Tooltip::can_draw() const noexcept
		{
			return m_draw;
		}
	} // namespace ui
} // namespace galaxy