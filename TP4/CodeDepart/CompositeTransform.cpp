///////////////////////////////////////////////////////////
//  CompositeTransform.cpp
//  Implementation of the Class CompositeTransform
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#include "CompositeTransform.h"
#include "AbsAudioFile.h"
#include "ChunkIterator.h"

CompositeTransform::CompositeTransform(const CompositeTransform & mdd)
{
	m_transforms.clear();

	if (this != &mdd) {

		TransformIterator_const i(mdd.begin());

		//parcourir le conteneur mdd
		while (i != mdd.end()) {

			//cloner chaque element normal de mdd
			m_transforms.push_back(TransformPtr(i->clone()));
			i++;
		}

	}
}

// Cloner la transformation composite et ses commandes enfant
CompositeTransform * CompositeTransform::clone(void) const
{
    // A Completer...
	return new CompositeTransform(*this);
}

// Executer les transformations enfant
void CompositeTransform::transform(const Chunk_iterator& c, AbsAudioFile& outFile) const
{
	// A Completer...
	//acceder a la classe transformation 

	const TransformContainer::const_iterator it = m_transforms.begin();
	TransformIterator_const transform_iterateur(it);
	for (int i = 0; i < m_transforms.size(); i++) {

		transform_iterateur->transform(c, outFile);//appel de la transformation approprie par le polymorphisme
		transform_iterateur++; //iteration 
	}

}

void CompositeTransform::addChild(const AbsTransform& t)
{ 
	// A Completer...
	m_transforms.push_back(TransformPtr(t.clone()));//reserver l'espace
}

void CompositeTransform::removeChild(TransformIterator_const transfIt)
{
	// A Completer...
	m_transforms.erase(transfIt);
}
