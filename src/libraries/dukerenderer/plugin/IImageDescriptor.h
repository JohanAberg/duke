/*
 * IImageDescriptor.h
 *
 *  Created on: 17 juin 2010
 *      Author: Guillaume Chatelet
 */

#ifndef IIMAGEDESCRIPTOR_H_
#define IIMAGEDESCRIPTOR_H_

struct ImageDescription;

class IImageDescriptor
{
public:
	virtual const ImageDescription& getImageDescription() const = 0;
};

#endif // IIMAGEDESCRIPTOR_H_
