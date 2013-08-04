/*
 * IndexOrder.h
 *
 *  Created on: 5 Jun 2013
 *      Author: pw00001
 */

#ifndef INDEXORDER_H_
#define INDEXORDER_H_

#include "VolumeIndex.h"
#include "VolumeSize.h"

class IndexOrderXYZ
{
public:
    static size_t toRaw(
            const VolumeSize &volSize,
            const VolumeIndex &index)
    {
        return   index[2] +
               volSize[2] *   index[1] +
               volSize[2] * volSize[1] * index[0];
    }
};

class IndexOrderYZX
{
public:
    static size_t toRaw(
                const VolumeSize &volSize,
                const VolumeIndex &index)
    {
        return   index[0] +
               volSize[2] *   index[2] +
               volSize[2] * volSize[1] * index[1];
    }
};

template<size_t Dim>
class IndexOrder
{
public:
    IndexOrder(std::array<size_t, Dim> order)
    : m_order(order)
    {}

    size_t toRaw(
        const std::array<size_t, Dim> &size,
        const std::array<size_t, Dim> &index) const
    {
        return toRawPT(size, index);
    }

    size_t toRaw(
        const VolumeSize &size,
        const VolumeIndex &index) const
    {
        return toRawPT(size, index);
    }

private:
    template<typename SizeT, typename IndexType>
    size_t toRawPT(const SizeT &size, const IndexType &index) const
    {
        size_t d(Dim-1);
        size_t result(index[m_order[d]]);
        size_t dimStride(1);
        while(d > 0)
        {
            dimStride *= size[m_order[d]];
            --d;
            result += index[m_order[d]] * dimStride;
        }
        return result;
    }

    std::array<size_t, Dim> m_order;
};

#endif /* INDEXORDER_H_ */
