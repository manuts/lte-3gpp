/*
 * lte_tables_36211.h
 *
 *  Tables defined in 3GPP TS 36.211
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

#ifndef _LTE_TABLES_36211_H_
#define _LTE_TABLES_36211_H_

/*
 *  References
 *  [1] 3GPP TS 36.211 version 15.2.0 Release 15
 */

#include <array>
#include <utility>

#include "lte_consts.h"
#include "lte_enums.h"
#include "debug_utils.h"

// [1] Table 4.2-2: Uplink-downlink configurations
inline constexpr std::array<std::pair<lte::enums::tddDlUlSwitchPeriodicity, std::array<lte::enums::tddSubframeType, lte::consts::numSubframesPerRadioFrame>>, lte::consts::numTddUlDlConfigurations> tddUlDlConfigurations_T4P2_2 =
{{
        {lte::enums::tddDlUlSwitchPeriodicity::ms05, {lte::enums::tddSubframeType::D, lte::enums::tddSubframeType::S, lte::enums::tddSubframeType::U, lte::enums::tddSubframeType::U, lte::enums::tddSubframeType::U, lte::enums::tddSubframeType::D, lte::enums::tddSubframeType::S, lte::enums::tddSubframeType::U, lte::enums::tddSubframeType::U, lte::enums::tddSubframeType::U}},
        {lte::enums::tddDlUlSwitchPeriodicity::ms05, {lte::enums::tddSubframeType::D, lte::enums::tddSubframeType::S, lte::enums::tddSubframeType::U, lte::enums::tddSubframeType::U, lte::enums::tddSubframeType::D, lte::enums::tddSubframeType::D, lte::enums::tddSubframeType::S, lte::enums::tddSubframeType::U, lte::enums::tddSubframeType::U, lte::enums::tddSubframeType::D}},
        {lte::enums::tddDlUlSwitchPeriodicity::ms05, {lte::enums::tddSubframeType::D, lte::enums::tddSubframeType::S, lte::enums::tddSubframeType::U, lte::enums::tddSubframeType::D, lte::enums::tddSubframeType::D, lte::enums::tddSubframeType::D, lte::enums::tddSubframeType::S, lte::enums::tddSubframeType::U, lte::enums::tddSubframeType::D, lte::enums::tddSubframeType::D}},
        {lte::enums::tddDlUlSwitchPeriodicity::ms10, {lte::enums::tddSubframeType::D, lte::enums::tddSubframeType::S, lte::enums::tddSubframeType::U, lte::enums::tddSubframeType::U, lte::enums::tddSubframeType::U, lte::enums::tddSubframeType::D, lte::enums::tddSubframeType::D, lte::enums::tddSubframeType::D, lte::enums::tddSubframeType::D, lte::enums::tddSubframeType::D}},
        {lte::enums::tddDlUlSwitchPeriodicity::ms10, {lte::enums::tddSubframeType::D, lte::enums::tddSubframeType::S, lte::enums::tddSubframeType::U, lte::enums::tddSubframeType::U, lte::enums::tddSubframeType::D, lte::enums::tddSubframeType::D, lte::enums::tddSubframeType::D, lte::enums::tddSubframeType::D, lte::enums::tddSubframeType::D, lte::enums::tddSubframeType::D}},
        {lte::enums::tddDlUlSwitchPeriodicity::ms10, {lte::enums::tddSubframeType::D, lte::enums::tddSubframeType::S, lte::enums::tddSubframeType::U, lte::enums::tddSubframeType::D, lte::enums::tddSubframeType::D, lte::enums::tddSubframeType::D, lte::enums::tddSubframeType::D, lte::enums::tddSubframeType::D, lte::enums::tddSubframeType::D, lte::enums::tddSubframeType::D}},
        {lte::enums::tddDlUlSwitchPeriodicity::ms05, {lte::enums::tddSubframeType::D, lte::enums::tddSubframeType::S, lte::enums::tddSubframeType::U, lte::enums::tddSubframeType::U, lte::enums::tddSubframeType::U, lte::enums::tddSubframeType::D, lte::enums::tddSubframeType::S, lte::enums::tddSubframeType::U, lte::enums::tddSubframeType::U, lte::enums::tddSubframeType::D}},
}};

const std::array<std::pair<lte::enums::tddDlUlSwitchPeriodicity, std::array<lte::enums::tddSubframeType, lte::consts::numSubframesPerRadioFrame>>, lte::consts::numTddUlDlConfigurations>& get_tddUlDlConfigurations_T4P2_2();

typedef struct {
    uint32_t len_DwPTS;
    uint32_t len_UpPTS;
    uint32_t len_GP;
} specialSubframeBreakdown_t;

constexpr uint8_t nGap2NA = 255;
typedef struct {
    // When nGap2 cannot be defined for the given system BW, then nGap2 is set to nGap2NA.
    uint8_t nGap1;  // N_{gap,1} in [1] Table 6.2.3.2-1
    uint8_t nGap2;  // N_{gap,2} in [1] Table 6.2.3.2-1
} nGaps_t;

#endif /* _LTE_TABLES_36211_H_ */
