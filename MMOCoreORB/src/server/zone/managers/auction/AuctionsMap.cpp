/*
 *	server/zone/managers/auction/AuctionsMap.cpp generated by engine3 IDL compiler 0.60
 */

#include "AuctionsMap.h"

#include "server/zone/objects/auction/AuctionItem.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/player/PlayerObject.h"

/*
 *	AuctionsMapStub
 */

enum {RPC_ADDITEM__SCENEOBJECT_STRING_AUCTIONITEM_ = 6,RPC_GETITEM__LONG_,RPC_GETVENDORITEMCOUNT__PLAYEROBJECT_,RPC_GETBAZAARITEMCOUNT__PLAYEROBJECT_};

AuctionsMap::AuctionsMap() : ManagedObject(DummyConstructorParameter::instance()) {
	AuctionsMapImplementation* _implementation = new AuctionsMapImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
	_setClassName("AuctionsMap");
}

AuctionsMap::AuctionsMap(DummyConstructorParameter* param) : ManagedObject(param) {
	_setClassName("AuctionsMap");
}

AuctionsMap::~AuctionsMap() {
}



int AuctionsMap::addItem(SceneObject* vendor, String& uid, AuctionItem* item) {
	AuctionsMapImplementation* _implementation = static_cast<AuctionsMapImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ADDITEM__SCENEOBJECT_STRING_AUCTIONITEM_);
		method.addObjectParameter(vendor);
		method.addAsciiParameter(uid);
		method.addObjectParameter(item);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->addItem(vendor, uid, item);
}

AuctionItem* AuctionsMap::getItem(unsigned long long id) {
	AuctionsMapImplementation* _implementation = static_cast<AuctionsMapImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETITEM__LONG_);
		method.addUnsignedLongParameter(id);

		return static_cast<AuctionItem*>(method.executeWithObjectReturn());
	} else
		return _implementation->getItem(id);
}

SortedVector<ManagedReference<AuctionItem* > > AuctionsMap::getVendorItems(const String& search) {
	AuctionsMapImplementation* _implementation = static_cast<AuctionsMapImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getVendorItems(search);
}

SortedVector<ManagedReference<AuctionItem* > > AuctionsMap::getBazaarItems(const String& search) {
	AuctionsMapImplementation* _implementation = static_cast<AuctionsMapImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getBazaarItems(search);
}

int AuctionsMap::getVendorItemCount(PlayerObject* ghost) {
	AuctionsMapImplementation* _implementation = static_cast<AuctionsMapImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETVENDORITEMCOUNT__PLAYEROBJECT_);
		method.addObjectParameter(ghost);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getVendorItemCount(ghost);
}

int AuctionsMap::getBazaarItemCount(PlayerObject* ghost) {
	AuctionsMapImplementation* _implementation = static_cast<AuctionsMapImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETBAZAARITEMCOUNT__PLAYEROBJECT_);
		method.addObjectParameter(ghost);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getBazaarItemCount(ghost);
}

DistributedObjectServant* AuctionsMap::_getImplementation() {

	_updated = true;
	return _impl;
}

void AuctionsMap::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	AuctionsMapImplementation
 */

AuctionsMapImplementation::AuctionsMapImplementation(DummyConstructorParameter* param) : ManagedObjectImplementation(param) {
	_initializeImplementation();
}


AuctionsMapImplementation::~AuctionsMapImplementation() {
}


void AuctionsMapImplementation::finalize() {
}

void AuctionsMapImplementation::_initializeImplementation() {
	_setClassHelper(AuctionsMapHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void AuctionsMapImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<AuctionsMap*>(stub);
	ManagedObjectImplementation::_setStub(stub);
}

DistributedObjectStub* AuctionsMapImplementation::_getStub() {
	return _this.get();
}

AuctionsMapImplementation::operator const AuctionsMap*() {
	return _this.get();
}

void AuctionsMapImplementation::lock(bool doLock) {
	_this.get()->lock(doLock);
}

void AuctionsMapImplementation::lock(ManagedObject* obj) {
	_this.get()->lock(obj);
}

void AuctionsMapImplementation::rlock(bool doLock) {
	_this.get()->rlock(doLock);
}

void AuctionsMapImplementation::wlock(bool doLock) {
	_this.get()->wlock(doLock);
}

void AuctionsMapImplementation::wlock(ManagedObject* obj) {
	_this.get()->wlock(obj);
}

void AuctionsMapImplementation::unlock(bool doLock) {
	_this.get()->unlock(doLock);
}

void AuctionsMapImplementation::runlock(bool doLock) {
	_this.get()->runlock(doLock);
}

void AuctionsMapImplementation::_serializationHelperMethod() {
	ManagedObjectImplementation::_serializationHelperMethod();

	_setClassName("AuctionsMap");

}

void AuctionsMapImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(AuctionsMapImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool AuctionsMapImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (ManagedObjectImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "AuctionsMap.vendorItemsForSale") {
		TypeInfo<VectorMap<String, SortedVector<ManagedReference<AuctionItem* > >*> >::parseFromBinaryStream(&vendorItemsForSale, stream);
		return true;
	}

	if (_name == "AuctionsMap.bazaarItemsForSale") {
		TypeInfo<VectorMap<String, SortedVector<ManagedReference<AuctionItem* > >*> >::parseFromBinaryStream(&bazaarItemsForSale, stream);
		return true;
	}

	if (_name == "AuctionsMap.allItems") {
		TypeInfo<VectorMap<unsigned long long, ManagedReference<AuctionItem* > > >::parseFromBinaryStream(&allItems, stream);
		return true;
	}


	return false;
}

void AuctionsMapImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = AuctionsMapImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int AuctionsMapImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = ManagedObjectImplementation::writeObjectMembers(stream);

	String _name;
	int _offset;
	uint32 _totalSize;
	_name = "AuctionsMap.vendorItemsForSale";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<VectorMap<String, SortedVector<ManagedReference<AuctionItem* > >*> >::toBinaryStream(&vendorItemsForSale, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "AuctionsMap.bazaarItemsForSale";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<VectorMap<String, SortedVector<ManagedReference<AuctionItem* > >*> >::toBinaryStream(&bazaarItemsForSale, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "AuctionsMap.allItems";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<VectorMap<unsigned long long, ManagedReference<AuctionItem* > > >::toBinaryStream(&allItems, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);


	return _count + 3;
}

AuctionsMapImplementation::AuctionsMapImplementation() {
	_initializeImplementation();
	// server/zone/managers/auction/AuctionsMap.idl():  		vendorItemsForSale.setNullValue(null);
	(&vendorItemsForSale)->setNullValue(NULL);
	// server/zone/managers/auction/AuctionsMap.idl():  		vendorItemsForSale.setNoDuplicateInsertPlan();
	(&vendorItemsForSale)->setNoDuplicateInsertPlan();
	// server/zone/managers/auction/AuctionsMap.idl():  		bazaarItemsForSale.setNullValue(null);
	(&bazaarItemsForSale)->setNullValue(NULL);
	// server/zone/managers/auction/AuctionsMap.idl():  		bazaarItemsForSale.setNoDuplicateInsertPlan();
	(&bazaarItemsForSale)->setNoDuplicateInsertPlan();
	// server/zone/managers/auction/AuctionsMap.idl():  		allItems.setNullValue(null);
	(&allItems)->setNullValue(NULL);
	// server/zone/managers/auction/AuctionsMap.idl():  		allItems.setNoDuplicateInsertPlan();
	(&allItems)->setNoDuplicateInsertPlan();
}

AuctionItem* AuctionsMapImplementation::getItem(unsigned long long id) {
	// server/zone/managers/auction/AuctionsMap.idl():  		return allItems.get(id);
	return (&allItems)->get(id);
}

int AuctionsMapImplementation::getVendorItemCount(PlayerObject* ghost) {
	// server/zone/managers/auction/AuctionsMap.idl():  		return 0;
	return 0;
}

int AuctionsMapImplementation::getBazaarItemCount(PlayerObject* ghost) {
	// server/zone/managers/auction/AuctionsMap.idl():  		return 0;
	return 0;
}

/*
 *	AuctionsMapAdapter
 */


#include "engine/orb/messages/InvokeMethodMessage.h"


AuctionsMapAdapter::AuctionsMapAdapter(AuctionsMap* obj) : ManagedObjectAdapter(obj) {
}

void AuctionsMapAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	DOBMessage* resp = inv->getInvocationMessage();

	switch (methid) {
	case RPC_ADDITEM__SCENEOBJECT_STRING_AUCTIONITEM_:
		{
			String uid; 
			resp->insertSignedInt(addItem(static_cast<SceneObject*>(inv->getObjectParameter()), inv->getAsciiParameter(uid), static_cast<AuctionItem*>(inv->getObjectParameter())));
		}
		break;
	case RPC_GETITEM__LONG_:
		{
			resp->insertLong(getItem(inv->getUnsignedLongParameter())->_getObjectID());
		}
		break;
	case RPC_GETVENDORITEMCOUNT__PLAYEROBJECT_:
		{
			resp->insertSignedInt(getVendorItemCount(static_cast<PlayerObject*>(inv->getObjectParameter())));
		}
		break;
	case RPC_GETBAZAARITEMCOUNT__PLAYEROBJECT_:
		{
			resp->insertSignedInt(getBazaarItemCount(static_cast<PlayerObject*>(inv->getObjectParameter())));
		}
		break;
	default:
		throw Exception("Method does not exists");
	}
}

int AuctionsMapAdapter::addItem(SceneObject* vendor, String& uid, AuctionItem* item) {
	return (static_cast<AuctionsMap*>(stub))->addItem(vendor, uid, item);
}

AuctionItem* AuctionsMapAdapter::getItem(unsigned long long id) {
	return (static_cast<AuctionsMap*>(stub))->getItem(id);
}

int AuctionsMapAdapter::getVendorItemCount(PlayerObject* ghost) {
	return (static_cast<AuctionsMap*>(stub))->getVendorItemCount(ghost);
}

int AuctionsMapAdapter::getBazaarItemCount(PlayerObject* ghost) {
	return (static_cast<AuctionsMap*>(stub))->getBazaarItemCount(ghost);
}

/*
 *	AuctionsMapHelper
 */

AuctionsMapHelper* AuctionsMapHelper::staticInitializer = AuctionsMapHelper::instance();

AuctionsMapHelper::AuctionsMapHelper() {
	className = "AuctionsMap";

	Core::getObjectBroker()->registerClass(className, this);
}

void AuctionsMapHelper::finalizeHelper() {
	AuctionsMapHelper::finalize();
}

DistributedObject* AuctionsMapHelper::instantiateObject() {
	return new AuctionsMap(DummyConstructorParameter::instance());
}

DistributedObjectServant* AuctionsMapHelper::instantiateServant() {
	return new AuctionsMapImplementation();
}

DistributedObjectAdapter* AuctionsMapHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new AuctionsMapAdapter(static_cast<AuctionsMap*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

