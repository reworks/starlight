
#ifndef BOOST_MPL_MAP_AUX_ERASE_KEY_IMPL_HPP_INCLUDED
#define BOOST_MPL_MAP_AUX_ERASE_KEY_IMPL_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2003-2004
// Copyright David Abrahams 2003-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <sl/libs/boost/mpl/erase_key_fwd.hpp>
#include <sl/libs/boost/mpl/map/aux_/has_key_impl.hpp>
#include <sl/libs/boost/mpl/map/aux_/item.hpp>
#include <sl/libs/boost/mpl/map/aux_/tag.hpp>
#include <sl/libs/boost/mpl/identity.hpp>
#include <sl/libs/boost/mpl/base.hpp>
#include <sl/libs/boost/mpl/eval_if.hpp>

#include <sl/libs/boost/type_traits/is_same.hpp>

namespace boost { namespace mpl {

template<>
struct erase_key_impl< aux::map_tag >
{
    template< 
          typename Map
        , typename Key
        > 
    struct apply
        : eval_if< 
              has_key_impl<aux::map_tag>::apply<Map,Key>
            , eval_if< 
                  is_same< Key,typename Map::key_ > 
                , base<Map>
                , identity< m_mask<Key,Map> >
                >
            , identity<Map>
            >
    {
    };
};

}}

#endif // BOOST_MPL_MAP_AUX_ERASE_KEY_IMPL_HPP_INCLUDED
