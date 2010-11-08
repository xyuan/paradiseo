/*
 <moCudaCopy.h>
 Copyright (C) DOLPHIN Project-Team, INRIA Lille - Nord Europe, 2006-2010

 Boufaras Karima, Thé Van Luong

 This software is governed by the CeCILL license under French law and
 abiding by the rules of distribution of free software.  You can  use,
 modify and/ or redistribute the software under the terms of the CeCILL
 license as circulated by CEA, CNRS and INRIA at the following URL
 "http://www.cecill.info".

 As a counterpart to the access to the source code and  rights to copy,
 modify and redistribute granted by the license, users are provided only
 with a limited warranty  and the software's author,  the holder of the
 economic rights,  and the successive licensors  have only  limited liability.

 In this respect, the user's attention is drawn to the risks associated
 with loading,  using,  modifying and/or developing or reproducing the
 software by the user in light of its specific status of free software,
 that may mean  that it is complicated to manipulate,  and  that  also
 therefore means  that it is reserved for developers  and  experienced
 professionals having in-depth computer knowledge. Users are therefore
 encouraged to load and test the software's suitability as regards their
 requirements in conditions enabling the security of their systems and/or
 data to be ensured and,  more generally, to use and operate it in the
 same conditions as regards security.
 The fact that you are presently reading this means that you have had
 knowledge of the CeCILL license and that you accept its terms.

 ParadisEO WebSite : http://paradiseo.gforge.inria.fr
 Contact: paradiseo-help@lists.gforge.inria.fr
 */

#ifndef _moCudaCopy_H_
#define _moCudaCopy_H_

// CUDA includes
#include <cutil.h>

/**
 *  class to copy data  from CPU memory to  GPU global memory and vice versa
 */

template<typename T>
class moCudaCopy {

public:

	/**
	 * Constructor
	 */

	moCudaCopy() {
	}

	/**
	 *Copy data from CPU memory to GPU global memory (default copy)
	 *@param _data the data representation where the data will be copied
	 *@param _dataTocpy the data to copy from CPU memory to GPU memory
	 *@param _dataSize the size of data to copy 
	 */

	void operator()(T* & _data, T * _dataTocpy, unsigned _dataSize) {

		//copy data from CPU memeory to GPU memory
		CUDA_SAFE_CALL(cudaMemcpy(_data, _dataTocpy, _dataSize * sizeof(T),
				cudaMemcpyHostToDevice));
		// Check if data was successfuly copied
		CUT_CHECK_ERROR("Copy of data from CPU to GPU global memory failed");

	}

	/**
	 *Copy data from CPU memory to GPU global memory and vice versa
	 *@param _data the data representation where the data will be copied
	 *@param _dataTocpy the data to copy from CPU memory to GPU memory and vice versa
	 *@param _dataSize the size of data to copy 
	 *@param _HostToDevice the direction of copy(true if copy will be done from CPU memory to GPU memory)
	 */

	void operator()(T* & _data, T * _dataTocpy, unsigned _dataSize,
			bool _HostToDevice) {

		if (_HostToDevice) {

			//copy data from CPU memory to GPU memory
			CUDA_SAFE_CALL(cudaMemcpy(_data, _dataTocpy, _dataSize * sizeof(T),
					cudaMemcpyHostToDevice));
			// Check if data was successfuly copied
			CUT_CHECK_ERROR("Copy of data from CPU to GPU global memory failed");
		} else {
			cudaMemcpy(_data, _dataTocpy, _dataSize * sizeof(T),
					cudaMemcpyDeviceToHost);
			// Check if data was successfuly copied from GPU memory to CPU memory
			CUT_CHECK_ERROR("Copy of data from GPU global memory to CPU failed");

		}
	}

	~moCudaCopy() {
	}

};

#endif