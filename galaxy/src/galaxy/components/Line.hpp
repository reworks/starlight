///
/// Line.hpp
/// galaxy
///
/// Refer to LICENSE.txt for more details.
///

#ifndef GALAXY_COMPONENTS_LINE_HPP_
#define GALAXY_COMPONENTS_LINE_HPP_

#include <nlohmann/json_fwd.hpp>

#include "galaxy/fs/Serializable.hpp"
#include "galaxy/graphics/Colour.hpp"
#include "galaxy/graphics/vertex/VertexData.hpp"

namespace galaxy
{
	namespace components
	{
		///
		/// Line definition for renderer.
		///
		class Line final : public graphics::VertexData, public fs::Serializable
		{
		public:
			///
			/// Constructor.
			///
			Line() noexcept;

			///
			/// Constructor.
			///
			/// \param col Colour of line.
			/// \param x1 X1 position.
			/// \param y1 Y1 position.
			/// \param x2 X2 position.
			/// \param y2 Y2 position.
			///
			Line(const graphics::Colour& col, const float x1, const float y1, const float x2, const float y2) noexcept;

			///
			/// JSON constructor.
			///
			/// \param json JSON defining object.
			///
			Line(const nlohmann::json& json);

			///
			/// Move constructor.
			///
			Line(Line&&) noexcept;

			///
			/// Move assignment operator.
			///
			Line& operator=(Line&&) noexcept;

			///
			/// Destructor.
			///
			virtual ~Line() noexcept = default;

			///
			/// Create the Line.
			///
			/// \param col Colour of line.
			/// \param x1 X1 position.
			/// \param y1 Y1 position.
			/// \param x2 X2 position.
			/// \param y2 Y2 position.
			///
			void create(const graphics::Colour& col, const float x1, const float y1, const float x2, const float y2);

			///
			/// Update vertexs.
			///
			void update();

			///
			/// Change colour.
			///
			/// \param col Colour of line.
			///
			void change_colour(const graphics::Colour& col);

			///
			/// Bind as active VA.
			///
			void bind() noexcept;

			///
			/// Unbind as active VA.
			///
			void unbind() noexcept;

			///
			/// Set opacity.
			///
			/// \param opacity Opacity 0 - 255.
			///
			void set_opacity(const std::uint8_t opacity) noexcept;

			///
			/// Get opacity.
			///
			/// \return Const std::uint8_t.
			///
			[[nodiscard]] const std::uint8_t get_opacity() const noexcept;

			///
			/// Get current colour.
			///
			/// \return Const reference to the current line colour.
			///
			[[nodiscard]] const graphics::Colour& get_colour() const noexcept;

			///
			/// Serializes object.
			///
			/// \return JSON object containing data to be serialized.
			///
			[[nodiscard]] nlohmann::json serialize() override;

			///
			/// Deserializes from object.
			///
			/// \param json Json object to retrieve data from.
			///
			void deserialize(const nlohmann::json& json) override;

		private:
			///
			/// Copy assignment operator.
			///
			Line& operator=(const Line&) = delete;

			///
			/// Copy constructor.
			///
			Line(const Line&) = delete;

		private:
			///
			/// First point.
			///
			glm::vec2 m_point_a;

			///
			/// Second point.
			///
			glm::vec2 m_point_b;

			///
			/// Colour.
			///
			graphics::Colour m_colour;
		};
	} // namespace components
} // namespace galaxy

#endif