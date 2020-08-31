///
/// VertexBuffer.cpp
/// quasar
///
/// Refer to LICENSE.txt for more details.
///

#include <glad/glad.h>

#include "VertexBuffer.hpp"

///
/// Core namespace.
///
namespace qs
{
	VertexBuffer::VertexBuffer() noexcept
	    : m_id {0}, m_size {0}
	{
		glGenBuffers(1, &m_id);
	}

	VertexBuffer::VertexBuffer(VertexBuffer&& vb)
	{
		this->m_id   = vb.m_id;
		this->m_size = vb.m_size;

		vb.m_id   = 0;
		vb.m_size = 0;
	}

	VertexBuffer& VertexBuffer::operator=(VertexBuffer&& vb)
	{
		if (this != &vb)
		{
			this->m_id   = vb.m_id;
			this->m_size = vb.m_size;

			vb.m_id   = 0;
			vb.m_size = 0;
		}

		return *this;
	}

	VertexBuffer::~VertexBuffer() noexcept
	{
		glDeleteBuffers(1, &m_id);
	}

	void VertexBuffer::bind() noexcept
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_id);
	}

	void VertexBuffer::unbind() noexcept
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	const unsigned int VertexBuffer::id() const noexcept
	{
		return m_id;
	}
} // namespace qs