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

static const VolumeSize size{5000,500,500};

TEST( ShuffleCopySpeedTest, XYZtoYZX_general )
{
    const IndexOrder<3> xyz{{2,1,0}};
    const IndexOrder<3> yzx{{1,0,2}};

    auto volumeXYZ(makeVolume(size, xyz));
    auto volumeYZX(makeVolume(size, yzx));

    volumeXYZ[VolumeIndex(0,0,0)] = 1;
    volumeYZX.shuffleCopy(volumeXYZ);
    EXPECT_EQ(1, volumeYZX[VolumeIndex(0,0,0)]);

}



TEST( ShuffleCopySpeedTest, XYZtoYZX_templated )
{

    auto volumeXYZ(makeVolume(size, IndexOrderXYZ()));
    auto volumeYZX(makeVolume(size, IndexOrderYZX()));

    volumeXYZ[VolumeIndex(0,0,0)] = 1;
    volumeYZX.shuffleCopy(volumeXYZ);
    EXPECT_EQ(1, volumeYZX[VolumeIndex(0,0,0)]);

}


TEST(ShuffleCopySpeedTest, XYZtoYZX_sizedIndexer)
{
    const SizedIndexOrder<3> xyz{{2,1,0}, size};
    const SizedIndexOrder<3> yzx{{1,0,2}, size};

    auto volumeXYZ(makeVolume(size, xyz));
    auto volumeYZX(makeVolume(size, yzx));

    volumeXYZ[VolumeIndex(0,0,0)] = 1;
    volumeYZX.shuffleCopy(volumeXYZ);
    EXPECT_EQ(1, volumeYZX[VolumeIndex(0,0,0)]);

}