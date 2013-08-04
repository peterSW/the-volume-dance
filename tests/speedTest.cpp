/*
 * speedTest.cpp
 *
 *  Created on: 4 Aug 2013
 *      Author: pw00001
 */



#include "gtest/gtest.h"

#include "VolumeFactory.h"
#include "IndexOrder.h"
#include "VolumeSize.h"

TEST( ShuffleCopySpeedTest, XYZtoYZX_general )
{
    const VolumeSize size(500,500,500);
    const IndexOrder<3> xyz({{2,1,0}});
    const IndexOrder<3> yzx({{1,0,2}});

    auto volumeXYZ(makeVolume(size, xyz));
    auto volumeYZX(makeVolume(size, yzx));

    volumeXYZ[VolumeIndex(0,0,0)] = 1;
    volumeYZX.shuffleCopy(volumeXYZ);
    EXPECT_EQ(1, volumeYZX[VolumeIndex(0,0,0)]);

}



TEST( ShuffleCopySpeedTest, XYZtoYZX_templated )
{
    const VolumeSize size(500,500,500);
    const IndexOrderXYZ xyz;
    const IndexOrderYZX yzx;

    auto volumeXYZ(makeVolume(size, xyz));
    auto volumeYZX(makeVolume(size, yzx));

    volumeXYZ[VolumeIndex(0,0,0)] = 1;
    volumeYZX.shuffleCopy(volumeXYZ);
    EXPECT_EQ(1, volumeYZX[VolumeIndex(0,0,0)]);

}

