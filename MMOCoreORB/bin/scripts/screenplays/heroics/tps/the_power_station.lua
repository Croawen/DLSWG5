local ObjectManager = require("managers.object.object_manager")

ThePowerStationScreenPlay = ScreenPlay:new {
	numberOfActs = 1,

}
spHelper = require("sphelper")
registerScreenPlay("ThePowerStationScreenPlay", true)

function ThePowerStationScreenPlay:start()
	if (isZoneEnabled("dungeon2")) then
		self:spawnMobiles()
	end
end

function ThePowerStationScreenPlay:spawnMobiles()
--Entrance/First Hallway
  spawnMobile("dungeon2", "tps_battle_droid", 300, -16.3, -7.0, -33.0, 86, 410000021)
  spawnMobile("dungeon2", "tps_battle_droid", 300, -27.4, -7.0, -33.0, 85, 410000021)
  spawnMobile("dungeon2", "tps_battle_droid", 300, -22.0, -7.0, -32.7, -7, 410000021)
  spawnMobile("dungeon2", "tps_battle_droid", 300, -22.0, -7.0, -19.7, -1, 410000014)
  spawnMobile("dungeon2", "tps_battle_droid", 300, -21.9, -7.0, -4.8, 178, 410000012)
  spawnMobile("dungeon2", "tps_battle_droid", 300, -16.8, -7.0, 0.3, -85, 410000012)
  
  --"power room (big blue light place first floor)" area to the right leading to first boss
  spawnMobile("dungeon2", "tps_black_sun_guard", 300, -12.1, -7.0, 0.1, 91, 410000018)
  spawnMobile("dungeon2", "tps_black_sun_guard", 300, -5.5, -7.0, 0.1, -99, 410000018)  
  spawnMobile("dungeon2", "tps_black_sun_assassin", 300, 0.1, -7.0, -5.8, -70, 410000018)  
  spawnMobile("dungeon2", "tps_black_sun_guard", 300, 0.5, -7.0, 5.6, -118, 410000018) 
  spawnMobile("dungeon2", "tps_black_sun_assassin", 900, 6, -7.0, 0.1, 85, 410000018) 
  spawnMobile("dungeon2", "tps_black_sun_assassin", 900, 13.3, -7.0, 0.0, -93, 410000018)
  spawnMobile("dungeon2", "tps_black_sun_assassin", 900, 20.8, -7.0, 5.2, -171, 410000020)
  spawnMobile("dungeon2", "tps_black_sun_assassin", 900, 23.2, -7.0, 5.2, -171, 410000020)
  
  --Boss Fight 1
  
  
    
 local pTrigger = spawnMobile("dungeon2", "tps_battle_droid", 35, 15.0, -7.0, 16.2, 92, 410000016)
if (pTrigger ~= nil ) then
        createObserver(OBJECTDESTRUCTION, "ThePowerStationScreenPlay", "notifyTriggerDead", pTrigger)
end
 
writeData("ThePowerStationScreenPlay:spawnState",0)
        return 0
end
 
function ThePowerStationScreenPlay:notifyTriggerDead(pTrigger, pPlayer)
           local pBoss = spawnMobile("dungeon2", "tps_boss1", 0, 15.0, -7.0, 16.2, 92, 410000016)
ObjectManager.withCreatureObject(pBoss, function(oBoss)
writeData("ThePowerStationScreenPlay:spawnState", 1)
writeData("tpsboss1", oBoss:getObjectID())
spatialChat(pBoss, "Intruders!  Droids, attack!  Do not let them shut down the force fields!")
          createObserver(DAMAGERECEIVED,"ThePowerStationScreenPlay","boss_damage", pBoss)
createObserver(OBJECTDESTRUCTION, "ThePowerStationScreenPlay", "notifyBossDead", pBoss)
createEvent(30, "ThePowerStationScreenPlay", "despawnBoss", pBoss)
 
end)
return 0
end

function ThePowerStationScreenPlay:notifyBossDead(pBoss, pPlayer)
writeData("ThePowerStationScreenPlay:spawnState", 0)
return 0
end
 
 
function ThePowerStationScreenPlay:despawnBoss(pBoss, pPlayer)
forcePeace(pBoss)
spHelper.destroy(readData("tpsboss1"),true)
writeData("ThePowerStationScreenPlay:spawnState", 0)
return 0
end

function ThePowerStationScreenPlay:boss_damage(pBoss, pPlayer)
 
local player = LuaCreatureObject(pPlayer)
local boss = LuaCreatureObject(pBoss)
if ( boss ~= nil ) then
local bossHealth = boss:getHAM(0)
local bossAction = boss:getHAM(3)
local bossMind = boss:getHAM(6)
local bossMaxHealth = boss:getMaxHAM(0)
local bossMaxAction = boss:getMaxHAM(3)
local bossMaxMind = boss:getMaxHAM(6)
 
local x1 = 0.2
local y1 = -24.2
local x2 = boss:getPositionX()
local y2 = boss:getPositionY()
 
local distance = ((x2 - x1)*(x2 - x1)) + ((y2 - y1)*(y2 - y1))
local maxDistance = 45
 
if distance > (maxDistance * maxDistance) then
spatialChat(pBoss, "Thats right you better run.  Droids, return to your normal duties, the cowards have fled!")
 
boss:healDamage(pBoss, 0, 2000000)
boss:healDamage(pBoss, 3, 2000000)
boss:healDamage(pBoss, 6, 2000000)
-- boss:setPvpStatusBitmask(0)
forcePeace(pBoss)
-- boss:setOptionsBitmask(128)
 
createEvent(3500, "ThePowerStationScreenPlay", "resetScreenplayStatus", pPlayer)
end

if (((bossHealth <= (bossMaxHealth *0.9))) and readData("ThePowerStationScreenPlay:spawnState") == 1) then
spatialChat(pBoss, "Calling in reinforcements!  Blast them!")
writeData("ThePowerStationScreenPlay:spawnState",2)
local add1 = spawnMobile("dungeon2", "tps_boss1_add", 0, 21.7, 7.0, 20.0, 169, 410000016)
ObjectManager.withCreatureObject(add1, function(firstTime)
local add2 = spawnMobile("dungeon2", "tps_boss1_add", 0, 21.7, 7.0, 10.5, 1, 410000016)
ObjectManager.withCreatureObject(add2, function(secondTime)
local add3 = spawnMobile("dungeon2", "tps_boss1_add", 0, 26.4, 7.0, 15.0, -09, 410000016)
ObjectManager.withCreatureObject(add3, function(thirdTime)
local add4 = spawnMobile("dungeon2", "tps_boss1_add", 0, 20.1, 7.0, 16.1, 05, 410000016)
ObjectManager.withCreatureObject(add4, function(fourthTime)
firstTime:engageCombat(pPlayer)
secondTime:engageCombat(pPlayer)
thirdTime:engageCombat(pPlayer)
fourthTime:engageCombat(pPlayer)
end)
end)
end)
end)
spatialChat(add1, "roger roger!") 
end

if (((bossHealth <= (bossMaxHealth *0.6))) and readData("ThePowerStationScreenPlay:spawnState") == 2) then
spatialChat(pBoss, "I will not tolerate any further interruptions, overwatch guards get in here and destroy them!")
writeData("ThePowerStationScreenPlay:spawnState",3)
local add5 = spawnMobile("dungeon2", "tps_boss1_add", 0, 21.7, 7.0, 20.0, 169, 410000016)
ObjectManager.withCreatureObject(add5, function(fifthTime)
local add6 = spawnMobile("dungeon2", "tps_boss1_add", 0, 21.7, 7.0, 10.5, 1, 410000016)
ObjectManager.withCreatureObject(add6, function(sixthTime)
local add7 = spawnMobile("dungeon2", "tps_boss1_add", 0, 26.4, 7.0, 15.0, -09, 410000016)
ObjectManager.withCreatureObject(add7, function(seventhTime)
local add8 = spawnMobile("dungeon2", "tps_boss1_add", 0, 20.1, 7.0, 16.1, 05, 410000016)
ObjectManager.withCreatureObject(add8, function(eighthTime)
fifthTime:engageCombat(pPlayer)
sixthTime:engageCombat(pPlayer)
seventhTime:engageCombat(pPlayer)
eighthTime:engageCombat(pPlayer)
end)
end)
end)
end)
spatialChat(add5, "Time to die, scum!") 
end


end
 
return 0
 
 
 
 
end
