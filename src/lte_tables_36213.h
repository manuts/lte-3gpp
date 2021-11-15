/*
 * lte_tables_36213.h
 *
 *  Tables defined in 3GPP TS 36.213
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

/*
 *  References
 *  [1] 3GPP TS 36.213 version 16.3.0 Release 16
 */

#ifndef _LTE_TABLES_36213_H_
#define _LTE_TABLES_36213_H_

#include <vector>

#include "lte_consts.h"
#include "lte_enums.h"

// [1] Table 10.1.3.1-1: Downlink association set K : {k0 , k1 , k_{M−1}} for TDD
inline const std::vector<std::vector<std::vector<uint8_t>>> downlinkAssociationSet_T10P1P3P1_1 =
{{
        {{},{},{6,},{},{4,},{},{},{6,},{},{4,},},
        {{},{},{7,6,},{4,},{},{},{},{7,6,},{4,},{},},
        {{},{},{8,7,4,6,},{},{},{},{},{8,7,4,6,},{},{},},
        {{},{},{7,6,11,},{6,5,},{5,4,},{},{},{},{},{},},
        {{},{},{12,8,7,11,},{6,5,4,7,},{},{},{},{},{},{},},
        {{},{},{13,12,9,8,7,5,4,11,6,},{},{},{},{},{},{},{},},
        {{},{},{7,},{7,},{5,},{},{},{7,},{7,},{},},
}};


#endif /* _LTE_TABLES_36213_H_ */
