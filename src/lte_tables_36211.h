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
 *  [2] 3GPP TS 36.211 version 16.7.0 Release 16
 */

#include <array>
#include <vector>
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

// [1] Table 5.6-1: SC-FDMA parameters
inline constexpr std::array<uint32_t, lte::consts::nSlotsPerSubframe*lte::consts::nSymbolsPerSlotNormalCp> cpLenNormalCp = {160, 144, 144, 144, 144, 144, 144, 160, 144, 144, 144, 144, 144, 144};
inline constexpr std::array<uint32_t, lte::consts::nSlotsPerSubframe*lte::consts::nSymbolsPerSlotExtendedCp> cpLenExtendedCp = {512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512};

const specialSubframeBreakdown_t specialSubframeConfiguration_T4P2_1(const uint8_t specialSubframeConfig,
                                                                     const lte::enums::cpType dlCpType,
                                                                     const lte::enums::cpType ulCpType,
                                                                     uint8_t& numDlSymbols,
                                                                     uint8_t& numUlSymbols,
                                                                     uint8_t srs_len_upPtsAdd = 0);

typedef struct {
    // element describing the random access configuration in [1] Table 5.7.1-2
    lte::enums::prachPreambleFormat preambleFormat;
    lte::enums::prachOccasionFrameRepititionMode systemFrameNumber;
    std::vector<uint8_t> subframeNumber;
} randomAccessConfigurationElementFSType1;

// [1] Table 5.7.1-2: Frame structure type 1 random access configuration for preamble formats 0-3
inline const std::vector<std::pair<uint8_t, randomAccessConfigurationElementFSType1>> randomAccessConfigurationsFSType1_T5P7P1_2 =
{{
    {0	, {lte::enums::prachPreambleFormat::f0	, lte::enums::prachOccasionFrameRepititionMode::Even	, {1                              }}},
    {1	, {lte::enums::prachPreambleFormat::f0	, lte::enums::prachOccasionFrameRepititionMode::Even	, {4                              }}},
    {2	, {lte::enums::prachPreambleFormat::f0	, lte::enums::prachOccasionFrameRepititionMode::Even	, {7                              }}},
    {3	, {lte::enums::prachPreambleFormat::f0	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {1                              }}},
    {4	, {lte::enums::prachPreambleFormat::f0	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {4                              }}},
    {5	, {lte::enums::prachPreambleFormat::f0	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {7                              }}},
    {6	, {lte::enums::prachPreambleFormat::f0	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {1, 6                           }}},
    {7	, {lte::enums::prachPreambleFormat::f0	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {2 ,7                           }}},
    {8	, {lte::enums::prachPreambleFormat::f0	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {3, 8                           }}},
    {9	, {lte::enums::prachPreambleFormat::f0	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {1, 4, 7                        }}},
    {10	, {lte::enums::prachPreambleFormat::f0	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {2, 5, 8                        }}},
    {11	, {lte::enums::prachPreambleFormat::f0	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {3, 6, 9                        }}},
    {12	, {lte::enums::prachPreambleFormat::f0	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {0, 2, 4, 6, 8                  }}},
    {13	, {lte::enums::prachPreambleFormat::f0	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {1, 3, 5, 7, 9                  }}},
    {14	, {lte::enums::prachPreambleFormat::f0	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {0, 1, 2, 3, 4, 5, 6, 7, 8, 9   }}},
    {15	, {lte::enums::prachPreambleFormat::f0	, lte::enums::prachOccasionFrameRepititionMode::Even	, {9                              }}},
    {16	, {lte::enums::prachPreambleFormat::f1	, lte::enums::prachOccasionFrameRepititionMode::Even	, {1                              }}},
    {17	, {lte::enums::prachPreambleFormat::f1	, lte::enums::prachOccasionFrameRepititionMode::Even	, {4                              }}},
    {18	, {lte::enums::prachPreambleFormat::f1	, lte::enums::prachOccasionFrameRepititionMode::Even	, {7                              }}},
    {19	, {lte::enums::prachPreambleFormat::f1	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {1                              }}},
    {20	, {lte::enums::prachPreambleFormat::f1	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {4                              }}},
    {21	, {lte::enums::prachPreambleFormat::f1	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {7                              }}},
    {22	, {lte::enums::prachPreambleFormat::f1	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {1, 6                           }}},
    {23	, {lte::enums::prachPreambleFormat::f1	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {2 ,7                           }}},
    {24	, {lte::enums::prachPreambleFormat::f1	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {3, 8                           }}},
    {25	, {lte::enums::prachPreambleFormat::f1	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {1, 4, 7                        }}},
    {26	, {lte::enums::prachPreambleFormat::f1	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {2, 5, 8                        }}},
    {27	, {lte::enums::prachPreambleFormat::f1	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {3, 6, 9                        }}},
    {28	, {lte::enums::prachPreambleFormat::f1	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {0, 2, 4, 6, 8                  }}},
    {29	, {lte::enums::prachPreambleFormat::f1	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {1, 3, 5, 7, 9                  }}},
    {30	, {lte::enums::prachPreambleFormat::fNA	, lte::enums::prachOccasionFrameRepititionMode::NA	    , {                               }}},
    {31	, {lte::enums::prachPreambleFormat::f1	, lte::enums::prachOccasionFrameRepititionMode::Even	, {9                              }}},
    {32	, {lte::enums::prachPreambleFormat::f2	, lte::enums::prachOccasionFrameRepititionMode::Even	, {1                              }}},
    {33	, {lte::enums::prachPreambleFormat::f2	, lte::enums::prachOccasionFrameRepititionMode::Even	, {4                              }}},
    {34	, {lte::enums::prachPreambleFormat::f2	, lte::enums::prachOccasionFrameRepititionMode::Even	, {7                              }}},
    {35	, {lte::enums::prachPreambleFormat::f2	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {1                              }}},
    {36	, {lte::enums::prachPreambleFormat::f2	, lte::enums::prachOccasionFrameRepititionMode::Any 	, {4                              }}},
    {37	, {lte::enums::prachPreambleFormat::f2	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {7                              }}},
    {38	, {lte::enums::prachPreambleFormat::f2	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {1, 6                           }}},
    {39	, {lte::enums::prachPreambleFormat::f2	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {2 ,7                           }}},
    {40	, {lte::enums::prachPreambleFormat::f2	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {3, 8                           }}},
    {41	, {lte::enums::prachPreambleFormat::f2	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {1, 4, 7                        }}},
    {42	, {lte::enums::prachPreambleFormat::f2	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {2, 5, 8                        }}},
    {43	, {lte::enums::prachPreambleFormat::f2	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {3, 6, 9                        }}},
    {44	, {lte::enums::prachPreambleFormat::f2	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {0, 2, 4, 6, 8                  }}},
    {45	, {lte::enums::prachPreambleFormat::f2	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {1, 3, 5, 7, 9                  }}},
    {46	, {lte::enums::prachPreambleFormat::fNA	, lte::enums::prachOccasionFrameRepititionMode::NA	    , {                               }}},
    {47	, {lte::enums::prachPreambleFormat::f2	, lte::enums::prachOccasionFrameRepititionMode::Even	, {9                              }}},
    {48	, {lte::enums::prachPreambleFormat::f3	, lte::enums::prachOccasionFrameRepititionMode::Even	, {1                              }}},
    {49	, {lte::enums::prachPreambleFormat::f3	, lte::enums::prachOccasionFrameRepititionMode::Even	, {4                              }}},
    {50	, {lte::enums::prachPreambleFormat::f3	, lte::enums::prachOccasionFrameRepititionMode::Even	, {7                              }}},
    {51	, {lte::enums::prachPreambleFormat::f3	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {1                              }}},
    {52	, {lte::enums::prachPreambleFormat::f3	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {4                              }}},
    {53	, {lte::enums::prachPreambleFormat::f3	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {7                              }}},
    {54	, {lte::enums::prachPreambleFormat::f3	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {1, 6                           }}},
    {55	, {lte::enums::prachPreambleFormat::f3	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {2 ,7                           }}},
    {56	, {lte::enums::prachPreambleFormat::f3	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {3, 8                           }}},
    {57	, {lte::enums::prachPreambleFormat::f3	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {1, 4, 7                        }}},
    {58	, {lte::enums::prachPreambleFormat::f3	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {2, 5, 8                        }}},
    {59	, {lte::enums::prachPreambleFormat::f3	, lte::enums::prachOccasionFrameRepititionMode::Any	    , {3, 6, 9                        }}},
    {60	, {lte::enums::prachPreambleFormat::fNA	, lte::enums::prachOccasionFrameRepititionMode::NA	    , {                               }}},
    {61	, {lte::enums::prachPreambleFormat::fNA	, lte::enums::prachOccasionFrameRepititionMode::NA	    , {                               }}},
    {62	, {lte::enums::prachPreambleFormat::fNA	, lte::enums::prachOccasionFrameRepititionMode::NA	    , {                               }}},
    {63	, {lte::enums::prachPreambleFormat::f3	, lte::enums::prachOccasionFrameRepititionMode::Even	, {9                              }}},
}};

typedef struct {
    // element describing the random access configuration in [1] Table 5.7.1-3
    lte::enums::prachPreambleFormat preambleFormat;
    lte::enums::prachDensity prachDensity;
    lte::enums::prachVersion prachVersion;
} randomAccessConfigurationElementFSType2;

inline const std::vector<std::pair<uint8_t, randomAccessConfigurationElementFSType2>> randomAccessConfigurationsFSType2_T5P7P1_3 =
{{
        {0   , {lte::enums::prachPreambleFormat::f0   , lte::enums::prachDensity::d0P5 , lte::enums::prachVersion::v0      }},
        {1   , {lte::enums::prachPreambleFormat::f0   , lte::enums::prachDensity::d0P5 , lte::enums::prachVersion::v1      }},
        {2   , {lte::enums::prachPreambleFormat::f0   , lte::enums::prachDensity::d0P5 , lte::enums::prachVersion::v2      }},
        {3   , {lte::enums::prachPreambleFormat::f0   , lte::enums::prachDensity::d1   , lte::enums::prachVersion::v0      }},
        {4   , {lte::enums::prachPreambleFormat::f0   , lte::enums::prachDensity::d1   , lte::enums::prachVersion::v1      }},
        {5   , {lte::enums::prachPreambleFormat::f0   , lte::enums::prachDensity::d1   , lte::enums::prachVersion::v2      }},
        {6   , {lte::enums::prachPreambleFormat::f0   , lte::enums::prachDensity::d2   , lte::enums::prachVersion::v0      }},
        {7   , {lte::enums::prachPreambleFormat::f0   , lte::enums::prachDensity::d2   , lte::enums::prachVersion::v1      }},
        {8   , {lte::enums::prachPreambleFormat::f0   , lte::enums::prachDensity::d2   , lte::enums::prachVersion::v2      }},
        {9   , {lte::enums::prachPreambleFormat::f0   , lte::enums::prachDensity::d3   , lte::enums::prachVersion::v0      }},
        {10  , {lte::enums::prachPreambleFormat::f0   , lte::enums::prachDensity::d3   , lte::enums::prachVersion::v1      }},
        {11  , {lte::enums::prachPreambleFormat::f0   , lte::enums::prachDensity::d3   , lte::enums::prachVersion::v2      }},
        {12  , {lte::enums::prachPreambleFormat::f0   , lte::enums::prachDensity::d4   , lte::enums::prachVersion::v0      }},
        {13  , {lte::enums::prachPreambleFormat::f0   , lte::enums::prachDensity::d4   , lte::enums::prachVersion::v1      }},
        {14  , {lte::enums::prachPreambleFormat::f0   , lte::enums::prachDensity::d4   , lte::enums::prachVersion::v2      }},
        {15  , {lte::enums::prachPreambleFormat::f0   , lte::enums::prachDensity::d5   , lte::enums::prachVersion::v0      }},
        {16  , {lte::enums::prachPreambleFormat::f0   , lte::enums::prachDensity::d5   , lte::enums::prachVersion::v1      }},
        {17  , {lte::enums::prachPreambleFormat::f0   , lte::enums::prachDensity::d5   , lte::enums::prachVersion::v2      }},
        {18  , {lte::enums::prachPreambleFormat::f0   , lte::enums::prachDensity::d6   , lte::enums::prachVersion::v0      }},
        {19  , {lte::enums::prachPreambleFormat::f0   , lte::enums::prachDensity::d6   , lte::enums::prachVersion::v1      }},
        {20  , {lte::enums::prachPreambleFormat::f1   , lte::enums::prachDensity::d0P5 , lte::enums::prachVersion::v0      }},
        {21  , {lte::enums::prachPreambleFormat::f1   , lte::enums::prachDensity::d0P5 , lte::enums::prachVersion::v1      }},
        {22  , {lte::enums::prachPreambleFormat::f1   , lte::enums::prachDensity::d0P5 , lte::enums::prachVersion::v2      }},
        {23  , {lte::enums::prachPreambleFormat::f1   , lte::enums::prachDensity::d1   , lte::enums::prachVersion::v0      }},
        {24  , {lte::enums::prachPreambleFormat::f1   , lte::enums::prachDensity::d1   , lte::enums::prachVersion::v1      }},
        {25  , {lte::enums::prachPreambleFormat::f1   , lte::enums::prachDensity::d2   , lte::enums::prachVersion::v0      }},
        {26  , {lte::enums::prachPreambleFormat::f1   , lte::enums::prachDensity::d3   , lte::enums::prachVersion::v0      }},
        {27  , {lte::enums::prachPreambleFormat::f1   , lte::enums::prachDensity::d4   , lte::enums::prachVersion::v0      }},
        {28  , {lte::enums::prachPreambleFormat::f1   , lte::enums::prachDensity::d5   , lte::enums::prachVersion::v0      }},
        {29  , {lte::enums::prachPreambleFormat::f1   , lte::enums::prachDensity::d6   , lte::enums::prachVersion::v0      }},
        {30  , {lte::enums::prachPreambleFormat::f2   , lte::enums::prachDensity::d0P5 , lte::enums::prachVersion::v0      }},
        {31  , {lte::enums::prachPreambleFormat::f2   , lte::enums::prachDensity::d0P5 , lte::enums::prachVersion::v1      }},
        {32  , {lte::enums::prachPreambleFormat::f2   , lte::enums::prachDensity::d0P5 , lte::enums::prachVersion::v2      }},
        {33  , {lte::enums::prachPreambleFormat::f2   , lte::enums::prachDensity::d1   , lte::enums::prachVersion::v0      }},
        {34  , {lte::enums::prachPreambleFormat::f2   , lte::enums::prachDensity::d1   , lte::enums::prachVersion::v1      }},
        {35  , {lte::enums::prachPreambleFormat::f2   , lte::enums::prachDensity::d2   , lte::enums::prachVersion::v0      }},
        {36  , {lte::enums::prachPreambleFormat::f2   , lte::enums::prachDensity::d3   , lte::enums::prachVersion::v0      }},
        {37  , {lte::enums::prachPreambleFormat::f2   , lte::enums::prachDensity::d4   , lte::enums::prachVersion::v0      }},
        {38  , {lte::enums::prachPreambleFormat::f2   , lte::enums::prachDensity::d5   , lte::enums::prachVersion::v0      }},
        {39  , {lte::enums::prachPreambleFormat::f2   , lte::enums::prachDensity::d6   , lte::enums::prachVersion::v0      }},
        {40  , {lte::enums::prachPreambleFormat::f3   , lte::enums::prachDensity::d0P5 , lte::enums::prachVersion::v0      }},
        {41  , {lte::enums::prachPreambleFormat::f3   , lte::enums::prachDensity::d0P5 , lte::enums::prachVersion::v1      }},
        {42  , {lte::enums::prachPreambleFormat::f3   , lte::enums::prachDensity::d0P5 , lte::enums::prachVersion::v2      }},
        {43  , {lte::enums::prachPreambleFormat::f3   , lte::enums::prachDensity::d1   , lte::enums::prachVersion::v0      }},
        {44  , {lte::enums::prachPreambleFormat::f3   , lte::enums::prachDensity::d1   , lte::enums::prachVersion::v1      }},
        {45  , {lte::enums::prachPreambleFormat::f3   , lte::enums::prachDensity::d2   , lte::enums::prachVersion::v0      }},
        {46  , {lte::enums::prachPreambleFormat::f3   , lte::enums::prachDensity::d3   , lte::enums::prachVersion::v0      }},
        {47  , {lte::enums::prachPreambleFormat::f3   , lte::enums::prachDensity::d4   , lte::enums::prachVersion::v0      }},
        {48  , {lte::enums::prachPreambleFormat::f4   , lte::enums::prachDensity::d0P5 , lte::enums::prachVersion::v0      }},
        {49  , {lte::enums::prachPreambleFormat::f4   , lte::enums::prachDensity::d0P5 , lte::enums::prachVersion::v1      }},
        {50  , {lte::enums::prachPreambleFormat::f4   , lte::enums::prachDensity::d0P5 , lte::enums::prachVersion::v2      }},
        {51  , {lte::enums::prachPreambleFormat::f4   , lte::enums::prachDensity::d1   , lte::enums::prachVersion::v0      }},
        {52  , {lte::enums::prachPreambleFormat::f4   , lte::enums::prachDensity::d1   , lte::enums::prachVersion::v1      }},
        {53  , {lte::enums::prachPreambleFormat::f4   , lte::enums::prachDensity::d2   , lte::enums::prachVersion::v0      }},
        {54  , {lte::enums::prachPreambleFormat::f4   , lte::enums::prachDensity::d3   , lte::enums::prachVersion::v0      }},
        {55  , {lte::enums::prachPreambleFormat::f4   , lte::enums::prachDensity::d4   , lte::enums::prachVersion::v0      }},
        {56  , {lte::enums::prachPreambleFormat::f4   , lte::enums::prachDensity::d5   , lte::enums::prachVersion::v0      }},
        {57  , {lte::enums::prachPreambleFormat::f4   , lte::enums::prachDensity::d6   , lte::enums::prachVersion::v0      }},
        {58  , {lte::enums::prachPreambleFormat::fNA , lte::enums::prachDensity::dNA   , lte::enums::prachVersion::vNA     }},
        {59  , {lte::enums::prachPreambleFormat::fNA , lte::enums::prachDensity::dNA   , lte::enums::prachVersion::vNA     }},
        {60  , {lte::enums::prachPreambleFormat::fNA , lte::enums::prachDensity::dNA   , lte::enums::prachVersion::vNA     }},
        {61  , {lte::enums::prachPreambleFormat::fNA , lte::enums::prachDensity::dNA   , lte::enums::prachVersion::vNA     }},
        {62  , {lte::enums::prachPreambleFormat::fNA , lte::enums::prachDensity::dNA   , lte::enums::prachVersion::vNA     }},
        {63  , {lte::enums::prachPreambleFormat::fNA , lte::enums::prachDensity::dNA   , lte::enums::prachVersion::vNA     }},
}};

typedef struct {
    // frequency resource index within the considered time instance
    uint8_t freqResIdx;
    lte::enums::prachOccasionTDDFrameRepMode tRA0;
    lte::enums::prachOccasionTDDNhf tRA1;
    // startSubframe: the uplink subframe number where the preamble starts,
    // counting from 0 at the first uplink subframe between 2 consecutive
    // downlink-to-uplink switch points.
    uint8_t startSubframe;
} randomAccessPremableMappingFSType2Elem;

const std::vector<std::pair<uint8_t, std::array<std::vector<randomAccessPremableMappingFSType2Elem>, lte::consts::numTddUlDlConfigurations>>>& randomAccessPreambleMappingFSType2_T5P7P1_4();

// [1] Table 5.7.2-4: Root Zadoff-Chu sequence order for preamble formats 0 – 3
inline const std::vector<std::pair<std::pair<uint16_t, uint16_t>, std::vector<uint16_t>>> rootZCSequenceOrder_formats0_3 =
{{
        {{0   , 23  }, {129, 710, 140, 699, 120, 719, 210, 629, 168, 671, 84, 755, 105, 734, 93, 746, 70, 769, 60, 779, 2, 837, 1, 838                                                                                                                                                                                                                                                  }},
        {{24  , 29  }, {56, 783, 112, 727, 148, 691                                                                                                                                                                                                                                                                                                                                     }},
        {{30  , 35  }, {80, 759, 42, 797, 40, 799                                                                                                                                                                                                                                                                                                                                       }},
        {{36  , 41  }, {35, 804, 73, 766, 146, 693                                                                                                                                                                                                                                                                                                                                      }},
        {{42  , 51  }, {31, 808, 28, 811, 30, 809, 27, 812, 29, 810                                                                                                                                                                                                                                                                                                                     }},
        {{52  , 63  }, {24, 815, 48, 791, 68, 771, 74, 765, 178, 661, 136, 703                                                                                                                                                                                                                                                                                                          }},
        {{64  , 75  }, {86, 753, 78, 761, 43, 796, 39, 800, 20, 819, 21, 818                                                                                                                                                                                                                                                                                                            }},
        {{76  , 89  }, {95, 744, 202, 637, 190, 649, 181, 658, 137, 702, 125, 714, 151, 688                                                                                                                                                                                                                                                                                             }},
        {{90  , 115 }, {217, 622, 128, 711, 142, 697, 122, 717, 203, 636, 118, 721, 110, 729, 89, 750, 103, 736, 61, 778, 55, 784, 15, 824, 14, 825                                                                                                                                                                                                                                     }},
        {{116 , 135 }, {12, 827, 23, 816, 34, 805, 37, 802, 46, 793, 207, 632, 179, 660, 145, 694, 130, 709, 223, 616                                                                                                                                                                                                                                                                   }},
        {{136 , 167 }, {228, 611, 227, 612, 132, 707, 133, 706, 143, 696, 135, 704, 161, 678, 201, 638, 173, 666, 106, 733, 83, 756, 91, 748, 66, 773, 53, 786, 10, 829, 9, 830                                                                                                                                                                                                         }},
        {{168 , 203 }, {7, 832, 8, 831, 16, 823, 47, 792, 64, 775, 57, 782, 104, 735, 101, 738, 108, 731, 208, 631, 184, 655, 197, 642, 191, 648, 121, 718, 141, 698, 149, 690, 216, 623, 218, 621                                                                                                                                                                                      }},
        {{204 , 263 }, {152, 687, 144, 695, 134, 705, 138, 701, 199, 640, 162, 677, 176, 663, 119, 720, 158, 681, 164, 675, 174, 665, 171, 668, 170, 669, 87, 752, 169, 670, 88, 751, 107, 732, 81, 758, 82, 757, 100, 739, 98, 741, 71, 768, 59, 780, 65, 774, 50, 789, 49, 790, 26, 813, 17, 822, 13, 826, 6, 833                                                                     }},
        {{264 , 327 }, {5, 834, 33, 806, 51, 788, 75, 764, 99, 740, 96, 743, 97, 742, 166, 673, 172, 667, 175, 664, 187, 652, 163, 676, 185, 654, 200, 639, 114, 725, 189, 650, 115, 724, 194, 645, 195, 644, 192, 647, 182, 657, 157, 682, 156, 683, 211, 628, 154, 685, 123, 716, 139, 700, 212, 627, 153, 686, 213, 626, 215, 624, 150, 689                                          }},
        {{328 , 383 }, {225, 614, 224, 615, 221, 618, 220, 619, 127, 712, 147, 692, 124, 715, 193, 646, 205, 634, 206, 633, 116, 723, 160, 679, 186, 653, 167, 672, 79, 760, 85, 754, 77, 762, 92, 747, 58, 781, 62, 777, 69, 770, 54, 785, 36, 803, 32, 807, 25, 814, 18, 821, 11, 828, 4, 835                                                                                         }},
        {{384 , 455 }, {3, 836, 19, 820, 22, 817, 41, 798, 38, 801, 44, 795, 52, 787, 45, 794, 63, 776, 67, 772, 72, 767, 76, 763, 94, 745, 102, 737, 90, 749, 109, 730, 165, 674, 111, 728, 209, 630, 204, 635, 117, 722, 188, 651, 159, 680, 198, 641, 113, 726, 183, 656, 180, 659, 177, 662, 196, 643, 155, 684, 214, 625, 126, 713, 131, 708, 219, 620, 222, 617, 226, 613         }},
        {{456 , 513 }, {230, 609, 232, 607, 262, 577, 252, 587, 418, 421, 416, 423, 413, 426, 411, 428, 376, 463, 395, 444, 283, 556, 285, 554, 379, 460, 390, 449, 363, 476, 384, 455, 388, 451, 386, 453, 361, 478, 387, 452, 360, 479, 310, 529, 354, 485, 328, 511, 315, 524, 337, 502, 349, 490, 335, 504, 324, 515                                                                }},
        {{514 , 561 }, {323, 516, 320, 519, 334, 505, 359, 480, 295, 544, 385, 454, 292, 547, 291, 548, 381, 458, 399, 440, 380, 459, 397, 442, 369, 470, 377, 462, 410, 429, 407, 432, 281, 558, 414, 425, 247, 592, 277, 562, 271, 568, 272, 567, 264, 575, 259, 580                                                                                                                  }},
        {{562 , 629 }, {237, 602, 239, 600, 244, 595, 243, 596, 275, 564, 278, 561, 250, 589, 246, 593, 417, 422, 248, 591, 394, 445, 393, 446, 370, 469, 365, 474, 300, 539, 299, 540, 364, 475, 362, 477, 298, 541, 312, 527, 313, 526, 314, 525, 353, 486, 352, 487, 343, 496, 327, 512, 350, 489, 326, 513, 319, 520, 332, 507, 333, 506, 348, 491, 347, 492, 322, 517              }},
        {{630 , 659 }, {330, 509, 338, 501, 341, 498, 340, 499, 342, 497, 301, 538, 366, 473, 401, 438, 371, 468, 408, 431, 375, 464, 249, 590, 269, 570, 238, 601, 234, 605                                                                                                                                                                                                            }},
        {{660 , 707 }, {257, 582, 273, 566, 255, 584, 254, 585, 245, 594, 251, 588, 412, 427, 372, 467, 282, 557, 403, 436, 396, 443, 392, 447, 391, 448, 382, 457, 389, 450, 294, 545, 297, 542, 311, 528, 344, 495, 345, 494, 318, 521, 331, 508, 325, 514, 321, 518                                                                                                                  }},
        {{708 , 729 }, {346, 493, 339, 500, 351, 488, 306, 533, 289, 550, 400, 439, 378, 461, 374, 465, 415, 424, 270, 569, 241, 598                                                                                                                                                                                                                                                    }},
        {{730 , 751 }, {231, 608, 260, 579, 268, 571, 276, 563, 409, 430, 398, 441, 290, 549, 304, 535, 308, 531, 358, 481, 316, 523                                                                                                                                                                                                                                                    }},
        {{752 , 765 }, {293, 546, 288, 551, 284, 555, 368, 471, 253, 586, 256, 583, 263, 576                                                                                                                                                                                                                                                                                            }},
        {{766 , 777 }, {242, 597, 274, 565, 402, 437, 383, 456, 357, 482, 329, 510                                                                                                                                                                                                                                                                                                      }},
        {{778 , 789 }, {317, 522, 307, 532, 286, 553, 287, 552, 266, 573, 261, 578                                                                                                                                                                                                                                                                                                      }},
        {{790 , 795 }, {236, 603, 303, 536, 356, 483                                                                                                                                                                                                                                                                                                                                    }},
        {{796 , 803 }, {355, 484, 405, 434, 404, 435, 406, 433                                                                                                                                                                                                                                                                                                                          }},
        {{804 , 809 }, {235, 604, 267, 572, 302, 537                                                                                                                                                                                                                                                                                                                                    }},
        {{810 , 815 }, {309, 530, 265, 574, 233, 606                                                                                                                                                                                                                                                                                                                                    }},
        {{816 , 819 }, {367, 472, 296, 543                                                                                                                                                                                                                                                                                                                                              }},
        {{820 , 837 }, {336, 503, 305, 534, 373, 466, 280, 559, 279, 560, 419, 420, 240, 599, 258, 581, 229, 610                                                                                                                                                                                                                                                                        }},
}};

typedef struct {
    uint8_t mSrs;
    uint8_t N;
} srsBandwidthConfigPerUe;

constexpr uint8_t numSrsBandwidthConfigurations = 8;    // cell specific parameter srs-BandwidthConfig $C_{SRS} \in {0,1,2,3,4,5,6,7}$.
constexpr uint8_t numSrsBandwidthOptions = 4;           // UE specific parameter srs-Bandwidth $B_{SRS} \in {0,1,2,3}$.
// [1] Table 5.5.3.2-1: srsBandwidthConfigPerUe values for the uplink bandwidth of 6 <= N UL <= 40
inline constexpr std::array<std::pair<uint8_t, std::array<srsBandwidthConfigPerUe, numSrsBandwidthOptions>>, numSrsBandwidthConfigurations> srsBandwidthPerUe_T5P5P3P2_1 =
{{
        {0,{{{36,1},{12,3},{4,3},{4,1}}}},
        {1,{{{32,1},{16,2},{8,2},{4,2}}}},
        {2,{{{24,1},{4,6},{4,1},{4,1}}}},
        {3,{{{20,1},{4,5},{4,1},{4,1}}}},
        {4,{{{16,1},{4,4},{4,1},{4,1}}}},
        {5,{{{12,1},{4,3},{4,1},{4,1}}}},
        {6,{{{8,1},{4,2},{4,1},{4,1}}}},
        {7,{{{4,1},{4,1},{4,1},{4,1}}}}

}};

// [1] Table 5.5.3.2-2: srsBandwidthConfigPerUe values for the uplink bandwidth of 40 < N UL <= 60
inline constexpr std::array<std::pair<uint8_t, std::array<srsBandwidthConfigPerUe, numSrsBandwidthOptions>>, numSrsBandwidthConfigurations> srsBandwidthPerUe_T5P5P3P2_2 =
{{
        {0,{{{48,1},{24,2},{12,2},{4,3}}}},
        {1,{{{48,1},{16,3},{8,2},{4,2}}}},
        {2,{{{40,1},{20,2},{4,5},{4,1}}}},
        {3,{{{36,1},{12,3},{4,3},{4,1}}}},
        {4,{{{32,1},{16,2},{8,2},{4,2}}}},
        {5,{{{24,1},{4,6},{4,1},{4,1}}}},
        {6,{{{20,1},{4,5},{4,1},{4,1}}}},
        {7,{{{16,1},{4,4},{4,1},{4,1}}}}
}};

// [1] Table 5.5.3.2-3: srsBandwidthConfigPerUe values for the uplink bandwidth of 60 < N UL <= 80
inline constexpr std::array<std::pair<uint8_t, std::array<srsBandwidthConfigPerUe, numSrsBandwidthOptions>>, numSrsBandwidthConfigurations> srsBandwidthPerUe_T5P5P3P2_3 =
{{
        {0,{{{72,1},{24,3},{12,2},{4,3}}}},
        {1,{{{64,1},{32,2},{16,2},{4,4}}}},
        {2,{{{60,1},{20,3},{4,5},{4,1}}}},
        {3,{{{48,1},{24,2},{12,2},{4,3}}}},
        {4,{{{48,1},{16,3},{8,2},{4,2}}}},
        {5,{{{40,1},{20,2},{4,5},{4,1}}}},
        {6,{{{36,1},{12,3},{4,3},{4,1}}}},
        {7,{{{32,1},{16,2},{8,2},{4,2}}}}
}};

// [1] Table 5.5.3.2-4: srsBandwidthConfigPerUe values for the uplink bandwidth of 80 < N UL <= 110
inline constexpr std::array<std::pair<uint8_t, std::array<srsBandwidthConfigPerUe, numSrsBandwidthOptions>>, numSrsBandwidthConfigurations> srsBandwidthPerUe_T5P5P3P2_4 =
{{
        {0,{{{96,1},{48,2},{24,2},{4,6}}}},
        {1,{{{96,1},{32,3},{16,2},{4,4}}}},
        {2,{{{80,1},{40,2},{20,2},{4,5}}}},
        {3,{{{72,1},{24,3},{12,2},{4,3}}}},
        {4,{{{64,1},{32,2},{16,2},{4,4}}}},
        {5,{{{60,1},{20,3},{4,5},{4,1}}}},
        {6,{{{48,1},{24,2},{12,2},{4,3}}}},
        {7,{{{48,1},{16,3},{8,2},{4,2}}}}
}};

inline constexpr std::array<std::pair<uint16_t, std::pair<int16_t, int16_t>>, 16> modulationMapperBPSK =
{{
        {0b0  ,{1   ,1}},
        {0b1  ,{-1  ,-1}},
}};

inline constexpr std::array<std::pair<uint16_t, std::pair<int16_t, int16_t>>, 16> modulationMapperQPSK =
{{
        {0b00  ,{1   ,1}},
        {0b01  ,{1   ,-1}},
        {0b10  ,{-1  ,1}},
        {0b11  ,{-1  ,-1}},
}};

inline constexpr std::array<std::pair<uint16_t, std::pair<int16_t, int16_t>>, 16> modulationMapper16QAM =
{{
        {0b0000    ,{1     ,1  }},
        {0b0001    ,{1     ,3  }},
        {0b0010    ,{3     ,1  }},
        {0b0011    ,{3     ,3  }},
        {0b0100    ,{1     ,-1 }},
        {0b0101    ,{1     ,-3 }},
        {0b0110    ,{3     ,-1 }},
        {0b0111    ,{3     ,-3 }},
        {0b1000    ,{-1    ,1  }},
        {0b1001    ,{-1    ,3  }},
        {0b1010    ,{-3    ,1  }},
        {0b1011    ,{-3    ,3  }},
        {0b1100    ,{-1    ,-1 }},
        {0b1101    ,{-1    ,-3 }},
        {0b1110    ,{-3    ,-1 }},
        {0b1111    ,{-3    ,-3 }},
}};

inline constexpr std::array<std::pair<uint16_t, std::pair<int16_t, int16_t>>, 64> modulationMapper64QAM =
{{
        {0b000000      ,{3      ,3  }},
        {0b000001      ,{3      ,1  }},
        {0b000010      ,{1      ,3  }},
        {0b000011      ,{1      ,1  }},
        {0b000100      ,{3      ,5  }},
        {0b000101      ,{3      ,7  }},
        {0b000110      ,{1      ,5  }},
        {0b000111      ,{1      ,7  }},
        {0b001000      ,{5      ,3  }},
        {0b001001      ,{5      ,1  }},
        {0b001010      ,{7      ,3  }},
        {0b001011      ,{7      ,1  }},
        {0b001100      ,{5      ,5  }},
        {0b001101      ,{5      ,7  }},
        {0b001110      ,{7      ,5  }},
        {0b001111      ,{7      ,7  }},
        {0b010000      ,{3      ,-3 }},
        {0b010001      ,{3      ,-1 }},
        {0b010010      ,{1      ,-3 }},
        {0b010011      ,{1      ,-1 }},
        {0b010100      ,{3      ,-5 }},
        {0b010101      ,{3      ,-7 }},
        {0b010110      ,{1      ,-5 }},
        {0b010111      ,{1      ,-7 }},
        {0b011000      ,{5      ,-3 }},
        {0b011001      ,{5      ,-1 }},
        {0b011010      ,{7      ,-3 }},
        {0b011011      ,{7      ,-1 }},
        {0b011100      ,{5      ,-5 }},
        {0b011101      ,{5      ,-7 }},
        {0b011110      ,{7      ,-5 }},
        {0b011111      ,{7      ,-7 }},
        {0b100000      ,{-3     ,3  }},
        {0b100001      ,{-3     ,1  }},
        {0b100010      ,{-1     ,3  }},
        {0b100011      ,{-1     ,1  }},
        {0b100100      ,{-3     ,5  }},
        {0b100101      ,{-3     ,7  }},
        {0b100110      ,{-1     ,5  }},
        {0b100111      ,{-1     ,7  }},
        {0b101000      ,{-5     ,3  }},
        {0b101001      ,{-5     ,1  }},
        {0b101010      ,{-7     ,3  }},
        {0b101011      ,{-7     ,1  }},
        {0b101100      ,{-5     ,5  }},
        {0b101101      ,{-5     ,7  }},
        {0b101110      ,{-7     ,5  }},
        {0b101111      ,{-7     ,7  }},
        {0b110000      ,{-3     ,-3 }},
        {0b110001      ,{-3     ,-1 }},
        {0b110010      ,{-1     ,-3 }},
        {0b110011      ,{-1     ,-1 }},
        {0b110100      ,{-3     ,-5 }},
        {0b110101      ,{-3     ,-7 }},
        {0b110110      ,{-1     ,-5 }},
        {0b110111      ,{-1     ,-7 }},
        {0b111000      ,{-5     ,-3 }},
        {0b111001      ,{-5     ,-1 }},
        {0b111010      ,{-7     ,-3 }},
        {0b111011      ,{-7     ,-1 }},
        {0b111100      ,{-5     ,-5 }},
        {0b111101      ,{-5     ,-7 }},
        {0b111110      ,{-7     ,-5 }},
        {0b111111      ,{-7     ,-7 }},
}};


inline constexpr std::array<std::pair<uint16_t, std::pair<int16_t, int16_t>>, 256> modulationMapper256QAM =
{{
        {0b00000000,    {5,   5    }},
        {0b00000001,    {5,   7    }},
        {0b00000010,    {7,   5    }},
        {0b00000011,    {7,   7    }},
        {0b00000100,    {5,   3    }},
        {0b00000101,    {5,   1    }},
        {0b00000110,    {7,   3    }},
        {0b00000111,    {7,   1    }},
        {0b00001000,    {3,   5    }},
        {0b00001001,    {3,   7    }},
        {0b00001010,    {1,   5    }},
        {0b00001011,    {1,   7    }},
        {0b00001100,    {3,   3    }},
        {0b00001101,    {3,   1    }},
        {0b00001110,    {1,   3    }},
        {0b00001111,    {1,   1    }},
        {0b00010000,    {5,   11   }},
        {0b00010001,    {5,   9    }},
        {0b00010010,    {7,   11   }},
        {0b00010011,    {7,   9    }},
        {0b00010100,    {5,   13   }},
        {0b00010101,    {5,   15   }},
        {0b00010110,    {7,   13   }},
        {0b00010111,    {7,   15   }},
        {0b00011000,    {3,   11   }},
        {0b00011001,    {3,   9    }},
        {0b00011010,    {1,   11   }},
        {0b00011011,    {1,   9    }},
        {0b00011100,    {3,   13   }},
        {0b00011101,    {3,   15   }},
        {0b00011110,    {1,   13   }},
        {0b00011111,    {1,   15   }},
        {0b00100000,    {11,  5    }},
        {0b00100001,    {11,  7    }},
        {0b00100010,    {9,   5    }},
        {0b00100011,    {9,   7    }},
        {0b00100100,    {11,  3    }},
        {0b00100101,    {11,  1    }},
        {0b00100110,    {9,   3    }},
        {0b00100111,    {9,   1    }},
        {0b00101000,    {13,  5    }},
        {0b00101001,    {13,  7    }},
        {0b00101010,    {15,  5    }},
        {0b00101011,    {15,  7    }},
        {0b00101100,    {13,  3    }},
        {0b00101101,    {13,  1    }},
        {0b00101110,    {15,  3    }},
        {0b00101111,    {15,  1    }},
        {0b00110000,    {11,  11   }},
        {0b00110001,    {11,  9    }},
        {0b00110010,    {9,   11   }},
        {0b00110011,    {9,   9    }},
        {0b00110100,    {11,  13   }},
        {0b00110101,    {11,  15   }},
        {0b00110110,    {9,   13   }},
        {0b00110111,    {9,   15   }},
        {0b00111000,    {13,  11   }},
        {0b00111001,    {13,  9    }},
        {0b00111010,    {15,  11   }},
        {0b00111011,    {15,  9    }},
        {0b00111100,    {13,  13   }},
        {0b00111101,    {13,  15   }},
        {0b00111110,    {15,  13   }},
        {0b00111111,    {15,  15   }},
        {0b01000000,    {5,   -5   }},
        {0b01000001,    {5,   -7   }},
        {0b01000010,    {7,   -5   }},
        {0b01000011,    {7,   -7   }},
        {0b01000100,    {5,   -3   }},
        {0b01000101,    {5,   -1   }},
        {0b01000110,    {7,   -3   }},
        {0b01000111,    {7,   -1   }},
        {0b01001000,    {3,   -5   }},
        {0b01001001,    {3,   -7   }},
        {0b01001010,    {1,   -5   }},
        {0b01001011,    {1,   -7   }},
        {0b01001100,    {3,   -3   }},
        {0b01001101,    {3,   -1   }},
        {0b01001110,    {1,   -3   }},
        {0b01001111,    {1,   -1   }},
        {0b01010000,    {5,   -11  }},
        {0b01010001,    {5,   -9   }},
        {0b01010010,    {7,   -11  }},
        {0b01010011,    {7,   -9   }},
        {0b01010100,    {5,   -13  }},
        {0b01010101,    {5,   -15  }},
        {0b01010110,    {7,   -13  }},
        {0b01010111,    {7,   -15  }},
        {0b01011000,    {3,   -11  }},
        {0b01011001,    {3,   -9   }},
        {0b01011010,    {1,   -11  }},
        {0b01011011,    {1,   -9   }},
        {0b01011100,    {3,   -13  }},
        {0b01011101,    {3,   -15  }},
        {0b01011110,    {1,   -13  }},
        {0b01011111,    {1,   -15  }},
        {0b01100000,    {11,  -5   }},
        {0b01100001,    {11,  -7   }},
        {0b01100010,    {9,   -5   }},
        {0b01100011,    {9,   -7   }},
        {0b01100100,    {11,  -3   }},
        {0b01100101,    {11,  -1   }},
        {0b01100110,    {9,   -3   }},
        {0b01100111,    {9,   -1   }},
        {0b01101000,    {13,  -5   }},
        {0b01101001,    {13,  -7   }},
        {0b01101010,    {15,  -5   }},
        {0b01101011,    {15,  -7   }},
        {0b01101100,    {13,  -3   }},
        {0b01101101,    {13,  -1   }},
        {0b01101110,    {15,  -3   }},
        {0b01101111,    {15,  -1   }},
        {0b01110000,    {11,  -11  }},
        {0b01110001,    {11,  -9   }},
        {0b01110010,    {9,   -11  }},
        {0b01110011,    {9,   -9   }},
        {0b01110100,    {11,  -13  }},
        {0b01110101,    {11,  -15  }},
        {0b01110110,    {9,   -13  }},
        {0b01110111,    {9,   -15  }},
        {0b01111000,    {13,  -11  }},
        {0b01111001,    {13,  -9   }},
        {0b01111010,    {15,  -11  }},
        {0b01111011,    {15,  -9   }},
        {0b01111100,    {13,  -13  }},
        {0b01111101,    {13,  -15  }},
        {0b01111110,    {15,  -13  }},
        {0b01111111,    {15,  -15  }},
        {0b10000000,    {-5,  5    }},
        {0b10000001,    {-5,  7    }},
        {0b10000010,    {-7,  5    }},
        {0b10000011,    {-7,  7    }},
        {0b10000100,    {-5,  3    }},
        {0b10000101,    {-5,  1    }},
        {0b10000110,    {-7,  3    }},
        {0b10000111,    {-7,  1    }},
        {0b10001000,    {-3,  5    }},
        {0b10001001,    {-3,  7    }},
        {0b10001010,    {-1,  5    }},
        {0b10001011,    {-1,  7    }},
        {0b10001100,    {-3,  3    }},
        {0b10001101,    {-3,  1    }},
        {0b10001110,    {-1,  3    }},
        {0b10001111,    {-1,  1    }},
        {0b10010000,    {-5,  11   }},
        {0b10010001,    {-5,  9    }},
        {0b10010010,    {-7,  11   }},
        {0b10010011,    {-7,  9    }},
        {0b10010100,    {-5,  13   }},
        {0b10010101,    {-5,  15   }},
        {0b10010110,    {-7,  13   }},
        {0b10010111,    {-7,  15   }},
        {0b10011000,    {-3,  11   }},
        {0b10011001,    {-3,  9    }},
        {0b10011010,    {-1,  11   }},
        {0b10011011,    {-1,  9    }},
        {0b10011100,    {-3,  13   }},
        {0b10011101,    {-3,  15   }},
        {0b10011110,    {-1,  13   }},
        {0b10011111,    {-1,  15   }},
        {0b10100000,    {-11, 5    }},
        {0b10100001,    {-11, 7    }},
        {0b10100010,    {-9,  5    }},
        {0b10100011,    {-9,  7    }},
        {0b10100100,    {-11, 3    }},
        {0b10100101,    {-11, 1    }},
        {0b10100110,    {-9,  3    }},
        {0b10100111,    {-9,  1    }},
        {0b10101000,    {-13, 5    }},
        {0b10101001,    {-13, 7    }},
        {0b10101010,    {-15, 5    }},
        {0b10101011,    {-15, 7    }},
        {0b10101100,    {-13, 3    }},
        {0b10101101,    {-13, 1    }},
        {0b10101110,    {-15, 3    }},
        {0b10101111,    {-15, 1    }},
        {0b10110000,    {-11, 11   }},
        {0b10110001,    {-11, 9    }},
        {0b10110010,    {-9,  11   }},
        {0b10110011,    {-9,  9    }},
        {0b10110100,    {-11, 13   }},
        {0b10110101,    {-11, 15   }},
        {0b10110110,    {-9,  13   }},
        {0b10110111,    {-9,  15   }},
        {0b10111000,    {-13, 11   }},
        {0b10111001,    {-13, 9    }},
        {0b10111010,    {-15, 11   }},
        {0b10111011,    {-15, 9    }},
        {0b10111100,    {-13, 13   }},
        {0b10111101,    {-13, 15   }},
        {0b10111110,    {-15, 13   }},
        {0b10111111,    {-15, 15   }},
        {0b11000000,    {-5,  -5   }},
        {0b11000001,    {-5,  -7   }},
        {0b11000010,    {-7,  -5   }},
        {0b11000011,    {-7,  -7   }},
        {0b11000100,    {-5,  -3   }},
        {0b11000101,    {-5,  -1   }},
        {0b11000110,    {-7,  -3   }},
        {0b11000111,    {-7,  -1   }},
        {0b11001000,    {-3,  -5   }},
        {0b11001001,    {-3,  -7   }},
        {0b11001010,    {-1,  -5   }},
        {0b11001011,    {-1,  -7   }},
        {0b11001100,    {-3,  -3   }},
        {0b11001101,    {-3,  -1   }},
        {0b11001110,    {-1,  -3   }},
        {0b11001111,    {-1,  -1   }},
        {0b11010000,    {-5,  -11  }},
        {0b11010001,    {-5,  -9   }},
        {0b11010010,    {-7,  -11  }},
        {0b11010011,    {-7,  -9   }},
        {0b11010100,    {-5,  -13  }},
        {0b11010101,    {-5,  -15  }},
        {0b11010110,    {-7,  -13  }},
        {0b11010111,    {-7,  -15  }},
        {0b11011000,    {-3,  -11  }},
        {0b11011001,    {-3,  -9   }},
        {0b11011010,    {-1,  -11  }},
        {0b11011011,    {-1,  -9   }},
        {0b11011100,    {-3,  -13  }},
        {0b11011101,    {-3,  -15  }},
        {0b11011110,    {-1,  -13  }},
        {0b11011111,    {-1,  -15  }},
        {0b11100000,    {-11, -5   }},
        {0b11100001,    {-11, -7   }},
        {0b11100010,    {-9,  -5   }},
        {0b11100011,    {-9,  -7   }},
        {0b11100100,    {-11, -3   }},
        {0b11100101,    {-11, -1   }},
        {0b11100110,    {-9,  -3   }},
        {0b11100111,    {-9,  -1   }},
        {0b11101000,    {-13, -5   }},
        {0b11101001,    {-13, -7   }},
        {0b11101010,    {-15, -5   }},
        {0b11101011,    {-15, -7   }},
        {0b11101100,    {-13, -3   }},
        {0b11101101,    {-13, -1   }},
        {0b11101110,    {-15, -3   }},
        {0b11101111,    {-15, -1   }},
        {0b11110000,    {-11, -11  }},
        {0b11110001,    {-11, -9   }},
        {0b11110010,    {-9,  -11  }},
        {0b11110011,    {-9,  -9   }},
        {0b11110100,    {-11, -13  }},
        {0b11110101,    {-11, -15  }},
        {0b11110110,    {-9,  -13  }},
        {0b11110111,    {-9,  -15  }},
        {0b11111000,    {-13, -11  }},
        {0b11111001,    {-13, -9   }},
        {0b11111010,    {-15, -11  }},
        {0b11111011,    {-15, -9   }},
        {0b11111100,    {-13, -13  }},
        {0b11111101,    {-13, -15  }},
        {0b11111110,    {-15, -13  }},
        {0b11111111,    {-15, -15  }},
}};

#endif /* _LTE_TABLES_36211_H_ */

