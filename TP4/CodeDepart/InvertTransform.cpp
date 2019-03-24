///////////////////////////////////////////////////////////
//  InvertTransform.cpp
//  Implementation of the Class InvertTransform
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#include "InvertTransform.h"
#include "AbsAudioFile.h"
#include "ChunkIterator.h"

// Methode pour appliquer une transformation d'inversion à un Chunk
void InvertTransform::transform(const Chunk_iterator& c, AbsAudioFile& outFile) const
{ 
   // A Completer...
	//declarer un iterateur non constant qui effectue des modifications sur l'iterateur c

	Chunk_iterator d(c);// cration d'un iterateur non constant 

	for (int i = 0; i < outFile.getChunkSize(); i++) { // la taille du vecteur de chunk 
		d->get()[i] = c->get()[outFile.getChunkSize() - i - 1]; // mettre les caracteres a la bonne place
	}

	outFile.addChunk(d);

}
