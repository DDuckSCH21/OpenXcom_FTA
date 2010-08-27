/*
 * Copyright 2010 Daniel Albano
 *
 * This file is part of OpenXcom.
 *
 * OpenXcom is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenXcom is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenXcom.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "City.h"

/**
 * Initializes a city with certain data.
 * @param name Name of the city.
 * @param lon Longitude of the city.
 * @param lat Latitude of the city.
 */
City::City(LangString name, double lon, double lat): _name(name), _lon(lon), _lat(lat)
{
}

/**
 *
 */
City::~City()
{
}

/**
 * Returns the name of the city.
 * @return City name.
 */
LangString City::getName()
{
	return _name;
}

/**
 * Returns the latitude coordinate of the city.
 * @return Latitude in radian.
 */
double City::getLatitude()
{
	return _lat;
}

/**
 * Changes the latitude coordinate of the city.
 * @param lat Latitude in radian.
 */
void City::setLatitude(double lat)
{
	_lat = lat;
}

/**
 * Returns the longitude coordinate of the city.
 * @return Longitude in radian.
 */
double City::getLongitude()
{
	return _lon;
}

/**
 * Changes the longitude coordinate of the city.
 * @param lon Longitude in radian.
 */
void City::setLongitude(double lon)
{
	_lon = lon;
}
