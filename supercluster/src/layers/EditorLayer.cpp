///
/// EditorLayer.cpp
/// supercluster
///
/// Refer to LICENSE.txt for more details.
///

#include <galaxy/core/ServiceLocator.hpp>
#include <galaxy/core/Window.hpp>

#include "scenes/EditorScene.hpp"

#include "EditorLayer.hpp"

namespace sc
{
	EditorLayer::EditorLayer()
	{
		m_window       = SL_HANDLE.window();
		m_active_scene = std::make_unique<EditorScene>();
	}

	EditorLayer::~EditorLayer()
	{
		m_window = nullptr;
	}

	void EditorLayer::on_push()
	{
	}

	void EditorLayer::on_pop()
	{
	}

	void EditorLayer::events()
	{
		m_active_scene->events();
		if (m_window->key_pressed(galaxy::input::Keys::ESC))
		{
			m_window->close();
		}
	}

	void EditorLayer::update(const double dt)
	{
		m_active_scene->update(dt);
	}

	void EditorLayer::pre_render()
	{
		m_active_scene->pre_render();
	}

	void EditorLayer::render()
	{
		m_active_scene->render();
	}
} // namespace sc