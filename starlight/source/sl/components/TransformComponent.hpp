///
/// TransformComponent.hpp
/// starlight
///
/// Created by reworks on 30/09/2016.
/// MIT License.
/// Refer to LICENSE.txt for more details.
///

#ifndef STARLIGHT_TRANSFORMCOMPONENT_HPP_
#define STARLIGHT_TRANSFORMCOMPONENT_HPP_

#include "sl/math/Rect.hpp"
#include "sl/libs/cereal/access.hpp"
#include "sl/libs/sol2/sol_forward.hpp"

namespace sl
{
	class TransformComponent final
	{
		friend class cereal::access;

	public:
		///
		/// Constructor.
		///
		/// \param table sol::table containing data.
		///
		TransformComponent(const sol::table& table);

		///
		/// Alternate Constructor.
		///
		/// \param layer Layer to render on.
		/// \param angle Angle to render at.
		/// \param rect Position x, y and Dimensions width, height.
		///
		TransformComponent(int layer, float angle, const Rect<float, int>& rect);

		///
		/// Destructor.
		///
		~TransformComponent() = default;

		///
		/// Default move assignment overload.
		///
		TransformComponent& operator=(const TransformComponent&);

	private:
		///
		/// Default constructor.
		/// Deleted.
		///
		TransformComponent() = delete;

		///
		/// Cereal serialize function.
		///
		template<class Archive>
		void serialize(Archive& ar)
		{
			ar(m_layer, m_angle, m_rect);
		}

	public:
		int m_layer;
		float m_angle;
		Rect<float, int> m_rect;
	};
}

#endif