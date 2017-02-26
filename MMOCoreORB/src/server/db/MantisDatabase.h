/*
 * Database.h
 *
 *  Created on: Nov 22, 2010
 *      Author: crush
 */

#ifndef DATABASE_H_
#define DATABASE_H_

#include "../conf/ConfigManager.h"

class Database {
	static Vector<Database*>* databases;
	static AtomicInteger currentDB;

	static String tablePrefix;

public:
	Database(ConfigManager* configManager) {
		String& dbHost = configManager->getHost();
        String& dbUser = configManager->getUser();
        String& dbPass = configManager->getPass();
        String& dbName = configManager->getName();
        tablePrefix = configManager->getPrefix();
        uint16& dbPort = configManager->getPort();

        databases = new Vector<Database*>();

        for (int i = 0; i < DEFAULT_SERVERDATABASE_INSTANCES; ++i) {
        	try {
        		Database* db = new engine::db::mysql::MySqlDatabase(String("Database" + String::valueOf(i)), dbHost);
        		db->connect(dbName, dbUser, dbPass, dbPort);

        		databases->add(db);
        	} catch (const Exception& e) {

        	}
        }

	}

	const static int DEFAULT_SERVERDATABASE_INSTANCES = 1;

	~Database() {
		while (!databases->isEmpty()) {
			Database* db = databases->remove(0);

			delete db;
		}

		delete databases;
		databases = NULL;
	}

	inline static Database* instance() {
		if (databases->size() == 0)
			return NULL;

		int i = currentDB.get() % databases->size();

		currentDB.increment();

		return databases->get(i);
	}

	static String& getTablePrefix() {
		return tablePrefix;
	}
};

#endif /* DATABASE_H_ */
