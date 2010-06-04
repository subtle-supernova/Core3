/*
 *	server/zone/objects/tangible/deed/building/BuildingDeed.cpp generated by engine3 IDL compiler 0.60
 */

#include "BuildingDeed.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "server/zone/Zone.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

/*
 *	BuildingDeedStub
 */

BuildingDeed::BuildingDeed() : Deed(DummyConstructorParameter::instance()) {
	_impl = new BuildingDeedImplementation();
	_impl->_setStub(this);
}

BuildingDeed::BuildingDeed(DummyConstructorParameter* param) : Deed(param) {
}

BuildingDeed::~BuildingDeed() {
}


void BuildingDeed::fillAttributeList(AttributeListMessage* alm, PlayerCreature* object) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		((BuildingDeedImplementation*) _impl)->fillAttributeList(alm, object);
}

void BuildingDeed::initializeTransientMembers() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		((BuildingDeedImplementation*) _impl)->initializeTransientMembers();
}

int BuildingDeed::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(player);
		method.addByteParameter(selectedID);

		return method.executeWithSignedIntReturn();
	} else
		return ((BuildingDeedImplementation*) _impl)->handleObjectMenuSelect(player, selectedID);
}

void BuildingDeed::setSurplusMaintenance(unsigned int surplusMaint) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addUnsignedIntParameter(surplusMaint);

		method.executeWithVoidReturn();
	} else
		((BuildingDeedImplementation*) _impl)->setSurplusMaintenance(surplusMaint);
}

unsigned int BuildingDeed::getSurplusMaintenance() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((BuildingDeedImplementation*) _impl)->getSurplusMaintenance();
}

bool BuildingDeed::isBuildingDeed() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);

		return method.executeWithBooleanReturn();
	} else
		return ((BuildingDeedImplementation*) _impl)->isBuildingDeed();
}

/*
 *	BuildingDeedImplementation
 */

BuildingDeedImplementation::BuildingDeedImplementation(DummyConstructorParameter* param) : DeedImplementation(param) {
	_initializeImplementation();
}

BuildingDeedImplementation::~BuildingDeedImplementation() {
}


void BuildingDeedImplementation::finalize() {
}

void BuildingDeedImplementation::_initializeImplementation() {
	_setClassHelper(BuildingDeedHelper::instance());

	_serializationHelperMethod();
}

void BuildingDeedImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (BuildingDeed*) stub;
	DeedImplementation::_setStub(stub);
}

DistributedObjectStub* BuildingDeedImplementation::_getStub() {
	return _this;
}

BuildingDeedImplementation::operator const BuildingDeed*() {
	return _this;
}

void BuildingDeedImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void BuildingDeedImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void BuildingDeedImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void BuildingDeedImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void BuildingDeedImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void BuildingDeedImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void BuildingDeedImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void BuildingDeedImplementation::_serializationHelperMethod() {
	DeedImplementation::_serializationHelperMethod();

	_setClassName("BuildingDeed");

	addSerializableVariable("surplusMaintenance", &surplusMaintenance);
}

BuildingDeedImplementation::BuildingDeedImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/deed/building/BuildingDeed.idl(58):  		Logger.setLoggingName("BuildingDeed");
	Logger::setLoggingName("BuildingDeed");
	// server/zone/objects/tangible/deed/building/BuildingDeed.idl(60):  		surplusMaintenance = 0;
	surplusMaintenance = 0;
}

void BuildingDeedImplementation::setSurplusMaintenance(unsigned int surplusMaint) {
	// server/zone/objects/tangible/deed/building/BuildingDeed.idl(77):  		surplusMaintenance = surplusMaint;
	surplusMaintenance = surplusMaint;
}

unsigned int BuildingDeedImplementation::getSurplusMaintenance() {
	// server/zone/objects/tangible/deed/building/BuildingDeed.idl(81):  		return surplusMaintenance;
	return surplusMaintenance;
}

bool BuildingDeedImplementation::isBuildingDeed() {
	// server/zone/objects/tangible/deed/building/BuildingDeed.idl(85):  		return true;
	return true;
}

/*
 *	BuildingDeedAdapter
 */

BuildingDeedAdapter::BuildingDeedAdapter(BuildingDeedImplementation* obj) : DeedAdapter(obj) {
}

Packet* BuildingDeedAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		initializeTransientMembers();
		break;
	case 7:
		resp->insertSignedInt(handleObjectMenuSelect((PlayerCreature*) inv->getObjectParameter(), inv->getByteParameter()));
		break;
	case 8:
		setSurplusMaintenance(inv->getUnsignedIntParameter());
		break;
	case 9:
		resp->insertInt(getSurplusMaintenance());
		break;
	case 10:
		resp->insertBoolean(isBuildingDeed());
		break;
	default:
		return NULL;
	}

	return resp;
}

void BuildingDeedAdapter::initializeTransientMembers() {
	((BuildingDeedImplementation*) impl)->initializeTransientMembers();
}

int BuildingDeedAdapter::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	return ((BuildingDeedImplementation*) impl)->handleObjectMenuSelect(player, selectedID);
}

void BuildingDeedAdapter::setSurplusMaintenance(unsigned int surplusMaint) {
	((BuildingDeedImplementation*) impl)->setSurplusMaintenance(surplusMaint);
}

unsigned int BuildingDeedAdapter::getSurplusMaintenance() {
	return ((BuildingDeedImplementation*) impl)->getSurplusMaintenance();
}

bool BuildingDeedAdapter::isBuildingDeed() {
	return ((BuildingDeedImplementation*) impl)->isBuildingDeed();
}

/*
 *	BuildingDeedHelper
 */

BuildingDeedHelper* BuildingDeedHelper::staticInitializer = BuildingDeedHelper::instance();

BuildingDeedHelper::BuildingDeedHelper() {
	className = "BuildingDeed";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void BuildingDeedHelper::finalizeHelper() {
	BuildingDeedHelper::finalize();
}

DistributedObject* BuildingDeedHelper::instantiateObject() {
	return new BuildingDeed(DummyConstructorParameter::instance());
}

DistributedObjectServant* BuildingDeedHelper::instantiateServant() {
	return new BuildingDeedImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* BuildingDeedHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new BuildingDeedAdapter((BuildingDeedImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

