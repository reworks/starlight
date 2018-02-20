
#ifndef BOOST_MPL_INDEX_IF_HPP_INCLUDED
#define BOOST_MPL_INDEX_IF_HPP_INCLUDED

// Copyright Eric Friedman 2003
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <sl/libs/boost/mpl/aux_/find_if_pred.hpp>
#include <sl/libs/boost/mpl/begin_end.hpp>
#include <sl/libs/boost/mpl/if.hpp>
#include <sl/libs/boost/mpl/int.hpp>
#include <sl/libs/boost/mpl/iter_fold_if.hpp>
#include <sl/libs/boost/mpl/next.hpp>
#include <sl/libs/boost/mpl/void.hpp>
#include <sl/libs/boost/mpl/aux_/na_spec.hpp>
#include <sl/libs/boost/mpl/aux_/lambda_support.hpp>
#include <sl/libs/boost/type_traits/is_same.hpp>

namespace boost { namespace mpl {

template<
      typename BOOST_MPL_AUX_NA_PARAM(Sequence)
    , typename BOOST_MPL_AUX_NA_PARAM(Predicate)
    >
struct index_if
{
    typedef typename iter_fold_if<
          Sequence
        , int_<0>
        , next<>
        , aux::find_if_pred<Predicate>
        >::type result_;

    typedef typename end<Sequence>::type not_found_;
    typedef typename first<result_>::type result_index_;
    typedef typename second<result_>::type result_iterator_;

    typedef typename if_<
          is_same< result_iterator_,not_found_ >
        , void_
        , result_index_
        >::type type;

    BOOST_MPL_AUX_LAMBDA_SUPPORT(2,index_if,(Sequence,Predicate))
};

BOOST_MPL_AUX_NA_SPEC(2, index_if)

}}

#endif // BOOST_MPL_INDEX_IF_HPP_INCLUDED
