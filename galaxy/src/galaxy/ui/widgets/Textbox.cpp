///
/// Textbox.cpp
/// galaxy
///
/// Refer to LICENSE.txt for more details.
///

#include "galaxy/core/ServiceLocator.hpp"
#include "galaxy/graphics/Renderer2D.hpp"
#include "galaxy/res/ShaderBook.hpp"

#include "Textbox.hpp"

namespace galaxy
{
	namespace ui
	{
		Textbox::Textbox() noexcept
		    : m_text_to_draw {""}, m_border_width {0.0f}, m_messages_index {0}, m_char_index {0}, m_draw_lower {false}, m_prev_text {""}, m_ind_x {0.0f}, m_ind_y {0.0f}, m_shader {nullptr}
		{
			m_indicator_timer.set_repeating(true);
			m_draw_text_timer.set_repeating(true);
		}

		Textbox::~Textbox()
		{
			m_messages.clear();
			m_indicator_timer.stop();
			m_draw_text_timer.stop();
		}

		void Textbox::create(std::string_view box, std::string_view indicator, std::string_view font, float border_width)
		{
			m_border_width = border_width;
			m_sprite.create(box);
			m_indicator.create(indicator, 0.0f);

			m_bounds.m_width  = m_sprite.get_width();
			m_bounds.m_height = m_sprite.get_height();

			m_text.load(font, m_theme->m_font_col);
			m_text.create("");
			m_text_transform.set_pos(m_bounds.m_x + m_border_width, m_bounds.m_y + m_border_width);

			// clang-format off
			m_indicator_timer.set([&]()
			{
				std::lock_guard<std::mutex> lock {m_mutex};
				
				if (m_draw_lower)
				{
					m_draw_lower = false;
					m_indicator_transform.set_pos(m_ind_x, m_ind_y);
				}
				else
				{
					m_draw_lower = true;
					m_indicator_transform.set_pos(m_ind_x, m_ind_y + (m_indicator.get_height() / 4.0f));
				}
			},
			800);
			m_indicator_timer.start();

			m_draw_text_timer.set([&]()
			{
				if (!(m_messages_index >= m_messages.size()))
				{
					if (!(m_char_index >= m_messages[m_messages_index].size()))
					{
						m_char_index++;
					}
				}
			},
			150);
			m_draw_text_timer.start();
			// clang-format on

			m_shader = SL_HANDLE.shaderbook()->get("text");

			m_theme->m_sb.add(&m_sprite, &m_transform, 0);
			m_theme->m_sb.add(&m_indicator, &m_indicator_transform, 1);
		}

		void Textbox::on_event(const events::MouseMoved& mme) noexcept
		{
			if (m_tooltip)
			{
				if (m_bounds.contains(mme.m_x, mme.m_y))
				{
					m_tooltip->can_draw(true);
					m_tooltip->update_pos(mme.m_x, mme.m_y);
				}
				else
				{
					m_tooltip->can_draw(false);
				}
			}
		}

		void Textbox::on_event(const events::KeyDown& kde) noexcept
		{
			if (kde.m_keycode == input::Keys::ENTER)
			{
				m_messages_index++;
				if (m_messages_index > (m_messages.size() - 1))
				{
					m_messages_index = (m_messages.size() - 1);
				}

				m_char_index = 0;
			}
		}

		void Textbox::update(const double dt)
		{
			m_draw_text_timer.update(dt);
			m_indicator_timer.update(dt);
			if (!(m_messages_index >= m_messages.size()))
			{
				if (!(m_char_index >= m_messages[m_messages_index].size()))
				{
					m_indicator.set_opacity(0.0f);

					auto cur_text = m_messages[m_messages_index].substr(0, m_char_index);
					if (cur_text != m_prev_text)
					{
						m_text.create(cur_text);
						m_prev_text = cur_text;
					}
				}
				else
				{
					m_indicator.set_opacity(1.0f);
				}
			}
		}

		void Textbox::render()
		{
			m_shader->bind();
			m_shader->set_uniform("u_cameraProj", m_theme->m_camera.get_proj());
			m_shader->set_uniform("u_cameraView", m_theme->m_camera.get_view());
			graphics::Renderer2D::draw_text(&m_text, &m_text_transform, m_shader);

			if (m_tooltip)
			{
				if (m_tooltip->can_draw())
				{
					m_tooltip->render();
				}
			}
		}

		void Textbox::set_text(std::span<std::string> messages) noexcept
		{
			m_messages.clear();
			m_messages.reserve(messages.size());
			m_messages.assign(messages.begin(), messages.end());
		}

		void Textbox::set_pos(const float x, const float y) noexcept
		{
			std::lock_guard<std::mutex> lock {m_mutex};

			m_bounds.m_x = x;
			m_bounds.m_y = y;
			m_transform.set_pos(x, y);

			m_text_transform.set_pos(m_bounds.m_x + m_border_width, m_bounds.m_y + m_border_width);

			m_ind_x = ((m_bounds.m_x + m_bounds.m_width) - m_indicator.get_width()) - m_border_width;
			m_ind_y = ((m_bounds.m_y + m_bounds.m_height) - m_indicator.get_height()) - m_border_width;
		}
	} // namespace ui
} // namespace galaxy