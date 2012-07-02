/*
 *	server/zone/objects/creature/conversation/DeliverMissionConversationObserver.cpp generated by engine3 IDL compiler 0.60
 */

#include "DeliverMissionConversationObserver.h"

/*
 *	DeliverMissionConversationObserverStub
 */

DeliverMissionConversationObserver::DeliverMissionConversationObserver(ConversationTemplate* conversationTemplate) : ConversationObserver(DummyConstructorParameter::instance()) {
	DeliverMissionConversationObserverImplementation* _implementation = new DeliverMissionConversationObserverImplementation(conversationTemplate);
	_impl = _implementation;
	_impl->_setStub(this);
	_setClassName("DeliverMissionConversationObserver");
}

DeliverMissionConversationObserver::DeliverMissionConversationObserver(DummyConstructorParameter* param) : ConversationObserver(param) {
	_setClassName("DeliverMissionConversationObserver");
}

DeliverMissionConversationObserver::~DeliverMissionConversationObserver() {
}



DistributedObjectServant* DeliverMissionConversationObserver::_getImplementation() {

	 if (!_updated) _updated = true;
	return _impl;
}

void DeliverMissionConversationObserver::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	DeliverMissionConversationObserverImplementation
 */

DeliverMissionConversationObserverImplementation::DeliverMissionConversationObserverImplementation(DummyConstructorParameter* param) : ConversationObserverImplementation(param) {
	_initializeImplementation();
}


DeliverMissionConversationObserverImplementation::~DeliverMissionConversationObserverImplementation() {
}


void DeliverMissionConversationObserverImplementation::finalize() {
}

void DeliverMissionConversationObserverImplementation::_initializeImplementation() {
	_setClassHelper(DeliverMissionConversationObserverHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void DeliverMissionConversationObserverImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<DeliverMissionConversationObserver*>(stub);
	ConversationObserverImplementation::_setStub(stub);
}

DistributedObjectStub* DeliverMissionConversationObserverImplementation::_getStub() {
	return _this.get();
}

DeliverMissionConversationObserverImplementation::operator const DeliverMissionConversationObserver*() {
	return _this.get();
}

void DeliverMissionConversationObserverImplementation::lock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->lock(doLock);
}

void DeliverMissionConversationObserverImplementation::lock(ManagedObject* obj) {
	_this.getReferenceUnsafeStaticCast()->lock(obj);
}

void DeliverMissionConversationObserverImplementation::rlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->rlock(doLock);
}

void DeliverMissionConversationObserverImplementation::wlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->wlock(doLock);
}

void DeliverMissionConversationObserverImplementation::wlock(ManagedObject* obj) {
	_this.getReferenceUnsafeStaticCast()->wlock(obj);
}

void DeliverMissionConversationObserverImplementation::unlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->unlock(doLock);
}

void DeliverMissionConversationObserverImplementation::runlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->runlock(doLock);
}

void DeliverMissionConversationObserverImplementation::_serializationHelperMethod() {
	ConversationObserverImplementation::_serializationHelperMethod();

	_setClassName("DeliverMissionConversationObserver");

}

void DeliverMissionConversationObserverImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(DeliverMissionConversationObserverImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool DeliverMissionConversationObserverImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (ConversationObserverImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "DeliverMissionConversationObserver.deliverMissionScreenHandler") {
		TypeInfo<DeliverMissionScreenHandler >::parseFromBinaryStream(&deliverMissionScreenHandler, stream);
		return true;
	}


	return false;
}

void DeliverMissionConversationObserverImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = DeliverMissionConversationObserverImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int DeliverMissionConversationObserverImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = ConversationObserverImplementation::writeObjectMembers(stream);

	String _name;
	int _offset;
	uint32 _totalSize;
	_name = "DeliverMissionConversationObserver.deliverMissionScreenHandler";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<DeliverMissionScreenHandler >::toBinaryStream(&deliverMissionScreenHandler, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);


	return _count + 1;
}

/*
 *	DeliverMissionConversationObserverAdapter
 */


#include "engine/orb/messages/InvokeMethodMessage.h"


DeliverMissionConversationObserverAdapter::DeliverMissionConversationObserverAdapter(DeliverMissionConversationObserver* obj) : ConversationObserverAdapter(obj) {
}

void DeliverMissionConversationObserverAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	DOBMessage* resp = inv->getInvocationMessage();

	switch (methid) {
	default:
		throw Exception("Method does not exists");
	}
}

/*
 *	DeliverMissionConversationObserverHelper
 */

DeliverMissionConversationObserverHelper* DeliverMissionConversationObserverHelper::staticInitializer = DeliverMissionConversationObserverHelper::instance();

DeliverMissionConversationObserverHelper::DeliverMissionConversationObserverHelper() {
	className = "DeliverMissionConversationObserver";

	Core::getObjectBroker()->registerClass(className, this);
}

void DeliverMissionConversationObserverHelper::finalizeHelper() {
	DeliverMissionConversationObserverHelper::finalize();
}

DistributedObject* DeliverMissionConversationObserverHelper::instantiateObject() {
	return new DeliverMissionConversationObserver(DummyConstructorParameter::instance());
}

DistributedObjectServant* DeliverMissionConversationObserverHelper::instantiateServant() {
	return new DeliverMissionConversationObserverImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* DeliverMissionConversationObserverHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new DeliverMissionConversationObserverAdapter(static_cast<DeliverMissionConversationObserver*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

