/*
* Copyright (C) DOLPHIN Project-Team, INRIA Futurs, 2006-2010
*
* Legillon Francois
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
#include <biVRP.h>
#include <utils/eoRNG.h>
class biVRPRBX: public eoBinOp<biVRP>{

	public:
		biVRPRBX(float _proba=0.5, eoRng &_rnd=eo::rng):proba(_proba),rnd(_rnd){}
		bool operator()(biVRP & vrp1, const biVRP &vrp2){
			unsigned int cur=0;
			std::set<int> alreadyIn;
			biVRP res(vrp1);
			for (unsigned int i=0;i<vrp1.upper().size();i++){
				if (vrp1.upper().isVehicleAt(i) && rnd.flip(proba)){
					alreadyIn.insert(vrp1.upper()[i]);
					res.upper()[cur++]=vrp1.upper()[i];
					while (!vrp1.upper().isVehicleAt(i)&& i<vrp1.upper().size()){
						alreadyIn.insert(vrp1.upper()[i]);
						res.upper()[cur++]=vrp1.upper()[i];
					}
				}else{
					i++;
				}
			}
			for (unsigned int i=0;i<vrp2.upper().size()&& cur<vrp1.upper().size();i++){
				if (!alreadyIn.count(vrp2.upper()[i])){
					res.upper()[cur++]=vrp2.upper()[i];
				}

			}
			vrp1=res;
			vrp1.invalidate();
			return true;

		}
	private:
		float proba;
		eoRng &rnd;

};