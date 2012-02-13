/*
    wdb - weather and water data storage

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


#ifndef FELTCONFIGFILE_H_
#define FELTCONFIGFILE_H_

/**
 * @addtogroup common
 * @{
 * @addtogroup configuration
 * @{
 */

/**
 * @file
 * Common class for parsing and decoding of config files for WDB applications
 */

// PROJECT INCLUDES
//

// STD
#include <list>
#include <string>
#include <iosfwd>
#include <tr1/unordered_map>

namespace felt {

    /**
      * FeltConfigFile is an implementation of a very simply config file system
      */
    class FeltConfigFile
    {
    public:
        FeltConfigFile( );
        ~FeltConfigFile();

        std::list<std::string> keys();

        std::string operator []( std::string key ) const;
        void open( std::string fileName );
        std::string get( std::string key ) const;

    private:
        std::string fileName_;
        std::list<std::string> configKeys_;
        std::tr1::unordered_map< std::string, std::string> configTable_;

        void parse( std::string specification );
        std::string extractKey( const std::string & specification );
        std::string extractValue( const std::string & specification );
    };

}	// namespace felt

#endif				/* FELTCONFIGFILE_H_ */
