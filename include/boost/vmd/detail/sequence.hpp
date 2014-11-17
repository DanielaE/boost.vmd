#if !defined(BOOST_VMD_DETAIL_SEQUENCE_HPP)
#define BOOST_VMD_DETAIL_SEQUENCE_HPP

#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/array/push_back.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/comparison/greater.hpp>
#include <boost/preprocessor/comparison/less_equal.hpp>
#include <boost/preprocessor/comparison/not_equal.hpp>
#include <boost/preprocessor/control/expr_iif.hpp>
#include <boost/preprocessor/control/iif.hpp>
#include <boost/preprocessor/control/while.hpp>
#include <boost/preprocessor/list/append.hpp>
#include <boost/preprocessor/list/transform.hpp>
#include <boost/preprocessor/logical/bitor.hpp>
#include <boost/preprocessor/logical/not.hpp>
#include <boost/preprocessor/seq/elem.hpp>
#include <boost/preprocessor/seq/push_back.hpp>
#include <boost/preprocessor/seq/size.hpp>
#include <boost/preprocessor/seq/to_array.hpp>
#include <boost/preprocessor/seq/to_tuple.hpp>
#include <boost/preprocessor/seq/transform.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/tuple/enum.hpp>
#include <boost/preprocessor/tuple/pop_front.hpp>
#include <boost/preprocessor/tuple/push_back.hpp>
#include <boost/preprocessor/tuple/replace.hpp>
#include <boost/preprocessor/tuple/size.hpp>
#include <boost/preprocessor/variadic/elem.hpp>
#include <boost/preprocessor/variadic/size.hpp>
#include <boost/preprocessor/variadic/to_tuple.hpp>
#include <boost/vmd/array.hpp>
#include <boost/vmd/empty.hpp>
#include <boost/vmd/identifier.hpp>
#include <boost/vmd/identity.hpp>
#include <boost/vmd/is_begin_tuple.hpp>
#include <boost/vmd/is_empty.hpp>
#include <boost/vmd/list.hpp>
#include <boost/vmd/number.hpp>
#include <boost/vmd/seq.hpp>
#include <boost/vmd/tuple.hpp>
#include <boost/vmd/types.hpp>
#include <boost/vmd/detail/empty_result.hpp>
#include <boost/vmd/detail/is_from.hpp>

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_INPUT_ELEM 0
#define BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ELEM 1
#define BOOST_VMD_DETAIL_SEQUENCE_STATE_ELEM_ELEM 2
#define BOOST_VMD_DETAIL_SEQUENCE_STATE_OUTTYPE_ELEM 3
#define BOOST_VMD_DETAIL_SEQUENCE_STATE_FROM_ELEM 4
#define BOOST_VMD_DETAIL_SEQUENCE_STATE_TYPES_ELEM 5
#define BOOST_VMD_DETAIL_SEQUENCE_STATE_INDEX_ELEM 6

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_INPUT(state) \
	BOOST_PP_TUPLE_ELEM(BOOST_VMD_DETAIL_SEQUENCE_STATE_INPUT_ELEM,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT(state) \
	BOOST_PP_TUPLE_ELEM(BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ELEM,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_ELEM(state) \
		BOOST_PP_TUPLE_ELEM(BOOST_VMD_DETAIL_SEQUENCE_STATE_ELEM_ELEM,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_OUTTYPE(state) \
		BOOST_PP_TUPLE_ELEM(BOOST_VMD_DETAIL_SEQUENCE_STATE_OUTTYPE_ELEM,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_FROM(state) \
		BOOST_PP_TUPLE_ELEM(BOOST_VMD_DETAIL_SEQUENCE_STATE_FROM_ELEM,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_TYPES(state) \
		BOOST_PP_TUPLE_ELEM(BOOST_VMD_DETAIL_SEQUENCE_STATE_TYPES_ELEM,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_INDEX(state) \
		BOOST_PP_TUPLE_ELEM(BOOST_VMD_DETAIL_SEQUENCE_STATE_INDEX_ELEM,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_IS_EMPTY(state) \
	BOOST_VMD_IS_EMPTY \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT(state) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD_FROM_EMPTY(state,ttuple) \
	(ttuple) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD_TO_SEQ(state,ttuple) \
	BOOST_PP_SEQ_PUSH_BACK(BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT(state),ttuple) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD_TO_TUPLE(state,ttuple) \
	BOOST_PP_TUPLE_PUSH_BACK(BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT(state),ttuple) \
/**/

// Array

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD_2(state,ttuple) \
	BOOST_PP_ARRAY_PUSH_BACK(BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT(state),ttuple) \
/**/

// List

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD_3(state,ttuple) \
	BOOST_PP_LIST_APPEND(BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT(state),(ttuple,BOOST_PP_NIL)) \
/**/

// Seq

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD_4(state,ttuple) \
	BOOST_PP_IIF \
	 	( \
	 	BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_IS_EMPTY(state), \
	 	BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD_FROM_EMPTY, \
	 	BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD_TO_SEQ \
	 	) \
	 (state,ttuple) \
/**/

// Tuple

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD_5(state,ttuple) \
	BOOST_PP_IIF \
	 	( \
	 	BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_IS_EMPTY(state), \
	 	BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD_FROM_EMPTY, \
	 	BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD_TO_TUPLE \
	 	) \
	 (state,ttuple) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD_GET_NAME(state) \
	BOOST_PP_CAT \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD_, \
		BOOST_VMD_DETAIL_SEQUENCE_STATE_OUTTYPE(state) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD_PROCESS(name,state,ttuple) \
	name(state,ttuple) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD(state,ttuple) \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD_PROCESS(BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD_GET_NAME(state),state,ttuple) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_PROCESSING_ELEM_CHECK(d,state) \
	BOOST_PP_EQUAL_D \
		( \
		d, \
		BOOST_PP_SEQ_SIZE(BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT(state)), \
		BOOST_VMD_DETAIL_SEQUENCE_STATE_ELEM(state) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_PROCESSING_IELEM(d,state) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_IS_EMPTY(BOOST_VMD_DETAIL_SEQUENCE_STATE_ELEM(state)), \
		BOOST_VMD_IDENTITY(0), \
		BOOST_VMD_DETAIL_SEQUENCE_PROCESSING_ELEM_CHECK \
		) \
	(d,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_PROCESSING_ELEM(d,state) \
	BOOST_VMD_IDENTITY_RESULT(BOOST_VMD_DETAIL_SEQUENCE_PROCESSING_IELEM(d,state)) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_GET_TYPE(state) \
		BOOST_PP_TUPLE_ELEM \
			( \
			0, \
			BOOST_PP_TUPLE_ELEM(BOOST_VMD_DETAIL_SEQUENCE_STATE_INDEX(state),BOOST_VMD_DETAIL_SEQUENCE_STATE_TYPES(state)) \
			) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_GET_TYPE_REENTRANT(state) \
		BOOST_PP_TUPLE_ELEM \
			( \
			1, \
			BOOST_PP_TUPLE_ELEM(BOOST_VMD_DETAIL_SEQUENCE_STATE_INDEX(state),BOOST_VMD_DETAIL_SEQUENCE_STATE_TYPES(state)) \
			) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_INNER_OP_UNKNOWN(d,state) \
	( \
	, \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD(state,(BOOST_VMD_TYPE_UNKNOWN,BOOST_VMD_DETAIL_SEQUENCE_STATE_INPUT(state))), \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_ELEM(state), \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_OUTTYPE(state), \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_FROM(state), \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_TYPES(state), \
	BOOST_PP_INC(BOOST_VMD_DETAIL_SEQUENCE_STATE_INDEX(state)) \
	) \
/**/

#define	BOOST_VMD_DETAIL_SEQUENCE_GET_FULL_TYPE(state) \
	BOOST_PP_CAT \
		( \
		BOOST_VMD_TYPE_, \
		BOOST_VMD_DETAIL_SEQUENCE_STATE_GET_TYPE(state) \
		) \
/**/

#define	BOOST_VMD_DETAIL_SEQUENCE_TYPE_FOUND_PROCESS(state,tuple) \
	( \
	BOOST_PP_TUPLE_ELEM(1,tuple), \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD \
		( \
		state, \
			( \
			BOOST_VMD_DETAIL_SEQUENCE_GET_FULL_TYPE(state), \
			BOOST_PP_TUPLE_ELEM(0,tuple) \
			) \
		), \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_ELEM(state), \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_OUTTYPE(state), \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_FROM(state), \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_TYPES(state), \
	BOOST_PP_INC(BOOST_PP_TUPLE_SIZE(BOOST_VMD_DETAIL_SEQUENCE_STATE_TYPES(state))) \
	) \
/**/

#define	BOOST_VMD_DETAIL_SEQUENCE_TYPE_FOUND_SEQ_SINGLE(tuple) \
	BOOST_PP_EQUAL(BOOST_PP_SEQ_SIZE(BOOST_PP_TUPLE_ELEM(0,tuple)),1) \
/**/

#define	BOOST_VMD_DETAIL_SEQUENCE_TYPE_FOUND_ISEQ(state,tuple) \
	BOOST_PP_IIF \
		( \
		BOOST_PP_EQUAL \
			( \
			BOOST_VMD_DETAIL_SEQUENCE_GET_FULL_TYPE(state), \
			BOOST_VMD_TYPE_SEQ \
			), \
		BOOST_VMD_DETAIL_SEQUENCE_TYPE_FOUND_SEQ_SINGLE, \
		BOOST_VMD_IDENTITY(0) \
		) \
	(tuple) \
/**/

#define	BOOST_VMD_DETAIL_SEQUENCE_TYPE_FOUND_SEQ(state,tuple) \
	BOOST_VMD_IDENTITY_RESULT(BOOST_VMD_DETAIL_SEQUENCE_TYPE_FOUND_ISEQ(state,tuple)) \
/**/

#define	BOOST_VMD_DETAIL_SEQUENCE_TYPE_FOUND(state,tuple) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_TYPE_FOUND_SEQ(state,tuple), \
		BOOST_VMD_DETAIL_SEQUENCE_INCREMENT_INDEX, \
		BOOST_VMD_DETAIL_SEQUENCE_TYPE_FOUND_PROCESS \
		) \
	(state,tuple) \
/**/

#define	BOOST_VMD_DETAIL_SEQUENCE_INCREMENT_INDEX(state,tuple) \
	BOOST_PP_TUPLE_REPLACE(state,BOOST_VMD_DETAIL_SEQUENCE_STATE_INDEX_ELEM,BOOST_PP_INC(BOOST_VMD_DETAIL_SEQUENCE_STATE_INDEX(state))) \
/**/

#define	BOOST_VMD_DETAIL_SEQUENCE_TEST_TYPE_TUPLE(state,tuple) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_IS_EMPTY \
			( \
			BOOST_PP_TUPLE_ELEM(0,tuple) \
			), \
		BOOST_VMD_DETAIL_SEQUENCE_INCREMENT_INDEX, \
		BOOST_VMD_DETAIL_SEQUENCE_TYPE_FOUND \
		) \
	(state,tuple) \
/**/

#define	BOOST_VMD_DETAIL_SEQUENCE_TEST_TYPE(d,call,state) \
	BOOST_VMD_DETAIL_SEQUENCE_TEST_TYPE_TUPLE \
		( \
		state, \
		call(BOOST_VMD_DETAIL_SEQUENCE_STATE_INPUT(state)) \
		) \
/**/
	
#define	BOOST_VMD_DETAIL_SEQUENCE_TEST_TYPE_D(d,call,state) \
	BOOST_VMD_DETAIL_SEQUENCE_TEST_TYPE_TUPLE \
		( \
		state, \
		call(d,BOOST_VMD_DETAIL_SEQUENCE_STATE_INPUT(state)) \
		) \
/**/
	
#define BOOST_VMD_DETAIL_SEQUENCE_GCLRT(state) \
	BOOST_PP_CAT \
		( \
		BOOST_VMD_, \
		BOOST_PP_CAT(BOOST_VMD_DETAIL_SEQUENCE_STATE_GET_TYPE(state),_D) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_GCLPL(state) \
	BOOST_PP_CAT \
		( \
		BOOST_VMD_, \
		BOOST_VMD_DETAIL_SEQUENCE_STATE_GET_TYPE(state) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_INNER_OP_TEST_GCL(state,rflag) \
	BOOST_PP_IIF \
		( \
		rflag, \
		BOOST_VMD_DETAIL_SEQUENCE_GCLRT, \
		BOOST_VMD_DETAIL_SEQUENCE_GCLPL \
		) \
	(state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_INNER_OP_TEST_RT_CALL(d,call,state,rflag) \
	BOOST_PP_IIF \
		( \
		rflag, \
		BOOST_VMD_DETAIL_SEQUENCE_TEST_TYPE_D, \
		BOOST_VMD_DETAIL_SEQUENCE_TEST_TYPE \
		) \
	(d,call,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_INNER_OP_TEST_RT(d,state,rflag) \
	BOOST_VMD_DETAIL_SEQUENCE_INNER_OP_TEST_RT_CALL \
		( \
		d, \
		BOOST_VMD_DETAIL_SEQUENCE_INNER_OP_TEST_GCL(state,rflag), \
		state, \
		rflag \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_INNER_OP_TEST(d,state) \
	BOOST_VMD_DETAIL_SEQUENCE_INNER_OP_TEST_RT \
		( \
		d, \
		state, \
		BOOST_VMD_DETAIL_SEQUENCE_STATE_GET_TYPE_REENTRANT(state) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_INNER_OP(d,state) \
	BOOST_PP_IIF \
		( \
		BOOST_PP_EQUAL \
			( \
			BOOST_VMD_DETAIL_SEQUENCE_STATE_INDEX(state), \
			BOOST_PP_TUPLE_SIZE(BOOST_VMD_DETAIL_SEQUENCE_STATE_TYPES(state)) \
			), \
		BOOST_VMD_DETAIL_SEQUENCE_INNER_OP_UNKNOWN, \
		BOOST_VMD_DETAIL_SEQUENCE_INNER_OP_TEST \
		) \
	(d,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_INNER_PRED(d,state) \
	BOOST_PP_NOT_EQUAL \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_STATE_INDEX(state), \
		BOOST_PP_INC(BOOST_PP_TUPLE_SIZE(BOOST_VMD_DETAIL_SEQUENCE_STATE_TYPES(state))) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_OP_PAREN_TUPLE_TYPES_ELEM_FROM(d,from) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_DETAIL_IS_RETURN_GENERAL_TUPLE_TYPE(from), \
		((SEQ,1),(TUPLE,0)), \
		BOOST_PP_IIF \
			( \
			BOOST_VMD_DETAIL_IS_RETURN_EXACT_TYPE(from), \
			((SEQ,1),(LIST,1),(ARRAY,0),(TUPLE,0)), \
			BOOST_PP_IIF \
				( \
				BOOST_VMD_DETAIL_IS_SPECIFIC_ARRAY(from), \
				((SEQ,1),(ARRAY,0),(TUPLE,0)), \
				BOOST_PP_IIF \
					( \
					BOOST_VMD_DETAIL_IS_SPECIFIC_LIST(from), \
					((SEQ,1),(LIST,1),(TUPLE,0)), \
					((SEQ,1),(TUPLE,0)) \
					) \
				) \
			) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_OP_PAREN_TUPLE_TYPES_ELEM(d,state) \
	BOOST_VMD_DETAIL_SEQUENCE_OP_PAREN_TUPLE_TYPES_ELEM_FROM \
		( \
		d, \
		BOOST_VMD_DETAIL_SEQUENCE_STATE_FROM(state) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_OP_PAREN_TUPLE_TYPES_ANY_NOE_CHC(d,state) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_DETAIL_IS_RETURN_GENERAL_TUPLE_TYPE(BOOST_VMD_DETAIL_SEQUENCE_STATE_FROM(state)), \
		((SEQ,1),(TUPLE,0)), \
		((SEQ,1),(LIST,1),(ARRAY,0),(TUPLE,0)) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_OP_PAREN_TUPLE_TYPES_ANY_INOE(d,state) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_IS_EMPTY \
			( \
			BOOST_VMD_DETAIL_SEQUENCE_STATE_FROM(state) \
			), \
		BOOST_VMD_IDENTITY(((SEQ,1),(LIST,1),(ARRAY,0),(TUPLE,0))), \
		BOOST_VMD_DETAIL_SEQUENCE_OP_PAREN_TUPLE_TYPES_ANY_NOE_CHC \
		) \
	(d,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_OP_PAREN_TUPLE_TYPES_ANY_NOE(d,state) \
	BOOST_VMD_IDENTITY_RESULT(BOOST_VMD_DETAIL_SEQUENCE_OP_PAREN_TUPLE_TYPES_ANY_INOE(d,state)) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_OP_PAREN_TUPLE_TYPES_IANY(d,state) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_IS_EMPTY \
			( \
			BOOST_VMD_DETAIL_SEQUENCE_STATE_ELEM(state) \
			), \
		BOOST_VMD_DETAIL_SEQUENCE_OP_PAREN_TUPLE_TYPES_ANY_NOE, \
		BOOST_VMD_IDENTITY(((SEQ,1),(TUPLE,0))) \
		) \
	(d,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_OP_PAREN_TUPLE_TYPES_ANY(d,state) \
	BOOST_VMD_IDENTITY_RESULT(BOOST_VMD_DETAIL_SEQUENCE_OP_PAREN_TUPLE_TYPES_IANY(d,state)) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_OP_PAREN_TUPLE_TYPES(d,state) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_PROCESSING_ELEM(d,state), \
		BOOST_VMD_DETAIL_SEQUENCE_OP_PAREN_TUPLE_TYPES_ELEM, \
		BOOST_VMD_DETAIL_SEQUENCE_OP_PAREN_TUPLE_TYPES_ANY \
		) \
	(d,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_OP_PAREN(d,state) \
	BOOST_PP_WHILE_ ## d \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_INNER_PRED, \
		BOOST_VMD_DETAIL_SEQUENCE_INNER_OP, \
		BOOST_PP_TUPLE_PUSH_BACK \
			( \
			BOOST_PP_TUPLE_PUSH_BACK \
				( \
				state, \
				BOOST_VMD_DETAIL_SEQUENCE_OP_PAREN_TUPLE_TYPES(d,state) \
				), \
			0 \
			) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_OP_ID_LOOP(d,state) \
	BOOST_PP_WHILE_ ## d \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_INNER_PRED, \
		BOOST_VMD_DETAIL_SEQUENCE_INNER_OP, \
		BOOST_PP_TUPLE_PUSH_BACK(BOOST_PP_TUPLE_PUSH_BACK(state,((NUMBER,0),(IDENTIFIER,1))),0) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_OP_ID_EL(d,state) \
	( \
	BOOST_VMD_AFTER_LIST_D(d,BOOST_VMD_DETAIL_SEQUENCE_STATE_INPUT(state)), \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD(state,(BOOST_VMD_TYPE_LIST,BOOST_PP_NIL)), \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_ELEM(state), \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_OUTTYPE(state), \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_FROM(state) \
	) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_OP_ID(d,state) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_IS_EMPTY_LIST \
			( \
			BOOST_VMD_BEGIN_IDENTIFIER \
				( \
				BOOST_VMD_DETAIL_SEQUENCE_STATE_INPUT(state) \
				) \
			), \
		BOOST_VMD_DETAIL_SEQUENCE_OP_ID_EL, \
		BOOST_VMD_DETAIL_SEQUENCE_OP_ID_LOOP \
		) \
	(d,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_OP_REDUCE_STATE(state) \
	( \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_INPUT(state), \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT(state), \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_ELEM(state), \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_OUTTYPE(state), \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_FROM(state) \
	) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_OP(d,state) \
	BOOST_VMD_DETAIL_SEQUENCE_OP_REDUCE_STATE \
		( \
		BOOST_PP_IIF \
			( \
			BOOST_VMD_IS_BEGIN_TUPLE \
				( \
				BOOST_VMD_DETAIL_SEQUENCE_STATE_INPUT(state) \
				), \
			BOOST_VMD_DETAIL_SEQUENCE_OP_PAREN, \
			BOOST_VMD_DETAIL_SEQUENCE_OP_ID \
			) \
		(d,state) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_PRED_CELEM_SZ(d,state) \
	BOOST_PP_LESS_EQUAL_D \
		( \
		d, \
		BOOST_PP_SEQ_SIZE(BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT(state)), \
		BOOST_VMD_DETAIL_SEQUENCE_STATE_ELEM(state) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_PRED_CELEM(d,state) \
	BOOST_VMD_IDENTITY_RESULT(BOOST_VMD_DETAIL_SEQUENCE_PRED_ICELEM(d,state)) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_PRED_ICELEM(d,state) \
	BOOST_PP_IIF \
		( \
		BOOST_PP_BITOR \
			( \
			BOOST_VMD_IS_EMPTY \
				( \
				BOOST_VMD_DETAIL_SEQUENCE_STATE_ELEM(state) \
				), \
			BOOST_VMD_IS_EMPTY \
				( \
				BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT(state) \
				) \
			), \
		BOOST_VMD_IDENTITY(1), \
		BOOST_VMD_DETAIL_SEQUENCE_PRED_CELEM_SZ \
		) \
	(d,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_PRED(d,state) \
	BOOST_VMD_IDENTITY_RESULT(BOOST_VMD_DETAIL_SEQUENCE_IPRED(d,state)) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_IPRED(d,state) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_IS_EMPTY \
			( \
			BOOST_VMD_DETAIL_SEQUENCE_STATE_INPUT(state) \
			), \
		BOOST_VMD_IDENTITY(0), \
		BOOST_VMD_DETAIL_SEQUENCE_PRED_CELEM \
		) \
	(d,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_EMPTY_TYPE_CHECK(output) \
	BOOST_PP_IIF \
		( \
		BOOST_PP_EQUAL(output,BOOST_VMD_TYPE_ARRAY), \
		(0,()), \
		BOOST_PP_NIL \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_EMPTY_TYPE(output) \
	BOOST_PP_IIF \
		( \
		BOOST_PP_BITOR \
			( \
			BOOST_PP_EQUAL(output,BOOST_VMD_TYPE_SEQ), \
			BOOST_PP_EQUAL(output,BOOST_VMD_TYPE_TUPLE) \
			), \
		BOOST_VMD_EMPTY, \
		BOOST_VMD_DETAIL_SEQUENCE_EMPTY_TYPE_CHECK \
		) \
	(output) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS(vseq,elem,...) \
	BOOST_PP_TUPLE_ELEM \
		( \
		0, \
		BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_TUPLE(vseq,elem,__VA_ARGS__) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_D(d,vseq,elem,...) \
	BOOST_PP_TUPLE_ELEM \
		( \
		0, \
		BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_TUPLE_D(d,vseq,elem,__VA_ARGS__) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_TUPLE_GET(state) \
	( \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT(state), \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_INPUT(state) \
	) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_TUPLE_GET_OUTPUT(...) \
	BOOST_PP_VARIADIC_ELEM(0,__VA_ARGS__) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_TUPLE_GET_IFROM(...) \
	BOOST_PP_IIF \
		( \
		BOOST_PP_EQUAL \
			( \
			BOOST_PP_VARIADIC_SIZE(__VA_ARGS__), \
			1 \
			), \
		BOOST_VMD_IDENTITY(BOOST_VMD_RETURN_EXACT_TYPE), \
		BOOST_PP_VARIADIC_ELEM \
		) \
	(1,__VA_ARGS__) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_TUPLE_GET_FROM(...) \
	BOOST_VMD_IDENTITY_RESULT(BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_TUPLE_GET_IFROM(__VA_ARGS__)) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_TUPLE(vseq,elem,...) \
	BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_TUPLE_GET \
		( \
		BOOST_PP_WHILE \
			( \
			BOOST_VMD_DETAIL_SEQUENCE_PRED, \
			BOOST_VMD_DETAIL_SEQUENCE_OP, \
				( \
				vseq, \
				BOOST_VMD_DETAIL_SEQUENCE_EMPTY_TYPE \
					( \
					BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_TUPLE_GET_OUTPUT(__VA_ARGS__) \
					), \
				elem, \
				BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_TUPLE_GET_OUTPUT(__VA_ARGS__), \
				BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_TUPLE_GET_FROM(__VA_ARGS__) \
				) \
			) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_TUPLE_D(d,vseq,elem,...) \
	BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_TUPLE_GET \
		( \
		BOOST_PP_WHILE_ ## d \
			( \
			BOOST_VMD_DETAIL_SEQUENCE_PRED, \
			BOOST_VMD_DETAIL_SEQUENCE_OP, \
				( \
				vseq, \
				BOOST_VMD_DETAIL_SEQUENCE_EMPTY_TYPE \
					( \
					BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_TUPLE_GET_OUTPUT(__VA_ARGS__) \
					), \
				elem, \
				BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_TUPLE_GET_OUTPUT(__VA_ARGS__), \
				BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_TUPLE_GET_FROM(__VA_ARGS__) \
				) \
			) \
		) \
/**/

/*--------------------------------------------------------------------------------------------------------------------------*/

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM_FSEQ_CHELM(seq,elem) \
	BOOST_PP_IIF \
		( \
		BOOST_PP_GREATER(BOOST_PP_SEQ_SIZE(seq),elem), \
		BOOST_PP_SEQ_ELEM, \
		BOOST_VMD_EMPTY \
		) \
	(elem,seq) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM_FSEQ(seq,elem) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_IS_EMPTY(seq), \
		BOOST_VMD_EMPTY, \
		BOOST_VMD_DETAIL_SEQUENCE_ELEM_FSEQ_CHELM \
		) \
	(seq,elem) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM_SPLIT_FSEQ_CHELM_EXTRACT(tuple,elem) \
	BOOST_PP_TUPLE_REPLACE \
		( \
		tuple, \
		0, \
		BOOST_PP_SEQ_ELEM(elem,BOOST_PP_TUPLE_ELEM(0,tuple)) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM_SPLIT_FSEQ_CHELM(tuple,elem) \
	BOOST_PP_IIF \
		( \
		BOOST_PP_GREATER(BOOST_PP_SEQ_SIZE(BOOST_PP_TUPLE_ELEM(0,tuple)),elem), \
		BOOST_VMD_DETAIL_SEQUENCE_ELEM_SPLIT_FSEQ_CHELM_EXTRACT, \
		BOOST_VMD_DETAIL_EMPTY_RESULT \
		) \
	(tuple,elem) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM_SPLIT_FSEQ(tuple,elem) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_IS_EMPTY(BOOST_PP_TUPLE_ELEM(0,tuple)), \
		BOOST_VMD_DETAIL_EMPTY_RESULT, \
		BOOST_VMD_DETAIL_SEQUENCE_ELEM_SPLIT_FSEQ_CHELM \
		) \
	(tuple,elem) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_TO_TUPLE_RP(seq) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_IS_EMPTY(seq), \
		BOOST_VMD_EMPTY, \
		BOOST_PP_SEQ_TO_TUPLE \
		) \
	(seq) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_TO_ARRAY_RP_EMPTY(seq) \
	(0,()) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_TO_ARRAY_RP(seq) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_IS_EMPTY(seq), \
		BOOST_VMD_DETAIL_SEQUENCE_TO_ARRAY_RP_EMPTY, \
		BOOST_PP_SEQ_TO_ARRAY \
		) \
	(seq) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_TO_LIST_OP(s,data,elem) \
	BOOST_PP_TUPLE_ELEM(data,elem) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_LIST_TR(list) \
	BOOST_PP_LIST_TRANSFORM(BOOST_VMD_DETAIL_SEQUENCE_TO_LIST_OP,1,list) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_TO_SEQ_OP(s,data,elem) \
	BOOST_PP_TUPLE_ELEM(data,elem) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_SEQ_TR_NE(seq) \
	BOOST_PP_SEQ_TRANSFORM(BOOST_VMD_DETAIL_SEQUENCE_TO_SEQ_OP,1,seq) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_SEQ_TR(seq) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_IS_EMPTY(seq), \
		BOOST_VMD_EMPTY, \
		BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_SEQ_TR_NE \
		) \
	(seq) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_ELEM_CE_TUPLE(selem) \
	BOOST_PP_TUPLE_ELEM(1,selem) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_ELEM_CE(selem) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_IS_EMPTY(selem), \
		BOOST_VMD_EMPTY, \
		BOOST_VMD_DETAIL_SEQUENCE_DATA_ELEM_CE_TUPLE \
		) \
	(selem) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_ELEM_SPLIT_ICE_REP(tuple) \
	BOOST_PP_TUPLE_REPLACE \
		( \
		tuple, \
		0, \
		BOOST_PP_TUPLE_ELEM(1,BOOST_PP_TUPLE_ELEM(0,tuple)) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_ELEM_SPLIT_ICE(tuple) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_IS_EMPTY(BOOST_PP_TUPLE_ELEM(0,tuple)), \
		BOOST_VMD_IDENTITY(tuple), \
		BOOST_VMD_DETAIL_SEQUENCE_DATA_ELEM_SPLIT_ICE_REP \
		) \
	(tuple) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_ELEM_SPLIT_CE(tuple) \
	BOOST_VMD_IDENTITY_RESULT(BOOST_VMD_DETAIL_SEQUENCE_DATA_ELEM_SPLIT_ICE(tuple)) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_ENUM_PROCESS(tuple) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_IS_EMPTY(tuple), \
		BOOST_VMD_EMPTY, \
		BOOST_PP_TUPLE_ENUM \
		) \
	(tuple) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_VSEQ(...) \
	BOOST_PP_VARIADIC_ELEM(0,__VA_ARGS__) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_IFROM(...) \
	BOOST_PP_IIF \
		( \
		BOOST_PP_EQUAL \
			( \
			BOOST_PP_VARIADIC_SIZE(__VA_ARGS__), \
			1 \
			), \
		BOOST_VMD_IDENTITY(BOOST_VMD_RETURN_EXACT_TYPE), \
		BOOST_PP_VARIADIC_ELEM \
		) \
	(1,__VA_ARGS__) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_FROM(...) \
	BOOST_VMD_IDENTITY_RESULT(BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_IFROM(__VA_ARGS__)) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_NOT_EMPTY(vseq) \
	BOOST_PP_NOT(BOOST_VMD_IS_EMPTY(vseq)) \
/**/

/*--------------------------------------------------------------------------------------------------------------------------*/

#define BOOST_VMD_DETAIL_SEQUENCE_MODS_STATE_INPUT(state) \
	BOOST_PP_TUPLE_ELEM(0,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_MODS_STATE_INDEX(state) \
	BOOST_PP_TUPLE_ELEM(1,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_MODS_STATE_SIZE(state) \
	BOOST_PP_TUPLE_ELEM(2,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_MODS_STATE_RESULT(state) \
	BOOST_PP_TUPLE_ELEM(3,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_MODS_STATE_CURRENT(state) \
	BOOST_PP_VARIADIC_ELEM(BOOST_VMD_DETAIL_SEQUENCE_MODS_STATE_INDEX(state),BOOST_VMD_DETAIL_SEQUENCE_MODS_STATE_INPUT(state)) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_MODS_STATE_TYPE(state) \
	BOOST_PP_TUPLE_ELEM(0,BOOST_VMD_DETAIL_SEQUENCE_MODS_STATE_RESULT(state)) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_MODS_STATE_AFTER(state) \
	BOOST_PP_TUPLE_ELEM(1,BOOST_VMD_DETAIL_SEQUENCE_MODS_STATE_RESULT(state)) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_MODS_PRED(d,state) \
	BOOST_PP_GREATER_D(d,BOOST_VMD_DETAIL_SEQUENCE_MODS_STATE_SIZE(state),BOOST_VMD_DETAIL_SEQUENCE_MODS_STATE_INDEX(state))
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_MODS_OP_CURRENT_RETURN_TYPE(d,state,number) \
	BOOST_VMD_DETAIL_SEQUENCE_MODS_OP_CURRENT_INDEX \
		( \
		d, \
		BOOST_PP_TUPLE_REPLACE_D \
			( \
			d, \
			state, \
			3, \
			BOOST_PP_TUPLE_REPLACE_D \
				( \
				d, \
				BOOST_VMD_DETAIL_SEQUENCE_MODS_STATE_RESULT(state), \
				0, \
				number \
				) \
			) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_MODS_OP_CURRENT_AFTER(d,state,number) \
	BOOST_VMD_DETAIL_SEQUENCE_MODS_OP_CURRENT_INDEX \
		( \
		d, \
		BOOST_PP_TUPLE_REPLACE_D \
			( \
			d, \
			state, \
			3, \
			BOOST_PP_TUPLE_REPLACE_D \
				( \
				d, \
				BOOST_VMD_DETAIL_SEQUENCE_MODS_STATE_RESULT(state), \
				1, \
				number \
				) \
			) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_MODS_OP_CURRENT_GTT(d,state) \
	BOOST_VMD_DETAIL_SEQUENCE_MODS_OP_CURRENT_RETURN_TYPE(d,state,2) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_MODS_OP_CURRENT_ET(d,state) \
	BOOST_VMD_DETAIL_SEQUENCE_MODS_OP_CURRENT_RETURN_TYPE(d,state,1) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_MODS_OP_CURRENT_SA(d,state) \
	BOOST_VMD_DETAIL_SEQUENCE_MODS_OP_CURRENT_RETURN_TYPE(d,state,3) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_MODS_OP_CURRENT_SL(d,state) \
	BOOST_VMD_DETAIL_SEQUENCE_MODS_OP_CURRENT_RETURN_TYPE(d,state,4) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_MODS_OP_CURRENT_NT(d,state) \
	BOOST_VMD_DETAIL_SEQUENCE_MODS_OP_CURRENT_RETURN_TYPE(d,state,0) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_MODS_OP_CURRENT_AFT(d,state) \
	BOOST_VMD_DETAIL_SEQUENCE_MODS_OP_CURRENT_AFTER(d,state,1) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_MODS_OP_CURRENT_NOAFT(d,state) \
	BOOST_VMD_DETAIL_SEQUENCE_MODS_OP_CURRENT_AFTER(d,state,0) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_MODS_OP_CURRENT_INDEX(d,state) \
	BOOST_PP_TUPLE_REPLACE_D \
		( \
		d, \
		state, \
		1, \
		BOOST_PP_INC(BOOST_VMD_DETAIL_SEQUENCE_MODS_STATE_INDEX(state)) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_MODS_OP_CURRENT(d,state,id) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_DETAIL_IS_RETURN_GENERAL_TUPLE_TYPE(id), \
		BOOST_VMD_DETAIL_SEQUENCE_MODS_OP_CURRENT_GTT, \
		BOOST_PP_IIF \
			( \
			BOOST_VMD_DETAIL_IS_RETURN_EXACT_TYPE(id), \
			BOOST_VMD_DETAIL_SEQUENCE_MODS_OP_CURRENT_ET, \
			BOOST_PP_IIF \
				( \
				BOOST_VMD_DETAIL_IS_SPECIFIC_ARRAY(id), \
				BOOST_VMD_DETAIL_SEQUENCE_MODS_OP_CURRENT_SA, \
				BOOST_PP_IIF \
					( \
					BOOST_VMD_DETAIL_IS_SPECIFIC_LIST(id), \
					BOOST_VMD_DETAIL_SEQUENCE_MODS_OP_CURRENT_SL, \
					BOOST_PP_IIF \
						( \
						BOOST_VMD_DETAIL_IS_RETURN_NO_TYPE(id), \
						BOOST_VMD_DETAIL_SEQUENCE_MODS_OP_CURRENT_NT, \
						BOOST_PP_IIF \
							( \
							BOOST_VMD_DETAIL_IS_RETURN_AFTER(id), \
							BOOST_VMD_DETAIL_SEQUENCE_MODS_OP_CURRENT_AFT, \
							BOOST_PP_IIF \
								( \
								BOOST_VMD_DETAIL_IS_RETURN_NO_AFTER(id), \
								BOOST_VMD_DETAIL_SEQUENCE_MODS_OP_CURRENT_NOAFT, \
								BOOST_VMD_DETAIL_SEQUENCE_MODS_OP_CURRENT_INDEX \
								) \
							) \
						) \
					) \
				) \
			) \
		) \
	(d,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_MODS_OP(d,state) \
	BOOST_VMD_DETAIL_SEQUENCE_MODS_OP_CURRENT(d,state,BOOST_VMD_DETAIL_SEQUENCE_MODS_STATE_CURRENT(state)) \
/**/

/*

  Returns a two-element tuple of number values.
  
  First tuple element  = 0 No type return
                         1 Exact type return
                         2 General tuple type return
                         3 Array return
                         4 List return
                         
  Second tuple element = 0 No after return
                         1 After return
                         
  Input                = Modifiers
  
*/

#define BOOST_VMD_DETAIL_SEQUENCE_MODS(...) \
	BOOST_PP_TUPLE_ELEM \
		( \
		3, \
		BOOST_PP_WHILE \
			( \
			BOOST_VMD_DETAIL_SEQUENCE_MODS_PRED, \
			BOOST_VMD_DETAIL_SEQUENCE_MODS_OP, \
				( \
				__VA_ARGS__, \
				0, \
				BOOST_PP_VARIADIC_SIZE(__VA_ARGS__), \
				(0,0) \
				) \
			) \
		) \
/**/

/*--------------------------------------------------------------------------------------------------------------------------*/

#define BOOST_VMD_DETAIL_SEQUENCE_POP_VARIADIC(...) \
	BOOST_PP_TUPLE_ENUM \
		( \
		BOOST_PP_TUPLE_POP_FRONT \
			( \
			BOOST_PP_VARIADIC_TO_TUPLE(__VA_ARGS__) \
			) \
		) \
/**/

/*--------------------------------------------------------------------------------------------------------------------------*/

// ELEM

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM_NEW_IND(vseq,elem,mods) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM_NEW_MODS_VAR(...) \
	BOOST_VMD_DETAIL_SEQUENCE_MODS \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_POP_VARIADIC(__VA_ARGS__) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM_NEW_IMODS(...) \
	BOOST_PP_IIF \
		( \
		BOOST_PP_EQUAL(BOOST_PP_VARIADIC_SIZE(__VA_ARGS__),1), \
		BOOST_VMD_IDENTITY((0,0)), \
		BOOST_VMD_DETAIL_SEQUENCE_ELEM_NEW_MODS_VAR \
		) \
	(__VA_ARGS__) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM_NEW_MODS(...) \
	BOOST_VMD_IDENTITY_RESULT(BOOST_VMD_DETAIL_SEQUENCE_ELEM_NEW_IMODS(__VA_ARGS__)) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM_NEW(elem,...) \
	BOOST_VMD_DETAIL_SEQUENCE_ELEM_NEW_IND \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_VSEQ(__VA_ARGS__), \
		elem, \
		BOOST_VMD_DETAIL_SEQUENCE_ELEM_NEW_MODS(__VA_ARGS__) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM(elem,...) \
	BOOST_PP_EXPR_IIF \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_NOT_EMPTY(BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_VSEQ(__VA_ARGS__)), \
		BOOST_VMD_DETAIL_SEQUENCE_ELEM_FSEQ \
			( \
			BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS \
				( \
				BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_VSEQ(__VA_ARGS__), \
				elem, \
				BOOST_VMD_TYPE_SEQ, \
				BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_FROM(__VA_ARGS__) \
				), \
			elem \
			) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM_D(d,elem,...) \
	BOOST_PP_EXPR_IIF \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_NOT_EMPTY(BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_VSEQ(__VA_ARGS__)), \
		BOOST_VMD_DETAIL_SEQUENCE_ELEM_FSEQ \
			( \
			BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_D \
				( \
				d, \
				BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_VSEQ(__VA_ARGS__), \
				elem, \
				BOOST_VMD_TYPE_SEQ, \
				BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_FROM(__VA_ARGS__) \
				), \
			elem \
			) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_ELEM(elem,vseq) \
	BOOST_VMD_DETAIL_SEQUENCE_DATA_ELEM_CE(BOOST_VMD_DETAIL_SEQUENCE_ELEM(elem,vseq,BOOST_VMD_RETURN_GENERAL_TUPLE_TYPE)) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_ELEM_D(d,elem,vseq) \
	BOOST_VMD_DETAIL_SEQUENCE_DATA_ELEM_CE(BOOST_VMD_DETAIL_SEQUENCE_ELEM_D(d,elem,vseq,BOOST_VMD_RETURN_GENERAL_TUPLE_TYPE)) \
/**/

// ELEM SPLIT

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM_SPLIT(elem,...) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_NOT_EMPTY(BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_VSEQ(__VA_ARGS__)), \
		BOOST_VMD_DETAIL_SEQUENCE_ELEM_SPLIT_FSEQ \
			( \
			BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_TUPLE \
				( \
				BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_VSEQ(__VA_ARGS__), \
				elem, \
				BOOST_VMD_TYPE_SEQ, \
				BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_FROM(__VA_ARGS__) \
				), \
			elem \
			), \
		BOOST_VMD_DETAIL_EMPTY_RESULT(elem) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM_SPLIT_D(d,elem,...) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_NOT_EMPTY(BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_VSEQ(__VA_ARGS__)), \
		BOOST_VMD_DETAIL_SEQUENCE_ELEM_SPLIT_FSEQ \
			( \
			BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_TUPLE_D \
				( \
				d, \
				BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_VSEQ(__VA_ARGS__), \
				elem, \
				BOOST_VMD_TYPE_SEQ, \
				BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_FROM(__VA_ARGS__) \
				), \
			elem \
			), \
		BOOST_VMD_DETAIL_EMPTY_RESULT(elem) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_ELEM_SPLIT(elem,vseq) \
	BOOST_VMD_DETAIL_SEQUENCE_DATA_ELEM_SPLIT_CE \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_ELEM_SPLIT(elem,vseq,BOOST_VMD_RETURN_GENERAL_TUPLE_TYPE) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_ELEM_SPLIT_D(d,elem,vseq) \
	BOOST_VMD_DETAIL_SEQUENCE_DATA_ELEM_SPLIT_CE \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_ELEM_SPLIT_D(d,elem,vseq,BOOST_VMD_RETURN_GENERAL_TUPLE_TYPE) \
		) \
/**/

// AFTER

#define BOOST_VMD_DETAIL_SEQUENCE_AFTER(elem,vseq) \
	BOOST_PP_TUPLE_ELEM(1,BOOST_VMD_DETAIL_SEQUENCE_DATA_ELEM_SPLIT(elem,vseq)) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_AFTER_D(d,elem,vseq) \
	BOOST_PP_TUPLE_ELEM(1,BOOST_VMD_DETAIL_SEQUENCE_DATA_ELEM_SPLIT_D(d,elem,vseq)) \
/**/

// SIZE

#define BOOST_VMD_DETAIL_SEQUENCE_SIZE(vseq) \
	BOOST_PP_ARRAY_SIZE(BOOST_VMD_DETAIL_SEQUENCE_TO_ARRAY(vseq,BOOST_VMD_RETURN_GENERAL_TUPLE_TYPE)) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_SIZE_D(d,vseq) \
	BOOST_PP_ARRAY_SIZE(BOOST_VMD_DETAIL_SEQUENCE_TO_ARRAY_D(d,vseq,BOOST_VMD_RETURN_GENERAL_TUPLE_TYPE)) \
/**/

// ARRAY

#define BOOST_VMD_DETAIL_SEQUENCE_TO_ARRAY(...) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_NOT_EMPTY(BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_VSEQ(__VA_ARGS__)), \
		BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS \
			( \
			BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_VSEQ(__VA_ARGS__), \
			, \
			BOOST_VMD_TYPE_ARRAY, \
			BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_FROM(__VA_ARGS__) \
			), \
		(0,()) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_TO_ARRAY_D(d,...) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_NOT_EMPTY(BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_VSEQ(__VA_ARGS__)), \
		BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_D \
			( \
			d, \
			BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_VSEQ(__VA_ARGS__), \
			, \
			BOOST_VMD_TYPE_ARRAY, \
			BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_IFROM(__VA_ARGS__) \
			), \
		(0,()) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_ARRAY(vseq) \
	BOOST_VMD_DETAIL_SEQUENCE_TO_ARRAY_RP \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_SEQ(vseq) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_ARRAY_D(d,vseq) \
	BOOST_VMD_DETAIL_SEQUENCE_TO_ARRAY_RP \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_SEQ_D(d,vseq) \
		) \
/**/

// LIST

#define BOOST_VMD_DETAIL_SEQUENCE_TO_LIST(...) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_NOT_EMPTY(BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_VSEQ(__VA_ARGS__)), \
		BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS \
			( \
			BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_VSEQ(__VA_ARGS__), \
			, \
			BOOST_VMD_TYPE_LIST, \
			BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_FROM(__VA_ARGS__) \
			), \
		BOOST_PP_NIL \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_TO_LIST_D(d,...) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_NOT_EMPTY(BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_VSEQ(__VA_ARGS__)), \
		BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_D \
			( \
			d, \
			BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_VSEQ(__VA_ARGS__), \
			, \
			BOOST_VMD_TYPE_LIST, \
			BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_FROM(__VA_ARGS__) \
			), \
		BOOST_PP_NIL \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_LIST(vseq) \
	BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_LIST_TR \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_TO_LIST(vseq,BOOST_VMD_RETURN_GENERAL_TUPLE_TYPE) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_LIST_D(d,vseq) \
	BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_LIST_TR \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_TO_LIST_D(d,vseq,BOOST_VMD_RETURN_GENERAL_TUPLE_TYPE) \
		) \
/**/

// SEQ

#define BOOST_VMD_DETAIL_SEQUENCE_TO_SEQ(...) \
	BOOST_PP_EXPR_IIF \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_NOT_EMPTY(BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_VSEQ(__VA_ARGS__)), \
		BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS \
			( \
			BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_VSEQ(__VA_ARGS__), \
			, \
			BOOST_VMD_TYPE_SEQ, \
			BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_FROM(__VA_ARGS__) \
			) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_TO_SEQ_D(d,...) \
	BOOST_PP_EXPR_IIF \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_NOT_EMPTY(BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_VSEQ(__VA_ARGS__)), \
		BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_D \
			( \
			d, \
			BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_VSEQ(__VA_ARGS__), \
			, \
			BOOST_VMD_TYPE_SEQ, \
			BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_FROM(__VA_ARGS__) \
			) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_SEQ(vseq) \
	BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_SEQ_TR \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_TO_SEQ(vseq,BOOST_VMD_RETURN_GENERAL_TUPLE_TYPE) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_SEQ_D(d,vseq) \
	BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_SEQ_TR \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_TO_SEQ_D(d,vseq,BOOST_VMD_RETURN_GENERAL_TUPLE_TYPE) \
		) \
/**/

// TUPLE

#define BOOST_VMD_DETAIL_SEQUENCE_TO_TUPLE(...) \
	BOOST_PP_EXPR_IIF \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_NOT_EMPTY(BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_VSEQ(__VA_ARGS__)), \
		BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS \
			( \
			BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_VSEQ(__VA_ARGS__), \
			, \
			BOOST_VMD_TYPE_TUPLE, \
			BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_FROM(__VA_ARGS__) \
			) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_TO_TUPLE_D(d,...) \
	BOOST_PP_EXPR_IIF \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_NOT_EMPTY(BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_VSEQ(__VA_ARGS__)), \
		BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_D \
			( \
			d, \
			BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_VSEQ(__VA_ARGS__), \
			, \
			BOOST_VMD_TYPE_TUPLE, \
			BOOST_VMD_DETAIL_SEQUENCE_ELEM_GET_FROM(__VA_ARGS__) \
			) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_TUPLE(vseq) \
	BOOST_VMD_DETAIL_SEQUENCE_TO_TUPLE_RP \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_SEQ(vseq) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_TUPLE_D(d,vseq) \
	BOOST_VMD_DETAIL_SEQUENCE_TO_TUPLE_RP \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_SEQ_D(d,vseq) \
		) \
/**/

// ENUM

#define BOOST_VMD_DETAIL_SEQUENCE_ENUM(...) \
	BOOST_VMD_DETAIL_SEQUENCE_ENUM_PROCESS \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_TO_TUPLE(__VA_ARGS__) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_ENUM_D(d,...) \
	BOOST_VMD_DETAIL_SEQUENCE_ENUM_PROCESS \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_TO_TUPLE_D(d,__VA_ARGS__) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_ENUM(vseq) \
	BOOST_VMD_DETAIL_SEQUENCE_ENUM_PROCESS \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_TUPLE(vseq) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_ENUM_D(d,vseq) \
	BOOST_VMD_DETAIL_SEQUENCE_ENUM_PROCESS \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_TUPLE_D(d,vseq) \
		) \
/**/

#endif /* BOOST_VMD_DETAIL_SEQUENCE_HPP */
