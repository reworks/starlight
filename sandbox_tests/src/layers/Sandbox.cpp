///
/// Sandbox.cpp
/// sandbox_tests
///
/// Refer to LICENSE.txt for more details.
///

#include <nlohmann/json.hpp>

#include <galaxy/core/ServiceLocator.hpp>
#include <galaxy/flags/Enabled.hpp>
#include <galaxy/fs/FileSystem.hpp>
#include <galaxy/graphics/Renderer.hpp>
#include <galaxy/graphics/Shader.hpp>

#include "scenes/SandboxScene.hpp"

#include "Sandbox.hpp"

namespace sb
{
	Sandbox::Sandbox()
	{
		m_window       = SL_HANDLE.window();
		m_active_scene = std::make_unique<SandboxScene>();

		/*
		// create and set texture
		auto tex = galaxy::fs::s_root + galaxy::fs::s_textures + "particle_demo.png";
		m_particle_gen.create(tex, 100.0f, 100.0f);
		m_particle_gen.define("default", {0, 0, 16, 16});
		m_particle_gen.configure("default");

		galaxy::graphics::Colour c = {0, 0, 0, 255};
		m_point.create(0, 0, 10, c);
		m_point.set_pos(200, 150);

		m_circle.create(0, 0, 20, 50, c);
		m_circle.set_pos(150, 150);

		

		auto e2 = m_world->create("wall");

		nlohmann::json j_wall =
		    R"(
			{
				"fixed": true,
				"density" : 0.1,
				"width" : 128.0,
				"height" : 128.0,
				"init-x" : 200.0,
				"init-y" : 200.0,
				"restitution" : 0,
				"static-friction" : 10,
				"dynamic-friction" : 5
			}
			)"_json;

		auto* pc = m_world->create_component<galaxy::physics::BodyWrapper>(e2, j_wall);
		auto* sc = m_world->create_component<galaxy::graphics::Sprite>(e2);
		sc->load("assets/textures/wall_small.png");
		sc->create<galaxy::graphics::BufferDynamic>();
		sc->set_pos(200, 200);

		auto* shader_c = m_world->create_component<galaxy::graphics::Shader>(e2);
		shader_c->load_path("assets/shaders/sprite.vs", "assets/shaders/sprite.fs");
		m_world->set_flag<galaxy::flags::Enabled>(e2);

		auto e = m_world->create("moving_arrow");

		nlohmann::json j =
		    R"(
			{
				"fixed": false,
				"density" : 0.1,
				"width" : 128.0,
				"height" : 32.0,
				"init-x" : 50.0,
				"init-y" : 200.0,
				"restitution" : 0,
				"static-friction" : 10,
				"dynamic-friction" : 5
			}
			)"_json;

		pc          = m_world->create_component<galaxy::physics::BodyWrapper>(e, j);
		m_test_body = static_cast<galaxy::physics::KineticBody*>(pc->m_body.get());

		sc = m_world->create_component<galaxy::graphics::Sprite>(e);
		sc->load("assets/textures/moving_arrow.png");
		sc->create<galaxy::graphics::BufferDynamic>();
		sc->set_pos(50, 200);

		shader_c = m_world->create_component<galaxy::graphics::Shader>(e);
		shader_c->load_path("assets/shaders/sprite.vs", "assets/shaders/sprite.fs");
		m_world->set_flag<galaxy::flags::Enabled>(e);

		m_boop.load("assets/audio/sfx/button.ogg");
		m_boop.set_gain(0.2);
		m_boop.set_pitch(0.2);
		*/
	}

	Sandbox::~Sandbox()
	{
		m_window = nullptr;
	}

	void Sandbox::on_push()
	{
	}

	void Sandbox::on_pop()
	{
	}

	void Sandbox::events()
	{
		m_active_scene->events();
		if (m_window->key_pressed(galaxy::input::Keys::ESC))
		{
			m_window->close();
		}

		/*
		if (m_window->key_pressed(galaxy::input::Keys::SPACE))
		{
			m_test_body->apply_horizontal_force(1.5f);
		}

		if (m_window->mouse_button_pressed(galaxy::input::MouseButton::BUTTON_RIGHT))
		{
			auto [pressed, pos] = m_window->get_cursor_pos();
			m_particle_gen.update_emitter(pos.x, pos.y);
			m_particle_gen.gen_circular("default", 100, 100.0f, 10.0f, 10.0f);
			m_boop.play();
		}
		*/
	}

	void Sandbox::update(const double dt)
	{
		m_active_scene->update(dt);
		//m_particle_gen.update(dt);
	}

	void Sandbox::pre_render()
	{
		m_active_scene->pre_render();
	}

	void Sandbox::render()
	{
		m_active_scene->render();
		/*
		auto* pts = SL_HANDLE.shaderbook()->get("particle");
		pts->bind();
		pts->set_uniform("u_cameraProj", m_camera.get_proj());
		pts->set_uniform("u_cameraView", m_camera.get_transform());
		SL_HANDLE.renderer()->draw_particles(m_particle_gen, *pts);

		auto* ps = SL_HANDLE.shaderbook()->get("point");
		ps->bind();
		ps->set_uniform("u_cameraProj", m_camera.get_proj());
		ps->set_uniform("u_cameraView", m_camera.get_transform());
		SL_HANDLE.renderer()->draw_point(m_point, *ps);

		SL_HANDLE.renderer()->draw_circle(m_circle, *ps);

		m_world->get_system<galaxy::systems::RenderSystem>()->render(m_camera);
		*/
	}
} // namespace sb