/*
 *  RSGISClumpPxls.h
 *  RSGIS_LIB
 *
 *  Created by Pete Bunting on 18/01/2012.
 *  Copyright 2012 RSGISLib.
 * 
 *  RSGISLib is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  RSGISLib is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with RSGISLib.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef RSGISClumpPxls_h
#define RSGISClumpPxls_h

#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

#include "gdal_priv.h"

#include "img/RSGISImageUtils.h"
#include "img/RSGISImageCalcException.h"

#include "img/RSGISCalcImageValue.h"
#include "img/RSGISCalcImage.h"

namespace rsgis{namespace segment{

    class RSGISClumpPxls
    {
    public:
        RSGISClumpPxls();
        void performClump(GDALDataset *catagories, GDALDataset *clumps, bool noDataValProvided, unsigned int noDataVal) throw(rsgis::img::RSGISImageCalcException);
        void performMultiBandClump(std::vector<GDALDataset*> *catagories, std::string clumpsOutputPath, std::string outFormat, bool noDataValProvided, unsigned int noDataVal) throw(rsgis::img::RSGISImageCalcException);
        ~RSGISClumpPxls();
    protected:
        inline bool allValueEqual(unsigned int *vals, unsigned int numVals, unsigned int equalVal);
        inline bool allValueEqual(unsigned int *vals1, unsigned int *vals2, unsigned int numVals);
    };
    
    class RSGISRelabelClumps
    {
    public:
        RSGISRelabelClumps();
        void relabelClumps(GDALDataset *catagories, GDALDataset *clumps) throw(rsgis::img::RSGISImageCalcException);
        void relabelClumpsCalcImg(GDALDataset *catagories, GDALDataset *clumps) throw(rsgis::img::RSGISImageCalcException);
        ~RSGISRelabelClumps();
    };
    
    class RSGISCreateRelabelLookupTable : public rsgis::img::RSGISCalcImageValue
	{
	public:
		RSGISCreateRelabelLookupTable(unsigned int *clumpIdxLookUp, unsigned int numVals);
		void calcImageValue(float *bandValues, int numBands, float *output) throw(rsgis::img::RSGISImageCalcException){throw rsgis::img::RSGISImageCalcException("No implemented");};
		void calcImageValue(float *bandValues, int numBands) throw(rsgis::img::RSGISImageCalcException);
		void calcImageValue(float *bandValues, int numBands, geos::geom::Envelope extent) throw(rsgis::img::RSGISImageCalcException){throw rsgis::img::RSGISImageCalcException("No implemented");};
		void calcImageValue(float *bandValues, int numBands, float *output, geos::geom::Envelope extent) throw(rsgis::img::RSGISImageCalcException){throw rsgis::img::RSGISImageCalcException("No implemented");};
		void calcImageValue(float ***dataBlock, int numBands, int winSize, float *output) throw(rsgis::img::RSGISImageCalcException){throw rsgis::img::RSGISImageCalcException("No implemented");};
        void calcImageValue(float ***dataBlock, int numBands, int winSize, float *output, geos::geom::Envelope extent) throw(rsgis::img::RSGISImageCalcException){throw rsgis::img::RSGISImageCalcException("No implemented");};
		bool calcImageValueCondition(float ***dataBlock, int numBands, int winSize, float *output) throw(rsgis::img::RSGISImageCalcException){throw rsgis::img::RSGISImageCalcException("No implemented");};
        ~RSGISCreateRelabelLookupTable();
    protected:
        unsigned int *clumpIdxLookUp;
        unsigned int numVals;
        unsigned int nextVal;
	};
    
    
    class RSGISApplyRelabelLookupTable : public rsgis::img::RSGISCalcImageValue
	{
	public:
		RSGISApplyRelabelLookupTable(unsigned int *clumpIdxLookUp, unsigned int numVals);
		void calcImageValue(float *bandValues, int numBands, float *output) throw(rsgis::img::RSGISImageCalcException);
		void calcImageValue(float *bandValues, int numBands) throw(rsgis::img::RSGISImageCalcException){throw rsgis::img::RSGISImageCalcException("No implemented");};
		void calcImageValue(float *bandValues, int numBands, geos::geom::Envelope extent) throw(rsgis::img::RSGISImageCalcException){throw rsgis::img::RSGISImageCalcException("No implemented");};
		void calcImageValue(float *bandValues, int numBands, float *output, geos::geom::Envelope extent) throw(rsgis::img::RSGISImageCalcException){throw rsgis::img::RSGISImageCalcException("No implemented");};
		void calcImageValue(float ***dataBlock, int numBands, int winSize, float *output) throw(rsgis::img::RSGISImageCalcException){throw rsgis::img::RSGISImageCalcException("No implemented");};
        void calcImageValue(float ***dataBlock, int numBands, int winSize, float *output, geos::geom::Envelope extent) throw(rsgis::img::RSGISImageCalcException){throw rsgis::img::RSGISImageCalcException("No implemented");};
		bool calcImageValueCondition(float ***dataBlock, int numBands, int winSize, float *output) throw(rsgis::img::RSGISImageCalcException){throw rsgis::img::RSGISImageCalcException("No implemented");};
        ~RSGISApplyRelabelLookupTable();
    protected:
        unsigned int *clumpIdxLookUp;
        unsigned int numVals;
	};
    
}}

#endif
