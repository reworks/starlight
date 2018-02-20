///
/// Box2DManager.hpp
/// starlight
///
/// Created by reworks on 12/11/2016.
/// MIT License.
/// Refer to LICENSE.txt for more details.
///

#ifndef STARLIGHT_BOX2DMANAGER_HPP_
#define STARLIGHT_BOX2DMANAGER_HPP_

#include <map>
#include <functional>

#include "sl/libs/Box2D/Box2D.h"

namespace sl
{
	class Box2DManager
	{
	public:
		///
		/// Constructor. Sets up Box2D systems.
		///
		/// \param gravity A gravity value for Box2D to use in simulations.
		///
		Box2DManager(float32 gravity);

		///
		/// Destructor
		///
		~Box2DManager();

	private:
		///
		/// Default Constructor.
		/// Deleted.
		///
		Box2DManager() = delete;

	public:
		std::unique_ptr<b2World> m_b2world;
	};
}

#endif