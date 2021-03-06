/*
<t-moFitnessCloudSampling.cpp>
Copyright (C) DOLPHIN Project-Team, INRIA Lille - Nord Europe, 2006-2010

Sébastien Verel, Arnaud Liefooghe, Jérémie Humeau

This software is governed by the CeCILL license under French law and
abiding by the rules of distribution of free software.  You can  ue,
modify and/ or redistribute the software under the terms of the CeCILL
license as circulated by CEA, CNRS and INRIA at the following URL
"http://www.cecill.info".

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

#include <iostream>
#include <cstdlib>
#include <cassert>

#include <sampling/moFitnessCloudSampling.h>
#include <sampling/moRndRndFitnessCloudSampling.h>
#include <sampling/moRndBestFitnessCloudSampling.h>
#include <sampling/moMHRndFitnessCloudSampling.h>
#include <sampling/moMHBestFitnessCloudSampling.h>
#include "moTestClass.h"
#include <eval/oneMaxEval.h>


int main() {

    std::cout << "[t-moFitnessCloudSampling] => START" << std::endl;

    bitNeighborhood nh(4);
    oneMaxEval<bitVector> fullEval;
    evalOneMax eval(4);
    dummyInit2 init(4);

    moFitnessCloudSampling<bitNeighbor> test1(init, nh, fullEval, eval, 3);

    moRndRndFitnessCloudSampling<bitNeighbor> test2(init, nh, fullEval, eval, 3);

    moRndBestFitnessCloudSampling<bitNeighbor> test3(init, nh, fullEval, eval, 3);

    moMHRndFitnessCloudSampling<bitNeighbor> test4(init, nh, fullEval, eval, 3);

    moMHBestFitnessCloudSampling<bitNeighbor> test5(init, nh, fullEval, eval, 3);

    test1();
    test2();
    test3();
    test4();
    test5();

    test1.fileExport("outputTestFitnessCloudSampling");


    std::cout << "[t-moFitnessCloudSampling] => OK" << std::endl;

    return EXIT_SUCCESS;
}

