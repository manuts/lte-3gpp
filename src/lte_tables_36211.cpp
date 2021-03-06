/*
 * lte_tables_36211.cpp
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
 *  Created on: 7 Dec 2021
 */

/*
 *  References
 *  [1] 3GPP TS 36.211 version 15.2.0 Release 15
 */

#include <array>
#include <utility>
#include <cmath>

#include "lte_consts.h"
#include "lte_enums.h"
#include "lte_types.h"
#include "lte_tables_36211.h"

#include "debug_utils.h"


inline const specialSubframeBreakdown_t specialSubframeConfiguration_T4P2_1(const uint8_t specialSubframeConfig,
                                                                            const lte::enums::cpType dlCpType,
                                                                            const lte::enums::cpType ulCpType,
                                                                            uint8_t srs_len_upPtsAdd = 0)
{
    DBG_ASSERT(specialSubframeConfig < 11);
    if (lte::enums::cpType::EXTENDED == dlCpType) {
        DBG_ASSERT(specialSubframeConfig < 8);
    }

    constexpr std::array<uint32_t, 11> dwPts_normalCp {6592, 19760, 21952, 24144, 26336, 6592, 19760, 21952, 24144, 13168, 13168};
    constexpr std::array<uint32_t, 8> dwPts_extendedCp {7680, 20480, 23040, 25600, 7680, 20480, 23040, 12800};
    uint32_t len_upPts = 0xffffffff;
    uint32_t len_dwPts = 0xffffffff;

    specialSubframeBreakdown_t breakdown;

    if (lte::enums::cpType::NORMAL == dlCpType) {
        // (lte::enums::cpType::NORMAL == dlCpType)
        len_dwPts = dwPts_normalCp.at(specialSubframeConfig);
        if (specialSubframeConfig < 5) {
            // (0 <= specialSubframeConfig < 5)
            len_upPts = (lte::enums::cpType::NORMAL == ulCpType) ? ((1 + srs_len_upPtsAdd)*2192) : ((1 + srs_len_upPtsAdd)*2560);
        } else if (specialSubframeConfig < 10) {
            // (5 <= specialSubframeConfig < 10)
            len_upPts = (lte::enums::cpType::NORMAL == ulCpType) ? ((2 + srs_len_upPtsAdd)*2192) : ((2 + srs_len_upPtsAdd)*2560);
        } else {
            // specialSubframeConfig = 11;
            len_upPts = (lte::enums::cpType::NORMAL == ulCpType) ? 13152 : 12800;
        }
    } else {
        // (lte::enums::cpType::EXTENDED == dlCpType)
        len_dwPts = dwPts_extendedCp.at(specialSubframeConfig);
        if (specialSubframeConfig < 4) {
            // (0 <= specialSubframeConfig < 4)
            len_upPts = (lte::enums::cpType::NORMAL == ulCpType) ? ((1 + srs_len_upPtsAdd)*2192) : ((1 + srs_len_upPtsAdd)*2560);
        } else if (specialSubframeConfig < 8) {
            // (4 <= specialSubframeConfig < 8)
            len_upPts = (lte::enums::cpType::NORMAL == ulCpType) ? ((2 + srs_len_upPtsAdd)*2192) : ((2 + srs_len_upPtsAdd)*2560);
        } else {
            DBG_ASSERT(specialSubframeConfig < 8);
        }
    } // if (lte::enums::cpType::NORMAL == dlCpType)

    DBG_ASSERT(len_upPts != 0xffffffff);
    DBG_ASSERT(len_dwPts != 0xffffffff);

    breakdown.len_DwPTS = len_dwPts;
    breakdown.len_UpPTS = len_upPts;
    DBG_ASSERT(lte::consts::numSamplesInMs_default > (breakdown.len_DwPTS + breakdown.len_UpPTS));
    breakdown.len_GP = (lte::consts::numSamplesInMs_default - (breakdown.len_DwPTS + breakdown.len_UpPTS));

    return breakdown;
}

inline const nGaps_t rbGapValues_T6P2P3P2_1(lte::types::nRb_t nRbDl)
{
    nGaps_t nGaps;

    DBG_ASSERT(nRbDl <= 110);
    DBG_ASSERT(nRbDl >= 6);

    nGaps.nGap1 = uint8_t(std::ceil(nRbDl/2));
    nGaps.nGap2 = nGap2NA;

    if (nRbDl == 11) {
        nGaps.nGap1 = 4;
    }
    if (nRbDl > 11) {
        nGaps.nGap1 = 8;
    }
    if (nRbDl > 19) {
        nGaps.nGap1 = 12;
    }
    if (nRbDl > 26) {
        nGaps.nGap1 = 18;
    }
    if (nRbDl > 44) {
        nGaps.nGap1 = 27;
    }
    if (nRbDl > 49) {
        nGaps.nGap1 = 27;
        nGaps.nGap2 = 9;
    }
    if (nRbDl > 63) {
        nGaps.nGap1 = 32;
        nGaps.nGap2 = 16;
    }
    if (nRbDl > 79) {
        nGaps.nGap1 = 48;
        nGaps.nGap2 = 16;
    }

    return nGaps;
}
