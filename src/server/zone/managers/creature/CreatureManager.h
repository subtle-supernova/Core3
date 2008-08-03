/*
 *	server/zone/managers/creature/CreatureManager.h generated by engine3 IDL compiler 0.55
 */

#ifndef CREATUREMANAGER_H_
#define CREATUREMANAGER_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/util/Coordinate.h"

class Zone;

#include "server/zone/ZoneProcessServerImplementation.h"

class Creature;

class CreatureObject;

class CreatureGroup;

class TrainerCreature;

class RecruiterCreature;

class ShuttleCreature;

class CreatureManager : public DistributedObjectStub {
public:
	CreatureManager(Zone* zone, ZoneProcessServerImplementation* processor);

	void init();

	void loadCreatures();

	void start();

	void stop();

	void loadTrainers();

	void loadRecruiters();

	void loadBlueFrogs();

	void unloadCreature(Creature* creature);

	Creature* spawnCreature(const string& stfname, const string& name, int objCrc, float x, float y, int bitmask = 00, bool doLock = true);

	Creature* spawnCreature(unsigned int objcrc, float x, float y, int bitmask = 0, bool baby = false, bool doLock = true);

	TrainerCreature* spawnTrainer(const string& profession, const string& stfname, const string& name, int objCrc, float x, float y, bool doLock = true);

	ShuttleCreature* spawnShuttle(const string& Planet, const string& City, Coordinate* playerSpawnPoint, float x, float y, float z, int tax = 0, bool starport = false, bool doLock = true);

	RecruiterCreature* spawnRecruiter(const string& stfname, const string& name, int objCrc, float x, float y, bool doLock = true);

	CreatureGroup* spawnCreatureGroup(int count, const string& stfname, const string& name, int objCrc, float x, float y, int bitmask = 00, int layout = 1);

	void registerFunctions();

	void registerGlobals();

	void loadCreatureFile();

	Creature* getCreature(unsigned long long oid);

protected:
	CreatureManager(DummyConstructorParameter* param);

	virtual ~CreatureManager();

	friend class CreatureManagerHelper;
};

class CreatureManagerImplementation;

class CreatureManagerAdapter : public DistributedObjectAdapter {
public:
	CreatureManagerAdapter(CreatureManagerImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void init();

	void loadCreatures();

	void start();

	void stop();

	void loadTrainers();

	void loadRecruiters();

	void loadBlueFrogs();

	void unloadCreature(Creature* creature);

	Creature* spawnCreature(const string& stfname, const string& name, int objCrc, float x, float y, int bitmask, bool doLock);

	Creature* spawnCreature(unsigned int objcrc, float x, float y, int bitmask, bool baby, bool doLock);

	TrainerCreature* spawnTrainer(const string& profession, const string& stfname, const string& name, int objCrc, float x, float y, bool doLock);

	ShuttleCreature* spawnShuttle(const string& Planet, const string& City, Coordinate* playerSpawnPoint, float x, float y, float z, int tax, bool starport, bool doLock);

	RecruiterCreature* spawnRecruiter(const string& stfname, const string& name, int objCrc, float x, float y, bool doLock);

	CreatureGroup* spawnCreatureGroup(int count, const string& stfname, const string& name, int objCrc, float x, float y, int bitmask, int layout);

	void registerFunctions();

	void registerGlobals();

	void loadCreatureFile();

	Creature* getCreature(unsigned long long oid);

protected:
	string _param0_spawnCreature__string_string_int_float_float_int_bool_;
	string _param1_spawnCreature__string_string_int_float_float_int_bool_;
	string _param0_spawnTrainer__string_string_string_int_float_float_bool_;
	string _param1_spawnTrainer__string_string_string_int_float_float_bool_;
	string _param2_spawnTrainer__string_string_string_int_float_float_bool_;
	string _param0_spawnShuttle__string_string_Coordinate_float_float_float_int_bool_bool_;
	string _param1_spawnShuttle__string_string_Coordinate_float_float_float_int_bool_bool_;
	string _param0_spawnRecruiter__string_string_int_float_float_bool_;
	string _param1_spawnRecruiter__string_string_int_float_float_bool_;
	string _param1_spawnCreatureGroup__int_string_string_int_float_float_int_int_;
	string _param2_spawnCreatureGroup__int_string_string_int_float_float_int_int_;
};

class CreatureManagerHelper : public DistributedObjectClassHelper, public Singleton<CreatureManagerHelper> {
	static CreatureManagerHelper* staticInitializer;

public:
	CreatureManagerHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<CreatureManagerHelper>;
};

class CreatureManagerServant : public DistributedObjectServant {
public:
	CreatureManager* _this;

public:
	CreatureManagerServant();
	virtual ~CreatureManagerServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*CREATUREMANAGER_H_*/
