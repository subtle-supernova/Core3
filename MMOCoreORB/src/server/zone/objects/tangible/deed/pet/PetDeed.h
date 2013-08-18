/*
 *	server/zone/objects/tangible/deed/pet/PetDeed.h generated by engine3 IDL compiler 0.60
 */

#ifndef PETDEED_H_
#define PETDEED_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {

class TangibleObject;

} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible;

namespace server {
namespace zone {

class Zone;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {
namespace packets {
namespace object {

class ObjectMenuResponse;

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;

namespace server {
namespace zone {
namespace objects {
namespace creature {

class CreatureObject;

} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;

namespace server {
namespace zone {
namespace templates {

class SharedObjectTemplate;

} // namespace templates
} // namespace zone
} // namespace server

using namespace server::zone::templates;

#include "server/zone/objects/manufactureschematic/craftingvalues/CraftingValues.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "engine/lua/LuaObject.h"

#include "server/zone/objects/tangible/deed/Deed.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace deed {
namespace pet {

class PetDeed : public Deed {
public:
	PetDeed();

	void initializeTransientMembers();

	void loadTemplateData(SharedObjectTemplate* templateData);

	void fillAttributeList(AttributeListMessage* alm, CreatureObject* object);

	void fillObjectMenuResponse(ObjectMenuResponse* menuResponse, CreatureObject* player);

	int handleObjectMenuSelect(CreatureObject* player, byte selectedID);

	void updateCraftingValues(CraftingValues* values, bool firstUpdate);

	bool isPetDeedObject();

	DistributedObjectServant* _getImplementation();
	DistributedObjectServant* _getImplementationForRead();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	PetDeed(DummyConstructorParameter* param);

	virtual ~PetDeed();

	friend class PetDeedHelper;
};

} // namespace pet
} // namespace deed
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::deed::pet;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace deed {
namespace pet {

class PetDeedImplementation : public DeedImplementation {
protected:
	int hitPoints;

	String controlDeviceObjectTemplate;

public:
	PetDeedImplementation();

	PetDeedImplementation(DummyConstructorParameter* param);

	void initializeTransientMembers();

	void loadTemplateData(SharedObjectTemplate* templateData);

	void fillAttributeList(AttributeListMessage* alm, CreatureObject* object);

	void fillObjectMenuResponse(ObjectMenuResponse* menuResponse, CreatureObject* player);

	int handleObjectMenuSelect(CreatureObject* player, byte selectedID);

	void updateCraftingValues(CraftingValues* values, bool firstUpdate);

	bool isPetDeedObject();

	WeakReference<PetDeed*> _this;

	operator const PetDeed*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~PetDeedImplementation();

	void finalize();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();
	bool readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode);
	int writeObjectMembers(ObjectOutputStream* stream);

	friend class PetDeed;
};

class PetDeedAdapter : public DeedAdapter {
public:
	PetDeedAdapter(PetDeed* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initializeTransientMembers();

	int handleObjectMenuSelect(CreatureObject* player, byte selectedID);

	bool isPetDeedObject();

};

class PetDeedHelper : public DistributedObjectClassHelper, public Singleton<PetDeedHelper> {
	static PetDeedHelper* staticInitializer;

public:
	PetDeedHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<PetDeedHelper>;
};

} // namespace pet
} // namespace deed
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::deed::pet;

#endif /*PETDEED_H_*/
