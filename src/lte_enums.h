/*
 * lte_enums.h
 *
 *  Enumerators used in LTE implementation
 *  Copyright (C) 2021 Manu T. Sreedharan
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 *  Created on: 15 Nov 2021
 */

#ifndef _LTE_ENUMS_H_
#define _LTE_ENUMS_H_

#include <stdint.h>

namespace lte
{
    namespace enums {
        enum class tddSubframeType {
            D = 254,    // downlink subframe
            U = 253,    // uplink subframe
            S = 252     // special subframe

        };

        enum class tddDlUlSwitchPeriodicity {
            ms05 = 5,
            ms10 = 10
        };

    }
}



#endif /* _LTE_ENUMS_H_ */
