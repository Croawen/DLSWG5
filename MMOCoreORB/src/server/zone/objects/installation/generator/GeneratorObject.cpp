/*
 *	server/zone/objects/installation/generator/GeneratorObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "GeneratorObject.h"

#include "server/zone/objects/area/ActiveArea.h"


// Imported class dependencies

#include "system/util/SortedVector.h"

#include "system/util/Vector.h"

#include "server/zone/objects/installation/HopperList.h"

#include "server/zone/objects/scene/variables/PendingTasksMap.h"

#include "server/zone/objects/scene/variables/StringId.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "engine/core/ObjectUpdateToDatabaseTask.h"

#include "server/zone/objects/scene/ObserverEventMap.h"

#include "server/zone/ZoneProcessServerImplementation.h"

#include "server/zone/Zone.h"

#include "server/zone/objects/installation/SyncrhonizedUiListenInstallationTask.h"

#include "server/zone/objects/scene/variables/CustomizationVariables.h"

#include "system/lang/Time.h"

#include "server/zone/objects/scene/variables/DeltaVector.h"

#include "server/zone/objects/structure/events/StructureMaintenanceTask.h"

#include "engine/util/Quaternion.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "system/util/VectorMap.h"

#include "server/zone/objects/structure/StructurePermissionList.h"

/*
 *	GeneratorObjectStub
 */

GeneratorObject::GeneratorObject() : InstallationObject(DummyConstructorParameter::instance()) {
	GeneratorObjectImplementation* _implementation = new GeneratorObjectImplementation();
	ManagedObject::_setImplementation(_implementation);
	_implementation->_setStub(this);
}

GeneratorObject::GeneratorObject(DummyConstructorParameter* param) : InstallationObject(param) {
}

GeneratorObject::~GeneratorObject() {
}


void GeneratorObject::fillObjectMenuResponse(ObjectMenuResponse* menuResponse, PlayerCreature* player) {
	GeneratorObjectImplementation* _implementation = (GeneratorObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->fillObjectMenuResponse(menuResponse, player);
}

int GeneratorObject::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	GeneratorObjectImplementation* _implementation = (GeneratorObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(player);
		method.addByteParameter(selectedID);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->handleObjectMenuSelect(player, selectedID);
}

void GeneratorObject::synchronizedUIListen(SceneObject* player, int value) {
	GeneratorObjectImplementation* _implementation = (GeneratorObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(player);
		method.addSignedIntParameter(value);

		method.executeWithVoidReturn();
	} else
		_implementation->synchronizedUIListen(player, value);
}

void GeneratorObject::synchronizedUIStopListen(SceneObject* player, int value) {
	GeneratorObjectImplementation* _implementation = (GeneratorObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addObjectParameter(player);
		method.addSignedIntParameter(value);

		method.executeWithVoidReturn();
	} else
		_implementation->synchronizedUIStopListen(player, value);
}

bool GeneratorObject::isGeneratorObject() {
	GeneratorObjectImplementation* _implementation = (GeneratorObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isGeneratorObject();
}

DistributedObjectServant* GeneratorObject::_getImplementation() {
	return getForUpdate();}

void GeneratorObject::_setImplementation(DistributedObjectServant* servant) {
	setObject((ManagedObjectImplementation*) servant);}

/*
 *	GeneratorObjectImplementation
 */

GeneratorObjectImplementation::GeneratorObjectImplementation(DummyConstructorParameter* param) : InstallationObjectImplementation(param) {
	_initializeImplementation();
}


GeneratorObjectImplementation::~GeneratorObjectImplementation() {
}


void GeneratorObjectImplementation::finalize() {
}

void GeneratorObjectImplementation::_initializeImplementation() {
	_setClassHelper(GeneratorObjectHelper::instance());

	_serializationHelperMethod();
}

void GeneratorObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (GeneratorObject*) stub;
	InstallationObjectImplementation::_setStub(stub);
}

DistributedObjectStub* GeneratorObjectImplementation::_getStub() {
	return _this;
}

GeneratorObjectImplementation::operator const GeneratorObject*() {
	return _this;
}

TransactionalObject* GeneratorObjectImplementation::clone() {
	return (TransactionalObject*) new GeneratorObjectImplementation(*this);
}


void GeneratorObjectImplementation::lock(bool doLock) {
}

void GeneratorObjectImplementation::lock(ManagedObject* obj) {
}

void GeneratorObjectImplementation::rlock(bool doLock) {
}

void GeneratorObjectImplementation::wlock(bool doLock) {
}

void GeneratorObjectImplementation::wlock(ManagedObject* obj) {
}

void GeneratorObjectImplementation::unlock(bool doLock) {
}

void GeneratorObjectImplementation::runlock(bool doLock) {
}

void GeneratorObjectImplementation::_serializationHelperMethod() {
	InstallationObjectImplementation::_serializationHelperMethod();

	_setClassName("GeneratorObject");

}

GeneratorObjectImplementation::GeneratorObjectImplementation() {
	_initializeImplementation();
	// server/zone/objects/installation/generator/GeneratorObject.idl(8):  		Logger.setLoggingName("GeneratorObject");
	Logger::setLoggingName("GeneratorObject");
}

bool GeneratorObjectImplementation::isGeneratorObject() {
	// server/zone/objects/installation/generator/GeneratorObject.idl(49):  		return true;
	return true;
}

/*
 *	GeneratorObjectAdapter
 */

GeneratorObjectAdapter::GeneratorObjectAdapter(GeneratorObjectImplementation* obj) : InstallationObjectAdapter(obj) {
}

Packet* GeneratorObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertSignedInt(handleObjectMenuSelect((PlayerCreature*) inv->getObjectParameter(), inv->getByteParameter()));
		break;
	case 7:
		synchronizedUIListen((SceneObject*) inv->getObjectParameter(), inv->getSignedIntParameter());
		break;
	case 8:
		synchronizedUIStopListen((SceneObject*) inv->getObjectParameter(), inv->getSignedIntParameter());
		break;
	case 9:
		resp->insertBoolean(isGeneratorObject());
		break;
	default:
		return NULL;
	}

	return resp;
}

int GeneratorObjectAdapter::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	return ((GeneratorObjectImplementation*) impl)->handleObjectMenuSelect(player, selectedID);
}

void GeneratorObjectAdapter::synchronizedUIListen(SceneObject* player, int value) {
	((GeneratorObjectImplementation*) impl)->synchronizedUIListen(player, value);
}

void GeneratorObjectAdapter::synchronizedUIStopListen(SceneObject* player, int value) {
	((GeneratorObjectImplementation*) impl)->synchronizedUIStopListen(player, value);
}

bool GeneratorObjectAdapter::isGeneratorObject() {
	return ((GeneratorObjectImplementation*) impl)->isGeneratorObject();
}

/*
 *	GeneratorObjectHelper
 */

GeneratorObjectHelper* GeneratorObjectHelper::staticInitializer = GeneratorObjectHelper::instance();

GeneratorObjectHelper::GeneratorObjectHelper() {
	className = "GeneratorObject";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void GeneratorObjectHelper::finalizeHelper() {
	GeneratorObjectHelper::finalize();
}

DistributedObject* GeneratorObjectHelper::instantiateObject() {
	return new GeneratorObject(DummyConstructorParameter::instance());
}

DistributedObjectServant* GeneratorObjectHelper::instantiateServant() {
	return new GeneratorObjectImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* GeneratorObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new GeneratorObjectAdapter((GeneratorObjectImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

