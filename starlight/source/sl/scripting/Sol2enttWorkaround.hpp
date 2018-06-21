///
/// Sol2enttWorkaround.hpp
/// starlight
///
/// Created by reworks on 17/02/2018.
/// MIT License.
/// Refer to LICENSE.txt for more details.
///

#ifndef STARLIGHT_SOL2ENTTWORKAROUND_HPP_
#define STARLIGHT_SOL2ENTTWORKAROUND_HPP_

#include "sl/libs/entt/entity/registry.hpp"

namespace sl
{
	///
	/// This class is a workaround because entt's default registry does not play
	/// nice with Sol2's usertype registration.
	///
	class Sol2enttWorkaround
	{
	public:
		///
		/// Default Constructor.
		///
		Sol2enttWorkaround() = default;
		
		///
		/// Default Destructor.
		///
		~Sol2enttWorkaround() = default;

		///
		/// Set the registry to use with the workaround.
		///
		/// \param registry A pointer to the entity registry.
		///
		void setRegistry(entt::DefaultRegistry* registry);

		///
		/// Wrapper for entt's create function.
		///
		/// \return Entity ID for newly created entity.
		///
		entt::DefaultRegistry::entity_type create();

		///
		/// Wrapper for entt's destroy function.
		///
		/// \param entity Entity to destroy.
		///
		void destroy(entt::DefaultRegistry::entity_type entity);

		///
		/// Wrapper for retrieving a component with entt.
		///
		/// \param entity Entity to retrieve the component from.
		///
		template<typename Component>
		Component& get(entt::DefaultRegistry::entity_type entity);

	private:
		///
		/// Pointer to the registry used by the World class.
		///
		entt::DefaultRegistry* m_registry;
	};

	template<typename Component>
	Component& Sol2enttWorkaround::get(entt::DefaultRegistry::entity_type entity)
	{
		return m_registry->get<Component>(entity);
	}

}

#endif