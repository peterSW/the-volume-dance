/*
 * SizedIndexer.h
 *
 *  Created on: 26 Feb 2015
 *      Author: pw00001
 */

#ifndef SIZEDINDEXER_H_
#define SIZEDINDEXER_H_

#include "IndexOrder.h"
#include "VolumeSize.h"

#include <array>

template <typename IndexOrder>
class SizedIndexer
{
    std::array<size_t, IndexOrder::dim> strides;

    SizedIndexer(IndexOrder indexOrder, VolumeSize volumeSize)
    :
        strides(calculateStrides(indexOrder, volumeSize))
    {}
};



#endif /* SIZEDINDEXER_H_ */
