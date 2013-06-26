/*
 * VolumeSize.h
 *
 *  Created on: 5 Jun 2013
 *      Author: pw00001
 */

#ifndef VOLUMESIZE_H_
#define VOLUMESIZE_H_

#include <array>

class VolumeSize
{
    static const size_t DIMESNSION = 3;
public:
    VolumeSize(size_t x, size_t y, size_t z)
    : m_size{{x,y,z}}
    {}

    size_t &operator [] (size_t i)
    {
        return m_size[i];
    }
    const size_t &operator [] (size_t i) const
    {
        return m_size[i];
    }

    friend bool operator == (const VolumeSize &a, const VolumeSize &b)
    {
        return a.m_size == b.m_size;
    }

    friend bool operator != (const VolumeSize &a, const VolumeSize &b)
    {
        return a.m_size != b.m_size;
    }

    size_t rawSize() const
    {
        size_t rawSize(1);
        for(const size_t size : m_size)
        {
            rawSize *= size;
        }
        return rawSize;
    }

private:
    std::array<size_t, DIMESNSION> m_size;
};


#endif /* VOLUMESIZE_H_ */
