///
///  LevelTag.cpp
///  starlight
///
///  Created by reworks on 21/11/2017.
///  Copyright (c) 2018+ reworks.
///  Refer to LICENSE.txt for more details.
///

#include "sol2/sol.hpp"
#include "re/fs/VFS.hpp"
#include "re/services/ServiceLocator.hpp"

#include "Level.hpp"

namespace sl
{
	Level::Level(const std::string& script)
	{
		sol::state lua;
		lua.script(VFS::get()->openAsString(script));
		sol::table level = lua.get<sol::table>("level");

		std::string mapData = Locator::get<VFS>()->openAsString("map");
		m_map = tmx_load_buffer(mapData.c_str(), mapData.length());

		m_bounds.x = 0;
		m_bounds.y = 0;
		m_bounds.width = m_map->width;
		m_bounds.height = m_map->height;
	}

	Level::~Level()
	{
		tmx_map_free(m_map);
	}

	const Rect<float, int>& Level::getBounds() const
	{
		return m_bounds;
	}

	void Level::addAnimatedTile(AnimatedTile& tile)
	{
		m_animatedTiles.emplace_back(tile);
	}
}