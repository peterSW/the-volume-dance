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

template <int Dim>
struct StridesFactory;

template <>
struct StridesFactory<2>
{

    template <typename SizeType>
    static inline std::array<size_t, 2> makeStrides(std::array<size_t, 2> order, SizeType size)
    {
        IndexOrder<2> helper(order);
        return std::array<size_t, 2>{
                helper.toRaw(size, {1, 0}),
                helper.toRaw(size, {0, 1})};
    }

};

template <>
struct StridesFactory<3>
{

    template <typename SizeType>
    static inline std::array<size_t, 3> makeStrides(std::array<size_t, 3> order, SizeType size)
    {
        IndexOrder<3> helper(order);
        return std::array<size_t, 3>{
                helper.toRaw(size, {1, 0, 0}),
                helper.toRaw(size, {0, 1, 0}),
                helper.toRaw(size, {0, 0, 1})};
    }

};


template <size_t Dim>
class SizedIndexOrder
{
public:
    SizedIndexOrder(std::array<size_t, Dim> order, std::array<size_t, Dim> size)
    :
        m_strides(StridesFactory<Dim>::makeStrides(order, size))
    {}
    SizedIndexOrder(std::array<size_t, Dim> order, VolumeSize size)
    :
        m_strides(StridesFactory<Dim>::makeStrides(order, size))
    {}

    template <typename DummySize, typename VolumeIndexType>
    size_t toRaw(
            const DummySize &,
            const VolumeIndexType &index) const
    {
        size_t result(0);
        for(std::size_t i(0); i < m_strides.size(); ++i)
        {
            result += m_strides[i] * index[i];
        }

        return result;
    }

private:



    std::array<size_t, Dim> m_strides;
};



#endif /* INDEXORDER_H_ */
