///
/// DebugInterface.hpp
/// starlight
///
/// Created by reworks on 20/04/2017.
/// MIT License.
/// Refer to LICENSE.txt for more details.
///

#ifndef STARLIGHT_DEBUGINTERFACE_HPP_
#define STARLIGHT_DEBUGINTERFACE_HPP_

#include <functional>

union ALLEGRO_EVENT;
struct ALLEGRO_DISPLAY;

namespace sl
{
	class BaseState;

    class DebugInterface
    {
    public:
		///
		/// Constructor.
		///
		/// \param display ALLEGRO_DISPLAY object.
		/// \param isDisabled Boolean. Set to true to disable.
		///
		DebugInterface(ALLEGRO_DISPLAY* display, bool isDisabled);

		///
		/// Destructor.
		///
		~DebugInterface();

		///
		/// Process imgui events.
		///
		/// \param event ALLEGRO_EVENT object.
		///
		void event(ALLEGRO_EVENT* event);

		///
		/// Begin new imgui frame.
		///
		void newFrame();

		///
		/// Draw IMGUI.
		///
		void render();

		///
		/// \brief Display menu on screen.
		///
		/// Call between update and render. Calls the functions that make up the main debug menu. ImGui functions mainly.
		///
		void displayMenu();

		///
		/// \brief Set a state to reload too.
		///
		/// func() is called first when reloading.
		///
		/// \param s State pointer to reload to.
		/// \param func Function to cleanup anything that normally isnt cleaned up at that time.
		///
		void setReloadState(std::shared_ptr<BaseState> s, std::function<void(void)> func);

	private:
		///
		/// Default Constructor.
		/// Deleted.
		///
		DebugInterface() = delete;

	private:
		bool m_disabled;
		std::function<void(void)> m_reloadFunc;
		std::shared_ptr<BaseState> m_reloadState;
    };
}

#endif