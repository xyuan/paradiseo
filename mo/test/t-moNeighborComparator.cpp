/*
  <t-moNeighborComparator.cpp>
  Copyright (C) DOLPHIN Project-Team, INRIA Lille - Nord Europe, 2006-2010

  Sébastien Verel, Arnaud Liefooghe, Jérémie Humeau

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

#include <problems/bitString/moBitNeighbor.h>
#include <comparator/moNeighborComparator.h>
#include <ga/eoBit.h>
#include <eoScalarFitness.h>

#include <cstdlib>
#include <cassert>

int main() {

    std::cout << "[t-moNeighborComparator] => START" << std::endl;


    moBitNeighbor<eoMinimizingFitness> neighbor1;
    moBitNeighbor<eoMinimizingFitness> neighbor2;

    moNeighborComparator< moBitNeighbor<eoMinimizingFitness> > test;

    neighbor1.fitness(3);
    neighbor2.fitness(2);
    //test with a minimizing fitness neighbor2 must be better than neighbor1 and reversly
    assert(test(neighbor1, neighbor2));
    assert(!test(neighbor2, neighbor1));

    //test equals
    assert(!test.equals(neighbor1,neighbor2));

    neighbor2.fitness(3);
    assert(test.equals(neighbor1,neighbor2));

    assert(test.className()=="moNeighborComparator");
    std::cout << "[t-moNeighborComparator] => OK" << std::endl;
    return EXIT_SUCCESS;
}
