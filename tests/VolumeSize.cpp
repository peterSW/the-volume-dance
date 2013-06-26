/*
 * VolumeSize.cpp
 *
 *  Created on: 11 Jun 2013
 *      Author: pw00001
 */

#include "gtest/gtest.h"
#include "VolumeSize.h"

TEST( VolumeSize, sizeToRaw )
{
    VolumeSize vs3by3by3(3,3,3);
    EXPECT_EQ(3*3*3, vs3by3by3.rawSize());
}

TEST( VolumeSize, sizeEquality )
{
    VolumeSize vs3by3by3(3,3,3);
    VolumeSize another3by3by3(3,3,3);
    VolumeSize vs3by1by3(3,1,3);

    EXPECT_TRUE( vs3by3by3 == another3by3by3);
    EXPECT_FALSE( vs3by3by3 == vs3by1by3);

    EXPECT_FALSE( vs3by3by3 != another3by3by3);
    EXPECT_TRUE( vs3by3by3 != vs3by1by3);


}

