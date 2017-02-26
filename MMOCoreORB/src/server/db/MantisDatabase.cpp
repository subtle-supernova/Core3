/*
 * Database.cpp
 *
 *  Created on: Nov 22, 2010
 *      Author: crush
 */


#include "Database.h"

Vector<Database*>* Database::databases = NULL;
AtomicInteger Database::currentDB;
String Database::tablePrefix;
