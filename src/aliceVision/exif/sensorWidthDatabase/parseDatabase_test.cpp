// This file is part of the AliceVision project and is made available under
// the terms of the MPL2 license (see the COPYING.md file).

#include "parseDatabase.hpp"

#include "dependencies/stlplus3/filesystemSimplified/file_system.hpp"

#include <string>


#define BOOST_TEST_MODULE parseDatabase
#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

using namespace aliceVision::exif::sensordb;

static const std::string sDatabase = "sensor_width_camera_database.txt";
BOOST_AUTO_TEST_CASE(InvalidDatabase)
{
  std::vector<Datasheet> vec_database;
  const std::string sfileDatabase = stlplus::create_filespec( std::string(THIS_SOURCE_DIR), "" );

  BOOST_CHECK(! parseDatabase( sfileDatabase, vec_database ) );
  BOOST_CHECK( vec_database.empty() );
}

BOOST_AUTO_TEST_CASE(ValidDatabase)
{
  std::vector<Datasheet> vec_database;
  const std::string sfileDatabase = stlplus::create_filespec( std::string(THIS_SOURCE_DIR), sDatabase );

  BOOST_CHECK( parseDatabase( sfileDatabase, vec_database ) );
  BOOST_CHECK( !vec_database.empty() );

}

BOOST_AUTO_TEST_CASE(ParseDatabaseSD900)
{
  std::vector<Datasheet> vec_database;
  Datasheet datasheet;
  const std::string sfileDatabase = stlplus::create_filespec( std::string(THIS_SOURCE_DIR), sDatabase );
  const std::string sModel = "Canon PowerShot SD900";
  const std::string sBrand = "Canon";

  BOOST_CHECK( parseDatabase( sfileDatabase, vec_database ) );
  BOOST_CHECK( getInfo( sBrand, sModel, vec_database, datasheet ) );
  BOOST_CHECK_EQUAL( "Canon", datasheet._brand );
  BOOST_CHECK_EQUAL( "Canon PowerShot SD900", datasheet._model );
  BOOST_CHECK_EQUAL( 7.11, datasheet._sensorSize );
}

BOOST_AUTO_TEST_CASE(ParseDatabaseA710_IS)
{
  std::vector<Datasheet> vec_database;
  Datasheet datasheet;
  const std::string sfileDatabase = stlplus::create_filespec( std::string(THIS_SOURCE_DIR), sDatabase );
  const std::string sModel = "Canon PowerShot A710 IS";
  const std::string sBrand = "Canon";

  BOOST_CHECK( parseDatabase( sfileDatabase, vec_database ) );
  BOOST_CHECK( getInfo( sBrand, sModel, vec_database, datasheet ) );
  BOOST_CHECK_EQUAL( "Canon", datasheet._brand );
  BOOST_CHECK_EQUAL( "Canon PowerShot A710 IS", datasheet._model );
  BOOST_CHECK_EQUAL( 5.75, datasheet._sensorSize );
}

BOOST_AUTO_TEST_CASE(ParseDatabaseNotExist)
{
  std::vector<Datasheet> vec_database;
  Datasheet datasheet;
  const std::string sfileDatabase = stlplus::create_filespec( std::string(THIS_SOURCE_DIR), sDatabase );
  const std::string sModel = "NotExistModel";
  const std::string sBrand = "NotExistBrand";

  BOOST_CHECK( parseDatabase( sfileDatabase, vec_database ) );
  BOOST_CHECK(! getInfo( sBrand, sModel, vec_database, datasheet ) );
}


BOOST_AUTO_TEST_CASE(ParseDatabaseCanon_EOS_550D)
{
  std::vector<Datasheet> vec_database;
  Datasheet datasheet;
  const std::string sfileDatabase = stlplus::create_filespec( std::string(THIS_SOURCE_DIR), sDatabase );
  const std::string sModel = "Canon EOS 550D";
  const std::string sBrand = "Canon";

  BOOST_CHECK( parseDatabase( sfileDatabase, vec_database ) );
  BOOST_CHECK( getInfo( sBrand, sModel, vec_database, datasheet ) );
  BOOST_CHECK_EQUAL( 22.3, datasheet._sensorSize );
}

BOOST_AUTO_TEST_CASE(ParseDatabaseCanon_EOS_5D_Mark_II)
{
  std::vector<Datasheet> vec_database;
  Datasheet datasheet;
  const std::string sfileDatabase = stlplus::create_filespec( std::string(THIS_SOURCE_DIR), sDatabase );
  const std::string sModel = "Canon EOS 5D Mark II";
  const std::string sBrand = "Canon";

  BOOST_CHECK( parseDatabase( sfileDatabase, vec_database ) );
  BOOST_CHECK( getInfo( sBrand, sModel, vec_database, datasheet ) );
  BOOST_CHECK_EQUAL( 35.8, datasheet._sensorSize );
}

BOOST_AUTO_TEST_CASE(ParseDatabaseCanon_EOS_1100D)
{
  std::vector<Datasheet> vec_database;
  Datasheet datasheet;
  const std::string sfileDatabase = stlplus::create_filespec( std::string(THIS_SOURCE_DIR), sDatabase );
  const std::string sModel = "Canon EOS 1100D";
  const std::string sBrand = "Canon";

  BOOST_CHECK( parseDatabase( sfileDatabase, vec_database ) );
  BOOST_CHECK( getInfo( sBrand, sModel, vec_database, datasheet ) );
  BOOST_CHECK_EQUAL( 22.2, datasheet._sensorSize );
}
