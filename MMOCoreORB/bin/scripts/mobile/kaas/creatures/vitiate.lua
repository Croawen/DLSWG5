vitiate = Creature:new {
	objectName = "@theme_park_name:emperor_palpatine",
	customName = "Vitiate",
	socialGroup = "dark_jedi",
	level = 100,
	chanceHit = 1,
	damageMin = 645,
	damageMax = 1000,
	baseXp = 9429,
	baseHAM = 240000,
	baseHAMmax = 300000,
	armor = 0,
	resists = {0,0,0,0,0,0,0,0,-1},
	meatType = "",
	meatAmount = 0,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0,
	ferocity = 0,
	pvpBitmask = AGGRESSIVE + ATTACKABLE + ENEMY,
  creatureBitmask = KILLER + STALKER,
  optionsBitmask = AIENABLED,
  diet = HERBIVORE,
	scale = 1.1,

	templates = {"object/mobile/ep3/palpatine_hologram.iff"},
	lootGroups = {},
	weapons = {"dark_jedi_weapons_gen4"},
  conversationTemplate = "",
  attacks = merge(lightsabermaster,forcepowermaster)
}

CreatureTemplates:addCreatureTemplate(vitiate, "vitiate")
