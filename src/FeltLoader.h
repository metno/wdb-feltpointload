/*
 wdb

 Copyright (C) 2012 met.no

 Contact information:
 Norwegian Meteorological Institute
 Box 43 Blindern
 0313 OSLO
 NORWAY
 E-mail: wdb@met.no

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 MA  02110-1301, USA
*/

#ifndef FELTLOADER_H_
#define FELTLOADER_H_

// PROJECT
//
#include "feltConstants.h"
#include "FeltConfigFile.h"
#include "FeltLoadConfiguration.h"

// WDB
//
#include <wdbLogHandler.h>
#include <wdb/WdbLevel.h>
#include <WdbConfigFile.h>
#include <wdb/LoaderConfiguration.h>
#include <wdb/LoaderDatabaseConnection.h>

// FIMEX
//
#include <fimex/CDMInterpolator.h>

// BOOST
//
#include <boost/date_time/posix_time/posix_time_types.hpp>

// STD
//
#include <vector>
#include <tr1/unordered_map>

namespace MetNoFimex {
    class CDMReader;
}

namespace felt {
    class FeltFile;
    class FeltField;

    class FeltLoader
    {
    public:
        FeltLoader(wdb::load::LoaderDatabaseConnection& connection,
//                   const wdb::load::LoaderConfiguration::LoadingOptions& loadingOptions,
                   const FeltLoadConfiguration& feltConfiguration,
                   wdb::WdbLogHandler & logHandler);
	~FeltLoader();

	void load(const FeltFile & feltFile);

    private:

        void load(const felt::FeltField & field, const std::string& placename, boost::shared_ptr<MetNoFimex::CDMInterpolator>& interpolator);

//        void getValues(std::vector<float> & out, const FeltField & field);
        void getValuesForLevel(const felt::FeltField& field,boost::shared_ptr<MetNoFimex::CDMInterpolator>& pReader, std::string& varName, std::string& varUnit, size_t level, std::vector<float> & out);
	std::string dataProviderName( const FeltField & field );
//	std::string placeName( const FeltField & field );
	boost::posix_time::ptime referenceTime(const FeltField & field);
	boost::posix_time::ptime validTimeFrom(const FeltField & field);
	boost::posix_time::ptime validTimeTo(const FeltField & field);
	std::string valueParameterName( const FeltField & field );
	std::string valueParameterUnit( const FeltField & field );
	void levelValues( std::vector<wdb::load::Level> & levels, const FeltField & field );
	int dataVersion(const FeltField & field);
	int confidenceCode(const FeltField & field);
//        void gridToLeftLowerHorizontal( std::vector<float> & out, const FeltField & field );

    private:
	/// The Database Connection
	wdb::load::LoaderDatabaseConnection & connection_;
	/// The feltLoad Configuration
//        const wdb::load::LoaderConfiguration::LoadingOptions & loadingOptions_;
        const FeltLoadConfiguration& feltConfiguration_;

	/// The feltLoad Logger
	wdb::WdbLogHandler & logHandler_;

	/// Conversion Hash Map - Dataprovider Name
        FeltConfigFile felt2DataProviderName_;
	/// Conversion Hash Map - Value Parameter
        FeltConfigFile felt2ValidTime_;
	/// Conversion Hash Map - Value Parameter
        FeltConfigFile felt2ValueParameter_;
	/// Conversion Hash Map - Level Parameter
        FeltConfigFile felt2LevelParameter_;
	/// Conversion Hash Map - Level Additions
        FeltConfigFile felt2LevelAdditions_;

        /// Conversion Hash Map - ID -> (lon lat)
        FeltConfigFile felt2StationAdditions_;

        /// fimex - CDMReader to be used in interpolation
        boost::shared_ptr<MetNoFimex::CDMReader> cdmReader_;
    };

}

#endif /*FELTLOADER_H_*/
