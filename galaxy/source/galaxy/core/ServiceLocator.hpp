///
/// ServiceLocator.hpp
/// galaxy
///
/// Created by reworks on 18/02/2018.
/// MIT License.
/// Refer to LICENSE.txt for more details.
///

#ifndef GALAXY_SERVICELOCATOR_HPP_
#define GALAXY_SERVICELOCATOR_HPP_

#include "galaxy/libs/sol2/sol.hpp"

namespace entt
{
	class Dispatcher;
}

namespace galaxy
{
	// This avoids mass includes.
	class World;
	class Window;
	class Box2DHelper;
	class ConfigReader;
	class FontBook;
	class MusicPlayer;
	class ShaderLibrary;
	class SoundPlayer;
	class StateMachine;
	class TextureAtlas;
	class VirtualFS;
	class DebugInterface;

	///
	/// Provides access to services in the framework.
	/// Cannot be created, copied or moved.
	///
	class Locator
	{
	public:
		///
		/// Destructor.
		///
		virtual ~Locator() noexcept = default;

	private:
		///
		/// Default constructor.
		/// Deleted.
		///
		Locator() = delete;

		///
		/// Copy Constructor.
		/// Deleted.
		///
		Locator(const Locator&) = delete;

		///
		/// Move Constructor.
		/// Deleted.
		///
		Locator(Locator&&) = delete;

		///
		/// Copy assignment operator.
		/// Deleted.
		///
		Locator& operator= (const Locator &) = delete;

		///
		/// Move assignment operator.
		/// Deleted.
		///
		Locator& operator= (Locator &&) = delete;

	public:
		///
		/// The main lua instance. Use this when doing lua things.
		///
		static inline sol::state* lua = nullptr;

		///
		/// Pointer to World service.
		///
		static inline World* world = nullptr;
		
		///
		/// Pointer to Window service.
		///
		static inline Window* window = nullptr;
		
		///
		/// Pointer to Box2DManager service.
		///
		static inline Box2DHelper* box2dHelper = nullptr;
		
		///
		/// Pointer to ConfigReader service.
		///
		static inline ConfigReader* configReader = nullptr;

		///
		/// Pointer to the event dispatcher service.
		///
		static inline entt::Dispatcher* dispatcher = nullptr;
		
		///
		/// Pointer to FontBook service.
		///
		static inline FontBook* fontBook = nullptr;

		///
		/// Pointer to MusicPlayer service.
		///		
		static inline MusicPlayer* musicPlayer = nullptr;
		
		///
		/// Pointer to ShaderLibrary service.
		///
		static inline ShaderLibrary* shaderLibrary = nullptr;
		
		///
		/// Pointer to SoundPlayer service.
		///
		static inline SoundPlayer* soundPlayer = nullptr;
		
		///
		/// Pointer to StateMachine service.
		///
		static inline StateMachine* stateMachine = nullptr;
		
		///
		/// Pointer to TextureAtlas service.
		///
		static inline TextureAtlas* textureAtlas = nullptr;
		
		///
		/// Pointer to VirtualFS service.
		///
		static inline VirtualFS* virtualFS = nullptr;
		
		///
		/// Pointer to DebugInterface service.
		///
		#ifdef _DEBUG
			static inline DebugInterface* debugInterface = nullptr;
		#endif
	};
}

#endif