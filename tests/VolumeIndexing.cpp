/*
 * VolumeIndex.cpp
 *
 *  Created on: 8 Jun 2013
 *      Author: pw00001
 */
#include "gtest/gtest.h"

#include "IndexOrder.h"
#include "VolumeIndex.h"

TEST( IndexOrder, VolumeToRawXYZ)
{
    EXPECT_EQ(0, IndexOrderXYZ::toRaw(
            VolumeSize(3,3,3),
            VolumeIndex(0,0,0)));

    EXPECT_EQ(2, IndexOrderXYZ::toRaw(
            VolumeSize(3,3,3),
            VolumeIndex(0,0,2)));

    EXPECT_EQ(3, IndexOrderXYZ::toRaw(
                VolumeSize(3,3,3),
                VolumeIndex(0,1,0)));

    EXPECT_EQ(3*3, IndexOrderXYZ::toRaw(
                    VolumeSize(3,3,3),
                    VolumeIndex(1,0,0)));

    EXPECT_EQ(3*3+3+1, IndexOrderXYZ::toRaw(
                        VolumeSize(3,3,3),
                        VolumeIndex(1,1,1)));
}

TEST( IndexOrder, VolumeToRawYZX)
{
    EXPECT_EQ(0, IndexOrderYZX::toRaw(
            VolumeSize(3,3,3),
            VolumeIndex(0,0,0)));

    EXPECT_EQ(3*2, IndexOrderYZX::toRaw(
            VolumeSize(3,3,3),
            VolumeIndex(0,0,2)));

    EXPECT_EQ(3*3*1, IndexOrderYZX::toRaw(
                VolumeSize(3,3,3),
                VolumeIndex(0,1,0)));

    EXPECT_EQ(1, IndexOrderYZX::toRaw(
                    VolumeSize(3,3,3),
                    VolumeIndex(1,0,0)));

    EXPECT_EQ(3*3+3+1, IndexOrderYZX::toRaw(
                        VolumeSize(3,3,3),
                        VolumeIndex(1,1,1)));
}

TEST( GeneralIndexOrder, SingleDim )
{
    std::array<size_t, 1> order;
    order[0] = 0;
    IndexOrder<1> xIndexOrder(order);
    std::array<size_t, 1> size;
    size[0] = 10;
    std::array<size_t, 1> index;
    index[0] = 3;
    EXPECT_EQ(3, xIndexOrder.toRaw(size,index));
}

TEST( GeneralIndexOrder, Dim2 )
{
    std::array<size_t, 2> order;
    order[0] = 0;
    order[1] = 1;
    IndexOrder<2> xIndexOrder(order);
    std::array<size_t, 2> size;
    size[0] = 10;
    size[1] = 5;
    std::array<size_t, 2> index;
    index[0] = 3;
    index[1] = 7;
    EXPECT_EQ(7+3*5, xIndexOrder.toRaw(size,index));
}

TEST( SizedIndexOrder, Dim2)
{
    std::array<size_t, 2> order;
    order[0] = 0;
    order[1] = 1;
    std::array<size_t, 2> size;
    size[0] = 10;
    size[1] = 5;
    SizedIndexOrder<2> indexOrder(order, size);
    std::array<size_t, 2> index;
    index[0] = 3;
    index[1] = 7;
    EXPECT_EQ(7+3*5, indexOrder.toRaw(size,index));
}
