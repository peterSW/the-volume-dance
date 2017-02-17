/*
 * test.cpp
 *
 *  Created on: 8 Jun 2013
 *      Author: pw00001
 */


#include "gtest/gtest.h"

#include "VolumeFactory.h"
#include "IndexOrder.h"
#include "VolumeSize.h"

TEST( SingleVoxelVol, XYZtoYZX )
{
    auto volumeXYZ(makeVolume(VolumeSize(1,1,1), IndexOrderXYZ()));
    auto volumeUniTypeXYZ(makeVolume(VolumeSize(1,1,1), IndexOrder<3>{{2,1,0}}));
    auto volumeYZX(makeVolume(VolumeSize(1,1,1), IndexOrderYZX()));

    ASSERT_EQ(1, volumeXYZ.size().rawSize());
    ASSERT_EQ(1, volumeUniTypeXYZ.size().rawSize());
    ASSERT_EQ(1, volumeYZX.size().rawSize());

    volumeUniTypeXYZ[VolumeIndex(0,0,0)] = 1;
    volumeYZX.shuffleCopy(volumeUniTypeXYZ);
    EXPECT_EQ(1, volumeYZX[VolumeIndex(0,0,0)]);

    volumeXYZ[VolumeIndex(0,0,0)] = 1;
    volumeYZX.shuffleCopy(volumeXYZ);
    EXPECT_EQ(1, volumeXYZ[VolumeIndex(0,0,0)]);
}

TEST( singleColumnVol, XYZtoYZX )
{
    auto volumeXYZ(makeVolume(VolumeSize(1,1,3), IndexOrderXYZ()));
    auto volumeYZX(makeVolume(VolumeSize(1,1,3), IndexOrderYZX()));

    volumeXYZ[VolumeIndex(0,0,0)] = 1;
    volumeXYZ[VolumeIndex(0,0,1)] = 2;
    volumeXYZ[VolumeIndex(0,0,2)] = 3;

    volumeYZX.shuffleCopy(volumeXYZ);

    EXPECT_EQ(1, volumeXYZ[VolumeIndex(0,0,0)]);
    EXPECT_EQ(2, volumeXYZ[VolumeIndex(0,0,1)]);
    EXPECT_EQ(3, volumeXYZ[VolumeIndex(0,0,2)]);
}

TEST( singleColumnVol, XYZtoYZX_GenIndexer )
{
    auto volumeXYZ(makeVolume(VolumeSize(1,1,3), IndexOrder<3>{{2,1,0}}));
    auto volumeYZX(makeVolume(VolumeSize(1,1,3), IndexOrder<3>{{1,0,2}}));

    volumeXYZ[VolumeIndex(0,0,0)] = 1;
    volumeXYZ[VolumeIndex(0,0,1)] = 2;
    volumeXYZ[VolumeIndex(0,0,2)] = 3;

    volumeYZX.shuffleCopy(volumeXYZ);

    EXPECT_EQ(1, volumeXYZ[VolumeIndex(0,0,0)]);
    EXPECT_EQ(2, volumeXYZ[VolumeIndex(0,0,1)]);
    EXPECT_EQ(3, volumeXYZ[VolumeIndex(0,0,2)]);
}

TEST(XYZ, layout)
{
    auto volumeXYZ(makeVolume(VolumeSize(2,2,2), IndexOrderXYZ()));

    volumeXYZ[VolumeIndex(0,0,0)] =   0;
    volumeXYZ[VolumeIndex(0,0,1)] =   1;
    volumeXYZ[VolumeIndex(0,1,0)] =  10;
    volumeXYZ[VolumeIndex(0,1,1)] =  11;
    volumeXYZ[VolumeIndex(1,0,0)] = 100;
    volumeXYZ[VolumeIndex(1,0,1)] = 101;
    volumeXYZ[VolumeIndex(1,1,0)] = 110;
    volumeXYZ[VolumeIndex(1,1,1)] = 111;

    EXPECT_EQ(   0, volumeXYZ.getRawData()[0] );
    EXPECT_EQ(   1, volumeXYZ.getRawData()[1] );
    EXPECT_EQ(  10, volumeXYZ.getRawData()[2] );
    EXPECT_EQ(  11, volumeXYZ.getRawData()[3] );
    EXPECT_EQ( 100, volumeXYZ.getRawData()[4] );
    EXPECT_EQ( 101, volumeXYZ.getRawData()[5] );
    EXPECT_EQ( 110, volumeXYZ.getRawData()[6] );
    EXPECT_EQ( 111, volumeXYZ.getRawData()[7] );

}

TEST(YZX, layout)
{
    auto volumeYZX(makeVolume(VolumeSize(2,2,2), IndexOrderYZX()));

    volumeYZX[VolumeIndex(0,0,0)] =   0;
    volumeYZX[VolumeIndex(1,0,0)] =   1;
    volumeYZX[VolumeIndex(0,0,1)] =  10;
    volumeYZX[VolumeIndex(1,0,1)] =  11;
    volumeYZX[VolumeIndex(0,1,0)] = 100;
    volumeYZX[VolumeIndex(1,1,0)] = 101;
    volumeYZX[VolumeIndex(0,1,1)] = 110;
    volumeYZX[VolumeIndex(1,1,1)] = 111;

    EXPECT_EQ(   0, volumeYZX.getRawData()[0] );
    EXPECT_EQ(   1, volumeYZX.getRawData()[1] );
    EXPECT_EQ(  10, volumeYZX.getRawData()[2] );
    EXPECT_EQ(  11, volumeYZX.getRawData()[3] );
    EXPECT_EQ( 100, volumeYZX.getRawData()[4] );
    EXPECT_EQ( 101, volumeYZX.getRawData()[5] );
    EXPECT_EQ( 110, volumeYZX.getRawData()[6] );
    EXPECT_EQ( 111, volumeYZX.getRawData()[7] );

}
