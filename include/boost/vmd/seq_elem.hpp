#if !defined(BOOST_VMD_SEQ_ELEM_HPP)
#define BOOST_VMD_SEQ_ELEM_HPP

#include <boost/vmd/detail/setup.hpp>

#if BOOST_PP_VARIADICS

#include <boost/vmd/detail/elem_after_seq.hpp>
#include <boost/vmd/detail/elem_seq.hpp>

/*

  The succeeding comments in this file are in doxygen format.

*/

/** \file
*/

#define BOOST_VMD_SEQ_ELEM(elem,...) \
	BOOST_VMD_DETAIL_ELEM_SEQ(elem,__VA_ARGS__) \
/**/

#define BOOST_VMD_AFTER_SEQ_ELEM(elem,vseq) \
	BOOST_VMD_DETAIL_ELEM_AFTER_SEQ(elem,vseq) \
/**/

#endif /* BOOST_PP_VARIADICS */
#endif /* BOOST_VMD_SEQ_ELEM_HPP */
