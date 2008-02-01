/*
* <moeoArchiveUpdater.h>
* Copyright (C) DOLPHIN Project-Team, INRIA Futurs, 2006-2007
* (C) OPAC Team, LIFL, 2002-2007
*
* Arnaud Liefooghe
*
* This software is governed by the CeCILL license under French law and
* abiding by the rules of distribution of free software.  You can  use,
* modify and/ or redistribute the software under the terms of the CeCILL
* license as circulated by CEA, CNRS and INRIA at the following URL
* "http://www.cecill.info".
*
* As a counterpart to the access to the source code and  rights to copy,
* modify and redistribute granted by the license, users are provided only
* with a limited warranty  and the software's author,  the holder of the
* economic rights,  and the successive licensors  have only  limited liability.
*
* In this respect, the user's attention is drawn to the risks associated
* with loading,  using,  modifying and/or developing or reproducing the
* software by the user in light of its specific status of free software,
* that may mean  that it is complicated to manipulate,  and  that  also
* therefore means  that it is reserved for developers  and  experienced
* professionals having in-depth computer knowledge. Users are therefore
* encouraged to load and test the software's suitability as regards their
* requirements in conditions enabling the security of their systems and/or
* data to be ensured and,  more generally, to use and operate it in the
* same conditions as regards security.
* The fact that you are presently reading this means that you have had
* knowledge of the CeCILL license and that you accept its terms.
*
* ParadisEO WebSite : http://paradiseo.gforge.inria.fr
* Contact: paradiseo-help@lists.gforge.inria.fr
*
*/
//-----------------------------------------------------------------------------

#ifndef MOEOARCHIVEUPDATER_H_
#define MOEOARCHIVEUPDATER_H_

#include <eoPop.h>
#include <utils/eoUpdater.h>
#include <archive/moeoArchive.h>

/**
 * This class allows to update the archive at each generation with newly found non-dominated solutions.
 */
template < class MOEOT >
class moeoArchiveUpdater : public eoUpdater
  {
  public:

    /**
     * Ctor
     * @param _arch an archive of non-dominated solutions
     * @param _pop the main population
     */
    moeoArchiveUpdater(moeoArchive < MOEOT > & _arch, const eoPop < MOEOT > & _pop) : arch(_arch), pop(_pop)
    {}


    /**
     * Updates the archive with newly found non-dominated solutions contained in the main population
     */
    void operator()()
    {
      arch.update(pop);
    }


  private:

    /** the archive of non-dominated solutions */
    moeoArchive < MOEOT > & arch;
    /** the main population */
    const eoPop < MOEOT > & pop;

  };

#endif /*MOEOARCHIVEUPDATER_H_*/
