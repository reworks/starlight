///
/// VertexData.hpp
/// galaxy
///
/// Refer to LICENSE.txt for more details.
///

#ifndef GALAXY_GRAPHICS_VERTEX_VERTEXDATA_HPP_
#define GALAXY_GRAPHICS_VERTEX_VERTEXDATA_HPP_

#include "galaxy/graphics/vertex/VertexArray.hpp"

namespace galaxy
{
	namespace graphics
	{
		///
		/// Provides a class with a method of rendering to screen.
		///
		class VertexData
		{
		public:
			///
			/// Constructor.
			///
			VertexData();

			///
			/// Copy constructor.
			///
			VertexData(const VertexData&) = delete;

			///
			/// Move constructor.
			///
			VertexData(VertexData&&);

			///
			/// Copy assignment operator.
			///
			VertexData& operator=(const VertexData&) = delete;

			///
			/// Move assignment operator.
			///
			VertexData& operator=(VertexData&&);

			///
			/// Virtual destructor.
			///
			virtual ~VertexData() = default;

			///
			/// Set z-level of sprite.
			///
			/// \param z_level z-ordering level to render sprite at.
			///
			void set_z_level(const unsigned int z_level);

			///
			/// Set opacity.
			///
			/// Only affects the currently active quad.
			///
			/// \param opacity Opacity range is from 0.0f (transparent) to 1.0f (opaque).
			///
			void set_opacity(const float opacity);

			///
			/// Get z-level of vertexs.
			///
			/// \return Const unsigned integer.
			///
			[[nodiscard]] const unsigned int z_level() const;

			///
			/// Get opacity.
			///
			/// \return Const float.
			///
			[[nodiscard]] const float opacity() const;

			///
			/// Get IBO.
			///
			/// \return Reference to IBO.
			///
			[[nodiscard]] IndexBuffer& get_ibo();

			///
			/// Get VBO.
			///
			/// \return Reference to VBO.
			///
			[[nodiscard]] VertexBuffer& get_vbo();

			///
			/// Get VAO.
			///
			/// \return Reference to VAO.
			///
			[[nodiscard]] VertexArray& get_vao();

			///
			/// Get index count.
			///
			/// \return Const unsigned integer.
			///
			[[nodiscard]] const unsigned int index_count() const;

		protected:
			///
			/// Opacity of sprite.
			///
			float m_opacity;

			///
			/// Z-Level
			///
			unsigned int m_z_level;

			///
			/// OpenGL Vertex Array Object.
			///
			VertexArray m_va;

			///
			/// Vertex buffer.
			///
			VertexBuffer m_vb;

			///
			/// Index (Element) buffer.
			///
			IndexBuffer m_ib;

			///
			/// Vertex layout.
			///
			VertexLayout m_layout;
		};
	} // namespace graphics
} // namespace galaxy

#endif