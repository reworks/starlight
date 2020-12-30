///
/// FreeType.hpp
/// galaxy
///
/// Refer to LICENSE.txt for more details.
///

#ifndef GALAXY_GRAPHICS_TEXT_FREETYPE_HPP_
#define GALAXY_GRAPHICS_TEXT_FREETYPE_HPP_

#include <ft2build.h>
#include FT_FREETYPE_H

///
/// Shortcut Macro.
///
#define FTLIB graphics::FreeTypeLib::handle()

///
/// OK return value macro.
///
#define FT_OK 0

namespace galaxy
{
	namespace graphics
	{
		///
		/// Wraps around freetype library initialization.
		///
		class FreeTypeLib final
		{
		public:
			///
			/// Copy constructor.
			///
			FreeTypeLib(const FreeTypeLib&) = delete;

			///
			/// Move constructor.
			///
			FreeTypeLib(FreeTypeLib&&) = delete;

			///
			/// Copy assignment operator.
			///
			FreeTypeLib& operator=(const FreeTypeLib&) = delete;

			///
			/// Move assignment operator.
			///
			FreeTypeLib& operator=(FreeTypeLib&&) = delete;

			///
			/// Destructor.
			///
			~FreeTypeLib() = default;

			///
			/// Get handle to library.
			///
			/// \return Refernce to this static instance.
			///
			static FreeTypeLib& handle();

			///
			/// Open library.
			///
			void open();

			///
			/// Close library.
			///
			void close();

			///
			/// Handle to FT library.
			///
			/// \return Reference to FT_Library.
			///
			[[nodiscard]] FT_Library& lib();

		private:
			///
			/// Constructor.
			///
			FreeTypeLib() = default;

		private:
			///
			/// FreeType library structure.
			///
			FT_Library m_freetype_lib;
		};
	} // namespace graphics
} // namespace galaxy

#endif