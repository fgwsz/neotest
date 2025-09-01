#ifndef NEOTEST_PP_H
#define NEOTEST_PP_H

//remove ()
//input:tuple__ is (__VA_ARGS__)
//output:__VA_ARGS__
//sample:
//  NEOTEST_PP_REMOVE_PARENS((x))
//      -> x
//???:
//  NEOTEST_PP_REMOVE_PARENS(x)
//      -> ???
// ??? is NEOTEST_PP_REMOVE_PARENS_IMPL x
// NEOTEST_PP_REMOVE_PARENS_IMPL is not be expanded,It is a unused macro.
// TODO: ??? -> x
#define NEOTEST_PP_REMOVE_PARENS(tuple__) \
    NEOTEST_PP_REMOVE_PARENS_IMPL tuple__ \
//
#define NEOTEST_PP_REMOVE_PARENS_IMPL(...) __VA_ARGS__

#define NEOTEST_PP_COMMA() ,
#define NEOTEST_PP_LPAREN() (
#define NEOTEST_PP_RPAREN() )
#define NEOTEST_PP_EMPTY()

//input:lhs__ rhs__
//output:lhs__ expanded result ## rhs__ expanded result
#define NEOTEST_PP_CONCAT(lhs__,rhs__) \
    NEOTEST_PP_CONCAT_IMPL(lhs__,rhs__) \
//
#define NEOTEST_PP_CONCAT_IMPL(lhs__,rhs__) lhs__##rhs__

//number__ +1
//input:number__ literal
//output:(number__+1) literal
//tips:number__ literal value in [0,1023](>=0 && <= 1023)
//sample:
//  NEOTEST_PP_INC(0)
//      -> 1
#define NEOTEST_PP_INC(number__) \
    NEOTEST_PP_CONCAT(NEOTEST_PP_INC_,number__)
//
#include"pp_inc.h"

//number__ -1
//input:number__ literal
//output:(number__-1) literal
//tips:number__ literal value in [1,1024](>=1 && <= 1024)
//sample:
//  NEOTEST_PP_DEC(1)
//      -> 0
#define NEOTEST_PP_DEC(number__) \
    NEOTEST_PP_CONCAT(NEOTEST_PP_DEC_,number__)
//
#include"pp_dec.h"

//n__:0 or 1
//input 0 output 1
//input 1 output 0
#define NEOTEST_PP_NOT(n__) \
    NEOTEST_PP_CONCAT(NEOTEST_PP_NOT_,n__) \
//
#define NEOTEST_PP_NOT_0 1
#define NEOTEST_PP_NOT_1 0

//lhs__ && rhs__
//lhs__:0 or 1
//rhs__:0 or 1
#define NEOTEST_PP_AND(lhs__,rhs__) \
    NEOTEST_PP_CONCAT(NEOTEST_PP_AND_,lhs__,rhs__) \
//
#define NEOTEST_PP_AND_00 0
#define NEOTEST_PP_AND_01 0
#define NEOTEST_PP_AND_10 0
#define NEOTEST_PP_AND_11 1

//lhs__ || rhs__
//lhs__:0 or 1
//rhs__:0 or 1
#define NEOTEST_PP_OR(lhs__,rhs__) \
    NEOTEST_PP_CONCAT(NEOTEST_PP_OR_,lhs__,rhs__) \
//
#define NEOTEST_PP_OR_00 0
#define NEOTEST_PP_OR_01 1
#define NEOTEST_PP_OR_10 1
#define NEOTEST_PP_OR_11 1

//bool(number__)
//input:number__ literal
//output:(number__-1) literal
//number__ literal value in [0,1024](>=0 && <= 1024)
//if number__ literal ==0 return 0
//else return 1
#define NEOTEST_PP_BOOL(number__) \
    NEOTEST_PP_CONCAT(NEOTEST_PP_BOOL_,number__) \
//
#include"pp_bool.h"

#define NEOTEST_PP_IF(pred__,then__,else__) \
    NEOTEST_PP_CONCAT(NEOTEST_PP_IF_,NEOTEST_PP_BOOL(pred__))(then__,else__) \
//
#define NEOTEST_PP_IF_1(then__,else__) then__
#define NEOTEST_PP_IF_0(then__,else__) else__

//NEOTEST_PP_DEC_SAFE(0) -> 0
#define NEOTEST_PP_DEC_SAFE(number__) \
    NEOTEST_PP_IF(number__,NEOTEST_PP_DEC(number__),0) \
//

#endif//NEOTEST_PP_H
