Route123_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route123_OnTransition
	.byte 0

Route123_OnTransition:
	special SetRoute123Weather
	end

Route123_EventScript_GigaDrainGirl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM19, Route123_EventScript_ReceivedGigaDrain
	msgbox Route123_Text_LoveGrassMonsHaveAny, MSGBOX_DEFAULT
	special IsGrassTypeInParty
	goto_if_eq VAR_RESULT, FALSE, Route123_EventScript_NoGrassMons
	msgbox Route123_Text_YouLikeGrassMonsTooHaveThis, MSGBOX_DEFAULT
	giveitem ITEM_TM19
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM19
	msgbox Route123_Text_CheckTreesWithMyGrassMon, MSGBOX_DEFAULT
	release
	end

Route123_EventScript_NoGrassMons::
	release
	end

Route123_EventScript_ReceivedGigaDrain::
	msgbox Route123_Text_CheckTreesWithMyGrassMon, MSGBOX_DEFAULT
	release
	end

Route123_EventScript_RouteSign::
	msgbox Route123_Text_RouteSign, MSGBOX_SIGN
	end

Route123_EventScript_RouteSignMtPyre::
	msgbox Route123_Text_RouteSignMtPyre, MSGBOX_SIGN
	end

Route123_EventScript_BerryMastersHouseSign::
	msgbox Route123_Text_BerryMastersHouse, MSGBOX_SIGN
	end

Route123_EventScript_Wendy::
	trainerbattle_single TRAINER_WENDY, Route123_Text_WendyIntro, Route123_Text_WendyDefeat
	msgbox Route123_Text_WendyPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Braxton::
	trainerbattle_single TRAINER_BRAXTON, Route123_Text_BraxtonIntro, Route123_Text_BraxtonDefeat
	msgbox Route123_Text_BraxtonPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Violet::
	trainerbattle_single TRAINER_VIOLET, Route123_Text_VioletIntro, Route123_Text_VioletDefeat
	msgbox Route123_Text_VioletPostBattle, MSGBOX_AUTOCLOSE
	end

// Route123_EventScript_Cameron::
// 	trainerbattle_single TRAINER_CAMERON_1, Route123_Text_CameronIntro, Route123_Text_CameronDefeat, Route123_EventScript_RegisterCameron
// 	specialvar VAR_RESULT, ShouldTryRematchBattle
// 	goto_if_eq VAR_RESULT, TRUE, Route123_EventScript_RematchCameron
// 	msgbox Route123_Text_CameronPostBattle, MSGBOX_DEFAULT
// 	release
// 	end

// Route123_EventScript_RegisterCameron::
// 	special PlayerFaceTrainerAfterBattle
// 	waitmovement 0
// 	msgbox Route123_Text_CameronRegister, MSGBOX_DEFAULT
// 	register_matchcall TRAINER_CAMERON_1
// 	release
// 	end

// Route123_EventScript_RematchCameron::
// 	trainerbattle_rematch TRAINER_CAMERON_1, Route123_Text_CameronRematchIntro, Route123_Text_CameronRematchDefeat
// 	msgbox Route123_Text_CameronPostRematch, MSGBOX_AUTOCLOSE
// 	end

Route123_EventScript_Jacki::
	trainerbattle_single TRAINER_JACKI_1, Route123_Text_JackiIntro, Route123_Text_JackiDefeat, Route123_EventScript_RegisterJacki
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route123_EventScript_RematchJacki
	msgbox Route123_Text_JackiPostBattle, MSGBOX_DEFAULT
	release
	end

Route123_EventScript_RegisterJacki::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route123_Text_JackiRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JACKI_1
	release
	end

Route123_EventScript_RematchJacki::
	trainerbattle_rematch TRAINER_JACKI_1, Route123_Text_JackiRematchIntro, Route123_Text_JackiRematchDefeat
	msgbox Route123_Text_JackiPostRematch, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Miu::
	trainerbattle_double TRAINER_MIU_AND_YUKI, Route123_Text_MiuIntro, Route123_Text_MiuDefeat, Route123_Text_MiuNotEnoughMons
	msgbox Route123_Text_MiuPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Yuki::
	trainerbattle_double TRAINER_MIU_AND_YUKI, Route123_Text_YukiIntro, Route123_Text_YukiDefeat, Route123_Text_YukiNotEnoughMons
	msgbox Route123_Text_YukiPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Kindra::
	trainerbattle_single TRAINER_KINDRA, Route123_Text_KindraIntro, Route123_Text_KindraDefeat
	msgbox Route123_Text_KindraPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Frederick::
	trainerbattle_single TRAINER_FREDRICK, Route123_Text_FrederickIntro, Route123_Text_FrederickDefeat
	msgbox Route123_Text_FrederickPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Alberto::
	trainerbattle_single TRAINER_ALBERTO, Route123_Text_AlbertoIntro, Route123_Text_AlbertoDefeat
	msgbox Route123_Text_AlbertoPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Ed::
	trainerbattle_single TRAINER_ED, Route123_Text_EdIntro, Route123_Text_EdDefeat
	msgbox Route123_Text_EdPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Kayley::
	trainerbattle_single TRAINER_KAYLEY, Route123_Text_KayleyIntro, Route123_Text_KayleyDefeat
	msgbox Route123_Text_KayleyPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Jonas::
	trainerbattle_single TRAINER_JONAS, Route123_Text_JonasIntro, Route123_Text_JonasDefeat
	msgbox Route123_Text_JonasPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Jazmyn::
	trainerbattle_single TRAINER_JAZMYN, Route123_Text_JazmynIntro, Route123_Text_JazmynDefeat
	msgbox Route123_Text_JazmynPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Davis::
	trainerbattle_single TRAINER_DAVIS, Route123_Text_DavisIntro, Route123_Text_DavisDefeat
	msgbox Route123_Text_DavisPostBattle, MSGBOX_AUTOCLOSE
	end

Route123_EventScript_Fernando::
	trainerbattle_single TRAINER_FERNANDO_1, Route123_Text_FernandoIntro, Route123_Text_FernandoDefeat, Route123_EventScript_RegisterFernando
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route123_EventScript_RematchFernando
	msgbox Route123_Text_FernandoPostBattle, MSGBOX_DEFAULT
	release
	end

Route123_EventScript_RegisterFernando::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route123_Text_FernandoRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_FERNANDO_1
	release
	end

Route123_EventScript_RematchFernando::
	trainerbattle_rematch TRAINER_FERNANDO_1, Route123_Text_FernandoRematchIntro, Route123_Text_FernandoRematchDefeat
	msgbox Route123_Text_FernandoPostRematch, MSGBOX_AUTOCLOSE
	end

Route123_Text_LoveGrassMonsHaveAny:
	.string "I love GRASS-type POKéMON!\p"
	.string "Do you have any GRASS-type POKéMON?$"

Route123_Text_YouLikeGrassMonsTooHaveThis:
	.string "Oh?\p"
	.string "You like GRASS-type POKéMON, too,\n"
	.string "don't you?\p"
	.string "I'm so happy, you can have this!\n"
	.string "It's a token of our friendship.$"

Route123_Text_CheckTreesWithMyGrassMon:
	.string "I check trees with my GRASS-type\n"
	.string "POKéMON. I'm like a tree doctor.$"

Route123_Text_RouteSign:
	.string "{RIGHT_ARROW} ROUTE 123\n"
	.string "{LEFT_ARROW} ROUTE 118$"

Route123_Text_RouteSignMtPyre:
	.string "{UP_ARROW} MT. PYRE\n"
	.string "“Forbidden to the faint of heart.”$"

Route123_Text_BerryMastersHouse:
	.string "BERRY MASTER'S HOUSE$"

Route123_EventScript_BirchsTrigger1::
	setvar VAR_TEMP_1, 0
	goto Route123_EventScript_BirchsRescue
	end


Route123_EventScript_BirchsTrigger2::
	setvar VAR_TEMP_1, 1
	goto Route123_EventScript_BirchsRescue
	end


Route123_EventScript_BirchsTrigger3::
	setvar VAR_TEMP_1, 2
	goto Route123_EventScript_BirchsRescue
	end


Route123_EventScript_BirchsRescue::
	lockall
	playbgm MUS_HELP, TRUE
	msgbox Route123_EventScript_BirchsRescue_Text_0, MSGBOX_AUTOCLOSE
	switch VAR_TEMP_1
	case 0, Route123_EventScript_BirchsRescue_3
	case 2, Route123_EventScript_BirchsRescue_4
Route123_EventScript_BirchsRescue_1:
	applymovement 22, BirchChase
	applymovement 23, BirchChase
	waitmovement 0
	msgbox Route123_EventScript_BirchsRescue_Text_1, MSGBOX_AUTOCLOSE
	fadescreen FADE_TO_BLACK
	removeobject 23
	setwildbattle SPECIES_ZIGZAGOON, 7, ITEM_ORAN_BERRY
	dowildbattle
	setflag FLAG_ROUTE_123_BIRCH_RESCUE
	setflag FLAG_ROUTE_123_ZIGZAGOON
	msgbox Route123_EventScript_BirchsRescue_Text_2, MSGBOX_AUTOCLOSE
	playfanfare MUS_OBTAIN_ITEM
	msgbox Route123_EventScript_BirchsRescue_Text_3
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	msgbox Route123_EventScript_BirchsRescue_Text_4, MSGBOX_DEFAULT
	releaseall
	end

Route123_EventScript_BirchsRescue_3:
	applymovement 22, BirchTrigger1
	applymovement 23, BirchTrigger1
	goto Route123_EventScript_BirchsRescue_1

Route123_EventScript_BirchsRescue_4:
	applymovement 22, BirchTrigger3
	applymovement 23, BirchTrigger3
	goto Route123_EventScript_BirchsRescue_1


BirchChase:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

BirchTrigger1:
	walk_down
	step_end

BirchTrigger3:
	walk_up
	step_end

Route123_EventScript_BirchsRescue_Text_0:
	.string "H-help me!$"

Route123_EventScript_BirchsRescue_Text_1:
	.string "This Zigzagoon is chasing me! Please\n"
	.string "help me by battling it!$"

Route123_EventScript_BirchsRescue_Text_2:
	.string "Whew…\p"
	.string "You saved me!\n"
	.string "I can't thank you enough.\p"
	.string "Oh?\n"
	.string "You're travelling to experience the\l"
	.string "world?\p"
	.string "Well if you're going to explore the world\n"
	.string "of Pokémon this might come in handy!$"

Route123_EventScript_BirchsRescue_Text_3:
	.string "{PLAYER} received the POKéDEX!$"

Route123_EventScript_BirchsRescue_Text_4:
	.string "That right there is a POKéDEX. It\n"
	.string "contains information on POKéMON you\l"
	.string "have caught. Come visit me in\l"
	.string "Littleroot Town if you get the chance.$"
