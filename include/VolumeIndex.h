/*
 * VolumeIndex.h
 *
 *  Created on: 5 Jun 2013
 *      Author: pw00001
 */

#ifndef VOLUMEINDEX_H_
#define VOLUMEINDEX_H_

#include <array>

class VolumeIndex
{
public:
    VolumeIndex(size_t x, size_t y, size_t z)
    :   m_index{{x,y,z}}
    {}

    size_t &operator [] (size_t i)
    {
        return m_index[i];
    }
    const size_t &operator [] (size_t i) const
    {
        return m_index[i];
    }
private:
    std::array<size_t, 3> m_index;
};

#endif /* VOLUMEINDEX_H_ */
