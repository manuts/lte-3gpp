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
 *  [4] 3GPP TS 36.213 version 15.2.0 Release 15
 */

#ifndef _LTE_TABLES_36213_H_
#define _LTE_TABLES_36213_H_

#include <vector>
#include <array>

#include "debug_utils.h"

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
inline constexpr std::array<std::array<uint8_t, lte::consts::numSubframesPerRadioFrame>, lte::consts::numTddUlDlConfigurations> uplinkAssociationIndex_T7P3_Y =
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
inline constexpr std::array<std::array<uint8_t, lte::consts::numSubframesPerRadioFrame>, lte::consts::numTddUlDlConfigurations> k_forTddConfigurations_T8_2 =
{{
        {4, 6, 0, 0, 0, 4, 6, 0, 0, 0},
        {0, 6, 0, 0, 4, 0, 6, 0, 0, 4},
        {0, 0, 0, 4, 0, 0, 0, 0, 4, 0},
        {4, 0, 0, 0, 0, 0, 0, 0, 4, 4},
        {0, 0, 0, 0, 0, 0, 0, 0, 4, 4},
        {0, 0, 0, 0, 0, 0, 0, 0, 4, 0},
        {7, 7, 0, 0, 0, 7, 7, 0, 0, 5},
}};

typedef struct {
    lte::types::iMcs_t iMcs;
    lte::enums::modulationOrder Qm;
    lte::enums::modulationOrder Qm_dash;
    std::vector<lte::enums::i_tbs> iTbs;
} mcs2tbsIndexTable_elem;

// [4] Table 7.3-X: Value of Downlink Assignment Index
inline constexpr uint8_t valueOfDownlinkAssignmentIndex(uint8_t numPDXCH)
{
    // The parameter numPDXCH represents the Number of subframes/slots
    // with PDSCH transmission and
    // with PDCCH/EPDC/SPDCCH CH indicating DL SPS release
    // i.e., numPDXCH is the values from last column of [4] Table 7.3-X
    DBG_ASSERT(numPDXCH <= 11);
    constexpr std::array<uint8_t, 11> mapNumPDXCH2DAI = {4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2};
    return(mapNumPDXCH2DAI[numPDXCH]);
}

// [4] Table 7.1.7.1-1: Modulation and TBS index table for PDSCH
inline const std::vector<mcs2tbsIndexTable_elem> mcs2tbsIndexTable1
{{
    {lte::types::iMcs_t(0),     lte::enums::modulationOrder::Qm2,   lte::enums::modulationOrder::Qm2,   {lte::enums::i_tbs::i0}                             },
    {lte::types::iMcs_t(1),     lte::enums::modulationOrder::Qm2,   lte::enums::modulationOrder::Qm2,   {lte::enums::i_tbs::i1}                             },
    {lte::types::iMcs_t(2),     lte::enums::modulationOrder::Qm2,   lte::enums::modulationOrder::Qm2,   {lte::enums::i_tbs::i2}                             },
    {lte::types::iMcs_t(3),     lte::enums::modulationOrder::Qm2,   lte::enums::modulationOrder::Qm2,   {lte::enums::i_tbs::i3}                             },
    {lte::types::iMcs_t(4),     lte::enums::modulationOrder::Qm2,   lte::enums::modulationOrder::Qm2,   {lte::enums::i_tbs::i4}                             },
    {lte::types::iMcs_t(5),     lte::enums::modulationOrder::Qm2,   lte::enums::modulationOrder::Qm4,   {lte::enums::i_tbs::i5}                             },
    {lte::types::iMcs_t(6),     lte::enums::modulationOrder::Qm2,   lte::enums::modulationOrder::Qm4,   {lte::enums::i_tbs::i6}                             },
    {lte::types::iMcs_t(7),     lte::enums::modulationOrder::Qm2,   lte::enums::modulationOrder::Qm4,   {lte::enums::i_tbs::i7}                             },
    {lte::types::iMcs_t(8),     lte::enums::modulationOrder::Qm2,   lte::enums::modulationOrder::Qm4,   {lte::enums::i_tbs::i8}                             },
    {lte::types::iMcs_t(9),     lte::enums::modulationOrder::Qm2,   lte::enums::modulationOrder::Qm4,   {lte::enums::i_tbs::i9}                             },
    {lte::types::iMcs_t(10),    lte::enums::modulationOrder::Qm4,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i9}                             },
    {lte::types::iMcs_t(11),    lte::enums::modulationOrder::Qm4,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i10}                            },
    {lte::types::iMcs_t(12),    lte::enums::modulationOrder::Qm4,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i11}                            },
    {lte::types::iMcs_t(13),    lte::enums::modulationOrder::Qm4,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i12}                            },
    {lte::types::iMcs_t(14),    lte::enums::modulationOrder::Qm4,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i13}                            },
    {lte::types::iMcs_t(15),    lte::enums::modulationOrder::Qm4,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i14}                            },
    {lte::types::iMcs_t(16),    lte::enums::modulationOrder::Qm4,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i15}                            },
    {lte::types::iMcs_t(17),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i15}                            },
    {lte::types::iMcs_t(18),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i16}                            },
    {lte::types::iMcs_t(19),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i17}                            },
    {lte::types::iMcs_t(20),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i18}                            },
    {lte::types::iMcs_t(21),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i19}                            },
    {lte::types::iMcs_t(22),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i20}                            },
    {lte::types::iMcs_t(23),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i21}                            },
    {lte::types::iMcs_t(24),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i22}                            },
    {lte::types::iMcs_t(25),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i23}                            },
    {lte::types::iMcs_t(26),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i24}                            },
    {lte::types::iMcs_t(27),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i25}                            },
    {lte::types::iMcs_t(28),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i26, lte::enums::i_tbs::i26A}   },
    {lte::types::iMcs_t(29),    lte::enums::modulationOrder::Qm2,   lte::enums::modulationOrder::Qm2,   {lte::enums::i_tbs::iRes}                           },
    {lte::types::iMcs_t(30),    lte::enums::modulationOrder::Qm4,   lte::enums::modulationOrder::Qm4,   {lte::enums::i_tbs::iRes}                           },
    {lte::types::iMcs_t(31),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::iRes}                           },
}};

// [4] Table 7.1.7.1-1A. Modulation and TBS index table 2 for PDSCH
inline const std::vector<mcs2tbsIndexTable_elem> mcs2tbsIndexTable2
{{
    {lte::types::iMcs_t(0),     lte::enums::modulationOrder::Qm2,   lte::enums::modulationOrder::Qm2,   {lte::enums::i_tbs::i0}                                                       },
    {lte::types::iMcs_t(1),     lte::enums::modulationOrder::Qm2,   lte::enums::modulationOrder::Qm2,   {lte::enums::i_tbs::i2}                                                       },
    {lte::types::iMcs_t(2),     lte::enums::modulationOrder::Qm2,   lte::enums::modulationOrder::Qm2,   {lte::enums::i_tbs::i4}                                                       },
    {lte::types::iMcs_t(3),     lte::enums::modulationOrder::Qm2,   lte::enums::modulationOrder::Qm4,   {lte::enums::i_tbs::i6}                                                       },
    {lte::types::iMcs_t(4),     lte::enums::modulationOrder::Qm2,   lte::enums::modulationOrder::Qm4,   {lte::enums::i_tbs::i8}                                                       },
    {lte::types::iMcs_t(5),     lte::enums::modulationOrder::Qm4,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i10}                                                      },
    {lte::types::iMcs_t(6),     lte::enums::modulationOrder::Qm4,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i11}                                                      },
    {lte::types::iMcs_t(7),     lte::enums::modulationOrder::Qm4,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i12}                                                      },
    {lte::types::iMcs_t(8),     lte::enums::modulationOrder::Qm4,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i13}                                                      },
    {lte::types::iMcs_t(9),     lte::enums::modulationOrder::Qm4,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i14}                                                      },
    {lte::types::iMcs_t(10),    lte::enums::modulationOrder::Qm4,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i15}                                                      },
    {lte::types::iMcs_t(11),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i16}                                                      },
    {lte::types::iMcs_t(12),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i17}                                                      },
    {lte::types::iMcs_t(13),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i18}                                                      },
    {lte::types::iMcs_t(14),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i19}                                                      },
    {lte::types::iMcs_t(15),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i20}                                                      },
    {lte::types::iMcs_t(16),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i21}                                                      },
    {lte::types::iMcs_t(17),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i22}                                                      },
    {lte::types::iMcs_t(18),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i23}                                                      },
    {lte::types::iMcs_t(19),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i24}                                                      },
    {lte::types::iMcs_t(20),    lte::enums::modulationOrder::Qm8,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i25}                                                      },
    {lte::types::iMcs_t(21),    lte::enums::modulationOrder::Qm8,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i27}                                                      },
    {lte::types::iMcs_t(22),    lte::enums::modulationOrder::Qm8,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i28}                                                      },
    {lte::types::iMcs_t(23),    lte::enums::modulationOrder::Qm8,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i29}                                                      },
    {lte::types::iMcs_t(24),    lte::enums::modulationOrder::Qm8,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i30}                                                      },
    {lte::types::iMcs_t(25),    lte::enums::modulationOrder::Qm8,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i31}                                                      },
    {lte::types::iMcs_t(26),    lte::enums::modulationOrder::Qm8,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i32}                                                      },
    {lte::types::iMcs_t(27),    lte::enums::modulationOrder::Qm8,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i33, lte::enums::i_tbs::i33A, lte::enums::i_tbs::i33B}    },
    {lte::types::iMcs_t(28),    lte::enums::modulationOrder::Qm2,   lte::enums::modulationOrder::Qm2,   {lte::enums::i_tbs::iRes}                                                     },
    {lte::types::iMcs_t(29),    lte::enums::modulationOrder::Qm4,   lte::enums::modulationOrder::Qm4,   {lte::enums::i_tbs::iRes}                                                     },
    {lte::types::iMcs_t(30),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::iRes}                                                     },
    {lte::types::iMcs_t(31),    lte::enums::modulationOrder::Qm8,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::iRes}                                                     },
}};

// [4] Table 7.1.7.1-1B. Modulation and TBS index table 3 for PDSCH
inline const std::vector<mcs2tbsIndexTable_elem> mcs2tbsIndexTable3
{{
    {lte::types::iMcs_t(0),     lte::enums::modulationOrder::Qm2,   lte::enums::modulationOrder::Qm2,   {lte::enums::i_tbs::i0}                                                    },
    {lte::types::iMcs_t(1),     lte::enums::modulationOrder::Qm2,   lte::enums::modulationOrder::Qm2,   {lte::enums::i_tbs::i2}                                                    },
    {lte::types::iMcs_t(2),     lte::enums::modulationOrder::Qm2,   lte::enums::modulationOrder::Qm2,   {lte::enums::i_tbs::i4}                                                    },
    {lte::types::iMcs_t(3),     lte::enums::modulationOrder::Qm2,   lte::enums::modulationOrder::Qm4,   {lte::enums::i_tbs::i6}                                                    },
    {lte::types::iMcs_t(4),     lte::enums::modulationOrder::Qm2,   lte::enums::modulationOrder::Qm4,   {lte::enums::i_tbs::i8}                                                    },
    {lte::types::iMcs_t(5),     lte::enums::modulationOrder::Qm4,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i11}                                                   },
    {lte::types::iMcs_t(6),     lte::enums::modulationOrder::Qm4,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i13}                                                   },
    {lte::types::iMcs_t(7),     lte::enums::modulationOrder::Qm4,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i15}                                                   },
    {lte::types::iMcs_t(8),     lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i16}                                                   },
    {lte::types::iMcs_t(9),     lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i18}                                                   },
    {lte::types::iMcs_t(10),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i20}                                                   },
    {lte::types::iMcs_t(11),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i21}                                                   },
    {lte::types::iMcs_t(12),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i22}                                                   },
    {lte::types::iMcs_t(13),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i23}                                                   },
    {lte::types::iMcs_t(14),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i24}                                                   },
    {lte::types::iMcs_t(15),    lte::enums::modulationOrder::Qm8,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i25}                                                   },
    {lte::types::iMcs_t(16),    lte::enums::modulationOrder::Qm8,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i27}                                                   },
    {lte::types::iMcs_t(17),    lte::enums::modulationOrder::Qm8,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i28}                                                   },
    {lte::types::iMcs_t(18),    lte::enums::modulationOrder::Qm8,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i29}                                                   },
    {lte::types::iMcs_t(19),    lte::enums::modulationOrder::Qm8,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i30}                                                   },
    {lte::types::iMcs_t(20),    lte::enums::modulationOrder::Qm8,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i31}                                                   },
    {lte::types::iMcs_t(21),    lte::enums::modulationOrder::Qm8,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i32}                                                   },
    {lte::types::iMcs_t(22),    lte::enums::modulationOrder::Qm8,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i33, lte::enums::i_tbs::i33A, lte::enums::i_tbs::i33B} },
    {lte::types::iMcs_t(23),    lte::enums::modulationOrder::Qm10,  lte::enums::modulationOrder::Qm10,  {lte::enums::i_tbs::i34A}                                                  },
    {lte::types::iMcs_t(24),    lte::enums::modulationOrder::Qm10,  lte::enums::modulationOrder::Qm10,  {lte::enums::i_tbs::i35}                                                   },
    {lte::types::iMcs_t(25),    lte::enums::modulationOrder::Qm10,  lte::enums::modulationOrder::Qm10,  {lte::enums::i_tbs::i36}                                                   },
    {lte::types::iMcs_t(26),    lte::enums::modulationOrder::Qm10,  lte::enums::modulationOrder::Qm10,  {lte::enums::i_tbs::i37A, lte::enums::i_tbs::i37}                          },
    {lte::types::iMcs_t(27),    lte::enums::modulationOrder::Qm2,   lte::enums::modulationOrder::Qm2,   {lte::enums::i_tbs::iRes}                                                  },
    {lte::types::iMcs_t(28),    lte::enums::modulationOrder::Qm4,   lte::enums::modulationOrder::Qm4,   {lte::enums::i_tbs::iRes}                                                  },
    {lte::types::iMcs_t(29),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::iRes}                                                  },
    {lte::types::iMcs_t(30),    lte::enums::modulationOrder::Qm8,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::iRes}                                                  },
    {lte::types::iMcs_t(31),    lte::enums::modulationOrder::Qm10,  lte::enums::modulationOrder::Qm10,  {lte::enums::i_tbs::iRes}                                                  },
}};

// [4] Table 7.1.7.1-1C. Modulation and TBS index table 4 for PDSCH
inline const std::vector<mcs2tbsIndexTable_elem> mcs2tbsIndexTable4
{{
    {lte::types::iMcs_t(0),     lte::enums::modulationOrder::Qm2,   lte::enums::modulationOrder::Qm2,   {lte::enums::i_tbs::i0}                             },
    {lte::types::iMcs_t(1),     lte::enums::modulationOrder::Qm2,   lte::enums::modulationOrder::Qm2,   {lte::enums::i_tbs::i1}                             },
    {lte::types::iMcs_t(2),     lte::enums::modulationOrder::Qm2,   lte::enums::modulationOrder::Qm2,   {lte::enums::i_tbs::i2}                             },
    {lte::types::iMcs_t(3),     lte::enums::modulationOrder::Qm2,   lte::enums::modulationOrder::Qm2,   {lte::enums::i_tbs::i3}                             },
    {lte::types::iMcs_t(4),     lte::enums::modulationOrder::Qm2,   lte::enums::modulationOrder::Qm2,   {lte::enums::i_tbs::i4}                             },
    {lte::types::iMcs_t(5),     lte::enums::modulationOrder::Qm2,   lte::enums::modulationOrder::Qm4,   {lte::enums::i_tbs::i5}                             },
    {lte::types::iMcs_t(6),     lte::enums::modulationOrder::Qm2,   lte::enums::modulationOrder::Qm4,   {lte::enums::i_tbs::i6}                             },
    {lte::types::iMcs_t(7),     lte::enums::modulationOrder::Qm2,   lte::enums::modulationOrder::Qm4,   {lte::enums::i_tbs::i7}                             },
    {lte::types::iMcs_t(8),     lte::enums::modulationOrder::Qm2,   lte::enums::modulationOrder::Qm4,   {lte::enums::i_tbs::i8}                             },
    {lte::types::iMcs_t(9),     lte::enums::modulationOrder::Qm2,   lte::enums::modulationOrder::Qm4,   {lte::enums::i_tbs::i9}                             },
    {lte::types::iMcs_t(10),    lte::enums::modulationOrder::Qm4,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i9}                             },
    {lte::types::iMcs_t(11),    lte::enums::modulationOrder::Qm4,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i10}                            },
    {lte::types::iMcs_t(12),    lte::enums::modulationOrder::Qm4,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i11}                            },
    {lte::types::iMcs_t(13),    lte::enums::modulationOrder::Qm4,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i12}                            },
    {lte::types::iMcs_t(14),    lte::enums::modulationOrder::Qm4,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i13}                            },
    {lte::types::iMcs_t(15),    lte::enums::modulationOrder::Qm4,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i14}                            },
    {lte::types::iMcs_t(16),    lte::enums::modulationOrder::Qm4,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i15}                            },
    {lte::types::iMcs_t(17),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i15}                            },
    {lte::types::iMcs_t(18),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i16}                            },
    {lte::types::iMcs_t(19),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i17}                            },
    {lte::types::iMcs_t(20),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i18}                            },
    {lte::types::iMcs_t(21),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i19}                            },
    {lte::types::iMcs_t(22),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i20}                            },
    {lte::types::iMcs_t(23),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i21}                            },
    {lte::types::iMcs_t(24),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i22}                            },
    {lte::types::iMcs_t(25),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i23}                            },
    {lte::types::iMcs_t(26),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i24}                            },
    {lte::types::iMcs_t(27),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i25}                            },
    {lte::types::iMcs_t(28),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i27}                            },
    {lte::types::iMcs_t(29),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i28}                            },
    {lte::types::iMcs_t(30),    lte::enums::modulationOrder::Qm8,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i25}                            },
    {lte::types::iMcs_t(31),    lte::enums::modulationOrder::Qm8,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i27}                            },
    {lte::types::iMcs_t(32),    lte::enums::modulationOrder::Qm8,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i28}                            },
    {lte::types::iMcs_t(33),    lte::enums::modulationOrder::Qm8,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i29}                            },
    {lte::types::iMcs_t(34),    lte::enums::modulationOrder::Qm8,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i30}                            },
    {lte::types::iMcs_t(35),    lte::enums::modulationOrder::Qm8,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i31}                            },
    {lte::types::iMcs_t(36),    lte::enums::modulationOrder::Qm8,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i32}                            },
    {lte::types::iMcs_t(37),    lte::enums::modulationOrder::Qm8,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i33A}                           },
    {lte::types::iMcs_t(38),    lte::enums::modulationOrder::Qm8,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i33, lte::enums::i_tbs::i33B}   },
    {lte::types::iMcs_t(39),    lte::enums::modulationOrder::Qm10,  lte::enums::modulationOrder::Qm10,  {lte::enums::i_tbs::i34A}                           },
    {lte::types::iMcs_t(40),    lte::enums::modulationOrder::Qm10,  lte::enums::modulationOrder::Qm10,  {lte::enums::i_tbs::i35}                            },
    {lte::types::iMcs_t(41),    lte::enums::modulationOrder::Qm10,  lte::enums::modulationOrder::Qm10,  {lte::enums::i_tbs::i36}                            },
    {lte::types::iMcs_t(42),    lte::enums::modulationOrder::Qm10,  lte::enums::modulationOrder::Qm10,  {lte::enums::i_tbs::i37A}                           },
    {lte::types::iMcs_t(43),    lte::enums::modulationOrder::Qm10,  lte::enums::modulationOrder::Qm10,  {lte::enums::i_tbs::i37}                            },
    {lte::types::iMcs_t(44),    lte::enums::modulationOrder::Qm2,   lte::enums::modulationOrder::Qm2,   {lte::enums::i_tbs::i0}                             },
    {lte::types::iMcs_t(45),    lte::enums::modulationOrder::Qm2,   lte::enums::modulationOrder::Qm2,   {lte::enums::i_tbs::i2}                             },
    {lte::types::iMcs_t(46),    lte::enums::modulationOrder::Qm4,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i9}                             },
    {lte::types::iMcs_t(47),    lte::enums::modulationOrder::Qm4,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i11}                            },
    {lte::types::iMcs_t(48),    lte::enums::modulationOrder::Qm4,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i13}                            },
    {lte::types::iMcs_t(49),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i15}                            },
    {lte::types::iMcs_t(50),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i17}                            },
    {lte::types::iMcs_t(51),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i19}                            },
    {lte::types::iMcs_t(52),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::i21}                            },
    {lte::types::iMcs_t(53),    lte::enums::modulationOrder::Qm8,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i25}                            },
    {lte::types::iMcs_t(54),    lte::enums::modulationOrder::Qm8,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i28}                            },
    {lte::types::iMcs_t(55),    lte::enums::modulationOrder::Qm8,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i30}                            },
    {lte::types::iMcs_t(56),    lte::enums::modulationOrder::Qm8,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::i32}                            },
    {lte::types::iMcs_t(57),    lte::enums::modulationOrder::Qm10,  lte::enums::modulationOrder::Qm10,  {lte::enums::i_tbs::i34A}                           },
    {lte::types::iMcs_t(58),    lte::enums::modulationOrder::Qm10,  lte::enums::modulationOrder::Qm10,  {lte::enums::i_tbs::i36}                            },
    {lte::types::iMcs_t(59),    lte::enums::modulationOrder::Qm2,   lte::enums::modulationOrder::Qm2,   {lte::enums::i_tbs::iRes}                           },
    {lte::types::iMcs_t(60),    lte::enums::modulationOrder::Qm4,   lte::enums::modulationOrder::Qm4,   {lte::enums::i_tbs::iRes}                           },
    {lte::types::iMcs_t(61),    lte::enums::modulationOrder::Qm6,   lte::enums::modulationOrder::Qm6,   {lte::enums::i_tbs::iRes}                           },
    {lte::types::iMcs_t(62),    lte::enums::modulationOrder::Qm8,   lte::enums::modulationOrder::Qm8,   {lte::enums::i_tbs::iRes}                           },
    {lte::types::iMcs_t(63),    lte::enums::modulationOrder::Qm10,  lte::enums::modulationOrder::Qm10,  {lte::enums::i_tbs::iRes}                           },
}};

#endif /* _LTE_TABLES_36213_H_ */
