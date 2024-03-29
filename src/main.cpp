/*
 wdb

 Copyright (C) 2007-2009 met.no

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

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

//
#include "FeltFile.h"
#include "FeltLoader.h"
#include "FeltLoadConfiguration.h"

// FIMEX
#include <fimex/CDM.h>
#include <fimex/CDMFileReaderFactory.h>

// WDB
//
#include <wdbLogHandler.h>
#include <wdb/LoaderConfiguration.h>
#include <wdb/LoaderDatabaseConnection.h>

// BOOST
//
#include <boost/filesystem/path.hpp>

// STD
//
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using namespace wdb::load;

// Support Functions
namespace
{

    /**
      * Write the program version to stream
      * @param	out		Stream to write to
      */
    void version( ostream & out )
    {
        out << PACKAGE_STRING << endl;
    }

    /**
      * Write help information to stram
      * @param	options		Description of the program options
      * @param	out			Stream to write to
      */
    void help( const boost::program_options::options_description & options, ostream & out )
    {
	version( out );
	out << '\n';
        out << "Usage: "PACKAGE_NAME" [OPTIONS] FILES...\n\n";
        out << "Options:\n";
        out << options << endl;
    }
} // namespace

int main(int argc, char ** argv)
{
    boost::shared_ptr<MetNoFimex::CDMReader> reader =
            MetNoFimex::CDMFileReaderFactory::create(MIFI_FILETYPE_FELT, "flth00.dat", "felt2nc_variables.xml");

//    FeltLoadConfiguration conf;
//    try {
//        conf.parse( argc, argv );

//        if(conf.general().help) {
//            help( conf.shownOptions(), cout );
//            return 0;
//    	}

//        if(conf.general().version) {
//            version( cout );
//            return 0;
//    	}
//    } catch(exception& e) {
//        cerr << e.what() << endl;
//        help(conf.shownOptions(), clog);
//        return 1;
//    }

//    wdb::WdbLogHandler logHandler(conf.logging().loglevel, conf.logging().logfile);
//    WDB_LOG & log = WDB_LOG::getInstance( "wdb.feltload.main" );
//    log.debug( "Starting feltLoad" );

//    // Get list of files
//    const vector<string> & file = conf.input().file;
//    vector<boost::filesystem::path> files;
//    copy(file.begin(), file.end(), back_inserter(files));

//    try {
//        if(conf.output().list) {
//            // List contents of files
//            for (vector<boost::filesystem::path>::const_iterator it = files.begin(); it != files.end(); ++ it)
//            {
//                cout << it->native_file_string() << endl;
//                felt::FeltFile f(*it);
//                cout << "Size:\t" << f.size() << endl;
//                for ( felt::FeltFile::const_iterator fit = f.begin(); fit != f.end(); ++ fit )
//                {
//                    try {
//                        cout << (*fit)->information() << endl;
//                    } catch( std::exception & e ) {
//                        cout << "ERROR: Unable to read file " << it->native_file_string() << "\n" << endl;
//                    }
//                }
//            }
//        } else {
//            // Write Files into Database
//            std::cerr<<__FILE__<<"|"<<__FUNCTION__<<"|"<<__LINE__<<": CHECK"<<std::endl;
//            wdb::load::LoaderDatabaseConnection dbConnection(conf);
//            std::cerr<<__FILE__<<"|"<<__FUNCTION__<<"|"<<__LINE__<<": CHECK"<<std::endl;
//            felt::FeltLoader loader(dbConnection, conf, logHandler);
//            std::cerr<<__FILE__<<"|"<<__FUNCTION__<<"|"<<__LINE__<<": CHECK"<<std::endl;
//            for(vector<boost::filesystem::path>::const_iterator it = files.begin(); it != files.end(); ++ it)
//            {
//                try {
//                    std::cerr<<__FILE__<<"|"<<__FUNCTION__<<"|"<<__LINE__<<": CHECK"<<std::endl;
//                    felt::FeltFile feltFile(* it);
//                    std::cerr<<__FILE__<<"|"<<__FUNCTION__<<"|"<<__LINE__<<": LOADING : "<< feltFile.fileName() <<std::endl;
//                    loader.load(feltFile);
//                    std::cerr<<__FILE__<<"|"<<__FUNCTION__<<"|"<<__LINE__<<": CHECK"<<std::endl;
//                } catch (exception& e) {
//                    log.errorStream() << "Unable to load file " << it->native_file_string();
//                    log.errorStream() << "Reason: " << e.what();
//                }
//            }
//        }
//    } catch(std::exception& e) {
//        log.fatalStream() << e.what();
//        return 1;
//    }
}
