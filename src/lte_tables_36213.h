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
 *  [2] 3GPP TS 36.213 version 13.9.0 Release 13
 *  [3] 3GPP TS 36.213 version 10.11.0 Release 10
 */

#ifndef _LTE_TABLES_36213_H_
#define _LTE_TABLES_36213_H_

#include <vector>
#include <array>

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

// [2] Table 7.3-Y: Uplink association index k' for TDD
inline const std::array<std::array<uint8_t, lte::consts::numSubframesPerRadioFrame>, lte::consts::numTddUlDlConfigurations> uplinkAssociationIndex_T7P3_Y =
{{
        // Note that table 7.3-Y does not have any entry for TDD UL/DL Configuration 0.
        // For TDD UL/DL Configuration 1-6, PUSCH in subframe n is allocated by UL-Grant in subframe n-k'.
        // For example, consider UL/DL Configuration 1:
        // A PUSCH transmission in (frame, subframe) = (x, 2) has to be allocated by UL-Grant in (frame, subframe) = (x-1, 6).
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 6, 4, 0, 0, 0, 6, 4, 0},
        {0, 0, 4, 0, 0, 0, 0, 4, 0, 0},
        {0, 0, 4, 4, 4, 0, 0, 0, 0, 0},
        {0, 0, 4, 4, 0, 0, 0, 0, 0, 0},
        {0, 0, 4, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 7, 7, 5, 0, 0, 7, 7, 0},
}};

// [3] Table 8-2 k for TDD configurations 0-6
inline const std::array<std::array<uint8_t, lte::consts::numSubframesPerRadioFrame>, lte::consts::numTddUlDlConfigurations> k_forTddConfigurations_T8_2 =
{{
        {4, 6, 0, 0, 0, 4, 6, 0, 0, 0},
        {0, 6, 0, 0, 4, 0, 6, 0, 0, 4},
        {0, 0, 0, 4, 0, 0, 0, 0, 4, 0},
        {4, 0, 0, 0, 0, 0, 0, 0, 4, 4},
        {0, 0, 0, 0, 0, 0, 0, 0, 4, 4},
        {0, 0, 0, 0, 0, 0, 0, 0, 4, 0},
        {7, 7, 0, 0, 0, 7, 7, 0, 0, 5},
}};

#endif /* _LTE_TABLES_36213_H_ */
