/*
 * ImageHolder.h
 *
 *  Created on: 5 mai 2010
 *      Author: Guillaume Chatelet
 */

#ifndef IMAGEHOLDER_H_
#define IMAGEHOLDER_H_

#include <dukeengine/memory/alloc/MemoryBlock.h>
#include <dukeio/ImageDescription.h>

class ImageHolder
{
private:
	ImageDescription m_ImageDescription;
	MemoryBlockPtr m_pImageData;

public:
	ImageHolder();
	~ImageHolder();

	void setImageData(const ImageDescription &description, const MemoryBlockPtr pMemory );

	inline const ImageDescription& getImageDescription() const {
		return m_ImageDescription;
	}

	inline const MemoryBlockPtr& getImageData() const {
		return m_pImageData;
	}

	template<typename T>
	const T* getPtr() const;
	size_t getImageDataSize() const;
};

template<typename T>
const T* ImageHolder::getPtr() const
{
	return reinterpret_cast<const T*>( m_ImageDescription.pImageData );
}

#endif /* IMAGEHOLDER_H_ */
