///
/// RigidBody.cpp
/// galaxy
///
/// Refer to LICENSE.txt for more details.
///

#include <magic_enum.hpp>
#include <nlohmann/json.hpp>

#include "RigidBody.hpp"

namespace galaxy
{
	namespace components
	{
		RigidBody::RigidBody() noexcept
		    : Serializable {this}, m_size {1.0f, 1.0f}, m_type {physics::BodyType::STATIC}
		{
		}

		RigidBody::RigidBody(const nlohmann::json& json)
		    : Serializable {this}, m_type {physics::BodyType::STATIC}
		{
			deserialize(json);
		}

		RigidBody::RigidBody(RigidBody&& rb) noexcept
		    : Serializable {this}
		{
			this->m_size = rb.m_size;
			this->m_aabb = std::move(rb.m_aabb);
			this->m_type = rb.m_type;
		}

		RigidBody& RigidBody::operator=(RigidBody&& rb) noexcept
		{
			if (this != &rb)
			{
				this->m_size = rb.m_size;
				this->m_aabb = std::move(rb.m_aabb);
				this->m_type = rb.m_type;
			}

			return *this;
		}

		const physics::AABB& RigidBody::update_aabb(const float x, const float y)
		{
			const glm::vec2 min = {x, y};
			const glm::vec2 max = {x + m_size.x, y + m_size.y};

			m_aabb = {min, max};

			// Fatten to encompass rotation.
			m_aabb.fatten(0.5f);
			m_aabb.update_area();

			return m_aabb;
		}

		void RigidBody::set_bodytype(const physics::BodyType type) noexcept
		{
			m_type = type;
		}

		void RigidBody::set_size(const glm::vec2& size) noexcept
		{
			m_size = size;
		}

		void RigidBody::set_size(const float width, const float height) noexcept
		{
			m_size.x = width;
			m_size.y = height;
		}

		const physics::AABB& RigidBody::get_aabb() const noexcept
		{
			return m_aabb;
		}

		const physics::BodyType RigidBody::get_type() const noexcept
		{
			return m_type;
		}

		nlohmann::json RigidBody::serialize()
		{
			// clang-format off
			nlohmann::json json = "{}"_json;
			json["type"] = magic_enum::enum_name(m_type);
			json["width"] = m_size.x;
			json["height"] = m_size.y;
			// clang-format on

			return json;
		}

		void RigidBody::deserialize(const nlohmann::json& json)
		{
			m_type   = magic_enum::enum_cast<physics::BodyType>(json.at("type").get<std::string>()).value();
			m_size.x = json["width"];
			m_size.y = json["height"];
		}
	} // namespace components
} // namespace galaxy