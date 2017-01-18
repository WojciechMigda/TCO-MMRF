/*******************************************************************************
 * Copyright (c) 2017 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the MIT License
 *******************************************************************************
 *
 * Filename: parse_csv.cpp
 *
 * Description:
 *      Simple numeric CSV parser with Spirit::Qi
 *
 * Authors:
 *          Wojciech Migda (wm)
 *
 *******************************************************************************
 * History:
 * --------
 * Date         Who  Ticket     Description
 * ----------   ---  ---------  ------------------------------------------------
 * 2017-01-09   wm              Initial version
 *
 ******************************************************************************/

#include "boost/spirit/include/qi_action.hpp"
#include "boost/spirit/include/qi_operator.hpp"

#include "boost/spirit/include/qi_parse.hpp"
#include "boost/spirit/include/qi_real.hpp"
#include "boost/spirit/include/qi_eps.hpp"
#include "boost/spirit/include/qi_char.hpp"

#include <cstddef>
#include <cmath>

bool parse_csv(const char * first, std::size_t sz, float * optr)
{
    using namespace boost::spirit;

    const char * last = first + sz;

    bool ok = qi::phrase_parse(
         first, last,
         (
             qi::double_[([&optr](float x){ *optr++ = x; })]
             | qi::eps[([&optr](){ *optr++ = NAN; })]
         ) % ',',
         qi::ascii::space
     );

    return ok;
}
