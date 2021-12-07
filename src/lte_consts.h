/*
 * lte_consts.h
 *
 *  Constants defined/derived from LTE standard
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
 *  [1] 3GPP TS 36.211 version 15.2.0 Release 15
 */

#ifndef _LTE_CONSTS_H_
#define _LTE_CONSTS_H_

#include <stdint.h>

namespace lte {
    namespace consts {

        // Radio frame duration in millisecond.
        constexpr uint8_t radioFrameDuration = 10;

        // Subframe duration in millisecond.
        constexpr uint8_t subframeDuration = 1;

        // Number of subframes per radio frame.
        constexpr uint8_t numSubframesPerRadioFrame = (radioFrameDuration/subframeDuration);

        // Number of TDD Uplink-downlink configurations
        // See [1] Table 4.2-2.
        constexpr uint8_t numTddUlDlConfigurations = 7;

        // number of rows in transport block size table
        constexpr uint8_t numItbs = 44;

        // Number of samples in a milli-second based on standard sampling rate of 30.72e6 samples per second.
        constexpr uint32_t numSamplesInMs_default = 30720;

        // maximum number of RBs per carrier.
        constexpr uint16_t nRbMin = 6;

        // maximum number of RBs per carrier.
        constexpr uint16_t nRbMax = 110;

        // Minimum number of RBs in UL
        constexpr uint16_t nRbMinUl = 6;

        // Maxinum number of RBs in UL
        constexpr uint16_t nRbMaxUl = 110;

        // Minimum number of RBs in DL
        constexpr uint16_t nRbMinDl = 6;

        // Maxinum number of RBs in DL
        constexpr uint16_t nRbMaxDl = 110;

        // Number of OFDM subcarriers per RB.
        constexpr uint8_t nRbSc = 12;

        // Number of OFDM symbols per slot
        constexpr uint8_t nSymbUlNormalCp = 7;
        constexpr uint8_t nSymbUlExtendedCp = 6;
    }
}



#endif /* _LTE_CONSTS_H_ */
