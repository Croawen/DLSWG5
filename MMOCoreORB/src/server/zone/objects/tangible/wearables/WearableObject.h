/*
 *	server/zone/objects/tangible/wearables/WearableObject.h generated by engine3 IDL compiler 0.60
 */

#ifndef WEARABLEOBJECT_H_
#define WEARABLEOBJECT_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {
namespace objects {
namespace manufactureschematic {

class ManufactureSchematic;

} // namespace manufactureschematic
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::manufactureschematic;

namespace server {
namespace zone {

class Zone;

} // namespace zone
} // namespace server

using namespace server::zone;

#include "server/zone/objects/tangible/wearables/WearableSkillModMap.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "engine/lua/LuaObject.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace wearables {

class WearableObject : public TangibleObject {
public:
	static const int MAXSOCKETS = 4;

	WearableObject();

	void initializeTransientMembers();

	void fillAttributeList(AttributeListMessage* msg, PlayerCreature* object);

	void updateCraftingValues(ManufactureSchematic* schematic);

	bool isWearableObject();

	int getMaxSockets();

	int socketsUsed();

	int socketsLeft();

	void setMaxSockets(int sockets);

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	WearableObject(DummyConstructorParameter* param);

	virtual ~WearableObject();

	friend class WearableObjectHelper;
};

} // namespace wearables
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::wearables;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace wearables {

class WearableObjectImplementation : public TangibleObjectImplementation {
protected:
	int socketCount;

	bool socketsGenerated;

public:
	static const int MAXSOCKETS = 4;

protected:
	WearableSkillModMap wearableSkillModMap;

public:
	WearableObjectImplementation();

	WearableObjectImplementation(DummyConstructorParameter* param);

	void initializeTransientMembers();

	void fillAttributeList(AttributeListMessage* msg, PlayerCreature* object);

	void updateCraftingValues(ManufactureSchematic* schematic);

	bool isWearableObject();

	int getMaxSockets();

	int socketsUsed();

	int socketsLeft();

	void setMaxSockets(int sockets);

private:
	void generateSockets(ManufactureSchematic* schematic);

public:
	WearableObject* _this;

	operator const WearableObject*();

	DistributedObjectStub* _getStub();
protected:
	virtual ~WearableObjectImplementation();

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

	friend class WearableObject;
	friend class TransactionalObjectHandle<WearableObjectImplementation*>;
};

class WearableObjectAdapter : public TangibleObjectAdapter {
public:
	WearableObjectAdapter(WearableObjectImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initializeTransientMembers();

	void updateCraftingValues(ManufactureSchematic* schematic);

	bool isWearableObject();

	int getMaxSockets();

	int socketsUsed();

	int socketsLeft();

	void setMaxSockets(int sockets);

};

class WearableObjectHelper : public DistributedObjectClassHelper, public Singleton<WearableObjectHelper> {
	static WearableObjectHelper* staticInitializer;

public:
	WearableObjectHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<WearableObjectHelper>;
};

} // namespace wearables
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::wearables;

#endif /*WEARABLEOBJECT_H_*/
