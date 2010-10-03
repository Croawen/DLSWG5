/*
 *	server/zone/objects/tangible/weapon/RangedWeaponObject.h generated by engine3 IDL compiler 0.60
 */

#ifndef RANGEDWEAPONOBJECT_H_
#define RANGEDWEAPONOBJECT_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {

class Zone;

} // namespace zone
} // namespace server

using namespace server::zone;

#include "server/zone/objects/tangible/weapon/WeaponObject.h"

#include "engine/lua/LuaObject.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace weapon {

class RangedWeaponObject : public WeaponObject {
public:
	RangedWeaponObject();

	void initializeTransientMembers();

	bool isRangedWeapon();

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	RangedWeaponObject(DummyConstructorParameter* param);

	virtual ~RangedWeaponObject();

	friend class RangedWeaponObjectHelper;
};

} // namespace weapon
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::weapon;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace weapon {

class RangedWeaponObjectImplementation : public WeaponObjectImplementation {

public:
	RangedWeaponObjectImplementation();

	RangedWeaponObjectImplementation(DummyConstructorParameter* param);

	void initializeTransientMembers();

	bool isRangedWeapon();

	RangedWeaponObject* _this;

	operator const RangedWeaponObject*();

	DistributedObjectStub* _getStub();
protected:
	virtual ~RangedWeaponObjectImplementation();

	TransactionalObject* clone();

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

	friend class RangedWeaponObject;
	friend class TransactionalObjectHandle<RangedWeaponObjectImplementation*>;
};

class RangedWeaponObjectAdapter : public WeaponObjectAdapter {
public:
	RangedWeaponObjectAdapter(RangedWeaponObjectImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initializeTransientMembers();

	bool isRangedWeapon();

};

class RangedWeaponObjectHelper : public DistributedObjectClassHelper, public Singleton<RangedWeaponObjectHelper> {
	static RangedWeaponObjectHelper* staticInitializer;

public:
	RangedWeaponObjectHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<RangedWeaponObjectHelper>;
};

} // namespace weapon
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::weapon;

#endif /*RANGEDWEAPONOBJECT_H_*/
