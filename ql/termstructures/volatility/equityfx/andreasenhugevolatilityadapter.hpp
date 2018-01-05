/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2017 Klaus Spanderen

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it
 under the terms of the QuantLib license.  You should have received a
 copy of the license along with this program; if not, please email
 <quantlib-dev@lists.sf.net>. The license is also available online at
 <http://quantlib.org/license.shtml>.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

/*! \file andreasenhugevolatilityadapter.hpp
    \brief Implements the BlackVolTermStructure interface based on a
           Andreasen-Huge volatility interpolation
*/

#ifndef quantlib_andreasen_huge_volatility_adapter_hpp
#define quantlib_andreasen_huge_volatility_adapter_hpp

#include <ql/termstructures/volatility/equityfx/blackvariancecurve.hpp>

namespace QuantLib {
    class AndreasenHugeVolatilityInterpl;

    class AndreasenHugeVolatilityAdapter : public BlackVarianceTermStructure {
      public:
        AndreasenHugeVolatilityAdapter(
            const boost::shared_ptr<AndreasenHugeVolatilityInterpl>& volInterpl,
            Real eps = 1e-10);

        Date maxDate() const;
        Real minStrike() const;
        Real maxStrike() const;

        Calendar calendar() const;
        DayCounter dayCounter() const;
        Natural settlementDays() const;
        const Date& referenceDate() const;

      protected:
        Real blackVarianceImpl(Time t, Real strike) const;

      private:
        const Real eps_;
        const boost::shared_ptr<AndreasenHugeVolatilityInterpl> volInterpl_;
    };
}


#endif
