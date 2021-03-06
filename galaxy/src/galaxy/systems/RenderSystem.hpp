///
/// RenderSystem.hpp
/// galaxy
///
/// Refer to LICENSE.txt for more details.
///

#ifndef GALAXY_SYSTEMS_RENDERSYSTEM_HPP_
#define GALAXY_SYSTEMS_RENDERSYSTEM_HPP_

#include "galaxy/ecs/Entity.hpp"
#include "galaxy/ecs/System.hpp"
#include "galaxy/graphics/Camera.hpp"
#include "galaxy/graphics/Renderables.hpp"

namespace galaxy
{
	namespace systems
	{
		///
		/// Contains information needed to render an object with OpenGL.
		///
		struct RenderData final
		{
			///
			/// The Entity.
			///
			ecs::Entity m_entity;

			///
			/// The type of renderable.
			///
			graphics::Renderables m_type;

			///
			/// The z level.
			///
			int m_z_level = 0;

			///
			/// Pointer to a transformation.
			///
			components::Transform* m_transform = nullptr;
		};

		///
		/// System that handles rendering of entities with a graphics::Sprite, TransformComponent, etc.
		///
		class RenderSystem final : public ecs::System
		{
			friend class core::World;

		public:
			///
			/// Constructor.
			///
			RenderSystem() noexcept = default;

			///
			/// Destructor.
			///
			virtual ~RenderSystem() noexcept = default;

			///
			/// Abstract implementation for updating the system. Use the manager to retreive your components.
			///
			/// \param world Game World containing entities.
			/// \param dt DeltaTime from gameloop.
			///
			void update(core::World& world, const double dt) override;

			///
			/// Render sprites / textures to screen.
			///
			/// \param world Game World containing entities.
			/// \param camera Camera used for rendering.
			///
			void render(core::World& world, graphics::Camera& camera);

		private:
			///
			/// Stored vector of renderdata to pass to renderer.
			///
			std::vector<RenderData> m_sorted;
		};
	} // namespace systems
} // namespace galaxy

#endif