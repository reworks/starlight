///
/// SparseSet.hpp
///
/// solar
/// See LICENSE.txt.
///

#ifndef SOLAR_SPARSESET_HPP_
#define SOLAR_SPARSESET_HPP_

#include <vector>

#include "solar/Config.hpp"

/*
TODO: ITERATORS!!!
*/

namespace sr
{
	///
	/// Fast storage of unsigned integers.
	/// Thanks to: https://www.computist.xyz/2018/06/sparse-sets.html
	///
	template<typename uint>
	class SparseSet
	{
		static_assert(std::is_unsigned<uint>::value, "SparseSet must be an unsigned integer!");

	public:
		SparseSet() noexcept;

		SparseSet(uint reserve) noexcept;

		uint insert(uint element) noexcept;
		
		bool has(uint element) noexcept;

		uint find(uint element) noexcept;

		void reserve(uint reserve) noexcept;
		
		void remove(uint element) noexcept;

		bool empty() noexcept;
		
		void clear() noexcept;

		uint size() const noexcept;

		uint capacity() const noexcept;

		uint operator[](uint element);

		uint operator[](uint element) const;

	private:
		///
		/// Current number of elements in sparse set.
		///
		uint m_size;

		///
		/// Capacity (max value + 1).
		///
		uint m_capacity;

		///
		/// The actual elements are stored here.
		///
		std::vector<uint> m_dense;

		///
		/// The elements are used as an index. They are indexes of the dense array.
		///
		std::vector<uint> m_sparse;
	};

	template<typename uint>
	inline SparseSet<uint>::SparseSet() noexcept
		:m_size(0), m_capacity(0)
	{
	}

	template<typename uint>
	inline SparseSet<uint>::SparseSet(uint reserve) noexcept
		:m_size(0), m_capacity(0)
	{
		reserve(reserve);
	}

	template<typename uint>
	inline uint SparseSet<uint>::insert(uint element) noexcept
	{
		if (element >= m_capacity)
		{
			reserve(m_capacity + 1);
		}

		m_dense[m_size] = element;
		m_sparse[element] = m_size;
		++m_size;

		return m_dense[m_sparse[element]];
	}

	template<typename uint>
	inline bool SparseSet<uint>::has(uint element) noexcept
	{
		bool success = false;

		if (element < m_capacity)
		{
			if (m_sparse[element] < m_size)
			{
				if (m_dense[m_sparse[element]] == element)
				{
					success = true;
				}
			}
		}

		return success;
	}

	template<typename uint>
	inline uint SparseSet<uint>::find(uint element) noexcept
	{
		if (has(element))
		{
			return m_dense[m_sparse[element]];
		}
		else
		{
			return -1;
		}
	}

	template<typename uint>
	inline void SparseSet<uint>::reserve(uint reserve) noexcept
	{
		if (reserve > m_capacity)
		{
			m_dense.resize(reserve, 0);
			m_sparse.resize(reserve, 0);

			m_capacity = reserve;
		}
	}

	template<typename uint>
	inline void SparseSet<uint>::remove(uint element) noexcept
	{
		if (has(element))
		{
			m_dense[m_sparse[element]] = m_dense[m_size - 1];
			m_sparse[m_dense[m_size - 1]] = m_sparse[element];
			--m_size;
		}
	}

	template<typename uint>
	inline bool SparseSet<uint>::empty() noexcept
	{
		return m_size == 0;
	}

	template<typename uint>
	inline void SparseSet<uint>::clear() noexcept
	{
		m_dense.clear();
		m_sparse.clear();

		m_capacity = 0;
		m_size = 0;
	}

	template<typename uint>
	inline uint SparseSet<uint>::size() const noexcept
	{
		return m_size;
	}

	template<typename uint>
	inline uint SparseSet<uint>::capacity() const noexcept
	{
		return m_capacity;
	}

	template<typename uint>
	inline uint SparseSet<uint>::operator[](uint element)
	{
		return find(element);
	}

	template<typename uint>
	inline uint SparseSet<uint>::operator[](uint element) const
	{
		return find(element);
	}
}

#endif