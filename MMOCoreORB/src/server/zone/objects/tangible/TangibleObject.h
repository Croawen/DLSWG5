/*
 *	server/zone/objects/tangible/TangibleObject.h generated by engine3 IDL compiler 0.60
 */

#ifndef TANGIBLEOBJECT_H_
#define TANGIBLEOBJECT_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {
namespace packets {
namespace scene {

class AttributeListMessage;

} // namespace scene
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::scene;

namespace server {
namespace zone {
namespace objects {
namespace player {

class PlayerCreature;

} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player;

namespace server {
namespace zone {

class Zone;

} // namespace zone
} // namespace server

using namespace server::zone;

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
namespace templates {

class SharedObjectTemplate;

} // namespace templates
} // namespace zone
} // namespace server

using namespace server::zone::templates;

#include "server/zone/objects/scene/variables/CustomizationVariables.h"

#include "server/zone/objects/scene/variables/DeltaVector.h"

#include "server/zone/objects/manufactureschematic/craftingvalues/CraftingValues.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "engine/lua/LuaObject.h"

#include "system/util/Vector.h"

#include "system/util/SortedVector.h"

#include "engine/log/Logger.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {

class TangibleObject : public SceneObject {
public:
	unsigned static const short MALE = 0x01;

	unsigned static const short FEMALE = 0x02;

	unsigned static const short HUMAN = 0x004;

	unsigned static const short TRANDOSHAN = 0x008;

	unsigned static const short TWILEK = 0x010;

	unsigned static const short BOTHAN = 0x020;

	unsigned static const short ZABRAK = 0x040;

	unsigned static const short RODIAN = 0x080;

	unsigned static const short MONCALAMARI = 0x100;

	unsigned static const short WOOKIEE = 0x200;

	unsigned static const short SULLUSTAN = 0x400;

	unsigned static const short ITHORIAN = 0x800;

	unsigned static const short NEUTRAL = 0x1000;

	unsigned static const short IMPERIAL = 0x2000;

	unsigned static const short REBEL = 0x4000;

	unsigned static const short COVERT = 0x8000;

	unsigned static const short ALL = 0xFFFF;

	unsigned static const short ALLSEXES = 0x03;

	unsigned static const short ALLFACTIONS = 0xF000;

	unsigned static const short HUMANOIDS = 0xF5FF;

	unsigned static const short HUMANOID_FOOTWEAR = 0xF5F7;

	unsigned static const short HUMANOID_HANDWEAR = 0xF5F7;

	unsigned static const short HUMANOID_HEADWEAR = 0xF5EF;

	unsigned static const short HUMANOID_MALES = 0xF5FD;

	unsigned static const short HUMANOID_FEMALES = 0xF5FE;

	unsigned static const short HUMANOID_IMPERIALS = 0x15FF;

	unsigned static const short HUMANOID_REBELS = 0x45FF;

	unsigned static const short NO_RODIANS = 0xFF7F;

	unsigned static const short NO_MONCALAMARI = 0xFEFF;

	unsigned static const short NO_WOOKIES = 0xFDFF;

	unsigned static const short WOOKIEES = 0xF203;

	unsigned static const short ITHORIANS = 0xF803;

	unsigned static const short TWILEKS = 0xF013;

	TangibleObject();

	void initializeMembers();

	void loadTemplateData(SharedObjectTemplate* templateData);

	void initializeTransientMembers();

	void setCustomObjectName(const UnicodeString& name, bool notifyClient);

	void sendBaselinesTo(SceneObject* player);

	void synchronizedUIListen(SceneObject* player, int value);

	void synchronizedUIStopListen(SceneObject* player, int value);

	void setDefender(SceneObject* defender);

	void addDefender(SceneObject* defender);

	void removeDefender(SceneObject* defender);

	void removeDefenders();

	void setCombatState();

	void setUseCount(unsigned int newUseCount, bool notifyClient = true);

	void decreaseUseCount(PlayerCreature* player = NULL);

	void fillAttributeList(AttributeListMessage* msg, PlayerCreature* object);

	void clearCombatState(bool clearDefenders = true);

	bool hasDefender(SceneObject* defender);

	bool isAttackableBy(CreatureObject* object);

	bool isAggressiveTo(PlayerCreature* object);

	void sendPvpStatusTo(PlayerCreature* player);

	int inflictDamage(TangibleObject* attacker, int damageType, int damage, bool destroy, bool notifyClient = true);

	int healDamage(TangibleObject* healer, int damageType, int damageToHeal, bool notifyClient = true);

	void setConditionDamage(int condDamage, bool notifyClient = true);

	void setCustomizationVariable(byte type, byte value, bool notifyClient = true);

	void setOptionsBitmask(unsigned int bitmask, bool notifyClient = true);

	void updateCraftingValues(ManufactureSchematic* schematic);

	int notifyObjectDestructionObservers(TangibleObject* attacker, int condition);

	byte getUnknownByte();

	bool isTicketCollector();

	bool isTicketObject();

	CustomizationVariables* getCustomizationVariables();

	int getUseCount();

	int getMaxCondition();

	void setMaxCondition(int maxCond);

	int getConditionDamage();

	int getVolume();

	float getComplexity();

	unsigned int getOptionsBitmask();

	int getLevel();

	unsigned int getPvpStatusBitmask();

	bool isTangibleObject();

	void getCustomizationString(String& variables);

	DeltaVector<ManagedReference<SceneObject* > >* getDefenderList();

	SceneObject* getMainDefender();

	bool isDestroyed();

	unsigned int getPlayerUseMask();

	int getFaction();

	bool isRebel();

	bool isImperial();

	bool isNeutral();

	bool isSliced();

	bool isPharmaceuticalObject();

	void setCustomizationString(const String& vars);

	void setPvpStatusBitmask(int bitmask);

	void setCraftersName(String& name);

	String getCraftersName();

	void setCraftersSerial(String& serial);

	void setLevel(int lev);

	String getCraftersSerial();

	bool isFromFactoryCrate();

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	TangibleObject(DummyConstructorParameter* param);

	virtual ~TangibleObject();

	String _return_getCraftersName;
	String _return_getCraftersSerial;

	friend class TangibleObjectHelper;
};

} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible;

namespace server {
namespace zone {
namespace objects {
namespace tangible {

class TangibleObjectImplementation : public SceneObjectImplementation {
protected:
	bool targetable;

	float complexity;

	int volume;

	int faction;

	CustomizationVariables customizationVariables;

	int conditionDamage;

	int maxCondition;

	int useCount;

	short level;

	unsigned int optionsBitmask;

	unsigned int pvpStatusBitmask;

	byte unknownByte;

	String craftersName;

	String craftersSerial;

	DeltaVector<ManagedReference<SceneObject* > > defenderList;

	unsigned short playerUseMask;

	bool sliced;

public:
	unsigned static const short MALE = 0x01;

	unsigned static const short FEMALE = 0x02;

	unsigned static const short HUMAN = 0x004;

	unsigned static const short TRANDOSHAN = 0x008;

	unsigned static const short TWILEK = 0x010;

	unsigned static const short BOTHAN = 0x020;

	unsigned static const short ZABRAK = 0x040;

	unsigned static const short RODIAN = 0x080;

	unsigned static const short MONCALAMARI = 0x100;

	unsigned static const short WOOKIEE = 0x200;

	unsigned static const short SULLUSTAN = 0x400;

	unsigned static const short ITHORIAN = 0x800;

	unsigned static const short NEUTRAL = 0x1000;

	unsigned static const short IMPERIAL = 0x2000;

	unsigned static const short REBEL = 0x4000;

	unsigned static const short COVERT = 0x8000;

	unsigned static const short ALL = 0xFFFF;

	unsigned static const short ALLSEXES = 0x03;

	unsigned static const short ALLFACTIONS = 0xF000;

	unsigned static const short HUMANOIDS = 0xF5FF;

	unsigned static const short HUMANOID_FOOTWEAR = 0xF5F7;

	unsigned static const short HUMANOID_HANDWEAR = 0xF5F7;

	unsigned static const short HUMANOID_HEADWEAR = 0xF5EF;

	unsigned static const short HUMANOID_MALES = 0xF5FD;

	unsigned static const short HUMANOID_FEMALES = 0xF5FE;

	unsigned static const short HUMANOID_IMPERIALS = 0x15FF;

	unsigned static const short HUMANOID_REBELS = 0x45FF;

	unsigned static const short NO_RODIANS = 0xFF7F;

	unsigned static const short NO_MONCALAMARI = 0xFEFF;

	unsigned static const short NO_WOOKIES = 0xFDFF;

	unsigned static const short WOOKIEES = 0xF203;

	unsigned static const short ITHORIANS = 0xF803;

	unsigned static const short TWILEKS = 0xF013;

	TangibleObjectImplementation();

	TangibleObjectImplementation(DummyConstructorParameter* param);

	void initializeMembers();

	void loadTemplateData(SharedObjectTemplate* templateData);

	void initializeTransientMembers();

	void setCustomObjectName(const UnicodeString& name, bool notifyClient);

	virtual void sendBaselinesTo(SceneObject* player);

	virtual void synchronizedUIListen(SceneObject* player, int value);

	virtual void synchronizedUIStopListen(SceneObject* player, int value);

	virtual void setDefender(SceneObject* defender);

	virtual void addDefender(SceneObject* defender);

	virtual void removeDefender(SceneObject* defender);

	virtual void removeDefenders();

	virtual void setCombatState();

	void setUseCount(unsigned int newUseCount, bool notifyClient = true);

	void decreaseUseCount(PlayerCreature* player = NULL);

	void fillAttributeList(AttributeListMessage* msg, PlayerCreature* object);

	virtual void clearCombatState(bool clearDefenders = true);

	bool hasDefender(SceneObject* defender);

	virtual bool isAttackableBy(CreatureObject* object);

	virtual bool isAggressiveTo(PlayerCreature* object);

	virtual void sendPvpStatusTo(PlayerCreature* player);

	virtual int inflictDamage(TangibleObject* attacker, int damageType, int damage, bool destroy, bool notifyClient = true);

	virtual int healDamage(TangibleObject* healer, int damageType, int damageToHeal, bool notifyClient = true);

	void setConditionDamage(int condDamage, bool notifyClient = true);

	void setCustomizationVariable(byte type, byte value, bool notifyClient = true);

	void setOptionsBitmask(unsigned int bitmask, bool notifyClient = true);

	virtual void updateCraftingValues(ManufactureSchematic* schematic);

	virtual int notifyObjectDestructionObservers(TangibleObject* attacker, int condition);

	byte getUnknownByte();

	virtual bool isTicketCollector();

	virtual bool isTicketObject();

	CustomizationVariables* getCustomizationVariables();

	virtual int getUseCount();

	int getMaxCondition();

	void setMaxCondition(int maxCond);

	int getConditionDamage();

	int getVolume();

	float getComplexity();

	unsigned int getOptionsBitmask();

	int getLevel();

	unsigned int getPvpStatusBitmask();

	bool isTangibleObject();

	void getCustomizationString(String& variables);

	DeltaVector<ManagedReference<SceneObject* > >* getDefenderList();

	SceneObject* getMainDefender();

	bool isDestroyed();

	unsigned int getPlayerUseMask();

	int getFaction();

	bool isRebel();

	bool isImperial();

	bool isNeutral();

	bool isSliced();

	virtual bool isPharmaceuticalObject();

	void setCustomizationString(const String& vars);

	void setPvpStatusBitmask(int bitmask);

	void setCraftersName(String& name);

	virtual String getCraftersName();

	void setCraftersSerial(String& serial);

	void setLevel(int lev);

	virtual String getCraftersSerial();

	bool isFromFactoryCrate();

	TangibleObject* _this;

	operator const TangibleObject*();

	DistributedObjectStub* _getStub();
protected:
	virtual ~TangibleObjectImplementation();

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

	friend class TangibleObject;
	friend class TransactionalObjectHandle<TangibleObjectImplementation*>;
};

class TangibleObjectAdapter : public SceneObjectAdapter {
public:
	TangibleObjectAdapter(TangibleObjectImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initializeMembers();

	void initializeTransientMembers();

	void setCustomObjectName(const UnicodeString& name, bool notifyClient);

	void sendBaselinesTo(SceneObject* player);

	void synchronizedUIListen(SceneObject* player, int value);

	void synchronizedUIStopListen(SceneObject* player, int value);

	void setDefender(SceneObject* defender);

	void addDefender(SceneObject* defender);

	void removeDefender(SceneObject* defender);

	void removeDefenders();

	void setCombatState();

	void setUseCount(unsigned int newUseCount, bool notifyClient);

	void decreaseUseCount(PlayerCreature* player);

	void clearCombatState(bool clearDefenders);

	bool hasDefender(SceneObject* defender);

	bool isAttackableBy(CreatureObject* object);

	bool isAggressiveTo(PlayerCreature* object);

	void sendPvpStatusTo(PlayerCreature* player);

	int inflictDamage(TangibleObject* attacker, int damageType, int damage, bool destroy, bool notifyClient);

	int healDamage(TangibleObject* healer, int damageType, int damageToHeal, bool notifyClient);

	void setConditionDamage(int condDamage, bool notifyClient);

	void setCustomizationVariable(byte type, byte value, bool notifyClient);

	void setOptionsBitmask(unsigned int bitmask, bool notifyClient);

	int notifyObjectDestructionObservers(TangibleObject* attacker, int condition);

	byte getUnknownByte();

	bool isTicketCollector();

	bool isTicketObject();

	int getUseCount();

	int getMaxCondition();

	void setMaxCondition(int maxCond);

	int getConditionDamage();

	int getVolume();

	float getComplexity();

	unsigned int getOptionsBitmask();

	int getLevel();

	unsigned int getPvpStatusBitmask();

	bool isTangibleObject();

	void getCustomizationString(String& variables);

	SceneObject* getMainDefender();

	bool isDestroyed();

	unsigned int getPlayerUseMask();

	int getFaction();

	bool isRebel();

	bool isImperial();

	bool isNeutral();

	bool isSliced();

	bool isPharmaceuticalObject();

	void setCustomizationString(const String& vars);

	void setPvpStatusBitmask(int bitmask);

	void setCraftersName(String& name);

	String getCraftersName();

	void setCraftersSerial(String& serial);

	void setLevel(int lev);

	String getCraftersSerial();

	bool isFromFactoryCrate();

protected:
	UnicodeString _param0_setCustomObjectName__UnicodeString_bool_;
	String _param0_getCustomizationString__String_;
	String _param0_setCustomizationString__String_;
	String _param0_setCraftersName__String_;
	String _param0_setCraftersSerial__String_;
};

class TangibleObjectHelper : public DistributedObjectClassHelper, public Singleton<TangibleObjectHelper> {
	static TangibleObjectHelper* staticInitializer;

public:
	TangibleObjectHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<TangibleObjectHelper>;
};

} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible;

#endif /*TANGIBLEOBJECT_H_*/
