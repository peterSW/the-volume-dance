/*
 * VolumeFactory.h
 *
 *  Created on: 5 Jun 2013
 *      Author: pw00001
 */

#ifndef VOLUMEFACTORY_H_
#define VOLUMEFACTORY_H_

#include "IndexOrder.h"
#include "VolumeSize.h"
#include "VolumeIndex.h"

#include <vector>

template <typename IndexOrder>
class Volume
{
public:
    typedef std::vector<int> RawDataType;

    Volume(const VolumeSize &size, const IndexOrder &indexer)
        :
        m_indexer(indexer),
        m_size(size),
        m_data(size.rawSize())
    {}

    const int &operator [] (const VolumeIndex &index) const
    {
        return m_data[m_indexer.toRaw(m_size, index)];
    }

    int &operator [] (const VolumeIndex &index)
    {
        return m_data[m_indexer.toRaw(m_size, index)];
    }

    template <typename SrcIndexOrder>
    void shuffleCopy(const Volume<SrcIndexOrder> &src)
    {
        const size_t rawSrcSize(src.size().rawSize());
        if(rawSrcSize != m_data.size())
        {
            m_data.resize(rawSrcSize);
            m_size = src.size();
        }
        operator [](VolumeIndex(0,0,0)) = src[VolumeIndex(0,0,0)];
    }

    const RawDataType &getRawData() const
    {
        return m_data;
    }

    VolumeSize size() const
    {
        return m_size;
    }

private:
    IndexOrder m_indexer;
    VolumeSize m_size;
    RawDataType m_data;
};

template<typename IndexOrder>
Volume<IndexOrder> makeVolume(const VolumeSize &size, const IndexOrder &indexer)
{
    return Volume<IndexOrder>(size, indexer);
}


#endif /* VOLUMEFACTORY_H_ */
